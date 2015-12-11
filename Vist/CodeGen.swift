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
    case NotIRGenerator, NotBBGenerator, NoOperator, MisMatchedTypes, NoLLVMFloat(UInt32), WrongFunctionApplication(String), NoLLVMType, NoBody, InvalidFunction, NoVariable(String)
}


var builder: LLVMBuilderRef = nil
var module: LLVMModuleRef = nil


// TODO: split up this protocol
/// A type which can generate LLVM IR code
protocol IRGenerator {
    func codeGen(scope: Scope) throws -> LLVMValueRef
    func llvmType(scope: Scope) throws -> LLVMTypeRef
}

protocol BasicBlockGenerator {
    func bbGen(parentScope parentScope: Scope, functionScope scope: Scope, fn: LLVMValueRef, args: UnsafeMutablePointer<LLVMTypeRef>) throws -> LLVMBasicBlockRef
}






//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Helpers
//-------------------------------------------------------------------------------------------------------------------------


private func isFloatType(t: LLVMTypeKind) -> Bool {
    return [LLVMFloatTypeKind, LLVMDoubleTypeKind, LLVMHalfTypeKind, LLVMFP128TypeKind].contains(t)
}

private extension Expression {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        if let x = try (self as? IRGenerator)?.codeGen(scope) { return x } else { throw IRError.NotIRGenerator }
    }
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        if let x = try (self as? IRGenerator)?.llvmType(scope) { return x } else { throw IRError.NotIRGenerator }
    }
    
    func bbGen(parentScope parentScope: Scope, functionScope scope: Scope, fn: LLVMValueRef, args: UnsafeMutablePointer<LLVMTypeRef>) throws -> LLVMBasicBlockRef {
        if let x = try (self as? BasicBlockGenerator)?.bbGen(parentScope: parentScope, functionScope: scope, fn: fn, args: args) { return x } else { throw IRError.NotBBGenerator }
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
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        return LLVMConstInt(try llvmType(scope), UInt64(val), LLVMBool(true))
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return LLVMIntType(size)
    }
}

extension FloatingPointLiteral: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        return LLVMConstReal(try llvmType(scope), val)
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
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
    
    func codeGen(scope: Scope) -> LLVMValueRef {
        return LLVMConstInt(LLVMInt1Type(), UInt64(val.hashValue), LLVMBool(false))
    }
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return LLVMInt1Type()
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Variable: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        return try scope.variable(name ?? "")
    }
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return try scope.variableType(name ?? "")
    }
}

extension Assignment: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        // create value
        let v = try value.codeGen(scope)
        
        // create ptr
        let type = LLVMTypeOf(v)
        let ptr = LLVMBuildAlloca(builder, type, name)
        // Load in memory
        let stored = LLVMBuildStore(builder, v, ptr)
        
        // update scope variables
        scope.addVariable(name, val: v)
        
        return stored
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return nil
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Expressions
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpression: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        let lIR = try lhs.codeGen(scope), rIR = try rhs.codeGen(scope)
        
        let type = try llvmType(scope)
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
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        let a = try lhs.llvmType(scope)
        let b = try lhs.llvmType(scope)
        
        if a == b { return a } else { throw IRError.MisMatchedTypes }
    }
    
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------


extension FunctionCall: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        // make function
        let fn = LLVMGetNamedFunction(module, name)
        let argCount = args.elements.count
        
        // arguments
        let argBuffer = try args.elements.map { try $0.codeGen(scope) }.ptr()
        defer { argBuffer.dealloc(argCount) }

        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else { throw IRError.WrongFunctionApplication(name) }
        
        // add call to IR
        let call = LLVMBuildCall(builder, fn, argBuffer, UInt32(argCount), name)
        
        return call
    }
    
    func llvmType(scope: Scope) -> LLVMTypeRef {
        let fn = LLVMGetNamedFunction(module, name)
        return LLVMGetReturnType(fn)
    }
    
}


// function definition
extension FunctionPrototype: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        let args = type.args, returns = type.returns, argCount = args.elements.count
        
        // If existing function definition
        let _fn = LLVMGetNamedFunction(module, name)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(argCount) && LLVMCountBasicBlocks(_fn) != 0 {
            return _fn
        }
        
        // Set params
        let argBuffer = UnsafeMutablePointer<LLVMTypeRef>.alloc(argCount)
        defer { argBuffer.dealloc(argCount) }
        
        for i in 0..<argCount {
//            let argument = args.elements[i]
            // TODO: set param type to something else & use .ptr()
            argBuffer.advancedBy(i).initialize(LLVMInt64Type())
        }
        
        // make function
        
        // TODO: set return type to something else
        let functionType = LLVMFunctionType(LLVMInt64Type(), argBuffer, UInt32(argCount), LLVMBool(false))
        let function = LLVMAddFunction(module, name, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        let functionScope = Scope()
        
        // set function param names and update table
        for i in 0..<UInt32(argCount) {
            let param = LLVMGetParam(function, i)
            let name = (impl?.params.elements[Int(i)] as? ValueType)?.name ?? ("fn\(self.name)_param\(i)")
            
            LLVMSetValueName(param, name)
            functionScope.addVariable(name, val: param)
        }
        
        // generate bb for body
        do {
            try impl?.body.bbGen(parentScope: scope, functionScope: functionScope, fn: function, args: argBuffer)
        } catch {
            LLVMDeleteFunction(function)
            throw error
        }
        
        return function
    }
    
    func llvmType(scope: Scope) -> LLVMTypeRef {
        return nil
    }
    
}


extension ReturnExpression: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        let v = try expression.codeGen(scope)
        return LLVMBuildRet(builder, v)
    }
    
    func llvmType(scope: Scope) -> LLVMTypeRef {
        return nil
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Control flow
//-------------------------------------------------------------------------------------------------------------------------










//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 BB Gen
//-------------------------------------------------------------------------------------------------------------------------


extension AST {
    func IRGen() throws -> LLVMBasicBlockRef {
        
        builder = LLVMCreateBuilder()
        module = LLVMModuleCreateWithName("vist_module")
        
        let argBuffer = [LLVMInt32Type()].ptr()
        defer { argBuffer.dealloc(1) }
        
        let functionType = LLVMFunctionType(LLVMInt32Type(), argBuffer, UInt32(1), LLVMBool(false))
        let mainFunction = LLVMAddFunction(module, "main", functionType)
        
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        
        let scope = Scope(vars: [:], block: programEntryBlock)
        
        for exp in expressions {
            try exp.codeGen(scope)
        }
        
        // TODO: Move main function to the end of funtions
        
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        LLVMBuildRet(builder, LLVMConstInt(LLVMInt32Type(), 0, LLVMBool(false)))
        
        return module
    }
}



extension Block: BasicBlockGenerator {
    
    func bbGen(parentScope parentScope: Scope, functionScope scope: Scope, fn: LLVMValueRef, args: UnsafeMutablePointer<LLVMTypeRef>) throws -> LLVMBasicBlockRef {
        
        let entryBlock = LLVMAppendBasicBlock(fn, "entry")
        LLVMPositionBuilderAtEnd(builder, entryBlock)
        
        scope.block = entryBlock
        
        for exp in expressions {
            try exp.codeGen(scope)
        }
        
        LLVMPositionBuilderAtEnd(builder, parentScope.block)
        return entryBlock
    }
    
}












