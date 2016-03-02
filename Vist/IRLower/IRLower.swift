//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef
}

extension Module {
    func irLower(module: LLVMModuleRef, isStdLib: Bool) throws {
        
        let irGen = (LLVMCreateBuilder(), module, isStdLib) as IRGen
        
        for fn in functions {
            LLVMAddFunction(irGen.module, fn.name, fn.type.lowerType(self))
        }
        
        for fn in functions {
            try fn.irLower(self, irGen: irGen)
        }
        
    }
}

extension Function: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let fn = functionPointer(irGen)
        
        guard let blocks = blocks else { return fn }
        
        for bb in blocks {
            
            let block = LLVMAppendBasicBlock(fn, bb.name)
            LLVMPositionBuilderAtEnd(irGen.builder, block)
            
            for case let inst as protocol<IRLower, Inst> in bb.instructions {
                let v = try inst.irLower(module, irGen: irGen)
                inst.updateUsesWithLoweredVal(v)
            }
            
        }
        
        return fn
    }
    
    func functionPointer(irGen: IRGen) -> LLVMValueRef {
        return LLVMGetNamedFunction(irGen.module, name)
    }
}


extension IntLiteralInst: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), UInt64(value.value), false)
    }
}

extension StructInitInst: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard case let t as TypeAlias = type, case let ty as StructType = t.targetType else { throw irGenError(.notStructType) }
        var val = LLVMGetUndef(ty.lowerType(module))
                
        for (i, el) in args.enumerate() {
            val = LLVMBuildInsertValue(irGen.builder, val, el.loweredValue, UInt32(i), "")
        }
        
        return val
    }
}

extension ReturnInst: IRLower {
    
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        if case _ as VoidLiteralValue = value.value {
            return LLVMBuildRetVoid(irGen.builder)
        }
        else {
            return LLVMBuildRet(irGen.builder, value.loweredValue)
        }
    }
}
extension VariableInst: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard let type = type else { throw irGenError(.notTyped) }
        let mem = LLVMBuildAlloca(irGen.builder, type.lowerType(module), irName ?? "")
        LLVMBuildStore(irGen.builder, value.loweredValue, mem)
        return mem
    }
}

extension FunctionCallInst: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let args = self.args.map { $0.loweredValue }.ptr()
        let argCount = self.args.count
        defer { args.dealloc(argCount) }
        
        let fn = function.functionPointer(irGen)
        
        let call = LLVMBuildCall(irGen.builder, fn, args, UInt32(argCount), irName ?? "")
        
        return call
    }
}

