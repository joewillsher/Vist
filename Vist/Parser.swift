//
//  Parser.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

enum ParseError: ErrorType {
    case ExpectedParen(Pos)
    case NoToken(Token, Pos)
    case ExpectedComma(Pos)
    case InvalidOperator(Pos)
    case InvalidCall(String, Pos) // cant call (*2) or (.print())
    case NoIdentifier(Pos)
    case ExpectedColon(Pos)
    case NoReturnType(Pos)
    case ExpectedAssignment(Pos)
    case NoExpression(Pos)
    case ExpectedBrace(Pos)
    case NoOperator(Pos)
    case MismatchedType((String, Pos), (String, Pos))
    case InvalidIfStatement
    case ExpectedIn(Pos), ExpectedDo(Pos)
    case NotIterator(Pos)
    case NotBlock(Pos)
}

private extension Array {
    mutating func removeLastSafely(str str: String, pos: Pos) throws -> Generator.Element {
        if self.isEmpty { throw ParseError.InvalidCall(str, pos) } else { return removeLast() }
    }
}

private extension Token {
    func isControlToken() -> Bool {
        switch self {
        case .Do, .OpenBrace: return true
        default: return false
        }
    }
    func isBrace() -> Bool {
        if case .OpenBrace = self { return true } else { return false }
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK: -                                            Parser
//-------------------------------------------------------------------------------------------------------------------------

/// Parser object, initialised with tokenised code and exposes methods to generare AST
struct Parser {
    
    private var index = 0
    private let tokensWithPos: [(Token, SourceLoc)]
    
    private var expressions = [Expression]()
    
    private var tokens: [Token]     { return tokensWithPos.map{$0.0} }
    private var currentToken: Token { return tokens[index] }
    private var currentPos: Pos     { return tokensWithPos.map{$0.1.range.start}[index] }
    
    private let precedences: [String: Int] = [
        "<": 10,
        ">": 10,
        "<=": 10,
        ">=": 10,
        "+": 20,
        "-": 20,
        "*": 40,
        "/": 40,
        "||": 5,
        "&&": 5,
        "==": 5,
        "!=": 5,
        "...": 15
    ]
    
    private mutating func getNextToken() -> Token {
        index++
        return currentToken
    }
    private func inspectNextToken(i: Int = 1) -> Token? { // debug function, acts as getNextToken() but does not mutate
        return index < tokens.count-i ? tokens[index+i] : nil
    }
    private func inspectNextPos(i: Int = 1) -> Pos? {
        return index < tokens.count-i ? tokensWithPos.map{$0.1.range.start}[index+i] : nil
    }
    
    init(tokens: [(Token, SourceLoc)]) {
        self.tokensWithPos = tokens
    }

    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                              Literals
    //-------------------------------------------------------------------------------------------------------------------------
    
    // whenever there is a lone object, check to see if the next token is an operator
    // when hit a (, check after )
    // parens should be objects containing only 1 expression,
    
    private mutating func parseIntExpression(token: Int) -> IntegerLiteral {
        getNextToken()
        return IntegerLiteral(val: token)
    }
    private mutating func parseFloatingPointExpression(token: Double) -> FloatingPointLiteral {
        getNextToken()
        return FloatingPointLiteral(val: token)
    }
    private mutating func parseStringExpression(token: String) -> StringLiteral {
        getNextToken()
        return StringLiteral(str: token)
    }
    private mutating func parseBooleanExpression(token: Bool) -> BooleanLiteral {
        getNextToken()
        return BooleanLiteral(val: token)
    }
    
    
    
    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                              Tuple
    //-------------------------------------------------------------------------------------------------------------------------
    
    ///parses expression like (Int, String), of type (_identifier, _identifier)
    private mutating func parseTypeTupleExpression() throws -> Tuple {
        
        var elements = [Expression]()
        while true {
            if case let .Identifier(id) = currentToken {
                elements.append(ValueType(name: id))    // param
                getNextToken()
                continue
            }
            
            switch currentToken {
            case .Comma:
                getNextToken()  // eat ','
                
            case .CloseParen:
                getNextToken()
                return Tuple(elements: elements)
                
            default:
                throw ParseError.ExpectedParen(currentPos)
            }
        }
    }
    
    private mutating func parseTupleExpression() throws -> Tuple {
        
        var elements = [Expression]()
        while true {
            
            elements.append(try parseExpression(currentToken))
            
            switch currentToken {
            case .Comma:
                getNextToken()  // eat ','
                
            case .CloseParen:
                getNextToken()
                return Tuple(elements: elements)
                
            default:
                throw ParseError.ExpectedParen(currentPos)
            }
        }
    }
    
    
    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                      Identifier and operators
    //-------------------------------------------------------------------------------------------------------------------------
    
    private mutating func parseTextExpression() throws -> Variable {
        guard case .Identifier(let i) = currentToken else { throw ParseError.NoIdentifier(currentPos) }
        return Variable(name: i)
    }
    
    private mutating func parseIdentifierExpression(token: String) throws -> Expression {
        
        guard case .OpenParen? = inspectNextToken() else {
            
            if case .Assign = getNextToken() {
                getNextToken() // eat '='
                
                let exp = try parseOperatorExpression()
                
                return Mutation(name: token, value: exp)
            }
            
            return Variable(name: token)
        }       // simple variable name
        getNextToken(); getNextToken() // eat 'identifier + ('
        
        if case .CloseParen = currentToken {   // simple itentifier() call
            getNextToken()
            return FunctionCall(name: token, args: Tuple(elements: []))
        }
        
        return FunctionCall(name: token, args: try parseTupleExpression())
    }
    
    
    private mutating func parseOperatorExpression() throws -> Expression {
        return try parseOperationRHS(lhs: try parsePrimary())
    }
    
    
    private mutating func parsePrimary() throws -> Expression {
        
        switch currentToken {
        case let .Identifier(id):
            return try parseIdentifierExpression(id)
            
        case let .PrefixOperator(op):
            getNextToken()
            return PrefixExpression(op: op, expr: try parsePrimary())
            
        case let .Integer(i):
            return parseIntExpression(i)
            
        case let .FloatingPoint(f):
            return parseFloatingPointExpression(f)
            
        case let .Boolean(b):
            return parseBooleanExpression(b)
            
        case .OpenParen:
            return try parseParenExpression()
            
        default:
            throw ParseError.NoIdentifier(currentPos)
        }
    }

    
    private mutating func parseParenExpression() throws -> Expression {
        
        guard case .OpenParen = currentToken else { throw ParseError.ExpectedParen(currentPos) }
        getNextToken()
        
        let expr = try parseOperatorExpression()
        
        guard case .CloseParen = currentToken else { throw ParseError.ExpectedParen(currentPos) }
        getNextToken()
        
        return expr
        
    }
    
    
    private mutating func parseOperationRHS(precedence: Int = 0, lhs: Expression) throws -> Expression {
        
        switch currentToken {
        case .InfixOperator(let op):
            guard let tokenPrecedence = precedences[op] else { throw ParseError.NoOperator(currentPos) }
            // If the token we have encountered does not bind as tightly as the current precedence, return the current expression
            if tokenPrecedence < precedence {
                return lhs
            }
            
            // Get next operand
            getNextToken()
            
            // Error handling
            let rhs = try parsePrimary()
            
            // Get next operator
            guard case let .InfixOperator(nextOp) = currentToken else { return BinaryExpression(op: op, lhs: lhs, rhs: rhs) }
            guard let nextTokenPrecedence = precedences[nextOp] else { throw ParseError.NoOperator(currentPos) }
            
            let newRhs = try parseOperationRHS(tokenPrecedence, lhs: rhs)
            
            if tokenPrecedence < nextTokenPrecedence {
                return try parseOperationRHS(nextTokenPrecedence, lhs: BinaryExpression(op: op, lhs: lhs, rhs: newRhs))
            }
            return try parseOperationRHS(precedence + 1, lhs: BinaryExpression(op: op, lhs: lhs, rhs: rhs))
            
            // Collapse the postfix operator and continue parsing
        case .PostfixOperator(let op):
            
            getNextToken()
            let newLHS = PostfixExpression(op: op, expr: lhs)
            return try parseOperationRHS(precedence, lhs: newLHS)
            
        case .PrefixOperator(let op):

            getNextToken()
            let newLHS = PrefixExpression(op: op, expr: lhs)
            return try parseOperationRHS(precedence, lhs: newLHS)
            // Encountered a different token, return the lhs.
        default:
            return lhs
        }
    }
    
    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                              Control flow
    //-------------------------------------------------------------------------------------------------------------------------
    
    
    private mutating func parseIfExpression() throws -> Expression {
        
        getNextToken() // eat `if`
        let condition = try parseOperatorExpression()
        
        // list of blocks
        var blocks: [(condition: Expression?, block: ScopeExpression)] = []
        
        let usesBraces = currentToken.isBrace()
        // get if block & append
        guard currentToken.isControlToken() else { throw ParseError.ExpectedBrace(currentPos) }
        let block = try parseBlockExpression()
        blocks.append((condition, block))
        
        while case .Else = currentToken {
            
            var condition: Expression?
            
            if case .If? = inspectNextToken() {
                // `else if` statement
                getNextToken(); getNextToken()
                condition = try parseOperatorExpression()
                
                if usesBraces {
                    guard currentToken.isControlToken() else { throw ParseError.ExpectedBrace(currentPos) }
                }
                
            } else { condition = nil }
            
            let block = try parseBlockExpression()
            
            blocks.append((condition, block))
        }
        
        return try ConditionalExpression(statements: blocks)
    }
    
    
    private mutating func parseForInLoopExpression() throws -> ForInLoopExpression<RangeIteratorExpression> {
        
        getNextToken() // eat 'for'
        let itentifier = try parseTextExpression() // bind loop label
        guard case .In = getNextToken() else { throw ParseError.ExpectedIn(currentPos) }
        getNextToken() // eat 'in'
        
        let loop = try parseForInIterator()
        let block = try parseBlockExpression()
        
        return ForInLoopExpression(identifier: itentifier, iterator: loop, block: block)
    }
    
    private mutating func parseWhileLoopExpression() throws -> WhileLoopExpression<WhileIteratorExpression> {
        
        getNextToken() // eat 'while'
        
        let iterator = try parseWhileIterator()
        let block = try parseBlockExpression()
        
        return WhileLoopExpression(iterator: iterator, block: block)
    }

    
    private mutating func parseForInIterator() throws -> RangeIteratorExpression {
        
        guard
            let o = try parseOperatorExpression() as? BinaryExpression,
            let lhs = o.lhs as? IntegerType,
            let rhs = o.rhs as? IntegerType
            else { throw ParseError.NotIterator(currentPos) }
        
        return RangeIteratorExpression(s: lhs.val, e: rhs.val)
    }
    
    private mutating func parseWhileIterator() throws -> WhileIteratorExpression {

        let cond = try parseOperatorExpression()
        
        return WhileIteratorExpression(condition: cond)
    }
    
    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                              Variables
    //-------------------------------------------------------------------------------------------------------------------------
    
    
    private mutating func parseVariableAssignmentMutable(mutable: Bool) throws -> Expression {

        guard case let .Identifier(id) = getNextToken() else { throw ParseError.NoIdentifier(currentPos) }

        var explicitType: String?
        if case .Colon = getNextToken(), case let .Identifier(t) = getNextToken() {
            explicitType = t
            getNextToken()
        }
        
        guard case .Assign = currentToken else { throw ParseError.ExpectedAssignment(currentPos) }
        getNextToken() // eat '='
        
        var value = try parseOperatorExpression()
        
        let type = explicitType ?? ((value as? Typed)?.type as? ValueType)?.name
        if let a = type, let b = explicitType where a != b { throw ParseError.MismatchedType((a, inspectNextPos(-1)!), (b, inspectNextPos(-3)!)) }
        
        // if explicit assignment defines size, add info about this size to object
        if let ex = explicitType, var sized = value as? Sized  {
            let s = ex.componentsSeparatedByCharactersInSet(NSCharacterSet.decimalDigitCharacterSet().invertedSet).joinWithSeparator("")
            if let n = UInt32(s) {
                sized.size = n
                value = sized
                print(n)
            }
        }
        
        return Assignment(name: id, type: type, isMutable: mutable, value: value)
    }
    
    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                              Function
    //-------------------------------------------------------------------------------------------------------------------------
    
    private mutating func parseFunctionType() throws -> FunctionType {
        
        getNextToken()
        let params = try parseTypeTupleExpression()
        
        guard case .Returns = currentToken else {
            return FunctionType(args: params, returns: Tuple.void())
        }
        
        getNextToken()
        if case .OpenParen = currentToken {
            getNextToken()
            return FunctionType(args: params, returns: try parseTypeTupleExpression())
            
        } else if case let .Identifier(type) = currentToken {
            getNextToken()
            return FunctionType(args: params, returns: Tuple(elements: [ValueType(name: type)]))
            
        } else {
            throw ParseError.NoReturnType(currentPos)
        }
    }

    
    private mutating func parseFunctionDeclaration() throws -> FunctionPrototype {
        
        guard case let .Identifier(id) = getNextToken() else { throw ParseError.NoIdentifier(currentPos) }
        guard case .Colon = getNextToken() else { throw ParseError.ExpectedColon(currentPos) }
        
        getNextToken() // eat ':'
        let type = try parseFunctionType()
        
        guard case .Assign = currentToken else {
            return FunctionPrototype(name: id, type: type, impl: nil)
        }
        getNextToken() // eat '='
        
        return FunctionPrototype(name: id, type: type, impl: try parseClosureDeclaration(type: type))
    }
    
    private mutating func parseClosureDeclaration(anon anon: Bool = false, type: FunctionType) throws -> FunctionImplementation {
        let names: [Expression]
        
        if case .Bar = currentToken {
            getNextToken() // eat '|'
            
            var nms: [String] = []
            while true {
                if case let .Identifier(name) = currentToken {
                    nms.append(name)
                }
                
                if case .Comma = getNextToken() {   // more params
                    getNextToken()  // eat ','
                    continue        // move to next arg
                }
                if case .Bar = currentToken {       // end of param list
                    getNextToken()  // eat '|'
                    break
                }
                throw ParseError.ExpectedComma(currentPos)  // else throw error
            }
            names = nms.map{ ValueType.init(name: $0) }
            
        } else {
            names = (0..<type.args.elements.count).map{"$\($0)"}.map{ ValueType.init(name: $0) }
        }
        
        guard currentToken.isControlToken() else { throw ParseError.ExpectedBrace(currentPos) }
        
        return FunctionImplementation(params: Tuple(elements: names), body: try parseBlockExpression())
    }
    
    private mutating func parseBraceExpressions() throws -> Block {
        getNextToken() // eat '{'

        var expressions = [Expression]()
        
        while true {
            if case .CloseBrace = currentToken { break }
            
            do { expressions.append(try parseExpression(currentToken)) }
            catch ParseError.NoToken(.CloseParen, _) { break }
        }
        getNextToken() // eat '}'
        return Block(expressions: expressions)
    }
    
    private mutating func parseReturnExpression() throws -> Expression {
        getNextToken() // eat `return`
        
        return ReturnExpression(expression: try parseExpression(currentToken))
    }
    
    private mutating func parseBracelessDoExpression() throws -> Block {
        getNextToken() // eat 'do'
        
        let ex = try parseExpression(currentToken)
        
        return Block(expressions: [ex])
    }
    
    private mutating func parseBlockExpression() throws -> Block {
        
        switch currentToken {
        case .OpenBrace:    return try parseBraceExpressions()
        case .Do, .Else:    return try parseBracelessDoExpression()
        default:            throw ParseError.NotBlock(currentPos)
        }
        
    }
    
    
    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                              Other
    //-------------------------------------------------------------------------------------------------------------------------
    
    private mutating func parseCommentExpression(str: String) throws -> Expression {
        getNextToken() //eat comment
        return Comment(str: str)
    }

    
    
    
    //-------------------------------------------------------------------------------------------------------------------------
    //  MARK:                                           AST Generator
    //-------------------------------------------------------------------------------------------------------------------------

    
    /// parses any token, starts new scopes
    ///
    /// promises that the input token will be consumed
    private mutating func parseExpression(token: Token) throws -> Expression {
        
        switch token {
        case     .Let:                  return try parseVariableAssignmentMutable(false)
        case     .Var:                  return try parseVariableAssignmentMutable(true)
        case     .Func:                 return try parseFunctionDeclaration()
        case     .Return:               return try parseReturnExpression()
        case     .OpenParen:            return try parseParenExpression()
        case     .OpenBrace:            return try parseBraceExpressions()
        case let .Identifier(str):      return try parseIdentifierExpression(str)
        case     .InfixOperator:        return try parseOperatorExpression()
        case let .Comment(str):         return try parseCommentExpression(str)
        case     .If:                   return try parseIfExpression()
        case     .For:                  return try parseForInLoopExpression()
        case     .Do:                   return try parseBracelessDoExpression()
        case     .While:                return try parseWhileLoopExpression()
        case let .Integer(i):           return parseIntExpression(i)
        case let .FloatingPoint(x):     return parseFloatingPointExpression(x)
        case let .Str(str):             return parseStringExpression(str)
        case     .Void:                 index++; return Void()
        case     .EOF, .CloseBrace:     index++; return EndOfScope()
        default:                        throw ParseError.NoToken(token, currentPos)
        }
    }
    
    private func tok() -> Token? { return index < tokens.count ? tokens[index] : nil }
    
    /// Returns abstract syntax tree from an instance of a parser
    ///
    /// [Detailed here](http://llvm.org/docs/tutorial/LangImpl2.html)
    mutating func parse() throws -> AST {
        
        index = 0
        expressions = []
        
        while let tok = tok() {
            expressions.append(try parseExpression(tok))
        }
        
        expressions = expressions.filter { !($0 is EndOfScope) }
        
        return AST(expressions: expressions)
    }
    
    
}





