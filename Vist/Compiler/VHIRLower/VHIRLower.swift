//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation.NSString

enum IRLowerError: VistError {
    case notLowerable( Value)
    
    var description: String {
        switch self {
        case .notLowerable(let v): return "value '\(v.vhir)' is not Lowerable"
        }
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



typealias IRGen = (builder: LLVMBuilderRef, module: LLVMModuleRef, isStdLib: Bool)


protocol VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef
}

extension Operand: VHIRLower {
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        // if already lowered, we use that
        if loweredValue != nil {
            return loweredValue
        }
            // otherwise we lower it to LLVM IR
        else if case let lowerable as VHIRLower = value {
            setLoweredValue(try lowerable.vhirLower(module, irGen: irGen))
            return loweredValue
        }
            // if it can't be lowered, throw an error
        else {
            throw error(IRLowerError.notLowerable(self))
        }
    }
}

extension Module {
    
    /// Creates or gets a function pointer
    private func getOrAddFunction(named name: String, type: FunctionType, irGen: IRGen) -> LLVMValueRef {
        // if already defined, we return it
        let f = LLVMGetNamedFunction(irGen.module, name)
        if f != nil { return f }
        
        // otherwise we create a new prototype
        let newPointer = LLVMAddFunction(irGen.module, name, type.lowerType(module))
        return newPointer
    }
    
    private func getOrAddRuntimeFunction(named name: String, irGen: IRGen) -> LLVMValueRef {
        let (_, fnType) = Runtime.unmangledFunctionNamed(name)!
        return module.getOrAddFunction(named: name, type: fnType, irGen: irGen)
    }
    
    func vhirLower(module: LLVMModuleRef, isStdLib: Bool) throws {
        
        let irGen = (LLVMCreateBuilder(), module, isStdLib) as IRGen
        loweredModule = module
        loweredBuilder = irGen.builder
        
        for fn in functions {
            // create function proto
            let function = getOrAddFunction(named: fn.name, type: fn.type, irGen: irGen)
            fn.loweredFunction = function
            
            // name the params
            for (i, p) in (fn.params ?? []).enumerate() where p.irName != nil {
                LLVMSetValueName(LLVMGetParam(function, UInt32(i)), p.irName ?? "")
            }
        }
        
        // lower the function bodies
        for fn in functions {
            try fn.vhirLower(self, irGen: irGen)
        }
        
        try validate()
    }
    
    private func validate() throws {
        var err = UnsafeMutablePointer<Int8>.alloc(1)
        guard !LLVMVerifyModule(loweredModule, LLVMReturnStatusAction, &err) else {
            throw irGenError(.invalidModule(loweredModule, String.fromCString(err)), userVisible: true)
        }
    }
}




extension Function: VHIRLower {
    
    private func applyInline() {
        switch inline {
        case .`default`: break
        case .always: LLVMAddFunctionAttr(loweredFunction, LLVMAlwaysInlineAttribute)
        case .never: LLVMAddFunctionAttr(loweredFunction, LLVMNoInlineAttribute)
        }
    }
    private func applyVisibility() {
        switch visibility {
        case .`public`:
            LLVMSetVisibility(loweredFunction, LLVMDefaultVisibility)
            LLVMSetLinkage(loweredFunction, LLVMExternalLinkage)
        case .`internal`:
            LLVMSetVisibility(loweredFunction, LLVMDefaultVisibility)
            LLVMSetLinkage(loweredFunction, LLVMExternalLinkage)
        case .`private`:
            LLVMSetVisibility(loweredFunction, LLVMProtectedVisibility)
            LLVMSetLinkage(loweredFunction, LLVMPrivateLinkage)
        }
    }
    private func applyAttributes() {
        if attributes.contains(.noreturn) { LLVMAddFunctionAttr(loweredFunction, LLVMNoReturnAttribute) }
        if attributes.contains(.readnone) { LLVMAddFunctionAttr(loweredFunction, LLVMReadNoneAttribute) }
    }
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let b = LLVMGetInsertBlock(irGen.builder)
        let fn = LLVMGetNamedFunction(irGen.module, name)
        
        // apply function attributes, linkage, and visibility
        applyInline()
        applyVisibility()
        applyAttributes()
        
        // if no body, return
        guard let blocks = blocks else { return fn }
        
        // declare blocks, so break instructions have something to br to
        for bb in blocks {
            bb.loweredBlock = LLVMAppendBasicBlock(fn, bb.name)
            LLVMPositionBuilderAtEnd(irGen.builder, bb.loweredBlock)
            
            for param in bb.parameters ?? [] {
                let v = try param.vhirLower(module, irGen: irGen)
                param.updateUsesWithLoweredVal(v)
            }
        }
        
        for bb in blocks {
            LLVMPositionBuilderAtEnd(irGen.builder, bb.loweredBlock)
            
            for case let inst as protocol<VHIRLower, Inst> in bb.instructions {
                let v = try inst.vhirLower(module, irGen: irGen)
                inst.updateUsesWithLoweredVal(v)
            }
        }
        
        if b != nil { LLVMPositionBuilderAtEnd(irGen.builder, b) }
        
        try validate()
        
        return fn
    }
    
    private func validate() throws {
        guard !LLVMVerifyFunction(loweredFunction, LLVMReturnStatusAction) else {
            LLVMDumpModule(module.loweredModule)
            throw irGenError(.invalidFunction(name), userVisible: true)
        }
    }
}

extension BasicBlock {

    func loweredValForParamNamed(name: String, predBlock: BasicBlock) throws -> LLVMValueRef {
        guard let application = applications.find({$0.predecessor === predBlock}), case let blockOperand as BlockOperand = application.args?.find({$0.name == name}) else { throw VHIRError.noFunctionBody }
        return blockOperand.loweredValue
    }
    
}


extension Param: VHIRLower {
    
    private func buildPhi() -> LLVMValueRef {
        phi = LLVMBuildPhi(module.loweredBuilder, type!.lowerType(module), paramName)
        return phi
    }
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard let function = parentFunction, block = parentBlock else { throw VHIRError.noParentBlock }
        
        if let functionParamIndex = function.params?.indexOf({$0.name == name}) {
            return LLVMGetParam(function.loweredFunction, UInt32(functionParamIndex))
        }
        else if phi != nil {
            return phi
        }
        else {
            let phi = buildPhi()
            
            for operand in try block.appliedArgs(for: self) {
                operand.phi = phi
            }
            
            return phi
        }
    }
}


extension IntLiteralInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), UInt64(value.value), false)
    }
}
extension BoolLiteralInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), value.value ? 1 : 0, false)
    }
}

extension String {
    
    enum Encoding : Int { case utf8 = 1, utf16 = 2 }
    
    var encoding: Encoding {
        switch smallestEncoding {
        case NSUTF16StringEncoding: return .utf16
        default: return .utf8
        }
    }
    var numberOfCodeUnits: Int {
        switch encoding {
        case .utf8: return utf8.count
        case .utf16: return utf16.count
        }
    }
}
extension String.Encoding : CustomStringConvertible {
    var description: String {
        switch self {
        case .utf8: return "utf8"
        case .utf16: return "utf16"
        }
    }
}

extension StringLiteralInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let str = LLVMBuildGlobalString(irGen.builder, value.value, "")
        return LLVMBuildBitCast(irGen.builder, str, BuiltinType.opaquePointer.lowerType(module), irName ?? "")
    }
}


extension StructInitInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard case let t as TypeAlias = type else { throw irGenError(.notStructType) }
        var val = LLVMGetUndef(t.lowerType(module))
        
        for (i, el) in args.enumerate() {
            val = LLVMBuildInsertValue(irGen.builder, val, el.loweredValue, UInt32(i), irName ?? "")
        }
        
        return val
    }
}

extension ReturnInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        if case _ as VoidLiteralValue = value.value {
            return LLVMBuildRetVoid(irGen.builder)
        }
        else {
            let v = try value.vhirLower(module, irGen: irGen)
            return LLVMBuildRet(irGen.builder, v)
        }
    }
}
extension YieldInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        var args = [value.loweredValue]
        return LLVMBuildCall(irGen.builder, targetThunk!.loweredFunction, &args, 1, irName ?? "")
    }
}

extension VariableInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard let type = type else { throw irGenError(.notTyped) }
        
        let mem = LLVMBuildAlloca(irGen.builder, type.lowerType(module), irName ?? "")
        LLVMBuildStore(irGen.builder, value.loweredValue, mem)
        return value.loweredValue
    }
}


extension VHIRFunctionCall {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return try FunctionCallInst.callFunction(functionRef,
                                                 type: functionType,
                                                 args: args.map { $0.loweredValue },
                                                 irGen: irGen,
                                                 irName: irName)
    }
    
}

private extension FunctionCallInst {
    private static func callFunction(ref: LLVMValueRef, type: FunctionType? = nil, args: [LLVMValueRef], irGen: IRGen, irName: String?) throws -> LLVMValueRef {
        var a = args
        let call = LLVMBuildCall(irGen.builder, ref, &a, UInt32(args.count), irName ?? "")
        type?.addMetadataTo(call)
        
        return call
    }
}

extension TupleCreateInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard let t = type else { throw irGenError(.notStructType) }
        var val = LLVMGetUndef(t.lowerType(module))
        
        for (i, el) in args.enumerate() {
            val = LLVMBuildInsertValue(irGen.builder, val, el.loweredValue, UInt32(i), irName ?? "")
        }
        
        return val
    }
}

extension TupleExtractInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildExtractValue(irGen.builder, tuple.loweredValue, UInt32(elementIndex), irName ?? "")
    }
}

extension TupleElementPtrInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildStructGEP(irGen.builder, tuple.loweredValue, UInt32(elementIndex), irName ?? "")
    }
}

extension StructExtractInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let index = try structType.indexOfMemberNamed(propertyName)
        return LLVMBuildExtractValue(irGen.builder, object.loweredValue, UInt32(index), irName ?? "")
    }
}

extension StructElementPtrInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let index = try structType.indexOfMemberNamed(propertyName)
        return LLVMBuildStructGEP(irGen.builder, object.loweredValue, UInt32(index), irName ?? "")
    }
}

extension Function {
    
    /// Constructs a function's faluire landing pad, or returns the one defined
    func buildCondFailBlock(module: Module, irGen: IRGen) throws -> LLVMBasicBlockRef {
        // if its there already, we can use it
        guard _condFailBlock == nil else { return _condFailBlock }
        
        // make fail block & save current pos
        let ins = LLVMGetInsertBlock(irGen.builder)
        let block = LLVMAppendBasicBlock(loweredFunction, "\(name.demangleName()).trap")
        LLVMPositionBuilderAtEnd(irGen.builder, block)
        
        // Build trap and unreachable
        try BuiltinInstCall.trapInst().vhirLower(module, irGen: irGen)
        LLVMBuildUnreachable(irGen.builder)

        // move back; save and return the fail block
        LLVMPositionBuilderAtEnd(irGen.builder, ins)
        _condFailBlock = block
        return block
    }
    
}


extension BuiltinInstCall: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        var args = self.args.map { $0.loweredValue }
        let intrinsic: LLVMValueRef
        
        switch inst {
            // overflowing arithmetic
        case .iadd: intrinsic = getSinglyOverloadedIntrinsic("llvm.sadd.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue))
        case .imul: intrinsic = getSinglyOverloadedIntrinsic("llvm.smul.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue))
        case .isub: intrinsic = getSinglyOverloadedIntrinsic("llvm.ssub.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue))
            
            // other intrinsics
        case .expect: intrinsic = getSinglyOverloadedIntrinsic("llvm.expect", irGen.module, LLVMTypeOf(l.loweredValue))
        case .trap:   intrinsic = getRawIntrinsic("llvm.trap", irGen.module)
        case .memcpy:
            // overload types -- we want `@llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1)`
            var overloadTypes = [LLVMTypeOf(args[0]), LLVMTypeOf(args[1]), LLVMInt64Type()]
            // construct intrinsic
            intrinsic = getOverloadedIntrinsic("llvm.memcpy", irGen.module, &overloadTypes, 3)
            // add extra memcpy args
            args.append(LLVMConstInt(LLVMInt32Type(), 1, false)) // i32 align
            args.append(LLVMConstInt(LLVMInt1Type(), 0, false)) // i1 isVolatile
            
        case .allocstack: return LLVMBuildArrayAlloca(irGen.builder, LLVMInt8Type(), args[0], irName ?? "")
        case .allocheap:  return LLVMBuildArrayMalloc(irGen.builder, LLVMInt8Type(), args[0], irName ?? "")
        
        case .advancepointer:
            var index = [r.loweredValue]
            return LLVMBuildGEP(irGen.builder, l.loweredValue, &index, 1, irName ?? "")
        case .opaqueload:
            return LLVMBuildLoad(irGen.builder, l.loweredValue, irName ?? "")
            
        case .condfail:
            guard let fn = parentFunction, current = parentBlock else { fatalError() }
            let success = LLVMAppendBasicBlock(fn.loweredFunction, "\(current.name).cont"), fail = try fn.buildCondFailBlock(module, irGen: irGen)
            
            LLVMMoveBasicBlockAfter(success, current.loweredBlock)
            LLVMBuildCondBr(irGen.builder, l.loweredValue, fail, success)
            LLVMPositionBuilderAtEnd(irGen.builder, success)
            return nil
            
            // handle calls which arent intrinsics, but builtin
            // instructions. Return these directly
        case .iaddoverflow: return LLVMBuildAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ieq:  return LLVMBuildICmp(irGen.builder, LLVMIntEQ, l.loweredValue, r.loweredValue, irName ?? "")
        case .ineq: return LLVMBuildICmp(irGen.builder, LLVMIntNE, l.loweredValue, r.loweredValue, irName ?? "")
        case .idiv: return LLVMBuildSDiv(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .irem: return LLVMBuildSRem(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ilt:  return LLVMBuildICmp(irGen.builder, LLVMIntSLT, l.loweredValue, r.loweredValue, irName ?? "")
        case .ilte: return LLVMBuildICmp(irGen.builder, LLVMIntSLE, l.loweredValue, r.loweredValue, irName ?? "")
        case .igte: return LLVMBuildICmp(irGen.builder, LLVMIntSGE, l.loweredValue, r.loweredValue, irName ?? "")
        case .igt:  return LLVMBuildICmp(irGen.builder, LLVMIntSGT, l.loweredValue, r.loweredValue, irName ?? "")
        case .ishl: return LLVMBuildShl(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ishr: return LLVMBuildAShr(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .iand: return LLVMBuildAnd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ior:  return LLVMBuildOr(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ixor: return LLVMBuildXor(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        
        case .and:  return LLVMBuildAnd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .or:   return LLVMBuildAnd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
            
        case .fadd: return LLVMBuildFAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .fsub: return LLVMBuildFAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .fmul: return LLVMBuildFMul(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .feq:  return LLVMBuildFCmp(irGen.builder, LLVMRealOEQ, l.loweredValue, r.loweredValue, irName ?? "")
        case .fneq: return LLVMBuildFCmp(irGen.builder, LLVMRealONE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fdiv: return LLVMBuildFDiv(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .frem: return LLVMBuildFRem(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .flt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOLT, l.loweredValue, r.loweredValue, irName ?? "")
        case .flte: return LLVMBuildFCmp(irGen.builder, LLVMRealOLE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fgte: return LLVMBuildFCmp(irGen.builder, LLVMRealOGE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fgt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOGT, l.loweredValue, r.loweredValue, irName ?? "")
        }
        
        return LLVMBuildCall(irGen.builder, intrinsic, &args, UInt32(args.count), irName ?? "")
    }
}

extension BreakInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildBr(irGen.builder, call.block.loweredBlock)
    }
}

extension CondBreakInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildCondBr(irGen.builder, condition.loweredValue, thenCall.block.loweredBlock, elseCall.block.loweredBlock)
    }
}

extension AllocInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildAlloca(irGen.builder, storedType.lowerType(module), irName ?? "")
    }
}

extension StoreInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildStore(irGen.builder, value.loweredValue, address.loweredValue)
    }
}
extension LoadInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, address.loweredValue, irName ?? "")
    }
}
extension BitcastInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildBitCast(irGen.builder, address.loweredValue, pointerType.lowerType(module), irName ?? "")
    }
}



extension ExistentialConstructInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        guard case let aliasType as TypeAlias = value.memType, case let structType as StructType = aliasType.targetType else { fatalError() }
        
        let exType = existentialType.usingTypesIn(module).lowerType(module)
        let valueMem = LLVMBuildAlloca(irGen.builder, aliasType.lowerType(module), "") // allocate the struct
        let ptr = LLVMBuildAlloca(irGen.builder, exType, "")
        
        let llvmName = irName.map { "\($0)." }
        
        let propArrayPtr = LLVMBuildStructGEP(irGen.builder, ptr, 0, "\(llvmName)prop_metadata") // [n x i32]*
        let methodArrayPtr = LLVMBuildStructGEP(irGen.builder, ptr, 1, "\(llvmName)method_metadata") // [n x i8*]*
        let structPtr = LLVMBuildStructGEP(irGen.builder, ptr, 2, "\(llvmName)opaque") // i8**
        
        let propArr = try existentialType.existentialPropertyMetadataFor(structType, module: module, irGen: irGen)
        LLVMBuildStore(irGen.builder, propArr, propArrayPtr)
        
        let methodArr = try existentialType.existentialMethodMetadataFor(structType, module: module, irGen: irGen)
        LLVMBuildStore(irGen.builder, methodArr, methodArrayPtr)
        
        let v = LLVMBuildLoad(irGen.builder, value.loweredValue, "")
        LLVMBuildStore(irGen.builder, v, valueMem)
        let opaqueValueMem = LLVMBuildBitCast(irGen.builder, valueMem, BuiltinType.opaquePointer.lowerType(module), "")
        LLVMBuildStore(irGen.builder, opaqueValueMem, structPtr)
        
        return LLVMBuildLoad(irGen.builder, ptr, irName ?? "")
    }
}

private extension ConceptType {
    /// Returns the metadata array map, which transforms the protocol's properties
    /// to an element in the `type`. Type `[n * i32]`
    func existentialPropertyMetadataFor(structType: StructType, module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let dataLayout = LLVMCreateTargetData(LLVMGetDataLayout(irGen.module))
        let conformingType = structType.lowerType(module)
        
        // a table of offsets
        let offsets = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { index in LLVMOffsetOfElement(dataLayout, conformingType, UInt32(index)) }
            .map { LLVMConstInt(LLVMInt32Type(), UInt64($0), false) }
        
        return try ArrayInst.lowerBuffer(offsets,
                                         elType: BuiltinType.int(size: 32),
                                         irName: "metadata",
                                         module: module,
                                         irGen: irGen)
    }
    
    /// Returns the metadata array of function pointers. Type `[n * i8*]`
    func existentialMethodMetadataFor(structType: StructType, module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let opaquePtrType = BuiltinType.opaquePointer
        
        let ptrs = try requiredFunctions
            .map { methodName, type, mutating in
                try structType.ptrToMethodNamed(methodName, type: type.withParent(structType, mutating: mutating), module: module)
            }
            .map { ptr in
                LLVMBuildBitCast(irGen.builder, ptr, opaquePtrType.lowerType(module), LLVMGetValueName(ptr))
        }
        
        return try ArrayInst.lowerBuffer(ptrs,
                                         elType: opaquePtrType,
                                         irName: "witness_table",
                                         module: module,
                                         irGen: irGen)
    }
}


extension ArrayInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        return try ArrayInst.lowerBuffer(values.map { $0.loweredValue },
                                         elType: arrayType.mem,
                                         irName: irName,
                                         module: module,
                                         irGen: irGen)
    }
    
    private static func lowerBuffer(buffer: [LLVMValueRef], elType: Type, irName: String?, module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let elementType = elType.lowerType(module)
        let elPtrType = LLVMPointerType(elementType, 0)
        
        let arrType = LLVMArrayType(elementType, UInt32(buffer.count))
        let ptr = LLVMBuildAlloca(irGen.builder, arrType, irName ?? "") // [n x el]*
        let basePtr = LLVMBuildBitCast(irGen.builder, ptr, elPtrType, "") // el*
        
        for (index, val) in buffer.enumerate() {
            // Make the index to lookup
            var mem = [LLVMConstInt(LLVMInt32Type(), UInt64(index), false)]
            // get the element ptr
            let el = LLVMBuildGEP(irGen.builder, basePtr, &mem, 1, "el.\(index)")
            let bcElPtr = LLVMBuildBitCast(irGen.builder, el, elPtrType, "el.ptr.\(index)")
            // store val into memory
            LLVMBuildStore(irGen.builder, val, bcElPtr)
        }
        
        return LLVMBuildLoad(irGen.builder, ptr, "")
    }
}

extension ExistentialPropertyInst : VHIRLower {
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {

        guard case let aliasType as TypeAlias = existential.memType, case let conceptType as ConceptType = aliasType.targetType, let propertyType = type?.lowerType(module) else { fatalError() }

        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        let i = try conceptType.indexOfMemberNamed(propertyName)
        
        var index = [LLVMConstInt(LLVMInt32Type(), UInt64(i), false)] // i32
        
        let llvmName = irName.map { "\($0)." } ?? ""
        
        let i32PtrType = BuiltinType.pointer(to: BuiltinType.int(size: 32)).lowerType(module)
        let arr = LLVMBuildStructGEP(irGen.builder, existential.loweredValue, 0, "\(llvmName)metadata_ptr") // [n x i32]*
        let propertyMetadataBasePtr = LLVMBuildBitCast(irGen.builder, arr, i32PtrType, "\(llvmName)metadata_base_ptr") // i32*
        
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, propertyMetadataBasePtr, &index, 1, "") // i32*
        var offset = [LLVMBuildLoad(irGen.builder, pointerToArrayElement, "")] // i32
        
        let elementPtrType = LLVMPointerType(propertyType, 0) // ElTy.Type        
        let structElementPointer = LLVMBuildStructGEP(module.loweredBuilder, existential.loweredValue, 2, "\(llvmName)element_pointer") // i8**
        let opaqueInstancePointer = LLVMBuildLoad(module.loweredBuilder, structElementPointer, "\(llvmName)opaque_instance_pointer") // i8*
        let instanceMemberPtr = LLVMBuildGEP(irGen.builder, opaqueInstancePointer, &offset, 1, "") // i8*
        let elPtr = LLVMBuildBitCast(irGen.builder, instanceMemberPtr, elementPtrType, "\(llvmName)ptr") // ElTy*
        return LLVMBuildLoad(irGen.builder, elPtr, irName ?? "")
    }
}

extension ExistentialUnboxInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let p = LLVMBuildStructGEP(irGen.builder, existential.loweredValue, 2, "")
        return LLVMBuildLoad(irGen.builder, p, irName ?? "")
    }
}

extension ExistentialWitnessMethodInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let llvmName = irName.map { "\($0)." } ?? ""
        let i = try existentialType.indexOf(methodNamed: methodName, argTypes: argTypes)
        let fnType = try existentialType
            .methodType(methodNamed: methodName, argTypes: argTypes)
            .withOpaqueParent().cannonicalType(module)
            .usingTypesIn(module)
        
        var index = LLVMConstInt(LLVMInt32Type(), UInt64(i), false) // i32
        
        let opaquePtrType = BuiltinType.pointer(to: BuiltinType.opaquePointer).lowerType(module)
        let arr = LLVMBuildStructGEP(irGen.builder, existential.loweredValue, 1, "\(llvmName)witness_table_ptr") // [n x i8*]*
        let methodMetadataBasePtr = LLVMBuildBitCast(irGen.builder, arr, opaquePtrType, "\(llvmName)witness_table_base_ptr") // i8**
        
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, methodMetadataBasePtr, &index, 1, "") // i8**
        let functionPointer = LLVMBuildLoad(irGen.builder, pointerToArrayElement, "") // i8*
        
        let functionType = BuiltinType.pointer(to: fnType).lowerType(module)
        return LLVMBuildBitCast(irGen.builder, functionPointer, functionType, irName ?? "") // fntype*
    }
}


private extension PtrOperand {
    func bitcastToRefCountedType(irGen: IRGen) throws -> LLVMValueRef {
        let refcounted = Runtime.refcountedObjectPointerType.lowerType(module)
        return LLVMBuildBitCast(irGen.builder, loweredValue, refcounted, "")
    }
}

extension AllocObjectInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let size = LLVMConstInt(LLVMInt32Type(), UInt64(storedType.size(module)), false)
        
        let ref = module.getOrAddRuntimeFunction(named: "vist_allocObject", irGen: irGen)
        return try FunctionCallInst.callFunction(ref,
                                                 args: [size],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}

extension RetainInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let ref = module.getOrAddRuntimeFunction(named: "vist_retainObject", irGen: irGen)
        return try FunctionCallInst.callFunction(ref,
                                                 args: [try object.bitcastToRefCountedType(irGen)],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}

extension ReleaseInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let functionName = unowned ? "vist_releaseUnownedObject" : "vist_releaseObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, irGen: irGen)
        
        return try FunctionCallInst.callFunction(ref,
                                                 args: [try object.bitcastToRefCountedType(irGen)],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}


extension DeallocObjectInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let functionName = unowned ? "vist_deallocUnownedObject" : "vist_deallocObject"
        let ref = module.getOrAddRuntimeFunction(named: functionName, irGen: irGen)
        
        return try FunctionCallInst.callFunction(ref,
                                                 args: [try object.bitcastToRefCountedType(irGen)],
                                                 irGen: irGen,
                                                 irName: irName)
    }
}





