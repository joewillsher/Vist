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
    case NotIRGenerator, NoOperator, MisMatchedTypes, NoLLVMFloat(UInt32), WrongFunctionApplication(String), NoLLVMType
}

private var runtimeVariables: [String: LLVMTypeRef] = [:]
private var funtionTable: [String: FunctionType] = [:]
private let builder = LLVMCreateBuilder()
private let context = LLVMGetGlobalContext()
private let module = LLVMModuleCreateWithName("vist_module")


/// A type which can generate LLVM IR code
protocol IRGenerator {
    func codeGen() throws -> LLVMValueRef
    func llvmType() throws -> LLVMTypeRef
}

extension IRGenerator {
    func llvmType() throws -> LLVMTypeRef { throw IRError.NoLLVMType }
}


extension IntegerLiteral: IRGenerator {
    
    func codeGen() throws -> LLVMValueRef {
        return LLVMConstInt(try llvmType(), UInt64(val), LLVMBool(true))
    }
    
    func llvmType() throws -> LLVMTypeRef {
        return LLVMIntType(size)
    }
}

extension FloatingPointLiteral: IRGenerator {
    
    func codeGen() throws -> LLVMValueRef {
        return LLVMConstReal(try llvmType(), val)
    }
    
    func llvmType() throws -> LLVMTypeRef {
        switch size {
        case 16: return LLVMHalfType()
        case 32: return LLVMFloatType()
        case 64: return LLVMDoubleType()
        case 128: return LLVMPPCFP128Type()
        default: throw IRError.NoLLVMFloat(size)
        }
    }
}

extension BooleanLiteral: IRGenerator {
    
    func codeGen() -> LLVMValueRef {
        return LLVMConstInt(LLVMInt1Type(), UInt64(val.hashValue), LLVMBool(false))
    }
    func llvmType() throws -> LLVMTypeRef {
        return LLVMInt1Type()
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

//extension Tuple: IRGenerator {
//    
//    func codeGen() throws -> LLVMValueRef {
//        
//        let arr = try elements.map { item -> LLVMValueRef in
//            guard let a = item as? IRGenerator else { throw IRError.NotIRGenerator }
//            return try a.codeGen()
//        }
//        
//        return COpaquePointer(arr.withUnsafeBufferPointer{ $0.baseAddress })
//    }
//}

extension FunctionCall: IRGenerator {
    
    func codeGen() throws -> LLVMValueRef {
        
        let fn = LLVMGetNamedFunction(module, name)
        let argCount = args.elements.count
        
        let argBuffer = UnsafeMutablePointer<LLVMValueRef>.alloc(argCount)
        
        for i in 0..<args.elements.count {
            
            let argument = args.elements[i]
            guard let val = try (argument as? IRGenerator)?.codeGen() else { throw IRError.NotIRGenerator }
            
            argBuffer.advancedBy(i).initialize(val)
        }

        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else { throw IRError.WrongFunctionApplication(name) }
        
        let call = LLVMBuildCall(builder, fn, argBuffer, UInt32(argCount), name)
        // name params
        return call
    }
    
}

extension FunctionImplementation: IRGenerator {
    
    func codeGen() throws -> LLVMValueRef {
        return nil
    }
}

// function definition
extension FunctionPrototype: IRGenerator {
    
    func codeGen() throws -> LLVMValueRef {
        
        let args = type.args, returns = type.returns, argCount = args.elements.count
        
        // If existing function definition
        let _fn = LLVMGetNamedFunction(module, name)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(argCount) && LLVMCountBasicBlocks(_fn) != 0 {
            return _fn
        }
        
        let argBuffer = UnsafeMutablePointer<LLVMTypeRef>.alloc(argCount)
        
        for i in 0..<argCount {
            let argument = args.elements[i]
            // not just float, get type of elements
            argBuffer.advancedBy(i).initialize(LLVMDoubleType())
        }
        
        // set return type to something else
        let functionType = LLVMFunctionType(LLVMDoubleType(), argBuffer, UInt32(argCount), LLVMBool(false))
        let fn = LLVMAddFunction(module, name, functionType)
        LLVMSetLinkage(fn, LLVMExternalLinkage);
        
        for i in 0..<UInt32(argCount) {
            let param = LLVMGetParam(fn, i)            
            let name = (impl?.params.elements[Int(i)] as? ValueType)?.name ?? ("fn\(fn)_param\(i)")
            LLVMSetValueName(param, name)
            runtimeVariables[name] = param
        }
        
        return fn
    }
}





extension AST: IRGenerator {
    func codeGen() throws -> LLVMValueRef {
        
        for (i, exp) in expressions.enumerate() {
            if let v = try (exp as? IRGenerator)?.codeGen() {

//                LLVMAppendBasicBlockInContext(context, v, "ast_exp_\(i)")
                LLVMDumpValue(v)
            }
        }
        
        return LLVMBuildRetVoid(builder)
    }
}






