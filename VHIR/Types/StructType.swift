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
    let heapAllocated: Bool
        
    init(members: [StructMember], methods: [StructMethod], name: String, heapAllocated: Bool = false) {
        self.name = name
        self.members = members
        self.methods = methods
        self.heapAllocated = heapAllocated
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
    func refCountedBox(module: Module) -> TypeAlias {
        let t = StructType(members: [("object", BuiltinType.pointer(to: self), true), ("refCount", BuiltinType.int(size: 32), false)],
                           methods: [], name: "\(name).refcounted", heapAllocated: true)
        return module.getOrInsert(t)
    }
    
    func usingTypesIn(module: Module) -> Ty {
        let mappedEls = members.map {
            ($0.name, $0.type.usingTypesIn(module), $0.mutable) as StructMember
        }
        var newTy = StructType(members: mappedEls, methods: methods, name: name, heapAllocated: heapAllocated)
        newTy.genericTypes = genericTypes
        newTy.concepts = concepts
        return module.getOrInsert(TypeAlias(name: name, targetType: newTy))
    }
    
    
    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    
    static func withTypes(tys: [Ty], name: String = "") -> StructType {
        return StructType(members: tys.map { (name: name, type: $0, mutable: true) }, methods: [], name: name)
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


