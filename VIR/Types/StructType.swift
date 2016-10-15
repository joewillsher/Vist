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
    var genericTypes: [GenericType]?
    var concepts: [ConceptType] = []
    let isHeapAllocated: Bool

    init(members: [StructMember], methods: [StructMethod], name: String, concepts: [ConceptType] = [], isHeapAllocated: Bool = false) {
        self.name = name
        self.members = members
        self.methods = methods
        self.concepts = concepts
        self.isHeapAllocated = isHeapAllocated
    }
}

extension StructType {
    
    func lowered(module: Module) -> LLVMType {
        var arr = members.map {
            $0.type.isAddressOnly ?
                $0.type.lowered(module: module).getPointerType().type :
                $0.type.lowered(module: module).type
        }
        return LLVMType(ref: LLVMStructType(&arr, UInt32(members.count), false))
    }
    
    func importedType(in module: Module) -> Type {
        if isHeapAllocated { return refCountedBox(module: module) }
        // add to the module cache
        return module.getOrInsert(type: TypeAlias(name: name, targetType: importedMemberType(in: module)))
    }
    /// Import the members of the struct type. Used by `StructType.importedType(in:)` 
    /// and `TypeAlias.refCountedBox(module:)` to import the members.
    private func importedMemberType(in module: Module) -> StructType {
        // import members
        let mappedEls = members.map { member in
            (member.name,
             member.type.importedType(in: module).persistentType(module: module),
             member.isMutable) as StructMember
        }
        let newTy = StructType(members: mappedEls, methods: methods, name: name, concepts: concepts, isHeapAllocated: isHeapAllocated)
        newTy.genericTypes = genericTypes
        newTy.concepts = concepts
        return newTy
    }
    func refCountedBox(module: Module) -> TypeAlias {
        return module.getOrInsert(type: ClassType(importedMemberType(in: module)))
    }
    
    static func named(_ n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    
    static func withTypes(_ tys: [Type], name: String = "") -> StructType {
        return StructType(members: tys.map { (name: name, type: $0, mutable: true) }, methods: [], name: name)
    }
        
    var irName: String {
        return name
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
    
    func machineType() -> AIRType {
        return .named(name: name, type: .aggregate(elements: members.map { $0.type.machineType() }))
    }
}



extension StructType : Hashable {
    var hashValue: Int {
        return name.hashValue
    }
    static func == (l: StructType, r: StructType) -> Bool {
        return l.name == r.name
    }
}




