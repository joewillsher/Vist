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
    case NotIRGenerator, NotBBGenerator, NoOperator, MisMatchedTypes, NoLLVMFloat(UInt32), WrongFunctionApplication(String), NoLLVMType, NoBody, InvalidFunction, NoVariable(String), NoBool
}


// global builder and module references
private var builder: LLVMBuilderRef = nil
private var module: LLVMModuleRef = nil


/// A type which can generate LLVM IR code
protocol IRGenerator {
    func codeGen(scope: Scope) throws -> LLVMValueRef
    func llvmType(scope: Scope) throws -> LLVMTypeRef
}

protocol BasicBlockGenerator {
    func bbGen(innerScope scope: Scope, fn: LLVMValueRef) throws -> LLVMBasicBlockRef
}






//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Helpers
//-------------------------------------------------------------------------------------------------------------------------


private func isFloatType(t: LLVMTypeKind) -> Bool {
    return [LLVMFloatTypeKind, LLVMDoubleTypeKind, LLVMHalfTypeKind, LLVMFP128TypeKind].contains(t)
}

extension Expression {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        if let x = try (self as? IRGenerator)?.codeGen(scope) { return x } else {
            
            throw IRError.NotIRGenerator }
    }
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        if let x = try (self as? IRGenerator)?.llvmType(scope) { return x } else { throw IRError.NotIRGenerator }
    }
    
    func bbGen(innerScope scope: Scope, fn: LLVMValueRef) throws -> LLVMBasicBlockRef {
        if let x = try (self as? BasicBlockGenerator)?.bbGen(innerScope: scope, fn: fn) { return x } else { throw IRError.NotBBGenerator }
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
            case "+": return LLVMBuildAdd(builder, lIR, rIR, "add_res")
            case "-": return LLVMBuildSub(builder, lIR, rIR, "sub_res")
            case "*": return LLVMBuildMul(builder, lIR, rIR, "mul_res")
            case "/": return LLVMBuildUDiv(builder, lIR, rIR, "div_res")
            case "%": return LLVMBuildURem(builder, lIR, rIR, "rem_res")
            case "&&": return LLVMBuildAnd(builder, lIR, rIR, "and_res")
            case "||": return LLVMBuildOr(builder, lIR, rIR, "or_res")
            case "<": return LLVMBuildICmp(builder, LLVMIntSLT, lIR, rIR, "cmp_lt_res")
            case ">": return LLVMBuildICmp(builder, LLVMIntSGT, lIR, rIR, "cmp_gt_res")
            default: throw IRError.NoOperator
            }
            
            // TODO: ==, !=, >=, <=

        } else if isFloatType(LLVMGetTypeKind(type)) {
            
            switch op {
            case "+": return LLVMBuildFAdd(builder, lIR, rIR, "fadd_res")
            case "-": return LLVMBuildFSub(builder, lIR, rIR, "fsub_res")
            case "*": return LLVMBuildFMul(builder, lIR, rIR, "fmul_res")
            case "/": return LLVMBuildFDiv(builder, lIR, rIR, "fdiv_res")
            case "%": return LLVMBuildFRem(builder, lIR, rIR, "frem_res")
            case "<": return LLVMBuildFCmp(builder, LLVMRealOLT, lIR, rIR, "fcmp_lt_res")
            case ">": return LLVMBuildFCmp(builder, LLVMRealOGT, lIR, rIR, "fcmp_gt_res")
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
        
        // scope internal to function, needs params setting and then the block should be added *inside* the bbGen function
        let functionScope = Scope(function: function, parentScope: scope)
        
        // set function param names and update table
        for i in 0..<UInt32(argCount) {
            let param = LLVMGetParam(function, i)
            let name = (impl?.params.elements[Int(i)] as? ValueType)?.name ?? ("fn\(self.name)_param\(i)")
            
            LLVMSetValueName(param, name)
            functionScope.addVariable(name, val: param)
        }
        
        // generate bb for body
        do {
            try impl?.body.bbGen(innerScope: functionScope, fn: function)
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


private func ifBBID(n n: Int, ex: ElseIfBlock) -> String? {
    return ex.condition == nil ? "\(n)else_bb" : "\(n)then_bb"
}

extension ConditionalExpression: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        let entryBlock = scope.block
        
        let statement = statements[0]
        
        
        
        
        
        
        guard let cond = try statement.condition?.codeGen(scope) else { throw IRError.NoBool }
        
        let contBlock = LLVMAppendBasicBlock(scope.function, "cont")
        
        let thenBlock = try statement.bbGen(innerScope: scope, contBlock: contBlock, name: "then")
//        let elseBlock = try statement.bbGen(innerScope: scope, contBlock: contBlock)
        
        
        
        LLVMPositionBuilderAtEnd(builder, entryBlock)

        LLVMBuildCondBr(builder, cond, thenBlock, contBlock)
        
        
        LLVMPositionBuilderAtEnd(builder, contBlock)

        scope.block = contBlock
        
        return nil
    }
    
    
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return nil
    }
}


extension ElseIfBlock {
    
    private func bbGen(innerScope scope: Scope, contBlock: LLVMBasicBlockRef, name: String) throws -> LLVMBasicBlockRef {
        
        let basicBlock = LLVMAppendBasicBlock(scope.function, name)
        LLVMPositionBuilderAtEnd(builder, basicBlock)

        
        for exp in block.expressions {
            try exp.codeGen(scope)
        }
        
        
        // move to cont block
        
        LLVMBuildBr(builder, contBlock)
        
        LLVMPositionBuilderAtEnd(builder, scope.block)
        
        return basicBlock
    }
    
    
}







//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 BB Gen
//-------------------------------------------------------------------------------------------------------------------------


extension AST {
    func IRGen() throws -> LLVMBasicBlockRef {
        
        // initialise global objects
        builder = LLVMCreateBuilder()
        module = LLVMModuleCreateWithName("vist_module")
        
        // main arguments
        let argBuffer = [LLVMInt32Type()].ptr()
        defer { argBuffer.dealloc(1) }
        
        // make main function & add to IR
        let functionType = LLVMFunctionType(LLVMInt32Type(), argBuffer, UInt32(1), LLVMBool(false))
        let mainFunction = LLVMAddFunction(module, "main", functionType)
        
        // Setup BB & scope
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        let scope = Scope(block: programEntryBlock, function: mainFunction)
        
        for exp in expressions {
            try exp.codeGen(scope)
        }
        
        // TODO: Move main function to the end of funtions
        
        LLVMBuildRet(builder, LLVMConstInt(LLVMInt32Type(), 0, LLVMBool(false)))
        
        return module
    }
}



extension Block: BasicBlockGenerator {
    
    func bbGen(innerScope scope: Scope, fn: LLVMValueRef) throws -> LLVMBasicBlockRef {
        
        // setup function block
        let entryBlock = LLVMAppendBasicBlock(fn, "entry")
        LLVMPositionBuilderAtEnd(builder, entryBlock)
        
        scope.block = entryBlock
        
        // code gen for function
        for exp in expressions {
            try exp.codeGen(scope)
        }
        
        // reset builder head tp parent scope
        LLVMPositionBuilderAtEnd(builder, scope.parentScope!.block)
        return entryBlock
    }
    
}












