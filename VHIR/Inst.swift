//
//  Inst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol Inst: RValue {
    var uses: [Operand] { get }
    var args: [Operand] { get set }
    var instHasSideEffects: Bool { get }
}

/// An instruction. Must be overriden but is used to remove
/// a lot of the state boilerplate that cant be defaulted
/// using just protocols
class InstBase: Inst {
    
    /// Self’s type, override with a computed getter
    var type: Ty? { fatalError("Override me") }
    /// override with the IR description, called by base to print this inst
    var instVHIR: String { fatalError("Override me") }
    
    var irName: String?
    weak var parentBlock: BasicBlock!
    
    var uses: [Operand] = []
    var args: [Operand] = []
    
    // calls into the subclasses overriden `instVHIR`
    var vhir: String { return instVHIR }
    
    private(set) var hasSideEffects = false
    var instHasSideEffects: Bool { return hasSideEffects }
    
    init(args: [Operand], irName: String? = nil) {
        self.args = args
        self.uses = []
        self.irName = irName
        
        for arg in self.args { arg.user = self }
    }
}

extension Inst {
    /// Removes the function from its parent
    func removeFromParent() throws {
        try parentBlock.remove(self)
    }
    /// Removes the function from its parent and
    /// drops all references to it
    func eraseFromParent() throws {
        
        // tell self’s operands that we’re not using it any more
        for arg in args { arg.value?.removeUse(arg) }
        args.removeAll()
        // remove this from everthing
        removeAllUses()
        try removeFromParent()
    }
    
}