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
    case `if`, `else`, `for`, `in`, `while`, `do`, yield
    case ref, type, `init`, `operator`, `concept`
    case assign, sqbrOpen, sqbrClose, comma, period, colon, semicolon, openParen, closeParen, returnArrow, bar, openBrace, closeBrace
    case infixOperator(String), prefixOperator(String), postfixOperator(String)
    case identifier(String), floatingPointLiteral(Double), integerLiteral(Int), booleanLiteral(Bool), nilLiteral
    case comment(String), stringLiteral(String)
    case at
    case newLine
    
    var isValidParamToken: Bool {
        switch self {
        case .identifier, .sqbrOpen, .openParen, openBrace, floatingPointLiteral, integerLiteral, booleanLiteral, stringLiteral: return true
        default: return false
        }
    }
    var isCloseParen: Bool {
        if case .closeParen = self { return true } else { return false }
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
