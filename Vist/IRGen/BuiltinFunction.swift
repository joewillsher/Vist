//
//  BuiltinFunction.swift
//  Vist
//
//  Created by Josef Willsher on 06/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

func builtinInstruction(named: String, irGen: IRGen) -> ([LLVMValueRef] throws -> LLVMValueRef)? {
    
    switch named {
    case "LLVM.trap": return { args in
        let l = getIntrinsic("llvm.trap", irGen.module, nil, false)
        
        let args = [].ptr()
        defer { args.dealloc(0) }
        
        return LLVMBuildCall(irGen.builder, l, args, 0, "")
        }
        
    case "LLVM.expect": return { args in
        let l = getIntrinsic("llvm.expect", irGen.module, LLVMTypeOf(args[0]), false)
        
        let args = args.ptr()
        defer { args.dealloc(2) }
        
        return LLVMBuildCall(irGen.builder, l, args, 2, "")
        }
        
        
        
    case "LLVM.i_add": return { args in
        let l = getIntrinsic("llvm.sadd.with.overflow", irGen.module, LLVMTypeOf(args[0]), false)
        
        let args = args.ptr()
        defer { args.dealloc(2) }
        
        return LLVMBuildCall(irGen.builder, l, args, 2, "add_res")
        }
        
    case "LLVM.i_sub": return { args in
        let l = getIntrinsic("llvm.ssub.with.overflow", irGen.module, LLVMTypeOf(args[0]), false)
        
        let args = args.ptr()
        defer { args.dealloc(2) }
        
        return LLVMBuildCall(irGen.builder, l, args, 2, "sub_res")
        }
    case "LLVM.i_mul": return { args in
        let l = getIntrinsic("llvm.smul.with.overflow", irGen.module, LLVMTypeOf(args[0]), false)
        
        let args = args.ptr()
        defer { args.dealloc(2) }
        
        return LLVMBuildCall(irGen.builder, l, args, 2, "mul_res")
        }
    case "LLVM.i_div": return { args in LLVMBuildUDiv(irGen.builder, args[0], args[1], "div_res") }
    case "LLVM.i_rem": return { args in LLVMBuildURem(irGen.builder, args[0], args[1], "rem_res") }

    case "LLVM.i_shr": return { args in LLVMBuildAShr(irGen.builder, args[0], args[1], "shr_res") }
    case "LLVM.i_shl": return { args in LLVMBuildShl(irGen.builder, args[0], args[1], "shl_res") }
    case "LLVM.i_and": return { args in LLVMBuildAnd(irGen.builder, args[0], args[1], "and_res") }
    case "LLVM.i_or": return { args in LLVMBuildOr(irGen.builder, args[0], args[1], "or_res") }
    case "LLVM.i_xor": return { args in LLVMBuildXor(irGen.builder, args[0], args[1], "xor_res") }
        
    case "LLVM.i_cmp_lt": return { args in return LLVMBuildICmp(irGen.builder, LLVMIntSLT, args[0], args[1], "cmp_lt_res") }
    case "LLVM.i_cmp_lte": return { args in return LLVMBuildICmp(irGen.builder, LLVMIntSLE, args[0], args[1], "cmp_lte_res") }
    case "LLVM.i_cmp_gt": return { args in return LLVMBuildICmp(irGen.builder, LLVMIntSGT, args[0], args[1], "cmp_gt_res") }
    case "LLVM.i_cmp_gte": return { args in return LLVMBuildICmp(irGen.builder, LLVMIntSGE, args[0], args[1], "cmp_gte_res") }
    case "LLVM.i_eq": return { args in return LLVMBuildICmp(irGen.builder, LLVMIntEQ, args[0], args[1], "cmp_eq_res") }
    case "LLVM.i_neq": return { args in return LLVMBuildICmp(irGen.builder, LLVMIntNE, args[0], args[1], "cmp_neq_res") }
        
        
    case "LLVM.b_and": return { args in return LLVMBuildAnd(irGen.builder, args[0], args[1], "cmp_and_res") }
    case "LLVM.b_or": return { args in return LLVMBuildOr(irGen.builder, args[0], args[1], "cmp_or_res") }
        
        
    case "LLVM.f_add": return { args in LLVMBuildFAdd(irGen.builder, args[0], args[1], "add_res") }
    case "LLVM.f_sub": return { args in LLVMBuildFSub(irGen.builder, args[0], args[1], "sub_res") }
    case "LLVM.f_mul": return { args in LLVMBuildFMul(irGen.builder, args[0], args[1], "mul_res") }
    case "LLVM.f_div": return { args in LLVMBuildFDiv(irGen.builder, args[0], args[1], "div_res") }
    case "LLVM.f_rem": return { args in LLVMBuildFRem(irGen.builder, args[0], args[1], "rem_res") }
        
    case "LLVM.f_cmp_lt": return { args in return LLVMBuildFCmp(irGen.builder, LLVMRealOLT, args[0], args[1], "cmp_lt_res") }
    case "LLVM.f_cmp_lte": return { args in return LLVMBuildFCmp(irGen.builder, LLVMRealOLE, args[0], args[1], "cmp_lte_res") }
    case "LLVM.f_cmp_gt": return { args in return LLVMBuildFCmp(irGen.builder, LLVMRealOGT, args[0], args[1], "cmp_gt_res") }
    case "LLVM.f_cmp_gte": return { args in return LLVMBuildFCmp(irGen.builder, LLVMRealOGE, args[0], args[1], "cmp_gte_res") }
    case "LLVM.f_eq": return { args in return LLVMBuildFCmp(irGen.builder, LLVMRealOEQ, args[0], args[1], "cmp_eq_res") }
    case "LLVM.f_neq": return { args in return LLVMBuildFCmp(irGen.builder, LLVMRealONE, args[0], args[1], "cmp_neq_res") }
        
    default: return nil
    }
}

