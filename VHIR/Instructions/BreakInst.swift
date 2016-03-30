//
//  BreakInst.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct BlockCall {
    var block: BasicBlock, args: [BlockOperand]?
    
    mutating func removeArg(atIndex index: Int) throws {
        if let arg = args?.removeAtIndex(index) {
            try arg.value?.removeAllUses()
        }
        if args?.isEmpty ?? false {
            args = nil
            
        }
    }
}

protocol BreakInstruction: Inst {
    func removeArg(atIndex index: Int) throws
}

final class BreakInst: InstBase, BreakInstruction {
    var call: BlockCall
    
    override var type: Ty? { return nil }
    
    private init(call: BlockCall) {
        self.call = call
        super.init(args: call.args ?? [], irName: nil)
    }
    
    override var instVHIR: String {
        return "break $\(call.block.name)\(call.args?.vhirValueTuple() ?? "")"
    }
    
    func removeArg(atIndex index: Int) throws {
        try call.removeArg(atIndex: index)
    }
    
    override var hasSideEffects: Bool { return true }
    override var isTerminator: Bool { return true }
}

final class CondBreakInst: InstBase, BreakInstruction {
    var thenCall: BlockCall, elseCall: BlockCall
    var condition: Operand
    
    override var type: Ty? { return nil }
    
    private init(then: BlockCall, `else`: BlockCall, condition: Operand) {
        self.thenCall = then
        self.elseCall = `else`
        self.condition = condition
        let args = (thenCall.args ?? []) + (elseCall.args ?? [])
        super.init(args: args, irName: nil)
    }
    
    override var instVHIR: String {
        // TODO: to print this we need to get the values from thenCall's args
        return "break \(condition.vhir), $\(thenCall.block.name)\(thenCall.args?.vhirValueTuple() ?? ""), $\(elseCall.block.name)\(elseCall.args?.vhirValueTuple() ?? "")"
    }
    
    func removeArg(atIndex index: Int) throws {
        try thenCall.removeArg(atIndex: index)
        try elseCall.removeArg(atIndex: index)
    }
    
    override var hasSideEffects: Bool { return true }
    override var isTerminator: Bool { return true }
}

extension Builder {
    
    func buildBreak(to block: BasicBlock, args: [BlockOperand]? = nil) throws -> BreakInst {
//        if let _ = block.parameters {
//            guard let applied = params?.map({$0.1})
//                where paramTypes.map({ $0.paramName }).elementsEqual(applied, isEquivalent: ==)
//                else { throw VHIRError.wrongBlockParams }
//        }
        let s = BreakInst(call: BlockCall(block: block, args: args))
        try addToCurrentBlock(s)
        
        guard let sourceBlock = insertPoint.block else { throw VHIRError.noParentBlock }
        try block.addApplication(from: sourceBlock, args: args, breakInst: s)
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
        try then.block.addApplication(from: sourceBlock, args: then.args, breakInst: s)
        try elseTo.block.addApplication(from: sourceBlock, args: elseTo.args, breakInst: s)
        return s
    }
}