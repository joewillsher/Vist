//
//  CFGLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ReturnInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        if case _ as VoidLiteralValue = value.value {
            return LLVMBuildRetVoid(irGen.builder)
        }
        else {
            let v = try value.vhirLower(module, irGen: irGen)
            return LLVMBuildRet(irGen.builder, v)
        }
    }
}

extension YieldInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        var args = [value.loweredValue]
        return LLVMBuildCall(irGen.builder, targetThunk!.loweredFunction, &args, 1, irName ?? "")
    }
}


extension BreakInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildBr(irGen.builder, call.block.loweredBlock)
    }
}

extension CondBreakInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildCondBr(irGen.builder, condition.loweredValue, thenCall.block.loweredBlock, elseCall.block.loweredBlock)
    }
}

extension VHIRFunctionCall {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return try FunctionCallInst.callFunction(functionRef,
                                                 type: functionType,
                                                 args: args.map { $0.loweredValue },
                                                 irGen: irGen,
                                                 irName: irName)
    }
    
}

extension FunctionCallInst {
    static func callFunction(ref: LLVMValueRef, type: FunctionType? = nil, args: [LLVMValueRef], irGen: IRGen, irName: String?) throws -> LLVMValueRef {
        var a = args
        let call = LLVMBuildCall(irGen.builder, ref, &a, UInt32(args.count), irName ?? "")
        type?.addMetadataTo(call)
        
        return call
    }
}

