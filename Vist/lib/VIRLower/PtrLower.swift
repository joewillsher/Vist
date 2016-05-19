//
//  PtrLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension AllocInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildAlloca(type: storedType.lowerType(module), name: irName)
    }
}

extension StoreInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildStore(value: value.loweredValue!, in: address.loweredValue!)
    }
}
extension LoadInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildLoad(from: address.loweredValue!, name: irName)
    }
}
extension BitcastInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildBitcast(value: address.loweredValue!, to: pointerType.lowerType(module), name: irName)
    }
}
