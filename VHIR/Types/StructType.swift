//
//  StructType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct StructType : StorageType {
    let name: String
    let members: [StructMember]
    var methods: [StructMethod]
    var genericTypes: [GenericType] = []
    var concepts: [ConceptType] = []
        
    init(members: [StructMember], methods: [StructMethod], name: String) {
        self.name = name
        self.members = members
        self.methods = methods
    }
}

extension StructType {
    
    func lowerType(module: Module) -> LLVMTypeRef {
        let arr = members
            .map { $0.type.lowerType(module) }
            .ptr()
        defer { arr.destroy(members.count) }
        
        return LLVMStructType(arr,
                              UInt32(members.count),
                              false)
    }
    
    func usingTypesIn(module: Module) -> Ty {
        let mappedEls = members.map {
            ($0.name, $0.type.usingTypesIn(module), $0.mutable) as StructMember
        }
        var newTy = StructType(members: mappedEls, methods: methods, name: name)
        newTy.genericTypes = genericTypes
        newTy.concepts = concepts
        return module.getOrInsert(TypeAlias(name: name, targetType: newTy))
    }
    
    
    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    
    static func withTypes(tys: [Ty]) -> StructType {
        return StructType(members: tys.map { (name: "", type: $0, mutable: true) }, methods: [], name: "")
    }
    
    var irName: String {
        return "\(name)"
    }
    
    var mangledName: String {
        return name
    }
}


extension StructType : Equatable { }


@warn_unused_result
func == (lhs: StructType, rhs: StructType) -> Bool {
    return lhs.name == rhs.name
}


