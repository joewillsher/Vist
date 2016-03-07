//
//  BreakInst.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class BreakInst: InstBase {
    var block: BasicBlock, params: [Operand]?
    
    override var type: Ty? { return nil }
    
    private init(block: BasicBlock, params: [Operand]?) {
        self.block = block
        super.init()
        self.irName = irName
        self.args = params ?? []
    }
    
    override var instVHIR: String {
        return "break \(block.name)\(params.map {$0.vhirValueTuple()} ?? "")"
    }
    
}
final class CondBreakInst: InstBase {
    var block: BasicBlock, elseBlock: BasicBlock, params: [Operand]?
    var condition: Operand
    
    override var type: Ty? { return nil }
    
    private init(block: BasicBlock, elseBlock: BasicBlock, condition: Operand, params: [Operand]?) {
        self.block = block
        self.elseBlock = elseBlock
        self.condition = condition
        super.init()
        self.irName = irName
        self.args = params ?? []
    }
    
    override var instVHIR: String {
        return "break \(condition.vhir), \(block.name)\(params.map {$0.vhirValueTuple()} ?? ""), \(elseBlock.name)\(params.map {$0.vhirValueTuple()} ?? "")"
    }
    
}

extension Builder {
    
    func buildBreak(block: BasicBlock, params: [Operand]?) throws -> BreakInst {
        if let blockParams = block.parameters {
            guard let applied = params where applied.elementsEqual(blockParams, isEquivalent: {$0.type == $1.type}) else { throw VHIRError.wrongBlockParams }
        }
        let s = BreakInst(block: block, params: params)
        try addToCurrentBlock(s)
        return s
    }
    func buildCondBreak(block: BasicBlock, elseBlock: BasicBlock, condition: Operand, params: [Operand]?) throws -> CondBreakInst {
        if let blockParams = block.parameters {
            guard let applied = params where applied.elementsEqual(blockParams, isEquivalent: {$0.type == $1.type}) else { throw VHIRError.wrongBlockParams }
        }
        let s = CondBreakInst(block: block, elseBlock: elseBlock, condition: condition, params: params)
        try addToCurrentBlock(s)
        return s
    }
}