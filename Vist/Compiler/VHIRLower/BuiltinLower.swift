//
//  BuiltinLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//




extension BuiltinInstCall: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        var args = self.args.map { $0.loweredValue }
        let intrinsic: LLVMValueRef
        
        switch inst {
        // overflowing arithmetic
        case .iadd: intrinsic = getSinglyOverloadedIntrinsic("llvm.sadd.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue))
        case .imul: intrinsic = getSinglyOverloadedIntrinsic("llvm.smul.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue))
        case .isub: intrinsic = getSinglyOverloadedIntrinsic("llvm.ssub.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue))
            
        // other intrinsics
        case .expect: intrinsic = getSinglyOverloadedIntrinsic("llvm.expect", irGen.module, LLVMTypeOf(l.loweredValue))
        case .trap:   intrinsic = getRawIntrinsic("llvm.trap", irGen.module)
        case .memcpy:
            // overload types -- we want `@llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1)`
            var overloadTypes = [LLVMTypeOf(args[0]), LLVMTypeOf(args[1]), LLVMInt64Type()]
            // construct intrinsic
            intrinsic = getOverloadedIntrinsic("llvm.memcpy", irGen.module, &overloadTypes, 3)
            // add extra memcpy args
            args.append(LLVMConstInt(LLVMInt32Type(), 1, false)) // i32 align
            args.append(LLVMConstInt(LLVMInt1Type(), 0, false)) // i1 isVolatile
            
        case .allocstack: return LLVMBuildArrayAlloca(irGen.builder, LLVMInt8Type(), args[0], irName ?? "")
        case .allocheap:  return LLVMBuildArrayMalloc(irGen.builder, LLVMInt8Type(), args[0], irName ?? "")
            
        case .advancepointer:
            var index = [r.loweredValue]
            return LLVMBuildGEP(irGen.builder, l.loweredValue, &index, 1, irName ?? "")
        case .opaqueload:
            return LLVMBuildLoad(irGen.builder, l.loweredValue, irName ?? "")
            
        case .condfail:
            guard let fn = parentFunction, current = parentBlock else { fatalError() }
            let success = LLVMAppendBasicBlock(fn.loweredFunction, "\(current.name).cont"), fail = try fn.buildCondFailBlock(module, irGen: irGen)
            
            LLVMMoveBasicBlockAfter(success, current.loweredBlock)
            LLVMBuildCondBr(irGen.builder, l.loweredValue, fail, success)
            LLVMPositionBuilderAtEnd(irGen.builder, success)
            return nil
            
            // handle calls which arent intrinsics, but builtin
        // instructions. Return these directly
        case .iaddoverflow: return LLVMBuildAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ieq:  return LLVMBuildICmp(irGen.builder, LLVMIntEQ, l.loweredValue, r.loweredValue, irName ?? "")
        case .ineq: return LLVMBuildICmp(irGen.builder, LLVMIntNE, l.loweredValue, r.loweredValue, irName ?? "")
        case .idiv: return LLVMBuildSDiv(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .irem: return LLVMBuildSRem(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ilt:  return LLVMBuildICmp(irGen.builder, LLVMIntSLT, l.loweredValue, r.loweredValue, irName ?? "")
        case .ilte: return LLVMBuildICmp(irGen.builder, LLVMIntSLE, l.loweredValue, r.loweredValue, irName ?? "")
        case .igte: return LLVMBuildICmp(irGen.builder, LLVMIntSGE, l.loweredValue, r.loweredValue, irName ?? "")
        case .igt:  return LLVMBuildICmp(irGen.builder, LLVMIntSGT, l.loweredValue, r.loweredValue, irName ?? "")
        case .ishl: return LLVMBuildShl(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ishr: return LLVMBuildAShr(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .iand: return LLVMBuildAnd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ior:  return LLVMBuildOr(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ixor: return LLVMBuildXor(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
            
        case .and:  return LLVMBuildAnd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .or:   return LLVMBuildAnd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
            
        case .fadd: return LLVMBuildFAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .fsub: return LLVMBuildFAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .fmul: return LLVMBuildFMul(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .feq:  return LLVMBuildFCmp(irGen.builder, LLVMRealOEQ, l.loweredValue, r.loweredValue, irName ?? "")
        case .fneq: return LLVMBuildFCmp(irGen.builder, LLVMRealONE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fdiv: return LLVMBuildFDiv(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .frem: return LLVMBuildFRem(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .flt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOLT, l.loweredValue, r.loweredValue, irName ?? "")
        case .flte: return LLVMBuildFCmp(irGen.builder, LLVMRealOLE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fgte: return LLVMBuildFCmp(irGen.builder, LLVMRealOGE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fgt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOGT, l.loweredValue, r.loweredValue, irName ?? "")
        }
        
        return LLVMBuildCall(irGen.builder, intrinsic, &args, UInt32(args.count), irName ?? "")
    }
}


extension Function {
    
    /// Constructs a function's faluire landing pad, or returns the one defined
    func buildCondFailBlock(module: Module, irGen: IRGen) throws -> LLVMBasicBlockRef {
        // if its there already, we can use it
        guard _condFailBlock == nil else { return _condFailBlock }
        
        // make fail block & save current pos
        let ins = LLVMGetInsertBlock(irGen.builder)
        let block = LLVMAppendBasicBlock(loweredFunction, "\(name.demangleName()).trap")
        LLVMPositionBuilderAtEnd(irGen.builder, block)
        
        // Build trap and unreachable
        try BuiltinInstCall.trapInst().vhirLower(module, irGen: irGen)
        LLVMBuildUnreachable(irGen.builder)
        
        // move back; save and return the fail block
        LLVMPositionBuilderAtEnd(irGen.builder, ins)
        _condFailBlock = block
        return block
    }
    
}


