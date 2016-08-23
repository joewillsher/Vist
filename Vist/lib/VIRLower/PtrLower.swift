//
//  PtrLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension AllocInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildAlloca(type: storedType.lowered(module: module), name: irName)
    }
}
extension StoreInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildStore(value: value.loweredValue!, in: address.loweredValue!)
    }
}
extension LoadInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildLoad(from: address.loweredValue!, name: irName)
    }
}
extension BitcastInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildBitcast(value: address.loweredValue!, to: pointerType.lowered(module: module), name: irName)
    }
}
extension FunctionRefInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return IGF.module.function(named: functionName)!.function
    }
}
extension DestroyAddrInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        switch addr.memType {
        case let type? where type.isConceptType():
            let ref = module.getRuntimeFunction(.destroyExistentialBuffer, IGF: &IGF)
            return try IGF.builder.buildCall(function: ref, args: [addr.loweredValue!])
            
        case let type as NominalType where type.isStructType():
            let metadata = try type.getLLVMTypeMetadata(IGF: &IGF, module: module)
            let bc = try IGF.builder.buildBitcast(value: addr.loweredValue!, to: LLVMType.opaquePointer)
            let ref = module.getRuntimeFunction(.destroyStructAddr, IGF: &IGF)
            return try IGF.builder.buildCall(function: ref, args: [bc, metadata])
            
        default:
            return LLVMValue.nullptr
        }
    }
}
extension DestroyValInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let mem = try IGF.builder.buildAlloca(type: val.type!.importedType(in: module).lowered(module: module), name: irName)
        try IGF.builder.buildStore(value: val.loweredValue!, in: mem)
        
        switch val.type {
        case let type? where type.isConceptType():
            let ref = module.getRuntimeFunction(.destroyExistentialBuffer, IGF: &IGF)
            return try IGF.builder.buildCall(function: ref, args: [mem])
            
        case let type as NominalType where type.isStructType():
            let bc = try IGF.builder.buildBitcast(value: mem, to: LLVMType.opaquePointer)
            let metadata = try type.getLLVMTypeMetadata(IGF: &IGF, module: module)
            let ref = module.getRuntimeFunction(.destroyStructAddr, IGF: &IGF)
            return try IGF.builder.buildCall(function: ref, args: [bc, metadata])
            
        default:
            return LLVMValue.nullptr
        }
    }
}


extension VariableInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return value.loweredValue!
    }
}

extension VariableAddrInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return addr.loweredValue!
    }
}
