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
        for block in function.dominator.analsis.reversed() {
            // First we remove any unconditional, conditional breaks
            for case let condBreakInst as CondBreakInst in block.instructions {
                
                guard case let literal as BoolLiteralInst = condBreakInst.condition.value else { continue }
                
                let toBlock = literal.value ?
                    condBreakInst.thenCall.block : condBreakInst.elseCall.block
                let unreachableBlock = literal.value ?
                    condBreakInst.elseCall.block : condBreakInst.thenCall.block
                let args = literal.value ?
                    condBreakInst.thenCall.args : condBreakInst.elseCall.args
                
                let sourceBlock = condBreakInst.parentBlock!
                
                let br = BreakInst(call: (block: toBlock, args: args))
                try sourceBlock.insert(inst: br, after: condBreakInst)
                
                try toBlock.removeApplication(break: condBreakInst)
                try unreachableBlock.removeApplication(break: condBreakInst)
                try toBlock.addApplication(from: sourceBlock, args: args, breakInst: br)
                
                try literal.eraseFromParent()
                try condBreakInst.eraseFromParent(replacingAllUsesWith: br)
                
                function.dominator.invalidate()
            }
        }
        
        // we can remove blocks with no preds without affecting the dom tree
        for block in function.blocks! where function.canRemove(block: block) {
            try function.removeBlock(block)
        }
        
        // then squash any pointless breaks
        for block in function.dominator.analsis.reversed() where block.predecessors.count == 1 {
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
    }
}


