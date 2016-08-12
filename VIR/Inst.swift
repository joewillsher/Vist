//
//  Inst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A VIR instruction
protocol Inst : Value {
    
    /// Customise behaviour of `setInstArgs`: implementing this function
    /// allows you to set `self`'s properties when the argument list is
    /// overriden
    func setArgs(_ args: [Operand])
    
    /// The arguments applied to this operand
    var args: [Operand] { get set }
    
    var vir: String { get }
    
    /// The block owning this inst
    weak var parentBlock: BasicBlock? { get set }
    
    /// Does this inst have side effects? If false, it can
    /// be removed if there are no users
    var hasSideEffects: Bool { get }
    /// Is this inst a valid block terminator?
    var isTerminator: Bool { get }
}

extension Inst {
    
    /// Removes the function from its parent
    func removeFromParent() throws {
        try parentBlock?.remove(inst: self)
    }
    
    /// Removes the function from its parent and
    /// drops all references to it
    func eraseFromParent(replacingAllUsesWith value: Value? = nil) throws {
        
        if let value = value {
            replaceAllUses(with: value)
        }
        
        // tell self’s operands that we’re not using it any more
        for arg in args {
            arg.value = nil
        }
        args.removeAll()
        
        try removeFromParent()
    }
    
    /// Own the arguments of this instruction: set each
    /// arg's user to `self`
    func initialiseArgs() {
        for arg in self.args { arg.user = self }
    }
    
    // default impl is empty
    func setArgs(_ args: [Operand]) { }
    
    /// Set the arguments of `self` to `args`
    func setInstArgs(_ args: [Operand]) {
        self.args = args
        setArgs(args)
    }
    
    // default impl is false
    var hasSideEffects: Bool { return false }
    var isTerminator: Bool { return false }
    
    
    func replace(with explode: @noescape (inout Explosion) throws -> Void) throws {
        var e = Explosion(replacing: self)
        try explode(&e)
        try e.replaceInst()
    }
}

extension Value {
    /// Replaces all uses which point to `self`
    /// with `val`
    func replaceAllUses(with val: Value) {
        for use in uses {
            use.value = val
        }
    }
}


