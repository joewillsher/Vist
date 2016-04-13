//
//  GeneratorInst.swift
//  Vist
//
//  Created by Josef Willsher on 07/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class YieldInst : InstBase {
    var value: Operand, targetThunk: Function?
    
    private init(value: Operand, targetThunk: Function?, parentBlock: BasicBlock?) {
        self.value = value
        self.targetThunk = targetThunk
        super.init(args: [value], irName: nil)
        self.parentBlock = parentBlock
    }
    
    override var instVHIR: String {
        return "yield \(targetThunk.map { "@\($0.name) " } ?? "<null>") (\(value)) \(useComment)"
    }
    
    override var type: Type? { return nil }
    
    override var hasSideEffects: Bool { return true }
}

final class YieldUnwindInst : InstBase {
    
    private init(parentBlock: BasicBlock?) {
        super.init(args: [], irName: nil)
        self.parentBlock = parentBlock
    }
    
    override var instVHIR: String {
        return "yield_unwind"
    }
    
    override var type: Type? { return nil }

    override var hasSideEffects: Bool { return true }
}

extension Builder {
    
    func buildYield(value: Operand, to targetThunk: Function?) throws -> YieldInst {
        return try _add(YieldInst(value: value, targetThunk: targetThunk, parentBlock: insertPoint.block))
    }
    func buildYieldUnwind() throws -> YieldUnwindInst {
        return try _add(YieldUnwindInst(parentBlock: insertPoint.block))
    }
}

