//
//  CodeGen.swift
//  Vist
//
//  Created by Josef Willsher on 15/11/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation
import LLVM

enum IRError: ErrorType {
    case NotIRGenerator, NoOperator, MisMatchedTypes, NoLLVMFloat(UInt32)
}

private var runtimeVariables: [String: LLVMTypeRef] = [:]
private let builder = LLVMCreateBuilder()
private let context = LLVMGetGlobalContext()
private let module = LLVMModuleCreateWithName("vist_module")


/// A type which can generate LLVM IR code
protocol IRGenerator {
    func codeGen() throws -> LLVMValueRef
}


extension IntegerLiteral: IRGenerator {
    
    func codeGen() -> LLVMValueRef {
        return LLVMConstInt(LLVMIntType(size), UInt64(val), LLVMBool(true))
    }
}

extension FloatingPointLiteral: IRGenerator {
    
    func codeGen() throws -> LLVMValueRef {
        switch size {
        case 16: return LLVMConstReal(LLVMHalfType(), val)
        case 32: return LLVMConstReal(LLVMFloatType(), val)
        case 64: return LLVMConstReal(LLVMDoubleType(), val)
        case 128: return LLVMConstReal(LLVMPPCFP128Type(), val)
        default: throw IRError.NoLLVMFloat(size)
        }
    }
}

extension BooleanLiteral: IRGenerator {
    
    func codeGen() -> LLVMValueRef {
        return LLVMConstInt(LLVMInt1Type(), UInt64(val.hashValue), LLVMBool(false))
    }
}

extension Variable: IRGenerator {
    
    func codeGen() -> LLVMValueRef {
        return runtimeVariables[name!]!
    }
}

extension BinaryExpression: IRGenerator {
    
    func codeGen() throws -> LLVMValueRef {
        
        guard let l = lhs as? IRGenerator, let r = rhs as? IRGenerator else { throw IRError.NotIRGenerator }
        let lIR = try l.codeGen(), rIR = try r.codeGen()
                
        if lhs is FloatingPointType && rhs is FloatingPointType {
            
            switch op {
            case "+": return LLVMBuildFAdd(builder, lIR, rIR, "addftmp")
            case "-": return LLVMBuildFSub(builder, lIR, rIR, "subftmp")
            case "*": return LLVMBuildFMul(builder, lIR, rIR, "mulftmp")
            case "/": return LLVMBuildFDiv(builder, lIR, rIR, "divftmp")
            case "%": return LLVMBuildFRem(builder, lIR, rIR, "remftmp")
            default: throw IRError.NoOperator
            }
        
        } else if lhs is IntegerType && rhs is IntegerType {
            
            switch op {
            case "+": return LLVMBuildAdd(builder, lIR, rIR, "addtmp")
            case "-": return LLVMBuildSub(builder, lIR, rIR, "subtmp")
            case "*": return LLVMBuildMul(builder, lIR, rIR, "multmp")
            case "/": return LLVMBuildUDiv(builder, lIR, rIR, "divtmp")
            case "%": return LLVMBuildURem(builder, lIR, rIR, "remftmp")
            default: throw IRError.NoOperator
            }
            
        } else if lhs is BooleanType && rhs is BooleanType {
            
            switch op {
            case "&&": return LLVMBuildAnd(builder, lIR, rIR, "andtmp")
            case "||": return LLVMBuildOr(builder, lIR, rIR, "ortmp")
            default: throw IRError.NoOperator
            }
        
        } else {
            throw IRError.MisMatchedTypes
        }
        
    }
}

extension Assignment: IRGenerator {
    
    
    // assignment returns nil & updates the runtime variables list
    func codeGen() throws -> LLVMValueRef {
        
        guard let val = value as? IRGenerator else { throw IRError.NotIRGenerator }
        let v = try val.codeGen()
        
        runtimeVariables[name] = v
        
        return LLVMBuildRetVoid(builder)
    }
    
}

extension AST: IRGenerator {
    func codeGen() throws -> LLVMValueRef {
        
        for exp in expressions {
            if let v = try (exp as? IRGenerator)?.codeGen() {
                LLVMDumpValue(v)
            }
        }
        
        return LLVMBuildRetVoid(builder)
    }
}






