//
//  Builder.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Handles adding instructions to the module
final class Builder {
    weak var module: Module!
    var insertPoint = InsertPoint()
    
    init(module: Module) { self.module = module }
    
    /// The builder's insert point
    struct InsertPoint {
        private var i: Inst?, b: BasicBlock?, f: Function?
        
        var inst: Inst? {
            get {
                return i
            }
            set(inst) {
                i = inst
                b = inst?.parentBlock
                f = inst?.parentBlock?.parentFunction
            }
        }
        var block: BasicBlock? {
            get {
                return b
            }
            set(block) {
                i = block?.instructions.last
                b = block
                f = block?.parentFunction
            }
        }
        var function: Function? {
            get {
                return f
            }
            set(function) {
                i = function?.lastBlock?.instructions.last
                b = function?.lastBlock
                f = function
            }
        }
    }
}

extension Builder {
    
    /// Inserts the instruction to the end of the block, and updates its
    /// parent and the builder's insert point
    func addToCurrentBlock(inst: Inst) throws {
        guard let block = insertPoint.block else { throw VIRError.noParentBlock }
        inst.parentBlock = block
        block.append(inst)
        insertPoint.inst = inst
    }
    
    /// Handles adding the instruction to the block -- then returns it
    func _add<I: Inst>(instruction: I) throws -> I {
        try addToCurrentBlock(inst: instruction)
        return instruction
    }
    
    /// Build an instruction and add to the current block
    @discardableResult
    func build<I : Inst>(_ inst: I) throws -> I {
        try addToCurrentBlock(inst: inst)
        return inst
    }
    func buildManaged<I : Inst>(_ inst: I, gen: VIRGenFunction) throws -> Managed<I> {
        try addToCurrentBlock(inst: inst)
        return Managed<I>.forUnmanaged(inst, gen: gen)
    }
    
}
