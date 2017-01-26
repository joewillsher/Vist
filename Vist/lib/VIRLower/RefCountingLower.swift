//
//  RefCountingLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension AllocObjectInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        let metadata = try refType.getLLVMTypeMetadata(igf: &igf, module: module)
        
        let ref = module.getRuntimeFunction(.allocObject, igf: &igf)
        let alloced = try igf.builder.buildCall(function: ref,
                                                args: [metadata],
                                                name: irName)
        
        return try igf.builder.buildBitcast(value: alloced, to: refType.ptrType().lowered(module: module))
    }
}

extension RetainInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(.retainObject, igf: &igf)
        return try igf.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType(module: module)],
                                         name: irName)
    }
}

extension ReleaseInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(.releaseObject,
                                            igf: &igf)
        return try igf.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType(module: module)],
                                         name: irName)
    }
}


extension DeallocObjectInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(.deallocObject,
                                            igf: &igf)
        return try igf.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType(module: module)],
                                         name: irName)
    }
}


extension PtrOperand {
    func bitcastToOpaqueRefCountedType(module: Module) throws -> LLVMValue {
        let refcounted = Runtime.refcountedObjectPointerType.importedCanType(in: module) as LLVMType
        return try module.loweredBuilder.buildBitcast(value: loweredValue!, to: refcounted)
    }
}
