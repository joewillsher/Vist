//
//  ParseError.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum ParseError: VistError {
    case expectedParen, expectedCloseBracket, noToken(Token), expectedComma
    case expectedOpenBrace, notBlock
    case invalidCall(String) // cant call (*2) or (.print())
    case noIdentifier
    case expectedColon, expectedDoubleColon, expectedBar
    case expectedAssignment, conceptCannotProvideVal
    case noOperator(String)
    case expectedIn
    case invalidIfStatement
    case objectNotAllowedInTopLevelOfTypeImpl(Token), noTypeName
    case noPrecedenceForOperator, attrDoesNotHaveParams, cannotChangeOpPrecedence(String, Int)
    case stdLibExprInvalid
    case notVariableDecl
    case expectedExpression
    case condAfterElse
    
    case noGenericParamName(on: String), noGenericConstraints(parent: String, genericParam: String), expectedGenericConstraint
    
    var description: String {
        switch self {
        case let .noToken(tok): return "Expected token '\(tok)'"
        case .expectedParen: return "Expected paren"
        case .expectedCloseBracket: return "Expected ']'"
        case .expectedComma: return "Expected deliniating ','"
        case .expectedColon: return "Expected ':' to declare storage type"
        case .expectedBar: return "Expected '|' to constrain generic parameter"
        case .expectedDoubleColon: return "Expected '::' to define function signature"
        case let .invalidCall(call): return "Invalid call to \(call)"
        case .noIdentifier: return "Expected identifier"
        case let .noOperator(op): return "No operator '\(op)'"
        case .expectedIn: return "Expected 'in'"
        case .notBlock: return "Expected block expression"
        case .expectedOpenBrace: return "Expected '{'"
        case .invalidIfStatement: return "If statement is invalid; a single unconditional 'else' expressions is only permitted in the final position"
        case let .objectNotAllowedInTopLevelOfTypeImpl(tok): return "'\(tok)': object not allowed at top level of type implementation"
        case .noTypeName: return "Expected name for type"
        case .noPrecedenceForOperator: return "Operator requires a definition of precedence in parens, like '@operator(30)'"
        case .attrDoesNotHaveParams: return "Attribute expected param in parentheses"
        case let .cannotChangeOpPrecedence(op, prec): return "Operator '\(op)' has precedence \(prec), which can't be changed"
        case .expectedAssignment: return "Expected assignment expression"
        case .conceptCannotProvideVal: return "Variable declaration in concept cannot provide a value"
        case .stdLibExprInvalid: return "Stdlib expression involving 'LLVM.' could not be parsed"
        case .notVariableDecl: return "Expected variable declaration"
        case let .noGenericParamName(on): return "Generic parameter on '\(on)' must specify name"
        case let .noGenericConstraints(parent, genericParam): return "'\(parent)'s generic parameter '\(genericParam)' supplies no constraints after '|'"
        case .expectedGenericConstraint: return "Expected generic parameter constraint"
        case .expectedExpression: return "Expected expression"
        case .condAfterElse: return "Else statement must be final if/else statement"
        }
    }
}
