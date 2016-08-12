//
//  ExistentialUnbox.swift
//  Vist
//
//  Created by Josef Willsher on 11/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// Unbox existentials and replace their existential container projections with
/// the concrete object, witness method lookups with a function reference, and 
/// existential open for member access with a GEP
enum ExistentialUnboxPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "existential-unbox"
    
    static func run(on function: Function) throws {
        
        for _ in function.instructions {
            
        }
        
    }
}
