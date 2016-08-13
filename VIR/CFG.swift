//
//  CFG.swift
//  Vist
//
//  Created by Josef Willsher on 26/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 ```
 func @factorial_tI : &thin (#Int) -> #Int {
 $entry(%a: #Int):
   %0 = int_literal 1
   %1 = struct_extract %a: #Int, !value
   %i_eq = builtin i_eq %1: #Builtin.Int64, %0: #Builtin.Int64
   break %i_eq: #Builtin.Bool, $if.0, $fail.0

 $if.0:
   %3 = int_literal 1
   %4 = struct %Int, (%3: #Builtin.Int64)
   return %4

 $fail.0:
   break $else.1

 $else.1:
   return %a
 }
 ```
 becomes
 ```
 func @factorial_tI : &thin (#Int) -> #Int {
 $entry(%a: #Int):
   %0 = int_literal 1
   %1 = struct_extract %a: #Int, !value
   %i_eq = builtin i_eq %1: #Builtin.Int64, %0: #Builtin.Int64
   break %i_eq: #Builtin.Bool, $true, $false

 $true:
   %3 = int_literal 1
   %4 = struct %Int, (%3: #Builtin.Int64)
   break $else.1 (%4: #Int)

 $false:
   break $else.1 (%a: #Int)

 $exit(%r: #Int):
   return %a
 }
 ```
*/
enum CFGPass : OptimisationPass {

    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "cfg"
    
    static func run(on function: Function) throws {
        try CFGFoldPass.run(on: function)
    }
}

enum CFGFoldPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "cfg-fold"
    
    static func run(on function: Function) throws {
        
        // remove any unconditional, conditional breaks
        for block in function.blocks ?? [] {
            for case let condBreakInst as CondBreakInst in block.instructions {
                
                guard case let literal as BoolLiteralInst = condBreakInst.condition.value else { continue }
                
                
                let toBlock: BasicBlock
                let unreachableBlock: BasicBlock
                let sourceBlock = condBreakInst.parentBlock!
                let args: [BlockOperand]?
                
                // if unconditionally true
                if literal.value {
                    toBlock = condBreakInst.thenCall.block
                    unreachableBlock = condBreakInst.elseCall.block
                    args = condBreakInst.thenCall.args
                }
                // if unconditionally false
                else {
                    toBlock = condBreakInst.elseCall.block
                    unreachableBlock = condBreakInst.thenCall.block
                    args = condBreakInst.elseCall.args
                }
                
                let br = BreakInst(call: (block: toBlock, args: args))
                try sourceBlock.insert(inst: br, after: condBreakInst)
                
                try toBlock.addApplication(from: sourceBlock, args: args, breakInst: br)
                try toBlock.removeApplication(break: condBreakInst)
                try unreachableBlock.removeApplication(break: condBreakInst)
                
                try literal.eraseFromParent()
                try condBreakInst.eraseFromParent(replacingAllUsesWith: br)
            }
        }
        
        // then remove any dead blocks, squash any pointless breaks
        for block in function.blocks ?? [] {
            switch block.applications.count {
                // if the block has only 1 pred we can put this block's instructions into that
            case 1:
                let application = block.applications[0]
                // if it is an unconditional break
                guard case let breakInst as BreakInst = application.breakInst, let pred = application.predecessor else { continue }
                
                try block.removeApplication(break: breakInst)
                try breakInst.eraseFromParent()
                
                for inst in block.instructions {
                    
                    // move any break insts
                    if case let brToNext as BreakInstruction = inst {
                        for succ in brToNext.successors {
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
                
                // if the block has no preds, we can remove it
            case 0:
                for inst in block.instructions {
                    // remove any break insts
                    if case let brToNext as BreakInstruction = inst {
                        for succ in brToNext.successors {
                            try succ.block.removeApplication(break: brToNext)
                        }
                    }
                }
                // remove block
                try block.removeFromParent()
                
            default:
                break
            }
        }
        
        
    }
}


