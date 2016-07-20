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
    
    func lowered(module: Module) -> LLVMType
    /// Replaces the function's memeber types with the module's typealias
    func importedType(in module: Module) -> Type
    
    /// The explicit name of this type. The same as the
    /// mangled name, unless the mangled name uses a different
    /// naming system, like the builtin types
    var explicitName: String { get }
    
    /// The name to show to users
    var prettyName: String { get }
    
    var isHeapAllocated: Bool { get }
    
    /// Whether this type is representible in a module
    /// - whether it is a structrual type or module defined type alias
    func isInModule() -> Bool
}


extension Type {
    // implement default behaviour
    var explicitName: String {
        return mangledName
    }
    
    var isHeapAllocated: Bool { return false }
    
    func isInModule() -> Bool {
        return false
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
    func getAsConceptType() throws -> ConceptType {
        if case let s as TypeAlias = self { return try s.targetType.getAsConceptType() }
        else if case let s as ConceptType = self { return s }
        else { fatalError("throw error -- not concept type") }
    }
    func getConcreteNominalType() -> NominalType? {
        if case let s as TypeAlias = self { return s.targetType.getConcreteNominalType() }
        else if case let s as StructType = self { return s }
        else if case let c as ConceptType = self { return c }
        else { return nil }
    }
}


// MARK: Cannonical equality functions, compares their module-agnostic type info

func == (lhs: Type?, rhs: Type) -> Bool {
    if let l = lhs { return l == rhs } else { return false }
}

func == (lhs: Type?, rhs: Type?) -> Bool {
    if let l = lhs, let r = rhs { return l == r } else { return false }
}

func != (lhs: Type?, rhs: Type) -> Bool {
    if let l = lhs { return l != rhs } else { return false }
}

func == (lhs: Type, rhs: Type) -> Bool {
    switch (lhs, rhs) {
    case (let l as NominalType, let r as ConceptType):
        return l.models(concept: r)
    case (let l as ConceptType, let r as NominalType):
        return r.models(concept: l)
    case (let l as NominalType, let r as GenericType):
        return l.validSubstitutionFor(generic: r)
    case (let l as GenericType, let r as NominalType):
        return r.validSubstitutionFor(generic: l)
        
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

func != (lhs: Type, rhs: Type) -> Bool {
    return !(lhs == rhs)
}

