//
//  CFGLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ReturnInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        if (returnValue.value as? TupleCreateInst)?.elements.isEmpty ?? false {
            return try igf.builder.buildRetVoid()
        }
        else {
            return try igf.builder.buildRet(val: returnValue.loweredValue!)
        }
    }
}

extension BreakInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        return try igf.builder.buildBr(to: call.block.loweredBlock!)
    }
}

extension CondBreakInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        return try igf.builder.buildCondBr(if: condition.loweredValue!,
                                           to: thenCall.block.loweredBlock!,
                                           elseTo: elseCall.block.loweredBlock!)
    }
}
extension CheckedCastBreakInst : VIRLower {
    
    /// In the successor block, constructs the value by calling `fn`. This erases the 
    /// phony phi node and replaces its users
    private func constructInSuccessorBlock(igf: inout IRGenFunction, with: (inout IRGenFunction) throws -> LLVMValue) rethrows {
        let ins = igf.builder.getInsertBlock()!
        igf.builder.position(before: successVariable.phi!)
        
        let val = try with(&igf)
        successVariable.phi!.eraseFromParent(replacingAllUsesWith: val)
        for use in successVariable.uses {
            use.setLoweredValue(val)
        }
        
        igf.builder.position(atEndOf: ins)
    }
    
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        let condition: LLVMValue
        
        switch (val.memType?.getConcreteNominalType(), targetType.getConcreteNominalType()) {
        case (let structType as StructType, let targetStructType as StructType):
            // if we are casting concrete type -> concrete type, we don't need to do anything
            // assert they are the same type
            precondition(structType == targetStructType)
            constructInSuccessorBlock(igf: &igf) { _ in val.loweredValue! }
            return try igf.builder.buildCondBr(if: LLVMValue.constBool(value: true),
                                               to: successCall.block.loweredBlock!,
                                               elseTo: failCall.block.loweredBlock!)
            
        case (let structType as StructType, let concept as ConceptType):
            
            if structType.models(concept: concept) {
                
                // if it conforms, we construct an existential
                try constructInSuccessorBlock(igf: &igf) { igf in
                    let exMemory = try igf.builder.buildAlloca(type: Runtime.existentialObjectType.importedCanType(in: module), name: successVariable.paramName)
                    let bc = try igf.builder.buildBitcast(value: val.loweredValue!, to: .opaquePointer)
                    _ = try ExistentialConstructInst.gen(instance: bc, out: exMemory,
                                                         structType: structType, existentialType: concept,
                                                         isLocal: true, module: module, igf: &igf)
                    return exMemory
                }
                // and return an unconditionally true branch
                return try igf.builder.buildCondBr(if: LLVMValue.constBool(value: true),
                                                   to: successCall.block.loweredBlock!,
                                                   elseTo: failCall.block.loweredBlock!)
            }
            else {
                // otherwise we erase the phi and unconditionally break to the false block
                constructInSuccessorBlock(igf: &igf) { igf in
                    LLVMValue.undef(type: successVariable.type!.lowered(module: module))
                }
                return try igf.builder.buildCondBr(if: LLVMValue.constBool(value: false),
                                                   to: successCall.block.loweredBlock!,
                                                   elseTo: failCall.block.loweredBlock!)
            }
            
        case (is ConceptType, let structType as StructType):
            let outMem = try igf.builder.buildAlloca(type: structType.importedCanType(in: module), name: successVariable.paramName)
            let cast = try igf.builder.buildBitcast(value: outMem, to: LLVMType.opaquePointer)
            let metadata = try structType.getLLVMTypeMetadata(igf: &igf, module: module)
            
            let ref = module.getRuntimeFunction(.castExistentialToConcrete, igf: &igf)
            let succeeded = try igf.builder.buildCall(function: ref, args: [val.loweredValue!, metadata, cast])
            
            condition = succeeded
            constructInSuccessorBlock(igf: &igf) { _ in outMem }

        case (is ConceptType, let targetConceptType as ConceptType):
            
            // HACK: this concept could be referenced by any type, so emit conformances
            // for this concept for all module types
            for type in module.typeList.values {
                guard let structType = type.getConcreteNominalType(), !structType.isConceptType() else { continue }
                guard structType.models(concept: targetConceptType) else { continue }
                _ = try structType.generateConformanceMetadata(concept: targetConceptType, igf: &igf, module: module)
            }
            
            let outMem = try igf.builder.buildAlloca(type: Runtime.existentialObjectType.importedCanType(in: module),
                                                     name: successVariable.paramName)
            let metadata = try targetConceptType.getLLVMTypeMetadata(igf: &igf, module: module)
            
            let ref = module.getRuntimeFunction(.castExistentialToConcept, igf: &igf)
            let succeeded = try igf.builder.buildCall(function: ref, args: [val.loweredValue!, metadata, outMem])
            
            condition = succeeded
            constructInSuccessorBlock(igf: &igf) { _ in outMem }

        default:
            fatalError("Casting to non struct/concept type is not supported")
        }
        
        return try igf.builder.buildCondBr(if: condition,
                                           to: successCall.block.loweredBlock!,
                                           elseTo: failCall.block.loweredBlock!)
    }
}


extension VIRFunctionCall {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        return try igf.builder.buildCall(function: functionRef,
                                             args: functionArgs.map { $0.loweredValue! },
                                             name: irName)
    }
    
}
