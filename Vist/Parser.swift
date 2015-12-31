//
//  Parser.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

enum ParseError: ErrorType {
    case ExpectedParen(Pos),  ExpectedCloseBracket(Pos), NoToken(Token, Pos), ExpectedComma(Pos), ExpectedBrace(Pos)
    case InvalidOperator(Pos), InvalidCall(String, Pos) // cant call (*2) or (.print())
    case NoIdentifier(Pos)
    case ExpectedColon(Pos), NoReturnType(Pos)
    case ExpectedAssignment(Pos), ExpectedBar(Pos)
    case NoExpression(Pos)
    case NoOperator(Pos)
    case MismatchedType((String, Pos), (String, Pos))
    case InvalidIfStatement
    case ExpectedIn(Pos), ExpectedDo(Pos)
    case NotIterator(Pos)
    case NotBlock(Pos)
    case SubscriptNotIntegerType(Pos)
    case ObjectNotAllowedInTopLevelOfTypeImpl(Pos), NoTypeName(Pos)
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
        "<": 30,
        ">": 30,
        "<=": 30,
        ">=": 30,
        "+": 80,
        "-": 80,
        "*": 100,
        "/": 100,
        "%": 70,
        "||": 10,
        "&&": 10,
        "==": 20,
        "!=": 20,
        "...": 40
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
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Literals
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
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
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                   Tuple
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    ///parses expression like Int String, of type _identifier _identifier
    private mutating func parseTypeExpression(alwaysWrap alwaysWrap: Bool = true) throws -> Expression {
        
        // if () type
        if case .OpenParen = currentToken, case .CloseParen = getNextToken() {
            getNextToken() // eat ')'
            if alwaysWrap {
                return TupleExpression(elements: [ValueType(name: "Void")])
            } else {
                return ValueType(name: "Void")
            }
        }
        
        var elements = [Expression]()
        while case let .Identifier(id) = currentToken {
            elements.append(ValueType(name: id))    // param
            getNextToken()
        }
        
        if let f = elements.first where elements.count == 1 && !alwaysWrap {
            return f
            
        } else {
            return TupleExpression(elements: elements)
        }
    }
    
    private mutating func parseTupleExpression() throws -> TupleExpression {
        
        var elements = [Expression]()
        while true {
            
            elements.append(try parseOperatorExpression())
            
            if case .CloseParen = currentToken {
                getNextToken()
                return TupleExpression(elements: elements)
            }
        }
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                      Identifier and operators
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    private mutating func parseTextExpression() throws -> Variable<AnyExpression> {
        guard case .Identifier(let i) = currentToken else { throw ParseError.NoIdentifier(currentPos) }
        return Variable(name: i)
    }
    
    /// Handles parsing of a text token
    private mutating func parseIdentifierExpression(token: String) throws -> Expression {
        
        switch inspectNextToken() {
        case .OpenParen?: // call
            getNextToken(); getNextToken() // eat 'identifier('
            
            if case .CloseParen = currentToken {   // simple itentifier() call
                getNextToken() // eat ')'
                return FunctionCallExpression(name: token, args: TupleExpression(elements: []))
            }
            
            return FunctionCallExpression(name: token, args: try parseTupleExpression())
            
        case .SqbrOpen?: // subscript
            getNextToken(); getNextToken() // eat 'identifier['
            
            let subscpipt = try parseOperatorExpression()
            
            getNextToken() // eat ']'
            
            
            guard case .Assign = currentToken else { // if call
                return ArraySubscriptExpression(arr: Variable<AnyExpression>(name: token), index: subscpipt)
            }
            getNextToken() // eat '='
            
            let exp = try parseOperatorExpression()
            // if assigning to subscripted value
            return MutationExpression(object: ArraySubscriptExpression(arr: Variable<AnyExpression>(name: token), index: subscpipt), value: exp)
            
        case .Assign?: // mutation
            getNextToken(); getNextToken() // eat 'identifier ='
            
            let exp = try parseOperatorExpression()
            
            return MutationExpression(object: Variable<AnyExpression>(name: token), value: exp)
            
        default: // just identifier
            defer { getNextToken() }
            return try parseOperatorExpression(Variable<AnyExpression>(name: token))
        }
    }
    
    /// Function called on `return a + 1` and `if a < 3`
    /// exp can be optionally defined as a known lhs operand to give more info to the parser
    private mutating func parseOperatorExpression(exp: Expression? = nil, prec: Int = 0) throws -> Expression {
        return try parseOperationRHS(prec, lhs: exp ?? (try parsePrimary()))
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
            
        case .SqbrOpen:
            return try parseArrayExpression()
            
        case .OpenBrace, .Do:
            let block = try parseBlockExpression()
            let closure = ClosureExpression(expressions: block.expressions, params: [])
            // set the params by looking at |the bit| before the block
            return closure
            
        default:
            throw ParseError.NoIdentifier(currentPos)
        }
    }
    
    
    private mutating func parseParenExpression() throws -> Expression {
        
        guard case .OpenParen = currentToken else { throw ParseError.ExpectedParen(currentPos) }
        getNextToken() // eat '('
        
        // if void tuple
        if case .CloseParen = currentToken {
            getNextToken() // eat void
            return TupleExpression.void()
        }
        
        let expr = try parseOperatorExpression()
        
        guard case .CloseParen = currentToken else { throw ParseError.ExpectedParen(currentPos) }
        getNextToken() // eat ')'
        
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
            guard case .InfixOperator(let nextOp) = currentToken else { return BinaryExpression(op: op, lhs: lhs, rhs: rhs) }
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
            
        default: // Encountered a different token, return the lhs.
            return lhs
        }
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseIfExpression() throws -> Expression {
        
        getNextToken() // eat `if`
        let condition = try parseOperatorExpression()
        
        // list of blocks
        var blocks: [(condition: Expression?, block: BlockExpression)] = []
        
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
            
            //            if usesBraces {
            getNextToken()
            //            }
            
            let block = try parseBlockExpression()
            
            blocks.append((condition, block))
        }
        
        return try ConditionalExpression<BlockExpression>(statements: blocks)
    }
    
    
    private mutating func parseForInLoopExpression() throws -> ForInLoopExpression<RangeIteratorExpression, AnyExpression, BlockExpression> {
        
        getNextToken() // eat 'for'
        let itentifier = try parseTextExpression() // bind loop label
        guard case .In = getNextToken() else { throw ParseError.ExpectedIn(currentPos) }
        getNextToken() // eat 'in'
        
        let loop = try parseForInIterator()
        let block = try parseBlockExpression()
        
        return ForInLoopExpression(identifier: itentifier, iterator: loop, block: block)
    }
    
    private mutating func parseWhileLoopExpression() throws -> WhileLoopExpression<WhileIteratorExpression, BlockExpression> {
        
        getNextToken() // eat 'while'
        
        let iterator = try parseWhileIterator()
        let block = try parseBlockExpression()
        
        return WhileLoopExpression(iterator: iterator, block: block)
    }
    
    
    private mutating func parseForInIterator() throws -> RangeIteratorExpression {
        
        guard let o = try parseOperatorExpression() as? BinaryExpression else { throw ParseError.NotIterator(currentPos) }
        
        return RangeIteratorExpression(s: o.lhs, e: o.rhs)
    }
    
    private mutating func parseWhileIterator() throws -> WhileIteratorExpression {
        
        let cond = try parseOperatorExpression()
        
        return WhileIteratorExpression(condition: cond)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseVariableAssignmentMutable(mutable: Bool) throws -> AssignmentExpression {
        
        guard case let .Identifier(id) = getNextToken() else { throw ParseError.NoIdentifier(currentPos) }
        
        var explicitType: String?
        if case .Colon = getNextToken(), case let .Identifier(t) = getNextToken() {
            explicitType = t
            getNextToken()
        }
        
        // TODO: Closure declaration parsing
        
        guard case .Assign = currentToken else { throw ParseError.ExpectedAssignment(currentPos) }
        getNextToken() // eat '='
        
        var value = try parseOperatorExpression()
        
        let type = explicitType ?? (value as? ExplicitlyTyped)?.explicitType
        if let a = type, let b = explicitType where a != b { throw ParseError.MismatchedType((a, inspectNextPos(-1)!), (b, inspectNextPos(-3)!)) }
        
        // if explicit assignment defines size, add info about this size to object
        if let ex = explicitType, var sized = value as? Sized  {
            let s = ex.componentsSeparatedByCharactersInSet(NSCharacterSet.decimalDigitCharacterSet().invertedSet).joinWithSeparator("")
            if let n = UInt32(s) {
                sized.size = n
                value = sized
            }
        }
        
        return AssignmentExpression(name: id, type: type, isMutable: mutable, value: value)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Function
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parses the function type signature
    private mutating func parseFunctionType() throws -> FunctionType {

        // param type
        let p = try parseTypeExpression() as! TupleExpression
        
        // case like fn: Int =
        guard case .Returns = currentToken else {
            return FunctionType(args: p, returns: ValueType(name: "Void"))
        }
        getNextToken() // eat '->'
        
        let r = try parseTypeExpression(alwaysWrap: false)
        
        // case like fn: Int -> Int =
        guard case .Returns = currentToken else {
            return FunctionType(args: p, returns: r)
        }

        var ty = FunctionType(args: p, returns: r)
        
        // curried case like fn: Int -> Int -> Int
        while case .Returns = currentToken {
            getNextToken()

            let params = TupleExpression(elements: [ty.returns])
            let returns = try parseTypeExpression()
            let out = FunctionType(args: params, returns: returns)
            
            ty = FunctionType(args: ty.args, returns: out)
        }
        
        return ty
    }
    
    
    private mutating func parseFunctionDeclaration() throws -> FunctionPrototypeExpression {
        
        guard case let .Identifier(id) = getNextToken() else { throw ParseError.NoIdentifier(currentPos) }
        guard case .Colon = getNextToken() else { throw ParseError.ExpectedColon(currentPos) }
        
        getNextToken() // eat ':'
        let type = try parseFunctionType()
        
        guard case .Assign = currentToken else {
            return FunctionPrototypeExpression(name: id, type: type, impl: nil)
        }
        getNextToken() // eat '='
        
        return FunctionPrototypeExpression(name: id, type: type, impl: try parseClosureDeclaration(type: type))
    }
    
    private mutating func parseClosureDeclaration(anon anon: Bool = false, type: FunctionType) throws -> FunctionImplementationExpression {
        let names: [Expression]
        
        if case .Bar = currentToken {
            getNextToken() // eat '|'
            
            var nms: [String] = []
            while case let .Identifier(name) = currentToken {
                nms.append(name)
                getNextToken()
            }
            guard case .Bar = currentToken else { throw ParseError.ExpectedBar(currentPos) }
            guard getNextToken().isControlToken() else { throw ParseError.NotBlock(currentPos) }
            names = nms.map{ ValueType.init(name: $0) }
            
        } else {
            names = (0..<type.args.elements.count).map{"$\($0)"}.map{ ValueType.init(name: $0) }
        }
        
        guard currentToken.isControlToken() else { throw ParseError.ExpectedBrace(currentPos) }
        
        return FunctionImplementationExpression(params: TupleExpression(elements: names), body: try parseBlockExpression())
    }
    
    private mutating func parseBraceExpressions() throws -> BlockExpression {
        getNextToken() // eat '{'
        
        var expressions = [Expression]()
        
        while true {
            if case .CloseBrace = currentToken { break }
            
            do {
                guard let exp = try parseExpression(currentToken) else { throw ParseError.NoToken(currentToken, currentPos) }
                expressions.append(exp)
            }
            catch ParseError.NoToken(.CloseParen, _) { break }
        }
        getNextToken() // eat '}'
        return BlockExpression(expressions: expressions)
    }
    
    private mutating func parseReturnExpression() throws -> Expression {
        getNextToken() // eat `return`
        
        return ReturnExpression(expression: try parseOperatorExpression())
    }
    
    private mutating func parseBracelessDoExpression() throws -> BlockExpression {
        getNextToken() // eat 'do'
        
        guard let ex = try parseExpression(currentToken) else { throw ParseError.NoToken(currentToken, currentPos) }
        
        return BlockExpression(expressions: [ex])
    }
    
    private mutating func parseBlockExpression() throws -> BlockExpression {
        
        switch currentToken {
        case .OpenBrace:    return try parseBraceExpressions()
        case .Do, .Else:    return try parseBracelessDoExpression()
        default:            throw ParseError.NotBlock(currentPos)
        }
        
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Array
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseArrayExpression() throws -> Expression {
        
        getNextToken() // eat '['
        
        var elements = [Expression]()
        while true {
            
            switch currentToken {
            case .Comma:
                getNextToken()  // eat ','
                
            case .SqrbrClose:
                getNextToken() // eat ']'
                return ArrayExpression(arr: elements)
                
            default:
                
                elements.append(try parseOperatorExpression())    // param
            }
        }
        
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Other
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseTypeExpression(byRef byRef: Bool) throws -> StructExpression {
        getNextToken() // eat 'type'
        
        guard case .Identifier(let name) = currentToken else { throw ParseError.NoTypeName(currentPos) }
        getNextToken() // eat name
        guard case .OpenBrace = currentToken else { throw ParseError.ExpectedBrace(currentPos) }
        getNextToken() // eat '{'
        
        var properties: [AssignmentExpression] = [], methods: [FunctionPrototypeExpression] = []
        
        while true {
            
            switch currentToken {
                
            case .Var:
                properties.append(try parseVariableAssignmentMutable(true))
                
            case .Let:
                properties.append(try parseVariableAssignmentMutable(true))
                
            case .Func:
                methods.append(try parseFunctionDeclaration())
                
            default:
                throw ParseError.ObjectNotAllowedInTopLevelOfTypeImpl(currentPos)
            }
            
            if case .CloseBrace = currentToken { break }
        }
        
        return StructExpression(name: name, properties: properties, methods: methods)
    }
    
}











//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Other
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    private mutating func parseCommentExpression(str: String) throws -> Expression {
        getNextToken() //eat comment
        return CommentExpression(str: str)
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                           AST Generator
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// parses any token, starts new scopes
    ///
    /// promises that the input token will be consumed
    private mutating func parseExpression(token: Token) throws -> Expression? {
        
        switch token {
        case .Let:                  return try parseVariableAssignmentMutable(false)
        case .Var:                  return try parseVariableAssignmentMutable(true)
        case .Func:                 return try parseFunctionDeclaration()
        case .Return:               return try parseReturnExpression()
        case .OpenParen:            return try parseParenExpression()
        case .OpenBrace:            return try parseBraceExpressions()
        case .Identifier(let str):  return try parseIdentifierExpression(str)
        case .InfixOperator:        return try parseOperatorExpression()
        case .Comment(let str):     return try parseCommentExpression(str)
        case .If:                   return try parseIfExpression()
        case .For:                  return try parseForInLoopExpression()
        case .Do:                   return try parseBracelessDoExpression()
        case .While:                return try parseWhileLoopExpression()
        case .SqbrOpen:             return try parseArrayExpression()
        case .Type:                 return try parseTypeExpression(byRef: false)
        case .Reference:            getNextToken(); return try parseTypeExpression(byRef: true)
        case .Integer(let i):       return parseIntExpression(i)
        case .FloatingPoint(let x): return parseFloatingPointExpression(x)
        case .Str(let str):         return parseStringExpression(str)
        case .Void:                 index++; return Void()
        case .EOF, .CloseBrace:     index++; return nil
        default:                    throw ParseError.NoToken(token, currentPos)
        }
    }
    
    // TODO: if statements have return type
    // TODO: Implicit return if a block only has 1 expression
    
    private func tok() -> Token? { return index < tokens.count ? tokens[index] : nil }
    
    /// Returns abstract syntax tree from an instance of a parser
    ///
    /// [Detailed here](http://llvm.org/docs/tutorial/LangImpl2.html)
    mutating func parse() throws -> AST {
        
        index = 0
        expressions = []
        
        while let tok = tok() {
            if let exp = try parseExpression(tok) {
                expressions.append(exp)
            }
        }
        
        return AST(expressions: expressions)
    }
    
    
}





