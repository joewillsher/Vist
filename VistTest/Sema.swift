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


enum SemaError : ErrorType {
    case InvalidType(LLVMType)
    case InvalidRedeclaration(String, Expression)
    case NoVariable(String), NoFunction(String)
    case WrongApplication, NotTypeProvider
    case HeterogenousArray(String), EmptyArray
    case NotVariableType, CannotSubscriptNonArrayVariable, NonIntegerSubscript
    case NonBooleanCondition, RangeWithInconsistentTypes, DifferentTypeForMutation
    case StructPropertyNotTyped, StructMethodNotTyped
    case WrongFunctionReturnType(applied: LLVMTyped, expected: LLVMTyped), WrongFunctionApplication(applied: LLVMTyped, expected: LLVMTyped, paramNum: Int)
    case NoTypeNamed(String), TypeNotFound
    case DifferentTypesForOperator(String)
}

func sema(inout ast: AST) throws {
    
    // add helper functions to ast tables
    let globalScope = SemaScope(parent: nil, returnType: nil)
    let pt = LLVMFnType(params: [LLVMType.Int(size: 64)], returns: LLVMType.Void)
    globalScope[function: "print"] = pt
    let ptd = LLVMFnType(params: [LLVMType.Float(size: 64)], returns: LLVMType.Void)
    globalScope[function: "printd"] = ptd
    
    ast.expressions = ast.expressions.filter { !($0 is CommentExpression) }
    
    try variableTypeSema(forScopeExpression: &ast, scope: globalScope)
    
}


