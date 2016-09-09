//
//  RegisterAllocator.swift
//  Vist
//
//  Created by Josef Willsher on 09/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension MCFunction {
    
    func allocateRegisters() throws {
        let graph = InterferenceGraph(function: self)
    }
    
}

