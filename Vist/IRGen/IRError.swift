//
//  IRError.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRError : ErrorType {
    case NoOperator
    case MisMatchedTypes, WrongFunctionApplication(String), NoLLVMType
    case NoBody, InvalidFunction, NoVariable(String), NoType(String), NoFunction(String), NoBool, TypeNotFound, NotMutable(String)
    case CannotAssignToVoid, CannotAssignToType(Expr.Type)
    case SubscriptingNonVariableTypeNotAllowed, SubscriptOutOfBounds
    case NoProperty(String), NotAStruct, CannotMutateParam
    
}

extension IRError : CustomStringConvertible {

    var description: String {
        // TODO: update IR errors
        switch self {
        default:
            return self._domain
        }
        
    }
}

