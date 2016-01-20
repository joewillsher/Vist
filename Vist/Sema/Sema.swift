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
    case InvalidType(BuiltinType)
    case InvalidRedeclaration(String, Expr)
    case NoVariable(String), NoFunction(String)
    case WrongApplication, NotTypeProvider, NoTypeFor(Expr)
    case HeterogenousArray(String), EmptyArray
    case NotVariableType, CannotSubscriptNonArrayVariable, NonIntegerSubscript
    case NonBooleanCondition, NotRangeType, DifferentTypeForMutation, NonIntegerRange
    case StructPropertyNotTyped, StructMethodNotTyped, InitialiserNotAssociatedWithType
    case WrongFunctionReturnType(applied: Ty, expected: Ty)
    case WrongFunctionApplication(applied: Ty, expected: Ty, paramNum: Int), WrongFunctionApplications(name: String, applied: [Ty], expected: [Ty])
    case NoTypeNamed(String), TypeNotFound
    case DifferentTypesForOperator(String)
    case NoPropertyNamed(String), CannotStoreInParameterStruct, TupleHasNoObjectAtIndex(Int)
}

func sema(ast: AST, globalScope: SemaScope) throws {
    
    try scopeSemallvmType(forScopeExpression: ast, scope: globalScope)
    
}


