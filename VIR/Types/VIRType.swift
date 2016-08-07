//
//  VIRType.swift
//  Vist
//
//  Created by Josef Willsher on 02/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct VIRType<T : Type> {
    let type: T
    
    func isAddressOnly() -> Bool { return false }
    
    init(lowering type: T, solver: ConstraintSolver) {
        self.type = type
    }
    
    init(lowering type: Type, solver: ConstraintSolver) {
        self.init(lowering: AnyType(type: type), solver: solver)
    }
}

struct AnyType : Type {
    private let type: Type
    
    fileprivate init(type: Type) {
        self.type = type
    }
    
    /// Name used in mangling function signatures
    var mangledName: String { return type.mangledName }
    
    func lowered(module: Module) -> LLVMType { return type.lowered(module: module) }
    /// Replaces the function's memeber types with the module's typealias
    func importedType(in module: Module) -> Type { return type.importedType(in: module) }
    
    /// The explicit name of this type. The same as the
    /// mangled name, unless the mangled name uses a different
    /// naming system, like the builtin types
    var explicitName: String { return type.explicitName }
    
    /// The name to show to users
    var prettyName: String { return type.prettyName }
    
    var isHeapAllocated: Bool { return type.isHeapAllocated }
    
    /// Whether this type is representible in a module
    /// - whether it is a structrual type or module defined type alias
    func isInModule() -> Bool { return type.isInModule() }
    
    /// Add a type constraint to `self`
    func addConstraint(_ constraint: Type, solver: ConstraintSolver) throws {
        return try type.addConstraint(constraint, solver: solver)
    }
    
    var vir: String { return type.vir }
}

