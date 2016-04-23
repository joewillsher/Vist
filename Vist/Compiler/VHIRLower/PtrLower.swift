//
//  PtrLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension AllocInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildAlloca(type: storedType.lowerType(module), name: irName)
    }
}

extension StoreInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildStore(value: value.loweredValue!, in: address.loweredValue!)
    }
}
extension LoadInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildLoad(from: address.loweredValue!, name: irName)
    }
}
extension BitcastInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildBitcast(value: address.loweredValue!, to: pointerType.lowerType(module), name: irName)
    }
}
