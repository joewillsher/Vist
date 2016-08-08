//
//  Type.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

private var emptyModule = LLVMModuleCreateWithName("___null___")

protocol Type : VIRElement, ASTPrintable {
    
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
    
    /// Add a type constraint to `self`
    func addConstraint(_: Type, solver: ConstraintSolver) throws
    /// Can this type satisfy the given constraint
    func canAddConstraint(_: Type, solver: ConstraintSolver) -> Bool
    
    var isAddressOnly: Bool { get }
}

extension Type {
    // implement default behaviour
    var explicitName: String {
        return mangledName
    }
    
    var isAddressOnly: Bool { return false }
    var isHeapAllocated: Bool { return false }
    
    func isInModule() -> Bool {
        return false
    }
    
    func getAsStructType() throws -> StructType {
        if case let s as TypeAlias = self { return try s.targetType.getAsStructType() }
        else if case let s as StructType = self { return s }
        else { throw VIRError.notStructType(self) }
    }
    func getAsTupleType() throws -> TupleType {
        if case let s as TypeAlias = self { return try s.targetType.getAsTupleType() }
        else if case let s as TupleType = self { return s }
        else { throw VIRError.notTupleType(self) }
    }
    func getAsConceptType() throws -> ConceptType {
        if case let s as TypeAlias = self { return try s.targetType.getAsConceptType() }
        else if case let s as ConceptType = self { return s }
        else { throw VIRError.notConceptType(self) }
    }
    func getConcreteNominalType() -> NominalType? {
        if case let s as TypeAlias = self { return s.targetType.getConcreteNominalType() }
        else if case let s as StructType = self { return s }
        else if case let c as ConceptType = self { return c }
        else { return nil }
    }
}


// MARK: Cannonical equality functions, compares their module-agnostic type info


extension ConstraintSolver {
    /// Can `subst` satisfy `constraint`
    func typeSatisfies(_ subst: Type?, constraint type: Type?) -> Bool {
        switch (subst, type) {
        case (let l as NominalType, let r as ConceptType):
            return l.models(concept: r)
        case (let l as NominalType, let r as GenericType):
            return l.validSubstitutionFor(generic: r)
        case (let variable as TypeVariable, let type):
            if let solved = try? solveConstraints(variable: variable) {
                return typeSatisfies(solved, constraint: type)
            }
            return false
        default:
            return subst == type
        }
    }
}

func == (lhs: Type?, rhs: Type?) -> Bool {
    switch (lhs, rhs) {
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
    case (nil, nil):
        return true
    default:
        return false
    }
}

func != (lhs: Type?, rhs: Type?) -> Bool {
    return !(lhs == rhs)
}
