//
//  ExistentialLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ExistentialConstructInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        guard case let aliasType as TypeAlias = value.memType, case let structType as StructType = aliasType.targetType else { fatalError() }
        
        let exType = existentialType.usingTypesIn(module).lowerType(module)
        let valueMem = LLVMBuildAlloca(irGen.builder, aliasType.lowerType(module), "") // allocate the struct
        let ptr = LLVMBuildAlloca(irGen.builder, exType, "")
        
        let llvmName = irName.map { "\($0)." }
        
        let propArrayPtr = LLVMBuildStructGEP(irGen.builder, ptr, 0, "\(llvmName)prop_metadata") // [n x i32]*
        let methodArrayPtr = LLVMBuildStructGEP(irGen.builder, ptr, 1, "\(llvmName)method_metadata") // [n x i8*]*
        let structPtr = LLVMBuildStructGEP(irGen.builder, ptr, 2, "\(llvmName)opaque") // i8**
        
        let propArr = try existentialType.existentialPropertyMetadataFor(structType, module: module, irGen: irGen)
        LLVMBuildStore(irGen.builder, propArr, propArrayPtr)
        
        let methodArr = try existentialType.existentialMethodMetadataFor(structType, module: module, irGen: irGen)
        LLVMBuildStore(irGen.builder, methodArr, methodArrayPtr)
        
        let v = LLVMBuildLoad(irGen.builder, value.loweredValue, "")
        LLVMBuildStore(irGen.builder, v, valueMem)
        let opaqueValueMem = LLVMBuildBitCast(irGen.builder, valueMem, BuiltinType.opaquePointer.lowerType(module), "")
        LLVMBuildStore(irGen.builder, opaqueValueMem, structPtr)
        
        return LLVMBuildLoad(irGen.builder, ptr, irName ?? "")
    }
}

extension ExistentialPropertyInst : VHIRLower {
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        guard case let aliasType as TypeAlias = existential.memType, case let conceptType as ConceptType = aliasType.targetType, let propertyType = type?.lowerType(module) else { fatalError() }
        
        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        let i = try conceptType.indexOfMemberNamed(propertyName)
        
        var index = [LLVMConstInt(LLVMInt32Type(), UInt64(i), false)] // i32
        
        let llvmName = irName.map { "\($0)." } ?? ""
        
        let i32PtrType = BuiltinType.pointer(to: BuiltinType.int(size: 32)).lowerType(module)
        let arr = LLVMBuildStructGEP(irGen.builder, existential.loweredValue, 0, "\(llvmName)metadata_ptr") // [n x i32]*
        let propertyMetadataBasePtr = LLVMBuildBitCast(irGen.builder, arr, i32PtrType, "\(llvmName)metadata_base_ptr") // i32*
        
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, propertyMetadataBasePtr, &index, 1, "") // i32*
        var offset = [LLVMBuildLoad(irGen.builder, pointerToArrayElement, "")] // i32
        
        let elementPtrType = LLVMPointerType(propertyType, 0) // ElTy.Type
        let structElementPointer = LLVMBuildStructGEP(module.loweredBuilder, existential.loweredValue, 2, "\(llvmName)element_pointer") // i8**
        let opaqueInstancePointer = LLVMBuildLoad(module.loweredBuilder, structElementPointer, "\(llvmName)opaque_instance_pointer") // i8*
        let instanceMemberPtr = LLVMBuildGEP(irGen.builder, opaqueInstancePointer, &offset, 1, "") // i8*
        let elPtr = LLVMBuildBitCast(irGen.builder, instanceMemberPtr, elementPtrType, "\(llvmName)ptr") // ElTy*
        return LLVMBuildLoad(irGen.builder, elPtr, irName ?? "")
    }
}

extension ExistentialUnboxInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let p = LLVMBuildStructGEP(irGen.builder, existential.loweredValue, 2, "")
        return LLVMBuildLoad(irGen.builder, p, irName ?? "")
    }
}

extension ExistentialWitnessMethodInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let llvmName = irName.map { "\($0)." } ?? ""
        let i = try existentialType.indexOf(methodNamed: methodName, argTypes: argTypes)
        let fnType = try existentialType
            .methodType(methodNamed: methodName, argTypes: argTypes)
            .withOpaqueParent().cannonicalType(module)
            .usingTypesIn(module)
        
        var index = LLVMConstInt(LLVMInt32Type(), UInt64(i), false) // i32
        
        let opaquePtrType = BuiltinType.pointer(to: BuiltinType.opaquePointer).lowerType(module)
        let arr = LLVMBuildStructGEP(irGen.builder, existential.loweredValue, 1, "\(llvmName)witness_table_ptr") // [n x i8*]*
        let methodMetadataBasePtr = LLVMBuildBitCast(irGen.builder, arr, opaquePtrType, "\(llvmName)witness_table_base_ptr") // i8**
        
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, methodMetadataBasePtr, &index, 1, "") // i8**
        let functionPointer = LLVMBuildLoad(irGen.builder, pointerToArrayElement, "") // i8*
        
        let functionType = BuiltinType.pointer(to: fnType).lowerType(module)
        return LLVMBuildBitCast(irGen.builder, functionPointer, functionType, irName ?? "") // fntype*
    }
}


private extension ConceptType {
    /// Returns the metadata array map, which transforms the protocol's properties
    /// to an element in the `type`. Type `[n * i32]`
    func existentialPropertyMetadataFor(structType: StructType, module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let dataLayout = LLVMCreateTargetData(LLVMGetDataLayout(irGen.module))
        let conformingType = structType.lowerType(module)
        
        // a table of offsets
        let offsets = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { index in LLVMOffsetOfElement(dataLayout, conformingType, UInt32(index)) }
            .map { LLVMConstInt(LLVMInt32Type(), UInt64($0), false) }
        
        return try ArrayInst.lowerBuffer(offsets,
                                         elType: BuiltinType.int(size: 32),
                                         irName: "metadata",
                                         module: module,
                                         irGen: irGen)
    }
    
    /// Returns the metadata array of function pointers. Type `[n * i8*]`
    func existentialMethodMetadataFor(structType: StructType, module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let opaquePtrType = BuiltinType.opaquePointer
        
        let ptrs = try requiredFunctions
            .map { methodName, type, mutating in
                try structType.ptrToMethodNamed(methodName, type: type.withParent(structType, mutating: mutating), module: module)
            }
            .map { ptr in
                LLVMBuildBitCast(irGen.builder, ptr, opaquePtrType.lowerType(module), LLVMGetValueName(ptr))
        }
        
        return try ArrayInst.lowerBuffer(ptrs,
                                         elType: opaquePtrType,
                                         irName: "witness_table",
                                         module: module,
                                         irGen: irGen)
    }
}

