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
            
        case let type as NominalType where type.isHeapAllocated:
            let ref = module.getRuntimeFunction(.releaseObject,
                                                IGF: &IGF)
            return try IGF.builder.buildCall(function: ref,
                                             args: [addr.bitcastToOpaqueRefCountedType()],
                                             name: irName)
            
        case let type as NominalType where type.isStructType():
            guard case let modType as TypeAlias = addr.memType, let destructor = modType.destructor else {
                return LLVMValue.nullptr
            }
            
            _ = try IGF.builder.buildApply(function: destructor.loweredFunction!.function, args: [addr.loweredValue!])
            return LLVMValue.nullptr
            
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
            
        case let type as StructType where type.isHeapAllocated:
            fatalError("Should not be releasing a ref counted object by value")
            
        case let type as NominalType where type.isStructType():
            // if it requires a custom deallocator, call that
            guard case let modType as TypeAlias = val.type, let destructor = modType.destructor else {
                return LLVMValue.nullptr // if not, we dont emit any destruction IR
            }
            
            try IGF.builder.buildApply(function: destructor.loweredFunction!.function, args: [mem])
            return LLVMValue.nullptr
            
        default:
            return LLVMValue.nullptr
        }
    }
}

extension CopyAddrInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        switch addr.memType {
        case let type? where type.isConceptType():
            // call into the runtime to copy the existential -- this calls the existential's
            // copy constructor, which copies over all vals stored in the existential.
            let ref = module.getRuntimeFunction(.copyExistentialBuffer, IGF: &IGF)
            try IGF.builder.buildCall(function: ref, args: [addr.loweredValue!, outAddr.loweredValue!])
            return outAddr.loweredValue!
            
//        case let type as StructType where type.isHeapAllocated:
//            // for a class, retain and return same pointer
//            let ref = module.getRuntimeFunction(.retainObject,
//                                                IGF: &IGF)
//            try IGF.builder.buildCall(function: ref,
//                                      args: [addr.bitcastToOpaqueRefCountedType()],
//                                      name: irName)
//            return addr.loweredValue!
            
        case let type as NominalType where type.isStructType():
            
            // if there is a copy constructor, call into that to init the new mem
            guard case let modType as TypeAlias = addr.memType, let copyConstructor = modType.copyConstructor else {
                // otheriwse we just do a shallow copy
                let val = try IGF.builder.buildLoad(from: addr.loweredValue!)
                try IGF.builder.buildStore(value: val, in: outAddr.loweredValue!)
                return outAddr.loweredValue!
            }
            
            _ = try IGF.builder.buildCall(function: copyConstructor.loweredFunction!, args: [addr.loweredValue!, outAddr.loweredValue!])
            return outAddr.loweredValue!
            
        default:
            let val = try IGF.builder.buildLoad(from: addr.loweredValue!)
            try IGF.builder.buildStore(value: val, in: outAddr.loweredValue!)
            return outAddr.loweredValue!
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
