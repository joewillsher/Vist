//
//  GenericType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct GenericType : StorageType {
    
    let name: String
    /// Concepts this generic type implements
    let concepts: [ConceptType] 
    let parentName: String
    
    static func fromConstraint(inScope scope: SemaScope) -> (constraint: ConstrainedType) throws -> GenericType {
        return { ty in
            if let c = ty.constraints.optionalMap({ scope[concept: $0] }) {
                return GenericType(name: ty.name, concepts: c, parentName: ty.parentName)
            }
            else {
                throw error(SemaError.ParamsNotTyped)
            }
        }
    }
    
    var members: [StructMember] {
        return concepts.flatMap { $0.requiredProperties }
    }
    
    var methods: [StructMethod] {
        return concepts.flatMap { $0.requiredFunctions }
    }
    
    // TODO: Reimplement this
    func memberTypes(module: LLVMModuleRef) -> LLVMTypeRef {
        return StructType.withTypes([
            BuiltinType.Array(el: BuiltinType.Int(size: 32), size: UInt32(concepts.flatMap({$0.requiredProperties}).count)),
            BuiltinType.OpaquePointer
            ]).memberTypes(module)
    }
    
    
    func ir() -> LLVMTypeRef {
        return nil
    }
    
    var irName: String {
        return "\(parentName).\(name).gen"
    }
    
    var mangledName: String {
        return name
    }
}



extension StorageType {
    
    func models(concept: ConceptType) -> Bool {
        for f in concept.requiredFunctions where !methods.contains({ $0.name == f.name && $0.type == f.type }) { return false }
        for p in concept.requiredProperties where !members.contains({ $0.name == p.name && $0.type == p.type }) { return false }
        return true
    }
}



