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
    let heapAllocated = false
    
    static func fromConstraint(inScope scope: SemaScope) -> (constraint: ConstrainedType) throws -> GenericType {
        return { ty in
            if let c = ty.constraints.optionalMap({ scope[concept: $0] }) {
                return GenericType(name: ty.name, concepts: c, parentName: ty.parentName)
            }
            else {
                throw semaError(.paramsNotTyped)
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
    func lowerType(module: Module) -> LLVMType {
        return StructType.withTypes([
            BuiltinType.array(el: BuiltinType.int(size: 32), size: concepts.flatMap({$0.requiredProperties}).count),
            BuiltinType.opaquePointer
            ]).lowerType(module)
    }
    
    func usingTypesIn(module: Module) -> Type {
        return GenericType(name: name, concepts: concepts.map { $0.usingTypesIn(module) as! ConceptType }, parentName: parentName)
    }
    
    var irName: String {
        return "\(parentName)\(name)"
    }
    
    var mangledName: String {
        return name
    }
}




