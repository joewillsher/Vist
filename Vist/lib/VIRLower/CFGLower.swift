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
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        let condition: LLVMValue
        
        if targetType.isStructType() {
            let structType = try targetType.getAsStructType()
            
            let outMem = try IGF.builder.buildAlloca(type: structType.importedType(in: module).lowered(module: module))
            let cast = try IGF.builder.buildBitcast(value: outMem, to: LLVMType.opaquePointer)
            let metadata = try structType.getLLVMTypeMetadata(IGF: &IGF, module: module)
            
            let ref = module.getRuntimeFunction(.castExistentialToConcrete, IGF: &IGF)
            let succeeded = try IGF.builder.buildCall(function: ref, args: [val.loweredValue!, metadata, cast])
            
            condition = succeeded
            
            let ins = IGF.builder.getInsertBlock()!
            IGF.builder.position(before: successVariable.phi!)
            
            let load = try IGF.builder.buildLoad(from: outMem)
            successVariable.phi!.eraseFromParent(replacingAllUsesWith: load)
            for use in successVariable.uses {
                use.setLoweredValue(load)
            }
            
            IGF.builder.position(atEndOf: ins)
        }
        else {
            fatalError("TODO")
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
