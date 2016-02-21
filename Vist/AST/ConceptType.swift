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
    
    func memberTypes(module: LLVMModuleRef) -> LLVMTypeRef {
        return StructType.withTypes([
            BuiltinType.Array(el: BuiltinType.Int(size: 32), size: UInt32(requiredProperties.count)), // prop offset list
            BuiltinType.Array(el: BuiltinType.OpaquePointer, size: UInt32(requiredFunctions.count)), // method witness list
            BuiltinType.OpaquePointer // wrapped object
            ]).memberTypes(module)
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

    
    /// Returns the metadata array map, which transforms the protocol's properties
    /// to an element in the `type`
    func existentialPropertyMetadataFor(structType: StructType, irGen: IRGen) throws -> LLVMValueRef {
        
        let dataLayout = LLVMCreateTargetData(LLVMGetDataLayout(irGen.module))
        let conformingType = structType.globalType(irGen.module)
        
        let offsets = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { index in LLVMOffsetOfElement(dataLayout, conformingType, UInt32(index)) }
            .map (BuiltinType.intGen(size: 32))
        
        return LLVMBuilder(irGen.builder).buildArrayOf(LLVMInt32Type(), values: offsets)
    }
    
    /// Returns the metadata array of function pointers
    func existentialMethodMetadataFor(structType: StructType, irGen: IRGen) throws -> LLVMValueRef {
        
        let opaquePtrType = BuiltinType.OpaquePointer.globalType(irGen.module)
        
        let ptrs = requiredFunctions
            .map { methodName, type in structType.ptrToMethodNamed(methodName, type: type, module: irGen.module) }
            .map { ptr in LLVMBuildBitCast(irGen.builder, ptr, opaquePtrType, LLVMGetValueName(ptr)) }
        
        return LLVMBuilder(irGen.builder).buildArrayOf(opaquePtrType, values: ptrs)
    }
}


