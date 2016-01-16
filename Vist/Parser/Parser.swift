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
    case NoIdentifier(Pos), NoBracket(Pos)
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
    case ObjectNotAllowedInTopLevelOfTypeImpl(Token, Pos), NoTypeName(Pos)
    case NoPrecedenceForOperator(String, Pos), OpDoesNotHaveParams(Pos), CannotChangeOpPrecedence(String, Int, Pos)
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
    
    private let isStdLib: Bool
    
    private var attrs: [AttributeExpression]
    
    private var precedences: [String: Int] = [
        "<": 30,
        ">": 30,
        "<=": 30,
        ">=": 30,
        "+": 80,
        "-": 80,
        "*": 100,
        "/": 100,
        "%": 90,
        "||": 10,
        "&&": 15,
        "==": 20,
        "!=": 20,
        "...": 40,
        "..<": 40
    ]
    
    private mutating func getNextToken(n: Int = 1) -> Token {
        index += n
        return currentToken
    }
    private func inspectNextToken(i: Int = 1) -> Token? { // debug function, acts as getNextToken() but does not mutate
        return index < tokens.count-i ? tokens[index+i] : nil
    }
    private func inspectNextPos(i: Int = 1) -> Pos? {
        return index < tokens.count-i ? tokensWithPos.map{$0.1.range.start}[index+i] : nil
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Literals
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseIntExpression(token: Int) throws -> Expression {
        getNextToken()
        let i = IntegerLiteral(val: token)
        
        if case .Period? = inspectNextToken() where isStdLib {
            getNextToken()
            return try parseMemberLookupExpression(i)
        }
        
        return i
    }
    private mutating func parseFloatingPointExpression(token: Double) -> FloatingPointLiteral {
        getNextToken()
        return FloatingPointLiteral(val: token)
    }
    private mutating func parseStringExpression(token: String) -> StringLiteral {
        getNextToken()
        return StringLiteral(str: token)
    }
    private mutating func parseBooleanExpression(token: Bool) throws -> Expression {
        getNextToken()
        let b = BooleanLiteral(val: token)
        
        if case .Period? = inspectNextToken() where isStdLib {
            getNextToken()
            return try parseMemberLookupExpression(b)
        }
        
        return b
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
            return alwaysWrap ? TupleExpression(elements: []) : ValueType(name: "Void")
        }
        
        var elements = [Expression]()
        loop: while true {
            switch currentToken {
            case let .Identifier(id):
                
                // handle native llvm type in stdlib
                if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where id == "LLVM" && isStdLib {
                    elements.append(ValueType(name: "LLVM.\(n)"))    // param
                    getNextToken(3)// eat LLVM.Id
                }
                else {
                    elements.append(ValueType(name: id))    // param
                    getNextToken()
                }

            case .SqbrOpen:
                guard case .Identifier(let id) = getNextToken() else { throw ParseError.NoIdentifier(currentPos) }
                
                // handle native llvm type in stdlib
                if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where id == "LLVM" && isStdLib {
                    elements.append(ValueType(name: "LLVM.\(n)"))    // param
                    getNextToken(2)// eat LLVM.Id
                }
                else {
                    elements.append(ValueType(name: id))    // param
                    getNextToken()
                }
                guard case .SqbrClose = getNextToken() else { throw ParseError.NoBracket(currentPos) }
                getNextToken() // eat ]
                
            default:
                break loop
            }
        }
        
        if let f = elements.first where elements.count == 1 && !alwaysWrap {
            return f
        }
        else {
            return TupleExpression(elements: elements)
        }
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                      Identifier and operators
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    private mutating func parseTextExpression() throws -> Variable {
        guard case .Identifier(let i) = currentToken else {
            throw ParseError.NoIdentifier(currentPos) }
        return Variable(name: i)
    }
    
    /// Handles parsing of a text token
    private mutating func parseIdentifierExpression(token: String) throws -> Expression {
        
        switch inspectNextToken() {
        case .OpenParen?: // call
            getNextToken() // eat 'identifier'
            
            if case .CloseParen? = inspectNextToken() {   // simple itentifier() call
                getNextToken(2) // eat '()'
                return FunctionCallExpression(name: token, args: TupleExpression.void())
            }
            
            return FunctionCallExpression(name: token, args: try parseTupleExpression())
            
        case .SqbrOpen?: // subscript
            getNextToken(2) // eat 'identifier['
            
            let subscpipt = try parseOperatorExpression()
            
            getNextToken() // eat ']'
            
            
            guard case .Assign = currentToken else { // if call
                return ArraySubscriptExpression(arr: Variable(name: token), index: subscpipt)
            }
            getNextToken() // eat '='
            
            let exp = try parseOperatorExpression()
            // if assigning to subscripted value
            return MutationExpression(object: ArraySubscriptExpression(arr: Variable(name: token), index: subscpipt), value: exp)
            
        case .Assign?: // mutation
            getNextToken(2)// eat 'identifier ='
            
            let exp = try parseOperatorExpression()
            
            return MutationExpression(object: Variable(name: token), value: exp)
            
        case .Period? where token == "LLVM" && isStdLib:
            getNextToken(2) // eat 'LLVM.'
            
            guard case .Identifier(let id) = currentToken else { fatalError() }
            return try parseIdentifierExpression("LLVM.\(id)")
            
        case .Period?: // property or fn
            getNextToken(2) // eat `.`
            
            return try parseMemberLookupExpression(Variable(name: token))
            
        default: // just identifier
            defer { getNextToken() }
            return try parseOperatorExpression(Variable(name: token))
        }
    }
    
    private mutating func parseMemberLookupExpression<Exp : Expression>(exp: Exp) throws -> Expression {
        
        switch currentToken {
        case .Identifier(let name):
            
            switch getNextToken() {
            case .OpenParen:
                
                if case .CloseParen = currentToken {   // simple itentifier() call
                    getNextToken(2) // eat ')'
                    return MethodCallExpression(name: name, params: TupleExpression.void(), object: exp)
                }
                
                return MethodCallExpression(name: name, params: try parseTupleExpression(), object: exp)
                
            case .Assign:
                getNextToken() // eat =
                
                let property = PropertyLookupExpression(name: name, object: exp)
                
                let exp = try parseOperatorExpression()
                return MutationExpression(object: property, value: exp)
                
            default:
                return PropertyLookupExpression(name: name, object: exp)
            }
            
        case .Integer(let i):
            
            switch getNextToken() {
            case .Assign:
                getNextToken() // eat =
                
                let property = TupleMemberLookupExpression(index: i, object: exp)
                
                let exp = try parseOperatorExpression()
                return MutationExpression(object: property, value: exp)
                
            default:
                return TupleMemberLookupExpression(index: i, object: exp)
            }
            
        default:
            throw ParseError.NoIdentifier(currentPos)
        }
        
    }
    
    
    /// Function called on `return a + 1` and `if a < 3` etc
    ///
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
            return try parseIntExpression(i)
            
        case let .FloatingPoint(f):
            return parseFloatingPointExpression(f)
            
        case let .Boolean(b):
            return try parseBooleanExpression(b)
            
        case .OpenParen:
            return try parseParenExpression(tuple: false)
            
        case .SqbrOpen:
            return try parseArrayExpression()
            
        case let .StringLiteral(str):
            return parseStringExpression(str)
            
        case .OpenBrace, .Do, .Bar:
            let block = try parseBlockExpression()
            let closure = ClosureExpression(expressions: block.expressions, params: block.variables.map { $0.name })
            return closure
            
        default:
            throw ParseError.NoIdentifier(currentPos)
        }
    }
    
    private mutating func parseTupleExpression() throws -> TupleExpression {
        return try parseParenExpression(tuple: true) as! TupleExpression
    }
    
    /// Guarantees if tuple is true, the return type is a TupleExpression
    private mutating func parseParenExpression(tuple tuple: Bool) throws -> Expression {
        
        guard case .OpenParen = currentToken else { throw ParseError.ExpectedParen(currentPos) }
        getNextToken() // eat `(`
        
        var exps: [Expression] = []
        
        while true {
            if case .CloseParen = currentToken { break }
            exps.append(try parseOperatorExpression())
        }
        getNextToken() // eat `)`
        
        switch exps.count {
        case 0: return TupleExpression.void()
        case 1: return tuple ? TupleExpression(elements: exps) : exps[0]
        case _: return TupleExpression(elements: exps)
        }
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
            
            if tokenPrecedence <= nextTokenPrecedence {
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
                getNextToken(2)
                condition = try parseOperatorExpression()
                
                if usesBraces {
                    guard currentToken.isControlToken() else { throw ParseError.ExpectedBrace(currentPos) }
                }
            }
            else {
                getNextToken()
                condition = nil
            }
            
            let block = try parseBlockExpression()
            
            blocks.append((condition, block))
        }
        
        return try ConditionalExpression<BlockExpression>(statements: blocks)
    }
    
    
    private mutating func parseForInLoopExpression() throws -> ForInLoopExpression<BlockExpression> {
        
        getNextToken() // eat 'for'
        let itentifier = try parseTextExpression() // bind loop label
        guard case .In = getNextToken() else { throw ParseError.ExpectedIn(currentPos) }
        getNextToken() // eat 'in'
        
        let loop = try parseOperatorExpression()
        let block = try parseBlockExpression()
        
        return ForInLoopExpression(identifier: itentifier, iterator: loop, block: block)
    }
    
    private mutating func parseWhileLoopExpression() throws -> WhileLoopExpression<BlockExpression> {
        
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
    
    private mutating func parseVariableAssignmentMutable(mutable: Bool, requiresInitialValue: Bool = true) throws -> AssignmentExpression {
        
        guard case let .Identifier(id) = getNextToken() else { throw ParseError.NoIdentifier(currentPos) }
        
        var explicitType: String?
        if case .Colon = getNextToken(), case let .Identifier(t) = getNextToken() {
            
            // handle stdlib case of native types
            if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where t == "LLVM" && isStdLib {
                explicitType = "LLVM.\(n)"
                getNextToken(3) // eat LLVM.Id
            }
            else {
                explicitType = t
                getNextToken()
            }
            
        }
        
        // TODO: Closure declaration parsing
        
        guard case .Assign = currentToken else {
            if requiresInitialValue || explicitType == nil {
                throw ParseError.ExpectedAssignment(currentPos)
            }
            else {
                return AssignmentExpression(name: id, type: explicitType, isMutable: mutable, value: NullExpression())
            }
        }
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
            else if explicitType == "Float" {
                sized.size = 32
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
        
        let a = attrs.flatMap { $0 as? FunctionAttributeExpression } ?? []
        let ops = attrs.flatMap { $0 as? ASTAttributeExpression }.flatMap { a -> Int? in if case .Operator(let p) = a { return p } else { return nil } }.last
        attrs = []
        
        getNextToken()
        let s: String
        if case .Identifier(let n) = currentToken {
            s = n
        }
        else if case .InfixOperator(let o) = currentToken, let pp = ops {
            s = o
            
            let found = precedences[o]
            if let x = found where x != ops { // make sure uses op’s predetermined prec
                throw ParseError.CannotChangeOpPrecedence(o, x, currentPos)
            }
            else if found == nil {
                precedences[o] = pp // update prec table if not found
            }
        }
        else {
            throw ParseError.NoIdentifier(currentPos)
        }
        
        let id: String
        if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where s == "LLVM" && isStdLib {
            id = "LLVM.\(n)"
            getNextToken(2) // eat
        }
        else {
            id = s
        }
        
        guard case .Colon = getNextToken() else { throw ParseError.ExpectedColon(currentPos) }
        
        getNextToken() // eat ':'
        let type = try parseFunctionType()
        
        guard case .Assign = currentToken else {
            return FunctionPrototypeExpression(name: id, type: type, impl: nil, attrs: a)
        }
        getNextToken() // eat '='
        
        return FunctionPrototypeExpression(name: id, type: type, impl: try parseClosureDeclaration(type: type), attrs: a)
    }
    
    private mutating func parseClosureNamesExpression() throws -> [ValueType] {
        
        guard case .Bar = currentToken else { return [] }
        getNextToken() // eat '|'
        
        var nms: [String] = []
        while case let .Identifier(name) = currentToken {
            nms.append(name)
            getNextToken()
        }
        guard case .Bar = currentToken else { throw ParseError.ExpectedBar(currentPos) }
        guard getNextToken().isControlToken() else { throw ParseError.NotBlock(currentPos) }
        
        return nms.map { ValueType.init(name: $0) }
    }
    
    private mutating func parseClosureDeclaration(anon anon: Bool = false, type: FunctionType) throws -> FunctionImplementationExpression {
        let names: [Expression]
        
        if case .Bar = currentToken {
            names = try parseClosureNamesExpression()
                .map { $0 as Expression }
        }
        else {
            names = (0..<type.args.elements.count)
                .map {"$\($0)"}
                .map { ValueType.init(name: $0) }
        }
        
        guard currentToken.isControlToken() else { throw ParseError.ExpectedBrace(currentPos) }
        
        return FunctionImplementationExpression(params: TupleExpression(elements: names), body: try parseBlockExpression())
    }
    
    private mutating func parseBraceExpression(names: [ValueType] = []) throws -> BlockExpression {
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
        return BlockExpression(expressions: expressions, variables: names)
    }
    
    private mutating func parseReturnExpression() throws -> Expression {
        getNextToken() // eat `return`
        
        return ReturnExpression(expression: try parseOperatorExpression())
    }
    
    private mutating func parseBracelessDoExpression(names: [ValueType] = []) throws -> BlockExpression {
        getNextToken() // eat 'do'
        
        guard let ex = try parseExpression(currentToken) else { throw ParseError.NoToken(currentToken, currentPos) }
        
        return BlockExpression(expressions: [ex], variables: names)
    }
    
    private mutating func parseBlockExpression(names: [ValueType] = []) throws -> BlockExpression {
        
        switch currentToken {
        case .Bar:          return try parseBlockExpression(try parseClosureNamesExpression())
        case .OpenBrace:    return try parseBraceExpression(names)
        case .Do, .Else:    return try parseBracelessDoExpression(names)
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
                
            case .SqbrClose:
                getNextToken() // eat ']'
                return ArrayExpression(arr: elements)
                
            default:
                
                elements.append(try parseOperatorExpression())    // param
            }
        }
        
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Type
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseTypeDeclarationExpression(byRef byRef: Bool) throws -> StructExpression {
        
        let a = attrs
        attrs = []
        
        getNextToken() // eat 'type'
        
        guard case .Identifier(let name) = currentToken else { throw ParseError.NoTypeName(currentPos) }
        getNextToken() // eat name
        guard case .OpenBrace = currentToken else { throw ParseError.ExpectedBrace(currentPos) }
        getNextToken() // eat '{'
        
        var properties: [AssignmentExpression] = [], methods: [FunctionPrototypeExpression] = [], initialisers: [InitialiserExpression] = []
        
        while true {
            
            if case .CloseBrace = currentToken { break }

            switch currentToken {
            case .Var:
                properties.append(try parseVariableAssignmentMutable(true, requiresInitialValue: false))
                
            case .Let:
                properties.append(try parseVariableAssignmentMutable(false, requiresInitialValue: false))
                
            case .Func:
                methods.append(try parseFunctionDeclaration())
                
            case .Init:
                initialisers.append(try parseInitDeclaration())
                
            case .At:
                try parseAttrExpression()
                
            case .Comment(let c):
                try parseCommentExpression(c)
                
            default:
                throw ParseError.ObjectNotAllowedInTopLevelOfTypeImpl(currentToken, currentPos)
            }
            
        }
        
        let s = StructExpression(name: name, properties: properties, methods: methods, initialisers: initialisers, attrs: a)
        for i in s.initialisers {
            i.parent = s
        }
        return s
    }
    
    private mutating func parseInitDeclaration() throws -> InitialiserExpression {
        
        getNextToken() // eat `init`
        let type = try parseFunctionType()
        guard case .Assign = currentToken else {
            return InitialiserExpression(ty: type, impl: nil, parent: nil)
        }
        getNextToken() // eat `=`
        
        return InitialiserExpression(ty: type, impl: try parseClosureDeclaration(type: type), parent: nil)
    }
    
}











//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Other
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    // TODO: Fix how this gets in the way of other things
    private mutating func parseCommentExpression(str: String) throws -> Expression {
        getNextToken() //eat comment
        return CommentExpression(str: str)
    }
    
    private mutating func parseAttrExpression() throws {
        getNextToken() // eat @
        
        if case .Identifier(let id) = currentToken {
            
            if case .OpenParen? = inspectNextToken() {
                getNextToken(2)
                
                switch id {
                case "operator":
                    guard let i = try parseOperatorExpression() as? IntegerLiteral else { throw ParseError.NoPrecedenceForOperator(id, currentPos) }
                    attrs.append(ASTAttributeExpression.Operator(prec: i.val))
                    
                default:
                    throw ParseError.OpDoesNotHaveParams(currentPos)
                }
                
                guard case .CloseParen = currentToken else { throw ParseError.ExpectedParen(currentPos) }
                getNextToken()
            }
            else if let a = FunctionAttributeExpression(rawValue: id) {
                getNextToken()
                attrs.append(a)
            }
            
        }
        
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
        case .OpenParen:            return try parseParenExpression(tuple: true)
        case .OpenBrace:            return try parseBraceExpression()
        case .Identifier(let str):  return try parseIdentifierExpression(str)
        case .InfixOperator:        return try parseOperatorExpression()
        case .Comment(let str):     return try parseCommentExpression(str)
        case .If:                   return try parseIfExpression()
        case .For:                  return try parseForInLoopExpression()
        case .Do:                   return try parseBracelessDoExpression()
        case .While:                return try parseWhileLoopExpression()
        case .SqbrOpen:             return try parseArrayExpression()
        case .Type:                 return try parseTypeDeclarationExpression(byRef: false)
        case .Reference:            getNextToken(); return try parseTypeDeclarationExpression(byRef: true)
        case .Integer(let i):       return  try parseIntExpression(i)
        case .FloatingPoint(let x): return parseFloatingPointExpression(x)
        case .Str(let str):         return parseStringExpression(str)
        case .At:                   try parseAttrExpression(); return nil
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

    init(tokens: [(Token, SourceLoc)], isStdLib: Bool = false) {
        self.tokensWithPos = tokens.filter {
            if case .Comment = $0.0 { return false } else { return true }
        }
        self.isStdLib = isStdLib
        self.attrs = []
    }
    
}





