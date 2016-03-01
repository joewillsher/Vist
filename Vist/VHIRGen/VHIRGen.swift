//
//  VHIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol VHIRGenerator {
    func vhirGen(module: Module) throws
}

extension AST: VHIRGenerator {
    
    func vhirGen(module: Module) throws {
        
    }
}

