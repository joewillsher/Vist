//
//  Optimiser.swift
//  Vist
//
//  Created by Josef Willsher on 12/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum OptLevel {
    case off, low, high
}

extension Module {
    
    func runPasses(optLevel: OptLevel) throws {
        
        for function in functions {
            try DCEPass.create(function, optLevel: optLevel)
        }
        
    }
}


protocol FunctionPass {
    func runOn(function: Function) throws
    init(optLevel: OptLevel)
}
protocol ModulePass {
    func runOn(module: Module) throws
    init(optLevel: OptLevel)
}

extension ModulePass {
    static func create(module: Module, optLevel: OptLevel) throws {
        return try Self(optLevel: optLevel).runOn(module)
    }
}
extension FunctionPass {
    static func create(function: Function, optLevel: OptLevel) throws {
        return try Self(optLevel: optLevel).runOn(function)
    }
}



// utils

extension Function {
    var instructions: LazyCollection<[Inst]> { return blocks.map { $0.flatMap { $0.instructions }.lazy } ?? LazyCollection([]) }
}

