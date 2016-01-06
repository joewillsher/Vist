//
//  BuiltinFunction.swift
//  Vist
//
//  Created by Josef Willsher on 06/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation


func builtinInstruction(named: String, builder: LLVMBuilderRef) -> ((LLVMValueRef, LLVMValueRef) throws -> LLVMValueRef)? {
    switch named {
        
    case "LLVM.i_add":
        return {
            LLVMBuildAdd(builder, $0, $1, "add_res")
        }
        
    case "LLVM.i_mul":
        return {
            LLVMBuildMul(builder, $0, $1, "mul_res")
        }
        
    case "LLVM.f_add":
        return {
            LLVMBuildFAdd(builder, $0, $1, "add_res")
        }
        
    case "LLVM.f_mul":
        return {
            LLVMBuildFMul(builder, $0, $1, "mul_res")
        }
        
    default:
        return nil
    }
}
