//
//  CFGLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ReturnInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        
        if case _ as VoidLiteralValue = value.value {
            return try IGF.builder.buildRetVoid()
        }
        else {
            let v = try value.vhirLower(IGF)
            return try IGF.builder.buildRet(v)
        }
    }
}

extension YieldInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildCall(targetThunk!.loweredFunction!, args: [value.loweredValue!], name: irName)
    }
}


extension BreakInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildBr(to: call.block.loweredBlock!)
    }
}

extension CondBreakInst : VHIRLower {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildCondBr(if: condition.loweredValue!,
                                           to: thenCall.block.loweredBlock!,
                                           elseTo: elseCall.block.loweredBlock!)
    }
}

extension VHIRFunctionCall {
    func vhirLower(IGF: IRGenFunction) throws -> LLVMValue {
        let call = try IGF.builder.buildCall(functionRef,
                                             args: args.map { $0.loweredValue! },
                                             name: irName)
        functionType.addMetadataTo(call)
        return call
    }
    
}
