//
//  Inst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A VIR instruction
protocol Inst : Value {
    /// The arguments applied to `self`
    var args: [Operand] { get set }
    
    var instHasSideEffects: Bool { get }
    var instIsTerminator: Bool { get }
}

/**
 An instruction. Must be overriden but is used to remove
 a lot of the state boilerplate that cant be defaulted
 using just protocols
 */
class InstBase : Inst {
    
    /// Self’s type, override with a computed getter
    var type: Type? { fatalError("Override function '\(#function)' in '\(self.dynamicType)'") }
    /// override with the IR description, called by base to print this inst
    var instVIR: String { fatalError("Override me '\(#function)' in '\(self.dynamicType)'") }
    
    final var irName: String?
    final weak var parentBlock: BasicBlock?
    
    final var uses: [Operand] = []
    final var args: [Operand] = []
    
    // calls into the subclasses overriden `instVIR`
    final var vir: String { return instVIR }
    
    private(set) var hasSideEffects = false, isTerminator = false
    // Accessors below implement protocol requirement; return the above
    // values which are to be overriden by subclasses
    final var instHasSideEffects: Bool { return hasSideEffects }
    final var instIsTerminator: Bool { return isTerminator }
    
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
        try parentBlock?.remove(inst: self)
    }
    
    /// Removes the function from its parent and
    /// drops all references to it
    func eraseFromParent() throws {
        
        // tell self’s operands that we’re not using it any more
        for arg in args {
            arg.removeSelfAsUser()
        }
        args.removeAll()
        // remove this from everthing
        removeAllUses()
        try removeFromParent()
    }
    
    /// Replaces all `Operand` instances which point to `self`
    /// with `val`
    func replaceAllUses(with val: Inst) {
        for use in uses {
            use.value = val
            val.addUse(use)
        }
        uses.removeAll()
    }
}

// We have to add it to instbase (not inst) because we can't use Inst protocol
// as a conformant of Inst in the generic parameter list
extension InstBase {
    /// Replace self by applying a function and a
    final func replace(with explode: (inout Explosion<InstBase>) throws -> Void) throws {
        var e = Explosion(inst: self)
        try explode(&e)
        try e.replaceInst()
    }
}


