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
final class Parser {
    
    private init(tokens: [(Token, SourceLoc)], isStdLib: Bool = false) {
        self.tokensWithPos = tokens.filter {
            if case .Comment = $0.0 { return false } else { return true }
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
        "..<": 40
    ]
    
    private func getNextToken(n: Int = 1) -> Token {
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
    
    private func resetConsiderNewLines() {
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
    ///
    private func parseTypeExpr() throws -> DefinedType {
        
        // if () type
        if case .OpenParen = currentToken, case .CloseParen = getNextToken() {
            getNextToken() // eat ')'
            return DefinedType.Void
        }
        
        var elements = [String]()
        loop: while true {
            switch currentToken {
            case let .Identifier(id):
                
                // handle native llvm type in stdlib
                if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where id == "LLVM" && isStdLib {
                    elements.append("LLVM.\(n)")    // param
                    getNextToken(3)// eat LLVM.Id
                }
                else {
                    elements.append(id)    // param
                    getNextToken()
                }

            case .SqbrOpen:
                guard case .Identifier(let id) = getNextToken() else { throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken()) }
                
                // handle native llvm type in stdlib
                if case .Period? = inspectNextToken(), case .Identifier(let n)? = inspectNextToken(2) where id == "LLVM" && isStdLib {
                    elements.append("LLVM.\(n)")    // param
                    getNextToken(2)// eat LLVM.Id
                }
                else {
                    elements.append(id)    // param
                    getNextToken()
                }
                guard case .SqbrClose = getNextToken() else { throw error(ParseError.ExpectedCloseBracket, loc: SourceRange.at(currentPos)) }
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
    ///
    private func parseParenExpr() throws -> Expr {
        
        // if in paren Expr we allow function parameters to be treated as functions not vars
        inTuple = false
        defer { revertInTupleState() }

        guard case .OpenParen = currentToken else { throw error(ParseError.ExpectedParen, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat `(`
        
        if case .CloseParen = currentToken {
            getNextToken() // eat `)`
            return TupleExpr.void()
        }
        
        var exps: [Expr] = []
        
        let head = try parseOperatorExpr()
        exps.append(head)
        
        if case .Comma = currentToken {
            revertInTupleState()
            inTuple = true
            getNextToken()
        }
        
        while case let a = currentToken where a.isValidParamToken {
            exps.append(try parseOperatorExpr())
            
            if inTuple {
                if case .Comma = currentToken {
                    getNextToken()
                }
                else { break }
            }
        }
        guard case .CloseParen = currentToken else { throw error(ParseError.ExpectedParen, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat `)`
        
        switch exps.count {
        case 0: return TupleExpr.void()
        case 1: return exps[0]
        case _: return TupleExpr(elements: exps)
        }
    }
    
    /// Parses a parameter list for a function call
    ///
    private func parseParamExpr() throws -> TupleExpr {
        
        var exps: [Expr] = []
        
        considerNewLines = true
        inTuple = true
        
        while case let a = currentToken where a.isValidParamToken {
            exps.append(try parseOperatorExpr())
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
    private func parseIdentifierAsVariable() throws -> VariableExpr {
        guard case .Identifier(let i) = currentToken else { throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken()) }
        return VariableExpr(name: i)
    }
    
    /// Handles parsing of an identifier token
    ///
    /// Works out whether its a function call, method lookup, variable
    /// instance, mutation, or tuple member lookup
    ///
    private func parseIdentifierExpr(token: String) throws -> Expr {
        
        switch inspectNextToken() {
        case .OpenParen? where inspectNextToken(2)?.isCloseParen ?? false: // call
            getNextToken(3) // eat 'func ()'
            return FunctionCallExpr(name: token, args: TupleExpr.void())
            
        case let u? where u.isValidParamToken && !inTuple:
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
            
            guard case .Identifier(let id) = currentToken else { throw error(ParseError.StdLibExprInvalid, userVisible: false) }
            return try parseIdentifierExpr("LLVM.\(id)")
            
        case .Period?: // property or fn
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
    ///
    private func parseMemberLookupExpr<Exp : AssignableExpr>(exp: Exp) throws -> Expr {
        
        switch currentToken {
        case .Identifier(let name):
            // property or method
            
            switch inspectNextToken() {
            case let u? where u.isValidParamToken && !inTuple: // method call
                getNextToken() // eat foo
                
                if case .OpenParen = currentToken {   // simple itentifier () call
                    getNextToken(2) // eat `)`
                    return MethodCallExpr(name: name, args: TupleExpr.void(), object: exp)
                }
                
                return MethodCallExpr(name: name, args: try parseParamExpr(), object: exp)
                
            case .Assign?:
                getNextToken(2) // eat `.foo` `=`
                
                let property = PropertyLookupExpr(name: name, object: exp)
                
                let exp = try parseOperatorExpr()
                return MutationExpr(object: property, value: exp)
                
            case .Period?: // nested lookup, like a.b.c
                getNextToken(2) // eat `foo.`

                let firstLookup = PropertyLookupExpr(name: name, object: exp)
                return try parseMemberLookupExpr(firstLookup)
                
            default: // otherwise its a property
                getNextToken()
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
    
    /// Function parses one expression, and can handle operators & parens, function 
    /// calls, literals & variables, blocks, arrays, and tuples
    ///
    /// Called on `return a + 1`, `let a = foo(x) + 1` and `if a < 3 do` etc
    ///
    /// - parameter exp: A known lhs operand to give more info to the parser
    ///
    /// - parameter prec: The precedence of the current token
    ///
    private func parseOperatorExpr(exp: Expr? = nil, prec: Int = 0) throws -> Expr {
        return try parseOperationRHS(prec, lhs: exp ?? (try parsePrimary()))
    }
    
    /// Parses a primary expression
    ///
    /// If it isnt succeeded by an operator this is the output of
    private func parsePrimary() throws -> Expr {
        
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
            return try parseParenExpr()
            
        case .OpenBrace, .Do /*, .OpenParen */: // FIXME: closures want to be able to do `let a = (u) do print u`
            let block = try parseBlockExpr()
            let closure = ClosureExpr(exprs: block.exprs, params: block.variables)
            return closure

        case .SqbrOpen:
            return try parseArrayExpr()
            
        case let .StringLiteral(str):
            return parseStringExpr(str)
            
        default:
            throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken())
        }
    }
    
    /// Parses RHS of an operator
    ///
    /// Handles precedence calculations and calls parseOperatorExpr again to get what follows
    ///
    private func parseOperationRHS(precedence: Int = 0, lhs: Expr) throws -> Expr {
        
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
    
    /// Parses an 'if else block' chain
    ///
    private func parseIfStmt() throws -> ConditionalStmt {
        
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
    
    /// Parses a `for _ in range do` statement
    ///
    private func parseForInLoopStmt() throws -> ForInLoopStmt {
        
        getNextToken() // eat 'for'
        let itentifier = try parseIdentifierAsVariable() // bind loop label
        guard case .In = getNextToken() else { throw error(ParseError.ExpectedIn, loc: SourceRange.at(currentPos)) }
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
    ///
    private func parseVariableDecl(mutble mutable: Bool, requiresInitialValue: Bool = true) throws -> VariableDecl {
        
        guard case let .Identifier(id) = getNextToken() else { throw error(ParseError.NoIdentifier, loc: rangeOfCurrentToken()) }
        
        let explicitType: DefinedType?
        
        if case .Colon = getNextToken() {
            getNextToken()
            explicitType = try parseTypeExpr()
        }
        else { explicitType = nil }
        
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
        
        let value = try parseOperatorExpr()
        return VariableDecl(name: id, type: explicitType, isMutable: mutable, value: value)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Function
//-------------------------------------------------------------------------------------------------------------------------


extension Parser {
    
    /// Parses the function type signature, like `Int Int -> Int` or `() -> Bool`
    ///
    private func parseFunctionType() throws -> FunctionType {
        
        // param type
        let p = try parseTypeExpr()
        
        // case like fn: Int =
        guard case .Returns = currentToken else {
            return FunctionType(paramType: p, returnType: DefinedType.Void)
        }
        getNextToken() // eat '->'
        
        let r = try parseTypeExpr()
        
        // case like fn: Int -> Int =
        guard case .Returns = currentToken else {
            return FunctionType(paramType: p, returnType: r)
        }
        
        var ty = FunctionType(paramType: p, returnType: r)
        
        // curried case like fn: Int -> Int -> Int
        while case .Returns = currentToken {
            getNextToken()

            let params = ty.returnType
            let returns = try parseTypeExpr()
            let out = FunctionType(paramType: params, returnType: returns)
            
            ty = FunctionType(paramType: ty.paramType, returnType: .Function(out))
        }
        
        return ty
    }
    
    /// Parse a function decl
    ///
    private func parseFuncDeclaration() throws -> FuncDecl {
        
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
        
        let start = inspectNextPos()
        guard case .Colon = getNextToken(), case .Colon = getNextToken() else {
            throw error(ParseError.ExpectedDoubleColon, loc: SourceRange(start: start!, end: currentPos))
        }
        
        getNextToken() // eat '='
        let type = try parseFunctionType()
        
        guard case .Assign = currentToken else {
            return FuncDecl(name: id, type: type, impl: nil, attrs: a)
        }
        getNextToken() // eat '='
        
        return FuncDecl(name: id, type: type, impl: try parseClosureDeclaration(type: type), attrs: a)
    }
    
    /// Get the parameter names applied
    ///
    private func parseClosureNamesExpr() throws -> [String] {
        
        guard case .OpenParen = currentToken else { return [] }
        getNextToken() // eat '('
        
        var nms: [String] = []
        while case let .Identifier(name) = currentToken {
            nms.append(name)
            getNextToken()
        }
        guard case .CloseParen = currentToken else { throw error(ParseError.ExpectedParen, loc: SourceRange.at(currentPos)) }
        guard let next = inspectNextToken() where next.isControlToken() else { throw error(ParseError.NotBlock, loc: SourceRange.at(currentPos)) }
        getNextToken() // eat 'do' or '{'
        
        return nms
    }
    
    /// Function parses the whole closure — used by functions & initialisers etc
    ///
    /// - returns: The function implementation—with parameter labels and the block’s expressions
    ///
    private func parseClosureDeclaration(anon anon: Bool = false, type: FunctionType) throws -> FunctionImplementationExpr {
        let names: [String]
        
        if case .OpenParen = currentToken {
            names = try parseClosureNamesExpr()
        }
        else {
            names = (0..<type.paramType.typeNames().count).map(implicitParamName)
        }
        
        guard currentToken.isControlToken() else { throw error(ParseError.NotBlock, loc: SourceRange.at(currentPos)) }
        
        return FunctionImplementationExpr(params: names, body: try parseBlockExpr())
    }
    
    /// Parses the insides of a '{...}' expression
    ///
    private func parseBraceExpr(names: [String] = []) throws -> BlockExpr {
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
    
    /// Parses the expression in a 'do' block
    ///
    private func parseBracelessDoExpr(names: [String] = []) throws -> BlockExpr {
        getNextToken() // eat 'do'
        
        guard let ex = try parseExpr(currentToken) else { throw error(ParseError.NoToken(currentToken), loc: SourceRange.at(currentPos)) }
        
        return BlockExpr(exprs: [ex], variables: names)
    }
    
    /// Parses expression following a `return`
    ///
    private func parseReturnExpr() throws -> ReturnStmt {
        getNextToken() // eat `return`
        
        return ReturnStmt(expr: try parseOperatorExpr())
    }

    /// Function scopes -- starts a new '{' or 'do' block
    ///
    /// Will parse any arg labels applied in parens
    ///
    private func parseBlockExpr(names: [String] = []) throws -> BlockExpr {
        
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
    
    /// Parses an array literal expression
    ///
    private func parseArrayExpr() throws -> Expr {
        
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
    
    /// Parse the declaration of a type
    ///
    /// - returns: The AST for a struct’s members, methods, & initialisers
    ///
    private func parseTypeDeclarationExpr(byRef byRef: Bool) throws -> StructExpr {
        
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
                properties.append(try parseVariableDecl(mutble: true, requiresInitialValue: false))
                
            case .Let:
                properties.append(try parseVariableDecl(mutble: false, requiresInitialValue: false))
                
            case .Func:
                methods.append(try parseFuncDeclaration())
                
            case .Init:
                initialisers.append(try parseInitDecl())
                
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
    
    /// Parse type's init function
    ///
    private func parseInitDecl() throws -> InitialiserDecl {
        
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
    
    /// Parse a comment literal
    private func parseCommentExpr(str: String) throws -> Expr {
        getNextToken() //eat comment
        return CommentExpr(str: str)
    }
    
    /// Parse an attribute on a function or type
    ///
    /// Updates the parser's cache
    ///
    private func parseAttrExpr() throws {
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
    
    /// Master parse function — depending on input calls the relevant child functions
    /// and constructs a branch of the AST
    ///
    private func parseExpr(token: Token) throws -> ASTNode? {
        
        switch token {
        case .Let:                  return try parseVariableDecl(mutble: false)
        case .Var:                  return try parseVariableDecl(mutble: true)
        case .Func:                 return try parseFuncDeclaration()
        case .Return:               return try parseReturnExpr()
        case .OpenParen:            return try parseParenExpr()
        case .OpenBrace:            return try parseBraceExpr()
        case .Identifier(let str):  return try parseIdentifierExpr(str)
        case .InfixOperator:        return try parseOperatorExpr()
        case .Comment(let str):     return try parseCommentExpr(str)
        case .If:                   return try parseIfStmt()
        case .For:                  return try parseForInLoopStmt()
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
    
    
    private func tok() -> Token? { return index < tokens.count ? tokens[index] : nil }
    
    /// Returns abstract syntax tree from an instance of a parser
    ///
    private func parse() throws -> AST {
        
        index = 0
        exprs = []
        
        while let tok = tok() {
            if let exp = try parseExpr(tok) {
                exprs.append(exp)
            }
        }
        
        return AST(exprs: exprs)
    }
    
    static func parseWith(toks: [(Token, SourceLoc)], isStdLib: Bool = false) throws -> AST {
        let p = Parser(tokens: toks, isStdLib: isStdLib)
        return try p.parse()
    }
    
}





