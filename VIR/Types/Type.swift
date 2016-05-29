//
//  Type.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

private var emptyModule = LLVMModuleCreateWithName("___null___")

protocol Type : VIRElement {
    
    /// Name used in mangling function signatures
    var mangledName: String { get }
    
    func lowerType(module: Module) -> LLVMType
    /// Replaces the function's memeber types with the module's typealias
    func usingTypesIn(module: Module) -> Type
    
    /// The explicit name of this type. The same as the
    /// mangled name, unless the mangled name uses a different
    /// naming system, like the builtin types
    var explicitName: String { get }
    
    var heapAllocated: Bool { get }
}

enum _WidthUnit { case bytes, bits }

extension Type {
    // implement default behaviour
    var explicitName: String {
        return mangledName
    }
    
    var heapAllocated: Bool { return false }
    
    /// the size in `unit` of this lowered type
    func size(unit unit: _WidthUnit = .bytes, module: Module) -> Int {
        let dataLayout = LLVMCreateTargetData(LLVMGetDataLayout(emptyModule))
        let s = Int(LLVMSizeOfTypeInBits(dataLayout, lowerType(module).type))
        switch unit {
        case .bits: return s
        case .bytes: return s / 8
        }
    }
    
    func getAsStructType() throws -> StructType {
        if case let s as TypeAlias = self { return try s.targetType.getAsStructType() }
        else if case let s as StructType = self { return s }
        else { fatalError("throw error -- not struct type") }
    }
    func getAsTupleType() throws -> TupleType {
        if case let s as TypeAlias = self { return try s.targetType.getAsTupleType() }
        else if case let s as TupleType = self { return s }
        else { fatalError("throw error -- not tuple type") }
    }
    func getConcreteNominalType() -> NominalType? {
        if case let s as TypeAlias = self { return s.targetType.getConcreteNominalType() }
        else if case let s as StructType = self { return s }
        else if case let c as ConceptType = self { return c }
        else { return nil }
    }
}


// MARK: Cannonical equality functions, compares their module-agnostic type info

@warn_unused_result
func == (lhs: Type?, rhs: Type) -> Bool {
    if let l = lhs { return l == rhs } else { return false }
}
@warn_unused_result
func == (lhs: Type?, rhs: Type?) -> Bool {
    if let l = lhs, let r = rhs { return l == r } else { return false }
}
@warn_unused_result
func != (lhs: Type?, rhs: Type) -> Bool {
    if let l = lhs { return l != rhs } else { return false }
}

@warn_unused_result
func == (lhs: Type, rhs: Type) -> Bool {
    switch (lhs, rhs) {
    case (let l as NominalType, let r as ConceptType):
        return l.models(r)
    case (let l as ConceptType, let r as NominalType):
        return r.models(l)
    case (let l as NominalType, let r as GenericType):
        return l.validSubstitutionFor(r)
    case (let l as GenericType, let r as NominalType):
        return r.validSubstitutionFor(l)
        
    case let (l as FunctionType, r as FunctionType):
        return r == l
    case (let lhs as NominalType, let rhs as NominalType):
        return lhs.name == rhs.name
    case let (l as BuiltinType, r as BuiltinType):
        return l == r
    case let (l as TupleType, r as TupleType):
        return l == r
    case let (l as TypeAlias, r as TypeAlias):
        return l == r
    default:
        return false
    }
}

@warn_unused_result
func != (lhs: Type, rhs: Type) -> Bool {
    return !(lhs == rhs)
}

