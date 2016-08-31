//
//  CFGLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ReturnInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        if (returnValue.value as? TupleCreateInst)?.elements.isEmpty ?? false {
            return try IGF.builder.buildRetVoid()
        }
        else {
            return try IGF.builder.buildRet(val: returnValue.loweredValue!)
        }
    }
}

extension BreakInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildBr(to: call.block.loweredBlock!)
    }
}

extension CondBreakInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildCondBr(if: condition.loweredValue!,
                                           to: thenCall.block.loweredBlock!,
                                           elseTo: elseCall.block.loweredBlock!)
    }
}
extension CheckedCastBreakInst : VIRLower {
    
    /// In the successor block, constructs the value by calling `fn`. This erases the 
    /// phony phi node and replaces its users
    private func withInSuccessorBlock(IGF: inout IRGenFunction, fn: @noescape (IGF: inout IRGenFunction) throws -> LLVMValue) rethrows {
        let ins = IGF.builder.getInsertBlock()!
        IGF.builder.position(before: successVariable.phi!)
        
        let val = try fn(IGF: &IGF)
        successVariable.phi!.eraseFromParent(replacingAllUsesWith: val)
        for use in successVariable.uses {
            use.setLoweredValue(val)
        }
        
        IGF.builder.position(atEndOf: ins)
    }
    
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        let condition: LLVMValue
        
        switch (val.memType?.getConcreteNominalType(), targetType.getConcreteNominalType()) {
        case (let structType as StructType, let targetStructType as StructType):
            // if we are casting concrete type -> concrete type, we don't need to do anything
            // assert they are the same type
            precondition(structType == targetStructType)
            try withInSuccessorBlock(IGF: &IGF) { IGF in
                try IGF.builder.buildLoad(from: val.loweredValue!)
            }
            return try IGF.builder.buildCondBr(if: LLVMValue.constBool(value: true),
                                               to: successCall.block.loweredBlock!,
                                               elseTo: failCall.block.loweredBlock!)
            
        case (let structType as StructType, let concept as ConceptType):
            
            if structType.models(concept: concept) {
                
                // if it conforms, we construct an existential
                try withInSuccessorBlock(IGF: &IGF) { IGF in
                    let exMemory = try IGF.builder.buildAlloca(type: Runtime.existentialObjectType.importedType(in: module).lowered(module: module))
                    let bc = try IGF.builder.buildBitcast(value: val.loweredValue!, to: .opaquePointer)
                    _ = try ExistentialConstructInst.gen(instance: bc, out: exMemory,
                                                         structType: structType, existentialType: concept,
                                                         isLocal: true, module: module, IGF: &IGF)
                    return try IGF.builder.buildLoad(from: exMemory)
                }
                // and return an unconditionally true branch
                return try IGF.builder.buildCondBr(if: LLVMValue.constBool(value: true),
                                                   to: successCall.block.loweredBlock!,
                                                   elseTo: failCall.block.loweredBlock!)
            }
            else {
                // otherwise we erase the phi and unconditionally break to the false block
                withInSuccessorBlock(IGF: &IGF) { IGF in
                    LLVMValue.undef(type: successVariable.type!.lowered(module: module))
                }
                return try IGF.builder.buildCondBr(if: LLVMValue.constBool(value: false),
                                                   to: successCall.block.loweredBlock!,
                                                   elseTo: failCall.block.loweredBlock!)
            }
            
        case (is ConceptType, let structType as StructType):
            let outMem = try IGF.builder.buildAlloca(type: structType.importedType(in: module).lowered(module: module))
            let cast = try IGF.builder.buildBitcast(value: outMem, to: LLVMType.opaquePointer)
            let metadata = try structType.getLLVMTypeMetadata(IGF: &IGF, module: module)
            
            let ref = module.getRuntimeFunction(.castExistentialToConcrete, IGF: &IGF)
            let succeeded = try IGF.builder.buildCall(function: ref, args: [val.loweredValue!, metadata, cast])
            
            condition = succeeded
            try withInSuccessorBlock(IGF: &IGF) { IGF in
                try IGF.builder.buildLoad(from: outMem)
            }

        case (is ConceptType, let targetConceptType as ConceptType):
            
            // HACK: this concept could be referenced by any type, so emit conformances
            // for this concept for all module types
            for type in module.typeList.values {
                guard case let structType as StructType = type.getConcreteNominalType() else { continue }
                guard structType.models(concept: targetConceptType) else { continue }
                _ = try structType.generateConformanceMetadata(concept: targetConceptType, IGF: &IGF, module: module)
            }
            
            let outMem = try IGF.builder.buildAlloca(type: Runtime.existentialObjectType.importedType(in: module).lowered(module: module))
            let metadata = try targetConceptType.getLLVMTypeMetadata(IGF: &IGF, module: module)
            
            let ref = module.getRuntimeFunction(.castExistentialToConcept, IGF: &IGF)
            let succeeded = try IGF.builder.buildCall(function: ref, args: [val.loweredValue!, metadata, outMem])
            
            condition = succeeded
            try withInSuccessorBlock(IGF: &IGF) { IGF in
                try IGF.builder.buildLoad(from: outMem)
            }

        default:
            fatalError("Casting to non struct/concept type is not supported")
        }
        
        return try IGF.builder.buildCondBr(if: condition,
                                           to: successCall.block.loweredBlock!,
                                           elseTo: failCall.block.loweredBlock!)
    }
}


extension VIRFunctionCall {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildCall(function: functionRef,
                                             args: functionArgs.map { $0.loweredValue! },
                                             name: irName)
    }
    
}
