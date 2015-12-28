//
//  Lexer.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Helpers
//-------------------------------------------------------------------------------------------------------------------------

enum LexerError: ErrorType {
    case OutOfRange
    case NoToken
}

private func identity<T>(a:T)->T { return a }


private extension Character {
    
    func value() -> Int32 {
        let s = String(self).unicodeScalars
        return Int32(s[s.startIndex].value)
    }
    
    func isAlNumOr_() -> Bool {
        return isalnum(value()) != 0 || self == "_"
    }

    func isNum() -> Bool {
        return isdigit(value()) != 0
    }

    func isAlphaOr_() -> Bool {
        return isalpha(value()) != 0 || self == "_"
    }
    
    func isNumOr_() -> Bool {
        return isdigit(value()) != 0 || self == "_" || self == "."
    }
    
    func isSymbol() -> Bool {
        return (isblank(value()) != 1) && operators.keys.reduce("", combine: +).characters.contains(self) || stdlibOperators.reduce("", combine: +).characters.contains(self)
    }
}

private enum Context {
    case Alpha, Numeric, NewLine, Symbol, WhiteSpace, Comment(Bool), StringLiteral
}

private func == (lhs: Character, rhs: String) -> Bool { return lhs == Character(rhs) }
private func != (lhs: Character, rhs: String) -> Bool { return !(lhs == rhs) }


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Token
//-------------------------------------------------------------------------------------------------------------------------

private extension Token {

    init(alpha: String) {
        // Text tokens which are language keywords
        switch alpha {
        case "let": self = .Let
        case "var": self = .Var
        case "func": self = .Func
        case "return": self = .Return
        case "if": self = .If
        case "else": self = .Else
        case "Void": self = .Void
        case "true": self = .Boolean(true)
        case "false": self = .Boolean(false)
        case "for": self = .For
        case "in": self = .In
        case "do": self = .Do
        case "while": self = .While
        case "type": self = .Type
        default: self = .Identifier(alpha)
        }
    }
    
    init(numeric: String) {
        //number literal
        let numberFormatter = NSNumberFormatter()
            numberFormatter.numberStyle = NSNumberFormatterStyle.DecimalStyle
        guard let number = numberFormatter.numberFromString(numeric.stringByReplacingOccurrencesOfString("_", withString: "")) else {
            self = .Identifier(numeric)
            return
        }
        
        if numeric.characters.contains(".") {
            self = .FloatingPoint(Double(number))
        } else {
            self = .Integer(Int(number))
        }
    }
    
    init(symbol: String) {
        self = (operators[symbol] ?? .InfixOperator(symbol)) ?? .InfixOperator(symbol)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Lexer state
//-------------------------------------------------------------------------------------------------------------------------


/// Lexer object which manages token generation
struct Lexer {
    
    let code: String
    let chars: [Character]
    
    init(code: String) {
        self.code = code
        self.chars =  (code+" ").characters.map(identity)
    }
    
    mutating func reset() {
        self = Lexer(code: code)
    }
    
    private var contextStart = 0
    private var index = 0
    
    private var charsInContext: [Character] = []
    
    private var tokens: [(Token, SourceLoc)] = []
    private var context: Context? = nil {
        didSet {
            if let _ = context { contextStartPos = pos }
        }
    }
    
    private var contextStartPos: Pos = (0,0)
    private var pos: Pos = (0,0)
    
    var currentChar: Character {
        return chars[index]
    }
    
    func charPtr(n: Int) throws -> Character {
        if index + n > 0 && index + n < chars.count { return chars[index+n] }
        else { throw LexerError.OutOfRange }
    }
    func charPtrSafe(n: Int) -> Character {
        return (try? charPtr(n)) ?? Character(" ")
    }

    
    func getSubstring(start: Int, length: Int) -> String? {
        if index + start + length > 0 && index + start + length < chars.count { return String(chars[index + start + length]) }
        else { return nil }
    }
    
    private mutating func updatePos() throws {
        if let a = (try? charPtr(-1)) where a == "\n" {
            pos = (pos.0+1, 0)
        } else {
            pos = (pos.0, pos.1+1)
        }
    }
    
    private mutating func resetContext() throws {
        try addContext()
        
        context = nil
        charsInContext = []
    }
    
    private mutating func consumeChar(n: Int = 1) throws {
        if index == chars.count { throw LexerError.OutOfRange }
        index += n
        try updatePos()
    }
    
    private mutating func addChar() {
        charsInContext.append(currentChar)
    }
    
    
    private mutating func addContext() throws {

        let str = String(charsInContext)
        let tok = try formToken(str)
        
        let loc = SourceLoc(range: SourceRange(start: contextStartPos, end: pos), string: str)
        tokens.append((tok, loc))
    }
    
    private mutating func formToken(str: String) throws -> Token {
        switch context {
        case .Alpha?:           return Token(alpha: str)
        case .Numeric?:         return Token(numeric: str)
        case .Symbol?:          return Token(symbol: str)
        case .StringLiteral?:   return .StringLiteral(str)
        case .Comment?:         return .Comment(str)
        default:                throw LexerError.NoToken
        }
    }
    
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Lex while functions
//-------------------------------------------------------------------------------------------------------------------------


extension Lexer {
    mutating private func lexString() throws {
        try lexWhilePredicate { $0.isAlNumOr_() }
        try resetContext()
    }
    
    mutating private func lexNumber() throws {
        try lexWhilePredicate {
            
            $0.isNumOr_()
        
        }
        try resetContext()
        
        // TODO: lookahead for . in number -- if not a number then return
    }
    
    mutating private func lexInteger() throws {
        try lexWhilePredicate { $0.isNum() }
        try resetContext()
    }
    
    mutating private func lexSymbol() throws {
        
        let start = index
        
        try lexWhilePredicate { return $0.isSymbol() }

        if operators.keys.contains(String(charsInContext)) || stdlibOperators.contains(String(charsInContext)) {
            try resetContext()
            return // is an expression, return it lexed
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
//        try lexWhilePredicate({$0.isSymbol()})
//    }
    
    mutating private func lexWhilePredicate(p: (Character) throws -> Bool) throws {
        while try p(currentChar) {
            addChar()
            if index<chars.count { try consumeChar() } else { break }
        }
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Main lexing loop
//-------------------------------------------------------------------------------------------------------------------------


extension Lexer {
    
    /// Returns tokenised code, with positions for error reporting
    ///
    /// [Detailed here](http://llvm.org/docs/tutorial/LangImpl1.html#language)
    mutating func getTokens() throws -> [(Token, SourceLoc)] {
        
        while index<chars.count {
            
            switch (context, currentChar) {
                
                
            case (.Comment(let multiLine)?, let n): // comment end
                
                if (multiLine && (n == "/" && charPtrSafe(-1) == "*")) || (!multiLine && (n == "\n" || n == "\r")) {
                    
                    try resetContext()
                }
                try consumeChar()
                continue
                
            case (_, "$"):
                context = .Alpha
                addChar()
                try consumeChar()
                try lexNumber()
                continue

            case (_, "/") where charPtrSafe(+1) == "/": // new comment
                context = .Comment(false)
                try consumeChar(2)
                continue
                
            case (_, "/") where charPtrSafe(+1) == "*": // new multi line comment
                context = .Comment(true)
                try consumeChar(2)
                continue
                
            case (_, "\""): // string literal start
                context = .StringLiteral
                try consumeChar()
                continue
                
            case (.StringLiteral?, "\"") where charPtrSafe(-1) != "\\": // comment end
                try resetContext()
                try consumeChar()
                continue
                
            case (.Alpha?, " "), (.Numeric?, "\t"):
                try resetContext()
                try consumeChar()
                continue
                
            case (_, let a) where a.isAlphaOr_():
                context = .Alpha
                try lexString()
                continue
                
            case (_, let a) where a.isNum():
                context = .Numeric
                try lexNumber()
                continue
                
            case (_, let s) where s.isSymbol():
                context = .Symbol
                try lexSymbol()
                continue
                
            case (_, let s) where isspace(s.value()) != 0:
                try consumeChar()
                continue
                
            case _:
                break
            }
            
            addChar()
            if index<chars.count-1 { try consumeChar() } else { break }
        }
        
        do {
            try resetContext()
        } catch { }
        
        return tokens + [(Token.EOF, SourceLoc.zero())]
    }
    

}



