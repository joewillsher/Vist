//
//  ConceptType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct ConceptType: StorageType {
    
    let name: String
    let requiredFunctions: [StructMethod], requiredProperties: [StructMember]
    
    func lowerType(module: Module) -> LLVMTypeRef {
        return StructType.withTypes([
            BuiltinType.array(el: BuiltinType.int(size: 32), size: UInt32(requiredProperties.count)), // prop offset list
            BuiltinType.array(el: BuiltinType.opaquePointer, size: UInt32(requiredFunctions.count)), // method witness list
            BuiltinType.opaquePointer // wrapped object
            ]).lowerType(module)
    }
    func lowerType(module: LLVMModuleRef) -> LLVMTypeRef {
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

    
    /// Returns the metadata array map, which transforms the protocol's properties
    /// to an element in the `type`. Type `[n * i32]`
    func existentialPropertyMetadataFor(structType: StructType, irGen: IRGen) throws -> LLVMValueRef {
        
        let dataLayout = LLVMCreateTargetData(LLVMGetDataLayout(irGen.module))
        let conformingType = structType.lowerType(irGen.module)
        
        let offsets = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { index in LLVMOffsetOfElement(dataLayout, conformingType, UInt32(index)) }
            .map (BuiltinType.intGen(size: 32))
        
        return LLVMBuilder(irGen.builder).buildArrayOf(LLVMInt32Type(), values: offsets)
    }
    
    /// Returns the metadata array of function pointers. Type `[n * i8*]`
    func existentialMethodMetadataFor(structType: StructType, irGen: IRGen) throws -> LLVMValueRef {
        
        let opaquePtrType = BuiltinType.opaquePointer.lowerType(irGen.module)
        
        let ptrs = requiredFunctions
            .map { methodName, type in structType.ptrToMethodNamed(methodName, type: type, module: irGen.module) }
            .map { ptr in LLVMBuildBitCast(irGen.builder, ptr, opaquePtrType, LLVMGetValueName(ptr)) }
        
        return LLVMBuilder(irGen.builder).buildArrayOf(opaquePtrType, values: ptrs)
    }
}


