//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 15/11/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

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



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Helpers
//-------------------------------------------------------------------------------------------------------------------------

extension ASTNode {
    
    private func nodeCodeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        guard case let gen as IRGenerator = self else { throw error(IRError.NotGenerator(self.dynamicType), userVisible: false) }
        return try gen.codeGen(stackFrame)
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

extension LLVMBool : Swift.BooleanType, BooleanLiteralConvertible {
    
    public init(booleanLiteral value: Bool) {
        self.init(value ? 1 : 0)
    }
    
    public var boolValue: Bool {
        return self == 1
    }
}

private func codeGenIn(stackFrame: StackFrame) -> Expr throws -> LLVMValueRef {
    return { e in try e.nodeCodeGen(stackFrame) }
}

private func validateModule(ref: LLVMModuleRef) throws {
    var err = UnsafeMutablePointer<Int8>.alloc(1)
    guard !LLVMVerifyModule(module, LLVMReturnStatusAction, &err) else {
        throw error(IRError.InvalidModule(module, String.fromCString(err)), userVisible: false)
    }
}


private func validateFunction(ref: LLVMValueRef, name: String) throws {
    guard !LLVMVerifyFunction(ref, LLVMReturnStatusAction) else {
        throw error(IRError.InvalidFunction(name), userVisible: false)
    }
}




/**************************************************************************************************************************/
// MARK: -                                                 IR GEN


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Literals
//-------------------------------------------------------------------------------------------------------------------------

extension IntegerLiteral : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        let rawType = BuiltinType.Int(size: size)
        let value = LLVMConstInt(rawType.ir(), UInt64(val), false)
        
        guard let type = self.type else { throw error(SemaError.IntegerNotTyped, userVisible: false) }
        return type.initialiseStdTypeFromBuiltinMembers(value, module: module, builder: builder)
    }
}


extension FloatingPointLiteral : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) -> LLVMValueRef {
        return LLVMConstReal(type!.ir(), val)
    }
}


extension BooleanLiteral : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        let rawType = BuiltinType.Bool
        let value = LLVMConstInt(rawType.ir(), UInt64(val.hashValue), false)
        
        guard let type = self.type else { throw error(SemaError.BoolNotTyped, userVisible: false) }
        return type.initialiseStdTypeFromBuiltinMembers(value, module: module, builder: builder)
    }
}


extension StringLiteral : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) -> LLVMValueRef {
        
        var s: COpaquePointer = nil
        str .cStringUsingEncoding(NSUTF8StringEncoding)?
            .withUnsafeBufferPointer { ptr in
            s = LLVMConstString(ptr.baseAddress, UInt32(ptr.count), true)
        }
        
        return s
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension VariableExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        let variable = try stackFrame.variable(name)
        return variable.value
    }
}


extension VariableDecl : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        if case let arr as ArrayExpr = value {
            //if asigning to array
            
            let a = try arr.arrInstance(stackFrame)
            a.allocHead(builder, name: name, mutable: isMutable)
            stackFrame.addVariable(a, named: name)
            
            return a.ptr
        }
        else if case let ty as FnType = value._type {
            // handle assigning a closure
            
            // Function being made
            let fn = LLVMAddFunction(module, name, ty.globalType(module))
            
            // make and move into entry block
            let entryBlock = LLVMAppendBasicBlock(fn, "entry")
            LLVMPositionBuilderAtEnd(builder, entryBlock)
            
            // stack frame of fn
            let fnStackFrame = StackFrame(block: entryBlock, function: fn, parentStackFrame: stackFrame)
            
            // value’s IR, this needs to be called and returned
            let v = try value.nodeCodeGen(fnStackFrame)
            
            let num = LLVMCountParams(fn)
            for i in 0..<num {
                let param = LLVMGetParam(fn, i)
                let name = i.implicitParamName()
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
        }
        else {
            // all other types
            
            // create value
            let v = try value.nodeCodeGen(stackFrame)
            
            // checks
            guard v != nil else { throw error(IRError.CannotAssignToType(value.dynamicType), userVisible: false) }
            let type = LLVMTypeOf(v)
            guard type != LLVMVoidType() else { throw error(IRError.CannotAssignToVoid, userVisible: false) }
            
            // create variable
            let variable: MutableVariable
            
            switch value._type {
            case let structType as StructType:
                variable = MutableStructVariable.alloc(structType, irName: name, irGen: (builder, module))
                
            case let tupleType as TupleType:
                variable = MutableTupleVariable.alloc(tupleType, irName: name, irGen: (builder, module))
                
            default:
                variable = ReferenceVariable.alloc(type, irName: name, irGen: (builder, module))
            }
            
            // Load in memory
            variable.value = v
            // update stack frame variables
            stackFrame.addVariable(variable, named: name)
            
            return v
        }
    }
}


extension MutationExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        switch object {
        case let object as VariableExpr:
            // object = newValue
            
            let variable = try stackFrame.variable(object.name)
            
            if case let arrayVariable as ArrayVariable = variable, case let arrayExpression as ArrayExpr = value {
                
                let newArray = try arrayExpression.arrInstance(stackFrame)
                arrayVariable.assignFrom(newArray)
            }
            else {
                let new = try value.nodeCodeGen(stackFrame)
                
                guard case let v as MutableVariable = variable else { throw error(IRError.NotMutable(object.name), userVisible: false) }
                v.value = new
            }
        case let sub as ArraySubscriptExpr:
            
            let arr = try sub.backingArrayVariable(stackFrame)
            
            let i = try sub.index.nodeCodeGen(stackFrame)
            let val = try value.nodeCodeGen(stackFrame)
            
            arr.store(val, inElementAtIndex: i)

        case let prop as PropertyLookupExpr:
            // foo.bar = meme
            
            guard case let n as VariableExpr = prop.object else { throw error(IRError.CannotLookupPropertyFromNonVariable, userVisible: false) }
            
            guard case let variable as MutableStructVariable = try stackFrame.variable(n.name) else {
                if try stackFrame.variable(n.name) is ParameterStructVariable { throw error(IRError.CannotMutateParam) }
                throw error(IRError.NoProperty(type: prop._type.description, property: n.name))
            }
                        
            let val = try value.nodeCodeGen(stackFrame)
            
            try variable.store(val, inPropertyNamed: prop.name)
            
        default:
            throw error(IRError.Unreachable, userVisible: false)
        }
        
        return nil
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Exprs
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        let lIR = try lhs.nodeCodeGen(stackFrame), rIR = try rhs.nodeCodeGen(stackFrame)
        guard let argTypes = [lhs, rhs].optionalMap({ $0._type }), fnType = self.fnType else { throw error(SemaError.ParamsNotTyped, userVisible: false) }
        
        let fn: LLVMValueRef
        
        if let (type, fnIR) = StdLib.getFunctionIR(op, args: argTypes, module: module) {
            fn = fnIR
        }
        else {
            fn = LLVMGetNamedFunction(module, mangledName)
        }
        
        // arguments
        let argBuffer = [lIR, rIR].ptr()
        defer { argBuffer.dealloc(2) }
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(2) else { throw error(IRError.WrongFunctionApplication(op), userVisible: false) }
        
        let doNotUseName = _type == BuiltinType.Void || _type == BuiltinType.Null || _type == nil
        let n = doNotUseName ? "" : "\(op).res"
        
        // add call to IR
        let call = LLVMBuildCall(builder, fn, argBuffer, UInt32(2), n)
        fnType.addMetadata(call)
        return call
    }
}


extension Void : IRGenerator {
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        return nil
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------

extension FunctionCallExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        let argCount = self.args.elements.count
        let args = try self.args.elements.map(codeGenIn(stackFrame))
        guard let argTypes = self.args.elements.optionalMap({ $0._type }) else { throw error(SemaError.ParamsNotTyped, userVisible: false) }

        // Lookup
        if let function = builtinBinaryInstruction(name, builder: builder, module: module) {
            guard args.count == 2 else { throw error(IRError.WrongFunctionApplication(name), userVisible: false) }
            return try function(args[0], args[1])
        }
        else if let function = builtinInstruction(name, builder: builder, module: module) {
            guard args.count == 0 else { throw error(IRError.WrongFunctionApplication(name), userVisible: false) }
            return function()
        }
        
        // get function decl IR
        let fn: LLVMValueRef
        
        if let (_, f) = StdLib.getFunctionIR(name, args: argTypes, module: module) {
            fn = f
        }
        else {
            fn = LLVMGetNamedFunction(module, mangledName)
        }
        
        guard let fnType = self.fnType else { throw error(IRError.NotTyped, userVisible: false) }
        
        // arguments
        let argBuffer = args.ptr()
        defer { argBuffer.dealloc(argCount) }
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else { throw error(IRError.WrongFunctionApplication(name), userVisible: false) }
        
        let doNotUseName = _type == BuiltinType.Void || _type == BuiltinType.Null || _type == nil
        let n = doNotUseName ? "" : "\(name)_res"
        
        // add call to IR
        let call = LLVMBuildCall(builder, fn, argBuffer, UInt32(argCount), n)
        fnType.addMetadata(call)
        return call
    }
    
}


private extension FunctionType {
    
    private func paramTypeIR() throws -> [LLVMTypeRef] {
        guard let res = type else { throw error(IRError.TypeNotFound, userVisible: false) }
        return try res.nonVoid.map(globalType(module))
    }
}


extension FuncDecl : IRGenerator {
    // function definition
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        let type: FnType
        let startIndex: Int // where do the user's params start being used, 0 for free funcs and 1 for methods
        let parentType: StructType? // the type of self is its a method
        
        let paramTypeNames = fnType.paramType.typeNames(), paramCount = paramTypeNames.count
        
        if let parent = self.parent {
            guard let _parentType = parent.type else { throw error(IRError.NoParentType, userVisible: false) }
            guard let _type = fnType.type else { throw error(IRError.TypeNotFound, userVisible: false) }
            
            type = FnType(params: [BuiltinType.Pointer(to: _parentType)] + _type.params, returns: _type.returns)
            startIndex = 1
            parentType = _parentType
        }
        else {
            guard let t = fnType.type else { throw error(IRError.TypeNotFound, userVisible: false) }
            
            type = t
            startIndex = 0
            parentType = nil
        }
        
        // If existing function definition
        let _fn = LLVMGetNamedFunction(module, mangledName)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(paramCount + startIndex) && LLVMCountBasicBlocks(_fn) != 0 && LLVMGetEntryBasicBlock(_fn) != nil {
            return _fn
        }
        
        // Set params
        let paramBuffer = try fnType.paramTypeIR().ptr()
        defer { paramBuffer.dealloc(paramCount) }
        
        // make function
        let functionType = type.globalType(module)
        let function = LLVMAddFunction(module, mangledName, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        if stackFrame.isStdLib {
            LLVMSetLinkage(function, LLVMExternalLinkage)
        }
        else { // set internal. Will set external or private if has the attribute
            LLVMSetLinkage(function, LLVMInternalLinkage)
        }
        
        // add attrs
        for a in attrs {
            a.addAttrTo(function)
        }
        
        // setup function block
        let entryBlock = LLVMAppendBasicBlock(function, "entry")
        LLVMPositionBuilderAtEnd(builder, entryBlock) // TODO: If isStdLib
        
        // Add function type to stack frame
        stackFrame.addFunctionType(functionType, named: mangledName)
        
        // stack frame internal to function, needs params setting and then the block should be added *inside* the bbGen function
        let functionStackFrame = StackFrame(block: entryBlock, function: function, parentStackFrame: stackFrame)
            
        // set function param names and update table
        for i in 0..<paramCount {
            let param = LLVMGetParam(function, UInt32(i + startIndex))
            let paramName = impl?.params[i] ?? i.implicitParamName()
            LLVMSetValueName(param, paramName)
            
            let tyName = paramTypeNames[i]
            
            switch try stackFrame.type(tyName) {
            case let t as StructType:
                let s = ParameterStructVariable(val: param, type: t, irName: paramName, irGen: (builder, module))
                functionStackFrame.addVariable(s, named: paramName)
                
            case let c as ConceptType:
                let e = ExistentialVariable.alloc(param, conceptType: c, irName: paramName, irGen: (builder, module))
                functionStackFrame.addVariable(e, named: paramName)
                
            default:
                let s = StackVariable(val: param, irName: paramName, irGen: (builder, module))
                functionStackFrame.addVariable(s, named: paramName)
            }
        }
        
        // if is a method
        if let parentType = parentType {
            // get self from param list
            let param = LLVMGetParam(function, 0)
            LLVMSetValueName(param, "self")
            // self's members
            
            let r = MutableStructVariable(type: parentType, ptr: param, irName: "self", irGen: (builder, module))
            functionStackFrame.addVariable(r, named: "self")
            
            // add self's properties implicitly
            for el in parent?.properties ?? [] {
                let p = SelfReferencingMutableVariable(propertyName: el.name, parent: r)
                functionStackFrame.addVariable(p, named: el.name)
            }
        }
        
        // generate bb for body
        do {
            try impl?.body.bbGen(innerStackFrame: functionStackFrame, ret: type.returns.globalType(module))
        }
        catch {
            LLVMDeleteFunction(function)
            throw error
        }
        
        try validateFunction(function, name: name)
        
        return function
    }
}


extension ReturnStmt : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        if expr._type?.globalType(module) == LLVMVoidType() {
            return LLVMBuildRetVoid(builder)
        }
        
        let v = try expr.nodeCodeGen(stackFrame)
        return LLVMBuildRet(builder, v)
    }
    
}


extension BlockExpr {
    
    private func bbGen(innerStackFrame stackFrame: StackFrame, ret: LLVMValueRef) throws {
        
        // code gen for function
        try exprs.walkChildren { exp in
            try exp.nodeCodeGen(stackFrame)
        }
        
        if exprs.isEmpty || (ret != nil && ret == LLVMVoidType()) {
            LLVMBuildRetVoid(builder)
        }
        
        // reset builder head to parent’s stack frame
        LLVMPositionBuilderAtEnd(builder, stackFrame.parentStackFrame!.block)
    }
    
}


extension ClosureExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        guard let type = self.type else { throw error(IRError.NotTyped, userVisible: false) }
        
        let paramBuffer = try type.params.map(ir).ptr()
        defer { paramBuffer.dealloc(type.params.count) }
        
        let name = "closure"//.mangle()
        
        let functionType = type.globalType(module)
        let function = LLVMAddFunction(module, name, functionType)
        
        // setup function block
        let entryBlock = LLVMAppendBasicBlock(function, "entry")
        LLVMPositionBuilderAtEnd(builder, entryBlock)
        
        stackFrame.addFunctionType(functionType, named: name)
        
        let functionStackFrame = StackFrame(function: function, parentStackFrame: stackFrame)
        
        // set function param names and update table
        for i in 0..<type.params.count {
            let param = LLVMGetParam(function, UInt32(i))
            let name = parameters[i]
            LLVMSetValueName(param, name)
            
            // FIXME: It looks like i'm lazy -- fix this when doing closures again 
            
//            let ty = LLVMTypeOf(param)
//            if LLVMGetTypeKind(ty) == LLVMStructTypeKind {
//                let ptr = LLVMBuildAlloca(builder, ty, "ptr\(name)")
//                LLVMBuildStore(builder, param, ptr)
//                
//                let tyName = type.params[i].name
//                let t = try stackFrame.type(tyName)
//                
//                let memTys = try t.members.map { ($0.0, try $0.1.globalType(module), $0.2) }
//                
//                let s = MutableStructVariable(type: ty, ptr: ptr, mutable: false, builder: builder, properties: memTys)
//                functionStackFrame.addVariable(name, val: s)
//            }
//            else {
                let s = StackVariable(val: param, irName: name, irGen: (builder, module))
                functionStackFrame.addVariable(s, named: name)
//            }
        }
        
        do {
            try BlockExpr(exprs: exprs).bbGen(innerStackFrame: functionStackFrame, ret: type.returns.globalType(module))
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

extension ElseIfBlockStmt {
    
    private func ifBBID(n n: Int) -> String {
        return condition == nil ? "else.\(n)" : "then.\(n)"
    }
}

extension ConditionalStmt : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        // block leading into and out of current if block
        var ifIn: LLVMBasicBlockRef = stackFrame.block
        var ifOut: LLVMBasicBlockRef = nil
        
        let leaveIf = LLVMAppendBasicBlock(stackFrame.function, "cont.stmt")
        var rets = true // whether all blocks return
        
        for (i, statement) in statements.enumerate() {
            
            LLVMPositionBuilderAtEnd(builder, ifIn)
            
            /// States whether the block being appended returns from the current scope
            let returnsFromScope = statement.block.exprs.contains { $0 is ReturnStmt }
            rets = rets && returnsFromScope
            
            // condition
            let cond = try statement.condition?.nodeCodeGen(stackFrame)
            if i < statements.count-1 {
                ifOut = LLVMAppendBasicBlock(stackFrame.function, "cont.\(i)")
            }
            else { //else or final else-if statement
                if rets { // If the block returns from the current scope, remove the cont block
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
                let v = try cond.load("value", fromType: statement.condition?._type, builder: builder)
                LLVMBuildCondBr(builder, v, block, ifOut)
            }
            else { // else statement, uncondtional jump
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


private extension ElseIfBlockStmt {
    
    /// Create the basic block for the if Expr
    private func bbGen(innerStackFrame stackFrame: StackFrame, contBlock: LLVMBasicBlockRef, name: String) throws -> LLVMBasicBlockRef {
        
        // add block
        let basicBlock = LLVMAppendBasicBlock(stackFrame.function, name)
        LLVMPositionBuilderAtEnd(builder, basicBlock)
        
        // parse code
        try block.bbGenInline(stackFrame: stackFrame)
        
        // if the block does continues to the contBlock, move the builder there
        let returnsFromScope = block.exprs.contains { $0 is ReturnStmt }
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


extension ForInLoopStmt : IRGenerator {
    
    //    ; ENTRY
    //    br label %loop.header
    //
    // loop.header:                                       ; preds = %loop.latch, %entry
    //    %loop.count.x = phi i64   [ i64 %start.value, %entry ],
    //                              [ %next.x, %loop.latch ]
    //    %x = insertvalue { i64 } undef, i64 %loop.count.x, 0
    //
    // loop.body:                                         ; preds = %loop.header
    //    ; BODY...
    //    br label %loop.latch
    //
    // loop.latch:                                        ; preds = %loop.body
    //    %next.x = add i64 %loop.count.x, 1
    //    %loop.repeat.test = icmp sgt i64 %next.x, i64 %end.value
    //    br i1 %loop.repeat.test, label %loop.exit, label %loop.header
    //
    // loop.exit:                                         ; preds = %loop.body
    //
    //    ; EXIT

    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        // generate loop and termination blocks
        let loopHeader = LLVMAppendBasicBlock(stackFrame.function, "loop.header")
        let loopBody =   LLVMAppendBasicBlock(stackFrame.function, "loop.body")
        let loopLatch =  LLVMAppendBasicBlock(stackFrame.function, "loop.latch")
        let afterLoop =  LLVMAppendBasicBlock(stackFrame.function, "loop.exit")
        
        let rangeIterator = try iterator.nodeCodeGen(stackFrame)
        
        let startValue = try rangeIterator
            .load("start", fromType: iterator._type, builder: builder, irName: "start")
            .load("value", fromType: StdLib.IntType, builder: builder, irName: "start.value")
        let endValue = try rangeIterator
            .load("end",   fromType: iterator._type, builder: builder, irName: "end")
            .load("value", fromType: StdLib.IntType, builder: builder, irName: "end.value")
        
        // move into loop block
        LLVMBuildBr(builder, loopHeader)
        LLVMPositionBuilderAtEnd(builder, loopHeader)
        
        let intType = BuiltinType.Int(size: 64)
        
        // define variable phi node
        let iteratorName = binded.name
        let loopCount = LLVMBuildPhi(builder, intType.globalType(module), "loop.count.\(iteratorName)")
        
        // add incoming value to phi node
        let num1 = [startValue].ptr(), incoming1 = [stackFrame.block].ptr()
        defer { num1.dealloc(1); incoming1.dealloc(1) }
        LLVMAddIncoming(loopCount, num1, incoming1, 1)
        
        // iterate and add phi incoming
        let one = LLVMConstInt(LLVMInt64Type(), UInt64(1), false)
        let next = LLVMBuildAdd(builder, one, loopCount, "next.\(iteratorName)")
        
        // gen the IR for the inner block
        let loopCountInt = StdLib.IntType.initialiseStdTypeFromBuiltinMembers(loopCount, module: module, builder: builder, irName: iteratorName)
        let loopVariable = StackVariable(val: loopCountInt, irName: iteratorName, irGen: (builder, module))
        let loopStackFrame = StackFrame(block: loopBody, vars: [iteratorName: loopVariable], function: stackFrame.function, parentStackFrame: stackFrame)
        
        // Generate loop body
        LLVMBuildBr(builder, loopBody)
        LLVMPositionBuilderAtEnd(builder, loopBody)
        try block.bbGenInline(stackFrame: loopStackFrame)
        
        LLVMBuildBr(builder, loopLatch)
        LLVMPositionBuilderAtEnd(builder, loopLatch)
        
        // conditional break
        let comp = LLVMBuildICmp(builder, LLVMIntSLE, next, endValue, "loop.repeat.test")
        LLVMBuildCondBr(builder, comp, loopHeader, afterLoop)
        
        // move back to loop / end loop
        let num2 = [next].ptr(), incoming2 = [loopLatch].ptr()
        defer { num2.dealloc(1); incoming2.dealloc(1) }
        LLVMAddIncoming(loopCount, num2, incoming2, 1)
        
        LLVMPositionBuilderAtEnd(builder, afterLoop)
        stackFrame.block = afterLoop
        
        return nil
    }
    
}


// TODO: Break statements and passing break-to bb in scope
extension WhileLoopStmt : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        // generate loop and termination blocks
        let loop = LLVMAppendBasicBlock(stackFrame.function, "loop.body")
        let afterLoop = LLVMAppendBasicBlock(stackFrame.function, "loop.exit")
        
        // whether to enter the while, first while check
        let initialCond = try condition.nodeCodeGen(stackFrame)
        let initialCondV = try initialCond.load("value", fromType: condition._type, builder: builder)

        // move into loop block
        LLVMBuildCondBr(builder, initialCondV, loop, afterLoop)
        LLVMPositionBuilderAtEnd(builder, loop)
        
        // gen the IR for the inner block
        let loopStackFrame = StackFrame(block: loop, function: stackFrame.function, parentStackFrame: stackFrame)
        try block.bbGenInline(stackFrame: loopStackFrame)
        
        // conditional break
        let conditionalRepeat = try condition.nodeCodeGen(stackFrame)
        let conditionalRepeatV = try conditionalRepeat.load("value", fromType: condition._type, builder: builder)
        LLVMBuildCondBr(builder, conditionalRepeatV, loop, afterLoop)
        
        // move back to loop / end loop
        LLVMPositionBuilderAtEnd(builder, afterLoop)
        stackFrame.block = afterLoop
        
        return nil
    }
    
}


private extension BlockExpr {
    
    /// Generates children’s code directly into the current scope & block
    private func bbGenInline(stackFrame stackFrame: StackFrame) throws {
        try exprs.walkChildren { exp in try exp.nodeCodeGen(stackFrame) }
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpr : IRGenerator {
    
    private func arrInstance(stackFrame: StackFrame) throws -> ArrayVariable {
        
        // assume homogeneous
        guard let elementType = elType?.globalType(module) else { throw error(IRError.TypeNotFound, userVisible: false) }
        let arrayType = LLVMArrayType(elementType, UInt32(arr.count))
        
        // allocate memory for arr
        let a = LLVMBuildArrayAlloca(builder, arrayType, nil, "arr")
        
        // obj
        let vars = try arr.map(codeGenIn(stackFrame))
        return ArrayVariable(ptr: a, elType: elementType, arrType: arrayType, irGen: (builder, module), vars: vars)
    }
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        return try arrInstance(stackFrame).load()
    }
    
}


extension ArraySubscriptExpr : IRGenerator {
    
    private func backingArrayVariable(stackFrame: StackFrame) throws -> ArrayVariable {
        guard case let v as VariableExpr = arr, case let arr as ArrayVariable = try stackFrame.variable(v.name) else { throw error(IRError.SubscriptingNonVariableTypeNotAllowed) }
        return arr
    }
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {

        let arr = try backingArrayVariable(stackFrame)
        let idx = try index.nodeCodeGen(stackFrame)
        
        return arr.loadElementAtIndex(idx)
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Structs
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        guard let type = self.type else { throw error(IRError.NotTyped, userVisible: false) }
        
        stackFrame.addType(type, named: name)

        try initialisers.walkChildren { i in
            try i.codeGen(stackFrame)
        }
        
        try methods.walkChildren { m in
            try m.codeGen(stackFrame)
        }

        return nil
    }
    
}

extension ConceptExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        guard let conceptType = type else { throw error(IRError.NotTyped, userVisible: false) }
        
        stackFrame.addConcept(conceptType, named: name)
        
        
        return nil
    }
}

extension InitialiserDecl : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        let paramTypeNames = ty.paramType.typeNames(), paramCount = paramTypeNames.count
        guard let
            functionType = ty.type?.globalType(module),
            name = parent?.name,
            parentProperties = parent?.properties,
            parentType = parent?.type
            else {
                throw error(IRError.TypeNotFound, userVisible: false)
        }
        
        // make function
        let function = LLVMAddFunction(module, mangledName, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        LLVMAddFunctionAttr(function, LLVMAlwaysInlineAttribute)
        
        guard let impl = self.impl else {
            return function
        }
        
        let entry = LLVMAppendBasicBlock(function, "entry")
        LLVMPositionBuilderAtEnd(builder, entry)

        // Add function type to stack frame
        stackFrame.addFunctionType(functionType, named: name)
        
        // stack frame internal to initialiser, cannot capture from surrounding scope
        let initStackFrame = StackFrame(function: function, parentStackFrame: nil, _isStdLib: stackFrame.isStdLib)
        
        // set function param names and update table
        // TODO: Split this out into a function for funcs & closures to use as well
        for i in 0..<paramCount {
            let param = LLVMGetParam(function, UInt32(i))
            let paramName = impl.params[i] ?? i.implicitParamName()
            LLVMSetValueName(param, paramName)
            
            let tyName = paramTypeNames[i]
            
            switch try stackFrame.type(tyName) {
            case let t as StructType:
                let s = ParameterStructVariable(val: param, type: t, irName: paramName, irGen: (builder, module))
                initStackFrame.addVariable(s, named: paramName)
                
            case let c as ConceptType:
                let e = ExistentialVariable.alloc(param, conceptType: c, irName: paramName, irGen: (builder, module))
                initStackFrame.addVariable(e, named: paramName)
                
            default:
                let s = StackVariable(val: param, irName: paramName, irGen: (builder, module))
                initStackFrame.addVariable(s, named: paramName)
            }
        }
        
        // allocate struct
        let s = MutableStructVariable.alloc(parentType, irName: parentType.name, irGen: (builder, module))
        stackFrame.addVariable(s, named: name)
        
        // add struct properties into scope
        for el in parentProperties {
            let p = SelfReferencingMutableVariable(propertyName: el.name, parent: s) // initialiser can always assign
            initStackFrame.addVariable(p, named: el.name)
        }
        
        // add args into scope
        try impl.body.exprs.walkChildren { exp in
            try exp.nodeCodeGen(initStackFrame)
        }
        
        // return struct instance from init function
        LLVMBuildRet(builder, s.value)
        
        LLVMPositionBuilderAtEnd(builder, stackFrame.block)
        return function
    }
}

extension PropertyLookupExpr : IRGenerator {
        
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        switch object {
        case let n as VariableExpr:
            guard case let variable as StructVariable = try stackFrame.variable(n.name) else { throw error(IRError.NoVariable(n.name)) }
            return try variable.loadPropertyNamed(name)
            
        case let propertyLookup as PropertyLookupExpr:
            let p = try propertyLookup.codeGen(stackFrame)
            return try p.load(name, fromType: propertyLookup._type, builder: builder, irName: String.fromCString(LLVMGetValueName(p))! + ".\(name)")
            
//        case let tupleLookup as TupleMemberLookupExpr:
//            break
            
        default:
            throw error(IRError.CannotLookupPropertyFromNonVariable)
        }
    }
}


extension MethodCallExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        // get method from module
        let f = LLVMGetNamedFunction(module, mangledName)
        let c = self.args.elements.count + 1
        
        guard let structType = self.structType else { throw error(IRError.NotStructType, userVisible: false) }
        
        // need to add self to beginning of params
        let ob = try object.nodeCodeGen(stackFrame)
        
        guard case let variable as VariableExpr = object else { throw error(IRError.CannotLookupPropertyFromNonVariable, userVisible: false) } // FIXME: this should be possible
        guard case let selfRef as MutableStructVariable = try stackFrame.variable(variable.name) else { throw error(IRError.NoVariable(variable.name), userVisible: false) }
        
        let args = try self.args.elements.map(codeGenIn(stackFrame))
        
        let argBuffer = ([selfRef.ptr] + args).ptr()
        defer { argBuffer.dealloc(c) }
        
        let doNotUseName = _type == BuiltinType.Void || _type == BuiltinType.Null || _type == nil
        let n = doNotUseName ? "" : "\(name).res"
        
        return LLVMBuildCall(builder, f, argBuffer, UInt32(c), n)
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Tuples
//-------------------------------------------------------------------------------------------------------------------------

extension TupleExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        if elements.count == 0 { return nil }
        
        guard let type = self.type else { throw error(IRError.NotTyped, userVisible: false) }
        
        let memeberIR = try elements.map(codeGenIn(stackFrame))
        
        let s = MutableTupleVariable.alloc(type, irGen: (builder, module))
        
        for (i, el) in memeberIR.enumerate() {
            try s.store(el, inPropertyAtIndex: i)
        }
        
        return s.value
    }
}

extension TupleMemberLookupExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame) throws -> LLVMValueRef {
        
        guard case let n as VariableExpr = object else { throw error(IRError.CannotLookupPropertyFromNonVariable, userVisible: false) }
        guard case let variable as TupleVariable = try stackFrame.variable(n.name) else { throw error(IRError.NoTupleMemberAt(index))}
        
        return try variable.loadPropertyAtIndex(index)
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 AST Gen
//-------------------------------------------------------------------------------------------------------------------------


extension AST {
    
    func IRGen(module m: LLVMModuleRef, isLibrary: Bool, stackFrame s: StackFrame) throws {
        
        // initialise global objects
        builder = LLVMCreateBuilder()
        module = m
        
        // main arguments
        let argBuffer = [LLVMTypeRef]().ptr()
        defer { argBuffer.dealloc(0) }
        
        // make main function & add to IR
        let functionType = LLVMFunctionType(LLVMVoidType(), argBuffer, UInt32(0), false)
        let mainFunction = LLVMAddFunction(module, "main", functionType)
        
        // Setup BB & stack frame
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        
        let stackFrame = StackFrame(block: programEntryBlock, function: mainFunction, parentStackFrame: s)
        
        let expressions: [ASTNode]
        
        if isLibrary {
             expressions = exprs.filter { $0 is FuncDecl || $0 is StructExpr }
        }
        else {
            expressions = exprs
        }
        
        try expressions.walkChildren { node in
            try node.nodeCodeGen(stackFrame)
        }
        
        // finalise module
        if isLibrary {
            LLVMDeleteFunction(mainFunction)
        }
        else {
            LLVMBuildRetVoid(builder)
        }
        
        // validate whole module
        try validateModule(module)
        
        LLVMDisposeBuilder(builder)
    }
}










