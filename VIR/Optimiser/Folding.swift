//
//  Folding.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



struct ConstantFoldingPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    
    static func run(on function: Function) throws {
        
        for _ in function.instructions {
            
//            guard case let builtin as BuiltinInstCall = inst else { continue }
//            
//            switch builtin.inst {
//            case .iadd:
//                
//                _ = builtin.args
//                
//                
//                
//            default:
//                continue
//            }
            
        }
        
    }
}

