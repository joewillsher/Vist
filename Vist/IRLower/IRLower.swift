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
            try fn.irLower(self, irGen: irGen)
        }
        
    }
}

extension Function: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        
        let fn = LLVMAddFunction(irGen.module, name, type.lowerType(module))
        
        guard let blocks = blocks else { return fn }
        
        
        
        for bb in blocks {
            
            LLVMAppendBasicBlock(fn, bb.name)
            
            for case let inst as protocol<IRLower, Inst> in bb.instructions {
                
                let v = try inst.irLower(module, irGen: irGen)
                inst.updateUsesWithLoweredVal(v)
            }
            
        }
        
        return fn
    }
}


extension IntLiteralInst: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), UInt64(value.value), false)
    }
}

extension StructInitInst: IRLower {
    func irLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard case let t as StructType = type else { throw irGenError(.notStructType) }
        let mem = LLVMBuildAlloca(irGen.builder, t.lowerType(module), "")
        
        for (i, el) in args.enumerate() {
            LLVMBuildInsertValue(irGen.builder, mem, el.loweredValue, UInt32(i), "")
        }
        
        return LLVMBuildLoad(irGen.builder, mem, irName ?? "")
    }
}

