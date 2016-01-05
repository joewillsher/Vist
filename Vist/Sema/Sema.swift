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
    case WrongApplication, NotTypeProvider, NoTypeFor(Expression)
    case HeterogenousArray(String), EmptyArray
    case NotVariableType, CannotSubscriptNonArrayVariable, NonIntegerSubscript
    case NonBooleanCondition, RangeWithInconsistentTypes, DifferentTypeForMutation
    case StructPropertyNotTyped, StructMethodNotTyped, InitialiserNotAssociatedWithType
    case WrongFunctionReturnType(applied: LLVMTyped, expected: LLVMTyped)
    case WrongFunctionApplication(applied: LLVMTyped, expected: LLVMTyped, paramNum: Int), WrongFunctionApplications(applied: [LLVMTyped], expected: [LLVMTyped])
    case NoTypeNamed(String), TypeNotFound
    case DifferentTypesForOperator(String)
    case NoPropertyNamed(String)
}

func sema(inout ast: AST) throws {
    
    // add helper functions to ast tables
    let globalScope = SemaScope(parent: nil, returnType: nil)
    
    let fns = [
        try LLVMFnType.fn("print", typeSignature: "LLVM.Int"),
        try LLVMFnType.fn("print", typeSignature: "LLVM.Int32"),
        try LLVMFnType.fn("print", typeSignature: "LLVM.Double"),
        try LLVMFnType.fn("print", typeSignature: "LLVM.Float"),
        try LLVMFnType.fn("print", typeSignature: "[LLVM.Int8]")
    ]
    
    for (name, fn) in fns {
        globalScope[function: name] = fn
    }
    
    try variableTypeSema(forScopeExpression: &ast, scope: globalScope)
    
}


