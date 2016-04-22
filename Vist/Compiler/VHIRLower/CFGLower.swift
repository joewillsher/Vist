//
//  CFGLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ReturnInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        
        if case _ as VoidLiteralValue = value.value {
            return try module.loweredBuilder.buildRetVoid()
        }
        else {
            let v = try value.vhirLower(module, irGen: irGen)
            return try module.loweredBuilder.buildRet(v)
        }
    }
}

extension YieldInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildCall(targetThunk!.loweredFunction!, args: [value.loweredValue!], name: irName)
    }
}


extension BreakInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildBr(to: call.block.loweredBlock!)
    }
}

extension CondBreakInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildCondBr(if: condition.loweredValue!,
                                                      to: thenCall.block.loweredBlock!,
                                                      elseTo: elseCall.block.loweredBlock!)
    }
}

extension VHIRFunctionCall {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        let call = try module.loweredBuilder.buildCall(functionRef,
                                                    args: args.map { $0.loweredValue! },
                                                    name: irName)
        functionType.addMetadataTo(call)
        return call
    }
    
}
