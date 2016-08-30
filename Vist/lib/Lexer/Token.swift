//
//  Token.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

typealias Pos = (Int, Int)

struct SourceRange {
    let start: Pos
    let end: Pos
    
    static func at(pos: Pos) -> SourceRange { return SourceRange(start: pos, end: pos) }
}

extension SourceRange: CustomStringConvertible {
    
    var description: String {
        if start == end {
            return "(l:\(start.0), c:\(start.1))"
        } else {
            return "from:(l:\(start.0), c:\(start.1)) to:(l:\(end.0), c:\(end.1))"
        }
    }
}

struct SourceLoc {
    let range: SourceRange
    let string: String
    
    static func zero() -> SourceLoc {
        return SourceLoc(range: SourceRange(start: (0,0), end: (0,0)), string: "")
    }
}

enum Token {
    case `let`, `var`, `func`, `return`, void
    case EOF
    case `if`, `else`, `for`, `in`, `while`, `do`, yield, the, `as`
    case ref, type, `init`, `operator`, `concept`
    case assign, sqbrOpen, sqbrClose, comma, period, colon, semicolon, openParen, closeParen, returnArrow, bar, openBrace, closeBrace
    case infixOperator(String), prefixOperator(String), postfixOperator(String)
    case identifier(String), floatingPointLiteral(Double), integerLiteral(Int), booleanLiteral(Bool), nilLiteral
    case comment(String), stringLiteral(String)
    case at
    case newLine
    
    var isValidParamToken: Bool {
        switch self {
        case .identifier, .sqbrOpen, .openParen, .openBrace, .floatingPointLiteral, .integerLiteral, .booleanLiteral, .stringLiteral, .do: return true
        default: return false
        }
    }
    var isCloseParen: Bool {
        if case .closeParen = self { return true } else { return false }
    }
}

extension Token : Equatable {
    static func == (lhs: Token, rhs: Token) -> Bool {
        switch (lhs, rhs) {
        case (.let, .let): return true
        case (.var, .var): return true
        case (.func, .func): return true
        case (.return, .return): return true
        case (.void, .void): return true
        case (.EOF, .EOF): return true
        case (.newLine, .newLine): return true
        case (.if, .if): return true
        case (.else, .else): return true
        case (.for, .for): return true
        case (.in, .in): return true
        case (.while, .while): return true
        case (.do, .do): return true
        case (.yield, .yield): return true
        case (.the, .the): return true
        case (.as, .as): return true
        case (.ref, .ref): return true
        case (.type, .type): return true
        case (.init, .init): return true
        case (.operator, .operator): return true
        case (.concept, .concept): return true
        case (.assign, .assign): return true
        case (.sqbrOpen, .sqbrOpen): return true
        case (.sqbrClose, .sqbrClose): return true
        case (.comma, .comma): return true
        case (.period, .period): return true
        case (.colon, .colon): return true
        case (.semicolon, .semicolon): return true
        case (.openParen, .openParen): return true
        case (.closeParen, .closeParen): return true
        case (.returnArrow, .returnArrow): return true
        case (.bar, .bar): return true
        case (.at, .at): return true
        case (.openBrace, .openBrace): return true
        case (.closeBrace, .closeBrace): return true
        case (.infixOperator(let l), .infixOperator(let r)): return l == r
        case (.prefixOperator(let l), .prefixOperator(let r)): return l == r
        case (.postfixOperator(let l), .postfixOperator(let r)): return l == r
        case (.identifier(let l), .identifier(let r)): return l == r
        case (.floatingPointLiteral(let l), .floatingPointLiteral(let r)): return l == r
        case (.integerLiteral(let l), .integerLiteral(let r)): return l == r
        case (.booleanLiteral(let l), .booleanLiteral(let r)): return l == r
        case (.stringLiteral(let l), .stringLiteral(let r)): return l == r
        case (.comment(let l), .comment(let r)): return l == r
        case (.nilLiteral, .nilLiteral): return true
        default: return false
        }
    }
}

let operators: [String: Token] = [
    "=": .assign,
    "[": .sqbrOpen,
    "]": .sqbrClose,
    ",": .comma,
    ".": .period,
    ":": .colon,
    ";": .semicolon,
    "(": .openParen,
    ")": .closeParen,
    "->": .returnArrow,
    "|": .bar,
    "}": .closeBrace,
    "{": .openBrace,
    "@": .at
]

let stdlibOperators: [String] = ["<", ">", "<=", ">=", "/", "+", "-", "*", "%", "&&", "||", "...", "..<", "==", "!=", "<<", ">>", "~|", "~^", "~&"]
