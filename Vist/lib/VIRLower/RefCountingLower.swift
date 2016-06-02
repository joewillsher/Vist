//
//  RefCountingLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension AllocObjectInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let sizeValue = storedType.lowered(module: module).size(unit: .bytes, IGF: IGF)
        let size = LLVMValue.constInt(value: sizeValue, size: 32)
        
        let ref = module.getOrAddRuntimeFunction(named: "vist_allocObject", IGF: &IGF)
        return try IGF.builder.buildCall(function: ref,
                                         args: [size],
                                         name: irName)
        
    }
}

extension RetainInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getOrAddRuntimeFunction(named: "vist_retainObject", IGF: &IGF)
        return try IGF.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}

extension ReleaseInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let functionName = unowned ? "vist_releaseUnownedObject" : "vist_releaseObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, IGF: &IGF)
        return try IGF.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}


extension DeallocObjectInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let functionName = unowned ? "vist_deallocUnownedObject" : "vist_deallocObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, IGF: &IGF)
        return try IGF.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}


private extension PtrOperand {
    func bitcastToOpaqueRefCountedType() throws -> LLVMValue {
        let refcounted = Runtime.refcountedObjectPointerType.lowered(module: module) as LLVMType
        return try module.loweredBuilder.buildBitcast(value: loweredValue!, to: refcounted)
    }
}
