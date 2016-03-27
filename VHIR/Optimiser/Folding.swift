//
//  Folding.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



final class ConstantFoldingPass: OptimisationPass {
    
    static var minOptLevel: OptLevel = .low
    
    func runOn(function: Function) throws {
        
        for inst in function.instructions {
            
            guard case let builtin as BuiltinInstCall = inst else { continue }
            
            switch builtin.inst {
            case .iadd:
                
                _ = builtin.args
                
                
                
            default:
                continue
            }
            
        }
        
    }
}

