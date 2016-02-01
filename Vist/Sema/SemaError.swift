//
//  SemaError.swift
//  Vist
//
//  Created by Josef Willsher on 22/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

enum SemaError : ErrorType, CustomStringConvertible {
    case InvalidType(BuiltinType)
    case InvalidRedeclaration(String, Expr)
    case NoVariable(String)
    case HeterogenousArray([Ty]), EmptyArray
    case CannotSubscriptNonArrayVariable, NonIntegerSubscript
    case NonBooleanCondition, NotRangeType, DifferentTypeForMutation(String, Ty, Ty)
    
    case NoFunction(String, [Ty])
    case WrongFunctionReturnType(applied: Ty, expected: Ty)
    case WrongFunctionApplications(name: String, applied: [Ty], expected: [Ty])
    case NoTypeNamed(String)
    case NoPropertyNamed(type: String, property: String), CannotStoreInParameterStruct(propertyName: String), NotStructType(Ty)
    
    
    
    case NoStdBoolType, NoStdIntType, NotTypeProvider, NoTypeFor(Expr)
    case StructPropertyNotTyped, StructMethodNotTyped, InitialiserNotAssociatedWithType
    case TypeNotFound
    
    var description: String {
        switch self {
        case let .InvalidType(t):
            return "Invalid type '\(t)'"
        case let .InvalidRedeclaration(t, _):
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
            
        case let .WrongFunctionReturnType(applied, expected):
            return "Invalid return from function. \(applied) is not convertible to \(expected)"
        case let .NoFunction(f, ts):
            return "Could not find function '\(f)' which accepts parameters of type \(ts.asTupleDescription())"
        case let .WrongFunctionApplications(name, applied, expected):
            return "Incorrect application of function '\(name)'. \(applied.asTupleDescription()) is not convertible to \(expected.asTupleDescription())"
        case let .NoTypeNamed(name):
            return "No type '\(name)' found"
        case let .NoPropertyNamed(type, property):
            return "Type '\(type)' does not have member '\(property)'"
        case let .CannotStoreInParameterStruct(pName):
            return "'\(pName)' is a member of an immutable type, passed as a parameter to a function"
        case let .NotStructType(t):
            return "'\(t)' is not a struct type"
            
        default: print(self); return ""
        }
    }
}


func semaError(err: SemaError, userVisible: Bool = true, file: StaticString = __FILE__, line: UInt = __LINE__) -> SemaError {
    
    #if DEBUG
        print("Vist error in ‘\(file)’, line \(line)")
        return err
    #else
        if userVisible {
            return err
        }
        else {
            fatalError("Compiler assertion failed \(err)", file: file, line: line)
        }
    #endif
    
}




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




