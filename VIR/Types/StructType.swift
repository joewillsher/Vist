//
//  StructType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class StructType : NominalType {
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
    
    func lowerType(module: Module) -> LLVMType {
        var arr = members.map { $0.type.lowerType(module).type }
        return LLVMType(ref: LLVMStructType(&arr, UInt32(members.count), false))
    }
    func refCountedBox(module: Module) -> TypeAlias {
        let t = StructType(members: [("object", BuiltinType.pointer(to: self), true), ("refCount", BuiltinType.int(size: 32), false)],
                           methods: [], name: "\(name).refcounted", heapAllocated: true)
        return module.getOrInsert(t)
    }
    
    func usingTypesIn(module: Module) -> Type {
        let mappedEls = members.map { member in
            (member.name, member.type.usingTypesIn(module), member.isMutable) as StructMember
        }
        var newTy = StructType(members: mappedEls, methods: methods, name: name, heapAllocated: heapAllocated)
        newTy.genericTypes = genericTypes
        newTy.concepts = concepts
        return module.getOrInsert(TypeAlias(name: name, targetType: newTy))
    }
    
    
    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    
    static func withTypes(tys: [Type], name: String = "") -> StructType {
        return StructType(members: tys.map { (name: name, type: $0, mutable: true) }, methods: [], name: name)
    }
    
    var irName: String {
        return "\(name)"
    }
    
    var mangledName: String {
        switch name {
        case "Int": return "I"
        case "Int32": return "I32"
        case "Bool": return "B"
        case "Double": return "D"
        case "Range": return "R"
        default: return name
        }
    }
    var explicitName: String { return name }
}


extension StructType : Equatable { }


@warn_unused_result
func == (lhs: StructType, rhs: StructType) -> Bool {
    return lhs.name == rhs.name
}


