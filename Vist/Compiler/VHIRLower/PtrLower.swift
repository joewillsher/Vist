//
//  PtrLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension AllocInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildAlloca(type: storedType.lowerType(module), name: irName)
    }
}

extension StoreInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildStore(value: value.loweredValue!, in: address.loweredValue!)
    }
}
extension LoadInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildLoad(from: address.loweredValue!, name: irName)
    }
}
extension BitcastInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildBitcast(value: address.loweredValue!, to: pointerType.lowerType(module), name: irName)
    }
}
