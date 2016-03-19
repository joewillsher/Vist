//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRLowerError: VistError {
    case notLowerable(Value)
    
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
            let f = LLVMAddFunction(irGen.module, fn.name, fn.type.lowerType(self))
            fn.loweredFunction = f
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


extension BBParam: VHIRLower {
    
    private func buildPhi() -> LLVMValueRef {
        phi = LLVMBuildPhi(module.loweredBuilder, type!.lowerType(module), paramName)
        return phi
    }
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        if let functionParamIndex = parentFunction.params?.indexOf({$0.name == name}) {
            return LLVMGetParam(parentFunction.loweredFunction, UInt32(functionParamIndex))
        }
        else if phi != nil {
            return phi
        }
        else {
            let phi = buildPhi()

            for operand in try parentBlock.appliedArgsForParam(self) {
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

extension BuiltinInstCall: VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let args = self.args.map { $0.loweredValue }
        
        let intrinsic: LLVMValueRef
        
        switch inst {
        case .iadd: intrinsic = getIntrinsic("llvm.sadd.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue), false)
        case .imul: intrinsic = getIntrinsic("llvm.smul.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue), false)
        case .isub: intrinsic = getIntrinsic("llvm.ssub.with.overflow", irGen.module, LLVMTypeOf(l.loweredValue), false)
            
        case .condfail: return nil // logic to fail on false, make an if branch
            
            // handle calls which arent intrinsics, but builtin
            // instructions. Return these directly
        case .lte: return LLVMBuildICmp(irGen.builder, LLVMIntSLE, l.loweredValue, r.loweredValue, irName ?? "")
        case .lt: return LLVMBuildICmp(irGen.builder, LLVMIntSLT, l.loweredValue, r.loweredValue, irName ?? "")
        case .gte: return LLVMBuildICmp(irGen.builder, LLVMIntSGE, l.loweredValue, r.loweredValue, irName ?? "")
        case .gt: return LLVMBuildICmp(irGen.builder, LLVMIntSGT, l.loweredValue, r.loweredValue, irName ?? "")
        case .iaddoverflow: return LLVMBuildAdd(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .idiv: return LLVMBuildSDiv(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        case .irem: return LLVMBuildSRem(irGen.builder, l.loweredValue, r.loweredValue, irName ?? "")
        }
        
        let argsIR = args.ptr()
        defer { argsIR.destroy(args.count) }
        
        return LLVMBuildCall(irGen.builder, intrinsic, argsIR, UInt32(args.count), irName ?? "")
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


