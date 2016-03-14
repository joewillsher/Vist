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
        if self.isEmpty { throw parseError(.invalidCall(str), loc: SourceRange.at(pos)) } else { return removeLast() }
    }
}

private extension Token {
    func isControlToken() -> Bool {
        switch self {
        case .`do`, .openBrace: return true
        default: return false
        }
    }
    func isBrace() -> Bool {
        if case .openBrace = self { return true } else { return false }
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
        "..<": 40,
        "<<": 10,
        ">>": 10,
        "~|": 10,
        "~^": 10,
        "~&": 15
    ]
    
    private func getNextToken(n: Int = 1) -> Token {
        if n == 0 { return currentToken }
        index += 1
        if case .newLine = currentToken where !considerNewLines {
            return getNextToken(n)
        }
        return getNextToken(n-1)
    }
    private func inspectNextToken(i: Int = 1) -> Token? { // debug function, acts as getNextToken() but does not mutate
        if index+i >= tokens.count-i { return nil }
        if case .newLine = currentToken where !considerNewLines {
            return inspectNextToken(i+1)
        }
        return tokens[index+i]
    }
    private func inspectNextPos(i: Int = 1) -> Pos? {
        if index+i >= tokens.count-i { return nil }
        if case .newLine = currentToken where !considerNewLines {
            return inspectNextPos(i+1)
        }
        return tokensWithPos.map{$0.1.range.start}[index+i]
    }
    
    
    private func rangeOfCurrentToken() -> SourceRange? {
        return inspectNextPos().map { SourceRange(start: currentPos, end: $0) }
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
    
    
    /// When parsing a parameter list we want to lay out function parameters next to eachother
    ///
    /// `add a b` parses as `add(a, b)` not `parse(a(b))`
    ///
    /// This flag is true if the parser is in a parameter list where identifiers are assumed to be vars not funcs
    private var inTuple: Bool {
        get {
            return _inTuple.last ?? false
        }
        set {
            _inTuple.append(newValue)
        }
    }
    private var _inTuple: [Bool] = [false]
    
    private func revertInTupleState() {
        _inTuple.removeLast()
    }

}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Literals
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Int literal expression
    private func parseIntExpr(token: Int) throws -> Expr {
        getNextToken()
        let i = IntegerLiteral(val: token)
        
        // TODO: make literals lookupable
//        if case .Period? = inspectNextToken() where isStdLib {
//            getNextToken()
//            return try parseMemberLookupExpr(i)
//        }
        
        return i
    }
    /// Float literal expression
    private func parseFloatingPointExpr(token: Double) -> FloatingPointLiteral {
        getNextToken()
        return FloatingPointLiteral(val: token)
    }
    /// String literal expression
    private func parseStringExpr(token: String) -> StringLiteral {
        getNextToken()
        return StringLiteral(str: token)
    }
    /// Bool literal expression
    private func parseBooleanExpr(token: Bool) throws -> Expr {
        getNextToken()
        let b = BooleanLiteral(val: token)
        
//        if case .Period? = inspectNextToken() where isStdLib {
//            getNextToken()
//            return try parseMemberLookupExpr(b)
//        }
        
        return b
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                          Tuple, brackets, and params
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parses type expression, used in variable decls and function signatures
    private func parseTypeExpr() throws -> DefinedType {
        
        // if () type
        if case .openParen = currentToken, case .closeParen = getNextToken() {
            getNextToken() // eat ')'
            return DefinedType.void
        }
        
        var elements = [String]()
        loop: while true {
            switch currentToken {
            case .identifier(let id):
                
                // handle native llvm type in stdlib
                if case .period? = inspectNextToken(), case .identifier(let n)? = inspectNextToken(2) where id == "Builtin" && isStdLib {
                    elements.append("Builtin.\(n)")    // param
                    getNextToken(3)// eat Builtin.Id
                }
                else {
                    elements.append(id)    // param
                    getNextToken()
                }

            case .sqbrOpen:
                guard case .identifier(let id) = getNextToken() else { throw parseError(.noIdentifier, loc: rangeOfCurrentToken()) }
                
                // handle native llvm type in stdlib
                if case .period? = inspectNextToken(), case .identifier(let n)? = inspectNextToken(2) where id == "Builtin" && isStdLib {
                    elements.append("Builtin.\(n)")    // param
                    getNextToken(2)// eat Builtin.Id
                }
                else {
                    elements.append(id)    // param
                    getNextToken()
                }
                
                guard case .sqbrClose = getNextToken() else { throw parseError(.expectedCloseBracket, loc: SourceRange.at(currentPos)) }
                getNextToken() // eat ]
                
            default:
                break loop
            }
        }
        
        return DefinedType(elements)
    }
    
    
    /// Parses an expression wrapped in parentheses
    ///
    /// If its a 0, or multi element tuple, this returns a tuple, otherwise the value in
    /// parens (as they were just used for disambiguation or operator precedence override)
    private func parseParenExpr() throws -> Expr {
        
        // if in paren Expr we allow function parameters to be treated as functions not vars
        inTuple = false
        defer { revertInTupleState() }

        guard case .openParen = currentToken else { throw parseError(.expectedParen, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat `(`
        
        if case .closeParen = currentToken {
            getNextToken() // eat `)`
            return TupleExpr.void()
        }
        
        var exps: [Expr] = []
        
        let head = try parseOperatorExpr()
        exps.append(head)
        
        if case .comma = currentToken {
            revertInTupleState()
            inTuple = true
            getNextToken()
        }
        
        while case let a = currentToken where a.isValidParamToken {
            exps.append(try parseOperatorExpr())
            
            if inTuple {
                if case .comma = currentToken {
                    getNextToken()
                }
                else { break }
            }
        }
        guard case .closeParen = currentToken else { throw parseError(.expectedParen, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat `)`
        
        switch exps.count {
        case 0: return TupleExpr.void()
        case 1: return exps[0]
        case _: return TupleExpr(elements: exps)
        }
    }
    
    /// Parses a parameter list for a function call
    private func parseParamExpr() throws -> TupleExpr {
        
        var exps: [Expr] = []
        
        considerNewLines = true
        inTuple = true
        
        while case let a = currentToken where a.isValidParamToken {
            exps.append(try parseOperatorExpr())
        }
        
        revertInTupleState()
        resetConsiderNewLines()
        
        return exps.isEmpty ? TupleExpr.void(): TupleExpr(elements: exps)
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                      Identifier and operators
//-------------------------------------------------------------------------------------------------------------------------
extension Parser {
    
    /// Parses a text token as a VariableExpr
    private func parseIdentifierAsVariable() throws -> VariableExpr {
        guard case .identifier(let i) = currentToken else { throw parseError(.noIdentifier, loc: rangeOfCurrentToken()) }
        return VariableExpr(name: i)
    }
    
    /// Handles parsing of an identifier token
    ///
    /// Works out whether its a function call, method lookup, variable
    /// instance, mutation, or tuple member lookup
    private func parseIdentifierExpr(token: String) throws -> Expr {
        
        switch inspectNextToken() {
        case .openParen? where inspectNextToken(2)?.isCloseParen ?? false: // call
            getNextToken(3) // eat 'func ()'
            return FunctionCallExpr(name: token, args: TupleExpr.void())
            
        case let u? where u.isValidParamToken && !inTuple:
            getNextToken() // eat 'identifier'
            
            return FunctionCallExpr(name: token, args: try parseParamExpr())
            
        case .sqbrOpen?: // subscript
            getNextToken(2) // eat 'identifier['
            
            let subscpipt = try parseOperatorExpr()
            getNextToken() // eat ']'
            
            guard case .assign = currentToken else { // if call
                return ArraySubscriptExpr(arr: VariableExpr(name: token), index: subscpipt)
            }
            getNextToken() // eat '='
            
            let exp = try parseOperatorExpr()
            // if assigning to subscripted value
            return MutationExpr(object: ArraySubscriptExpr(arr: VariableExpr(name: token), index: subscpipt), value: exp)
            
        case .assign?: // mutation
            getNextToken(2)// eat 'identifier ='
            
            let exp = try parseOperatorExpr()
            
            return MutationExpr(object: VariableExpr(name: token), value: exp)
            
        case .period? where token == "Builtin" && isStdLib:
            getNextToken(2) // eat 'Builtin.'
            
            guard case .identifier(let id) = currentToken else { throw parseError(.stdLibExprInvalid, userVisible: false) }
            return try parseIdentifierExpr("Builtin.\(id)")
            
        case .period?: // property or fn
            getNextToken(2) // eat `.`
            
            return try parseMemberLookupExpr(VariableExpr(name: token))
            
        default: // just identifier
            
            defer { getNextToken() }
            return try parseOperatorExpr(VariableExpr(name: token))
        }
    }
    
    /// Handles the case of `identifier.`*something*
    ///
    /// Parses property and tuple member lookup, and method calls
    private func parseMemberLookupExpr(exp: ChainableExpr) throws -> Expr {
        
        switch currentToken {
        case .identifier(let name):
            // property or method
            
            switch inspectNextToken() {
            case let u? where u.isValidParamToken && !inTuple: // method call
                getNextToken() // eat foo
                
                if case .openParen = currentToken {   // simple itentifier () call
                    getNextToken(2) // eat `)`
                    return MethodCallExpr(name: name, args: TupleExpr.void(), object: exp)
                }
                return MethodCallExpr(name: name, args: try parseParamExpr(), object: exp)
                
            case .assign?:
                getNextToken(2) // eat `.foo` `=`
                
                let property = PropertyLookupExpr(propertyName: name, object: exp)
                
                let exp = try parseOperatorExpr()
                return MutationExpr(object: property, value: exp)
                
            case .period?: // nested lookup, like a.b.c
                getNextToken(2) // eat `foo.`

                let firstLookup = PropertyLookupExpr(propertyName: name, object: exp)
                return try parseMemberLookupExpr(firstLookup)
                
            default: // otherwise its a property
                getNextToken()
                return PropertyLookupExpr(propertyName: name, object: exp)
            }
            
        case .integerLiteral(let i):
            let element = TupleMemberLookupExpr(index: i, object: exp)
            
            switch getNextToken() {
            case .assign:
                getNextToken() // eat =
                let exp = try parseOperatorExpr()
                return MutationExpr(object: element, value: exp)
                
            case .period: // nested lookup, like a.b.c
                getNextToken() // eat `foo.`
                return try parseMemberLookupExpr(element)
                
            default:
                return element
            }
            
        default:
            throw parseError(.noIdentifier, loc: rangeOfCurrentToken())
        }
        
    }
    
    /// Function parses one expression, and can handle operators & parens, function 
    /// calls, literals & variables, blocks, arrays, and tuples
    ///
    /// Called on `return a + 1`, `let a = foo(x) + 1` and `if a < 3 do` etc
    ///
    /// - parameter exp: A known lhs operand to give more info to the parser
    ///
    /// - parameter prec: The precedence of the current token
    private func parseOperatorExpr(exp: Expr? = nil, prec: Int = 0) throws -> Expr {
        return try parseOperationRHS(prec, lhs: exp ?? (try parsePrimary()))
    }
    
    /// Parses a primary expression
    ///
    /// If it isnt succeeded by an operator this is the output of
    private func parsePrimary() throws -> Expr {
        
        switch currentToken {
        case .identifier(let id):
            return try parseIdentifierExpr(id)
            
        case .prefixOperator(let op):
            getNextToken()
            return PrefixExpr(op: op, expr: try parsePrimary())
            
        case .integerLiteral(let i):
            return try parseIntExpr(i)
            
        case .floatingPointLiteral(let f):
            return parseFloatingPointExpr(f)
            
        case .booleanLiteral(let b):
            return try parseBooleanExpr(b)
            
        case .openParen:
            return try parseParenExpr()
            
        case .openBrace, .`do` /*, .OpenParen */: // FIXME: closures want to be able to do `let a = (u) do print u`
            let block = try parseBlockExpr()
            let closure = ClosureExpr(exprs: block.exprs, params: block.variables)
            return closure

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
            getNextToken()
            
            // Error handling
            let rhs = try parsePrimary()
            
            // Get next operator
            guard case .infixOperator(let nextOp) = currentToken else { return BinaryExpr(op: op, lhs: lhs, rhs: rhs) }
            guard let nextTokenPrecedence = precedences[nextOp] else { throw parseError(.noOperator(op), loc: rangeOfCurrentToken()) }
            
            let newRhs = try parseOperationRHS(tokenPrecedence, lhs: rhs)
            
            if tokenPrecedence <= nextTokenPrecedence {
                return try parseOperationRHS(nextTokenPrecedence, lhs: BinaryExpr(op: op, lhs: lhs, rhs: newRhs))
            }
            return try parseOperationRHS(precedence + 1, lhs: BinaryExpr(op: op, lhs: lhs, rhs: rhs))
            
            // Collapse the postfix operator and continue parsing
        case .postfixOperator(let op):
            
            getNextToken()
            let newLHS = PostfixExpr(op: op, expr: lhs)
            return try parseOperationRHS(precedence, lhs: newLHS)
            
        case .prefixOperator(let op):
            
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
    
    /// Parses an 'if else block' chain
    private func parseIfStmt() throws -> ConditionalStmt {
        
        getNextToken() // eat `if`
        let condition = try parseOperatorExpr()
        
        // list of blocks
        var blocks: [(condition: Expr?, block: BlockExpr)] = []
        
        let usesBraces = currentToken.isBrace()
        // get if block & append
        guard currentToken.isControlToken() else { throw parseError(.notBlock, loc: SourceRange.at(currentPos)) }
        let block = try parseBlockExpr()
        blocks.append((condition, block))
        
        while case .`else` = currentToken {
            
            var condition: Expr?
            
            if case .`if`? = inspectNextToken() {
                // `else if` statement
                getNextToken(2)
                condition = try parseOperatorExpr()
                
                guard currentToken.isControlToken() && (usesBraces == currentToken.isBrace()) else { throw parseError(.notBlock, loc: SourceRange.at(currentPos)) }
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
    
    /// Parses a `for _ in range do` statement
    private func parseForInLoopStmt() throws -> ForInLoopStmt {
        
        getNextToken() // eat 'for'
        let itentifier = try parseIdentifierAsVariable() // bind loop label
        guard case .`in` = getNextToken() else { throw parseError(.expectedIn, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat 'in'
        
        let loop = try parseOperatorExpr()
        let block = try parseBlockExpr()
        
        return ForInLoopStmt(identifier: itentifier, iterator: loop, block: block)
    }
    
    /// Parses while loop statements
    ///
    private func parseWhileLoopStmt() throws -> WhileLoopStmt {
        
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
    
    /// Parses a variable's declaration
    private func parseVariableDecl(declContext: DeclContext) throws -> [VariableDecl] {
        
        let mutable: Bool
        switch currentToken {
        case .`let`: mutable = false
        case .`var`: mutable = true
        default: throw parseError(.notVariableDecl, userVisible: false)
        }
        
        var decls: [VariableDecl] = []
        getNextToken()
        
        while true {
            guard case .identifier(let id) = currentToken else { throw parseError(.noIdentifier, loc: rangeOfCurrentToken()) }
            
            let explicitType: DefinedType?
            
            if case .colon = getNextToken() {
                getNextToken()
                explicitType = try parseTypeExpr()
            }
            else { explicitType = nil }
            // TODO: Closure declaration parsing
            
            /// Declaration used if no initial value is given
            
            var decl: VariableDecl
            
            switch currentToken {
            case .assign:
                // concept member cannot provide value
                if case .concept = declContext {
                    throw parseError(.conceptCannotProvideVal, loc: SourceRange.at(currentPos))
                }
                
                getNextToken() // eat '='
                
                let value = try parseOperatorExpr()
                decl = VariableDecl(name: id, type: explicitType, isMutable: mutable, value: value)
                
            default: // if no value provided
                guard let _ = explicitType else {
                    throw parseError(.expectedAssignment, loc: SourceRange.at(currentPos))
                }
                
//                let placeholder = PlaceholderExpr(_type: nil, defined: ex)
                decl = VariableDecl(name: id, type: explicitType, isMutable: mutable, value: NullExpr())
            }
            
            if case .comma = currentToken {
                decls.append(decl)
                getNextToken()
            }
            else {
                decls.append(decl)
                return decls
            }
        }
    }
    
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Function
//-------------------------------------------------------------------------------------------------------------------------


extension Parser {
    
    /// Parses the function type signature, like `Int Int -> Int` or `() -> Bool`
    private func parseFunctionType() throws -> DefinedFunctionType {
        
        // param type
        var ty = DefinedFunctionType(paramType: try parseTypeExpr(), returnType: DefinedType.void)

        // case like `func fn: Int = `
        guard case .returnArrow = currentToken else { return ty }
        getNextToken() // eat '->'
        
        // case like `func fn: Int -> Int =`
        ty = DefinedFunctionType(paramType: ty.paramType, returnType: try parseTypeExpr())
        
        // curried case like `func fn: Int -> Int -> Int =`
        while case .returnArrow = currentToken {
            getNextToken()

            let params = ty.returnType
            let returns = try parseTypeExpr()
            let out = DefinedFunctionType(paramType: params, returnType: returns)
            
            ty = DefinedFunctionType(paramType: ty.paramType, returnType: .function(out))
        }
        
        return ty
    }
    
    /// Parse a function decl
    private func parseFuncDeclaration(declContext: DeclContext) throws -> FuncDecl {
        
        let a = attrs.flatMap { $0 as? FunctionAttributeExpr } ?? []
        let ops = attrs.flatMap { $0 as? ASTAttributeExpr }.flatMap { a -> Int? in if case .Operator(let p) = a { return p } else { return nil } }.last
        attrs = []
        
        getNextToken()
        let s: String
        if case .identifier(let n) = currentToken {
            s = n
        }
        else if case .infixOperator(let o) = currentToken, let pp = ops {
            s = o
            
            let found = precedences[o]
            if let x = found where x != ops { // make sure uses op’s predetermined prec
                throw parseError(.cannotChangeOpPrecedence(o, x), loc: SourceRange.at(currentPos))
            }
            else if found == nil {
                precedences[o] = pp // update prec table if not found
            }
        }
        else {
            throw parseError(.noIdentifier, loc: rangeOfCurrentToken())
        }
        
        let functionName: String
        if case .period? = inspectNextToken(), case .identifier(let n)? = inspectNextToken(2) where s == "Builtin" && isStdLib {
            functionName = "Builtin.\(n)"
            getNextToken(2) // eat
        }
        else {
            functionName = s
        }
        getNextToken()
        
        let genericParameters = try parseGenericParameterList(objName: functionName)
        
        let typeSignatureStartPos = currentPos
        guard case .colon = currentToken, case .colon = getNextToken() else {
            throw parseError(.expectedDoubleColon, loc: SourceRange(start: typeSignatureStartPos, end: currentPos))
        }
        
        getNextToken() // eat '='
        let type = try parseFunctionType()
        
        guard case .assign = currentToken else {
            return FuncDecl(name: functionName, type: type, impl: nil, attrs: a, genericParameters: genericParameters)
        }
        getNextToken() // eat '='
        
        return FuncDecl(name: functionName, type: type, impl: try parseClosureDeclaration(type: type), attrs: a, genericParameters: genericParameters)
    }
    
    /// Get the parameter names applied
    private func parseClosureNamesExpr() throws -> [String] {
        
        guard case .openParen = currentToken else { return [] }
        getNextToken() // eat '('
        
        var nms: [String] = []
        while case .identifier(let name) = currentToken {
            nms.append(name)
            getNextToken()
        }
        guard case .closeParen = currentToken else { throw parseError(.expectedParen, loc: SourceRange.at(currentPos)) }
        guard let next = inspectNextToken() where next.isControlToken() else { throw parseError(.notBlock, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat 'do' or '{'
        
        return nms
    }
    
    /// Function parses the whole closure — used by functions & initialisers etc
    ///
    /// - returns: The function implementation—with parameter labels and the block’s expressions
    private func parseClosureDeclaration(anon anon: Bool = false, type: DefinedFunctionType) throws -> FunctionImplementationExpr {
        let names: [String]
        
        if case .openParen = currentToken {
            names = try parseClosureNamesExpr()
        }
        else {
            names = (0..<type.paramType.typeNames().count).map(implicitParamName)
        }
        
        guard currentToken.isControlToken() else { throw parseError(.notBlock, loc: SourceRange.at(currentPos)) }
        
        return FunctionImplementationExpr(params: names, body: try parseBlockExpr())
    }
    
    /// Parses the insides of a '{...}' expression
    private func parseBraceExpr(names: [String] = []) throws -> BlockExpr {
        getNextToken() // eat '{'
        
        var exprs = [ASTNode]()
        
        while true {
            if case .closeBrace = currentToken { break }
            exprs.appendContentsOf(try parseExpr(currentToken))
        }
        getNextToken() // eat '}'
        return BlockExpr(exprs: exprs, variables: names)
    }
    
    /// Parses the expression in a 'do' block
    private func parseBracelessDoExpr(names: [String] = []) throws -> BlockExpr {
        getNextToken() // eat 'do'
        
        return BlockExpr(exprs: try parseExpr(currentToken), variables: names)
    }
    
    /// Parses expression following a `return`
    private func parseReturnExpr() throws -> ReturnStmt {
        getNextToken() // eat `return`
        
        return ReturnStmt(expr: try parseOperatorExpr())
    }

    /// Function scopes -- starts a new '{' or 'do' block
    ///
    /// Will parse any arg labels applied in parens
    private func parseBlockExpr(names: [String] = []) throws -> BlockExpr {
        
        switch currentToken {
        case .openParen:    return try parseBlockExpr(try parseClosureNamesExpr())
        case .openBrace:    return try parseBraceExpr(names)
        case .`do`, .`else`:return try parseBracelessDoExpr(names)
        default:            throw parseError(.notBlock, loc: SourceRange.at(currentPos))
        }
        
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Array
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Parses an array literal expression
    private func parseArrayExpr() throws -> Expr {
        
        getNextToken() // eat '['
        
        var elements = [Expr]()
        while true {
            switch currentToken {
            case .comma:
                getNextToken()  // eat ','
                
            case .sqbrClose:
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
    
    private func parseGenericParameterList(objName objName: String ) throws -> [ConstrainedType] {
        
        var genericParameters: [ConstrainedType] = []
        
//        type TwoType T U {
//        type Array (Element | Foo Bar) {
        
        let genericParamListStartPos = currentPos
        
        while true {
            switch currentToken {
            case .identifier(let genericParamName):
                genericParameters.append((name: genericParamName, constraints: [], parentName: objName))
                getNextToken()
                
            case .openParen:
                let currentParamStartPos = currentPos
                
                guard case .identifier(let genericParamName) = getNextToken() else { // get name of generic param
                    throw parseError(.noGenericParamName(on: objName), loc: SourceRange(start: genericParamListStartPos, end: currentPos))
                }
                guard case .bar = getNextToken() else { // if we are using parens in generic param we must constrain it
                    throw parseError(.expectedBar, loc: SourceRange(start: inspectNextPos(-2) ?? currentPos, end: currentPos))
                }
                
                var constraints: [String] = []
                
                loopOverConstraints: while true {
                    switch getNextToken() {
                    case .identifier(let constraint):
                        constraints.append(constraint)
                        
                    case .closeParen where !constraints.isEmpty:
                        getNextToken() // eat ')'
                        break loopOverConstraints
                        
                    case .closeParen where constraints.isEmpty:
                        throw parseError(.noGenericConstraints(parent: objName, genericParam: genericParamName), loc: SourceRange(start: currentParamStartPos, end: currentPos))
                        
                    default:
                        throw parseError(.expectedGenericConstraint, loc: SourceRange.at(currentPos))
                    }
                }
                
                genericParameters.append((name: genericParamName, constraints: constraints, parentName: objName))
                
            default:
                return genericParameters
            }
        }
        
    }
    
    
    
    
    /// Parse the declaration of a type
    ///
    /// - returns: The AST for a struct’s members, methods, & initialisers
    private func parseTypeDeclarationExpr(byRef byRef: Bool) throws -> StructExpr {
        
        let a = attrs
        attrs = []
        
        getNextToken() // eat 'type'
        
        guard case .identifier(let typeName) = currentToken else { throw parseError(.noTypeName, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat name
        
        let genericParameters = try parseGenericParameterList(objName: typeName)
        
        guard case .openBrace = currentToken else { throw parseError(.expectedOpenBrace, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat '{'
        
        var properties: [VariableDecl] = [], methods: [FuncDecl] = [], initialisers: [InitialiserDecl] = []
        
        conceptScopeLoop: while true {
            switch currentToken {
            case .`var`, .`let`:
                properties.appendContentsOf(try parseVariableDecl(.type))
                
            case .`func`:
                methods.append(try parseFuncDeclaration(.type))
                
            case .`init`:
                initialisers.append(try parseInitDecl())
                
            case .at:
                try parseAttrExpr()
                
            case .comment(let c):
                try parseCommentExpr(c)
                
            case .closeBrace:
                break conceptScopeLoop
                
            default:
                throw parseError(.objectNotAllowedInTopLevelOfTypeImpl(currentToken), loc: SourceRange.at(currentPos))
            }
            
        }
        
        let s = StructExpr(name: typeName, properties: properties, methods: methods, initialisers: initialisers, attrs: a, genericParameters: genericParameters)
        
        // associate functions with the struct
        for i in s.initialisers {
            i.parent = s
        }
        
        for m in s.methods {
            m.parent = s
        }
        
        return s
    }
    
    /// Parse type's init function
    private func parseInitDecl() throws -> InitialiserDecl {
        
        getNextToken() // eat `init`
        let type = try parseFunctionType()
        guard case .assign = currentToken else {
            return InitialiserDecl(ty: type, impl: nil, parent: nil)
        }
        getNextToken() // eat `=`
        
        return InitialiserDecl(ty: type, impl: try parseClosureDeclaration(type: type), parent: nil)
    }
    
    
    private func parseConceptExpr() throws -> ConceptExpr {
        getNextToken() // eat 'concept'
        
        guard case .identifier(let conceptName) = currentToken else { throw parseError(.noTypeName, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat name
        
        guard case .openBrace = currentToken else { throw parseError(.expectedOpenBrace, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat '{'
        
        var properties: [VariableDecl] = [], methods: [FuncDecl] = []
        
        typeScopeLoop: while true {
            switch currentToken {
            case .`var`, .`let`:
                properties.appendContentsOf(try parseVariableDecl(.concept))
                
            case .`func`:
                methods.append(try parseFuncDeclaration(.concept))
                
            case .at:
                try parseAttrExpr()
                
            case .comment(let c):
                try parseCommentExpr(c)
                
            case .closeBrace:
                break typeScopeLoop
                
            default:
                throw parseError(.objectNotAllowedInTopLevelOfTypeImpl(currentToken), loc: SourceRange.at(currentPos))
            }
        }
        let c = ConceptExpr(name: conceptName, requiredProperties: properties, requiredMethods: methods)
        
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
    private func parseCommentExpr(str: String) throws -> Expr {
        getNextToken() //eat comment
        return CommentExpr(str: str)
    }
    
    /// Parse an attribute on a function or type
    ///
    /// Updates the parser's cache
    private func parseAttrExpr() throws {
        getNextToken() // eat @
        
        guard case .identifier(let id) = currentToken else { return }
        
        if case .openParen? = inspectNextToken() {
            getNextToken(2)
            
            switch id {
            case "operator":
                guard case let i as IntegerLiteral = try parseOperatorExpr() else { throw parseError(.noPrecedenceForOperator, loc: SourceRange.at(currentPos)) }
                attrs.append(ASTAttributeExpr.Operator(prec: i.val))
                
            default:
                throw parseError(.attrDoesNotHaveParams, loc: SourceRange.at(currentPos))
            }
            
            guard case .closeParen = currentToken else { throw parseError(.expectedParen, loc: SourceRange.at(currentPos)) }
            getNextToken()
        }
        else if let a = FunctionAttributeExpr(rawValue: id) {
            getNextToken()
            attrs.append(a)
        } 

    }
}


private enum DeclContext {
    case global, type, concept
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                           AST Generator
//-------------------------------------------------------------------------------------------------------------------------

extension Parser {
    
    /// Master parse function — depending on input calls the relevant child functions
    /// and constructs a branch of the AST
    private func parseExpr(token: Token) throws -> [ASTNode] {
        
        switch token {
        case .`let`:                return try parseVariableDecl(.global).mapAs(ASTNode) // swift bug
        case .`var`:                return try parseVariableDecl(.global).mapAs(ASTNode)
        case .`func`:               return [try parseFuncDeclaration(.global)]
        case .`return`:             return [try parseReturnExpr()]
        case .openParen:            return [try parseParenExpr()]
        case .openBrace:            return [try parseBraceExpr()]
        case .identifier(let str):  return [try parseIdentifierExpr(str)]
        case .comment(let str):     return [try parseCommentExpr(str)]
        case .`if`:                 return [try parseIfStmt()]
        case .`for`:                return [try parseForInLoopStmt()]
        case .`do`:                 return [try parseBracelessDoExpr()]
        case .`while`:              return [try parseWhileLoopStmt()]
        case .sqbrOpen:             return [try parseArrayExpr()]
        case .type:                 return [try parseTypeDeclarationExpr(byRef: false)]
        case .concept:              return [try parseConceptExpr()]
        case .reference:            getNextToken(); return [try parseTypeDeclarationExpr(byRef: true)]
        case .integerLiteral(let i):        return  [try parseIntExpr(i)]
        case .floatingPointLiteral(let x):  return [parseFloatingPointExpr(x)]
        case .stringLiteral(let str):       return [parseStringExpr(str)]
        case .at:                   try parseAttrExpr(); return []
        case .void:                 index += 1; return [Void()]
        case .EOF, .closeBrace:     index += 1; return []
        case .newLine:              getNextToken(); return []
        default:                    throw parseError(.noToken(token), loc: SourceRange.at(currentPos))
        }
    }
    
    
    private func tok() -> Token? { return index < tokens.count ? tokens[index] : nil }
    
    /// Returns abstract syntax tree from an instance of a parser
    private func parse() throws -> AST {
        
        index = 0
        exprs = []
        
        while let tok = tok() {
            exprs.appendContentsOf(try parseExpr(tok))
        }
        
        return AST(exprs: exprs)
    }
    
    static func parseWith(toks: [(Token, SourceLoc)], isStdLib: Bool = false) throws -> AST {
        let p = Parser(tokens: toks, isStdLib: isStdLib)
        return try p.parse()
    }
    
}





