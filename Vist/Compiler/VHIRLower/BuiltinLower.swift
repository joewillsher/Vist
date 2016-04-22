//
//  BuiltinLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//




extension BuiltinInstCall: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try LLVMValue(ref: vhirLower(module, irGen: irGen))
    }
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        var args = self.args.map { $0.loweredValue!._value }
        let intrinsic: LLVMValueRef
        
        switch inst {
        // overflowing arithmetic
        case .iadd: intrinsic = getSinglyOverloadedIntrinsic("llvm.sadd.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue!._value))
        case .imul: intrinsic = getSinglyOverloadedIntrinsic("llvm.smul.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue!._value))
        case .isub: intrinsic = getSinglyOverloadedIntrinsic("llvm.ssub.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue!._value))
            
        // other intrinsics
        case .expect: intrinsic = getSinglyOverloadedIntrinsic("llvm.expect", irGen.module, LLVMTypeOf(l.loweredValue!._value))
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
            var index = [r.loweredValue!._value]
            return LLVMBuildGEP(irGen.builder, l.loweredValue!._value, &index, 1, irName ?? "")
        case .opaqueload:
            return LLVMBuildLoad(irGen.builder, l.loweredValue!._value, irName ?? "")
            
        case .condfail:
            guard let fn = parentFunction, current = parentBlock else { fatalError() }
            let success = try fn.loweredFunction!.appendBasicBlock(named: "\(current.name).cont"), fail = try fn.buildCondFailBlock(module, irGen: irGen)
            
            success.move(after: current.loweredBlock!)
            try module.loweredBuilder.buildCondBr(if: l.loweredValue!, to: fail, elseTo: success)
            module.loweredBuilder.positionAtEnd(success)
            return nil
            
            // handle calls which arent intrinsics, but builtin
        // instructions. Return these directly
        case .iaddoverflow: return LLVMBuildAdd(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ieq:  return LLVMBuildICmp(irGen.builder, LLVMIntEQ, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ineq: return LLVMBuildICmp(irGen.builder, LLVMIntNE, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .idiv: return LLVMBuildSDiv(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .irem: return LLVMBuildSRem(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ilt:  return LLVMBuildICmp(irGen.builder, LLVMIntSLT, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ilte: return LLVMBuildICmp(irGen.builder, LLVMIntSLE, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .igte: return LLVMBuildICmp(irGen.builder, LLVMIntSGE, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .igt:  return LLVMBuildICmp(irGen.builder, LLVMIntSGT, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ishl: return LLVMBuildShl(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ishr: return LLVMBuildAShr(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .iand: return LLVMBuildAnd(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ior:  return LLVMBuildOr(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .ixor: return LLVMBuildXor(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
            
        case .and:  return LLVMBuildAnd(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .or:   return LLVMBuildAnd(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
            
        case .fadd: return LLVMBuildFAdd(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .fsub: return LLVMBuildFAdd(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .fmul: return LLVMBuildFMul(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .feq:  return LLVMBuildFCmp(irGen.builder, LLVMRealOEQ, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .fneq: return LLVMBuildFCmp(irGen.builder, LLVMRealONE, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .fdiv: return LLVMBuildFDiv(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .frem: return LLVMBuildFRem(irGen.builder, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .flt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOLT, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .flte: return LLVMBuildFCmp(irGen.builder, LLVMRealOLE, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .fgte: return LLVMBuildFCmp(irGen.builder, LLVMRealOGE, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        case .fgt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOGT, l.loweredValue!._value, r.loweredValue!._value, irName ?? "")
        }
        
        return LLVMBuildCall(irGen.builder, intrinsic, &args, UInt32(args.count), irName ?? "")
    }
}


extension Function {
    
    /// Constructs a function's faluire landing pad, or returns the one defined
    func buildCondFailBlock(module: Module, irGen: IRGen) throws -> LLVMBasicBlock {
        // if its there already, we can use it
        if let condFailBlock = _condFailBlock { return condFailBlock }
        
        // make fail block & save current pos
        let ins = module.loweredBuilder.getInsertBlock()
        let block = try loweredFunction!.appendBasicBlock(named: "\(name.demangleName()).trap")
        module.loweredBuilder.positionAtEnd(block)
        
        // Build trap and unreachable
        try BuiltinInstCall.trapInst().vhirLower(module, irGen: irGen) as LLVMValue
        try module.loweredBuilder.buildUnreachable()
        
        // move back; save and return the fail block
        module.loweredBuilder.positionAtEnd(ins!)
        _condFailBlock = block
        return block
    }
    
}


