//
//  BuiltinLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension BuiltinInstCall: VIRLower {
    
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        // applied args
        // self provides `lhs` and `rhs` which are lazily computed args[0] and args[1]
        var args = self.args.map { $0.loweredValue! as LLVMValue }
        // An intrinsic to call with args
        let intrinsic: LLVMFunction
        
        switch inst {
        // overflowing arithmetic
        case .iadd: intrinsic = try IGF.module.getIntrinsic(named: "llvm.sadd.with.overflow", overload: lhs.type)
        case .imul: intrinsic = try IGF.module.getIntrinsic(named: "llvm.smul.with.overflow", overload: lhs.type)
        case .isub: intrinsic = try IGF.module.getIntrinsic(named: "llvm.ssub.with.overflow", overload: lhs.type)
            
        // other intrinsics
        case .expect: intrinsic = try IGF.module.getIntrinsic(named: "llvm.expect", overload: lhs.type)
        case .trap:   intrinsic = try IGF.module.getIntrinsic(named: "llvm.trap")
        case .memcpy:
            // overload types -- we want `@llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1)`
            // construct intrinsic
            intrinsic = try IGF.module.getIntrinsic(named: "llvm.memcpy",
                                                    overload: lhs.type, rhs.type, .intType(size: 64))
            // add extra memcpy args
            args.append(LLVMValue.constInt(value: 1, size: 32)) // i32 align -- align 1
            args.append(LLVMValue.constBool(value: false)) // i1 isVolatile -- false
                
        case .allocstack: return try IGF.builder.buildArrayAlloca(size: lhs, elementType: .intType(size: 8), name: irName)
        case .allocheap:  return try IGF.builder.buildArrayMalloc(size: lhs, elementType: .intType(size: 8), name: irName)
        case .heapfree: return try IGF.builder.buildFree(ptr: lhs, name: irName)
            
        case .advancepointer: return try IGF.builder.buildGEP(ofAggregate: lhs, index: rhs, name: irName)
        case .opaqueload:     return try IGF.builder.buildLoad(from: lhs, name: irName)
        case .opaquestore:    return try IGF.builder.buildStore(value: rhs, in: lhs)
            
        case .condfail:
            guard let fn = parentFunction, let current = parentBlock else { fatalError() }
            let success = try fn.loweredFunction!.appendBasicBlock(named: "\(current.name).cont"), fail = try fn.buildCondFailBlock(IGF: &IGF)
            
            success.move(after: current.loweredBlock!)
            try module.loweredBuilder.buildCondBr(if: lhs, to: fail, elseTo: success)
            module.loweredBuilder.position(atEndOfBlock: success)
            return .nullptr
            
        // handle calls which arent intrinsics, but builtin
        // instructions. We can just call them directly, and return
        case .iaddoverflow: return try IGF.builder.buildIAdd(lhs: lhs, rhs: rhs, name: irName)
        case .idiv: return try IGF.builder.buildIDiv(lhs: lhs, rhs: rhs, name: irName)
        case .irem: return try IGF.builder.buildIRem(lhs: lhs, rhs: rhs, name: irName)
        case .ieq, .beq:  return try IGF.builder.buildIntCompare(.equal, lhs: lhs, rhs: rhs, name: irName)
        case .ineq: return try IGF.builder.buildIntCompare(.notEqual, lhs: lhs, rhs: rhs)
        case .ilt:  return try IGF.builder.buildIntCompare(.lessThan, lhs: lhs, rhs: rhs, name: irName)
        case .igt:  return try IGF.builder.buildIntCompare(.greaterThan, lhs: lhs, rhs: rhs, name: irName)
        case .ilte: return try IGF.builder.buildIntCompare(.lessThanEqual, lhs: lhs, rhs: rhs, name: irName)
        case .igte: return try IGF.builder.buildIntCompare(.greaterThanEqual, lhs: lhs, rhs: rhs, name: irName)
        case .ishl: return try IGF.builder.buildIShiftL(lhs: lhs, rhs: rhs, name: irName)
        case .ishr: return try IGF.builder.buildIShiftR(lhs: lhs, rhs: rhs, name: irName)
        case .iand, .and: return try IGF.builder.buildAnd(lhs: lhs, rhs: rhs, name: irName)
        case .ior, .or:  return try IGF.builder.buildOr(lhs: lhs, rhs: rhs, name: irName)
        case .ixor: return try IGF.builder.buildXor(lhs: lhs, rhs: rhs, name: irName)
        
        case .fadd: return try IGF.builder.buildFAdd(lhs: lhs, rhs: rhs, name: irName)
        case .fsub: return try IGF.builder.buildFSub(lhs: lhs, rhs: rhs, name: irName)
        case .fmul: return try IGF.builder.buildFMul(lhs: lhs, rhs: rhs, name: irName)
        case .fdiv: return try IGF.builder.buildFDiv(lhs: lhs, rhs: rhs, name: irName)
        case .frem: return try IGF.builder.buildFRem(lhs: lhs, rhs: rhs, name: irName)
        case .feq:  return try IGF.builder.buildFloatCompare(.equal, lhs: lhs, rhs: rhs, name: irName)
        case .fneq: return try IGF.builder.buildFloatCompare(.notEqual, lhs: lhs, rhs: rhs, name: irName)
        case .flt:  return try IGF.builder.buildFloatCompare(.lessThan, lhs: lhs, rhs: rhs, name: irName)
        case .fgt:  return try IGF.builder.buildFloatCompare(.greaterThan, lhs: lhs, rhs: rhs, name: irName)
        case .flte: return try IGF.builder.buildFloatCompare(.lessThanEqual, lhs: lhs, rhs: rhs, name: irName)
        case .fgte: return try IGF.builder.buildFloatCompare(.lessThanEqual, lhs: lhs, rhs: rhs, name: irName)
            
        case .trunc8: return try IGF.builder.buildTrunc(val: lhs, size: 8, name: irName)
        case .trunc16: return try IGF.builder.buildTrunc(val: lhs, size: 16, name: irName)
        case .trunc32: return try IGF.builder.buildTrunc(val: lhs, size: 32, name: irName)
        }
        
        // call the intrinsic
        let call = try IGF.builder.buildCall(function: intrinsic, args: args, name: irName)
        if case .trap = inst { try IGF.builder.buildUnreachable() }        
        return call
    }
}


extension Function {
    
    /// Constructs a function's faluire landing pad, or returns the one defined
    func buildCondFailBlock(IGF: inout IRGenFunction) throws -> LLVMBasicBlock {
        // if its there already, we can use it
        if let condFailBlock = _condFailBlock { return condFailBlock }
        
        // make fail block & save current pos
        let ins = IGF.builder.getInsertBlock()
        let block = try loweredFunction!.appendBasicBlock(named: "\(name.demangleName()).trap")
        IGF.builder.position(atEndOfBlock: block)
        
        // Build trap and unreachable
        _ = try BuiltinInstCall.trapInst().virLower(IGF: &IGF)
        
        // move back; save and return the fail block
        IGF.builder.position(atEndOfBlock: ins!)
        _condFailBlock = block
        return block
    }
    
}


