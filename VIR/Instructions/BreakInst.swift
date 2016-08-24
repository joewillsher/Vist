//
//  BreakInst.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias BlockCall = (block: BasicBlock, args: [BlockOperand]?)

protocol BreakInstruction : Inst {
    var successors: [BlockCall] { get }
    
    /// Adds `outgoingArg` to each outgoing edge
    func addPhi(outgoingVal arg: Value, phi: Param, from block: BasicBlock) throws
    func hasPhiArg(_: Param) -> Bool
}

final class BreakInst : BreakInstruction, Inst {
    var call: BlockCall
    
    var uses: [Operand] = []
    var args: [Operand]
    
    var type: Type? { return nil }
    
    init(call: BlockCall) {
        self.call = call
        self.args = call.args ?? []
        initialiseArgs()
    }
    
    var vir: String {
        return "break $\(call.block.name)\(call.args?.virValueTuple() ?? "") // id: \(name)"
    }
    
    var hasSideEffects: Bool { return true }
    var isTerminator: Bool { return true }
    
    var parentBlock: BasicBlock?
    var irName: String?
    
    var successors: [BlockCall] {
        return [call]
    }
    
    func addPhi(outgoingVal arg: Value, phi: Param, from block: BasicBlock) throws {
        let arg = BlockOperand(optionalValue: arg, param: phi, block: block)
        call.args = (call.args ?? []) + [arg]
        try call.block.addPhiArg(arg, from: block)
        args.append(arg)
        initialiseArgs()
    }
    
    func hasPhiArg(_ phi: Param) -> Bool {
        return call.args?.contains(where: { $0.param === phi }) ?? false
    }
}

final class CondBreakInst : Inst, BreakInstruction {
    var thenCall: BlockCall, elseCall: BlockCall
    var condition: Operand
    
    var uses: [Operand] = []
    var args: [Operand]
    
    var type: Type? { return nil }
    
    init(then: BlockCall, else: BlockCall, condition: Operand) {
        self.thenCall = then
        self.elseCall = `else`
        self.condition = condition
        let blockArgs = (thenCall.args ?? []) + (elseCall.args ?? []) as [Operand]
        self.args = [condition] + blockArgs
        initialiseArgs()
    }
    
    var vir: String {
        return "cond_break \(condition.vir), $\(thenCall.block.name)\(thenCall.args?.virValueTuple() ?? ""), $\(elseCall.block.name)\(elseCall.args?.virValueTuple() ?? "") // id: \(name)"
    }
    
    var hasSideEffects: Bool { return true }
    var isTerminator: Bool { return true }
    
    var parentBlock: BasicBlock?
    var irName: String?
    
    var successors: [BlockCall] {
        return [thenCall, elseCall]
    }
    
    func addPhi(outgoingVal arg: Value, phi: Param, from block: BasicBlock) throws {
        let thenArg = BlockOperand(optionalValue: arg, param: phi, block: block)
        thenCall.args = (thenCall.args ?? []) + [thenArg]
        try thenCall.block.addPhiArg(thenArg, from: block)
        let elseArg = BlockOperand(optionalValue: arg, param: phi, block: block)
        elseCall.args = (elseCall.args ?? []) + [elseArg]
        try elseCall.block.addPhiArg(elseArg, from: block)
        args.append(thenArg)
        args.append(elseArg)
        initialiseArgs()
    }
    func hasPhiArg(_ phi: Param) -> Bool {
        // both thenCall and elseCall should have it, so we only need to check 1
        return thenCall.args?.contains(where: { $0.param === phi }) ?? false
    }
}

extension Builder {
    
    @discardableResult
    func buildBreak(to block: BasicBlock, args: [BlockOperand]? = nil) throws -> BreakInst {
//        if let _ = block.parameters {
//            guard let applied = params?.map({$0.1}),
//                paramTypes.map({ $0.paramName }).elementsEqual(applied, isEquivalent: ==)
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
//                let b = applied.optionalMap({ $0.type! }),
//                paramTypes.map({ $0.1 }).elementsEqual(b, isEquivalent: ==)
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
