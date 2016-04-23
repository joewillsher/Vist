//
//  RefCountingLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension AllocObjectInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        let size = LLVMValue.constInt(storedType.size(module), size: 32)
        
        let ref = module.getOrAddRuntimeFunction(named: "vist_allocObject", IGF: IGF)
        return try IGF.builder.buildCall(ref,
                                         args: [size],
                                         name: irName)
        
    }
}

extension RetainInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        let ref = module.getOrAddRuntimeFunction(named: "vist_retainObject", IGF: IGF)
        return try IGF.builder.buildCall(ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}

extension ReleaseInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        let functionName = unowned ? "vist_releaseUnownedObject" : "vist_releaseObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, IGF: IGF)
        return try IGF.builder.buildCall(ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}


extension DeallocObjectInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        let functionName = unowned ? "vist_deallocUnownedObject" : "vist_deallocObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, IGF: IGF)
        return try IGF.builder.buildCall(ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}


private extension PtrOperand {
    func bitcastToOpaqueRefCountedType() throws -> LLVMValue {
        let refcounted = Runtime.refcountedObjectPointerType.lowerType(module) as LLVMType
        return try module.loweredBuilder.buildBitcast(value: loweredValue!, to: refcounted)
    }
}
