//
//  Parser.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


private extension Array {
    mutating func removeLastSafely(str str: String, pos: Pos) throws -> Generator.Element {
        if self.isEmpty { throw error(ParseError.InvalidCall(str), loc: SourceRange.at(pos)) } else { return removeLast() }
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
    
    private var exprs = [ASTNode]()
    
    private var tokens: [Token]     { return tokensWithPos.map{$0.0} }
    private var currentToken: Token { return tokens[index] }
    private var currentPos: Pos     { return tokensWithPos.map{$0.1.range.start}[index] }
    
    private let isStdLib: Bool
    
    private var attrs: [AttributeExpr]
    
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
        if n == 0 { return currentToken }
        index += 1
        if case .WhiteSpace = currentToken where !considerNewLines {
            return getNextToken(n)
        }
        return getNextToken(n-1)
    }
    private func inspectNextToken(i: Int = 1) -> Token? { // debug function, acts as getNextToken() but does not mutate
        if index+i >= tokens.count-i { return nil }
        if case .WhiteSpace = currentToken where !considerNewLines {
            return inspectNextToken(i+1)
        }
        return tokens[index+i]
    }
    private func inspectNextPos(i: Int = 1) -> Pos? {
        if index+i >= tokens.count-i { return nil }
        if case .WhiteSpace = currentToken where !considerNewLines {
            return inspectNextPos(i+1)
        }
        return tokensWithPos.map{$0.1.range.start}[index+i]
    }
    
    
    private func rangeOfCurrentToken() -> SourceRange? {
        if let n = inspectNextPos() { return SourceRange(start: currentPos, end: n) } else { return nil }
    }
    
    
    /// Contains whether the current parsing context considers new line chatacters
    private var considerNewLines: Bool {
        get {
            return _considerNewLines.last ?? false
        }
        set {
            _considerNewLines.append(newValue)
        }
    }
    private var _considerNewLines: [Bool] = [false] // temp var used to reset
    
    private mutating func resetConsiderNewLines() {
        _considerNewLines.removeLast()
        
        // if we now dont care about whitespace, move to next non whitespace char
        if !considerNewLines {
            while case .WhiteSpace = currentToken {
                index += 1
            }
        }
    }
    
    
    /// When parsing a parameter list we want to lay out function parameters next to eachother
    ///
    /// `add a b` parses as `add(a, b)` not `parse(a(b))`
    ///
    /// This flag is true if the parser is in a parameter list where identifiers are assumed to be vars not funcs
    private var inParameterList: Bool {
        get {
            return _inParameterList.last ?? false
        }
        set {
            _inParameterList.append(newValue)
        }
    }
    private var _inParameterList: [Bool] = [false]
    
    private mutating func revertParameterListState() {
        _inParameterList.removeLast()
    }

}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Literals
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseIntExpr(token: Int) throws -> Expr {
        getNextToken()
        let i = IntegerLiteral(val: token)
        
        if case .Period? = inspectNextToken() where isStdLib {
            getNextToken()
            return try parseMemberLookupExpr(i)
        }
        
        return i
    }
    private mutating func parseFloatingPointExpr(token: Double) -> FloatingPointLiteral {
        getNextToken()
        return FloatingPointLiteral(val: token)
    }
    private mutating func parseStringExpr(token: String) -> StringLiteral {
        getNextToken()
        return StringLiteral(str: token)
    }
    private mutating func parseBooleanExpr(token: Bool) throws -> Expr {
        getNextToken()
        let b = BooleanLiteral(val: token)
        
        if case .Period? = inspectNextToken() where isStdLib {
            getNextToken()
            return try parseMemberLookupExpr(b)
        }
        
        return b
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                          Tuple, brackets, and params
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    ///parses Expr like Int String, of type _identifier _identifier
    private mutating func parseTypeExpr() throws -> TupleExpr {
        
        // if () type
        if case .OpenParen = currentToken, case .CloseParen = getNextToken() {
            getNextToken() // eat ')'
            return TupleExpr(elements: [])
        }
        
        var elements = [Expr]()
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
                guard case .Identifier(let id) = getNextToken() else { throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken()) }
                
                // handle native llvm type in stdlib
                if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where id == "LLVM" && isStdLib {
                    elements.append(ValueType(name: "LLVM.\(n)"))    // param
                    getNextToken(2)// eat LLVM.Id
                }
                else {
                    elements.append(ValueType(name: id))    // param
                    getNextToken()
                }
                guard case .SqbrClose = getNextToken() else { throw error(ParseError.ExpectedCloseBracket, loc: SourceRange.at(currentPos)) }
                getNextToken() // eat ]
                
            default:
                break loop
            }
        }
        
        return TupleExpr(elements: elements)
    }
    
    // TODO: Tuple parsing seperate to parens
    //    private mutating func parseTupleExpr() throws -> TupleExpr {
    //
    //    }
    
    /// Guarantees if tuple is true, the return type is a TupleExpression
    private mutating func parseParenExpr(tuple tuple: Bool) throws -> Expr {
        
        guard case .OpenParen = currentToken else { throw error(ParseError.ExpectedParen, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat `(`
        
        var exps: [Expr] = []
        
        while case let a = currentToken where a.isValidParamToken {
            exps.append(try parseOperatorExpr())
        }
        guard case .CloseParen = currentToken else { throw error(ParseError.ExpectedParen, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat `)`
        
        switch exps.count {
        case 0: return TupleExpr.void()
        case 1: return tuple ? TupleExpr(elements: exps) : exps[0]
        case _: return TupleExpr(elements: exps)
        }
    }
    
    private mutating func parseParamExpr() throws -> TupleExpr {
        
        var exps: [Expr] = []
        
        considerNewLines = true
        inParameterList = true
        
        while case let a = currentToken where a.isValidParamToken {
            exps.append(try parseOperatorExpr())
        }
        
        revertParameterListState()
        resetConsiderNewLines()
        
        return exps.isEmpty ? TupleExpr.void() : TupleExpr(elements: exps)
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                      Identifier and operators
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    private mutating func parseTextExpr() throws -> VariableExpr {
        guard case .Identifier(let i) = currentToken else { throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken()) }
        return VariableExpr(name: i)
    }
    
    /// Handles parsing of a text token
    private mutating func parseIdentifierExpr(token: String) throws -> Expr {
        
        switch inspectNextToken() {
        case .OpenParen? where inspectNextToken(2)?.isCloseParen ?? false: // call
            getNextToken(3) // eat 'func ()'
            return FunctionCallExpr(name: token, args: TupleExpr.void())
            
        case let u? where u.isValidParamToken && !inParameterList:
            getNextToken() // eat 'identifier'
            
            return FunctionCallExpr(name: token, args: try parseParamExpr())
            
        case .SqbrOpen?: // subscript
            getNextToken(2) // eat 'identifier['
            
            let subscpipt = try parseOperatorExpr()
            getNextToken() // eat ']'
            
            guard case .Assign = currentToken else { // if call
                return ArraySubscriptExpr(arr: VariableExpr(name: token), index: subscpipt)
            }
            getNextToken() // eat '='
            
            let exp = try parseOperatorExpr()
            // if assigning to subscripted value
            return MutationExpr(object: ArraySubscriptExpr(arr: VariableExpr(name: token), index: subscpipt), value: exp)
            
        case .Assign?: // mutation
            getNextToken(2)// eat 'identifier ='
            
            let exp = try parseOperatorExpr()
            
            return MutationExpr(object: VariableExpr(name: token), value: exp)
            
        case .Period? where token == "LLVM" && isStdLib:
            getNextToken(2) // eat 'LLVM.'
            
            guard case .Identifier(let id) = currentToken else { fatalError() }
            return try parseIdentifierExpr("LLVM.\(id)")
            
        case .Period?: // property or fn
            getNextToken(2) // eat `.`
            
            return try parseMemberLookupExpr(VariableExpr(name: token))
            
        default: // just identifier
            
            defer { getNextToken() }
            return try parseOperatorExpr(VariableExpr(name: token))
        }
    }
    
    private mutating func parseMemberLookupExpr<Exp : Expr>(exp: Exp) throws -> Expr {
        
        switch currentToken {
        case .Identifier(let name):
            // property or method
            
            switch inspectNextToken() {
            case let u? where u.isValidParamToken && !inParameterList: // method call
                getNextToken() // eat foo
                
                if case .OpenParen = currentToken {   // simple itentifier () call
                    getNextToken(2) // eat `)`
                    return MethodCallExpr(name: name, params: TupleExpr.void(), object: exp)
                }
                
                return MethodCallExpr(name: name, params: try parseParamExpr(), object: exp)
                
            case .Assign?:
                getNextToken(2) // eat `.foo` `=`
                
                let property = PropertyLookupExpr(name: name, object: exp)
                
                let exp = try parseOperatorExpr()
                return MutationExpr(object: property, value: exp)
                
            default: // otherwise its a property
                defer { getNextToken() }
                return PropertyLookupExpr(name: name, object: exp)
            }
            
            
        case .Integer(let i):
            
            switch getNextToken() {
            case .Assign:
                getNextToken() // eat =
                
                let property = TupleMemberLookupExpr(index: i, object: exp)
                
                let exp = try parseOperatorExpr()
                return MutationExpr(object: property, value: exp)
                
            default:
                return TupleMemberLookupExpr(index: i, object: exp)
            }
            
        default:
            throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken())
        }
        
    }
    
    
    /// Function called on `return a + 1` and `if a < 3` etc
    ///
    /// exp can be optionally defined as a known lhs operand to give more info to the parser
    private mutating func parseOperatorExpr(exp: Expr? = nil, prec: Int = 0) throws -> Expr {
        return try parseOperationRHS(prec, lhs: exp ?? (try parsePrimary()))
    }
    
    private mutating func parsePrimary() throws -> Expr {
        
        switch currentToken {
        case let .Identifier(id):
            return try parseIdentifierExpr(id)
            
        case let .PrefixOperator(op):
            getNextToken()
            return PrefixExpr(op: op, expr: try parsePrimary())
            
        case let .Integer(i):
            return try parseIntExpr(i)
            
        case let .FloatingPoint(f):
            return parseFloatingPointExpr(f)
            
        case let .Boolean(b):
            return try parseBooleanExpr(b)
            
        case .OpenParen:
            // if in paren Expr we allow function parameters to be treated as functions not vars
            inParameterList = false
            defer { revertParameterListState() }

            return try parseParenExpr(tuple: false)
            
        case .OpenBrace, .Do /*, .OpenParen */: // FIXME: closures want to be abel to do `let a = (u) do print u`
            let block = try parseBlockExpr()
            let closure = ClosureExpr(exprs: block.exprs, params: block.variables.map { $0.name })
            return closure

        case .SqbrOpen:
            return try parseArrayExpr()
            
        case let .StringLiteral(str):
            return parseStringExpr(str)
            
        default:
            throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken())
        }
    }
    
    
    private mutating func parseOperationRHS(precedence: Int = 0, lhs: Expr) throws -> Expr {
        
        switch currentToken {
        case .InfixOperator(let op):
            guard let tokenPrecedence = precedences[op] else { throw error(ParseError.NoOperator(op), loc: rangeOfCurrentToken()) }
            // If the token we have encountered does not bind as tightly as the current precedence, return the current Expr
            if tokenPrecedence < precedence {
                return lhs
            }
            
            // Get next operand
            getNextToken()
            
            // Error handling
            let rhs = try parsePrimary()
            
            // Get next operator
            guard case .InfixOperator(let nextOp) = currentToken else { return BinaryExpr(op: op, lhs: lhs, rhs: rhs) }
            guard let nextTokenPrecedence = precedences[nextOp] else { throw error(ParseError.NoOperator(op), loc: rangeOfCurrentToken()) }
            
            let newRhs = try parseOperationRHS(tokenPrecedence, lhs: rhs)
            
            if tokenPrecedence <= nextTokenPrecedence {
                return try parseOperationRHS(nextTokenPrecedence, lhs: BinaryExpr(op: op, lhs: lhs, rhs: newRhs))
            }
            return try parseOperationRHS(precedence + 1, lhs: BinaryExpr(op: op, lhs: lhs, rhs: rhs))
            
            // Collapse the postfix operator and continue parsing
        case .PostfixOperator(let op):
            
            getNextToken()
            let newLHS = PostfixExpr(op: op, expr: lhs)
            return try parseOperationRHS(precedence, lhs: newLHS)
            
        case .PrefixOperator(let op):
            
            getNextToken()
            let newLHS = PrefixExpr(op: op, expr: lhs)
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
    
    private mutating func parseIfExpr() throws -> ConditionalStmt {
        
        getNextToken() // eat `if`
        let condition = try parseOperatorExpr()
        
        // list of blocks
        var blocks: [(condition: Expr?, block: BlockExpr)] = []
        
        let usesBraces = currentToken.isBrace()
        // get if block & append
        guard currentToken.isControlToken() else { throw error(ParseError.NotBlock, loc: SourceRange.at(currentPos)) }
        let block = try parseBlockExpr()
        blocks.append((condition, block))
        
        while case .Else = currentToken {
            
            var condition: Expr?
            
            if case .If? = inspectNextToken() {
                // `else if` statement
                getNextToken(2)
                condition = try parseOperatorExpr()
                
                if usesBraces {
                    guard currentToken.isControlToken() else { throw error(ParseError.NotBlock, loc: SourceRange.at(currentPos)) }
                }
            }
            else {
                getNextToken()
                condition = nil
            }
            
            let block = try parseBlockExpr()
            
            blocks.append((condition, block))
        }
        
        return try ConditionalStmt(statements: blocks)
    }
    
    
    private mutating func parseForInLoopExpr() throws -> ForInLoopStmt {
        
        getNextToken() // eat 'for'
        let itentifier = try parseTextExpr() // bind loop label
        guard case .In = getNextToken() else { throw error(ParseError.ExpectedIn, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat 'in'
        
        let loop = try parseOperatorExpr()
        let block = try parseBlockExpr()
        
        return ForInLoopStmt(identifier: itentifier, iterator: loop, block: block)
    }
    
    private mutating func parseWhileLoopStmt() throws -> WhileLoopStmt {
        
        getNextToken() // eat 'while'
        
        let condition = try parseOperatorExpr()
        let block = try parseBlockExpr()
        
        return WhileLoopStmt(condition: condition, block: block)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseVariableAssignmentMutable(mutable: Bool, requiresInitialValue: Bool = true) throws -> VariableDecl {
        
        guard case let .Identifier(id) = getNextToken() else { throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken()) }
        
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
                throw error(ParseError.ExpectedAssignment, loc: SourceRange.at(currentPos))
            }
            else {
                return VariableDecl(name: id, type: explicitType, isMutable: mutable, value: NullExpr())
            }
        }
        getNextToken() // eat '='
        
        var value = try parseOperatorExpr()
        
        let type = explicitType ?? (value as? ExplicitlyTyped)?.explicitType
        
        // if explicit assignment defines size, add info about this size to object
        if let ex = explicitType, case var sized as SizedExpr = value  {
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
        
        return VariableDecl(name: id, type: type, isMutable: mutable, value: value)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Function
//-------------------------------------------------------------------------------------------------------------------------

private extension TupleExpr {
    var unwrapped: Expr {
        switch elements.count {
        case 0: return ValueType(name: "Void")
        case 1: return elements[0]
        case _: return self
        }
    }
}

extension Parser {
    
    /// Parses the function type signature
    private mutating func parseFunctionType() throws -> FunctionType {
        
        // param type
        let p = try parseTypeExpr()
        
        // case like fn: Int =
        guard case .Returns = currentToken else {
            return FunctionType(args: p, returns: ValueType(name: "Void"))
        }
        getNextToken() // eat '->'
        
        let r = try parseTypeExpr().unwrapped
        
        // case like fn: Int -> Int =
        guard case .Returns = currentToken else {
            return FunctionType(args: p, returns: r)
        }

        var ty = FunctionType(args: p, returns: r)
        
        // curried case like fn: Int -> Int -> Int
        while case .Returns = currentToken {
            getNextToken()

            let params = TupleExpr(elements: [ty.returns])
            let returns = try parseTypeExpr()
            let out = FunctionType(args: params, returns: returns)
            
            ty = FunctionType(args: ty.args, returns: out)
        }
        
        return ty
    }
    
    
    private mutating func parseFuncDeclaration() throws -> FuncDecl {
        
        let a = attrs.flatMap { $0 as? FunctionAttributeExpr } ?? []
        let ops = attrs.flatMap { $0 as? ASTAttributeExpr }.flatMap { a -> Int? in if case .Operator(let p) = a { return p } else { return nil } }.last
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
                throw error(ParseError.CannotChangeOpPrecedence(o, x), loc: SourceRange.at(currentPos))
            }
            else if found == nil {
                precedences[o] = pp // update prec table if not found
            }
        }
        else {
            throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken())
        }
        
        let id: String
        if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where s == "LLVM" && isStdLib {
            id = "LLVM.\(n)"
            getNextToken(2) // eat
        }
        else {
            id = s
        }
        
        let start = inspectNextPos()!
        guard case .Colon = getNextToken(), case .Colon = getNextToken() else {
            throw error(ParseError.ExpectedDoubleColon, loc: SourceRange(start: start, end: currentPos))
        }
        
        getNextToken() // eat '='
        let type = try parseFunctionType()
        
        guard case .Assign = currentToken else {
            return FuncDecl(name: id, type: type, impl: nil, attrs: a)
        }
        getNextToken() // eat '='
        
        return FuncDecl(name: id, type: type, impl: try parseClosureDeclaration(type: type), attrs: a)
    }
    
    private mutating func parseClosureNamesExpr() throws -> [ValueType] {
        
        guard case .OpenParen = currentToken else { return [] }
        getNextToken() // eat '|'
        
        var nms: [String] = []
        while case let .Identifier(name) = currentToken {
            nms.append(name)
            getNextToken()
        }
        guard case .CloseParen = currentToken else { throw error(ParseError.ExpectedParen, loc: SourceRange.at(currentPos)) }
        guard let next = inspectNextToken() where next.isControlToken() else { throw error(ParseError.NotBlock, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat 'do' or '{'
        
        return nms.map { ValueType.init(name: $0) }
    }
    
    private mutating func parseClosureDeclaration(anon anon: Bool = false, type: FunctionType) throws -> FunctionImplementationExpr {
        let names: [Expr]
        
        if case .OpenParen = currentToken {
            names = try parseClosureNamesExpr()
                .map { $0 as Expr }
        }
        else {
            names = (0..<type.args.elements.count)
                .map (implicitArgName)
                .map { ValueType.init(name: $0) }
        }
        
        guard currentToken.isControlToken() else { throw error(ParseError.NotBlock, loc: SourceRange.at(currentPos)) }
        
        return FunctionImplementationExpr(params: TupleExpr(elements: names), body: try parseBlockExpr())
    }
    
    private mutating func parseBraceExpr(names: [ValueType] = []) throws -> BlockExpr {
        getNextToken() // eat '{'
        
        var exprs = [ASTNode]()
        
        while true {
            if case .CloseBrace = currentToken { break }
            guard let exp = try parseExpr(currentToken) else { throw error(ParseError.NoToken(currentToken), loc: SourceRange.at(currentPos)) }
            exprs.append(exp)
        }
        getNextToken() // eat '}'
        return BlockExpr(exprs: exprs, variables: names)
    }
    
    private mutating func parseReturnExpr() throws -> ReturnStmt {
        getNextToken() // eat `return`
        
        return ReturnStmt(expr: try parseOperatorExpr())
    }
    
    private mutating func parseBracelessDoExpr(names: [ValueType] = []) throws -> BlockExpr {
        getNextToken() // eat 'do'
        
        guard let ex = try parseExpr(currentToken) else { throw error(ParseError.NoToken(currentToken), loc: SourceRange.at(currentPos)) }
        
        return BlockExpr(exprs: [ex], variables: names)
    }
    
    private mutating func parseBlockExpr(names: [ValueType] = []) throws -> BlockExpr {
        
        switch currentToken {
        case .OpenParen:    return try parseBlockExpr(try parseClosureNamesExpr())
        case .OpenBrace:    return try parseBraceExpr(names)
        case .Do, .Else:    return try parseBracelessDoExpr(names)
        default:            throw error(ParseError.NotBlock, loc: SourceRange.at(currentPos))
        }
        
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Array
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseArrayExpr() throws -> Expr {
        
        getNextToken() // eat '['
        
        var elements = [Expr]()
        while true {
            
            switch currentToken {
            case .Comma:
                getNextToken()  // eat ','
                
            case .SqbrClose:
                getNextToken() // eat ']'
                return ArrayExpr(arr: elements)
                
            default:
                
                elements.append(try parseOperatorExpr())    // param
            }
        }
        
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Type
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private mutating func parseTypeDeclarationExpr(byRef byRef: Bool) throws -> StructExpr {
        
        let a = attrs
        attrs = []
        
        getNextToken() // eat 'type'
        
        guard case .Identifier(let name) = currentToken else { throw error(ParseError.NoTypeName, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat name
        guard case .OpenBrace = currentToken else { throw error(ParseError.ExpectedOpenBrace, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat '{'
        
        var properties: [VariableDecl] = [], methods: [FuncDecl] = [], initialisers: [InitialiserDecl] = []
        
        while true {
            
            if case .CloseBrace = currentToken { break }

            switch currentToken {
            case .Var:
                properties.append(try parseVariableAssignmentMutable(true, requiresInitialValue: false))
                
            case .Let:
                properties.append(try parseVariableAssignmentMutable(false, requiresInitialValue: false))
                
            case .Func:
                methods.append(try parseFuncDeclaration())
                
            case .Init:
                initialisers.append(try parseInitDeclaration())
                
            case .At:
                try parseAttrExpr()
                
            case .Comment(let c):
                try parseCommentExpr(c)
                
            default:
                throw error(ParseError.ObjectNotAllowedInTopLevelOfTypeImpl(currentToken), loc: SourceRange.at(currentPos))
            }
            
        }
        
        let s = StructExpr(name: name, properties: properties, methods: methods, initialisers: initialisers, attrs: a)
        
        // associate functions with the struct
        for i in s.initialisers {
            i.parent = s
        }
        for m in s.methods {
            m.parent = s
        }
        
        return s
    }
    
    private mutating func parseInitDeclaration() throws -> InitialiserDecl {
        
        getNextToken() // eat `init`
        let type = try parseFunctionType()
        guard case .Assign = currentToken else {
            return InitialiserDecl(ty: type, impl: nil, parent: nil)
        }
        getNextToken() // eat `=`
        
        return InitialiserDecl(ty: type, impl: try parseClosureDeclaration(type: type), parent: nil)
    }
    
}






//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Other
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    // TODO: Fix how this gets in the way of other things
    private mutating func parseCommentExpr(str: String) throws -> Expr {
        getNextToken() //eat comment
        return CommentExpr(str: str)
    }
    
    private mutating func parseAttrExpr() throws {
        getNextToken() // eat @
        
        guard case .Identifier(let id) = currentToken else { return }
        
        if case .OpenParen? = inspectNextToken() {
            getNextToken(2)
            
            switch id {
            case "operator":
                guard case let i as IntegerLiteral = try parseOperatorExpr() else { throw error(ParseError.NoPrecedenceForOperator, loc: SourceRange.at(currentPos)) }
                attrs.append(ASTAttributeExpr.Operator(prec: i.val))
                
            default:
                throw error(ParseError.AttrDoesNotHaveParams, loc: SourceRange.at(currentPos))
            }
            
            guard case .CloseParen = currentToken else { throw error(ParseError.ExpectedParen, loc: SourceRange.at(currentPos)) }
            getNextToken()
        }
        else if let a = FunctionAttributeExpr(rawValue: id) {
            getNextToken()
            attrs.append(a)
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
    private mutating func parseExpr(token: Token) throws -> ASTNode? {
        
        switch token {
        case .Let:                  return try parseVariableAssignmentMutable(false)
        case .Var:                  return try parseVariableAssignmentMutable(true)
        case .Func:                 return try parseFuncDeclaration()
        case .Return:               return try parseReturnExpr()
        case .OpenParen:            return try parseParenExpr(tuple: true)
        case .OpenBrace:            return try parseBraceExpr()
        case .Identifier(let str):  return try parseIdentifierExpr(str)
        case .InfixOperator:        return try parseOperatorExpr()
        case .Comment(let str):     return try parseCommentExpr(str)
        case .If:                   return try parseIfExpr()
        case .For:                  return try parseForInLoopExpr()
        case .Do:                   return try parseBracelessDoExpr()
        case .While:                return try parseWhileLoopStmt()
        case .SqbrOpen:             return try parseArrayExpr()
        case .Type:                 return try parseTypeDeclarationExpr(byRef: false)
        case .Reference:            getNextToken(); return try parseTypeDeclarationExpr(byRef: true)
        case .Integer(let i):       return  try parseIntExpr(i)
        case .FloatingPoint(let x): return parseFloatingPointExpr(x)
        case .StringLiteral(let str):return parseStringExpr(str)
        case .At:                   try parseAttrExpr(); return nil
        case .Void:                 index += 1; return Void()
        case .EOF, .CloseBrace:     index += 1; return nil
        case .WhiteSpace:           getNextToken(); return nil
        default:                    throw error(ParseError.NoToken(token), loc: SourceRange.at(currentPos))
        }
    }
    
    // TODO: if statements have return type
    // TODO: Implicit return if a block only has 1 Expr
    
    private func tok() -> Token? { return index < tokens.count ? tokens[index] : nil }
    
    /// Returns abstract syntax tree from an instance of a parser
    ///
    /// [Detailed here](http://llvm.org/docs/tutorial/LangImpl2.html)
    mutating func parse() throws -> AST {
        
        index = 0
        exprs = []
        
        while let tok = tok() {
            if let exp = try parseExpr(tok) {
                exprs.append(exp)
            }
        }
        
        return AST(exprs: exprs)
    }

    init(tokens: [(Token, SourceLoc)], isStdLib: Bool = false) {
        self.tokensWithPos = tokens.filter {
            if case .Comment = $0.0 { return false } else { return true }
        }
        self.isStdLib = isStdLib
        self.attrs = []
    }
    
}





