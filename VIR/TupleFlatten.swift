//
//  TupleFlatten.swift
//  Vist
//
//  Created by Josef Willsher on 22/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A simpler version of `StructFlatten` which doesn't need to
/// work with ptr insts
enum TupleFlattenPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "struct-flatten"
    
    static func run(on function: Function) throws {
        for inst in function.instructions {
            
            instCheck: switch inst {
            case let createInst as TupleCreateInst:
                var tupleMembers = createInst.args.map { $0.value! }
                
                for case let extract as TupleExtractInst in createInst.uses.map({$0.user}) {
                    let member = tupleMembers[extract.elementIndex]
                    // replace the extract inst with the member
                    try extract.eraseFromParent(replacingAllUsesWith: member)
                }
                
                // If all struct users have been removed, remove the init
                if createInst.uses.isEmpty {
                    try createInst.eraseFromParent()
                }
                    default:
                        break instCheck
                    }
                }
                
                try allocInst.eraseFromParent()
                
            default:
                break
            }
            
        }
        
    }
}
