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
        if contains(.Ohigh) { return .high }
        else if contains(.O) { return .low }
        else { return .off }
    }
}

extension Module {
    
    func runPasses(optLevel: OptLevel) throws {
        
        for function in functions where function.hasBody {
            // this is first for testing
        }
        
        for function in functions where function.hasBody {
            try StdLibInlinePass.create(function, optLevel: optLevel)
            try InlinePass.create(function, optLevel: optLevel)
            try RegisterPromotionPass.create(function, optLevel: optLevel)
            try ConstantFoldingPass.create(function, optLevel: optLevel)
            try DCEPass.create(function, optLevel: optLevel)
//            try CFGSimplificationPass.create(function, optLevel: optLevel)
        }
        
        try DeadFunctionPass.create(self, optLevel: optLevel)
        
    }
}


protocol OptimisationPass {
    /// What the pass is run on, normally function or module
    associatedtype PassTarget
    /// The minimum opt level this pass will be run
    static var minOptLevel: OptLevel { get }
    /// Runs the pass
    static func run(on: PassTarget) throws
}

extension OptimisationPass {
    static func create(_ element: PassTarget, optLevel: OptLevel) throws {
        guard optLevel.rawValue >= minOptLevel.rawValue else { return }
        return try run(on: element)
    }
}

// utils

extension Function {
    var instructions: LazyCollection<[Inst]> { return blocks.map { $0.flatMap { $0.instructions }.lazy } ?? [Inst]().lazy }
}


/// An explosion of instructions -- used to replace an inst with many others
struct Explosion<InstType : Inst> {
    let inst: InstType
    private(set) var explodedInstructions: [Inst] = []
    init(replacing inst: InstType) { self.inst = inst }
    
    @discardableResult
    mutating func insert<I : Inst>(inst: I) -> I {
        explodedInstructions.append(inst)
        return inst
    }
    @discardableResult
    mutating func insert(inst: Inst) -> Inst {
        explodedInstructions.append(inst)
        return inst
    }
    
    /// The element of the explosion which replaces the inst
    var tail: Inst? { return explodedInstructions.last }
    private var block: BasicBlock? { return inst.parentBlock }
    
    /// Replaces the instruction with the exploded values
    func replaceInst() throws {
        
        guard let block = inst.parentBlock else {
            fatalError("TODO: throw error -- no block")
        }
        
        var pos = inst as Inst
        // add the insts to this scope
        for i in explodedInstructions {
            try block.insert(inst: i, after: pos)
            pos = i // insert next after this inst
        }
        
        try inst.eraseFromParent(replacingAllUsesWith: tail)
    }
}


final class DominatorTreeNode {
    
//    let block: BasicBlock
    
}

/// A tree of dominating blocks in a function
final class DominatorTree : Sequence {
    
    private var function: Function
    
    init(function: Function) {
        self.function = function
    }
    
    typealias Iterator = AnyIterator<BasicBlock>
    
    func makeIterator() -> Iterator {
        return AnyIterator {
            return nil
        }
    }
}


enum OptError : VistError {
    case invalidValue(Value)
    
    var description: String {
        switch self {
        case .invalidValue(let inst): return "Invalid value '\(inst.valueName)'"
        }
    }
}



