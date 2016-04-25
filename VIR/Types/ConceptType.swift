//
//  ConceptType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class ConceptType : NominalType {
    let name: String
    let requiredFunctions: [StructMethod], requiredProperties: [StructMember]
    let heapAllocated = false
    
    init(name: String, requiredFunctions: [StructMethod], requiredProperties: [StructMember]) {
        self.name = name
        self.requiredFunctions = requiredFunctions
        self.requiredProperties = requiredProperties
    }
}

extension ConceptType {
    
    func lowerType(module: Module) -> LLVMType {
        return StructType.withTypes([
            BuiltinType.array(el: BuiltinType.int(size: 32), size: requiredProperties.count), // prop offset list
            BuiltinType.array(el: BuiltinType.opaquePointer, size: requiredFunctions.count), // method witness list
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
    
    func usingTypesIn(module: Module) -> Type {
        let fns = requiredFunctions.map { fn in
            (name: fn.name, type: fn.type.usingTypesIn(module) as! FunctionType, mutating: fn.mutating) as StructMethod
        }
        let mems = requiredProperties.map { memb in
            (memb.name, memb.type.usingTypesIn(module), memb.isMutable) as StructMember
        }
        let c = ConceptType(name: name, requiredFunctions: fns, requiredProperties: mems)
        return module.getOrInsert(TypeAlias(name: name, targetType: c))
    }

}


