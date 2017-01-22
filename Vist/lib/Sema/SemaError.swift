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
    case immutableVariable(name: String, type: String), immutableCapture(name: String), immutableProperty(p: String, ty: Type), immutableObject(type: Type), immutableTupleMember(index: Int)
    case cannotAssignToNullExpression(String)
    case noTupleElement(index: Int, size: Int)
    
    case noFunction(String, [Type]), wrongFuncParamList(applied: [String], forType: [Type])
    case wrongFunctionReturnType(applied: Type, expected: Type)
    case wrongFunctionApplications(name: String, applied: [Type], expected: [Type])
    case noTypeNamed(String)
    case noPropertyNamed(type: String, property: String), noMethodNamed(type: String, property: String), cannotStoreInParameterStruct(propertyName: String), notStructType(Type?), notTupleType(Type?)
    case noModel(type: StructType, concept: ConceptType)
    
    case functionNotMethod, mutatingMethodOnImmutable(method: String, baseType: String), closureNotFunctionType, noMangledName(unmangled: String)
    case conceptBody(concept: NominalType, function: FuncDecl)
    
    case selfNonTypeContext
    case unsatisfiableConstraints(constraints: [TypeConstraint]), noConstraints
    case couldNotAddConstraint(constraint: Type, to: Type)
    
    // not user visible
    case noStdBoolType, noStdIntType, notTypeProvider, noTypeForStruct, noTypeForTuple, noTypeForFunction(name: String), notFunctionType(TypeRepr)
    case structPropertyNotTyped(type: String, property: String), structMethodNotTyped(type: String, methodName: String)
    case initialiserNotAssociatedWithType, deinitialiserNotAssociatedWithType, noDeinitBody
    case typeNotFound, paramsNotTyped, integerNotTyped, boolNotTyped
    case noMemberwiseInit
    
    case cannotCoerce(from: Type, to: Type), dynamicCastFail(label: String, from: Type, to: Type)
    
    case invalidYield, invalidReturn, notGenerator(Type?)
    case cannotInferClosureParamListSize
    
    case genericSubstitutionInvalid, notValidLookup, unreachable(String), todo(String)
    case deinitNonRefType(Type)
    
    var description: String {
        switch self {
        case .invalidType(let t):
            return "Invalid type '\(t.prettyName)'"
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
        case .differentTypeForMutation(let name, let from, let to):
            return (name.map { "Cannot change type of '\($0)'" } ?? "Could not change type") + " from '\(from.prettyName)' to '\(to.prettyName)'"
        case .immutableVariable(let name, let type):
            return "Variable '\(name)' of type '\(type)' is immutable"
        case .immutableCapture(let name):
            return "Cannot mutate 'self' in non mutating method. Make method '@mutable' to modify '\(name)'"
        case .immutableProperty(let p, let ty):
            return "Variable of type '\(ty.prettyName)' does not have mutable property '\(p)'"
        case .immutableObject(let ty):
            return "Object of type '\(ty.prettyName)' is immutable"
        case .immutableTupleMember(let i):
            return "Tuple member at index \(i) is immutable"
        case .cannotAssignToNullExpression(let name):
            return "Variable '\(name)' cannot be assigned to null typed expression"
        case .noTupleElement(let i, let s):
            return "Could not extract element at index \(i) from tuple with \(s) elements"
            
        case .wrongFunctionReturnType(let applied, let expected):
            return "Invalid return from function. '\(applied.prettyName)' is not convertible to '\(expected.prettyName)'"
        case .noFunction(let f, let ts):
            return "Could not find function '\(f)' which accepts parameters of type '\(ts.asTupleDescription())'"
        case .wrongFuncParamList(let applied, let forType):
            return "Could not bind parameter list (\(applied.joined(separator: " "))) to param types '\(forType.asTupleDescription())'"
        case .wrongFunctionApplications(let name, let applied, let expected):
            return "Incorrect application of function '\(name)'. '\(applied.asTupleDescription())' is not convertible to '\(expected.asTupleDescription())'"
        case .noTypeNamed(let name):
            return "No type '\(name)' found"
        case .noPropertyNamed(let type, let property):
            return "Type '\(type)' does not have member '\(property)'"
        case .noMethodNamed(let type, let property):
            return "Type '\(type)' does not have method '\(property)'"
        case .cannotStoreInParameterStruct(let pName):
            return "'\(pName)' is a member of an immutable type passed as a parameter to a function"
        case .notStructType(let t):
            return "'\(t?.prettyName ?? "_")' is not a struct type"
        case .notTupleType(let t):
            return "'\(t?.prettyName ?? "_")' is not a tuple type"
        case .invalidYield:
            return "Can only yield from a generator function"
        case .invalidReturn:
            return "Cannot return from a generator function"
        case .notGenerator(let ty):
            return "\(ty.map { "'\($0.prettyName)' is not a generator type. "  })You can only loop over generator types"
        case .noTypeForFunction(let name):
            return "Function '\(name)' was not typed"
        case .noModel(let type, let concept):
            return "Type '\(type.name)' does not conform to concept '\(concept.name)'"
        case .notFunctionType(let repr):
            return "Function must have function type; '\(repr._astName_instance ?? "")' is not valid"
        case .conceptBody(let type, let decl):
            return "Concept method requirement '\(decl.name)' in '\(type.name)' cannot have a body"
        case .deinitNonRefType(let type):
            return "Cannot add a 'deinit' to a non 'ref type' '\(type.prettyName)'"
        case .noDeinitBody:
            return "'deinit' must have a body"
        case .selfNonTypeContext:
            return "'self' expression is only valid in a type context"
            
        case .cannotInferClosureParamListSize:
            return "Cannot infer the size of a closure parameter list; either specify the type or provide an explicit parameter list"
        case .closureNotFunctionType:
            return "Closure must have a function type"
            
        case .mutatingMethodOnImmutable(let method, let baseType):
            return "Cannot call mutating method '\(method)' on immutable object of type '\(baseType)'"
        case .noMangledName(let name):
            return "No mangled name for '\(name)'"
        case .cannotCoerce(let from, let to):
            return "Could not coerce expression of type '\(from.prettyName)' to '\(to.prettyName)'"
        case .dynamicCastFail(let name, let from, let to):
            return "Dynamic cast of '\(name)' from '\(from.prettyName)' to '\(to.prettyName)' will always fail"
            
        // not user visible
        case .functionNotMethod: return "No method found"
        case .noStdBoolType: return "Stdlib did not provide a Bool type"
        case .noStdIntType: return "Stdlib did not provide an Int type"
        case .notTypeProvider: return "ASTNode does not conform to `TypeProvider` and does not provide an implementation of `typeForNode(_:)"
        case .noTypeForStruct, .noTypeForTuple: return "Lookup's parent does not have a type"
        case .structPropertyNotTyped(let type, let property): return "Property '\(property)' in '\(type)' was not typed"
        case .structMethodNotTyped(let type, let method): return "Method '\(method)' in '\(type)' was not typed"
        case .initialiserNotAssociatedWithType: return "Initialiser's parent type was unexpectedly nil"
        case .deinitialiserNotAssociatedWithType: return "Deinitialiser's parent type was unexpectedly nil"
        case .typeNotFound: return "Type not found"
        case .paramsNotTyped: return "Params not typed"
        case .integerNotTyped: return "Integer literal not typed"
        case .boolNotTyped: return "Bool literal not typed"
        case .noMemberwiseInit: return "Could not construct memberwise initialiser"
            
        case .genericSubstitutionInvalid: return "Generic substitution invalid"
        case .notValidLookup: return "Lookup expression was not valid"
        case .unreachable(let message): return "Unreachable: \(message)"
        case .todo(let message): return "Todo: \(message)"
            
        case .unsatisfiableConstraints(let constraints):
            let names = constraints.map {$0.name}
            return "Could not satisfy type constraitns: \(names.joined(separator: " "))"
        case .noConstraints:
            return "Could not satisfy empty type constraints"
        case .couldNotAddConstraint(let constraint, let type):
            return "Could not constrain type '\(type.prettyName)' to '\(constraint.prettyName)'"
        }
    }
}


// used for array's error messages
private extension Collection where Iterator.Element == Type {
    
    /// Returns info about the collection
    func heterogeneous() -> (type: Type?, except: Type?) {
        guard let first = self.first else { return (nil, nil) }
        
        guard let u = index(where: { $0 != first }) else { return (nil, nil) }
        
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
        return "(" + map {$0.prettyName}.joined(separator: " ") + ")"
    }
    
}




