//
//  Verify.swift
//  Vist
//
//  Created by Josef Willsher on 16/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension Module {
    
    func verify() {
        for function in functions where function.hasBody {
            function.verify()
        }
    }
}

extension Function {
    
    func verify() {
        guard let blocks = blocks else { return  }
        
        for block in blocks {
            for inst in block.instructions {
                // check operands are alive
                for arg in inst.args {
                    assert(arg.value != nil,
                           "\(inst.valueName) : \(inst.dynamicType) has a null argument")
                    assert(arg.value?.parentFunction == self || arg.value is VoidLiteralValue,
                           "\(inst.valueName) : \(inst.dynamicType) has an arg from another function ('\(arg.value?.parentFunction?.name ?? "nil")')")
                }
                // check the users are alive
                for use in inst.uses {
                    assert(use.user != nil,
                           "\(inst.valueName) : \(inst.dynamicType) has a null user")
                    assert(use.user?.parentFunction == self,
                           "\(inst.valueName) : \(inst.dynamicType) is referenced from another function ('\(use.user?.parentFunction?.name ?? "nil")')")
                }
            }
            
            // check the block's exit is a control flow inst
            if let last = block.instructions.last {
                assert(last is ReturnInst || last is BreakInstruction,
                       "Last instruction in \(block.name) must be a control flow instruction")
            }
        }

    }
}
