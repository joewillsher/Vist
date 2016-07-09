//
//  Inliner.swift
//  Vist
//
//  Created by Josef Willsher on 20/06/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Inline pass inlines single block functions
struct InlinePass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    
    static func run(on function: Function) throws {
        
        if function.hasHadInline { return }
        function.hasHadInline = true
        
        for inst in function.instructions {
            switch inst {
            case let call as FunctionCallInst:
                
                // inline that function first
                try run(on: call.function)
                
                var explosion = Explosion(replacing: call)
                // if it was inlined, replace the inst
                if try inline(call, intoFunction: function, explosion: &explosion) {
                    try explosion.replaceInst()
                }
                
            case _ as FunctionApplyInst:
                break // TODO
            default: // the inst isnt a call or apply
                break
            }
        }
    }
    
    /// - returns: whether the call was inlined
    static func inline(_ call: FunctionCallInst, intoFunction: Function, explosion: inout Explosion<FunctionCallInst>) throws -> Bool {
        
        guard call.function.isInlineable && call.function.shouldInline(at: .high) else {
            return false
        }
        
        let block = call.function.blocks![0]
        
        var alreadyInlined: [String: Value] = [:], params: [Param] = []
        
        // forward pass FIXME: should be through dominator tree
        
        // add params
        for param in block.parameters ?? [] {
            let inlined = param.copy()
            alreadyInlined[param.name] = inlined
            params.append(inlined)
        }
        
        // move instructions
        for sourceInst in block.instructions {
            
            let inst = try sourceInst.copy(using: &alreadyInlined)
            
            if case let returnInst as ReturnInst = inst {
                explosion.insert(inst:
                    VariableInst(operand: Operand(alreadyInlined[returnInst.returnValue.name]!),
                                 irName: call.function.name+".ret"))
                break // last inst in block is return
            }
            
            let inlinedInst = explosion.insert(inst: inst)
            
            for arg in inlinedInst.args {
                arg.value = alreadyInlined[arg.name]!
            }
        }
        
        for (arg, param) in zip(call.args, params) {
            param.replaceAllUses(with: arg.value!)
        }
        
        return true
    }
    
    

}

extension Inst {
    
    private func copy(using found: inout [String: Value]) throws -> Self {
        let i = copy()
        found[name] = i
        return i
    }
    
}




// copy to new location, then replace all users when we have the replacement

private extension BasicBlock {
    
    
    /// Creates a parentless basic block which is a copy of self
    func copy() -> BasicBlock {
        let params = parameters?.map { $0.copy() }
        return BasicBlock(name: name, parameters: params, parentFunction: nil)
    }
    
}

extension Param {
    
    // param has no params so a copy is clean
    func copy() -> Self {
        precondition(phi == nil) // cannot copy if we are in VIRLower
        return self.dynamicType.init(paramName: paramName, type: type!)
    }
}



private extension Function {
    
    /// Can we inline this function
    var isInlineable: Bool {
        return blocks.map { $0.count <= 1 } ?? false
    }
    
    /// Do we want to inline this function at `optLevel`
    func shouldInline(at optLevel: OptLevel) -> Bool {
        precondition(isInlineable)
        
        return true
    }
    
}

