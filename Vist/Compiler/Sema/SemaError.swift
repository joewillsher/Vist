//
//  SemaError.swift
//  Vist
//
//  Created by Josef Willsher on 22/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

enum SemaError: VistError {
    case invalidType(BuiltinType), invalidFloatType(Int)
    case invalidRedeclaration(String), invalidTypeRedeclaration(String)
    case noVariable(String)
    case heterogenousArray([Type]), emptyArray
    case cannotSubscriptNonArrayVariable, nonIntegerSubscript
    case nonBooleanCondition, notRangeType, differentTypeForMutation(name: String?, from: Type, to: Type)
    case immutableVariable(name: String, type: String), immutableProperty(p: String, ty: String), immutableObject(type: String), immutableTupleMember(index: Int)
    case cannotAssignToNullExpression(String)
    case noTupleElement(index: Int, size: Int)
    
    case noFunction(String, [Type]), wrongFuncParamList(applied: [String], forType: [Type])
    case wrongFunctionReturnType(applied: Type, expected: Type)
    case wrongFunctionApplications(name: String, applied: [Type], expected: [Type])
    case noTypeNamed(String)
    case noPropertyNamed(type: String, property: String), cannotStoreInParameterStruct(propertyName: String), notStructType(Type?), notTupleType(Type?)
    
    // not user visible
    case noStdBoolType, noStdIntType, notTypeProvider, noTypeForStruct, noTypeForTuple
    case structPropertyNotTyped(type: String, property: String), structMethodNotTyped(type: String, methodName: String), initialiserNotAssociatedWithType
    case typeNotFound, paramsNotTyped, integerNotTyped, boolNotTyped
    case noMemberwiseInit
    
    case invalidYield, invalidReturn, notGenerator(Type?)
    
    case genericSubstitutionInvalid, notValidLookup, unreachable(String), todo(String)
    
    var description: String {
        switch self {
        case .invalidType(let t):
            return "Invalid type '\(t)'"
        case .invalidFloatType(let s):
            return "Invalid float of size \(s)"
        case .invalidRedeclaration(let t):
            return "Variable '\(t)' is already declared"
        case .invalidTypeRedeclaration(let t):
            return "Type '\(t)' is already defined"
        case .noVariable(let v):
            return "Could not find variable '\(v)' in this scope"
        case .heterogenousArray(let arr):
            let (type, except) = arr.heterogeneous()
            return "Invalid heterogeneous array of '\(type)' contains '\(except)')"
        case .emptyArray:
            return "Empty array -- could not infer type"
        case .cannotSubscriptNonArrayVariable:
            return "You can currently only subscript an array variable"
        case .nonIntegerSubscript:
            return "Subscript is not an integer"
        case .nonBooleanCondition:
            return "Condition is not a boolean expression"
        case .notRangeType:
            return "Expression is not of type 'Range'"
        case let .differentTypeForMutation(name, from, to):
            return (name.map { "Cannot change type of '\($0)'" } ?? "Could not change type") + " from '\(from.explicitName)' to '\(to.explicitName)'"
        case .immutableVariable(let name, let type):
            return "Variable '\(name)' of type '\(type)' is immutable"
        case let .immutableProperty(p, ty):
            return "Variable of type '\(ty)' does not have mutable property '\(p)'"
        case .immutableObject(let ty):
            return "Object of type '\(ty)' is immutable"
        case .immutableTupleMember(let i):
            return "Tuple member at index \(i) is immutable"
        case .cannotAssignToNullExpression(let name):
            return "Variable '\(name)' cannot be assigned to null typed expression"
        case let .noTupleElement(i, s):
            return "Could not extract element at index \(i) from tuple with \(s) elements"
            
        case let .wrongFunctionReturnType(applied, expected):
            return "Invalid return from function. '\(applied)' is not convertible to '\(expected)'"
        case let .noFunction(f, ts):
            return "Could not find function '\(f)' which accepts parameters of type '\(ts.asTupleDescription())'"
        case let .wrongFuncParamList(applied, forType):
            return "Could not bind parameter list '(\(applied.joinWithSeparator(" ")))' to param types '\(forType.asTupleDescription())'"
        case let .wrongFunctionApplications(name, applied, expected):
            return "Incorrect application of function '\(name)'. '\(applied.asTupleDescription())' is not convertible to '\(expected.asTupleDescription())'"
        case .noTypeNamed(let name):
            return "No type '\(name)' found"
        case let .noPropertyNamed(type, property):
            return "Type '\(type)' does not have member '\(property)'"
        case .cannotStoreInParameterStruct(let pName):
            return "'\(pName)' is a member of an immutable type passed as a parameter to a function"
        case .notStructType(let t):
            return "'\(t?.explicitName ?? "")' is not a struct type"
        case .notTupleType(let t):
            return "'\(t?.explicitName ?? "")' is not a tuple type"
        case .invalidYield:
            return "Can only yield from a generator function"
        case .invalidReturn:
            return "Cannot return from a generator function"
        case .notGenerator(let ty):
            return "\(ty.map { "'\($0)' is not a generator type. "  })You can only loop over generator types"
            
            // not user visible
        case .noStdBoolType: return "Stdlib did not provide a Bool type"
        case .noStdIntType: return "Stdlib did not provide an Int type"
        case .notTypeProvider: return "ASTNode does not conform to `TypeProvider` and does not provide an implementation of `typeForNode(_:)"
        case .noTypeForStruct, .noTypeForTuple: return "Lookup's parent does not have a type"
        case let .structPropertyNotTyped(type, property): return "Property '\(property)' in '\(type)' was not typed"
        case let .structMethodNotTyped(type, method): return "Method '\(method)' in '\(type)' was not typed"
        case .initialiserNotAssociatedWithType: return "Initialiser's parent type was unexpectedly nil"
        case .typeNotFound: return "Type not found"
        case .paramsNotTyped: return "Params not typed"
        case .integerNotTyped: return "Integer literal not typed"
        case .boolNotTyped: return "Bool literal not typed"
        case .noMemberwiseInit: return "Could not construct memberwise initialiser"
            
        case .genericSubstitutionInvalid: return "Generic substitution invalid"
        case .notValidLookup: return "Lookup expression was not valid"
        case .unreachable(let message): return "Unreachable: \(message)"
        case .todo(let message): return "Todo: \(message)"
        }
    }
}


// used for array's error messages
private extension CollectionType where Generator.Element == Type {
    
    /// Returns info about the collection
    func heterogeneous() -> (type: Type?, except: Type?) {
        guard let first = self.first else { return (nil, nil) }
        
        guard let u = indexOf({ $0 != first }) else { return (nil, nil) }
        
        let f = filter { $0 == self[u] }
        let o = filter { $0 == first }
        
        if f.count < o.count {
            return (type: o.first, except: f.first)
        }
        else {
            return (type: f.first, except: o.first)
        }
    }
    
    func asTupleDescription() -> String {
        return "(" + map {$0.mangledName}.joinWithSeparator(" ") + ")"
    }
    
}




