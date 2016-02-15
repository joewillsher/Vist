//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 15/11/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


/// A type which can generate LLVM IR code
private protocol IRGenerator {
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef
}

private protocol BasicBlockGenerator {
    func bbGen(innerStackFrame stackFrame: StackFrame, irGen: IRGen, fn: LLVMValueRef) throws -> LLVMBasicBlockRef
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Helpers
//-------------------------------------------------------------------------------------------------------------------------

extension ASTNode {
    
    private func nodeCodeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        guard case let gen as IRGenerator = self else { throw error(IRError.NotGenerator(self.dynamicType), userVisible: false) }
        return try gen.codeGen(stackFrame, irGen: irGen)
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

private func codeGenIn(stackFrame: StackFrame, irGen: IRGen) -> Expr throws -> LLVMValueRef {
    return { e in try e.nodeCodeGen(stackFrame, irGen: irGen) }
}

private func validateModule(ref: LLVMModuleRef) throws {
    var err = UnsafeMutablePointer<Int8>.alloc(1)
    guard !LLVMVerifyModule(ref, LLVMReturnStatusAction, &err) else {
        throw error(IRError.InvalidModule(ref, String.fromCString(err)), userVisible: false)
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
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        let rawType = BuiltinType.Int(size: size)
        let value = LLVMConstInt(rawType.ir(), UInt64(val), false)
        
        guard let type = self.type else { throw error(SemaError.IntegerNotTyped, userVisible: false) }
        return type.initialiseStdTypeFromBuiltinMembers(value, irGen: irGen)
    }
}


extension FloatingPointLiteral : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) -> LLVMValueRef {
        return LLVMConstReal(type!.ir(), val)
    }
}


extension BooleanLiteral : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        let rawType = BuiltinType.Bool
        let value = LLVMConstInt(rawType.ir(), UInt64(val.hashValue), false)
        
        guard let type = self.type else { throw error(SemaError.BoolNotTyped, userVisible: false) }
        return type.initialiseStdTypeFromBuiltinMembers(value, irGen: irGen)
    }
}


extension StringLiteral : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) -> LLVMValueRef {
        
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
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        let variable = try stackFrame.variable(name)
        return variable.value
    }
}


extension VariableDecl : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        if case let arr as ArrayExpr = value {
            //if asigning to array
            
            let a = try arr.arrInstance(stackFrame, irGen: irGen)
            a.allocHead(irGen.builder, name: name, mutable: isMutable)
            stackFrame.addVariable(a, named: name)
            
            return a.ptr
        }
        else if case let ty as FnType = value._type {
            // handle assigning a closure
            
            // Function being made
            let fn = LLVMAddFunction(irGen.module, name, ty.globalType(irGen.module))
            
            // make and move into entry block
            let entryBlock = LLVMAppendBasicBlock(fn, "entry")
            LLVMPositionBuilderAtEnd(irGen.builder, entryBlock)
            
            // stack frame of fn
            let fnStackFrame = StackFrame(block: entryBlock, function: fn, parentStackFrame: stackFrame)
            
            // value’s IR, this needs to be called and returned
            let v = try value.nodeCodeGen(fnStackFrame, irGen: irGen)
            
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
            let call = LLVMBuildCall(irGen.builder, v, args, num, "")
            
            // return this value from `fn`
            LLVMBuildRet(irGen.builder, call)
            
            // move into bb from before
            LLVMPositionBuilderAtEnd(irGen.builder, stackFrame.block)
            
            return fn
        }
        else {
            // all other types
            
            // create value
            let v = try value.nodeCodeGen(stackFrame, irGen: irGen)
            
            // checks
            guard v != nil else { throw error(IRError.CannotAssignToType(value.dynamicType), userVisible: false) }
            let type = LLVMTypeOf(v)
            guard type != LLVMVoidType() else { throw error(IRError.CannotAssignToVoid, userVisible: false) }
            
            // create variable
            let variable: MutableVariable
            
            switch value._type {
            case let structType as StructType:
                variable = MutableStructVariable.alloc(structType, irName: name, irGen: irGen)
                
            case let tupleType as TupleType:
                variable = MutableTupleVariable.alloc(tupleType, irName: name, irGen: irGen)
                
            case let existentialType as ConceptType:
                let existentialVariable = ExistentialVariable.alloc(existentialType, fromExistential: v, mutable: isMutable, irName: name, irGen: irGen)
                stackFrame.addVariable(existentialVariable, named: name)
                return v
                
            default:
                variable = ReferenceVariable.alloc(type, irName: name, irGen: irGen)
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
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        switch object {
        case let object as VariableExpr:
            // object = newValue
            
            let variable = try stackFrame.variable(object.name)
            
            if case let arrayVariable as ArrayVariable = variable, case let arrayExpression as ArrayExpr = value {
                
                let newArray = try arrayExpression.arrInstance(stackFrame, irGen: irGen)
                arrayVariable.assignFrom(newArray)
            }
            else {
                let new = try value.nodeCodeGen(stackFrame, irGen: irGen)
                
                guard case let v as MutableVariable = variable else { throw error(IRError.NotMutable(object.name), userVisible: false) }
                v.value = new
            }
        case let sub as ArraySubscriptExpr:
            
            let arr = try sub.backingArrayVariable(stackFrame, irGen: irGen)
            
            let i = try sub.index.nodeCodeGen(stackFrame, irGen: irGen)
            let val = try value.nodeCodeGen(stackFrame, irGen: irGen)
            
            arr.store(val, inElementAtIndex: i)

        case let prop as PropertyLookupExpr:
            // foo.bar = meme
            
            guard case let n as VariableExpr = prop.object else { throw error(IRError.CannotLookupPropertyFromNonVariable, userVisible: false) }
            
            guard case let variable as MutableStructVariable = try stackFrame.variable(n.name) else {
                if try stackFrame.variable(n.name) is ParameterStructVariable { throw error(IRError.CannotMutateParam) }
                throw error(IRError.NoProperty(type: prop._type.description, property: n.name))
            }
                        
            let val = try value.nodeCodeGen(stackFrame, irGen: irGen)
            
            try variable.store(val, inPropertyNamed: prop.propertyName)
            
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
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let lIR = try lhs.nodeCodeGen(stackFrame, irGen: irGen), rIR = try rhs.nodeCodeGen(stackFrame, irGen: irGen)
        guard let argTypes = [lhs, rhs].optionalMap({ $0._type }), fnType = self.fnType else { throw error(SemaError.ParamsNotTyped, userVisible: false) }
        
        let fn: LLVMValueRef
        
        if let (type, fnIR) = StdLib.getFunctionIR(mangledName, module: irGen.module) {
            fn = fnIR
        }
        else {
            fn = LLVMGetNamedFunction(irGen.module, mangledName)
        }
        
        // arguments
        let argBuffer = [lIR, rIR].ptr()
        defer { argBuffer.dealloc(2) }
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(2) else { throw error(IRError.WrongFunctionApplication(op), userVisible: false) }
        
        let doNotUseName = _type == BuiltinType.Void || _type == BuiltinType.Null || _type == nil
        let n = doNotUseName ? "" : "\(op).res"
        
        // add call to IR
        let call = LLVMBuildCall(irGen.builder, fn, argBuffer, UInt32(2), n)
        fnType.addMetadataTo(call)
        
        return call
    }
}


extension Void : IRGenerator {
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        return nil
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------

extension FunctionCallExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let args = try self.args.elements.map(codeGenIn(stackFrame, irGen: irGen))

        // Lookup
        if let function = builtinBinaryInstruction(name, irGen: irGen) {
            guard args.count == 2 else { throw error(IRError.WrongFunctionApplication(name), userVisible: false) }
            return try function(args[0], args[1])
        }
        else if let function = builtinInstruction(name, irGen: irGen) {
            guard args.count == 0 else { throw error(IRError.WrongFunctionApplication(name), userVisible: false) }
            return function()
        }
        
        // get function decl IR
        let fn: LLVMValueRef
        
        if let (_, f) = StdLib.getFunctionIR(mangledName, module: irGen.module) {
            fn = f
        }
        else {
            fn = LLVMGetNamedFunction(irGen.module, mangledName)
        }
        
        let argCount = self.args.elements.count
        guard let paramTypes = self.fnType?.params, let argTypes = self.args.elements.optionalMap({ $0._type }) else { throw error(SemaError.ParamsNotTyped, userVisible: false) }
        
        var argBuff: [LLVMValueRef] = []
        
        for i in 0..<argCount {
            let ref = args[i], argType = argTypes[i], paramType = paramTypes[i]
            
            guard case let paramConceptType as ConceptType = paramType, case let structType as StructType = argType else {
                argBuff.append(ref)
                continue
            }
            
            let existentialVariable = try ExistentialVariable.alloc(structType, conceptType: paramConceptType, initWithValue: ref, mutable: false, irGen: irGen)
            argBuff.append(existentialVariable.value)
        }
        
        // arguments
        let argBuffer = argBuff.ptr()
        defer { argBuffer.dealloc(argCount) }
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else { throw error(IRError.WrongFunctionApplication(name), userVisible: false) }
        
        let doNotUseName = _type == BuiltinType.Void || _type == BuiltinType.Null || _type == nil
        let n = doNotUseName ? "" : "\(name)_res"
        
        // add call to IR
        let call = LLVMBuildCall(irGen.builder, fn, argBuffer, UInt32(argCount), n)
        
        guard let fnType = self.fnType else { throw error(IRError.NotTyped, userVisible: false) }
        fnType.addMetadataTo(call)
        
        return call
    }
    
}


private extension FunctionType {
    
    private func paramTypeIR(irGen: IRGen) throws -> [LLVMTypeRef] {
        guard let res = type else { throw error(IRError.TypeNotFound, userVisible: false) }
        return try res.nonVoid.map(globalType(irGen.module))
    }
}


extension FuncDecl : IRGenerator {
    // function definition
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
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
        let _fn = LLVMGetNamedFunction(irGen.module, mangledName)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(paramCount + startIndex) && LLVMCountBasicBlocks(_fn) != 0 && LLVMGetEntryBasicBlock(_fn) != nil {
            return _fn
        }
        
        // Set params
        let paramBuffer = try fnType.paramTypeIR(irGen).ptr()
        defer { paramBuffer.dealloc(paramCount) }
        
        // make function
        let functionType = type.globalType(irGen.module)
        let function = LLVMAddFunction(irGen.module, mangledName, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        
        if irGen.isStdLib {
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
        LLVMPositionBuilderAtEnd(irGen.builder, entryBlock) // TODO: If isStdLib
        
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
                let s = ParameterStructVariable(val: param, type: t, irName: paramName, irGen: irGen)
                functionStackFrame.addVariable(s, named: paramName)
                
            case let c as ConceptType:
                let e = ExistentialVariable.alloc(c, fromExistential: param, mutable: false, irName: paramName, irGen: irGen)
                functionStackFrame.addVariable(e, named: paramName)
                
            default:
                let s = StackVariable(val: param, irName: paramName, irGen: irGen)
                functionStackFrame.addVariable(s, named: paramName)
            }
        }
        
        // if is a method
        if let parentType = parentType {
            // get self from param list
            let param = LLVMGetParam(function, 0)
            LLVMSetValueName(param, "self")
            // self's members
            
            let r = MutableStructVariable(type: parentType, ptr: param, irName: "self", irGen: irGen)
            functionStackFrame.addVariable(r, named: "self")
            
            // add self's properties implicitly
            for el in parent?.properties ?? [] {
                let p = SelfReferencingMutableVariable(propertyName: el.name, parent: r)
                functionStackFrame.addVariable(p, named: el.name)
            }
        }
        
        // generate bb for body
        do {
            try impl?.body.bbGen(innerStackFrame: functionStackFrame, ret: type.returns.globalType(irGen.module), irGen: irGen)
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
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        if expr._type?.globalType(irGen.module) == LLVMVoidType() {
            return LLVMBuildRetVoid(irGen.builder)
        }
        
        let v = try expr.nodeCodeGen(stackFrame, irGen: irGen)
        return LLVMBuildRet(irGen.builder, v)
    }
    
}


extension BlockExpr {
    
    private func bbGen(innerStackFrame stackFrame: StackFrame, ret: LLVMValueRef, irGen: IRGen) throws {
        
        // code gen for function
        try exprs.walkChildren { exp in
            try exp.nodeCodeGen(stackFrame, irGen: irGen)
        }
        
        if exprs.isEmpty || (ret != nil && ret == LLVMVoidType()) {
            LLVMBuildRetVoid(irGen.builder)
        }
        
        // reset builder head to parent’s stack frame
        LLVMPositionBuilderAtEnd(irGen.builder, stackFrame.parentStackFrame!.block)
    }
    
}


extension ClosureExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        guard let type = self.type else { throw error(IRError.NotTyped, userVisible: false) }
        
        let paramBuffer = try type.params.map(ir).ptr()
        defer { paramBuffer.dealloc(type.params.count) }
        
        let name = "closure"//.mangle()
        
        let functionType = type.globalType(irGen.module)
        let function = LLVMAddFunction(irGen.module, name, functionType)
        
        // setup function block
        let entryBlock = LLVMAppendBasicBlock(function, "entry")
        LLVMPositionBuilderAtEnd(irGen.builder, entryBlock)
        
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
//                let ptr = LLVMBuildAlloca(irGen.builder, ty, "ptr\(name)")
//                LLVMBuildStore(irGen.builder, param, ptr)
//                
//                let tyName = type.params[i].name
//                let t = try stackFrame.type(tyName)
//                
//                let memTys = try t.members.map { ($0.0, try $0.1.globalType(irGen.module), $0.2) }
//                
//                let s = MutableStructVariable(type: ty, ptr: ptr, mutable: false, builder: irGen.builder, properties: memTys)
//                functionStackFrame.addVariable(name, val: s)
//            }
//            else {
                let s = StackVariable(val: param, irName: name, irGen: irGen)
                functionStackFrame.addVariable(s, named: name)
//            }
        }
        
        do {
            try BlockExpr(exprs: exprs).bbGen(innerStackFrame: functionStackFrame, ret: type.returns.globalType(irGen.module), irGen: irGen)
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
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        // block leading into and out of current if block
        var ifIn: LLVMBasicBlockRef = stackFrame.block
        var ifOut: LLVMBasicBlockRef = nil
        
        let leaveIf = LLVMAppendBasicBlock(stackFrame.function, "cont.stmt")
        var rets = true // whether all blocks return
        
        for (i, statement) in statements.enumerate() {
            
            LLVMPositionBuilderAtEnd(irGen.builder, ifIn)
            
            /// States whether the block being appended returns from the current scope
            let returnsFromScope = statement.block.exprs.contains { $0 is ReturnStmt }
            rets = rets && returnsFromScope
            
            // condition
            let cond = try statement.condition?.nodeCodeGen(stackFrame, irGen: irGen)
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
            let block = try statement.bbGen(innerStackFrame: tStackFrame, contBlock: leaveIf, irGen: irGen, name: statement.ifBBID(n: i))
            
            // move builder to in scope
            LLVMPositionBuilderAtEnd(irGen.builder, ifIn)
            
            if let cond = cond { //if statement, make conditonal jump
                let v = try cond.load("value", fromType: statement.condition?._type, builder: irGen.builder)
                LLVMBuildCondBr(irGen.builder, v, block, ifOut)
            }
            else { // else statement, uncondtional jump
                LLVMBuildBr(irGen.builder, block)
                break
            }
            
            ifIn = ifOut
        }
        
        LLVMPositionBuilderAtEnd(irGen.builder, leaveIf)
        stackFrame.block = ifOut
        
        return nil
    }
}


private extension ElseIfBlockStmt {
    
    /// Create the basic block for the if Expr
    private func bbGen(innerStackFrame stackFrame: StackFrame, contBlock: LLVMBasicBlockRef, irGen: IRGen, name: String) throws -> LLVMBasicBlockRef {
        
        // add block
        let basicBlock = LLVMAppendBasicBlock(stackFrame.function, name)
        LLVMPositionBuilderAtEnd(irGen.builder, basicBlock)
        
        // parse code
        try block.bbGenInline(stackFrame: stackFrame, irGen: irGen)
        
        // if the block does continues to the contBlock, move the builder there
        let returnsFromScope = block.exprs.contains { $0 is ReturnStmt }
        if !returnsFromScope {
            LLVMBuildBr(irGen.builder, contBlock)
            LLVMPositionBuilderAtEnd(irGen.builder, contBlock)
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

    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        // generate loop and termination blocks
        let loopHeader = LLVMAppendBasicBlock(stackFrame.function, "loop.header")
        let loopBody =   LLVMAppendBasicBlock(stackFrame.function, "loop.body")
        let loopLatch =  LLVMAppendBasicBlock(stackFrame.function, "loop.latch")
        let afterLoop =  LLVMAppendBasicBlock(stackFrame.function, "loop.exit")
        
        let rangeIterator = try iterator.nodeCodeGen(stackFrame, irGen: irGen)
        
        let startValue = try rangeIterator
            .load("start", fromType: iterator._type, builder: irGen.builder, irName: "start")
            .load("value", fromType: StdLib.IntType, builder: irGen.builder, irName: "start.value")
        let endValue = try rangeIterator
            .load("end",   fromType: iterator._type, builder: irGen.builder, irName: "end")
            .load("value", fromType: StdLib.IntType, builder: irGen.builder, irName: "end.value")
        
        // move into loop block
        LLVMBuildBr(irGen.builder, loopHeader)
        LLVMPositionBuilderAtEnd(irGen.builder, loopHeader)
        
        let intType = BuiltinType.Int(size: 64)
        
        // define variable phi node
        let iteratorName = binded.name
        let loopCount = LLVMBuildPhi(irGen.builder, intType.globalType(irGen.module), "loop.count.\(iteratorName)")
        
        // add incoming value to phi node
        let num1 = [startValue].ptr(), incoming1 = [stackFrame.block].ptr()
        defer { num1.dealloc(1); incoming1.dealloc(1) }
        LLVMAddIncoming(loopCount, num1, incoming1, 1)
        
        // iterate and add phi incoming
        let one = LLVMConstInt(LLVMInt64Type(), UInt64(1), false)
        let next = LLVMBuildAdd(irGen.builder, one, loopCount, "next.\(iteratorName)")
        
        // gen the IR for the inner block
        let loopCountInt = StdLib.IntType.initialiseStdTypeFromBuiltinMembers(loopCount, irGen: irGen, irName: iteratorName)
        let loopVariable = StackVariable(val: loopCountInt, irName: iteratorName, irGen: irGen)
        let loopStackFrame = StackFrame(block: loopBody, vars: [iteratorName: loopVariable], function: stackFrame.function, parentStackFrame: stackFrame)
        
        // Generate loop body
        LLVMBuildBr(irGen.builder, loopBody)
        LLVMPositionBuilderAtEnd(irGen.builder, loopBody)
        try block.bbGenInline(stackFrame: loopStackFrame, irGen: irGen)
        
        LLVMBuildBr(irGen.builder, loopLatch)
        LLVMPositionBuilderAtEnd(irGen.builder, loopLatch)
        
        // conditional break
        let comp = LLVMBuildICmp(irGen.builder, LLVMIntSLE, next, endValue, "loop.repeat.test")
        LLVMBuildCondBr(irGen.builder, comp, loopHeader, afterLoop)
        
        // move back to loop / end loop
        let num2 = [next].ptr(), incoming2 = [loopLatch].ptr()
        defer { num2.dealloc(1); incoming2.dealloc(1) }
        LLVMAddIncoming(loopCount, num2, incoming2, 1)
        
        LLVMPositionBuilderAtEnd(irGen.builder, afterLoop)
        stackFrame.block = afterLoop
        
        return nil
    }
    
}


// TODO: Break statements and passing break-to bb in scope
extension WhileLoopStmt : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        // generate loop and termination blocks
        let loop = LLVMAppendBasicBlock(stackFrame.function, "loop.body")
        let afterLoop = LLVMAppendBasicBlock(stackFrame.function, "loop.exit")
        
        // whether to enter the while, first while check
        let initialCond = try condition.nodeCodeGen(stackFrame, irGen: irGen)
        let initialCondV = try initialCond.load("value", fromType: condition._type, builder: irGen.builder)
        
        // move into loop block
        LLVMBuildCondBr(irGen.builder, initialCondV, loop, afterLoop)
        LLVMPositionBuilderAtEnd(irGen.builder, loop)
        
        // gen the IR for the inner block
        let loopStackFrame = StackFrame(block: loop, function: stackFrame.function, parentStackFrame: stackFrame)
        try block.bbGenInline(stackFrame: loopStackFrame, irGen: irGen)
        
        // conditional break
        let conditionalRepeat = try condition.nodeCodeGen(stackFrame, irGen: irGen)
        let conditionalRepeatV = try conditionalRepeat.load("value", fromType: condition._type, builder: irGen.builder)
        LLVMBuildCondBr(irGen.builder, conditionalRepeatV, loop, afterLoop)
        
        // move back to loop / end loop
        LLVMPositionBuilderAtEnd(irGen.builder, afterLoop)
        stackFrame.block = afterLoop
        
        return nil
    }
    
}


private extension BlockExpr {
    
    /// Generates children’s code directly into the current scope & block
    private func bbGenInline(stackFrame stackFrame: StackFrame, irGen: IRGen) throws {
        try exprs.walkChildren { exp in try exp.nodeCodeGen(stackFrame, irGen: irGen) }
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpr : IRGenerator {
    
    private func arrInstance(stackFrame: StackFrame, irGen: IRGen) throws -> ArrayVariable {
        
        // assume homogeneous
        guard let elementType = elType?.globalType(irGen.module) else { throw error(IRError.TypeNotFound, userVisible: false) }
        let arrayType = LLVMArrayType(elementType, UInt32(arr.count))
        
        // allocate memory for arr
        let a = LLVMBuildArrayAlloca(irGen.builder, arrayType, nil, "arr")
        
        // obj
        let vars = try arr.map(codeGenIn(stackFrame, irGen: irGen))
        return ArrayVariable(ptr: a, elType: elementType, arrType: arrayType, irGen: irGen, vars: vars)
    }
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        return try arrInstance(stackFrame, irGen: irGen).load()
    }
    
}


extension ArraySubscriptExpr : IRGenerator {
    
    private func backingArrayVariable(stackFrame: StackFrame, irGen: IRGen) throws -> ArrayVariable {
        guard case let v as VariableExpr = arr, case let arr as ArrayVariable = try stackFrame.variable(v.name) else { throw error(IRError.SubscriptingNonVariableTypeNotAllowed) }
        return arr
    }
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {

        let arr = try backingArrayVariable(stackFrame, irGen: irGen)
        let idx = try index.nodeCodeGen(stackFrame, irGen: irGen)
        
        return arr.loadElementAtIndex(idx)
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Structs
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        guard let type = self.type else { throw error(IRError.NotTyped, userVisible: false) }

        // occupy stack frame
        stackFrame.addType(type, named: name)
        
        for genericType in type.genericTypes {
            stackFrame.addType(genericType, named: genericType.name)
        }
        
        // IRGen on elements
        let errorCollector = ErrorCollector()
        
        let m = type.memberTypes(irGen.module)
        
        
        try initialisers.walkChildren(errorCollector) { i in
            try i.codeGen(stackFrame, irGen: irGen)
        }
        
        try methods.walkChildren(errorCollector) { m in
            try m.codeGen(stackFrame, irGen: irGen)
        }
        
        try errorCollector.throwIfErrors()
        
        return nil
    }
    
}

extension ConceptExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        guard let conceptType = type else { throw error(IRError.NotTyped, userVisible: false) }
        stackFrame.addConcept(conceptType, named: name)
        
        return nil
    }
}

extension InitialiserDecl : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let paramTypeNames = ty.paramType.typeNames(), paramCount = paramTypeNames.count
        guard let
            functionType = ty.type?.globalType(irGen.module),
            name = parent?.name,
            parentProperties = parent?.properties,
            parentType = parent?.type
            else {
                throw error(IRError.TypeNotFound, userVisible: false)
        }
        
        // make function
        let function = LLVMAddFunction(irGen.module, mangledName, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        LLVMAddFunctionAttr(function, LLVMAlwaysInlineAttribute)
        
        guard let impl = self.impl else {
            return function
        }
        
        let entry = LLVMAppendBasicBlock(function, "entry")
        LLVMPositionBuilderAtEnd(irGen.builder, entry)

        // Add function type to stack frame
        stackFrame.addFunctionType(functionType, named: name)
        
        // stack frame internal to initialiser, cannot capture from surrounding scope
        let initStackFrame = StackFrame(function: function, parentStackFrame: nil)
        
        // set function param names and update table
        // TODO: Split this out into a function for funcs & closures to use as well
        for i in 0..<paramCount {
            let param = LLVMGetParam(function, UInt32(i))
            let paramName = impl.params[i] ?? i.implicitParamName()
            LLVMSetValueName(param, paramName)
            
            let tyName = paramTypeNames[i]
            
            switch try stackFrame.type(tyName) {
            case let t as StructType:
                let s = ParameterStructVariable(val: param, type: t, irName: paramName, irGen: irGen)
                initStackFrame.addVariable(s, named: paramName)
                
            case let c as ConceptType:
                let e = ExistentialVariable.alloc(c, fromExistential: param, mutable: false, irName: paramName, irGen: irGen)
                initStackFrame.addVariable(e, named: paramName)
                
            default:
                let s = StackVariable(val: param, irName: paramName, irGen: irGen)
                initStackFrame.addVariable(s, named: paramName)
            }
        }
        
        // allocate struct
        let s = MutableStructVariable.alloc(parentType, irName: parentType.name, irGen: irGen)
        stackFrame.addVariable(s, named: name)
        
        // add struct properties into scope
        for el in parentProperties {
            let p = SelfReferencingMutableVariable(propertyName: el.name, parent: s) // initialiser can always assign
            initStackFrame.addVariable(p, named: el.name)
        }
        
        // add args into scope
        try impl.body.exprs.walkChildren { exp in
            try exp.nodeCodeGen(initStackFrame, irGen: irGen)
        }
        
        // return struct instance from init function
        LLVMBuildRet(irGen.builder, s.value)
        
        LLVMPositionBuilderAtEnd(irGen.builder, stackFrame.block)
        return function
    }
}

extension PropertyLookupExpr : IRGenerator {
    
    private func codeGenStruct(stackFrame: StackFrame, irGen: IRGen) throws -> (variable: ContainerVariable, propertyRef: LLVMValueRef) {
        
        /// b.foo.t
        // Bar { Foo { Int } }
        
        let variable: StructVariable
        
        switch object {
        case let n as VariableExpr:
            guard case let v as StructVariable = try stackFrame.variable(n.name) else { throw error(IRError.NoVariable(n.name)) }
            variable = v
            
        case let propertyLookup as PropertyLookupExpr:
            
            let (lookupVariable, _) = try propertyLookup.codeGenStruct(stackFrame, irGen: irGen)
            guard case let structVariable as StructVariable = lookupVariable else { throw error(IRError.NoVariable(propertyName)) }
            
            let lookupVal = try structVariable.loadPropertyNamed(propertyLookup.propertyName)
            
            let variable: protocol<StructVariable, MutableVariable>
            
            switch propertyLookup._type {
            case let t as StructType:
                variable = MutableStructVariable.alloc(t, irGen: irGen)
                
            case let c as ConceptType:
                variable = ExistentialVariable.alloc(c, fromExistential: lookupVal, mutable: false, irName: propertyLookup.propertyName, irGen: irGen)
                
            default:
                throw error(IRError.NoVariable(propertyLookup._type?.name ?? "<not typed>"), userVisible: false)
            }
            
            variable.value = lookupVal
            return (variable, try variable.loadPropertyNamed(self.propertyName))
            
        case let tupleLookup as TupleMemberLookupExpr:
            
            let (lookupVariable, _) = try tupleLookup.codeGenStruct(stackFrame, irGen: irGen)
            guard case let structVariable as StructVariable = lookupVariable else { throw error(IRError.NoVariable(tupleLookup.desc)) }
            variable = structVariable
            
        default:
            throw error(IRError.CannotLookupPropertyFromNonVariable)
        }
        
        return (variable, try variable.loadPropertyNamed(propertyName))
    }
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        return try codeGenStruct(stackFrame, irGen: irGen).propertyRef
    }
}


extension MethodCallExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        // get method from module
        let f = LLVMGetNamedFunction(irGen.module, mangledName)
        let c = self.args.elements.count + 1
        
        guard let structType = self.structType else { throw error(IRError.NotStructType, userVisible: false) }
        
        // need to add self to beginning of params
        let ob = try object.nodeCodeGen(stackFrame, irGen: irGen)
        
        guard case let variable as VariableExpr = object else { throw error(IRError.CannotLookupPropertyFromNonVariable, userVisible: false) } // FIXME: this should be possible
        guard case let selfRef as MutableStructVariable = try stackFrame.variable(variable.name) else { throw error(IRError.NoVariable(variable.name), userVisible: false) }
        
        let args = try self.args.elements.map(codeGenIn(stackFrame, irGen: irGen))
        
        let argBuffer = ([selfRef.ptr] + args).ptr()
        defer { argBuffer.dealloc(c) }
        
        let doNotUseName = _type == BuiltinType.Void || _type == BuiltinType.Null || _type == nil
        let n = doNotUseName ? "" : "\(name).res"
        
        return LLVMBuildCall(irGen.builder, f, argBuffer, UInt32(c), n)
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Tuples
//-------------------------------------------------------------------------------------------------------------------------

extension TupleExpr : IRGenerator {
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        if elements.count == 0 { return nil }
        
        guard let type = self.type else { throw error(IRError.NotTyped, userVisible: false) }
        
        let memeberIR = try elements.map(codeGenIn(stackFrame, irGen: irGen))
        
        let s = MutableTupleVariable.alloc(type, irGen: irGen)
        
        for (i, el) in memeberIR.enumerate() {
            try s.store(el, inPropertyAtIndex: i)
        }
        
        return s.value
    }
}

extension TupleMemberLookupExpr : IRGenerator {
    
    private func codeGenStruct(stackFrame: StackFrame, irGen: IRGen) throws -> (variable: ContainerVariable, propertyRef: LLVMValueRef) {
        
        let variable: TupleVariable
        
        switch object {
        case let n as VariableExpr:
            guard case let v as TupleVariable = try stackFrame.variable(n.name) else { throw error(IRError.NoVariable(n.name)) }
            variable = v
            
        case let propertyLookup as PropertyLookupExpr:
            
            let (lookupVariable, _) = try propertyLookup.codeGenStruct(stackFrame, irGen: irGen)
            guard case let tupleVariable as TupleVariable = lookupVariable else { throw error(IRError.NoVariable(propertyLookup.desc)) }
            variable = tupleVariable
            
        case let tupleLookup as TupleMemberLookupExpr:
            
            let (lookupVariable, _) = try tupleLookup.codeGenStruct(stackFrame, irGen: irGen)
            guard case let tupleVariable as TupleVariable = lookupVariable else { throw error(IRError.NoVariable(tupleLookup.desc)) }
            variable = tupleVariable
            
        default:
            throw error(IRError.CannotLookupPropertyFromNonVariable)
        }
        
        return (variable, try variable.loadPropertyAtIndex(index))
    }
    
    private func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        guard case let n as VariableExpr = object else { throw error(IRError.CannotLookupPropertyFromNonVariable, userVisible: false) }
        guard case let variable as TupleVariable = try stackFrame.variable(n.name) else { throw error(IRError.NoTupleMemberAt(index))}
        
        return try variable.loadPropertyAtIndex(index)
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 AST Gen
//-------------------------------------------------------------------------------------------------------------------------


extension AST {
    
    func irGen(module m: LLVMModuleRef, isLibrary: Bool, isStdLib: Bool) throws {
        
        // initialise global objects
        let builder = LLVMCreateBuilder()
        let module = m
        
        // main arguments
        let argBuffer = [LLVMTypeRef]().ptr()
        defer { argBuffer.dealloc(0) }
        
        // make main function & add to IR
        let functionType = LLVMFunctionType(LLVMVoidType(), argBuffer, UInt32(0), false)
        let mainFunction = LLVMAddFunction(module, "main", functionType)
        
        // Setup BB & stack frame
        let programEntryBlock = LLVMAppendBasicBlock(mainFunction, "entry")
        LLVMPositionBuilderAtEnd(builder, programEntryBlock)
        
        let stackFrame = StackFrame(block: programEntryBlock, function: mainFunction)
        
        let expressions: [ASTNode]
        
        if isLibrary {
             expressions = exprs.filter { $0 is FuncDecl || $0 is StructExpr }
        }
        else {
            expressions = exprs
        }
        
        try expressions.walkChildren { node in
            try node.nodeCodeGen(stackFrame, irGen: (builder, module, isStdLib))
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










