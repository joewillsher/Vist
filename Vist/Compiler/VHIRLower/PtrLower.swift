//
//  PtrLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension AllocInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildAlloca(irGen.builder, storedType.lowerType(module), irName ?? "")
    }
}

extension StoreInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildStore(irGen.builder, value.loweredValue, address.loweredValue)
    }
}
extension LoadInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, address.loweredValue, irName ?? "")
    }
}
extension BitcastInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildBitCast(irGen.builder, address.loweredValue, pointerType.lowerType(module), irName ?? "")
    }
}
