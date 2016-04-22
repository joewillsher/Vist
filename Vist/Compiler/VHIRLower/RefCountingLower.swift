//
//  RefCountingLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension AllocObjectInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let size = LLVMConstInt(LLVMInt32Type(), UInt64(storedType.size(module)), false)
        
        let ref = module.getOrAddRuntimeFunction(named: "vist_allocObject", irGen: irGen)
        return try FunctionCallInst.callFunction(ref,
                                                 args: [size],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}

extension RetainInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let ref = module.getOrAddRuntimeFunction(named: "vist_retainObject", irGen: irGen)
        return try FunctionCallInst.callFunction(ref,
                                                 args: [try object.bitcastToOpaqueRefCountedType(irGen)],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}

extension ReleaseInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let functionName = unowned ? "vist_releaseUnownedObject" : "vist_releaseObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, irGen: irGen)
        
        return try FunctionCallInst.callFunction(ref,
                                                 args: [try object.bitcastToOpaqueRefCountedType(irGen)],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}


extension DeallocObjectInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let functionName = unowned ? "vist_deallocUnownedObject" : "vist_deallocObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, irGen: irGen)
        
        return try FunctionCallInst.callFunction(ref,
                                                 args: [try object.bitcastToOpaqueRefCountedType(irGen)],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}


private extension PtrOperand {
    func bitcastToOpaqueRefCountedType(irGen: IRGen) throws -> LLVMValueRef {
        let refcounted = Runtime.refcountedObjectPointerType.lowerType(module)
        return LLVMBuildBitCast(irGen.builder, loweredValue, refcounted, "")
    }
}
