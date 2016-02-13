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
    func existentialMetadataMapFor(structType: StructType, irGen: IRGen) throws -> LLVMValueRef {
        
//        let conformingType = structType.globalType(irGen.module)
//        LLVMOffsetOfElement(LLVMCreateTargetData(<#T##StringRep: UnsafePointer<Int8>##UnsafePointer<Int8>#>), <#T##StructTy: LLVMTypeRef##LLVMTypeRef#>, <#T##Element: UInt32##UInt32#>)
        
        
        let indicies = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { LLVMConstInt(LLVMInt32Type(), UInt64($0 * 8), false) }
        let i32PtrType = LLVMPointerType(LLVMInt32Type(), 0)
        
        // FIXME: calculate *actual* ptr offset, instead of element
        // index * 8
        
        let arrType = LLVMArrayType(LLVMInt32Type(), UInt32(indicies.count))
        let ptr = LLVMBuildAlloca(irGen.builder, arrType, "metadata_alloc")
        let basePtr = LLVMBuildBitCast(irGen.builder, ptr, i32PtrType, "metadata_base_ptr") // i32*

        for (i, mappedIndex) in indicies.enumerate() {
            // Get pointer to element n
            let indicies = [LLVMConstInt(LLVMInt32Type(), UInt64(i), false)].ptr()
            defer { indicies.dealloc(1) }
            
            printi32(mappedIndex, irGen: irGen)
            
            let el = LLVMBuildGEP(irGen.builder, ptr, indicies, 1, "el.\(i)")
            let bcElPtr = LLVMBuildBitCast(irGen.builder, el, LLVMPointerType(LLVMInt32Type(), 0), "el.ptr.\(i)")
            // load val into memory
            LLVMBuildStore(irGen.builder, mappedIndex, bcElPtr)
        }
        
        return LLVMBuildLoad(irGen.builder, ptr, "metadata_val")
    }
    
}

func printi32(v: LLVMValueRef, irGen: IRGen) {
    let c = StdLib.getFunctionIR("_Int32_i32", module: irGen.module)!.functionIR
    let iiii = LLVMBuildCall(irGen.builder, c, [v].ptr(), 1, "")
    let cc = StdLib.getFunctionIR("_print_Int32", module: irGen.module)!.functionIR
    LLVMBuildCall(irGen.builder, cc, [iiii].ptr(), 1, "")
}


