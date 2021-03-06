//
//  ConceptType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class ConceptType : NominalType {
    let name: String
    var requiredFunctions: [StructMethod], requiredProperties: [StructMember]
    var concepts: [ConceptType] = []
    let isHeapAllocated = false
    
    init(name: String, requiredFunctions: [StructMethod], requiredProperties: [StructMember]) {
        self.name = name
        self.requiredFunctions = requiredFunctions
        self.requiredProperties = requiredProperties
    }
}

extension ConceptType {
    
    func lowered(module: Module) -> LLVMType {
        return Runtime.existentialObjectType.importedCanType(in: module)
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
    
    func importedType(in module: Module) -> Type {
        let fns = requiredFunctions.map { fn in
            (name: fn.name, type: fn.type.importedType(in: module) as! FunctionType, mutating: fn.mutating) as StructMethod
        }
        let mems = requiredProperties.map { memb in
            (memb.name, memb.type.importedType(in: module), memb.isMutable) as StructMember
        }
        let c = ConceptType(name: name, requiredFunctions: fns, requiredProperties: mems)
        return module.getOrInsert(type: ModuleType(name: name, targetType: c))
    }

    func machineType() -> AIRType {
        return Runtime.existentialObjectType.machineType()
    }
}

extension ConceptType : Hashable {
    var hashValue: Int {
        return name.hashValue
    }
    static func == (l: ConceptType, r: ConceptType) -> Bool {
        return l.name == r.name
    }
}
