//
//  Builder.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class InsertPoint {
    var inst: Inst?
    var block: BasicBlock?
    var function: Function?
}


final class Builder {
    weak var module: Module!
    var insertPoint = InsertPoint()
    
    init(module: Module) {
        self.module = module
    }
}

extension Builder {
    
    /// Sets the builder's insert point to this function
    func setInsertPoint(f: Function) throws {
        if insertPoint.function === f { return }
        guard let b = try? f.getLastBlock() else {
            insertPoint.function = f
            try addBasicBlock("entry")
            return
        }
        insertPoint.inst = b.instructions.last
        insertPoint.block = b
        insertPoint.function = f
    }
    /// Sets the builder's insert point to this block
    func setInsertPoint(b: BasicBlock) throws {
        insertPoint.inst = b.instructions.last
        insertPoint.block = b
        insertPoint.function = b.parentFunction
    }
    /// Sets the builder's insert point to this instruction
    func setInsertPoint(i: Inst) throws {
        insertPoint.inst = i
        insertPoint.block = i.parentBlock
        insertPoint.function = i.parentBlock?.parentFunction
    }
    
    /// Inserts the instruction to the end of the block, and updates its
    /// parent and the builder's insert point
    func addToCurrentBlock(inst: Inst) throws {
        guard let block = insertPoint.block else { throw VHIRError.noParentBlock }
        inst.parentBlock = block
        try block.insert(inst)
        try setInsertPoint(inst)
    }
        
}
