//
//  CFG.swift
//  Vist
//
//  Created by Josef Willsher on 26/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// Removes dead blocks and merges blocks with trivial breaks
enum CFGFoldPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "cfg-fold"
    
    static func run(on function: Function) throws {
        
        guard function.hasBody else { return }
        
        // iterate up the dom tree, starting at the children; if we change
        // the CFG below, we invalidate this tree and start again
        for block in function.dominator.analysis.reversed() {
            // First we remove any unconditional, conditional breaks
            instLoop: for case let inst as BreakInstruction in block.instructions {
                
                let cond: Bool
                
                let toBlock: BasicBlock
                let unreachableBlock: BasicBlock
                let args: [BlockOperand]?
                
                let sourceBlock = inst.parentBlock!

                switch inst {
                case let condBreakInst as CondBreakInst:
                    guard case let literal as BoolLiteralInst = condBreakInst.condition.value else { continue }
                    
                    cond = literal.value
                    toBlock = cond ?
                        condBreakInst.thenCall.block : condBreakInst.elseCall.block
                    unreachableBlock = cond ?
                        condBreakInst.elseCall.block : condBreakInst.thenCall.block
                    args = literal.value ?
                        condBreakInst.thenCall.args : condBreakInst.elseCall.args
                    
                    try literal.eraseFromParent()
                    
                    let br = BreakInst(call: (block: toBlock, args: args))
                    try sourceBlock.insert(inst: br, after: inst)
                    
                    try toBlock.removeApplication(break: inst)
                    try unreachableBlock.removeApplication(break: inst)
                    try toBlock.addApplication(from: sourceBlock, args: args, breakInst: br)
                    
                    try inst.eraseFromParent(replacingAllUsesWith: br)
                    
                    function.dominator.invalidate()
                    OptStatistics.condBreakChecksRemoved += 1
                    
                case let castBreakInst as CheckedCastBreakInst:
                    
                    let val: Value?
                    
                    switch (castBreakInst.val.memType?.getConcreteNominalType(), castBreakInst.targetType.getConcreteNominalType()) {
                    case (let structType as StructType, let targetStructType as StructType):
                        cond = structType == targetStructType
                        val = castBreakInst.val.value
                        
                    case (let structType as StructType, let concept as ConceptType):
                        cond = structType.models(concept: concept)
                        val = castBreakInst.val.value
                        
                    case (is ConceptType, let structType as StructType):
                        guard case let const as ExistentialConstructInst = castBreakInst.val.value else {
                            continue instLoop
                        }
                        
                        cond = const.value.value?.type?.getBasePointeeType() == structType
                        val = cond ? const.value.value : nil
                        
                    case (is ConceptType, let targetConceptType as ConceptType):
                        continue instLoop // TODO
                    default:
                        fatalError()
                    }
                    
                    toBlock = cond ?
                        castBreakInst.successCall.block : castBreakInst.failCall.block
                    unreachableBlock = cond ?
                        castBreakInst.failCall.block : castBreakInst.successCall.block
                    args = cond ?
                        castBreakInst.successCall.args : castBreakInst.failCall.args
                    
                    if cond {
                        let mem: LValue
                        if val!.type!.isPointerType() {
                            mem = val as! LValue
                        } else {
                            let alloc = AllocInst(memType: castBreakInst.successVariable.type!.getBasePointeeType())
                            let st = StoreInst(address: alloc, value: val!)
                            try sourceBlock.insert(inst: st, at: castBreakInst)
                            try sourceBlock.insert(inst: alloc, at: st)
                            mem = alloc
                        }
                        castBreakInst.successVariable.replaceAllUses(with: mem)
                        // remove success block params
                        toBlock.parameters?.removeFirst()
                        if toBlock.parameters?.isEmpty ?? false {
                            toBlock.parameters = nil
                        }
                    }
                    
                    let br = BreakInst(call: (block: toBlock, args: args))
                    try sourceBlock.insert(inst: br, after: inst)
                    
                    try toBlock.removeApplication(break: inst)
                    try unreachableBlock.removeApplication(break: inst)
                    // create normal application to target block
                    try toBlock.addApplication(from: sourceBlock, args: args, breakInst: br)
                    
                    try inst.eraseFromParent(replacingAllUsesWith: br)
                    
                    function.dominator.invalidate()
                    OptStatistics.condBreakChecksRemoved += 1
                    
                default:
                    continue instLoop
                }
                
                
            }
        }
        
        // we can remove blocks with no preds without affecting the dom tree
        for block in function.blocks! where function.canRemove(block: block) {
            try function.removeBlock(block)
        }
        
        // then squash any pointless breaks
        for block in function.dominator.analysis.reversed() where block.predecessors.count == 1 {
            let application = block.applications[0]
            // if it is an unconditional break
            guard case let breakInst as BreakInst = application.breakInst, let pred = application.predecessor else {
                continue
            }
            
            // wire params up to the applied arg
            for (param, arg) in zip(block.parameters ?? [], application.args ?? []) {
                param.replaceAllUses(with: arg.value!)
            }
            
            try block.removeApplication(break: breakInst)
            try breakInst.eraseFromParent()
            
            for inst in block.instructions {
                
                // move any break insts
                if case let brToNext as BreakInstruction = inst {
                    for succ in brToNext.successors {
                        // rewire each arg to say it is from pred, so when the phi
                        // is generated the phi-incoming block is correct
                        for arg in succ.args ?? [] {
                            arg.predBlock = pred
                        }
                        // rewire them to point from the pred block to the next block
                        try succ.block.removeApplication(break: brToNext)
                        try succ.block.addApplication(from: pred, args: succ.args, breakInst: brToNext)
                    }
                }
                
                // move over the inst
                try block.remove(inst: inst)
                pred.append(inst)
            }
            
            try block.eraseFromParent()
            function.dominator.invalidate()
            
            OptStatistics.blocksMerged += 1
        }
        
        
    }
}

private extension Function {
    /// - returns: true iff `block` has no preds and is not the entry block
    func canRemove(block: BasicBlock) -> Bool {
        return (entryBlock !== block) && block.predecessors.isEmpty
    }
    
    func removeBlock(_ block: BasicBlock) throws {
        for inst in block.instructions {
            // remove any break insts
            if case let brToNext as BreakInstruction = inst {
                for succ in brToNext.successors {
                    try succ.block.removeApplication(break: brToNext)
                }
            }
            try inst.eraseFromParent()
        }
        // remove block
        try block.removeFromParent()
        OptStatistics.deadBlocksRemoved += 1
    }
}

extension OptStatistics {
    static var deadBlocksRemoved = 0
    static var blocksMerged = 0
    /// How many `cond_break` insts are promoted to `break`
    static var condBreakChecksRemoved = 0
}

