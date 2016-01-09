//
//  Sema.swift
//  Vist
//
//  Created by Josef Willsher on 22/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

// TODO: Semantic analyser

// Should walk the ast and:
// - ✅ ensure type correctness for functions
// - ✅ ensure variables and functions are availiable
// - ✅ generate the interface for a file to allow it to be linked with other files
// - ✅ add metadata about return types, array member types
// - specialise types to generic versions
// - parse fn decls first, see TODOs in SemaTypeCheck.swift line 68

import Foundation

enum SemaError : ErrorType {
    case InvalidType(LLVMType)
    case InvalidRedeclaration(String, Expression)
    case NoVariable(String), NoFunction(String)
    case WrongApplication, NotTypeProvider, NoTypeFor(Expression)
    case HeterogenousArray(String), EmptyArray
    case NotVariableType, CannotSubscriptNonArrayVariable, NonIntegerSubscript
    case NonBooleanCondition, RangeWithInconsistentTypes, DifferentTypeForMutation
    case StructPropertyNotTyped, StructMethodNotTyped, InitialiserNotAssociatedWithType
    case WrongFunctionReturnType(applied: LLVMTyped, expected: LLVMTyped)
    case WrongFunctionApplication(applied: LLVMTyped, expected: LLVMTyped, paramNum: Int), WrongFunctionApplications(applied: [LLVMTyped], expected: [LLVMTyped])
    case NoTypeNamed(String), TypeNotFound
    case DifferentTypesForOperator(String)
    case NoPropertyNamed(String), CannotStoreInParameterStruct
}

func sema(inout ast: AST) throws {
    
    // add helper functions to ast tables
    let globalScope = SemaScope(parent: nil, returnType: nil)
    
    // expose runtime (like print and fatalError) and compiler magic (like add) functions to the vist code
    // see llvmheader.vist
    let code = try String(contentsOfFile: "\(PROJECT_DIR)/Vist/stdlib/llvmheader.vist")
    var l = Lexer(code: code)
    var p = Parser(tokens: try l.getTokens(), isStdLib: true)
    var a = try p.parse()
    try variableTypeSema(forScopeExpression: &a)
    
    let fns = a.expressions
        .flatMap { ($0 as? FunctionPrototypeExpression) }
        .map { ($0.name, $0.fnType.type as? LLVMFnType) }

    let structs = a.expressions
        .flatMap { ($0 as? StructExpression) }
    let tys = structs
        .map { ($0.name, $0.type as? LLVMStType) }
    let methods = structs
        .flatMap {
            $0.methods
                .flatMap { ($0.name, $0.type as? LLVMFnType) }
            +
            $0.initialisers
                .flatMap { ($0.parent?.name ?? "", $0.type as? LLVMFnType)
            }
    }
    
    for (name, t) in fns + methods {
        globalScope[function: name] = t
    }
    
    for (name, t) in tys {
        globalScope[type: name] = t
    }

    try variableTypeSema(forScopeExpression: &ast, scope: globalScope)
    
}


