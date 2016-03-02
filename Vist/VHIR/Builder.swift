//
//  Builder.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class Builder {
    weak var module: Module?
    var inst: Inst?
    var block: BasicBlock?
    var function: Function?
    
    init(module: Module) {
        self.module = module
    }
}

extension Builder {
    
    func setInsertPoint(node: VHIR) throws {
        switch node {
        case let f as Function:
            guard let b = try? f.getLastBlock() else {
                function = f
                try addBasicBlock("entry")
                return
            }
            inst = b.instructions.last
            block = b
            function = f
            
        case let b as BasicBlock:
            inst = b.instructions.last
            block = b
            function = b.parentFunction
            
        case let i as Inst:
            inst = i
            block = i.parentBlock
            function = i.parentBlock?.parentFunction
        default:
            throw VHIRError.cannotMoveBuilderHere
        }
    }
    
    func addToCurrentBlock(inst: Inst) throws {
        guard let block = block else { throw VHIRError.noParentBlock }
        inst.parentBlock = block
        try block.insert(inst)
        try setInsertPoint(inst)
    }
    
    func addBasicBlock(name: String, params: [Value]? = nil) throws -> BasicBlock {
        if let function = function, let b = function.blocks where !b.isEmpty {
            let bb = BasicBlock(name: name, parameters: params, parentFunction: function)
            function.blocks?.append(bb)
            block = bb
            return bb
        }
        else {
            throw VHIRError.noFunctionBody
        }
    }
    
}
