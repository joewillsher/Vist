//
//  IRError.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRError : ErrorType, CustomStringConvertible {
    case NoOperator
    case MisMatchedTypes, WrongFunctionApplication(String), NoLLVMType
    case NoBody, InvalidFunction, NoVariable(String), NoType(String), NoFunction(String), NoBool, TypeNotFound, NotMutable(String)
    case CannotAssignToVoid, CannotAssignToType(Expr.Type)
    case SubscriptingNonVariableTypeNotAllowed, SubscriptOutOfBounds
    case NoProperty(String), NotAStruct, CannotMutateParam
    
    var description: String {
        
        switch self {
        default:
            return self._domain
        }
        
    }
}

