//
//  RefCountingLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension AllocObjectInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
//        let metadataMem = try IGF.builder.buildAlloca(type: Runtime.typeMetadataType.importedType(in: module).lowered(module: module))
        let metadata = try storedType.getLLVMTypeMetadata(IGF: &IGF, module: module)
//        try IGF.builder.buildStore(value: metadata, in: <#T##LLVMValue#>)
        
        let ref = module.getRuntimeFunction(.allocObject, IGF: &IGF)
        let alloced = try IGF.builder.buildCall(function: ref,
                                                args: [metadata],
                                                name: irName)
        
        return try IGF.builder.buildBitcast(value: alloced, to: storedType.lowered(module: module).getPointerType())
    }
}

extension RetainInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(.retainObject, IGF: &IGF)
        return try IGF.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}

extension ReleaseInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(unowned ? .releaseUnownedObject : .releaseObject,
                                                 IGF: &IGF)
        return try IGF.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}


extension DeallocObjectInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(unowned ? .deallocUnownedObject : .deallocObject,
                                                 IGF: &IGF)
        return try IGF.builder.buildCall(function: ref,
                                         args: [object.bitcastToOpaqueRefCountedType()],
                                         name: irName)
    }
}


private extension PtrOperand {
    func bitcastToOpaqueRefCountedType() throws -> LLVMValue {
        let refcounted = Runtime.refcountedObjectPointerType.lowered(module: module) as LLVMType
        return try module.loweredBuilder.buildBitcast(value: loweredValue!, to: refcounted)
    }
}
