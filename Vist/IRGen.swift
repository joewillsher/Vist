//
//  CodeGen.swift
//  Vist
//
//  Created by Josef Willsher on 15/11/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


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
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef
}

private protocol BasicBlockGenerator {
    func bbGen(innerStackFrame stackFrame: StackFrame, fn: LLVMValueRef) throws -> LLVMBasicBlockRef
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
    
    func expressioncodeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        if let x = try (self as? IRGenerator)?.codeGen(stackFrame) { return x }
        else { throw IRError.NotIRGenerator }
    }
    func expressionbbGen(innerStackFrame stackFrame: StackFrame, fn: LLVMValueRef) throws -> LLVMBasicBlockRef {
        if let x = try (self as? BasicBlockGenerator)?.bbGen(innerStackFrame: stackFrame, fn: fn) { return x } else { throw IRError.NotBBGenerator }
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
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        return LLVMConstInt(try type!.ir(), UInt64(val), LLVMBool(false))
    }
}


extension FloatingPointLiteral : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        return LLVMConstReal(try type!.ir(), val)
    }
}


extension BooleanLiteral : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) -> LLVMValueRef {
        return LLVMConstInt(LLVMInt1Type(), UInt64(val.hashValue), LLVMBool(false))
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Variable : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        let variable = try stackFrame.variable(name ?? "")
        
        return variable.load(name ?? "")
    }
}


extension AssignmentExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        if let arr = value as? ArrayExpression {
            //if asigning to array
            
            let a = try arr.arrInstance(stackFrame)
            a.allocHead(builder, name: name, mutable: isMutable)
            stackFrame.addVariable(name, val: a)
            
            return a.ptr
            
        } else if let ty = value.type as? LLVMFnType {
            // handle assigning a closure
            
            // Function being made
            let fn = LLVMAddFunction(module, name, try ty.ir())
            
            // make and move into entry block
            let entryBlock = LLVMAppendBasicBlock(fn, "entry")
            LLVMPositionBuilderAtEnd(builder, entryBlock)
            
            // stack frame of fn
            let fnStackFrame = StackFrame(block: entryBlock, function: fn, parentStackFrame: stackFrame)
            
            // value’s IR, this needs to be called and returned
            let v = try value.expressioncodeGen(fnStackFrame)
            
            let num = LLVMCountParams(fn)
            for i in 0..<num {
                let param = LLVMGetParam(fn, i)
                let name = ("$\(Int(i))")
                LLVMSetValueName(param, name)
            }
            
            // args of `fn`
            let args = (0..<num)
                .map { LLVMGetParam(fn, $0) }
                .ptr()
            defer { args.dealloc(Int(num)) }
            
            // call function pointer `v`
            let call = LLVMBuildCall(builder, v, args, num, "")
            
            // return this value from `fn`
            LLVMBuildRet(builder, call)
            
            // move into bb from before
            LLVMPositionBuilderAtEnd(builder, stackFrame.block)
            
            return fn
            
        } else {
            // all other types
            
            // create value
            let v = try value.expressioncodeGen(stackFrame)
            
            // checks
            guard v != nil else { throw IRError.CannotAssignToType(value.dynamicType) }
            let type = LLVMTypeOf(v)
            guard type != LLVMVoidType() else { throw IRError.CannotAssignToVoid }
            
            // create variable
            let variable = ReferenceVariable.alloc(builder, type: type, name: name ?? "", mutable: isMutable)
            
            // Load in memory
            variable.store(v)
            
            // update stack frame variables
            
            stackFrame.addVariable(name, val: variable)
            
            
            return v
        }
    }
}


extension MutationExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        if let object = object as? Variable<AnyExpression> {
            // object = newValue
            
            let variable = try stackFrame.variable(object.name)
            
            
            if let arrayVariable = variable as? ArrayVariable, arrayExpression = value as? ArrayExpression {
                
                let newArray = try arrayExpression.arrInstance(stackFrame)
                arrayVariable.assignFrom(builder, arr: newArray)
                
            } else {
                
                let new = try value.expressioncodeGen(stackFrame)
                
                guard let v = variable as? MutableVariable where v.mutable else { throw IRError.NotMutable }
                v.store(new)
                
            }
        
        } else if let sub = object as? ArraySubscriptExpression {
            
            let arr = try sub.backingArrayVariable(stackFrame)
            
            let i = try sub.index.expressioncodeGen(stackFrame)
            let val = try value.expressioncodeGen(stackFrame)
            
            arr.store(val, inElementAtIndex: i)
        }
        
        return nil
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Expressions
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        let lIR = try lhs.expressioncodeGen(stackFrame), rIR = try rhs.expressioncodeGen(stackFrame)
        
        guard let type = try self.type?.ir() else { throw IRError.TypeNotFound }
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
}


extension Void : IRGenerator {
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        return nil
    }
}


extension CommentExpression : IRGenerator {
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        return nil
    }

}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------

extension FunctionCallExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        // make function
        let fn = LLVMGetNamedFunction(module, name)
        
        // arguments
        let argCount = args.elements.count
        let a = try args.elements.map { try $0.expressioncodeGen(stackFrame) }
        let argBuffer = a.ptr()
        defer { argBuffer.dealloc(argCount) }
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else {
            throw IRError.WrongFunctionApplication(name) }
        
        let doNotUseName = type == LLVMType.Void || type == LLVMType.Null || type == nil
        
        // add call to IR
        return LLVMBuildCall(builder, fn, argBuffer, UInt32(argCount), doNotUseName ? "" : name)
    }
    
}


private extension FunctionType {
    
    func params() throws -> [LLVMTypeRef] {
        guard let res = (type as? LLVMFnType)?.nonVoid else { throw IRError.TypeNotFound }
        return try res.map(ir)
    }
}


extension FunctionPrototypeExpression : IRGenerator {
    // function definition
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        let args = fnType.args, argCount = args.elements.count
        guard let type = self.fnType.type as? LLVMFnType else { throw IRError.TypeNotFound }
        
        // If existing function definition
        let _fn = LLVMGetNamedFunction(module, name)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(argCount) && LLVMCountBasicBlocks(_fn) != 0 && LLVMGetEntryBasicBlock(_fn) != nil {
            return _fn
        }
        
        // Set params
        let argBuffer = try fnType.params().ptr()
        defer { argBuffer.dealloc(argCount) }
        
        // make function
        let functionType = try type.ir()
        let function = LLVMAddFunction(module, name, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        // Add function type to stack frame
        stackFrame.addFunctionType(name, val: functionType)
        
        // stack frame internal to function, needs params setting and then the block should be added *inside* the bbGen function
        let functionStackFrame = StackFrame(function: function, parentStackFrame: stackFrame)
        
        // set function param names and update table
        for i in 0..<argCount {
            let param = LLVMGetParam(function, UInt32(i))
            let name = (impl?.params.elements[i] as? ValueType)?.name ?? ("$\(i)")
            LLVMSetValueName(param, name)
            
            let s = StackVariable(val: param, builder: builder)
            functionStackFrame.addVariable(name, val: s)
        }
        
        // generate bb for body
        do {
            try impl?.body.bbGen(innerStackFrame: functionStackFrame, fn: function, ret: try type.returns.ir())
        } catch {
            LLVMDeleteFunction(function)
            throw error
        }
        
        return function
    }
    
}


extension ReturnExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        if try expression.type?.ir() == LLVMVoidType() {
            return LLVMBuildRetVoid(builder)
        }
        
        let v = try expression.expressioncodeGen(stackFrame)
        return LLVMBuildRet(builder, v)
    }
    
}


extension BlockExpression {
    
    func bbGen(innerStackFrame stackFrame: StackFrame, fn: LLVMValueRef, ret: LLVMValueRef) throws -> LLVMBasicBlockRef {
        
        // setup function block
        let entryBlock = LLVMAppendBasicBlock(fn, "entry")
        LLVMPositionBuilderAtEnd(builder, entryBlock)
        
        stackFrame.block = entryBlock
        
        // code gen for function
        for exp in expressions {
            try exp.expressioncodeGen(stackFrame)
        }
        
        if expressions.isEmpty || (ret != nil && ret == LLVMVoidType()) {
            LLVMBuildRetVoid(builder)
        }
        
        // reset builder head to parent’s stack frame
        LLVMPositionBuilderAtEnd(builder, stackFrame.parentStackFrame!.block)
        return entryBlock
    }
    
}


extension ClosureExpression : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        guard let type = type as? LLVMFnType else { fatalError() }
        
        let argBuffer = try type.params.map(ir).ptr()
        defer { argBuffer.dealloc(type.params.count) }
        
        let name = "closure"//.mangle()
        
        let functionType = try type.ir()
        let function = LLVMAddFunction(module, name, functionType)
        
        
        stackFrame.addFunctionType(name, val: functionType)
        
        let functionStackFrame = StackFrame(function: function, parentStackFrame: stackFrame)
        
        // set function param names and update table
        for i in 0..<type.params.count {
            let param = LLVMGetParam(function, UInt32(i))
            let name = parameters.isEmpty ? "$\(i)" : parameters[i]
            LLVMSetValueName(param, name)
            
            let s = StackVariable(val: param, builder: builder)
            functionStackFrame.addVariable(name, val: s)
        }
        
        do {
            try BlockExpression(expressions: expressions)
                .bbGen(innerStackFrame: functionStackFrame, fn: function, ret: try type.returns.ir())
        } catch {
            LLVMDeleteFunction(function)
            throw error
        }
        
        return function
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                              Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension ElseIfBlockExpression {
    
    private func ifBBID(n n: Int) -> String {
        return condition == nil ? "else\(n)" : "then\(n)"
    }
}

extension ConditionalExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        // block leading into and out of current if block
        var ifIn: LLVMBasicBlockRef = stackFrame.block
        var ifOut: LLVMBasicBlockRef = nil
        
        let leaveIf = LLVMAppendBasicBlock(stackFrame.function, "cont")
        var rets = true // whether all blocks return
        
        for (i, statement) in statements.enumerate() {
            
            LLVMPositionBuilderAtEnd(builder, ifIn)
            
            /// States whether the block being appended returns from the current scope
            let returnsFromScope = statement.block.expressions.contains { $0 is ReturnExpression }
            rets = rets && returnsFromScope
            
            // condition
            let cond = try statement.condition?.expressioncodeGen(stackFrame)
            if i < statements.count-1 {
                
                ifOut = LLVMAppendBasicBlock(stackFrame.function, "cont\(i)")
                
            } else { //else or final else-if statement

                // If the block returns from the current scope, remove the cont block
                if rets {
                    LLVMRemoveBasicBlockFromParent(leaveIf)
                }
                
                ifOut = leaveIf
            }
            
            // block and associated stack frame - the then / else block
            let tStackFrame = StackFrame(function: stackFrame.function, parentStackFrame: stackFrame)
            let block = try statement.bbGen(innerStackFrame: tStackFrame, contBlock: leaveIf, name: statement.ifBBID(n: i))
            
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
        stackFrame.block = ifOut
        
        return nil
    }
}


private extension ElseIfBlockExpression {
    
    /// Create the basic block for the if expression
    private func bbGen(innerStackFrame stackFrame: StackFrame, contBlock: LLVMBasicBlockRef, name: String) throws -> LLVMBasicBlockRef {
        
        // add block
        let basicBlock = LLVMAppendBasicBlock(stackFrame.function, name)
        LLVMPositionBuilderAtEnd(builder, basicBlock)
        
        // parse code
        try block.bbGenInline(stackFrame: stackFrame)
        
        // if the block does continues to the contBlock, move the builder there
        let returnsFromScope = block.expressions.contains { $0 is ReturnExpression }
        if !returnsFromScope {
            LLVMBuildBr(builder, contBlock)
            LLVMPositionBuilderAtEnd(builder, contBlock)
        }
        
        return basicBlock
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Loops
//-------------------------------------------------------------------------------------------------------------------------

extension ForInLoopExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        // generate loop and termination blocks
        let loop = LLVMAppendBasicBlock(stackFrame.function, "loop")
        let afterLoop = LLVMAppendBasicBlock(stackFrame.function, "afterloop")
        
        // move into loop block
        LLVMBuildBr(builder, loop)
        LLVMPositionBuilderAtEnd(builder, loop)
        
        // define variable phi node
        let name = binded.name ?? ""
        let i = LLVMBuildPhi(builder, LLVMInt64Type(), name)
        
        guard let rangeIterator = iterator as? RangeIteratorExpression else { throw IRError.ForLoopIteratorNotInt }

        let start = try rangeIterator.start.expressioncodeGen(stackFrame)
        let end = try rangeIterator.end.expressioncodeGen(stackFrame)
        
        // add incoming value to phi node
        let num1 = [start].ptr(), incoming1 = [stackFrame.block].ptr()
        defer { num1.dealloc(1); incoming1.dealloc(1) }
        LLVMAddIncoming(i, num1, incoming1, 1)
        
        
        // iterate and add phi incoming
        let one = LLVMConstInt(LLVMInt64Type(), UInt64(1), LLVMBool(false))
        let next = LLVMBuildAdd(builder, one, i, "next\(name)")
        
        // gen the IR for the inner block
        let lv = StackVariable(val: i, builder: builder)
        let loopStackFrame = StackFrame(block: loop, vars: [name: lv], function: stackFrame.function, parentStackFrame: stackFrame)
        try block.bbGenInline(stackFrame: loopStackFrame)
        
        // conditional break
        let comp = LLVMBuildICmp(builder, LLVMIntSLE, next, end, "looptest")
        LLVMBuildCondBr(builder, comp, loop, afterLoop)
        
        // move back to loop / end loop
        let num2 = [next].ptr(), incoming2 = [loopStackFrame.block].ptr()
        defer { num2.dealloc(1); incoming2.dealloc(1) }
        LLVMAddIncoming(i, num2, incoming2, 1)
        
        LLVMPositionBuilderAtEnd(builder, afterLoop)
        stackFrame.block = afterLoop
        
        return nil
    }
    
}


// TODO: Break statements and passing break-to bb in scope
extension WhileLoopExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        guard try iterator.condition.type?.ir() == LLVMInt1Type() else { throw IRError.NotBoolCondition }
        
        // generate loop and termination blocks
        let loop = LLVMAppendBasicBlock(stackFrame.function, "loop")
        let afterLoop = LLVMAppendBasicBlock(stackFrame.function, "afterloop")
        
        // whether to enter the while, first while check
        let initialCond = try iterator.condition.expressioncodeGen(stackFrame)
        
        // move into loop block
        LLVMBuildCondBr(builder, initialCond, loop, afterLoop)
        LLVMPositionBuilderAtEnd(builder, loop)
        
        // gen the IR for the inner block
        let loopStackFrame = StackFrame(block: loop, function: stackFrame.function, parentStackFrame: stackFrame)
        try block.bbGenInline(stackFrame: loopStackFrame)
        
        // conditional break
        let conditionalRepeat = try iterator.condition.expressioncodeGen(stackFrame)
        LLVMBuildCondBr(builder, conditionalRepeat, loop, afterLoop)
        
        // move back to loop / end loop
        LLVMPositionBuilderAtEnd(builder, afterLoop)
        stackFrame.block = afterLoop
        
        return nil
    }
    
}


private extension ScopeExpression {
    
    /// Generates children’s code directly into the current scope & block
    func bbGenInline(stackFrame stackFrame: StackFrame) throws {
        
        // code gen for function
        for exp in expressions {
            try exp.expressioncodeGen(stackFrame)
        }
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpression : IRGenerator {
    
    func arrInstance(stackFrame: StackFrame) throws -> ArrayVariable {
        
        // assume homogeneous
        guard let elementType = try elType?.ir() else { throw IRError.TypeNotFound }
        let arrayType = LLVMArrayType(elementType, UInt32(arr.count))
        
        // allocate memory for arr
        let a = LLVMBuildArrayAlloca(builder, arrayType, nil, "arr")
        
        // obj
        let vars = try arr.map { try $0.expressioncodeGen(stackFrame) }
        let variable = ArrayVariable(ptr: a, elType: elementType, arrType: arrayType, builder: builder, vars: vars)
        
        return variable
    }
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        return try arrInstance(stackFrame).load()
    }
    
}


extension ArraySubscriptExpression : IRGenerator {
    
    private func backingArrayVariable(stackFrame: StackFrame) throws -> ArrayVariable {
        guard let v = arr as? Variable<AnyExpression> else { throw IRError.SubscriptingNonVariableTypeNotAllowed }
        guard let arr = try stackFrame.variable(v.name) as? ArrayVariable else { throw IRError.SubscriptingNonVariableTypeNotAllowed }
        
        return arr
    }

    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {

        let arr = try backingArrayVariable(stackFrame)
        let idx = try index.expressioncodeGen(stackFrame)
        
        return arr.loadElementAtIndex(idx)
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Structs
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpression : IRGenerator {
    
    func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        guard let type = try type?.ir() else { throw IRError.TypeNotFound }
        let numEls = properties.count
        
        let structStackFrame = StackFrame(block: stackFrame.block, function: stackFrame.function, parentStackFrame: stackFrame)
        
        let els = try properties
            .map { try $0.codeGen(structStackFrame) }
            .ptr()
        defer { els.dealloc(numEls) }
        
        for i in initialisers {
            try i.codeGen(stackFrame)
        }
        
        let a = LLVMConstStruct(els, UInt32(numEls), LLVMBool(false))
        
        return a
    }
    
}


extension InitialiserExpression : IRGenerator {
    
    // TODO: Redo this implementation
    // initialiser should take pointer to allocated struct
    // and initalise it
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        let args = ty.args, argCount = args.elements.count
        guard let type = type as? LLVMFnType, name = parent?.name, parentType = parent?.type else {
            throw IRError.TypeNotFound }
        
        // make function
        let functionType = try type.ir()
        let function = LLVMAddFunction(module, name, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        // Add function type to stack frame
        stackFrame.addFunctionType(name, val: functionType)
        
        // stack frame internal to initialiser, cannot capture from surrounding scope
        let initStackFrame = StackFrame(function: function, parentStackFrame: nil)
        
        // set function param names and update table
        for i in 0..<argCount {
            let param = LLVMGetParam(function, UInt32(i))
            let name = (impl.params.elements[i] as? ValueType)?.name ?? ("$\(i)")
            LLVMSetValueName(param, name)
            
            let s = StackVariable(val: param, builder: builder)
            initStackFrame.addVariable(name, val: s)
        }
        
        let s = ReferenceVariable.alloc(builder, type: try parentType.ir(), mutable: false)
        stackFrame.addVariable(name, val: s)
        
        // TODO: run init block

        return function
    }
}

extension PropertyLookupExpression : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
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
        
        // Setup BB & stack frame
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        let stackFrame = StackFrame(block: programEntryBlock, function: mainFunction)
        
        for exp in expressions {
            try exp.expressioncodeGen(stackFrame)
        }
                
        LLVMBuildRet(builder, LLVMConstInt(LLVMInt64Type(), 0, LLVMBool(false)))
    }
}










