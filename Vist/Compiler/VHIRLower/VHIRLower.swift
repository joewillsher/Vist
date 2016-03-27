//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRLowerError: VistError {
    case notLowerable(RValue)
    
    var description: String {
        switch self {
        case .notLowerable(let v): return "value '\(v.vhir)' is not Lowerable"
        }
    }
}

protocol VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef
}

extension Operand: VHIRLower {
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        if loweredValue != nil {
            return loweredValue
        }
        else if case let lowerable as VHIRLower = value {
            return try lowerable.vhirLower(module, irGen: irGen)
        }
        else {
            throw error(IRLowerError.notLowerable(self))
        }
    }
}

extension Module {
    func vhirLower(module: LLVMModuleRef, isStdLib: Bool) throws {
        
        let irGen = (LLVMCreateBuilder(), module, isStdLib) as IRGen
        loweredModule = module
        loweredBuilder = irGen.builder
        
        for fn in functions {
            let function = LLVMAddFunction(irGen.module, fn.name, fn.type.lowerType(self))
            fn.loweredFunction = function
            for (i, p) in (fn.params ?? []).enumerate() where p.irName != nil {
                LLVMSetValueName(LLVMGetParam(function, UInt32(i)), p.irName ?? "")
            }
        }
        
        for fn in functions {
            try fn.vhirLower(self, irGen: irGen)
        }
        
    }
}

extension Function: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let b = LLVMGetInsertBlock(irGen.builder)
        let fn = functionPointerInModule(irGen.module)
        
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
        return fn
    }
    
    private func functionPointerInModule(module: LLVMModuleRef) -> LLVMValueRef {
        return LLVMGetNamedFunction(module, name)
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
            
            for operand in try block.appliedArgsForParam(self) {
                operand.phi = phi
            }
            
            return phi
        }
    }
}


extension IntLiteralInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), UInt64(value.value), false)
    }
}
extension BoolLiteralInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), value.value ? 1 : 0, false)
    }
}

extension StructInitInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard case let t as TypeAlias = type else { throw irGenError(.notStructType) }
        var val = LLVMGetUndef(t.lowerType(module))
        
        for (i, el) in args.enumerate() {
            val = LLVMBuildInsertValue(irGen.builder, val, el.loweredValue, UInt32(i), irName ?? "")
        }
        
        return val
    }
}

extension ReturnInst: VHIRLower {
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

extension VariableInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard let type = type else { throw irGenError(.notTyped) }
        
        let mem = LLVMBuildAlloca(irGen.builder, type.lowerType(module), irName ?? "")
        LLVMBuildStore(irGen.builder, value.loweredValue, mem)
        return value.loweredValue
    }
}

extension FunctionCallInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let args = self.args.map { $0.loweredValue }.ptr()
        let argCount = self.args.count
        defer { args.dealloc(argCount) }
        
        let fn = function.functionPointerInModule(irGen.module)
        let call = LLVMBuildCall(irGen.builder, fn, args, UInt32(argCount), irName ?? "")
        function.type.addMetadataTo(call)
        
        return call
    }
}

extension TupleCreateInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard let t = type else { throw irGenError(.notStructType) }
        var val = LLVMGetUndef(t.lowerType(module))
        
        for (i, el) in args.enumerate() {
            val = LLVMBuildInsertValue(irGen.builder, val, el.loweredValue, UInt32(i), irName ?? "")
        }
        
        return val
    }
}

extension TupleExtractInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildExtractValue(irGen.builder, tuple.loweredValue, UInt32(elementIndex), irName ?? "")
    }
}

extension TupleElementPtrInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildStructGEP(irGen.builder, tuple.loweredValue, UInt32(elementIndex), irName ?? "")
    }
}

extension StructExtractInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let index = try structType.indexOfMemberNamed(propertyName)
        return LLVMBuildExtractValue(irGen.builder, object.loweredValue, UInt32(index), irName ?? "")
    }
}

extension StructElementPtrInst: VHIRLower {
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
        
        let args = self.args.map { $0.loweredValue }
        let intrinsic: LLVMValueRef
        
        switch inst {
            // overflowing arithmetic
        case .iadd: intrinsic = getIntrinsic("llvm.sadd.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue), false)
        case .imul: intrinsic = getIntrinsic("llvm.smul.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue), false)
        case .isub: intrinsic = getIntrinsic("llvm.ssub.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue), false)
            
            // other intrinsics
        case .expect: intrinsic = getIntrinsic("llvm.expect", irGen.module, LLVMTypeOf(l.loweredValue), false)
        case .trap: intrinsic = getIntrinsic("llvm.trap", irGen.module, nil, false)
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
        case .ilt:   return LLVMBuildICmp(irGen.builder, LLVMIntSLT, l.loweredValue, r.loweredValue, irName ?? "")
        case .ilte:  return LLVMBuildICmp(irGen.builder, LLVMIntSLE, l.loweredValue, r.loweredValue, irName ?? "")
        case .igte:  return LLVMBuildICmp(irGen.builder, LLVMIntSGE, l.loweredValue, r.loweredValue, irName ?? "")
        case .igt:   return LLVMBuildICmp(irGen.builder, LLVMIntSGT, l.loweredValue, r.loweredValue, irName ?? "")
        case .ishl: return LLVMBuildShl(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ishr: return LLVMBuildAShr(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .iand: return LLVMBuildAnd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ior:  return LLVMBuildOr(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .ixor: return LLVMBuildXor(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
            
        case .fadd: return LLVMBuildAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .fsub: return LLVMBuildAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .fmul: return LLVMBuildMul(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .feq:  return LLVMBuildFCmp(irGen.builder, LLVMRealOEQ, l.loweredValue, r.loweredValue, irName ?? "")
        case .fneq: return LLVMBuildFCmp(irGen.builder, LLVMRealONE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fdiv: return LLVMBuildFDiv(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .frem: return LLVMBuildFRem(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .flt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOLT, l.loweredValue, r.loweredValue, irName ?? "")
        case .flte: return LLVMBuildFCmp(irGen.builder, LLVMRealOLE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fgte: return LLVMBuildFCmp(irGen.builder, LLVMRealOGE, l.loweredValue, r.loweredValue, irName ?? "")
        case .fgt:  return LLVMBuildFCmp(irGen.builder, LLVMRealOGT, l.loweredValue, r.loweredValue, irName ?? "")
        }
        
        let argBuffer = args.ptr()
        defer { argBuffer.destroy(args.count) }
        
        return LLVMBuildCall(irGen.builder, intrinsic, argBuffer, UInt32(args.count), irName ?? "")
    }
}

extension BreakInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildBr(irGen.builder, call.block.loweredBlock)
    }
}

extension CondBreakInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildCondBr(irGen.builder, condition.loweredValue, thenCall.block.loweredBlock, elseCall.block.loweredBlock)
    }
}

extension AllocInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildAlloca(irGen.builder, storedType.lowerType(module), irName ?? "")
    }
}

extension StoreInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildStore(irGen.builder, value.loweredValue, address.loweredValue)
    }
}
extension LoadInst: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, address.loweredValue, irName ?? "")
    }
}


