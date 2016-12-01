//
//  Builder.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol Builder : class {
    weak var module: Module! { get set }
    init(module: Module)
}

/// Handles adding instructions to the module
final class VIRBuilder : Builder {
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

final class AIRBuilder : Builder {
    weak var module: Module!
    var insertPoint = InsertPoint(block: nil)
    
    /// AIR builder just needs a block; it inserts at the beginning
    struct InsertPoint {
        var block: AIRBlock?
    }
    var registerIndex: Int = 0
    
    init(module: Module) { self.module = module }
}

extension VIRBuilder {
    
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

}
extension AIRBuilder {
    
    /// Inserts the instruction to the end of the block, and updates its
    /// parent and the builder's insert point
    func addToCurrentBlock<Op: AIROp>(op: Op) throws {
        guard let block = insertPoint.block else { throw VIRError.noParentBlock }
        block.insts.append(op)
    }
    
    /// Handles adding the instruction to the block -- then returns it
    func _add<Op: AIROp>(_ op: Op) throws -> Op {
        try addToCurrentBlock(op: op)
        return op
    }
    
    /// Build an instruction and add to the current block
    @discardableResult
    func build<Op : AIROp>(_ op: Op) throws -> Op {
        try addToCurrentBlock(op: op)
        return op
    }
    
}
