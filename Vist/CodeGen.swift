//
//  CodeGen.swift
//  Vist
//
//  Created by Josef Willsher on 15/11/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

enum IRError : ErrorType {
    case NotIRGenerator, NotBBGenerator, NoOperator
    case MisMatchedTypes, NoLLVMFloat(UInt32), WrongFunctionApplication(String), NoLLVMType
    case NoBody, InvalidFunction, NoVariable(String), NoBool, TypeNotFound, NotMutable
    case CannotAssignToVoid, CannotAssignToType(Expression.Type)
    case ForLoopIteratorNotInt, NotBoolCondition, SubscriptingNonVariableTypeNotAllowed, SubscriptingNonArrayType, SubscriptOutOfBounds
}


// global builder and module references
private var builder: LLVMBuilderRef = nil
private var module: LLVMModuleRef = nil


/// A type which can generate LLVM IR code
private protocol IRGenerator {
    func codeGen(scope: Scope) throws -> LLVMValueRef
    func llvmType(scope: Scope) throws -> LLVMTypeRef
}

private protocol BasicBlockGenerator {
    func bbGen(innerScope scope: Scope, fn: LLVMValueRef) throws -> LLVMBasicBlockRef
}

private var typeDict: [String: LLVMTypeRef] = [
    "Int": LLVMInt64Type(),
    "Int64": LLVMInt64Type(),
    "Int32": LLVMInt32Type(),
//    "Int128": LLVMIntType(128), // no support in swift for literals of this size
//    "Int256": LLVMIntType(256),
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
    
    func expressionCodeGen(scope: Scope) throws -> LLVMValueRef {
        if let x = try (self as? IRGenerator)?.codeGen(scope) { return x }
        else { throw IRError.NotIRGenerator }
    }
    func expressionllvmType(scope: Scope) throws -> LLVMTypeRef {
        if let x = try (self as? IRGenerator)?.llvmType(scope) { return x }
        else { throw IRError.NotIRGenerator }
    }
    
    func expressionbbGen(innerScope scope: Scope, fn: LLVMValueRef) throws -> LLVMBasicBlockRef {
        if let x = try (self as? BasicBlockGenerator)?.bbGen(innerScope: scope, fn: fn) { return x } else { throw IRError.NotBBGenerator }
    }
}

extension IRGenerator {
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return nil
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


extension IntegerLiteral : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        return LLVMConstInt(try llvmType(scope), UInt64(val), LLVMBool(true))
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return LLVMIntType(size)
    }
}

extension FloatingPointLiteral : IRGenerator {
    
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

extension BooleanLiteral : IRGenerator {
    
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

extension Variable : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        let variable = try scope.variable(name ?? "")
        
        return variable.load(name ?? "")
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return try scope.variable(name ?? "").type
    }
}

extension AssignmentExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        if let arr = value as? ArrayExpression {
            //if asigning to array
            
            let a = try arr.arrInstance(scope)
            a.allocHead(builder, name: name, mutable: isMutable)
            scope.addVariable(name, val: a)
            
            return a.ptr
            
        } else {
            // all other types
            
            // create value
            let v = try value.expressionCodeGen(scope)
            
            // checks
            guard v != nil else { throw IRError.CannotAssignToType(value.dynamicType) }
            let type = LLVMTypeOf(v)
            guard type != LLVMVoidType() else { throw IRError.CannotAssignToVoid }
            
            // create variable
            let variable = ReferenceVariable.alloc(builder, type: type, name: name ?? "", mutable: isMutable)
            
            // Load in memory
            variable.store(v)
            
            // update scope variables
            scope.addVariable(name, val: variable)
            return v
        }
    }
}

extension MutationExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        if let object = object as? Variable {
            // object = newValue
            
            let variable = try scope.variable(object.name)
            
            
            if let arrayVariable = variable as? ArrayVariable, arrayExpression = value as? ArrayExpression {
                
                let newArray = try arrayExpression.arrInstance(scope)
                arrayVariable.assignFrom(builder, arr: newArray)
                
            } else {
                
                
                let new = try value.expressionCodeGen(scope)
                
                guard let v = variable as? MutableVariable where v.mutable else { throw IRError.NotMutable }
                v.store(new)
                
            }
        
        } else if let sub = object as? ArraySubscriptExpression {
            
            let arr = try sub.backingArrayVariable(scope)
            
            let i = try sub.index.expressionCodeGen(scope)
            let ptr = arr.ptrToElementAtIndex(i)
            
            let val = try value.expressionCodeGen(scope)
            
            LLVMBuildStore(builder, val, ptr)
        }
        
        return nil
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Expressions
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        let lIR = try lhs.expressionCodeGen(scope), rIR = try rhs.expressionCodeGen(scope)
        
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
        
        switch op {
        case "<", ">", "==", "!=", ">=", "<=":
            return LLVMInt1Type()
            
        default:
            let a = try lhs.expressionllvmType(scope)
            let b = try lhs.expressionllvmType(scope)
            
            if a == b { return a } else { throw IRError.MisMatchedTypes }
        }
        
    }
    
}

extension Void : IRGenerator {
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return LLVMVoidType()
    }
    private func codeGen(scope: Scope) throws -> LLVMValueRef {
        return nil
    }
}

extension CommentExpression : IRGenerator {
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        return nil
    }

}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------


extension FunctionCallExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        // make function
        let fn = LLVMGetNamedFunction(module, name)
        let argCount = args.elements.count
        
        // arguments
        let a = try args.elements.map { try $0.expressionCodeGen(scope) }
        let argBuffer = a.ptr()
        defer { argBuffer.dealloc(argCount) }
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else { throw IRError.WrongFunctionApplication(name) }
        
        // TODO: Check if return is nil and name otheriwse
        
        // add call to IR
        return LLVMBuildCall(builder, fn, argBuffer, UInt32(argCount), "")
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        let fn = LLVMGetNamedFunction(module, name)
        let ty = LLVMTypeOf(fn)
        return LLVMGetReturnType(ty)
    }
    
}

private extension FunctionType {
    
    
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
extension FunctionPrototypeExpression : IRGenerator {
    
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
        let returnType = try type.returnType()
        let functionType = LLVMFunctionType(returnType, argBuffer, UInt32(argCount), LLVMBool(false))
        let function = LLVMAddFunction(module, name, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        // Add function type to scope table
        scope.addFunctionType(name, val: functionType)
        
        // scope internal to function, needs params setting and then the block should be added *inside* the bbGen function
        let functionScope = Scope(function: function, parentScope: scope)
        
        // set function param names and update table
        for i in 0..<argCount {
            let param = LLVMGetParam(function, UInt32(i))
            let name = (impl?.params.elements[i] as? ValueType)?.name ?? ("$\(i)")
            LLVMSetValueName(param, name)

            let s = StackVariable(val: param, builder: builder)
            functionScope.addVariable(name, val: s)
        }
        
        // generate bb for body
        do {
            try impl?.body.bbGen(innerScope: functionScope, fn: function, ret: returnType)
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


extension ReturnExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        if try expression.expressionllvmType(scope) == LLVMVoidType() {
            return LLVMBuildRetVoid(builder)
        }
        
        let v = try expression.expressionCodeGen(scope)
        return LLVMBuildRet(builder, v)
    }
    
    func llvmType(scope: Scope) -> LLVMTypeRef {
        return nil
    }
    
}



extension BlockExpression {
    
    func bbGen(innerScope scope: Scope, fn: LLVMValueRef, ret: LLVMValueRef) throws -> LLVMBasicBlockRef {
        
        // setup function block
        let entryBlock = LLVMAppendBasicBlock(fn, "entry")
        LLVMPositionBuilderAtEnd(builder, entryBlock)
        
        scope.block = entryBlock
        
        // code gen for function
        for exp in expressions {
            try exp.expressionCodeGen(scope)
        }
        
        if expressions.isEmpty || (ret != nil && ret == LLVMVoidType()) {
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


private func ifBBID(n n: Int, ex: ElseIfBlockExpression) -> String {
    return ex.condition == nil ? "else\(n)" : "then\(n)"
}

extension ConditionalExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        // block leading into and out of current if block
        var ifIn: LLVMBasicBlockRef = scope.block
        var ifOut: LLVMBasicBlockRef = nil
        
        let leaveIf = LLVMAppendBasicBlock(scope.function, "cont")
        var rets = true // whether all blocks return
        
        for (i, statement) in statements.enumerate() {
            
            LLVMPositionBuilderAtEnd(builder, ifIn)
            
            /// States whether the block being appended returns from the current scope
            let returnsFromScope = statement.block.expressions.contains { $0 is ReturnExpression }
            rets = rets && returnsFromScope
            
            // condition
            let cond = try statement.condition?.expressionCodeGen(scope)
            if i < statements.count-1 {
                
                ifOut = LLVMAppendBasicBlock(scope.function, "cont\(i)")
                
            } else { //else or final else-if statement

                // If the block returns from the current scope, remove the cont block
                if rets {
                    LLVMRemoveBasicBlockFromParent(leaveIf)
                }
                
                ifOut = leaveIf
            }
            
            // block and associated scope - the then / else block
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
    
    
}


private extension ElseIfBlockExpression {
    
    /// Create the basic block for the if expression
    private func bbGen(innerScope scope: Scope, contBlock: LLVMBasicBlockRef, name: String) throws -> LLVMBasicBlockRef {
        
        // add block
        let basicBlock = LLVMAppendBasicBlock(scope.function, name)
        LLVMPositionBuilderAtEnd(builder, basicBlock)
        
        // parse code
        try block.bbGenInline(scope: scope)
        
        // if the block does continues to the contBlock, move the builder there
        let returnsFromScope = block.expressions.contains { $0 is ReturnExpression }
        if !returnsFromScope {
            LLVMBuildBr(builder, contBlock)
            LLVMPositionBuilderAtEnd(builder, contBlock)
        }
        
        return basicBlock
    }
    
    
}


extension ForInLoopExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        // generate loop and termination blocks
        let loop = LLVMAppendBasicBlock(scope.function, "loop")
        let afterLoop = LLVMAppendBasicBlock(scope.function, "afterloop")
        
        // move into loop block
        LLVMBuildBr(builder, loop)
        LLVMPositionBuilderAtEnd(builder, loop)
        
        // define variable phi node
        let name = binded.name ?? ""
        let i = LLVMBuildPhi(builder, LLVMInt64Type(), name)
        
        guard let rangeIterator = iterator as? RangeIteratorExpression else { throw IRError.ForLoopIteratorNotInt }

        let start = try rangeIterator.start.expressionCodeGen(scope)
        let end = try rangeIterator.end.expressionCodeGen(scope)
        
        // add incoming value to phi node
        LLVMAddIncoming(i, [start].ptr(), [scope.block].ptr(), 1)
        
        
        // iterate and add phi incoming
        let one = LLVMConstInt(LLVMInt64Type(), UInt64(1), LLVMBool(false))
        let next = LLVMBuildAdd(builder, one, i, "next\(name)")
        
        // gen the IR for the inner block
        let lv = StackVariable(val: i, builder: builder)
        let loopScope = Scope(block: loop, vars: [name: lv], function: scope.function, parentScope: scope)
        try block.bbGenInline(scope: loopScope)
        
        // conditional break
        let comp = LLVMBuildICmp(builder, LLVMIntSLE, next, end, "looptest")
        LLVMBuildCondBr(builder, comp, loop, afterLoop)
        
        // move back to loop / end loop
        LLVMAddIncoming(i, [next].ptr(), [loopScope.block].ptr(), 1)
        
        LLVMPositionBuilderAtEnd(builder, afterLoop)
        scope.block = afterLoop
        
        return nil
    }
    
}

// TODO: Break statements and passing break-to bb in scope

extension WhileLoopExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        guard try iterator.condition.expressionllvmType(scope) == LLVMInt1Type() else { throw IRError.NotBoolCondition }
        
        // generate loop and termination blocks
        let loop = LLVMAppendBasicBlock(scope.function, "loop")
        let afterLoop = LLVMAppendBasicBlock(scope.function, "afterloop")
        
        // whether to enter the while, first while check
        let initialCond = try iterator.condition.expressionCodeGen(scope)
        
        // move into loop block
        LLVMBuildCondBr(builder, initialCond, loop, afterLoop)
        LLVMPositionBuilderAtEnd(builder, loop)
        
        // gen the IR for the inner block
        let loopScope = Scope(block: loop, function: scope.function, parentScope: scope)
        try block.bbGenInline(scope: loopScope)
        
        // conditional break
        let conditionalRepeat = try iterator.condition.expressionCodeGen(scope)
        LLVMBuildCondBr(builder, conditionalRepeat, loop, afterLoop)
        
        // move back to loop / end loop
        LLVMPositionBuilderAtEnd(builder, afterLoop)
        scope.block = afterLoop
        
        return nil
    }
    
}



private extension ScopeExpression {
    
    /// Generates children’s code directly into the current scope & block
    func bbGenInline(scope scope: Scope) throws {
        
        // code gen for function
        for exp in expressions {
            try exp.expressionCodeGen(scope)
        }
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpression : IRGenerator {
    
    func arrInstance(scope: Scope) throws -> ArrayVariable {
        
        // assume homogeneous
        let elementType = try arr.first!.expressionllvmType(scope)
        let arrayType = LLVMArrayType(elementType, UInt32(arr.count))
        
        // allocate memory for arr
        let a = LLVMBuildArrayAlloca(builder, arrayType, nil, "arr")
        
        // obj
        let vars = try arr.map { try $0.expressionCodeGen(scope) }
        let variable = ArrayVariable(ptr: a, elType: elementType, arrType: arrayType, builder: builder, vars: vars)
        
        return variable
    }
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        return try arrInstance(scope).base
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        let elementType = try arr.first!.expressionllvmType(scope)
        return LLVMArrayType(elementType, UInt32(arr.count))
    }
    
}

extension ArraySubscriptExpression : IRGenerator {
    
    private func backingArrayVariable(scope: Scope) throws -> ArrayVariable {
        guard let v = arr as? Variable else { throw IRError.SubscriptingNonVariableTypeNotAllowed }
        guard let arr = try scope.variable(v.name) as? ArrayVariable else { throw IRError.SubscriptingNonVariableTypeNotAllowed }
        
        return arr
    }

    func codeGen(scope: Scope) throws -> LLVMValueRef {

        let arr = try backingArrayVariable(scope)
        let idx = try index.expressionCodeGen(scope)
        let ptr = arr.ptrToElementAtIndex(idx)
        
        return LLVMBuildLoad(builder, ptr, "element")
    }
    
    func llvmType(scope: Scope) throws -> LLVMTypeRef {
        return try backingArrayVariable(scope).elementType
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpression : IRGenerator {
    
    func codeGen(scope: Scope) throws -> LLVMValueRef {
        
        
        
        
        
        
        
        return nil
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
        let functionType = LLVMFunctionType(LLVMInt64Type(), argBuffer, UInt32(0), LLVMBool(false))
        let mainFunction = LLVMAddFunction(module, "main", functionType)
        
        // Setup BB & scope
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        let scope = Scope(block: programEntryBlock, function: mainFunction)
        
        for exp in expressions {
            try exp.expressionCodeGen(scope)
        }
                
        LLVMBuildRet(builder, LLVMConstInt(LLVMInt64Type(), 0, LLVMBool(false)))
    }
}












