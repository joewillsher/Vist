//
//  Builder.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// The builder's insert point
struct InsertPoint {
    private(set) var inst: Inst?
    private(set) var block: BasicBlock?
    private(set) var function: Function?
}

/// Handles adding instructions to the module
final class Builder {
    weak var module: Module!
    var insertPoint = InsertPoint()
    
    init(module: Module) { self.module = module }
}

extension Builder {
    
    // 😣😣 this is 😷, sort out an InsertPoint interface which is stable over changes of IR
    
    /// Sets the builder's insert point to `function`
    func setInsertPoint(function: Function) throws {
        if insertPoint.function === function { return }
        guard let b = function.lastBlock else {
            insertPoint.function = function
            try buildFunctionEntryBlock(function)
            insertPoint.block = function.entryBlock
            return
        }
        insertPoint.inst = b.instructions.last
        insertPoint.block = b
        insertPoint.function = function
    }
    /// Sets the builder's insert point to `block`
    func setInsertPoint(block: BasicBlock) throws {
        insertPoint.inst = block.instructions.last
        insertPoint.block = block
        insertPoint.function = block.parentFunction
    }
    /// Sets the builder's insert point to `inst`
    func setInsertPoint(inst: Inst) throws {
        insertPoint.inst = inst
        insertPoint.block = inst.parentBlock
        insertPoint.function = inst.parentBlock?.parentFunction
    }
    
    /// Inserts the instruction to the end of the block, and updates its
    /// parent and the builder's insert point
    func addToCurrentBlock(inst: Inst) throws {
        guard let block = insertPoint.block else { throw VHIRError.noParentBlock }
        inst.parentBlock = block
        block.append(inst)
        try setInsertPoint(inst)
    }
}
