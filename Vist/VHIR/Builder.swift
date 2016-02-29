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
        let binInst = BinaryInst(name: name, l: l, r: r, irName: irName)
        binInst.parentBlock = block
        try block.insert(binInst, after: inst)
        inst = binInst
        return binInst
    }
    
    func createReturnInst(value: Operand) throws -> ReturnInst {
        guard let block = block else { throw VHIRError.noParentBlock }
        let retInst = ReturnInst(value: value, parentBlock: block)
        try block.insert(retInst, after: inst)
        inst = retInst
        return retInst
    }
    
}
