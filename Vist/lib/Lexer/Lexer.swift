//
//  Lexer.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.NSString
import class Foundation.NumberFormatter
import class Foundation.Scanner

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Helpers
//-------------------------------------------------------------------------------------------------------------------------

enum LexerError: Error {
    case outOfRange
    case noToken
}

private func identity<T>(a:T)->T { return a }


private extension Character {
    
    var value: Int32 {
        let s = String(self).unicodeScalars
        return Int32(s[s.startIndex].value)
    }
    
    /// Is an operator code unit in itself
    ///
    /// These are language code units which should be lexed
    /// as independent always
    func isOperatorCodeUnit() -> Bool {
        return "=[],.:;()->|}{@".characters.contains(self)
    }
    // TODO
//    /// Is a valid start of an operator
//    func isOperatorStartCodeUnit() -> Bool {
//        
//    }
//    func isIdentifierStartCodeUnit() -> Bool {
//        
//    }
//    func isIdentifierContinuationCodeUnit() -> Bool {
//        
//    }

    

    func isNum() -> Bool {
        return isdigit(value) != 0
    }

    func isAlphaOr_() -> Bool {
        return isalpha(value) != 0 || self == "_"
    }
    
    func isNumOr_() -> Bool {
        return isdigit(value) != 0 || self == "_" || self == "."
    }
    func isHexNumOr_() -> Bool {
        return ishexnumber(value) != 0 || self == "_"
    }
    func isBinNumOr_() -> Bool {
        return self == "0" || self == "1" || self == "_"
    }
    

    func isSymbol() -> Bool {
        return (isblank(value) != 1) && isOperatorCodeUnit() || stdlibOperators.reduce("", +).characters.contains(self)
    }
    
    func isWhiteSpace() -> Bool {
        return isspace(value) != 0
    }
    
    func isNewLine() -> Bool {
        return self == "\n" || self == "\r"
    }
    
    func isSingleCharSymbol() -> Bool {
        return (isblank(value) != 1) && [":"].contains(self)
    }
}
extension Character {
    func isAlNumOr_() -> Bool {
        return isalnum(value) != 0 || self == "_"
    }
}

private enum LexerContext {
    case alpha, numeric, newLine, symbol, comment(Bool), stringLiteral
}

private func == (lhs: Character, rhs: String) -> Bool { return lhs == Character(rhs) }
private func != (lhs: Character, rhs: String) -> Bool { return !(lhs == rhs) }

private extension String {
    
    init(escaping: String) {
        
        var chars: [Character] = []
        let count = escaping.characters.count
        chars.reserveCapacity(count)
        
        // '\' character
        let escapeChar = Character("\\")
        
        var escape = false
        
        for (i, c) in escaping.characters.enumerated() {
            
            if escape {
                defer { escape = false }
                switch c {
                case "\\": chars.append("\\")
                case "n": chars.append("\n")
                case "t": chars.append("\t")
                case "r": chars.append("\r")
                default: break
                }
            }
            else if c == escapeChar {
                escape = true
            }
            else {
                chars.append(c)
            }
        }
        
        self = String(chars)
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Token
//-------------------------------------------------------------------------------------------------------------------------

private extension Token {
    
    static func fromIdentifier(_ alpha: String) -> Token {
        // Text tokens which are language keywords
        switch alpha {
        case "let": return .let
        case "var": return .var
        case "func": return .func
        case "return": return .return
        case "if": return .if
        case "else": return .else
        case "Void": return .void
        case "true": return .booleanLiteral(true)
        case "false": return .booleanLiteral(false)
        case "for": return .for
        case "in": return .in
        case "do": return .do
        case "while": return .while
        case "type": return .type
        case "concept": return .concept
        case "init": return .init
        case "deinit": return .deinit
        case "ref": return .ref
        case "yield": return .yield
        case "the": return .the
        case "as": return .as
        case "self": return .self
        default: return .identifier(alpha)
        }
    }
    
    static func fromNumberLiteral(_ numeric: String) -> Token {
        
        guard !numeric.hasPrefix("0x") else {
            var int: UInt64 = 0
            Scanner(string: numeric).scanHexInt64(&int)
            return .integerLiteral(Int(int))
        }
//        guard !numeric.hasPrefix("0b") else {
//            var int: UInt64 = 0
//            NSScanner(string: numeric).scan
//            return .integerLiteral(Int(int))
//        }
        
        //number literal
        let numberFormatter = NumberFormatter()
        numberFormatter.numberStyle = .decimal
        guard let number = numberFormatter.number(from: numeric.replacingOccurrences(of: "_", with: "")) else {
            return .identifier(numeric)
        }
        
        if numeric.characters.contains(".") {
            return .floatingPointLiteral(Double(number))
        }
        else {
            return .integerLiteral(Int(number))
        }
    }
    
    static func fromSymbol(_ symbol: String) -> Token {
        return operators[symbol] ?? .infixOperator(symbol)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Lexer state
//-------------------------------------------------------------------------------------------------------------------------

extension String {
    
    func getTokens() throws -> [(Token, SourceLoc)] {
        var lexer = Lexer(code: self)
        return try lexer.getTokens()
    }
}

/// Lexer object which manages token generation
private struct Lexer {
    
    let code: String
    let chars: [Character]
    
    init(code: String) {
        self.code = code
        self.chars =  (code+" ").characters.map(identity)
    }
    
    private var contextStart = 0
    fileprivate var index = 0
    
    fileprivate var charsInContext: [Character] = []
    
    fileprivate var tokens: [(Token, SourceLoc)] = []
    fileprivate var context: LexerContext? = nil {
        didSet {
            if let _ = context { contextStartPos = pos }
        }
    }
    
    private var contextStartPos: Pos = (0,0)
    fileprivate var pos: Pos = (0,0)
    
    var currentChar: Character {
        return chars[index]
    }
    
    func charPtr(_ n: Int) -> Character? {
        if index + n > 0, index + n < chars.count { return chars[index+n] }
        return nil
    }
    
    private mutating func updatePos() throws {
        if let a = charPtr(-1), a == "\n" {
            pos = (pos.0+1, 0)
        }
        else {
            pos = (pos.0, pos.1+1)
        }
    }
    
    fileprivate mutating func resetContext() throws {
        try addContext()
        
        context = nil
        charsInContext = []
    }
    
    fileprivate mutating func consumeChar(_ n: Int = 1) throws {
        index += n
        try updatePos()
        guard index < chars.count else { throw LexerError.outOfRange }
    }
    
    fileprivate mutating func addChar() {
        charsInContext.append(currentChar)
    }
    
    
    fileprivate mutating func addContext() throws {

        let str = String(charsInContext)
        let tok = try formToken(str)
        
        let loc = SourceLoc(range: SourceRange(start: contextStartPos, end: pos), string: str)
        tokens.append((tok, loc))
    }
    
    fileprivate mutating func formToken(_ str: String) throws -> Token {
        switch context {
        case .alpha?:           return Token.fromIdentifier(str)
        case .numeric?:         return Token.fromNumberLiteral(str)
        case .symbol?:          return Token.fromSymbol(str)
        case .stringLiteral?:   return .stringLiteral(String(escaping: str))
        case .comment?:         return .comment(str)
        case .newLine?:         return .newLine
        default:                throw LexerError.noToken
        }
    }
    
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Lex while functions
//-------------------------------------------------------------------------------------------------------------------------


private extension Lexer {
    mutating func lexString() throws {
        try lexWhilePredicate { $0.isAlNumOr_() }
        try resetContext()
    }
    
    mutating func lexWhiteSpace() throws {
        try lexWhilePredicate { $0.isWhiteSpace() }
        if charsInContext.contains(where: ({ $0.isNewLine()})) {
            try resetContext()
        } else {
            context = nil
            charsInContext = []
        }
    }
    
    mutating func lexNumber() throws {
        addChar()
        let initial = currentChar
        try consumeChar()
        if case "x" = currentChar, case "0" = initial {
            addChar()
            try consumeChar()
            try lexWhilePredicate {
                $0.isHexNumOr_()
            }
        }
        else {
            var hadPeriod = false
            try lexWhilePredicate { c in
                if case "." = c {
                    // if we've seen a '.' already, this is not a decimal point
                    guard !hadPeriod else { return false }
                    // if the next char isn't a number this isnt a decimal point
                    guard charPtr(1)?.isNum() ?? false else { return false }
                    // if its a decimal point, mark we cant see another
                    hadPeriod = true
                }
                return c.isNumOr_()
            }
        }
        try resetContext()
        
        // TODO: lookahead for . in number -- if not a number then return
    }
    
    mutating func lexInteger() throws {
        try lexWhilePredicate { $0.isNum() }
        try resetContext()
    }
    
    mutating func lexOperatorDecl() throws {
        try lexWhilePredicate { $0.isSymbol() && $0 != ":" }
        try resetContext()
    }
    
    mutating func lexSymbol() throws {
        
        let start = index
        
        try lexWhilePredicate { $0.isSymbol() && $0 != "$" }

        if operators.keys.contains(String(charsInContext)) || stdlibOperators.contains(String(charsInContext)) {
            try resetContext()
            return // is an Expr, return it lexed
        }
        
        index = start
        charsInContext = []
        
        try lexWhilePredicate {
            if operators.keys.contains(String(self.charsInContext)) || stdlibOperators.contains(String(self.charsInContext)) { return false }
            else { return $0.isSymbol() }
        }
        try resetContext()
    }
    
    // TODO: Implement funciton versions for comments and string literals
//    mutating private func lexComment() throws {
//        try lexWhilePredicate({$0.isSymbol()})
//    }
//
//    mutating private func lexStringLiteral() throws {
//        try lexWhilePredicate({$0 != "\""})
//    }
//    
    mutating private func lexWhilePredicate(p: (Character) throws -> Bool) throws {
        while try p(currentChar) {
            addChar()
            guard let _ = try? consumeChar() else { return }
        }
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Main lexing loop
//-------------------------------------------------------------------------------------------------------------------------


// todo: lexing multiple operators next to eachother
// instead of current (whitelist based) method, contunue
// lexing for all but the chars used exclusively by the language


extension Lexer {
    
    /// Returns tokenised code, with positions for error reporting
    ///
    /// [Detailed here](http://llvm.org/docs/tutorial/LangImpl1.html#language)
    mutating func getTokens() throws -> [(Token, SourceLoc)] {
        
        while index<chars.count {
            
            switch (context, currentChar) {
                
            case (.comment(let multiLine)?, let n): // comment end
                
                if (multiLine && (n == "/" && charPtr(-1) == "*")) || (!multiLine && (n == "\n" || n == "\r")) {
                    try resetContext()
                    try consumeChar()
                    if !multiLine { tokens.append((.newLine, SourceLoc(range: SourceRange.at(pos: pos), string: "\n"))) } // if not multi line, add a new line token after it
                    continue
                }
                addChar()
                try consumeChar()
                continue
                
            case (_, "$"):
                context = .alpha
                addChar()
                try consumeChar()
                try lexNumber()
                continue
                
            case (_, "/") where charPtr(+1) == "/": // new comment
                context = .comment(false)
                try consumeChar(2)
                continue
                
            case (_, "/") where charPtr(+1) == "*": // new multi line comment
                context = .comment(true)
                try consumeChar(2)
                continue
                
            case (.stringLiteral?, "\"") where charPtr(-1) != "\\": // comment end
                try resetContext()
                try consumeChar()
                continue
                
            case (_, "\""): // string literal start
                context = .stringLiteral
                try consumeChar()
                continue

            case (.stringLiteral?, _):
                addChar()
                try consumeChar()
                continue
                
            case (.alpha?, " "), (.numeric?, "\t"):
                try resetContext()
                try consumeChar()
                continue
                
            case (_, let a) where a.isAlphaOr_():
                context = .alpha
                try lexString()
                continue
                
            case (_, let a) where a.isNum():
                context = .numeric
                try lexNumber()
                continue
                
            case (_, let s) where s.isSingleCharSymbol():
                context = .symbol
                addChar()
                try consumeChar()
                try resetContext()
                continue
                
            case (_, let s) where s.isSymbol():
                context = .symbol
                try lexSymbol()
                continue
                
            case (_, let s) where s.isWhiteSpace():
                context = .newLine
                try lexWhiteSpace()
                continue
                
            case _:
                break
            }
            
            addChar()
            if index<chars.count-1 { try consumeChar() } else { break }
        }
        
        do { // wtf is this
            try resetContext()
        } catch { }
        
        return tokens + [(Token.EOF, SourceLoc.zero())]
    }
    

}



