//
//  Explosion.swift
//  Vist
//
//  Created by Josef Willsher on 16/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// An explosion of instructions -- used to replace an inst with many others
struct Explosion<InstType : Inst> {
    let instToReplace: InstType
    private(set) var explodedInstructions: [Inst] = []
    init(replacing inst: InstType) { instToReplace = inst }
    
    @discardableResult
    mutating func insert<I : Inst>(inst: I) -> I {
        explodedInstructions.append(inst)
        return inst
    }
    @discardableResult
    mutating func insert(inst: Inst) -> Inst {
        explodedInstructions.append(inst)
        return inst
    }
    
    mutating func insertTail(_ val: Value) {
        precondition(tail == nil) // cannot change tail
        tail = val
        // if the tail isnt just a value, but an inst, we want
        // to add it to the block too
        if case let inst as Inst = val {
            insert(inst: inst)
        }
    }
    
    /// The element of the explosion which replaces the inst
    private(set) var tail: Value? = nil
    private var block: BasicBlock? { return instToReplace.parentBlock }
    
    /// Replaces the instruction with the exploded values
    func replaceInst() throws {
        precondition(tail != nil)
        
        guard let block = instToReplace.parentBlock else {
            fatalError("TODO: throw error -- no block")
        }
        
        var pos = instToReplace as Inst
        
        // add the insts to this scope (if it's not already there)
        for i in explodedInstructions where !block.contains(i) {
            try block.insert(inst: i, after: pos)
            pos = i // insert next after this inst
        }
        
        try instToReplace.eraseFromParent(replacingAllUsesWith: tail)
    }
}
