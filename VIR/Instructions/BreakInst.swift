//
//  BreakInst.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias BlockCall = (block: BasicBlock, args: [BlockOperand]?)

protocol BreakInstruction : Inst {
}

final class BreakInst : InstBase, BreakInstruction {
    var call: BlockCall
    
    override var type: Type? { return nil }
    
    private init(call: BlockCall) {
        self.call = call
        super.init(args: call.args ?? [], irName: nil)
    }
    
    override var instVIR: String {
        return "break $\(call.block.name)\(call.args?.virValueTuple() ?? "")"
    }
    
    override var hasSideEffects: Bool { return true }
    override var isTerminator: Bool { return true }
}

final class CondBreakInst : InstBase, BreakInstruction {
    var thenCall: BlockCall, elseCall: BlockCall
    var condition: Operand
    
    override var type: Type? { return nil }
    
    private init(then: BlockCall, else: BlockCall, condition: Operand) {
        self.thenCall = then
        self.elseCall = `else`
        self.condition = condition
        let args = (thenCall.args ?? []) + (elseCall.args ?? [])
        super.init(args: args, irName: nil)
    }
    
    override var instVIR: String {
        return "break \(condition.vir), $\(thenCall.block.name)\(thenCall.args?.virValueTuple() ?? ""), $\(elseCall.block.name)\(elseCall.args?.virValueTuple() ?? "")"
    }
    
    override var hasSideEffects: Bool { return true }
    override var isTerminator: Bool { return true }
}

extension Builder {
    
    @discardableResult
    func buildBreak(to block: BasicBlock, args: [BlockOperand]? = nil) throws -> BreakInst {
//        if let _ = block.parameters {
//            guard let applied = params?.map({$0.1})
//                where paramTypes.map({ $0.paramName }).elementsEqual(applied, isEquivalent: ==)
//                else { throw VIRError.wrongBlockParams }
//        }
        let s = BreakInst(call: (block: block, args: args))
        try addToCurrentBlock(inst: s)
        
        guard let sourceBlock = insertPoint.block else { throw VIRError.noParentBlock }
        try block.addApplication(from: sourceBlock, args: args, breakInst: s)
        return s
    }
    
    @discardableResult
    func buildCondBreak(if condition: Operand, to then: BlockCall, elseTo: BlockCall) throws -> CondBreakInst {
//        if let _ = thenBlock.block.parameters {
//            guard let applied = params?.optionalMap({$0.type}),
//                let b = applied.optionalMap({ $0.type! })
//                where paramTypes.map({ $0.1 }).elementsEqual(b, isEquivalent: ==)
//                else { throw VIRError.wrongBlockParams }
//        }
        let s = CondBreakInst(then: then, else: elseTo, condition: condition)
        try addToCurrentBlock(inst: s)
        
        guard let sourceBlock = insertPoint.block else { throw VIRError.noParentBlock }
        try then.block.addApplication(from: sourceBlock, args: then.args, breakInst: s)
        try elseTo.block.addApplication(from: sourceBlock, args: elseTo.args, breakInst: s)
        return s
    }
}