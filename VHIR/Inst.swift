//
//  Inst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol Inst: Value {
    var uses: [Operand] { get set }
    var args: [Operand] { get set }
}

/// An instruction o
class InstBase: Inst {
    
    /// Self's type, override with a computed getter
    var type: Ty? { return nil }
    /// override with the IR description, called by base to print this inst
    var instVHIR: String { fatalError() }
    
    var irName: String?
    weak var parentBlock: BasicBlock!
    
    var uses: [Operand] = []
    var args: [Operand] = []
    
    // calls into the subclasses overriden `instVHIR`
    var vhir: String { return instVHIR }
}

extension Inst {
    /// Removes the function from its parent
    func removeFromParent() throws {
        try parentBlock.remove(self)
    }
    /// Removes the function from its parent and
    /// drops all references to it
    func eraseFromParent() throws {
        removeAllUses()
        try parentBlock.remove(self)
    }
}