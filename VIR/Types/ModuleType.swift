//
//  ModuleType.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// A defined abstract type. These sit in a type table in VIR and LLVM
/// and allow the types to be named.
///
/// `ModuleType` simply wraps `targetType` and
final class ModuleType : Type {
    let name: String, targetType: NominalType
    
    var witnessTables: [ConceptType: VIRWitnessTable] = [:]
    var destructor: Function? = nil
    var deinitialiser: Function? = nil
    var copyConstructor: Function? = nil
    var isImported: Bool
    
    init(name: String, targetType: NominalType) {
        self.name = name
        self.targetType = targetType
        self.isImported = StdLib.type(name: name) != nil
    }
    
    func lowered(module: Module) -> LLVMType {
        
        if targetType is ConceptType {
            return ModuleType(name: "", targetType: Runtime.existentialObjectType).lowered(module: module)
        }
        
        if module.loweredModule == nil {
            // backup if a module isn't lowered
            return targetType.lowered(module: module)
        }
        
        // when lowering the alias, we need to get the ref in the LLVM module...
        let found = try? getNamedType(targetType.irName, module.loweredModule!.getModule())
        // found: TypeRef??
        if let f = found?.flatMap({$0}) {
            return LLVMType(ref: f)
        }
        
        // ...and if it isnt already defined we lower the target and add it
        let type = targetType.lowered(module: module)
        let namedType = createNamedType(type.type!, targetType.irName)
        
        return LLVMType(ref: namedType)
    }
    
}

extension ModuleType : NominalType {
    var members: [StructMember] { return targetType.members }
    var methods: [StructMethod] { return targetType.methods }
    var irName: String { return targetType.irName }
    var isHeapAllocated: Bool { return targetType.isHeapAllocated }
    var concepts: [ConceptType] {
        get { return targetType.concepts }
        set { targetType.concepts = newValue }
    }
    var explicitName: String { return targetType.explicitName }
    var mangledName: String { return targetType.mangledName }
    func machineType() -> AIRType { return targetType.machineType() }
    func persistentType(module: Module) -> Type { return targetType.persistentType(module: module) }
    func instanceRawType(module: Module) -> LLVMType { return targetType.instanceRawType(module: module) }
}

extension ModuleType {
    
    func importedType(in module: Module) -> Type {
        return self
    }
    
    func isInModule() -> Bool {
        return true
    }
}

// we need a hash for the type so it can sit in the the type table set
extension ModuleType : Hashable {
    var hashValue: Int {
        return name.hashValue
    }
    static func == (lhs: ModuleType, rhs: ModuleType) -> Bool {
        return lhs.targetType == rhs.targetType
    }
}

//class VIRType<Base : Type> : Type {
//    
//}




