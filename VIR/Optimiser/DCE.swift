//
//  DCE.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Dead code elimination pass
struct DCEPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    
    static func run(on function: Function) throws {
        
        for inst in function.instructions.reversed()
            where inst.uses.isEmpty && !inst.instHasSideEffects {
                try inst.eraseFromParent()
                
        }
        
    }
}

struct DeadFunctionPass : OptimisationPass {
    
    typealias PassTarget = Module
    static var minOptLevel: OptLevel = .low
    
    static func run(on module: Module) throws {
        for _ in module.functions {
            // remove function if no users & private
            // need to implement function users if i want to do this
        }
    }
}

struct CFGSimplificationPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    
    static func run(on function: Function) throws {
        
        for _ in function.blocks ?? [] {            
        }
        
    }
}


