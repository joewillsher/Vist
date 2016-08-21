//
//  DCE.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Dead code elimination pass
enum DCEPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    static let name = "dce"
    
    static func run(on function: Function) throws {
        
        try function.blocks?.forEach(UnreachableRemovePass.run(on:))

        for block in function.dominator.analsis.reversed() {
            for inst in block.instructions.reversed() where
                inst.uses.isEmpty && !inst.hasSideEffects {
                    try inst.eraseFromParent()
                    OptStatistics.deadInstructionsRemoved += 1
            }
        }
    }
}

/// Remove dynamically dead code which traps before being reached
private enum UnreachableRemovePass : OptimisationPass {
    
    typealias PassTarget = BasicBlock
    static let minOptLevel: OptLevel = .low
    static let name = "unreachable-remove"
    
    static func run(on block: BasicBlock) throws {
        
        // the insts after the current inst
        // -- the list to be removed if there is a trap
        var after: [Inst] = []
        // go backwards
        for inst in block.instructions.reversed() {
            // if it is a trap, remove all insts after
            if case let trap as BuiltinInstCall = inst, trap.inst == .trap {
                for i in after {
                    try i.eraseFromParent()
                    OptStatistics.unreachableInstructionsRemoved += 1
                }
            }
            after.append(inst)
        }
    }
}


enum DeadFunctionPass : OptimisationPass {
    
    typealias PassTarget = Module
    static let minOptLevel: OptLevel = .low
    static let name = "dead-function"
    
    static func run(on module: Module) throws {
        for _ in module.functions {
            // remove function if no users & private
            // need to implement function users if i want to do this
        }
    }
}

enum CFGSimplificationPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "cfg-simplify"
    
    static func run(on function: Function) throws {
        
        for _ in function.blocks ?? [] {            
        }
        
    }
}

extension OptStatistics {
    static var deadInstructionsRemoved = 0
    static var unreachableInstructionsRemoved = 0
}

