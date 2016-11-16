//
//  Codegen.swift
//  Vist
//
//  Created by Josef Willsher on 18/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.Process

private extension MCFunction {
    
    private func emitEpilogue() {
        // pushq    rbp
        // movq     rbp, rsp
        // subq     32, rsp
        let pushFrame = MCInst.push(target.basePtr)
        let mov = MCInst.mov(dest: .reg(target.basePtr), src: .reg(target.stackPtr))
        let growStack = MCInst.sub(target.stackPtr, .imm(stackSize))
        
        insts.insert(contentsOf: [pushFrame, mov, growStack], at: 0)
    }
    private func emitPrologue() {
        // addq	32, %rsp
        // popq	%rbp
        let pop = MCInst.add(target.stackPtr, .imm(stackSize))
        let shrinkStack = MCInst.pop(target.basePtr)
        
        let retIndex = insts.index(of: .ret)!
        insts.insert(contentsOf: [pop, shrinkStack], at: retIndex)
    }
    
    func emitStackManagement() {
        // if no stack usage, we don't need an epilogue or prologue
        guard stackSize > 0 else { return }
        emitEpilogue()
        emitPrologue()
    }
    
}


extension AIRModule {
    
    /// Emits machine code from the AIRModule, this performs instruction selection, 
    /// register allocation, then creates an asm file at `url`
    @discardableResult
    func emitMachine(at path: String, target: TargetMachine.Type) throws -> MCModule {
        
        let fns = try functions.map { function -> MCFunction in
            let dag = SelectionDAG(builder: builder, target: target)
            // TODO: currently only works when there is 1 block
            dag.build(block: function.blocks.first!)
            let fn = try MCFunction(name: function.name, dag: dag)
            try fn.allocateRegisters(builder: builder)
            fn.emitStackManagement()
            try PeepholePassManager(function: fn).runPasses()
            return fn
        }
        
        let module = MCModule(sections: [.text(functions: fns)])
        // write out
        try module.asm.write(toFile: path, atomically: false, encoding: .utf8)
        return module
    }
    
}



extension Module {
    
    /// - returns: the AIR for this VIR module
    func emitAIR(builder: AIRBuilder) throws -> AIRModule {
        
        let module = AIRModule(builder: builder)
        
        for function in functions {
            let ps = try function.params?.map { try $0.lowerVIRToAIR(builder: builder) as! AIRFunction.Param } ?? []
            let airFn = AIRFunction(name: function.name, type: function.type.machineType(), params: ps)
            function.airFunction = airFn
        }
        
        for function in functions where function.hasBody {
            for bb in function.dominator.analysis {
                let airBB = AIRBlock()
                builder.insertPoint.block = airBB
                function.airFunction!.blocks.append(airBB)
                
                // emit the AIR for the body
                for case let inst as AIRLower & Inst in bb.instructions {
                    let air = try inst.lowerVIRToAIR(builder: builder)
                    inst.updateUsesWithAIR(air)
                }
            }
            // add it to the module
            module.functions.append(function.airFunction!)
        }
        
        return module
    }
    
}
