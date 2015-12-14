//
//  CodeGen.swift
//  Vist
//
//  Created by Josef Willsher on 15/11/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation
//import LLVM

enum IRError: ErrorType {
    case NotIRGenerator, NotBBGenerator, NoOperator, MisMatchedTypes, NoLLVMFloat(UInt32), WrongFunctionApplication(String), NoLLVMType, NoBody, InvalidFunction, NoVariable(String), NoBool, TypeNotFound
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

private var typeDict: [String: LLVMTypeRef] = [
    "Int": LLVMInt64Type(),
    "Int64": LLVMInt64Type(),
    "Int32": LLVMInt32Type(),
    "Int16": LLVMInt16Type(),
    "Int8": LLVMInt8Type(),
    "Bool": LLVMInt1Type(),
    "Double": LLVMDoubleType(),
    "Float": LLVMFloatType(),
    "Void": LLVMVoidType(),
]




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Helpers
//-------------------------------------------------------------------------------------------------------------------------


private func isFloatType(t: LLVMTypeKind) -> Bool {
    return [LLVMFloatTypeKind, LLVMDoubleTypeKind, LLVMHalfTypeKind, LLVMFP128TypeKind].contains(t)
}

extension Expression {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        if let x = try (self as? IRGenerator)?.codeGen(scope) { return x } else { throw IRError.NotIRGenerator }
    }
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        if let x = try (self as? IRGenerator)?.llvmType(scope) { return x } else { throw IRError.NotIRGenerator }
    }
    
    func bbGen(innerScope scope: Scope, fn: LLVMValueRef) throws -> LLVMBasicBlockRef {
        if let x = try (self as? BasicBlockGenerator)?.bbGen(innerScope: scope, fn: fn) { return x } else { throw IRError.NotBBGenerator }
    }
}

extension CollectionType where
    Generator.Element == COpaquePointer,
    Index == Int,
    Index.Distance == Int {
    
    /// get a ptr to the memory of the collection
    func ptr() -> UnsafeMutablePointer<Generator.Element> {
        
        let p = UnsafeMutablePointer<Generator.Element>.alloc(count)
        
        for i in self.startIndex..<self.endIndex {
            p.advancedBy(i).initialize(self[i])
        }
        
        return p
    }
    
}

extension LLVMBool {
    init(_ b: Bool) {
        self.init(b ? 1 : 0)
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
            case "<=": return LLVMBuildICmp(builder, LLVMIntSLE, lIR, rIR, "cmp_lte_res")
            case ">=": return LLVMBuildICmp(builder, LLVMIntSGE, lIR, rIR, "cmp_gte_res")
            case "==": return LLVMBuildICmp(builder, LLVMIntEQ, lIR, rIR, "cmp_eq_res")
            case "!=": return LLVMBuildICmp(builder, LLVMIntNE, lIR, rIR, "cmp_neq_res")
            default: throw IRError.NoOperator
            }

        } else if isFloatType(LLVMGetTypeKind(type)) {
            
            switch op {
            case "+": return LLVMBuildFAdd(builder, lIR, rIR, "fadd_res")
            case "-": return LLVMBuildFSub(builder, lIR, rIR, "fsub_res")
            case "*": return LLVMBuildFMul(builder, lIR, rIR, "fmul_res")
            case "/": return LLVMBuildFDiv(builder, lIR, rIR, "fdiv_res")
            case "%": return LLVMBuildFRem(builder, lIR, rIR, "frem_res")
            case "<": return LLVMBuildFCmp(builder, LLVMRealOLT, lIR, rIR, "fcmp_lt_res")
            case ">": return LLVMBuildFCmp(builder, LLVMRealOGT, lIR, rIR, "fcmp_gt_res")
            case "<=": return LLVMBuildFCmp(builder, LLVMRealOLE, lIR, rIR, "cmp_lte_res")
            case ">=": return LLVMBuildFCmp(builder, LLVMRealOGE, lIR, rIR, "cmp_gte_res")
            case "==": return LLVMBuildFCmp(builder, LLVMRealOEQ, lIR, rIR, "cmp_eq_res")
            case "!=": return LLVMBuildFCmp(builder, LLVMRealONE, lIR, rIR, "cmp_neq_res")
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

extension Void: IRGenerator {
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return LLVMVoidType()
    }
}

extension Comment: IRGenerator {
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        return nil
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
        return LLVMBuildCall(builder, fn, argBuffer, UInt32(argCount), "")
    }
    
    func llvmType(scope: Scope) -> LLVMTypeRef {
        let fn = LLVMGetNamedFunction(module, name)
        let ty = LLVMTypeOf(fn)
        return LLVMGetReturnType(ty)
    }
    
}

extension FunctionType {
    
    
    func params() throws -> [LLVMTypeRef] {
        let res = args.mapAs(ValueType).flatMap { typeDict[$0.name] }
        if res.count == args.elements.count { return res } else { throw IRError.TypeNotFound }
    }
    
    func returnType() throws -> LLVMTypeRef {
        let res = returns.mapAs(ValueType).flatMap { typeDict[$0.name] }
        if res.count == returns.elements.count && res.count == 0 { return LLVMVoidType() }
        if let f = res.first where res.count == returns.elements.count { return f } else { throw IRError.TypeNotFound }
    }
    
}



// function definition
extension FunctionPrototype: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        let args = type.args, argCount = args.elements.count
        
        // If existing function definition
        let _fn = LLVMGetNamedFunction(module, name)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(argCount) && LLVMCountBasicBlocks(_fn) != 0 {
            return _fn
        }
        
        // Set params
        let argBuffer = try type.params().ptr()
        defer { argBuffer.dealloc(argCount) }
        
        // make function
        let functionType = LLVMFunctionType(try type.returnType(), argBuffer, UInt32(argCount), LLVMBool(false))
        let function = LLVMAddFunction(module, name, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        // scope internal to function, needs params setting and then the block should be added *inside* the bbGen function
        let functionScope = Scope(function: function, parentScope: scope)
        
        // set function param names and update table
        for i in 0..<argCount {
            let param = LLVMGetParam(function, UInt32(i))
            let name = (impl?.params.elements[i] as? ValueType)?.name ?? ("$\(i)")
            
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
        
        if try expression.llvmType(scope) == LLVMVoidType() {
            return LLVMBuildRetVoid(builder)
        }
        
        let v = try expression.codeGen(scope)
        return LLVMBuildRet(builder, v)
    }
    
    func llvmType(scope: Scope) -> LLVMTypeRef {
        return nil
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
        
        if expressions.isEmpty {
            LLVMBuildRetVoid(builder)
        }
        
        // reset builder head tp parent scope
        LLVMPositionBuilderAtEnd(builder, scope.parentScope!.block)
        return entryBlock
    }
    
}






//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Control flow
//-------------------------------------------------------------------------------------------------------------------------


private func ifBBID(n n: Int, ex: ElseIfBlock) -> String {
    return ex.condition == nil ? "else\(n)" : "then\(n)"
}

extension ConditionalExpression: IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        // TODO: if cond is true/fasle at compile remove jump
        
        // block leading into and out of current if block
        var ifIn: LLVMBasicBlockRef = scope.block
        var ifOut: LLVMBasicBlockRef = nil
        
        let leaveIf = LLVMAppendBasicBlock(scope.function, "cont")
        
        for (i, statement) in statements.enumerate() {
            
            LLVMPositionBuilderAtEnd(builder, ifIn)
            
            // condition
            let cond = try statement.condition?.codeGen(scope)
            if i < statements.count-1 {
                ifOut = LLVMAppendBasicBlock(scope.function, "cont\(i)")
            } else {
                ifOut = leaveIf
            }
            
            // block and associated scope
            let tScope = Scope(function: scope.function, parentScope: scope)
            let block = try statement.bbGen(innerScope: tScope, contBlock: leaveIf, name: ifBBID(n: i, ex: statement))
            
            // move builder to in scope
            LLVMPositionBuilderAtEnd(builder, ifIn)
            
            if let cond = cond { //if statement, make conditonal jump
                LLVMBuildCondBr(builder, cond, block, ifOut)
            } else { // else statement, uncondtional jump
                LLVMBuildBr(builder, block)
                break
            }
            
            ifIn = ifOut
        }
        
        LLVMPositionBuilderAtEnd(builder, leaveIf)
        scope.block = ifOut
        
        return nil
    }
    
    
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return nil
    }
}


extension ElseIfBlock {
    
    /// Create the basic block for the if expression
    private func bbGen(innerScope scope: Scope, contBlock: LLVMBasicBlockRef, name: String) throws -> LLVMBasicBlockRef {
        
        // add block
        let basicBlock = LLVMAppendBasicBlock(scope.function, name)
        LLVMPositionBuilderAtEnd(builder, basicBlock)
        
        // parse code
        for exp in block.expressions {
            try exp.codeGen(scope)
        }
        
        // move to cont block
        LLVMBuildBr(builder, contBlock)
        LLVMPositionBuilderAtEnd(builder, contBlock)
        
        return basicBlock
    }
    
    
}







//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 AST Gen
//-------------------------------------------------------------------------------------------------------------------------


extension AST {
    func IRGen(module m: LLVMModuleRef) throws {
        
        // initialise global objects
        builder = LLVMCreateBuilder()
        module = m
        
        // main arguments
        let argBuffer = [LLVMTypeRef]().ptr()
        defer { argBuffer.dealloc(0) }
        
        // make main function & add to IR
        let functionType = LLVMFunctionType(LLVMInt32Type(), argBuffer, UInt32(0), LLVMBool(false))
        let mainFunction = LLVMAddFunction(module, "main", functionType)
        
        // Setup BB & scope
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        let scope = Scope(block: programEntryBlock, function: mainFunction)
        
        for exp in expressions {
            try exp.codeGen(scope)
        }
                
        LLVMBuildRet(builder, LLVMConstInt(LLVMInt32Type(), 0, LLVMBool(false)))
    }
}












