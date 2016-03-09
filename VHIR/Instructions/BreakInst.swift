//
//  BreakInst.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias BlockCall = (block: BasicBlock, params: [Operand]?)

final class BreakInst: InstBase {
    var block: BasicBlock, params: [Operand]?
    
    override var type: Ty? { return nil }
    
    private init(call: BlockCall) {
        self.block = call.block
        self.params = call.params
        super.init()
        self.irName = irName
        self.args = params ?? []
    }
    
    override var instVHIR: String {
        return "break \(block.name)\(params?.vhirValueTuple() ?? "")"
    }
    
}

final class CondBreakInst: InstBase {
    var thenCall: BlockCall, elseCall: BlockCall
    var condition: Operand
    
    override var type: Ty? { return nil }
    
    private init(then: BlockCall, `else`: BlockCall, condition: Operand) {
        self.thenCall = then
        self.elseCall = `else`
        self.condition = condition
        super.init()
        self.irName = irName
        self.args = (thenCall.params ?? []) + (elseCall.params ?? [])
    }
    
    override var instVHIR: String {
        return "break \(condition.vhir), \(thenCall.block.name)\(thenCall.params?.vhirValueTuple() ?? ""), \(elseCall.block.name)\(elseCall.params?.vhirValueTuple() ?? "")"
    }
}

extension Builder {
    
    func buildBreak(block: BasicBlock, params: [Operand]? = nil) throws -> BreakInst {
//        if let _ = block.parameters {
//            guard let applied = params?.map({$0.1})
//                where paramTypes.map({ $0.paramName }).elementsEqual(applied, isEquivalent: ==)
//                else { throw VHIRError.wrongBlockParams }
//        }
        let s = BreakInst(call: (block: block, params: params))
        try addToCurrentBlock(s)
        
        guard let sourceBlock = insertPoint.block else { throw VHIRError.noParentBlock }
        try block.addApplication(from: sourceBlock, args: params)
        return s
    }
    
    func buildCondBreak(condition: Operand, then: BlockCall, `else`: BlockCall) throws -> CondBreakInst {
//        if let _ = thenBlock.block.parameters {
//            guard let applied = params?.optionalMap({$0.type}),
//                let b = applied.optionalMap({ $0.type! })
//                where paramTypes.map({ $0.1 }).elementsEqual(b, isEquivalent: ==)
//                else { throw VHIRError.wrongBlockParams }
//        }
        let s = CondBreakInst(then: then, else: `else`, condition: condition)
        try addToCurrentBlock(s)
        
        guard let sourceBlock = insertPoint.block else { throw VHIRError.noParentBlock }
        try then.block.addApplication(from: sourceBlock, args: then.params)
        try `else`.block.addApplication(from: sourceBlock, args: `else`.params)
        return s
    }
}