//
//  ParseError.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum ParseError: VistError {
    case ExpectedParen,  ExpectedCloseBracket, NoToken(Token), ExpectedComma
    case ExpectedOpenBrace, NotBlock
    case InvalidCall(String) // cant call (*2) or (.print())
    case NoIdentifier
    case ExpectedColon, ExpectedDoubleColon, ExpectedBar
    case ExpectedAssignment
    case NoOperator(String)
    case ExpectedIn
    case InvalidIfStatement
    case ObjectNotAllowedInTopLevelOfTypeImpl(Token), NoTypeName
    case NoPrecedenceForOperator, AttrDoesNotHaveParams, CannotChangeOpPrecedence(String, Int)
    case StdLibExprInvalid
    
    case NoGenericParamName(on: String), NoGenericConstraints(parent: String, genericParam: String), ExpectedGenericConstraint
    
    var description: String {
        switch self {
        case let .NoToken(tok): return "Expected token '\(tok)'"
        case .ExpectedParen: return "Expected paren"
        case .ExpectedCloseBracket: return "Expected ']'"
        case .ExpectedComma: return "Expected deliniating ','"
        case .ExpectedColon: return "Expected ':' to declare storage type"
        case .ExpectedBar: return "Expected '|' to constrain generic parameter"
        case .ExpectedDoubleColon: return "Expected '::' to define function signature"
        case let .InvalidCall(call): return "Invalid call to \(call)"
        case .NoIdentifier: return "Expected identifier"
        case let .NoOperator(op): return "No operator '\(op)'"
        case .ExpectedIn: return "Expected 'in'"
        case .NotBlock: return "Expected block expression"
        case .ExpectedOpenBrace: return "Expected '{'"
        case .InvalidIfStatement: return "If statement is invalid; a single unconditional 'else' expressions is only permitted in the final position"
        case let .ObjectNotAllowedInTopLevelOfTypeImpl(tok): return "'\(tok)': object not allowed at top level of type implementation"
        case .NoTypeName: return "Expected name for type"
        case .NoPrecedenceForOperator: return "Operator requires a definition of precedence in parens, like '@operator(30)'"
        case .AttrDoesNotHaveParams: return "Attribute expected param in parentheses"
        case let .CannotChangeOpPrecedence(op, prec): return "Operator '\(op)' has precedence \(prec), which can't be changed"
        case .ExpectedAssignment: return "Expected assignment expression"
        case .StdLibExprInvalid: return "Stdlib expression involving 'LLVM.' could not be parsed"
        case let .NoGenericParamName(on): return "Generic parameter on '\(on)' must specify name"
        case let .NoGenericConstraints(parent, genericParam): return "'\(parent)'s generic parameter '\(genericParam)' supplies no constraints after '|'"
        case .ExpectedGenericConstraint: return "Expected generic parameter constraint"
        }
    }
}