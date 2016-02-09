//
//  SemaError.swift
//  Vist
//
//  Created by Josef Willsher on 22/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

enum SemaError : VistError {
    case InvalidType(BuiltinType), InvalidFloatType(UInt32)
    case InvalidRedeclaration(String)
    case NoVariable(String)
    case HeterogenousArray([Ty]), EmptyArray
    case CannotSubscriptNonArrayVariable, NonIntegerSubscript
    case NonBooleanCondition, NotRangeType, DifferentTypeForMutation(String, Ty, Ty), ImmutableVariable(String), ImmutableProperty(p: String, obj: String, ty: String)
    case CannotAssignToNullExpression(String)
    case NoTupleElement(index: Int, size: Int)
    
    case NoFunction(String, [Ty])
    case WrongFunctionReturnType(applied: Ty, expected: Ty)
    case WrongFunctionApplications(name: String, applied: [Ty], expected: [Ty])
    case NoTypeNamed(String)
    case NoPropertyNamed(type: String, property: String), CannotStoreInParameterStruct(propertyName: String), NotStructType(Ty)
    
    // not user visible
    case NoStdBoolType, NoStdIntType, NotTypeProvider, NoTypeForStruct, NoTypeForTuple
    case StructPropertyNotTyped(type: String, property: String), StructMethodNotTyped(type: String, methodName: String), InitialiserNotAssociatedWithType
    case TypeNotFound, ParamsNotTyped, IntegerNotTyped, BoolNotTyped
    case NoMemberwiseInit
    
    case GenericSubstitutionInvalid
    
    var description: String {
        switch self {
        case let .InvalidType(t):
            return "Invalid type '\(t)'"
        case let .InvalidFloatType(s):
            return "Invalid float of size \(s)"
        case let .InvalidRedeclaration(t):
            return "Variable '\(t)' is already declared"
        case let .NoVariable(v):
            return "Could not find variable '\(v)' in this scope"
        case let .HeterogenousArray(arr):
            let (type, except) = arr.heterogeneous()
            return "Invalid heterogeneous array of '\(type)' contains '\(except)')"
        case .EmptyArray:
            return "Empty array -- could not infer type"
        case .CannotSubscriptNonArrayVariable:
            return "You can only subscript an array variable"
        case .NonIntegerSubscript:
            return "Subscript is not an integer"
        case .NonBooleanCondition:
            return "Condition is not a boolean expression"
        case .NotRangeType:
            return "Expression is not of type 'Range'"
        case let .DifferentTypeForMutation(name, from, to):
            return "Cannot change type of '\(name)' from '\(from)' to '\(to)'"
        case let .ImmutableVariable(name):
            return "Variable '\(name)' is immutable"
        case let .ImmutableProperty(p, obj, ty):
            return "Variable '\(obj)' (of type '\(ty)') does not have mutable property '\(p)'"
        case let .CannotAssignToNullExpression(name):
            return "Variable '\(name)' cannot be assigned to null typed expression"
        case let .NoTupleElement(i, s):
            return "Tuple of size \(s). Cannot access its element at index \(i)"
            
        case let .WrongFunctionReturnType(applied, expected):
            return "Invalid return from function. '\(applied)' is not convertible to '\(expected)'"
        case let .NoFunction(f, ts):
            return "Could not find function '\(f)' which accepts parameters of type '\(ts.asTupleDescription())'"
        case let .WrongFunctionApplications(name, applied, expected):
            return "Incorrect application of function '\(name)'. '\(applied.asTupleDescription())' is not convertible to '\(expected.asTupleDescription())'"
        case let .NoTypeNamed(name):
            return "No type '\(name)' found"
        case let .NoPropertyNamed(type, property):
            return "Type '\(type)' does not have member '\(property)'"
        case let .CannotStoreInParameterStruct(pName):
            return "'\(pName)' is a member of an immutable type passed as a parameter to a function"
        case let .NotStructType(t):
            return "'\(t)' is not a struct type"
            
            // not user visible
        case .NoStdBoolType: return "Stdlib did not provide a Bool type"
        case .NoStdIntType: return "Stdlib did not provide an Int type"
        case .NotTypeProvider: return "ASTNode does not conform to `TypeProvider` and does not provide an implementation of `llvmType(_:)"
        case .NoTypeForStruct, .NoTypeForTuple: return "Lookup's parent does not have a type"
        case let .StructPropertyNotTyped(type, property): return "Property '\(property)' in '\(type)' was not typed"
        case let .StructMethodNotTyped(type, method): return "Method '\(method)' in '\(type)' was not typed"
        case .InitialiserNotAssociatedWithType: return "Initialiser's parent type was unexpectedly nil"
        case .TypeNotFound: return "Type not found"
        case .ParamsNotTyped: return "Params not typed"
        case .IntegerNotTyped: return "Integer literal not typed"
        case .BoolNotTyped: return "Bool literal not typed"
        case .NoMemberwiseInit: return "Could not construct memberwise initialiser"
            
        case .GenericSubstitutionInvalid: return "Generic substitution invalid"
        }
    }
}


// used for array's error messages
private extension CollectionType where Generator.Element == Ty {
    
    /// Returns info about the collection
    func heterogeneous() -> (type: Ty?, except: Ty?) {
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
        return "(" + map {$0.description}.joinWithSeparator(" ") + ")"
    }
    
}




