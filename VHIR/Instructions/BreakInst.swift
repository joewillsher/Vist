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
        self.params = params
        super.init()
        self.irName = irName
        self.args = params ?? []
    }
    
    override var instVHIR: String {
        let d: [Ty]? = params?.optionalMap({$0.type})
        return "break \(block.name)\(d?.vhirTypeTuple() ?? "")"
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
        return "break \(condition.vhir), \(block.name)\(params?.vhirValueTuple() ?? ""), \(elseBlock.name)\(params?.vhirValueTuple() ?? "")"
    }
}

extension Builder {
    
    func buildBreak(block: BasicBlock, params: [Operand]?) throws -> BreakInst {
        if let _ = block.parameters {
//            guard let applied = params?.map({$0.1})
//                where paramTypes.map({ $0.paramName }).elementsEqual(applied, isEquivalent: ==)
//                else { throw VHIRError.wrongBlockParams }
        }
        let s = BreakInst(block: block, params: params)
        try addToCurrentBlock(s)
        
        guard let sourceBlock = insertPoint.block else { throw VHIRError.noParentBlock }
        try block.addApplication(from: sourceBlock, args: params)
        
        return s
    }
    func buildCondBreak(block: BasicBlock, elseBlock: BasicBlock, condition: Operand, params: [Operand]?) throws -> CondBreakInst {
        if let _ = block.parameters {
//            guard let applied = params?.optionalMap({$0.type}),
//                let b = applied.optionalMap({ $0.type! })
//                where paramTypes.map({ $0.1 }).elementsEqual(b, isEquivalent: ==)
//                else { throw VHIRError.wrongBlockParams }
        }
        let s = CondBreakInst(block: block, elseBlock: elseBlock, condition: condition, params: params)
        try addToCurrentBlock(s)
        
        guard let sourceBlock = insertPoint.block else { throw VHIRError.noParentBlock }
        try block.addApplication(from: sourceBlock, args: params)
        
        return s
    }
}