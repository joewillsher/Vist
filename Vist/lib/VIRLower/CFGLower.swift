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

extension VIRFunctionCall {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildCall(function: functionRef,
                                             args: functionArgs.map { $0.loweredValue! },
                                             name: irName)
    }
    
}
