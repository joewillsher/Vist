//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 15/11/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


/// A type which can generate LLVM IR code
protocol IRGenerator {
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef
}

private protocol BasicBlockGenerator {
    func bbGen(innerStackFrame stackFrame: StackFrame, irGen: IRGen, fn: LLVMValueRef) throws -> LLVMBasicBlockRef
}

protocol RuntimeVariableProvider {
    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable
}

extension RuntimeVariableProvider where Self: ChainableExpr {
    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable {
        return try _type!.variableForVal(codeGen(stackFrame, irGen: irGen), irGen: irGen)
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Helpers
//-------------------------------------------------------------------------------------------------------------------------

extension ASTNode {
    
    private func nodeCodeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        guard case let gen as IRGenerator = self else { throw irGenError(.notIRGenerator(self.dynamicType)) }
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

// Extends LLVM bool to be initialisable from bool literal, and usable
// as condition
extension LLVMBool: BooleanType, BooleanLiteralConvertible {
    
    public init(booleanLiteral value: Bool) {
        self.init(value ? 1: 0)
    }
    
    public var boolValue: Bool {
        return self == 1
    }
}

/// Curried impl of `Expr.codeGenIn(_:irGen:)`.
/// Returns a function which maps the codegen on a expr
func codeGenIn(stackFrame: StackFrame, irGen: IRGen) -> Expr throws -> LLVMValueRef {
    return { e in try e.nodeCodeGen(stackFrame, irGen: irGen) }
}


private func validateModule(ref: LLVMModuleRef) throws {
    var err = UnsafeMutablePointer<Int8>.alloc(1)
    guard !LLVMVerifyModule(ref, LLVMReturnStatusAction, &err) else {
        throw irGenError(.invalidModule(ref, String.fromCString(err)), userVisible: true)
    }
}


private func validateFunction(ref: LLVMValueRef, name: String) throws {
    guard !LLVMVerifyFunction(ref, LLVMReturnStatusAction) else {
        throw irGenError(.invalidFunction(name), userVisible: true)
    }
}




/**************************************************************************************************************************/
// MARK: -                                                 IR GEN


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Literals
//-------------------------------------------------------------------------------------------------------------------------

extension IntegerLiteral: RuntimeVariableProvider, IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        let rawType = BuiltinType.int(size: size).globalType(irGen.module)
        let value = LLVMConstInt(rawType, UInt64(val), false)
        
        guard let type = type else { throw semaError(.integerNotTyped) }
        return try type.initialiseStdTypeFromBuiltinMembers(value, irGen: irGen)
    }
    
    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable {
        let v = MutableStructVariable.alloc(type!, irGen: irGen)
        v.value = try codeGen(stackFrame, irGen: irGen)
        return v
    }
}


extension FloatingPointLiteral: RuntimeVariableProvider, IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) -> LLVMValueRef {
        return LLVMConstReal(type!.globalType(nil), val)
    }
    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable {
        return StackVariable(val: codeGen(stackFrame, irGen: irGen), irName: "", irGen: irGen)
    }
}


extension BooleanLiteral: RuntimeVariableProvider, IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        let rawType = BuiltinType.bool.globalType(irGen.module)
        let value = LLVMConstInt(rawType, UInt64(val.hashValue), false)
        
        guard let type = type else { throw semaError(.boolNotTyped) }
        return try type.initialiseStdTypeFromBuiltinMembers(value, irGen: irGen)
    }
    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable {
        let v = MutableStructVariable.alloc(type!, irGen: irGen)
        v.value = try codeGen(stackFrame, irGen: irGen)
        return v
    }
}


extension StringLiteral: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) -> LLVMValueRef {
        
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

extension VariableExpr: RuntimeVariableProvider, IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        let variable = try stackFrame.variable(name)
        return variable.value
    }
    
    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable {
        return try stackFrame.variable(name)
    }
}


extension VariableDecl: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let irName = name.stringByReplacingOccurrencesOfString("$", withString: "d")
        
        if case let arr as ArrayExpr = value {
            //if asigning to array
            
            let a = try arr.arrInstance(stackFrame, irGen: irGen)
            a.allocHead(irGen.builder, name: irName, mutable: isMutable)
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
            guard v != nil else { throw irGenError(.cannotAssignToType(value.dynamicType)) }
            let type = LLVMTypeOf(v)
            guard type != LLVMVoidType() else { throw irGenError(.cannotAssignToVoid) }
            
            // create variable
            let variable: MutableVariable
            
            switch value._type {
            case let structType as StructType:
                variable = MutableStructVariable.alloc(structType, irName: irName, irGen: irGen)
                
            case let tupleType as TupleType:
                variable = MutableTupleVariable.alloc(tupleType, irName: irName, irGen: irGen)
                
            case let existentialType as ConceptType:
                let existentialVariable = ExistentialVariable.assignFromExistential(v, conceptType: existentialType, mutable: isMutable, irName: irName, irGen: irGen)
                stackFrame.addVariable(existentialVariable, named: name)
                return v
                
            case let ty?:
                variable = ReferenceVariable.alloc(ty, irName: name, irGen: irGen)
                
            default:
                throw irGenError(.notTyped)
            }
            
            // Load in memory
            variable.value = v
            // update stack frame variables
            stackFrame.addVariable(variable, named: name)
            
            return v
        }
    }
}


extension MutationExpr: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
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
                
                guard case let v as MutableVariable = variable else { throw irGenError(.notMutable(object.name)) }
                v.value = new
            }
        case let sub as ArraySubscriptExpr:
            
            let arr = try sub.backingArrayVariable(stackFrame, irGen: irGen)
            
            let i = try sub.index.nodeCodeGen(stackFrame, irGen: irGen)
            let val = try value.nodeCodeGen(stackFrame, irGen: irGen)
            
            arr.store(val, inElementAtIndex: i)

        case let tupMemberLookup as TupleMemberLookupExpr:
            // tuple.1 = newValue
            
            guard case let storageVariable as MutableVariable = try tupMemberLookup.variableGen(stackFrame, irGen: irGen) else { throw irGenError(.noTupleMemberAt(tupMemberLookup.index)) }
            storageVariable.value = try value.nodeCodeGen(stackFrame, irGen: irGen)
            
        case let propertyLookup as PropertyLookupExpr:
            // foo.bar = newValue
            
            guard case let storageVariable as MutableVariable = try propertyLookup.variableGen(stackFrame, irGen: irGen) else { throw irGenError(.noProperty(type: propertyLookup.object.typeName, property: propertyLookup.propertyName)) }
            storageVariable.value = try value.nodeCodeGen(stackFrame, irGen: irGen)
            
        default:
            throw irGenError(.unreachable)
        }
        
        return nil
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Exprs
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpr: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let lIR = try lhs.nodeCodeGen(stackFrame, irGen: irGen), rIR = try rhs.nodeCodeGen(stackFrame, irGen: irGen)
        guard let argTypes = [lhs, rhs].optionalMap({ $0._type }), fnType = self.fnType else { throw irGenError(.notTyped) }
        
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
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(2) else { throw irGenError(.wrongFunctionApplication(op)) }
        
        let doNotUseName = _type == BuiltinType.void || _type == BuiltinType.null || _type == nil
        let n = doNotUseName ? "": "\(op).res"
        
        // add call to IR
        let call = LLVMBuildCall(irGen.builder, fn, argBuffer, UInt32(2), n)
        fnType.addMetadataTo(call)
        
        return call
    }
}


extension Void: IRGenerator {
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        return nil
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------

extension FunctionCallExpr: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let args = try self.args.elements.map(codeGenIn(stackFrame, irGen: irGen))

        // Lookup from builtin
        if let function = builtinInstruction(name, irGen: irGen) {
            return try function(args)
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
        guard let paramTypes = self.fnType?.params, let argTypes = self.args.elements.optionalMap({ $0._type }) else { throw semaError(.paramsNotTyped) }
        
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
        
        guard fn != nil && LLVMCountParams(fn) == UInt32(argCount) else { throw irGenError(.wrongFunctionApplication(name)) }
        
        let doNotUseName = _type == BuiltinType.void || _type == BuiltinType.null || _type == nil
        let n = doNotUseName ? "": "\(name)_res"
        
        // add call to IR
        let call = LLVMBuildCall(irGen.builder, fn, argBuffer, UInt32(argCount), n)
        
        guard let fnType = self.fnType else { throw irGenError(.notTyped) }
        fnType.addMetadataTo(call)
        
        return call
    }
    
}


private extension FunctionType {
    
    private func paramTypeIR(irGen: IRGen) throws -> [LLVMTypeRef] {
        guard let res = type else { throw irGenError(.typeNotFound) }
        return try res.nonVoid.map(globalType(irGen.module))
    }
}


/// Creates or gets a function pointer
func ptrToFunction(mangledName: String, type: FnType, module: LLVMModuleRef) -> LLVMValueRef {
    let f = LLVMGetNamedFunction(module, mangledName)
    
    // if already defined, we return it
    if f != nil { return f }
    
    // otherwise we create a prototype
    let newPointer = LLVMAddFunction(module, mangledName, type.globalType(module))
    return newPointer
}


extension FuncDecl: IRGenerator {
    // function definition
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let type: FnType
        let startIndex: Int // where do the user's params start being used, 0 for free funcs and 1 for methods
        let parentType: StorageType? // the type of self is its a method
        
        let paramTypeNames = fnType.paramType.typeNames(), paramCount = paramTypeNames.count
        
        if let parent = self.parent {
            guard case let _parentType as StorageType = parent._type else { throw irGenError(.noParentType) }
            guard let _type = fnType.type else { throw irGenError(.typeNotFound) }
            
            type = _type.withParent(_parentType)
            startIndex = 1
            parentType = _parentType
        }
        else {
            guard let t = fnType.type else { throw irGenError(.typeNotFound) }
            
            type = t
            startIndex = 0
            parentType = nil
        }
        
        // If existing function defined and implemented, return it
        let _fn = LLVMGetNamedFunction(irGen.module, mangledName)
        if _fn != nil && LLVMCountParams(_fn) == UInt32(paramCount + startIndex) && LLVMCountBasicBlocks(_fn) != 0 && LLVMGetEntryBasicBlock(_fn) != nil {
            return _fn
        }
        
        // Set params
        let paramBuffer = try fnType.paramTypeIR(irGen).ptr()
        defer { paramBuffer.dealloc(paramCount) }
        
        // make function
        let functionType = type.globalType(irGen.module)
        let function = ptrToFunction(mangledName, type: type, module: irGen.module)
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
            let irName = paramName.stringByReplacingOccurrencesOfString("$", withString: "param")
            LLVMSetValueName(param, paramName)
            
            let tyName = paramTypeNames[i]
            
            switch try stackFrame.type(tyName) {
            case let t as StructType:
                let s = ParameterStorageVariable(val: param, type: t, irName: irName, irGen: irGen)
                functionStackFrame.addVariable(s, named: paramName)
                
            case let c as ConceptType:
                let e = ExistentialVariable.assignFromExistential(param, conceptType: c, mutable: false, irName: irName, irGen: irGen)
                functionStackFrame.addVariable(e, named: paramName)
                
            default:
                let s = StackVariable(val: param, irName: irName, irGen: irGen)
                functionStackFrame.addVariable(s, named: paramName)
            }
        }
        
        // if is a method
        if let parentType = parentType {
            // get self from param list
            let param = LLVMGetParam(function, 0)
            LLVMSetValueName(param, "self")
            // self's members
            
            let r: protocol<MutableVariable, StorageVariable>
            
            switch parentType {
            case let structType as StructType:
                r = MutableStructVariable(type: structType, ptr: param, irName: "self", irGen: irGen)

            case let conceptExistentialType as ConceptType:
                r = ExistentialVariable(ptr: param, conceptType: conceptExistentialType, mutable: false, irName: "self", irGen: irGen)
                
            default:
                throw irGenError(.unreachable)
            }
            
            functionStackFrame.addVariable(r, named: "self")

            // add self's properties implicitly
            for el in parentType.members {
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


extension ReturnStmt: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
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


extension ClosureExpr: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        guard let type = self.type else { throw irGenError(.notTyped) }
        
        let paramBuffer = try type.params.map(globalType(irGen.module)).ptr()
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

extension ConditionalStmt: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
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


extension ForInLoopStmt: IRGenerator {
    
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
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
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
        
        let intType = BuiltinType.int(size: 64)
        
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
        let loopCountInt = try StdLib.IntType.initialiseStdTypeFromBuiltinMembers(loopCount, irGen: irGen, irName: iteratorName)
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
extension WhileLoopStmt: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
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

extension ArrayExpr: IRGenerator {
    
    private func arrInstance(stackFrame: StackFrame, irGen: IRGen) throws -> ArrayVariable {
        
        // assume homogeneous
        guard let elementType = elType?.globalType(irGen.module) else { throw irGenError(.typeNotFound) }
        let arrayType = LLVMArrayType(elementType, UInt32(arr.count))
        
        // allocate memory for arr
        let a = LLVMBuildArrayAlloca(irGen.builder, arrayType, nil, "arr")
        
        // obj
        let vars = try arr.map(codeGenIn(stackFrame, irGen: irGen))
        return ArrayVariable(ptr: a, elType: elementType, arrType: arrayType, irGen: irGen, vars: vars)
    }
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        return try arrInstance(stackFrame, irGen: irGen).load()
    }
    
}


extension ArraySubscriptExpr: IRGenerator {
    
    private func backingArrayVariable(stackFrame: StackFrame, irGen: IRGen) throws -> ArrayVariable {
        guard case let v as VariableExpr = arr, case let arr as ArrayVariable = try stackFrame.variable(v.name) else { throw irGenError(.subscriptingNonVariableTypeNotAllowed) }
        return arr
    }
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {

        let arr = try backingArrayVariable(stackFrame, irGen: irGen)
        let idx = try index.nodeCodeGen(stackFrame, irGen: irGen)
        
        return arr.loadElementAtIndex(idx)
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Structs
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpr: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        guard let type = type else { throw irGenError(.notTyped) }

        // occupy stack frame
        stackFrame.addType(type, named: name)
        
        for genericType in type.genericTypes {
            stackFrame.addType(genericType, named: genericType.name)
        }
        
        // IRGen on elements
        let errorCollector = ErrorCollector()
        
        _ = type.memberTypes(irGen.module)
        
        
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

extension ConceptExpr: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        guard let conceptType = type else { throw irGenError(.notTyped) }
        stackFrame.addConcept(conceptType, named: name)
        
        return nil
    }
}

extension InitialiserDecl: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        let paramTypeNames = ty.paramType.typeNames(), paramCount = paramTypeNames.count
        guard let
            parentType = parent?.type,
            functionType = ty.type?.globalType(irGen.module),
            name = parent?.name,
            parentProperties = parent?.properties
            else {
                throw irGenError(.typeNotFound)
        }
        
        // make function
        let function = LLVMAddFunction(irGen.module, mangledName, functionType)
        LLVMSetFunctionCallConv(function, LLVMCCallConv.rawValue)
        LLVMAddFunctionAttr(function, LLVMAlwaysInlineAttribute)
        
        guard let impl = impl else {
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
            let paramName = impl.params[i]
            let irName = paramName.stringByReplacingOccurrencesOfString("$", withString: "param")
            LLVMSetValueName(param, paramName)
            
            let tyName = paramTypeNames[i]
            
            let variable: RuntimeVariable
            switch try stackFrame.type(tyName) {
            case let t as StructType:
                variable = ParameterStorageVariable(val: param, type: t, irName: irName, irGen: irGen)
                
            case let c as ConceptType:
                variable = ExistentialVariable.assignFromExistential(param, conceptType: c, mutable: false, irName: irName, irGen: irGen)
                
            default:
                variable = StackVariable(val: param, irName: irName, irGen: irGen)
            }
            initStackFrame.addVariable(variable, named: paramName)
        }
        
        // allocate struct, self instance
        let s = MutableStructVariable.alloc(parentType, irName: parentType.name, irGen: irGen)
        initStackFrame.addVariable(s, named: "self")
        
        // add struct properties into scope
        for el in parentProperties {
            let p = SelfReferencingMutableVariable(propertyName: el.name, parent: s)
            initStackFrame.addVariable(p, named: el.name)
        }
        
        // COdegen for block body
        try impl.body.exprs.walkChildren { exp in
            try exp.nodeCodeGen(initStackFrame, irGen: irGen)
        }
        
        // return struct instance from init function
        LLVMBuildRet(irGen.builder, s.value)
        
        LLVMPositionBuilderAtEnd(irGen.builder, stackFrame.block)
        return function
    }
}


extension PropertyLookupExpr: RuntimeVariableProvider, IRGenerator {

    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable {
        guard case let storageVariable as StorageVariable = try object.variableGen(stackFrame, irGen: irGen) else { throw irGenError(.notStructType) }
        guard let type = _type else { throw irGenError(.notTyped) }
        return try type.variableForPtr(try storageVariable.ptrToPropertyNamed(propertyName), irGen: irGen)
    }
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        return try variableGen(stackFrame, irGen: irGen).value
    }
}





extension MethodCallExpr: RuntimeVariableProvider, IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        // get method from module
        let c = self.args.elements.count + 1
        
        guard let structType = structType else { throw irGenError(.notStructType) }
        guard let fnType = fnType else { throw irGenError(.notTyped) }
        
        // need to add self to beginning of params
        let ob = try object.nodeCodeGen(stackFrame, irGen: irGen)
        
        guard case let selfRef as StorageVariable = try object.variableGen(stackFrame, irGen: irGen) else { throw irGenError(.notStructType) }
        
        let functionPtr = try selfRef.ptrToMethodNamed(name, fnType: fnType)
                
        let args = try self.args.elements.map(codeGenIn(stackFrame, irGen: irGen))
        
        let argBuffer = ([selfRef.instancePtr] + args).ptr()
        defer { argBuffer.dealloc(c) }
        
        let doNotUseName = _type == BuiltinType.void || _type == BuiltinType.null || _type == nil
        let n = doNotUseName ? "" : "\(name).res"
        
        return LLVMBuildCall(irGen.builder, functionPtr, argBuffer, UInt32(c), n)
    }
    
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Tuples
//-------------------------------------------------------------------------------------------------------------------------

extension TupleExpr: IRGenerator {
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        
        if elements.count == 0 { return nil }
        guard let type = self.type else { throw irGenError(.notTyped) }
        
        let memeberIR = try elements.map(codeGenIn(stackFrame, irGen: irGen))

        let s = MutableTupleVariable.alloc(type, irGen: irGen)
        
        for (i, el) in memeberIR.enumerate() {
            try s.store(el, inElementAtIndex: i)
        }
        
        return s.value
    }
}

extension TupleMemberLookupExpr: RuntimeVariableProvider, IRGenerator {
    
    func variableGen(stackFrame: StackFrame, irGen: IRGen) throws -> RuntimeVariable {
        guard case let tupleVariable as TupleVariable = try object.variableGen(stackFrame, irGen: irGen) else { throw irGenError(.notTupleType) }
        guard let type = _type else { throw irGenError(.notTyped) }
        return try type.variableForPtr(tupleVariable.ptrToElementAtIndex(index), irGen: irGen)
    }
    
    func codeGen(stackFrame: StackFrame, irGen: IRGen) throws -> LLVMValueRef {
        return try variableGen(stackFrame, irGen: irGen).value
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






