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
        
        for inst in function.instructions.reversed() where
            inst.uses.isEmpty && !inst.instHasSideEffects {
                try inst.eraseFromParent()
                
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


