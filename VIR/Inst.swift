//
//  Inst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A VIR instruction
protocol Inst : Value {
    
    var instHasSideEffects: Bool { get }
    var instIsTerminator: Bool { get }
    
    /// Override this to do stuff after setting args
    func setArgs(args: [Operand])
    /// Call this to set the args
    func setInstArgs(args: [Operand])
    
    var uses: [Operand] { get set }
    var args: [Operand] { get set }
    
    var type: Type? { get }
    
    var vir: String { get }
    
    var irName: String? { get set }
    weak var parentBlock: BasicBlock? { get set }
}

extension Inst {
    /// Removes the function from its parent
    func removeFromParent() throws {
        try parentBlock?.remove(inst: self)
    }
    
    func initialiseArgs() {
        for arg in self.args { arg.user = self }
    }
    
    func setArgs(args: [Operand]) { }
    
    func setInstArgs(args: [Operand]) {
        self.args = args
        setArgs(args: args)
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
    
    var instHasSideEffects: Bool { return false }
    var instIsTerminator: Bool { return false }
    
    func replace(with explode: @noescape (inout Explosion) throws -> Void) throws {
        var e = Explosion(replacing: self)
        try explode(&e)
        try e.replaceInst()
    }
    
}

extension Value {
    /// Replaces all `Operand` instances which point to `self`
    /// with `val`
    func replaceAllUses(with val: Value) {
        for use in uses {
            use.value = val
        }
    }
}

//// We have to add it to instbase (not inst) because we can't use Inst protocol
//// as a conformant of Inst in the generic parameter list
//extension InstBase {
//}


