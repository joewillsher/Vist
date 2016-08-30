//
//  Parser.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.NSString


private extension Array {
    mutating func removeLastSafely(str: String, pos: Pos) throws -> Iterator.Element {
        guard !isEmpty else { throw parseError(.invalidCall(str), loc: .at(pos: pos)) }
        return removeLast()
    }
}

private extension Token {
    func isControlToken() -> Bool {
        switch self {
        case .do, .openBrace: return true
        default: return false
        }
    }
    func isBrace() -> Bool {
        return .openBrace == self
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK: -                                            Parser
//-------------------------------------------------------------------------------------------------------------------------

/// Parser object, initialised with tokenised code and exposes methods to generare AST
final class Parser {
    
    private init(tokens: [(Token, SourceLoc)], isStdLib: Bool = false) {
        self.tokensWithPos = tokens.filter {
            if case .comment = $0.0 { return false } else { return true }
        }
        self.isStdLib = isStdLib
        self.attrs = []
    }
    
    static func parse(withTokens toks: [(Token, SourceLoc)], isStdLib: Bool = false) throws -> AST {
        return try Parser(tokens: toks, isStdLib: isStdLib).parse()
    }
    
    fileprivate var index = 0
    fileprivate let tokensWithPos: [(Token, SourceLoc)]
    
    fileprivate var exprs = [ASTNode]()
    
    fileprivate var tokens: [Token]     { return tokensWithPos.map{$0.0} }
    fileprivate var currentToken: Token { return tokens[index] }
    fileprivate var currentPos: Pos     { return tokensWithPos.map{$0.1.range.start}[index] }
    
    fileprivate let isStdLib: Bool
    
    fileprivate var attrs: [AttributeExpr]
    
    fileprivate var precedences: [String: Int] = [
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
        "..<": 40,
        "<<": 50,
        ">>": 50,
        "~|": 90,
        "~^": 90,
        "~&": 95,
    ]
    
    fileprivate var diag = Diagnostics()
    
    /// Consume `n` tokens
    @discardableResult fileprivate func consumeToken(_ n: Int = 1) -> Token {
        if n == 0 { return currentToken }
        index += 1
        if case .newLine = currentToken, !considerNewLines {
            return consumeToken(n)
        }
        return consumeToken(n-1)
    }
    
    /// Consume the current token if it matches `token`
    /// - returns: Whether the token matched
    fileprivate func consumeIf(_ token: Token) -> Bool {
        guard token == currentToken else {
            return false
        }
        consumeToken()
        return true
    }
    /// Consume the current tokens if they match `tokens`
    /// - returns: Whether the series of tokens matched
    fileprivate func consumeIf(_ tokens: Token...) -> Bool {
        // Check they all match
        for (dist, token) in tokens.enumerated() {
            guard inspectNextToken(lookahead: dist) == token else { return false }
        }
        // then consume them
        for token in tokens {
            guard consumeIf(token) else { return false }
        }
        return true
    }
    /// If the current token is an identifier, return its string
    fileprivate func consumeIfIdentifier() -> String? {
        guard case .identifier(let id) = currentToken else { return nil }
        consumeToken()
        return id
    }
    /// Consume the current token if it is an identifier
    /// - throws: if the current token is not an identifier
    @discardableResult fileprivate func consumeIdentifier() throws -> String {
        guard case .identifier(let id) = currentToken else {
            throw parseError(.noIdentifier, loc: .at(pos: currentPos))
        }
        consumeToken()
        return id
    }
    @discardableResult fileprivate func consumeIdentifierOrOperator() throws -> String {
        
        switch currentToken {
        case .identifier(let id), .infixOperator(let id):
            consumeToken()
            return id
        default:
            throw parseError(.noIdentifier, loc: .at(pos: currentPos))
        }
    }

    
    /// Consume the token if it matches `token`
    fileprivate func consume(_ token: Token) throws {
        guard token == currentToken else {
            throw parseError(.noToken(token), loc: .at(pos: currentPos))
        }
        consumeToken()
    }
    /// Consume the current tokens if they match `tokens`
    fileprivate func consume(tokens: Token...) throws {
        for token in tokens {
            guard consumeIf(token) else {
                throw parseError(.noToken(token), loc: .at(pos: currentPos))
            }
        }
    }
    
    /// Return the token `steps` ahead of the current token
    @discardableResult fileprivate func inspectNextToken(lookahead steps: Int = 1) -> Token? {
        if index+steps >= tokens.count-steps { return nil }
        if case .newLine = currentToken, !considerNewLines {
            return inspectNextToken(lookahead: steps+1)
        }
        return tokens[index+steps]
    }
    @discardableResult fileprivate func inspectNextPos(_ i: Int = 1) -> Pos? {
        if index+i >= tokens.count-i { return nil }
        if case .newLine = currentToken, !considerNewLines {
            return inspectNextPos(i+1)
        }
        return tokensWithPos.map{$0.1.range.start}[index+i]
    }
    
    fileprivate func rangeOfCurrentToken() -> SourceRange? {
        return inspectNextPos().map { SourceRange(start: currentPos, end: $0) }
    }
    
    fileprivate struct ConsumeIfMatch {
        let token: Token
        let parser: Parser
        init(_ token: Token, _ parser: Parser) {
            self.token = token
            self.parser = parser
        }
        
        static func ~= (pattern: (Token) -> Bool, value: ConsumeIfMatch) -> Bool {
            if pattern(value.token) {
                value.parser.consumeToken()
                return true
            }
            return false
        }
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
    
    private func resetConsiderNewLines() {
        _considerNewLines.removeLast()
        
        // if we now dont care about whitespace, move to next non whitespace char
        if !considerNewLines {
            while case .newLine = currentToken {
                index += 1
            }
        }
    }
    
    func withConsiderNewLines<T>(_ fn: @noescape (nextToken: Token) throws -> T) throws -> T {
        
        considerNewLines = true
        
        guard let tok = inspectNextToken() else {
            throw parseError(.expectedExpression, userVisible: false)
        }
        let v = try fn(nextToken: tok)
        
        resetConsiderNewLines()
        return v
    }
    
    func nextTokenIsCall() throws -> Bool {
        return try withConsiderNewLines { nextToken in
            nextToken.isValidParamToken && !inTuple // param lists (== !inTuple) don't allow calls
                && (allowsTrailingDo || !nextToken.isControlToken()) // if trailing do not allowed, only accept if not control token
        }
    }
    func isValidParamToken() -> Bool {
        return currentToken.isValidParamToken
            && (allowsTrailingDo || !currentToken.isControlToken())
    }

    
    /// When parsing a parameter list we want to lay out function parameters next to eachother
    ///
    /// `add a b` parses as `(add (a b))` not `(parse (a (b)))`
    ///
    /// This flag is true if the parser is in a parameter list where identifiers are assumed to be vars not funcs
    fileprivate var inTuple: Bool {
        get { return _inTupleStack.last ?? false }
        set { _inTupleStack.append(newValue) }
    }
    private var _inTupleStack: [Bool] = [false]
    
    fileprivate func revertInTupleState() {
        _inTupleStack.removeLast()
    }
    
    fileprivate var allowsTrailingDo: Bool {
        get { return _allowsTrailingDoStack.last ?? true }
        set { _allowsTrailingDoStack.append(newValue) }
    }
    private var _allowsTrailingDoStack: [Bool] = [true]
    
    fileprivate func revertAllowsTrailingDo() {
        _allowsTrailingDoStack.removeLast()
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Literals
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Int literal expression
    fileprivate func parseIntExpr(_ token: Int) throws -> Expr {
        try consume(.integerLiteral(token))
        return IntegerLiteral(val: token)
    }
    /// Float literal expression
    fileprivate func parseFloatingPointExpr(_ token: Double) -> FloatingPointLiteral {
        consumeToken()
        return FloatingPointLiteral(val: token)
    }
    /// String literal expression
    fileprivate func parseStringExpr(_ token: String) -> StringLiteral {
        consumeToken()
        return StringLiteral(str: token)
    }
    /// Bool literal expression
    fileprivate func parseBooleanExpr(_ token: Bool) throws -> Expr {
        consumeToken()
        return BooleanLiteral(val: token)
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                          Tuple, brackets, and params
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parse a type repr as a function repr
    /// - note: `Int` is interpreted as `Int -> ()` and `()` as `() -> ()` for example
    fileprivate func parseFunctionTypeRepr() throws -> FunctionTypeRepr {
        switch try parseTypeRepr() {
        case .function(let fn): return fn
        case let param: return FunctionTypeRepr(paramType: param, returnType: .void)
        }
    }
    
    /// Parses type repr, used in variable decls and function signatures
    fileprivate func parseTypeRepr() throws -> TypeRepr {
        
        var elements: [TypeRepr] = []
        func repr() -> TypeRepr {
            if elements.isEmpty { return .void }
            if elements.count == 1 { return elements[0] }
            return .tuple(elements)
        }
        
        loop: while true {
            switch currentToken {
            case .identifier(let id):
                // handle native llvm type in stdlib
                if case .period? = inspectNextToken(), case .identifier(let n)? = inspectNextToken(lookahead: 2), id == "Builtin", isStdLib {
                    elements.append(.type("Builtin.\(n)"))    // param
                    consumeToken(3)// eat Builtin.Id
                }
                else {
                    elements.append(.type(id))    // param
                    consumeToken()
                }
            case .openParen:
                try consume(.openParen)
                
                if consumeIf(.closeParen) {
                    elements.append(.void)
                }
                else {
                    var types: [TypeRepr] = []
                    repeat {
                        try types.append(parseTypeRepr())
                    } while consumeIf(.comma)
                    
                    try consume(.closeParen)
                    if types.count == 1 { elements.append(types[0]) }
                    else { elements.append(.tuple(types)) }
                }
                
            case .sqbrOpen:
                guard let id = consumeIfIdentifier() else {
                    throw parseError(.noIdentifier, loc: rangeOfCurrentToken())
                }
                
                // handle native llvm type in stdlib
                if case .period? = inspectNextToken(), case .identifier(let n)? = inspectNextToken(lookahead: 2), id == "Builtin", isStdLib {
                    elements.append(.type("Builtin.\(n)"))    // param
                    consumeToken(2)// eat Builtin.Id
                }
                else {
                    elements.append(.type(id))    // param
                }
                
                try consume(.sqbrClose)
                
            case .returnArrow:
                // case like `func fn: Int = `
                try consume(.returnArrow)
                
                // case like `func fn: Int -> Int =`
                var ty = FunctionTypeRepr(paramType: repr(), returnType: try parseTypeRepr())
                
                // curried case like `func fn: Int -> Int -> Int =`
                while consumeIf(.returnArrow) {
                    let params = ty.returnType
                    let returns = try parseTypeRepr()
                    let out = FunctionTypeRepr(paramType: params, returnType: returns)
                    
                    ty = FunctionTypeRepr(paramType: ty.paramType, returnType: .function(out))
                }
                
                elements = [.function(ty)]
                
            default:
                return repr()
            }
        }
    }
}

extension Parser {
    
    /// Parses an expression wrapped in parentheses
    ///
    /// If its a 0, or multi element tuple, this returns a tuple, otherwise the value in
    /// parens (as they were just used for disambiguation or operator precedence override)
    fileprivate func parseParenExpr() throws -> Expr {
        
        // if in paren Expr we allow function parameters to be treated as functions not vars
        inTuple = false
        defer { revertInTupleState() }

        try consume(.openParen)
        
        if consumeIf(.closeParen) {
            return TupleExpr.void()
        }
        
        var exprs: [Expr] = []
        
        repeat {
            try exprs.append(parseOperatorExpr())
            guard !inTuple || consumeIf(.comma) else { break }
        } while isValidParamToken()
        
        try consume(.closeParen)
        
        if exprs.count == 1 { return exprs[0] }
        return TupleExpr(elements: exprs)
    }
    
    /// Parses a parameter list for a function call
    fileprivate func parseParamExpr() throws -> TupleExpr {
        
        var exps: [Expr] = []
        
        considerNewLines = true
        inTuple = true
        
        while isValidParamToken() {
            try exps.append(parseOperatorExpr())
        }
        
        revertInTupleState()
        resetConsiderNewLines()
        
        return exps.isEmpty ? TupleExpr.void() : TupleExpr(elements: exps)
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                      Identifier and operators
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    /// Parses a text token as a VariableExpr
    fileprivate func parseIdentifierAsVariable() throws -> VariableExpr {
        return VariableExpr(name: try consumeIdentifier())
    }
    
    fileprivate func parseIdentifier() throws -> Expr {
        
        var isCall = try nextTokenIsCall()
        var name = try consumeIdentifier()
        
        // handle stdlib's 'Builtin.' identifiers
        if isStdLib, name == "Builtin", consumeIf(.period) {
            isCall = try nextTokenIsCall()
            name = try "Builtin.\(consumeIdentifier())"
        }
        
        if isCall {
            if consumeIf(.openParen, .closeParen) {
                return FunctionCallExpr(name: name, args: TupleExpr.void())
            }
            return FunctionCallExpr(name: name, args: try parseParamExpr())
        }
        
        return try parseChainableExpr(base: VariableExpr(name: name))
    }

    
    private func parseChainableExpr<Chainable : ChainableExpr>(base: Chainable) throws -> Expr {
        
        switch currentToken {
        case .sqbrOpen: // subscript
            try consume(.sqbrOpen)
            let subscpipt = try parseOperatorExpr()
            try consume(.sqbrClose)
            
            guard consumeIf(.assign) else { // if assignment
                return ArraySubscriptExpr(arr: base, index: subscpipt)
            }
            
            // if assigning to subscripted value
            return MutationExpr(object: ArraySubscriptExpr(arr: base,
                                                           index: subscpipt),
                                value: try parseOperatorExpr())
            
        case .assign:
            try consume(.assign)
            return MutationExpr(object: base,
                                value: try parseOperatorExpr())
            
        case .period: // property or fn
            try consume(.period)

            switch currentToken {
            case .identifier(let name):
                // property or method
                let isCall = try nextTokenIsCall()
                consumeToken()
                
                if isCall {
                    if case .openParen = currentToken, case .closeParen? = inspectNextToken() {   // simple itentifier () call
                        try consume(tokens: .openParen, .closeParen)
                        return MethodCallExpr(name: name,
                                              args: TupleExpr.void(),
                                              object: base)
                    }
                    return MethodCallExpr(name: name,
                                          args: try parseParamExpr(),
                                          object: base)
                }
                
                let lookup = PropertyLookupExpr(propertyName: name, object: base)
                return try parseChainableExpr(base: lookup)
                
            case .integerLiteral(let i):
                consumeToken()
                let element = TupleMemberLookupExpr(index: i, object: base)
                return try parseChainableExpr(base: element)
                
            default:
                throw parseError(.noIdentifier, loc: rangeOfCurrentToken())
            }
            
        default: // just identifier
            return base
        }
        
    }
}


extension Parser {
    
    /// Function parses one expression, and can handle operators & parens, function 
    /// calls, literals & variables, blocks, arrays, and tuples
    ///
    /// Called on `return a + 1`, `let a = foo(x) + 1` and `if a < 3 do` etc
    ///
    /// - parameter exp: A known lhs operand to give more info to the parser
    /// - parameter prec: The precedence of the current token
    private func parseOperatorExpr(_ exp: Expr? = nil, prec: Int = 0) throws -> Expr {
        return try parseOperationRHS(precedence: prec, lhs: exp ?? parsePrimary())
    }
    
    /// Parses a primary expression
    ///
    /// If it isnt succeeded by an operator this is the output of
    private func parsePrimary() throws -> Expr {
        
        switch currentToken {
        case .identifier:
            return try parseIdentifier()
            
        case .prefixOperator(let op):
            consumeToken()
            return PrefixExpr(op: op, expr: try parsePrimary())
            
        case .integerLiteral(let i):
            return try parseIntExpr(i)
            
        case .floatingPointLiteral(let f):
            return parseFloatingPointExpr(f)
            
        case .booleanLiteral(let b):
            return try parseBooleanExpr(b)
            
        case .openBrace, .do /*, .OpenParen */: // FIXME: closures want to be able to do `let a = (u) do print u`
            let block = try parseBlockExpr()
            return ClosureExpr(exprs: block.exprs, params: block.parameters)
            
        case .openParen where allowsTrailingDo:
            // look past param list
            var lookaheadDist = 1
            
            while case .identifier? = inspectNextToken(lookahead: lookaheadDist) {
                lookaheadDist += 1
            }
            guard case .closeParen? = inspectNextToken(lookahead: lookaheadDist) else { fallthrough }
            guard inspectNextToken(lookahead: lookaheadDist+1)?.isControlToken() ?? false else { fallthrough }
            
            let block = try parseBlockExpr()
            return ClosureExpr(exprs: block.exprs, params: block.parameters)
            
        case .openParen:
            return try parseParenExpr()
            
        case .sqbrOpen:
            return try parseArrayExpr()
            
        case .stringLiteral(let str):
            return parseStringExpr(str)
            
        default:
            throw parseError(.noIdentifier, loc: rangeOfCurrentToken())
        }
    }
    
    /// Parses RHS of an operator
    ///
    /// Handles precedence calculations and calls parseOperatorExpr again to get what follows
    private func parseOperationRHS(precedence: Int = 0, lhs: Expr) throws -> Expr {
        
        switch currentToken {
        case .infixOperator(let op):
            guard let tokenPrecedence = precedences[op] else { throw parseError(.noOperator(op), loc: rangeOfCurrentToken()) }
            // If the token we have encountered does not bind as tightly as the current precedence, return the current Expr
            if tokenPrecedence < precedence {
                return lhs
            }
            
            // Get next operand
            consumeToken()
            
            // Error handling
            let rhs = try parsePrimary()
            
            // Get next operator
            guard case .infixOperator(let nextOp) = currentToken else {
                return BinaryExpr(op: op, lhs: lhs, rhs: rhs)
            }
            
            guard let nextTokenPrecedence = precedences[nextOp] else {
                throw parseError(.noOperator(op), loc: rangeOfCurrentToken())
            }
            
            let newRhs = try parseOperationRHS(precedence: tokenPrecedence, lhs: rhs)
            
            if tokenPrecedence <= nextTokenPrecedence {
                return try parseOperationRHS(precedence: nextTokenPrecedence,
                                             lhs: BinaryExpr(op: op, lhs: lhs, rhs: newRhs))
            }
            return try parseOperationRHS(precedence: precedence + 1,
                                         lhs: BinaryExpr(op: op, lhs: lhs, rhs: rhs))
            
        case .as:
            try consume(.as)
            return try CoercionExpr(base: lhs, type: parseTypeRepr())
            
            // Collapse the postfix operator and continue parsing
        case .postfixOperator(let op):
            consumeToken()
            let newLHS = PostfixExpr(op: op, expr: lhs)
            return try parseOperationRHS(precedence: precedence,
                                         lhs: newLHS)
        case .prefixOperator(let op):
            consumeToken()
            let newLHS = PrefixExpr(op: op, expr: lhs)
            return try parseOperationRHS(precedence: precedence,
                                         lhs: newLHS)
        default: // Encountered a different token, return the lhs.
            return lhs
        }
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parse an expression which is terminated by a 'do' or '{'.
    /// To disambiguate in the grammar, these expressions cannot contain
    /// a parameter which is a closure.
    fileprivate func parseInlineExpr() throws -> Expr {
        // `if val do ` is ambiguous, `val do` could be a call
        allowsTrailingDo = false
        let v = try parseOperatorExpr()
        revertAllowsTrailingDo()
        return v
    }
    
    /// Parses an 'if else block' chain
    private func parseIfStmt() throws -> ConditionalStmt {
        precondition(currentToken == .if)
        
        // list of blocks
        var blocks: [ElseIfBlockStmt] = []
        var usesBraces: Bool? = nil
        
        repeat {
            var condition: ConditionalPattern
            
            // An `if` statement
            if consumeIf(.if) {
                
                // if x the Type
                if case .identifier = currentToken, case .the? = inspectNextToken() {
                    let id = try! consumeIdentifier()
                    try! consume(.the)
                    let repr = try parseTypeRepr()
                    // if there is an assignent
                    // if x the Type = foo
                    let bound: Expr? = try consumeIf(.assign) ? parseInlineExpr() : nil
                    condition = .typeMatch(TypeMatchPattern(variable: id, explicitBoundExpr: bound, type: repr))
                }
                // if cond
                else {
                    condition = try .boolean(parseInlineExpr())
                }
                
                guard currentToken.isControlToken() else {
                    throw parseError(.notBlock, loc: .at(pos: currentPos))
                }
                if let t = usesBraces, t != currentToken.isBrace() {
                    throw parseError(.notBlock, loc: .at(pos: currentPos))
                }
                else {
                    usesBraces = currentToken.isBrace()
                }
            }
            else {
                condition = .none
            }
            
            let block = try parseBlockExpr()
            blocks.append(ElseIfBlockStmt(condition: condition, block: block))
        } while consumeIf(.else)
        
        return ConditionalStmt(statements: blocks)
    }
    
    /// Parses a `for _ in range do` statement
    private func parseForInLoopStmt() throws -> ForInLoopStmt {
        try consume(.for)
        let itentifier = try parseIdentifierAsVariable() // bind loop label
        try consume(.in)
        
        let loop = try parseInlineExpr()
        let block = try parseBlockExpr()
        
        return ForInLoopStmt(identifier: itentifier, iterator: loop, block: block)
    }
    
    /// Parses while loop statements
    private func parseWhileLoopStmt() throws -> WhileLoopStmt {
        try consume(.while)
        let condition = try parseInlineExpr()
        let block = try parseBlockExpr()
        return WhileLoopStmt(condition: condition, block: block)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parses a variable's declaration
    fileprivate func parseVariableDecl(declContext: DeclContext) throws -> TypeMemberVariableDecl {
        
        let mutable: Bool
        switch currentToken {
        case .let: mutable = false
        case .var: mutable = true
        default: throw parseError(.notVariableDecl, userVisible: false)
        }
        
        var decls: [VariableDecl] = []
        consumeToken() // eat var/let
        
        repeat {
            guard let id = consumeIfIdentifier() else {
                throw parseError(.noIdentifier, loc: rangeOfCurrentToken())
            }
            
            let explicitType: TypeRepr? = try consumeIf(.colon)
                ? parseTypeRepr()
                : nil
            
            /// Declaration used if no initial value is given
            var decl: VariableDecl
            
            if consumeIf(.assign) {
                // concept member cannot provide value
                if case .concept = declContext {
                    throw parseError(.conceptCannotProvideVal, loc: .at(pos: currentPos))
                }
                
                decl = VariableDecl(name: id,
                                    typeRepr: explicitType,
                                    isMutable: mutable,
                                    value: try parseOperatorExpr())
            }
            else {
                // must be typed if no val
                guard let _ = explicitType else {
                    throw parseError(.expectedAssignment, loc: .at(pos: currentPos))
                }
                decl = VariableDecl(name: id,
                                    typeRepr: explicitType,
                                    isMutable: mutable,
                                    value: NullExpr())
            }
            decls.append(decl)
        } while consumeIf(.comma)
        
        if decls.count == 1 {
            return decls[0]
        }
        return VariableGroupDecl(declared: decls)
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Function
//-------------------------------------------------------------------------------------------------------------------------


extension Parser {
    
    /// Parse a function decl
    fileprivate func parseFuncDeclaration(declContext: DeclContext) throws -> FuncDecl {
        
        let a = attrs.flatMap { $0 as? FunctionAttributeExpr } ?? []
        let ops = attrs
            .flatMap { $0 as? ASTAttributeExpr }
            .flatMap { a -> Int? in
                if case .Operator(let p) = a { return p } else { return nil }
            }.last
        attrs = []
        
        try consume(.func)
        let s: String
        if case .identifier(let n) = currentToken {
            s = n
        }
        else if case .infixOperator(let o) = currentToken, let pp = ops {
            s = o
            
            let found = precedences[o]
            if let x = found, x != ops { // make sure uses op’s predetermined prec
                throw parseError(.cannotChangeOpPrecedence(o, x), loc: .at(pos: currentPos))
            }
            else if found == nil {
                precedences[o] = pp // update prec table if not found
            }
        }
        else {
            throw parseError(.noIdentifier, loc: rangeOfCurrentToken())
        }
        
        let functionName: String
        if case .period? = inspectNextToken(), case .identifier(let n)? = inspectNextToken(lookahead: 2), s == "Builtin" && isStdLib {
            functionName = "Builtin.\(n)"
            consumeToken(2) // eat
        }
        else {
            functionName = s
        }
        
        try consumeIdentifierOrOperator()
        
        let genericParameters = try parseGenericParameterList(objName: functionName)
        
        let typeSignatureStartPos = currentPos
        guard consumeIf(.colon, .colon) else {
            throw parseError(.expectedDoubleColon, loc: SourceRange(start: typeSignatureStartPos, end: currentPos))
        }
        
        let repr = try parseFunctionTypeRepr()
        
        guard consumeIf(.assign) else {
            return FuncDecl(name: functionName, typeRepr: repr, impl: nil, attrs: a, genericParameters: genericParameters)
        }
        
        return FuncDecl(name: functionName,
                        typeRepr: repr,
                        impl: try parseFunctionBodyExpr(type: repr),
                        attrs: a,
                        genericParameters: genericParameters)
    }
    
    /// Get the parameter names applied
    private func parseClosureNamesExpr() throws -> [String] {
        
        guard consumeIf(.openParen) else { return [] }
        
        var nms: [String] = []
        while let name = consumeIfIdentifier() {
            nms.append(name)
        }
        try consume(.closeParen)
        guard currentToken.isControlToken() else {
            throw parseError(.notBlock, loc: .at(pos: currentPos))
        }
        
        return nms
    }
    
    /// Function parses the function body — used by functions & initialisers etc
    /// - returns: The function implementation—with parameter labels and the block’s expressions
    private func parseFunctionBodyExpr(anon: Bool = false, type: FunctionTypeRepr) throws -> FunctionBodyExpr {
        let names: [String]
        
        if case .openParen = currentToken {
            names = try parseClosureNamesExpr()
        }
        else {
            names = (0..<type.paramType.typeNames().count).map { "$\($0)" }
        }
        
        guard currentToken.isControlToken() else {
            throw parseError(.notBlock, loc: .at(pos: currentPos))
        }
        
        return FunctionBodyExpr(params: names, body: try parseBlockExpr())
    }
    
    /// Parses the insides of a '{...}' expression
    private func parseBraceExpr(names: [String]? = nil) throws -> BlockExpr {
        try consume(.openBrace)
        
        var body: [ASTNode] = []
        
        while !consumeIf(.closeBrace) {
            guard let stmt = try parseStmt(context: .function) else {
                throw parseError(.expectedExpression, loc: .at(pos: currentPos))
            }
            body.append(stmt)
        }
        return BlockExpr(exprs: body, parameters: names)
    }
    
    /// Parses the expression in a 'do' block
    private func parseBracelessDoExpr(names: [String]? = nil) throws -> BlockExpr {
        try consume(.do)
        guard let body = try parseStmt(context: .function) else {
            throw parseError(.expectedExpression, loc: .at(pos: currentPos))
        }
        return BlockExpr(exprs: [body], parameters: names)
    }
    
    /// Parses expression following a `return`
    private func parseReturnStmt() throws -> ReturnStmt {
        try consume(.return)
        return ReturnStmt(expr: try parseOperatorExpr())
    }
    
    /// Parses expression following a `yield`
    private func parseYieldStmt() throws -> YieldStmt {
        try consume(.yield)
        return YieldStmt(expr: try parseOperatorExpr())
    }

    /// Function scopes -- starts a new '{' or 'do' block
    ///
    /// Will parse any arg labels applied in parens
    private func parseBlockExpr(names: [String]? = nil) throws -> BlockExpr {
        
        switch currentToken {
        case .openParen:    return try parseBlockExpr(names: parseClosureNamesExpr())
        case .openBrace:    return try parseBraceExpr(names: names)
        case .do, .else:    return try parseBracelessDoExpr(names: names)
        default:            throw parseError(.notBlock, loc: .at(pos: currentPos))
        }
        
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Array
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parses an array literal expression
    private func parseArrayExpr() throws -> Expr {
        try consume(.sqbrOpen)
        
        var elements = [Expr]()
        while true {
            switch currentToken {
            case .comma:
                try! consume(.comma)
                
            case .sqbrClose:
                try! consume(.sqbrClose) // eat ']'
                return ArrayExpr(arr: elements)
                
            default:
                try elements.append(parseOperatorExpr())    // param
            }
        }
        
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Type
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    private func parseGenericParameterList(objName: String ) throws -> [ConstrainedType]? {
        
        var genericParameters: [ConstrainedType] = []
        
//        type TwoType T U {
//        type Array (Element | Foo Bar) {
        
        let genericParamListStartPos = currentPos
        
        while true {
            switch currentToken {
            case .identifier(let genericParamName):
                genericParameters.append((name: genericParamName, constraints: [], parentName: objName))
                consumeToken()
                
            case .openParen:
                let currentParamStartPos = currentPos
                
                guard let genericParamName = consumeIfIdentifier() else { // get name of generic param
                    throw parseError(.noGenericParamName(on: objName), loc: SourceRange(start: genericParamListStartPos, end: currentPos))
                }
                try consume(.bar)
                
                var constraints: [String] = []
                
                loopOverConstraints: while true {
                    switch consumeToken() {
                    case .identifier(let constraint):
                        constraints.append(constraint)
                        
                    case .closeParen where !constraints.isEmpty:
                        try! consume(.closeParen)
                        break loopOverConstraints
                        
                    case .closeParen where constraints.isEmpty:
                        throw parseError(.noGenericConstraints(parent: objName, genericParam: genericParamName), loc: SourceRange(start: currentParamStartPos, end: currentPos))
                        
                    default:
                        throw parseError(.expectedGenericConstraint, loc: .at(pos: currentPos))
                    }
                }
                
                genericParameters.append((name: genericParamName, constraints: constraints, parentName: objName))
                
            default:
                if genericParameters.isEmpty { return nil }
                return genericParameters
            }
        }
        
    }
    
    
    
    
    /// Parse the declaration of a type
    ///
    /// - returns: The AST for a struct’s members, methods, & initialisers
    private func parseTypeDeclExpr() throws -> TypeDecl {
        
        let a = attrs
        attrs = []
        
        let refType = consumeIf(.ref)
        try consume(.type)
        
        guard let typeName = consumeIfIdentifier() else {
            throw parseError(.noTypeName, loc: .at(pos: currentPos))
        }
        
        let genericParameters = try parseGenericParameterList(objName: typeName)
        var concepts: [String] = []
        
        if consumeIf(.bar) {
            while let concept = consumeIfIdentifier() {
                concepts.append(concept)
            }
        }
        try consume(.openBrace)
        
        var properties: [TypeMemberVariableDecl] = [], methods: [FuncDecl] = [], initialisers: [InitDecl] = []
        
        conceptScopeLoop: while true {
            switch currentToken {
            case .var, .let:        try properties.append(parseVariableDecl(declContext: .type))
            case .func:             try methods.append(parseFuncDeclaration(declContext: .type))
            case .init:             try initialisers.append(parseInitDecl())
            case .at:               try parseAttrExpr()
            case .comment(let c):   try parseCommentExpr(str: c)
            case .closeBrace:
                try consume(.closeBrace)
                break conceptScopeLoop
            default:
                throw parseError(.objectNotAllowedInTopLevelOfTypeImpl(currentToken), loc: .at(pos: currentPos))
            }
            
        }
        
        let decl = TypeDecl(name: typeName,
                            attrs: a,
                            properties: properties,
                            methods: methods,
                            initialisers: initialisers,
                            genericParameters: genericParameters,
                            concepts: concepts,
                            byRef: refType)
        // associate functions with the struct
        for member in decl.properties {
            member.parent = decl
        }
        for method in decl.methods {
            method.parent = decl
        }
        for initialiser in decl.initialisers {
            initialiser.parent = decl
        }
        return decl
    }
    
    /// Parse type's init function
    private func parseInitDecl() throws -> InitDecl {
        
        try consume(.init)
        let repr = try parseFunctionTypeRepr()
        
        guard consumeIf(.assign) else {
            return InitDecl(ty: repr,
                            impl: nil,
                            parent: nil,
                            isImplicit: false)
        }
        return InitDecl(ty: repr,
                        impl: try parseFunctionBodyExpr(type: repr),
                        parent: nil,
                        isImplicit: false)
    }
    
    
    private func parseConceptDecl() throws -> ConceptDecl {
        try consume(.concept)
        
        guard let conceptName = consumeIfIdentifier() else {
            throw parseError(.noTypeName, loc: .at(pos: currentPos))
        }
        guard consumeIf(.openBrace) else {
            throw parseError(.expectedOpenBrace, loc: .at(pos: currentPos))
        }
        
        var properties: [TypeMemberVariableDecl] = [], methods: [FuncDecl] = []
        
        typeScopeLoop: while true {
            switch currentToken {
            case .var, .let:
                try properties.append(parseVariableDecl(declContext: .concept))
                
            case .func:
                try methods.append(parseFuncDeclaration(declContext: .concept))
                
            case .at:
                try parseAttrExpr()
                
            case .comment(let c):
                try parseCommentExpr(str: c)
                
            case .closeBrace:
                try consume(.closeBrace)
                break typeScopeLoop
                
            default:
                throw parseError(.objectNotAllowedInTopLevelOfTypeImpl(currentToken), loc: .at(pos: currentPos))
            }
        }
        let c = ConceptDecl(name: conceptName, requiredProperties: properties, requiredMethods: methods)
        
        for m in c.requiredMethods {
            m.parent = c
        }

        return c
    }
    
    
}






//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Other
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    /// Parse a comment literal
    @discardableResult private func parseCommentExpr(str: String) throws -> Expr {
        consumeToken() //eat comment
        return CommentExpr(str: str)
    }
    
    /// Parse an attribute on a function or type
    ///
    /// Updates the parser's cache
    private func parseAttrExpr() throws {
        try consume(.at)
        
        guard let id = consumeIfIdentifier() else { return }
        
        if consumeIf(.openParen) {
            switch id {
            case "operator":
                guard case let i as IntegerLiteral = try parseOperatorExpr() else {
                    throw parseError(.noPrecedenceForOperator, loc: .at(pos: currentPos))
                }
                attrs.append(ASTAttributeExpr.Operator(prec: i.val))
                
            default:
                throw parseError(.attrDoesNotHaveParams, loc: .at(pos: currentPos))
            }
            
            try consume(.closeParen)
        }
        else if let a = FunctionAttributeExpr(rawValue: id) {
            attrs.append(a)
        } 

    }
}


private enum DeclContext {
    case global, type, concept, function
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                           AST Generator
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parser entry point — parses a decl or stmt
    private func parseStmt(context: DeclContext) throws -> ASTNode? {
        
        switch currentToken {
        case .let:                return try parseVariableDecl(declContext: .global)
        case .var:                return try parseVariableDecl(declContext: .global)
        case .func:               return try parseFuncDeclaration(declContext: .global)
        case .return:             return try parseReturnStmt()
        case .yield:              return try parseYieldStmt()
        case .openParen:          return try parseParenExpr()
        case .openBrace:          return try parseBraceExpr()
        case .identifier:         return try parseIdentifier()
        case .comment(let str):   return try parseCommentExpr(str: str)
        case .if:                 return try parseIfStmt()
        case .for:                return try parseForInLoopStmt()
        case .do:                 return try parseBracelessDoExpr()
        case .while:              return try parseWhileLoopStmt()
        case .sqbrOpen:           return try parseArrayExpr()
        case .type, .ref:         return try parseTypeDeclExpr()
        case .concept:            return try parseConceptDecl()
        case .integerLiteral(let i):        return try parseIntExpr(i)
        case .floatingPointLiteral(let x):  return parseFloatingPointExpr(x)
        case .stringLiteral(let str):       return parseStringExpr(str)
        case .at:
            try parseAttrExpr()
            defer { attrs.removeAll() }
            return try parseStmt(context: context)
        case .void:
            index += 1
            return VoidExpr()
        case .EOF, .closeBrace:
            index += 1
            return nil
        case .newLine:
            consumeToken()
            return try parseStmt(context: context)
        default:
            throw parseError(.noToken(currentToken), loc: .at(pos: currentPos))
        }
    }
    
    
    private func tok() -> Token? { return index < tokens.count ? tokens[index] : nil }
    
    /// Returns AST from an instance of a parser
    private func parse() throws -> AST {
        
        index = 0
        exprs = []
        
        while let expr = try parseStmt(context: .global) {
            exprs.append(expr)
        }
        
        return AST(exprs: exprs)
    }
    
}





