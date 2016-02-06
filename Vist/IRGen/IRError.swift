//
//  IRError.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRError : VistError {
    case WrongFunctionApplication(String)
    case NoVariable(String), NoFunction(String), NoType(String), TypeNotFound
    case NotMutable(String), NotMutableProp(name: String, inType: String)
    case CannotAssignToVoid, CannotAssignToType(Expr.Type), CannotMutateParam
    case SubscriptingNonVariableTypeNotAllowed
    case NoProperty(type: String, property: String), NoTupleMemberAt(Int)
    
    case CannotLookupPropertyFromNonVariable, NotGenerator(ASTNode.Type), NoParentType
    
    case NotTyped, NotStructType
    case InvalidModule(LLVMModuleRef, String?), InvalidFunction(String)
    
    case Unreachable
    
    var description: String {
        switch self {
        case let .WrongFunctionApplication(fn): return "Incorrect application of function '\(fn)'"
            
        case let .NoVariable(v): return "No variable '\(v)' found in this scope"
        case let .NoFunction(f): return "No function '\(f)' found in this scope"
        case let .NoType(t): return "No type '\(t)' found in this scope"
        case .TypeNotFound: return "Type was not found"
            
        case let .NotMutable(name): return "Cannot mutate variable '\(name)'"
        case let .NotMutableProp(name, type): return "Cannot mutate property '\(name)' in '\(type)'"

        case let .CannotAssignToType(t): return "Cannot assign to expression of type '\(t)'"
        case .CannotAssignToVoid: return "Cannot assign to void expression"
        case .CannotMutateParam: return "Cannot mutate immutable function parameter"
            
        case .SubscriptingNonVariableTypeNotAllowed: return "Only subscripting a variable is permitted"

        case let .NoProperty(type, prop): return "Type '\(type)' does not contain member '\(prop)'"
        case let .NoTupleMemberAt(i): return "Tuple does not have member at index \(i)"

        case .CannotLookupPropertyFromNonVariable: return "Only property lookup from a variable object is permitted"
        case let .NotGenerator(t): return "'\(t)' is not an IR generator"
        case .NoParentType: return "Parent type is not a struct or does not exist"
        case .NotTyped: return "Expression is not typed"
        case .NotStructType: return "Expression was not a struct type"
            
        case let .InvalidModule(_, desc): return "Invalid module generated:\n\t~\(desc?.stringByReplacingOccurrencesOfString("\n", withString: "\n\t~") ?? "")"
        case let .InvalidFunction(f): return "Invalid function IR for '\(f)'"
            
        case .Unreachable: return "Code flow should not reach here"
        }
    }
}

