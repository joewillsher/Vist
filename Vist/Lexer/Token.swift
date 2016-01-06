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
}

struct SourceLoc {
    let range: SourceRange
    let string: String
    
    static func zero() -> SourceLoc {
        return SourceLoc(range: SourceRange(start: (0,0), end: (0,0)), string: "")
    }
}

enum Token {
    case Let, Var, Func, Return, Void
    case EOF
    case If, Else, For, In, While, Do
    case Type, Reference, Init
    case Assign, SqbrOpen, SqbrClose, Comma, Period, Colon, Semicolon, OpenParen, CloseParen, Returns, Bar, OpenBrace, CloseBrace
    case InfixOperator(String), PrefixOperator(String), PostfixOperator(String)
    case Identifier(String), FloatingPoint(Double), Integer(Int), Boolean(Bool)
    case Char(Character), Str(String), Comment(String), StringLiteral(String)
    case At
}

let operators: [String: Token] = [
    "=": .Assign,
    "[": .SqbrOpen,
    "]": .SqbrClose,
    ",": .Comma,
    ".": .Period,
    ":": .Colon,
    ";": .Semicolon,
    "(": .OpenParen,
    ")": .CloseParen,
    "->": .Returns,
    "|": .Bar,
    "}": .CloseBrace,
    "{": .OpenBrace,
    "@": .At
]

let stdlibOperators: [String] = ["<", ">", "<=", ">=", "/", "+", "-", "*", "%", "&&", "||", "...", "==", "!="]
