//
//  BreakInst.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias BlockCall = (block: BasicBlock, args: [BlockOperand]?)

final class BreakInst: InstBase {
    var call: BlockCall
    
    override var type: Ty? { return nil }
    
    private init(call: BlockCall) {
        self.call = call
        super.init()
        self.irName = irName
        self.args = args ?? []
    }
    
    override var instVHIR: String {
        return "break $\(call.block.name)\(call.args?.vhirValueTuple() ?? "")"
    }
    
    override var hasSideEffects: Bool { return true }
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
        self.args = (thenCall.args ?? []) + (elseCall.args ?? [])
    }
    
    override var instVHIR: String {
        return "break \(condition.vhir), $\(thenCall.block.name)\(thenCall.args?.vhirValueTuple() ?? ""), $\(elseCall.block.name)\(elseCall.args?.vhirValueTuple() ?? "")"
    }
    
    override var hasSideEffects: Bool { return true }
}

extension Builder {
    
    func buildBreak(to block: BasicBlock, args: [BlockOperand]? = nil) throws -> BreakInst {
//        if let _ = block.parameters {
//            guard let applied = params?.map({$0.1})
//                where paramTypes.map({ $0.paramName }).elementsEqual(applied, isEquivalent: ==)
//                else { throw VHIRError.wrongBlockParams }
//        }
        let s = BreakInst(call: (block: block, args: args))
        try addToCurrentBlock(s)
        
        guard let sourceBlock = insertPoint.block else { throw VHIRError.noParentBlock }
        try block.addApplication(from: sourceBlock, args: args)
        return s
    }
    
    func buildCondBreak(`if` condition: Operand, to then: BlockCall, elseTo: BlockCall) throws -> CondBreakInst {
//        if let _ = thenBlock.block.parameters {
//            guard let applied = params?.optionalMap({$0.type}),
//                let b = applied.optionalMap({ $0.type! })
//                where paramTypes.map({ $0.1 }).elementsEqual(b, isEquivalent: ==)
//                else { throw VHIRError.wrongBlockParams }
//        }
        let s = CondBreakInst(then: then, else: elseTo, condition: condition)
        try addToCurrentBlock(s)
        
        guard let sourceBlock = insertPoint.block else { throw VHIRError.noParentBlock }
        try then.block.addApplication(from: sourceBlock, args: then.args)
        try elseTo.block.addApplication(from: sourceBlock, args: elseTo.args)
        return s
    }
}