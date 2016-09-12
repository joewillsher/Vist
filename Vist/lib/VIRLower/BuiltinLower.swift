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
        case .iadd: intrinsic = try IGF.module.getIntrinsic(.i_add_overflow, overload: lhs.type)
        case .imul: intrinsic = try IGF.module.getIntrinsic(.i_mul_overflow, overload: lhs.type)
        case .isub: intrinsic = try IGF.module.getIntrinsic(.i_sub_overflow, overload: lhs.type)
        case .ipow: intrinsic = try IGF.module.getIntrinsic(.i_pow, overload: lhs.type)
            
        // other intrinsics
        case .expect: intrinsic = try IGF.module.getIntrinsic(.expect, overload: lhs.type)
        case .trap:   intrinsic = try IGF.module.getIntrinsic(.trap)
        case .memcpy:
            // overload types -- we want `@llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1)`
            // construct intrinsic
            intrinsic = try IGF.module.getIntrinsic(.memcopy,
                                                    overload: lhs.type, rhs.type, .intType(size: 64))
            // add extra memcpy args
            args.append(LLVMValue.constInt(value: 1, size: 32)) // i32 align -- align 1
            args.append(LLVMValue.constBool(value: false)) // i1 isVolatile -- false
            
        case .withptr:
            let alloc = try IGF.builder.buildAlloca(type: lhs.type)
            try IGF.builder.buildStore(value: lhs, in: alloc)
            return try IGF.builder.buildBitcast(value: alloc, to: LLVMType.opaquePointer)
            
        case .allocstack: return try IGF.builder.buildArrayAlloca(size: lhs, elementType: .intType(size: 8), name: irName)
        case .allocheap:  return try IGF.builder.buildArrayMalloc(size: lhs, elementType: .intType(size: 8), name: irName)
        case .heapfree: return try IGF.builder.buildFree(ptr: lhs, name: irName)
            
        case .advancepointer: return try IGF.builder.buildGEP(ofAggregate: lhs, index: rhs, name: irName)
        case .opaqueload:     return try IGF.builder.buildLoad(from: lhs, name: irName)
        case .opaquestore:    return try IGF.builder.buildStore(value: rhs, in: lhs)
            
        case .condfail:
            guard let fn = parentFunction, let current = parentBlock else { fatalError() }
            var success = try fn.loweredFunction!.appendBasicBlock(named: "\(current.name).cont"), fail = try fn.buildCondFailBlock(IGF: &IGF)
            
            success.move(after: current.loweredBlock!)
            try module.loweredBuilder.buildCondBr(if: lhs, to: fail, elseTo: success)
            try parentBlock!.splitBlock(backEdge: &success, IGF: &IGF)
            module.loweredBuilder.position(atEndOf: success)
            return .nullptr
            
        // handle calls which arent intrinsics, but builtin
        // instructions. We can just call them directly, and return
        case .iaddunchecked: return try IGF.builder.buildIAdd(lhs: lhs, rhs: rhs, name: irName)
        case .imulunchecked: return try IGF.builder.buildIMul(lhs: lhs, rhs: rhs, name: irName)
        case .idiv: return try IGF.builder.buildIDiv(lhs: lhs, rhs: rhs, name: irName)
        case .irem: return try IGF.builder.buildIRem(lhs: lhs, rhs: rhs, name: irName)
        case .ieq, .beq:   return try IGF.builder.buildIntCompare(.equal, lhs: lhs, rhs: rhs, name: irName)
        case .ineq, .bneq: return try IGF.builder.buildIntCompare(.notEqual, lhs: lhs, rhs: rhs)
        case .ilt:  return try IGF.builder.buildIntCompare(.lessThan, lhs: lhs, rhs: rhs, name: irName)
        case .igt:  return try IGF.builder.buildIntCompare(.greaterThan, lhs: lhs, rhs: rhs, name: irName)
        case .ilte: return try IGF.builder.buildIntCompare(.lessThanEqual, lhs: lhs, rhs: rhs, name: irName)
        case .igte: return try IGF.builder.buildIntCompare(.greaterThanEqual, lhs: lhs, rhs: rhs, name: irName)
        case .ishl: return try IGF.builder.buildIShiftL(lhs: lhs, rhs: rhs, name: irName)
        case .ishr: return try IGF.builder.buildIShiftR(lhs: lhs, rhs: rhs, name: irName)
        case .iand, .and: return try IGF.builder.buildAnd(lhs: lhs, rhs: rhs, name: irName)
        case .not:        return try IGF.builder.buildNot(val: lhs, name: irName)
        case .ior, .or:   return try IGF.builder.buildOr(lhs: lhs, rhs: rhs, name: irName)
        case .ixor:       return try IGF.builder.buildXor(lhs: lhs, rhs: rhs, name: irName)
        
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
            
        case .trunc8:  return try IGF.builder.buildTrunc(val: lhs, size: 8, name: irName)
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
        IGF.builder.position(atEndOf: block)
        
        // Build trap and unreachable
        _ = try BuiltinInstCall.trapInst().virLower(IGF: &IGF)
        
        // move back; save and return the fail block
        IGF.builder.position(atEndOf: ins!)
        _condFailBlock = block
        return block
    }
    
}

private extension BasicBlock {
    
    /// Corrects any phi nodes which were changed by splitting the block
    /// - note moves the insert point away from the current position
    func splitBlock(backEdge new: inout LLVMBasicBlock, IGF: inout IRGenFunction) throws {
        // for each phi which references this block
        for phiOperand in loweredBlock!.phiUses {
            let phi = loweredBlock!.phiUses.remove(phiOperand)!.loweredValue!
            
            // move after it, and build a replacement
            try IGF.builder.position(after: phi)
            let newPhi = try IGF.builder.buildPhi(type: phi.type)
            
            // add the incoming vals
            let range = 0 ..< Int(LLVMCountIncoming(phi._value!))
            let incoming = range.map { incomingIndex -> (value: LLVMValue, from: LLVMBasicBlock) in
                switch (phi.incomingBlock(at: incomingIndex), phi.incomingValue(at: incomingIndex)) {
                case (loweredBlock!, let val):
                    // repalce incoming from the old block with the new
                    return (value: val, from: new)
                case (let block, let val):
                    return (value: val, from: block)
                }
            }
            // add thses incoming to the phi
            newPhi.addPhiIncoming(incoming)
            phiOperand.setLoweredValue(newPhi)
            
            phi.eraseFromParent(replacingAllUsesWith: newPhi)
            newPhi.name = phi.name
            // move the phi uses from the old block to the new
            new.addPhiUse(phiOperand)
        }
        
        // set the current lowered block to be the continuation block
        loweredBlock = new
    }
}

