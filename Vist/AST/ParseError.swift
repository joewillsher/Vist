//
//  ParseError.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum ParseError: ErrorType {
    case ExpectedParen,  ExpectedCloseBracket, NoToken(Token), ExpectedComma
    case ExpectedOpenBrace, NotBlock
    case InvalidCall(String) // cant call (*2) or (.print())
    case NoIdentifier
    case ExpectedColon, ExpectedDoubleColon
    case ExpectedAssignment
    case NoOperator(String)
    case ExpectedIn
    case InvalidIfStatement
    case ObjectNotAllowedInTopLevelOfTypeImpl(Token), NoTypeName
    case NoPrecedenceForOperator, AttrDoesNotHaveParams, CannotChangeOpPrecedence(String, Int)
}
extension ParseError : CustomStringConvertible {
    
    var description: String {
        
        switch self {
        case let .NoToken(tok): return "Expected token '\(tok)'"
        case .ExpectedParen: return "Expected paren"
        case .ExpectedCloseBracket: return "Expected ']'"
        case .ExpectedComma: return "Expected ','"
        case .ExpectedColon: return "Expected ':'"
        case .ExpectedDoubleColon: return "Expected '::'"
        case let .InvalidCall(call): return "Invalid call to \(call)"
        case .NoIdentifier: return "Expected identifier"
        case let .NoOperator(op): return "No operator '\(op)'"
        case .ExpectedIn: return "Expected 'in'"
        case .NotBlock: return "Expected block expression"
        case .ExpectedOpenBrace: return "Expected '{'"
        case .InvalidIfStatement: return "If statement is invalid. Only 1 unconditional 'else' expressions is permitted in the final position"
        case let .ObjectNotAllowedInTopLevelOfTypeImpl(tok): return "'\(tok)': object not allowed at top level of type implementation"
        case .NoTypeName: return "Expected name for type"
        case .NoPrecedenceForOperator: return "Operator requires a definition of precedence in parens, like '@operator(30)'"
        case .AttrDoesNotHaveParams: return "Attribute expected param in parentheses"
        case let .CannotChangeOpPrecedence(op, prec): return "Operator '\(op)' has precedence \(prec), which can't be changed"
        case .ExpectedAssignment: return "Expected assignment expression"
        }
        
    }
}