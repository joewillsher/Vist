//
//  IRError.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRError: VistError {
    case wrongFunctionApplication(String)
    case noVariable(String), noFunction(String), noType(String), typeNotFound
    case notMutable(String), notMutableProp(name: String, inType: String)
    case cannotAssignToVoid, cannotAssignToType(Expr.Type), cannotMutateParam
    case subscriptingNonVariableTypeNotAllowed
    case noProperty(type: String, property: String), noTupleMemberAt(Int)
    
    case cannotLookupPropertyFromNonVariable, notIRGenerator(ASTNode.Type), noParentType
    case cannotLookupPropertyFromThis(prop: String), cannotLookupElementFromNonTuple
    
    case notTyped, notStructType
    case invalidModule(LLVMModuleRef, String?), invalidFunction(String)
    
    case unreachable
    
    var description: String {
        switch self {
        case .wrongFunctionApplication(let fn): return "Incorrect application of function '\(fn)'"
            
        case .noVariable(let v): return "No variable '\(v)' found in this scope"
        case .noFunction(let f): return "No function '\(f)' found in this scope"
        case .noType(let t): return "No type '\(t)' found in this scope"
        case .typeNotFound: return "Type was not found"
            
        case .notMutable(let name): return "Cannot mutate variable '\(name)'"
        case .notMutableProp(let name, let type): return "Cannot mutate property '\(name)' in '\(type)'"

        case .cannotAssignToType(let t): return "Cannot assign to expression of type '\(t)'"
        case .cannotAssignToVoid: return "Cannot assign to void expression"
        case .cannotMutateParam: return "Cannot mutate immutable function parameter"
            
        case .subscriptingNonVariableTypeNotAllowed: return "Only subscripting a variable is permitted"

        case let .noProperty(type, prop): return "Type '\(type)' does not contain member '\(prop)'"
        case let .noTupleMemberAt(i): return "Tuple does not have member at index \(i)"

        case .cannotLookupPropertyFromThis(let p): return "Cannot lookup property \(p)"
        case .cannotLookupElementFromNonTuple: return "Can only look up member by index from tuple"
            
        case .cannotLookupPropertyFromNonVariable: return "Only property lookup from a variable object is permitted"
        case .notIRGenerator(let t): return "'\(t)' is not an IR generator"
        case .noParentType: return "Parent type is not a struct or does not exist"
        case .notTyped: return "Expression is not typed"
        case .notStructType: return "Expression was not a struct type"
            
        case .invalidModule(_, let desc): return "Invalid module generated:\n\t~\(desc?.stringByReplacingOccurrencesOfString("\n", withString: "\n\t~") ?? "")"
        case .invalidFunction(let f): return "Invalid function IR for '\(f)'"
            
        case .unreachable: return "Code flow should not reach here"
        }
    }
}

