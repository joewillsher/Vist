//
//  ConceptType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct ConceptType : StorageType {
    let name: String
    let requiredFunctions: [StructMethod], requiredProperties: [StructMember]
    let heapAllocated = false
}

extension ConceptType {
    
    func lowerType(module: Module) -> LLVMTypeRef {
        return StructType.withTypes([
            BuiltinType.array(el: BuiltinType.int(size: 32), size: UInt32(requiredProperties.count)), // prop offset list
            BuiltinType.array(el: BuiltinType.opaquePointer, size: UInt32(requiredFunctions.count)), // method witness list
            BuiltinType.opaquePointer // wrapped object
            ]).lowerType(module)
    }
    
    var irName: String {
        return "\(name).ex"
    }
    
    var mangledName: String {
        return name
    }
    
    var members: [StructMember] {
        return requiredProperties
    }
    
    var methods: [StructMethod] {
        return requiredFunctions
    }
    
    func usingTypesIn(module: Module) -> Ty {
        let fns = requiredFunctions.map { (name: $0.name, type: $0.type.usingTypesIn(module) as! FnType)  as StructMethod }
        let mems = requiredProperties.map { ($0.name, $0.type.usingTypesIn(module), $0.mutable) as StructMember }
        let c = ConceptType(name: name, requiredFunctions: fns, requiredProperties: mems)
        return module.getOrInsert(TypeAlias(name: name, targetType: c))
    }

}


