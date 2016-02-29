//
//  Builder.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class Builder {
    var module: Module
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
                function = f; return
            }
            block = b
            inst = b.instructions.last
            
        case let b as BasicBlock:
            block = b
            inst = b.instructions.last
            
        case let i as Inst:
            block = i.parentBlock
            inst = i
            
        default:
            throw VHIRError.cannotMoveBuilderHere
        }
    }
    
    func addBasicBlock(name: String, params: [Value]? = nil) throws -> BasicBlock {
        if let function = function, let _ = function.blocks {
            let bb = BasicBlock(name: name, parameters: params, parentFunction: function)
            function.blocks?.append(bb)
            block = bb
            return bb
        }
        else if let function = function {
            let fnParams = zip(function.paramNames, function.type.params).map(BBParam.init).map { $0 as Value }
            let bb = BasicBlock(name: name, parameters: fnParams + (params ?? []), parentFunction: function)
            function.blocks = [bb]
            block = bb
            return bb
        }
        throw VHIRError.noFunctionBody
    }
    
    func createBinaryInst(name: String, l: Operand, r: Operand, irName: String? = nil) throws -> BinaryInst {
        guard let block = block else { throw VHIRError.noParentBlock }
        let i = BinaryInst(name: name, l: l, r: r, irName: irName)
        i.parentBlock = block
        try block.addInstruction(i)
        return i
    }
    
    func createReturnInst(value: Operand) throws -> ReturnInst {
        guard let p = block else { throw VHIRError.noParentBlock }
        let r = ReturnInst(value: value, parentBlock: p)
        try p.addInstruction(r)
        return r
    }
    
}
