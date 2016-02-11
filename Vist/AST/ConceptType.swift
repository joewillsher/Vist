//
//  ConceptType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct ConceptType : StorageType {
    
    let name: String
    let requiredFunctions: [StructMethod], requiredProperties: [StructMember]
    
    /// a pointer to array of self's properties' implementation indecies in the conformant
    /// followed by an opaque pointer to the conformant
    func ir() -> LLVMTypeRef {
        return StructType.withTypes([
            BuiltinType.Array(el: BuiltinType.Int(size: 32), size: UInt32(requiredProperties.count)),
            BuiltinType.OpaquePointer
            ]).ir()
    }
    
    func memberTypes(module: LLVMModuleRef) -> LLVMTypeRef {
        return StructType.withTypes([
            BuiltinType.Array(el: BuiltinType.Int(size: 32), size: UInt32(requiredProperties.count)),
            BuiltinType.OpaquePointer
            ]).memberTypes(module)
    }
    
    
    var debugDescription: String {
        return name
    }
    
    var mangledTypeName: String {
        return "\(name).ex.ty"
    }
    
    var members: [StructMember] {
        return requiredProperties
    }
    
    var methods: [StructMethod] {
        return requiredFunctions
    }
    
    
    var description: String {
        return name
    }

    
    /// Returns the metadata array map, which transforms the protocol's properties
    /// to an element in the `type`
    ///
    func existentialMetadataMapFor(structType: StructType, builder: LLVMBuilderRef) throws -> LLVMValueRef {
        
        let indicies = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { LLVMConstInt(LLVMInt32Type(), UInt64($0), false) }
        
        let buffer = indicies.ptr(), size = UInt32(indicies.count)
        defer { buffer.dealloc(indicies.count) }

        let arrType = LLVMArrayType(LLVMInt32Type(), size)
        let ptr = LLVMBuildArrayAlloca(builder, arrType, buffer.memory, "")
        return LLVMBuildLoad(builder, ptr, "")
    }
    
}

