//
//  BuiltinFunction.swift
//  Vist
//
//  Created by Josef Willsher on 06/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation


func builtinBinaryInstruction(named: String, builder: LLVMBuilderRef, module: LLVMModuleRef) -> ((LLVMValueRef, LLVMValueRef) throws -> LLVMValueRef)? {
    switch named {
        
    case "LLVM.i_add": return {
        let l = getIntrinsic("llvm.sadd.with.overflow", module, LLVMTypeOf($0))
        
        let args = [$0, $1].ptr()
        defer { args.dealloc(2) }
        
        return LLVMBuildCall(builder, l, args, 2, "add_res")
        }
        
    case "LLVM.i_sub": return {
        let l = getIntrinsic("llvm.ssub.with.overflow", module, LLVMTypeOf($0))
        
        let args = [$0, $1].ptr()
        defer { args.dealloc(2) }
        
        return LLVMBuildCall(builder, l, args, 2, "sub_res")
        }
    case "LLVM.i_mul": return {
        let l = getIntrinsic("llvm.smul.with.overflow", module, LLVMTypeOf($0))
        
        let args = [$0, $1].ptr()
        defer { args.dealloc(2) }
        
        return LLVMBuildCall(builder, l, args, 2, "mul_res")
        }
    case "LLVM.i_div": return { LLVMBuildUDiv(builder, $0, $1, "div_res") }
    case "LLVM.i_rem": return { LLVMBuildURem(builder, $0, $1, "rem_res") }
        
    case "LLVM.i_cmp_lt": return { return LLVMBuildICmp(builder, LLVMIntSLT, $0, $1, "cmp_lt_res") }
    case "LLVM.i_cmp_lte": return { return LLVMBuildICmp(builder, LLVMIntSLE, $0, $1, "cmp_lte_res") }
    case "LLVM.i_cmp_gt": return { return LLVMBuildICmp(builder, LLVMIntSGT, $0, $1, "cmp_gt_res") }
    case "LLVM.i_cmp_gte": return { return LLVMBuildICmp(builder, LLVMIntSGE, $0, $1, "cmp_gte_res") }
    case "LLVM.i_eq": return { return LLVMBuildICmp(builder, LLVMIntEQ, $0, $1, "cmp_eq_res") }
    case "LLVM.i_neq": return { return LLVMBuildICmp(builder, LLVMIntNE, $0, $1, "cmp_neq_res") }
        
        
    case "LLVM.b_and": return { return LLVMBuildAnd(builder, $0, $1, "cmp_and_res") }
    case "LLVM.b_or": return { return LLVMBuildOr(builder, $0, $1, "cmp_or_res") }
        
        
    case "LLVM.f_add": return { LLVMBuildFAdd(builder, $0, $1, "add_res") }
    case "LLVM.f_sub": return { LLVMBuildFSub(builder, $0, $1, "sub_res") }
    case "LLVM.f_mul": return { LLVMBuildFMul(builder, $0, $1, "mul_res") }
    case "LLVM.f_div": return { LLVMBuildFDiv(builder, $0, $1, "div_res") }
    case "LLVM.f_rem": return { LLVMBuildFRem(builder, $0, $1, "rem_res") }
        
    case "LLVM.f_cmp_lt": return { return LLVMBuildFCmp(builder, LLVMRealOLT, $0, $1, "cmp_lt_res") }
    case "LLVM.f_cmp_lte": return { return LLVMBuildFCmp(builder, LLVMRealOLE, $0, $1, "cmp_lte_res") }
    case "LLVM.f_cmp_gt": return { return LLVMBuildFCmp(builder, LLVMRealOGT, $0, $1, "cmp_gt_res") }
    case "LLVM.f_cmp_gte": return { return LLVMBuildFCmp(builder, LLVMRealOGE, $0, $1, "cmp_gte_res") }
    case "LLVM.f_eq": return { return LLVMBuildFCmp(builder, LLVMRealOEQ, $0, $1, "cmp_eq_res") }
    case "LLVM.f_neq": return { return LLVMBuildFCmp(builder, LLVMRealONE, $0, $1, "cmp_neq_res") }
        
    default: return nil
    }
}

func builtinInstruction(named: String, builder: LLVMBuilderRef, module: LLVMModuleRef) -> (() -> LLVMValueRef)? {

    switch named {
    case "LLVM.trap": return {
        let l = getIntrinsic("llvm.trap", module, nil)
        
        let args = [].ptr()
        defer { args.dealloc(0) }
        
        return LLVMBuildCall(builder, l, args, 0, "")
        }
        
    default:
        return nil
    }
    
}
