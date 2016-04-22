//
//  RefCountingLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension AllocObjectInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        let size = LLVMValue.constInt(storedType.size(module), size: 32)
        
        let ref = module.getOrAddRuntimeFunction(named: "vist_allocObject", irGen: irGen)
        return try module.loweredBuilder.buildCall(ref,
                                                    args: [size],
                                                    name: irName)

    }
}

extension RetainInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        let ref = module.getOrAddRuntimeFunction(named: "vist_retainObject", irGen: irGen)
        return try module.loweredBuilder.buildCall(ref,
                                                    args: [object.bitcastToOpaqueRefCountedType()],
                                                    name: irName)
    }
}

extension ReleaseInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        let functionName = unowned ? "vist_releaseUnownedObject" : "vist_releaseObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, irGen: irGen)
        return try module.loweredBuilder.buildCall(ref,
                                                    args: [object.bitcastToOpaqueRefCountedType()],
                                                    name: irName)
    }
}


extension DeallocObjectInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        let functionName = unowned ? "vist_deallocUnownedObject" : "vist_deallocObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, irGen: irGen)
        return try module.loweredBuilder.buildCall(ref,
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
