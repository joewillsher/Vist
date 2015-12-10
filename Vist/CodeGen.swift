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
    case NotIRGenerator, NotBBGenerator, NoOperator, MisMatchedTypes, NoLLVMFloat(UInt32), WrongFunctionApplication(String), NoLLVMType, NoBody, InvalidFunction
}


// TODO: Scope manager
private var runtimeVariables: [String: LLVMValueRef] = [:]
private var runtimeVariableTypes: [String: LLVMTypeRef] = [:]


// TODO: split up this protocol
/// A type which can generate LLVM IR code
protocol IRGenerator {
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef
}

protocol BasicBlockGenerator {
    func bbGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, _ bb: LLVMBasicBlockRef, fn: LLVMValueRef, args: UnsafeMutablePointer<LLVMTypeRef>) throws -> LLVMBasicBlockRef
}






//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Helpers
//-------------------------------------------------------------------------------------------------------------------------


private func assignVariable(obj: LLVMTypeRef, name: String) {
    runtimeVariables[name] = obj
    runtimeVariableTypes[name] = LLVMTypeOf(obj)
}

private func removeVariable(name: String) {
    runtimeVariables[name] = nil
    runtimeVariableTypes[name] = nil
}

private func isFloatType(t: LLVMTypeKind) -> Bool {
    return [LLVMFloatTypeKind, LLVMDoubleTypeKind, LLVMHalfTypeKind, LLVMFP128TypeKind].contains(t)
}

private extension Expression {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        if let x = try (self as? IRGenerator)?.codeGen(builder, module, bb: bb) { return x } else { throw IRError.NotIRGenerator }
    }
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef {
        if let x = try (self as? IRGenerator)?.llvmType(builder, module, bb: bb) { return x } else { throw IRError.NotIRGenerator }
    }
    
    func bbGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, _ bb: LLVMBasicBlockRef, fn: LLVMValueRef, args: UnsafeMutablePointer<LLVMTypeRef>) throws -> LLVMBasicBlockRef {
        if let x = try (self as? BasicBlockGenerator)?.bbGen(builder, module, bb, fn: fn, args: args) { return x } else { throw IRError.NotBBGenerator }
    }

}

private extension CollectionType where
    Generator.Element == COpaquePointer,
    Index == Int,
    Index.Distance == Int {
    
    func ptr() -> UnsafeMutablePointer<Generator.Element> {
        
        let p = UnsafeMutablePointer<Generator.Element>.alloc(count)
        
        for i in self.startIndex..<self.endIndex {
            p.advancedBy(i).initialize(self[i])
        }
        
        return p
    }
    
}









/**************************************************************************************************************************/
// MARK: -                                                 IR GEN

 
 

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Literals
//-------------------------------------------------------------------------------------------------------------------------


extension IntegerLiteral: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        return LLVMConstInt(try llvmType(builder, module, bb: bb), UInt64(val), LLVMBool(true))
    }
    
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef {
        return LLVMIntType(size)
    }
}

extension FloatingPointLiteral: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        return LLVMConstReal(try llvmType(builder, module, bb: bb), val)
    }
    
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef {
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
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) -> LLVMValueRef {
        return LLVMConstInt(LLVMInt1Type(), UInt64(val.hashValue), LLVMBool(false))
    }
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef {
        return LLVMInt1Type()
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Variable: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) -> LLVMValueRef {
        return runtimeVariables[name!]!
    }
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef {
        return runtimeVariableTypes[name!]!
    }
}

extension Assignment: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        
        // create value
        let v = try value.codeGen(builder, module, bb: bb)
        
        // create ptr
        let type = LLVMTypeOf(v)
        let ptr = LLVMBuildAlloca(builder, type, name)
        // Load in memory
        let stored = LLVMBuildStore(builder, v, ptr)
        
        // update tables
        runtimeVariableTypes[name] = type
        runtimeVariables[name] = v
        
        return stored
    }
    
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef {
        return LLVMTypeOf(try codeGen(builder, module, bb: bb))
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Expressions
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpression: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        
        let lIR = try lhs.codeGen(builder, module, bb: bb), rIR = try rhs.codeGen(builder, module, bb: bb)
        
        let type = try llvmType(builder, module, bb: bb)
        if LLVMGetTypeKind(type) == LLVMIntegerTypeKind {
            
            switch op {
            case "+": return LLVMBuildAdd(builder, lIR, rIR, "addtmp")
            case "-": return LLVMBuildSub(builder, lIR, rIR, "subtmp")
            case "*": return LLVMBuildMul(builder, lIR, rIR, "multmp")
            case "/": return LLVMBuildUDiv(builder, lIR, rIR, "divtmp")
            case "%": return LLVMBuildURem(builder, lIR, rIR, "remftmp")
            case "&&": return LLVMBuildAnd(builder, lIR, rIR, "andtmp")
            case "||": return LLVMBuildOr(builder, lIR, rIR, "ortmp")
            default: throw IRError.NoOperator
            }

        } else if isFloatType(LLVMGetTypeKind(type)) {
            
            switch op {
            case "+": return LLVMBuildFAdd(builder, lIR, rIR, "addftmp")
            case "-": return LLVMBuildFSub(builder, lIR, rIR, "subftmp")
            case "*": return LLVMBuildFMul(builder, lIR, rIR, "mulftmp")
            case "/": return LLVMBuildFDiv(builder, lIR, rIR, "divftmp")
            case "%": return LLVMBuildFRem(builder, lIR, rIR, "remftmp")
            default: throw IRError.NoOperator
            }

        } else {
            throw IRError.MisMatchedTypes
        }
        
    }
    
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMTypeRef {
        guard let l = lhs as? IRGenerator, let r = rhs as? IRGenerator else { throw IRError.NotIRGenerator }
        let a = try l.llvmType(builder, module, bb: bb)
        let b = try r.llvmType(builder, module, bb: bb)
        
        if a == b { return a } else { throw IRError.MisMatchedTypes }
    }
    
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------


extension FunctionCall: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        
        let fn = LLVMGetNamedFunction(module, name)
        let argCount = args.elements.count
        
        let argBuffer = try args.elements.map { try $0.codeGen(builder, module, bb: bb) }.ptr()
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else { throw IRError.WrongFunctionApplication(name) }
        
        let call = LLVMBuildCall(builder, fn, argBuffer, UInt32(argCount), name)
        
        return call
    }
    
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) -> LLVMTypeRef {
        return nil
    }
    
}


// function definition
extension FunctionPrototype: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        
        let args = type.args, returns = type.returns, argCount = args.elements.count
        
        // If existing function definition
        let _fn = LLVMGetNamedFunction(module, name)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(argCount) && LLVMCountBasicBlocks(_fn) != 0 {
            return _fn
        }
        
        // Set params
        let argBuffer = UnsafeMutablePointer<LLVMTypeRef>.alloc(argCount)
        
        for i in 0..<argCount {
//            let argument = args.elements[i]
            // TODO: set param type to something else and make this loop use the .ptr() method on `CollectionType`
            argBuffer.advancedBy(i).initialize(LLVMInt64Type())
        }
        
        // make function
        
        // TODO: set return type to something else
        let functionType = LLVMFunctionType(LLVMInt64Type(), argBuffer, UInt32(argCount), LLVMBool(false))
        let function = LLVMAddFunction(module, name, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        // set function param names and update table
        for i in 0..<UInt32(argCount) {
            let param = LLVMGetParam(function, i)
            let name = (impl?.params.elements[Int(i)] as? ValueType)?.name ?? ("fn\(self.name)_param\(i)")
            let type = llvmType(builder, module, bb: bb)
            
            LLVMSetValueName(param, name)
            runtimeVariables[name] = param
            runtimeVariableTypes[name] = type
        }
        
        // generate bb for body
        do {
            try impl?.body.bbGen(builder, module, bb, fn: function, args: argBuffer)
        } catch {
            LLVMDeleteFunction(function)
            throw error
        }
        
        return function
    }
    
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) -> LLVMTypeRef {
        return nil
    }

}


extension ReturnExpression: IRGenerator {
    
    func codeGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) throws -> LLVMValueRef {
        let v = try expression.codeGen(builder, module, bb: bb)
        return LLVMBuildRet(builder, v)
    }
    
    func llvmType(builder: LLVMBuilderRef, _ module: LLVMModuleRef, bb: LLVMBasicBlockRef) -> LLVMTypeRef {
        return nil
    }
    
}













//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 BB Gen
//-------------------------------------------------------------------------------------------------------------------------


extension AST {
    func ASTGen() throws -> LLVMBasicBlockRef {
        
        let builder = LLVMCreateBuilder()
        let module = LLVMModuleCreateWithName("vist_module")
        
        let argBuffer = [LLVMInt64Type()].ptr()
        
        let functionType = LLVMFunctionType(LLVMInt64Type(), argBuffer, UInt32(1), LLVMBool(false))
        let mainFunction = LLVMAddFunction(module, "main", functionType)
        
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        
        for exp in expressions {
            try exp.codeGen(builder, module, bb: programEntryBlock)
        }
        
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        LLVMBuildRet(builder, LLVMConstInt(LLVMInt64Type(), 0, LLVMBool(false)))
        
        print("\n\n")
        
        
        
        return module
    }
}



extension Block: BasicBlockGenerator {
    
    func bbGen(builder: LLVMBuilderRef, _ module: LLVMModuleRef, _ bb: LLVMBasicBlockRef, fn: LLVMValueRef, args: UnsafeMutablePointer<LLVMTypeRef>) throws -> LLVMBasicBlockRef {
        
        let entryBlock = LLVMAppendBasicBlock(fn, "entry")
        LLVMPositionBuilderAtEnd(builder, entryBlock)
        
        for exp in expressions {
            try exp.codeGen(builder, module, bb: entryBlock)
        }
        
        LLVMPositionBuilderAtEnd(builder, bb)
        return entryBlock
    }
    
}












