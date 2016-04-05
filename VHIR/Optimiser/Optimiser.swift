//
//  Optimiser.swift
//  Vist
//
//  Created by Josef Willsher on 12/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum OptLevel: Int {
    case off = 0, low = 1, high = 3
}

extension CompileOptions {
    func optLevel() -> OptLevel {
        if contains(.O) { return .low }
        else if contains(.Ohigh) { return .high }
        else { return .off }
    }
}

extension Module {
    
    func runPasses(optLevel optLevel: OptLevel) throws {
        
        for function in functions {
            try ConstantFoldingPass.create(function, optLevel: optLevel)
            try DCEPass.create(function, optLevel: optLevel)
            try CFGSimplificationPass.create(function, optLevel: optLevel)
        }
        
        try DeadFunctionPass.create(self, optLevel: optLevel)
        
    }
}


protocol OptimisationPass {
    /// What the pass is run on, normally function or module
    associatedtype Element
    /// The minimum opt level this pass will be run
    static var minOptLevel: OptLevel { get }
    init()
    /// Runs the pass
    func runOn(element: Element) throws
}

extension OptimisationPass {
    static func create(function: Element, optLevel: OptLevel) throws {
        guard optLevel.rawValue >= minOptLevel.rawValue else { return }
        return try Self().runOn(function)
    }
}

// utils

extension Function {
    var instructions: LazyCollection<[Inst]> { return blocks.map { $0.flatMap { $0.instructions }.lazy } ?? LazyCollection([]) }
}

