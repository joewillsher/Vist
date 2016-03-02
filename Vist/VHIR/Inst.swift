//
//  Inst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// An instruction o
protocol Inst: Value {
    var args: [Operand] { get }
    var type: Ty? { get }
    var instName: String { get }
}

extension Inst {
    /// Removes the function from its parent
    func removeFromParent() throws {
        try parentBlock?.remove(self)
    }
    /// Removes the function from its parent and
    /// drops all references to it
    func eraseFromParent() throws {
        removeAllUses()
        try parentBlock?.remove(self)
    }
    
    var module: Module? {
        return parentBlock?.parentFunction.parentModule
    }
}