//
//  ARC.swift
//  Vist
//
//  Created by Josef Willsher on 23/10/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


enum ARCSimplifyPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    static let name = "arc"
    
    static func run(on: Function) throws {
        
    }
}
