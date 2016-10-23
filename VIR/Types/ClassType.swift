//
//  ClassType.swift
//  Vist
//
//  Created by Josef Willsher on 10/10/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A reference counted box type
final class ClassType : NominalType {
    let storedType: StructType
    
    var name: String { return storedType.name }
    
    init(_ stored: StructType) {
        self.storedType = stored
    }
    
    func lowered(module: Module) -> LLVMType {
        var els = [storedType.lowered(module: module).getPointerType().type, LLVMType.intType(size: 32).type, LLVMType.opaquePointer.type]
        return LLVMType(ref: LLVMStructType(&els, UInt32(els.count), false))
    }
    
    var members: [StructMember] { return storedType.members }
    var methods: [StructMethod] { return storedType.methods }
    var irName: String { return storedType.irName }
    var isHeapAllocated: Bool { return true }
    var concepts: [ConceptType] {
        get { return storedType.concepts }
        set { storedType.concepts = newValue }
    }
    var explicitName: String { return storedType.explicitName }
    var mangledName: String { return storedType.mangledName }
    func machineType() -> AIRType { return storedType.machineType() }

    func persistentType(module: Module) -> Type {
        return BuiltinType.pointer(to: storedType.refCountedBox(module: module))
    }
    
    func importedType(in module: Module) -> Type {
        return module.getOrInsert(type: ModuleType(name: name, targetType: self))
    }
    
    var isAddressOnly: Bool {
        return true
    }
    func instanceRawType(module: Module) -> LLVMType {
        return storedType.lowered(module: module)
    }
}
