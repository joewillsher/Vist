//
//  DCE.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Dead code elimination pass
struct DCEPass : OptimisationPass {
    
    static var minOptLevel: OptLevel = .low
    
    func runOn(function: Function) throws {
        
        for inst in function.instructions.reverse()
            where inst.uses.isEmpty && !inst.instHasSideEffects {
                try inst.eraseFromParent()
        }
        
    }
}

struct DeadFunctionPass : OptimisationPass {
    
    static var minOptLevel: OptLevel = .low
    
    func runOn(module: Module) throws {
        for _ in module.functions {
            // remove function if no users & private
            // need to implement function users if i want to do this
        }
    }
}

struct CFGSimplificationPass : OptimisationPass {
    static var minOptLevel: OptLevel = .high
    
    func runOn(function: Function) throws {
        
        for _ in function.blocks ?? [] {
            
//            guard bb.predecessors.count == 1 && bb.successors.count != 0 else { continue }
//            guard let application = bb.applications.first else { continue }
//            guard let args = application.args, pred = application.predecessor else { continue }
//            
//            
            
        }
        
    }
}


