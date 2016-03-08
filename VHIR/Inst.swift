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

/// An instruction. Must be overriden but is used to remove
/// a lot of the state boilerplate that cant be defaulted
/// using just protocols
class InstBase: Inst {
    
    /// Self's type, override with a computed getter
    var type: Ty? { fatalError("Override me") }
    /// override with the IR description, called by base to print this inst
    var instVHIR: String { fatalError("Override me") }
    
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
        try parentBlock.remove(self)
        removeAllUses()
        parentBlock = nil
    }
}