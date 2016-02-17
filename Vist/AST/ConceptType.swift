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
    ///
    func existentialMetadataMapFor(structType: StructType, irGen: IRGen) throws -> LLVMValueRef {
        
        let dataLayout = LLVMCreateTargetData(LLVMGetDataLayout(irGen.module))
        let conformingType = structType.globalType(irGen.module)
        
        let indicies = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { index in LLVMOffsetOfElement(dataLayout, conformingType, UInt32(index)) }
            .map (BuiltinType.intGen(size: 32))
        
        let arrType = LLVMArrayType(LLVMInt32Type(), UInt32(indicies.count))
        let ptr = LLVMBuildAlloca(irGen.builder, arrType, "metadata") // [n x i32]*
        let i32PtrType = LLVMPointerType(LLVMInt32Type(), 0)
        let basePtr = LLVMBuildBitCast(irGen.builder, ptr, i32PtrType, "") // i32*

        for (i, offset) in indicies.enumerate() {
            // Get pointer to element n
            let indicies = [BuiltinType.intGen(size: 32)(i)].ptr()
            defer { indicies.dealloc(1) }
            
            let el = LLVMBuildGEP(irGen.builder, basePtr, indicies, 1, "el.\(i)")
            let bcElPtr = LLVMBuildBitCast(irGen.builder, el, i32PtrType, "el.ptr.\(i)")
            // load val into memory
            LLVMBuildStore(irGen.builder, offset, bcElPtr)
        }
                
        return LLVMBuildLoad(irGen.builder, ptr, "")
    }
}


