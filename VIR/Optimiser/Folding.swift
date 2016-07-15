//
//  Folding.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



enum ConstantFoldingPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    
    static func run(on function: Function) throws {
        
        for inst in function.instructions {
            
            switch inst {
            case let builtin as BuiltinInstCall:
                switch builtin.inst {
                case .iadd:
                    let (lhs, rhs) = (builtin.lhs, builtin.rhs)
                    
                    
                default:
                    break
                }
                
                // see through variable instructions by removing them
            case let variable as VariableInst:
                try variable.eraseFromParent(replacingAllUsesWith: variable.value.value)
                
            default:
                break
            }
            
        }
        
    }
//    
//    static func staticIntValue(inst: Inst) -> Int? {
//        
//    }
//    
}

