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
    
    /// A record to look up already copied instructions, used when 
    /// traversing the inlined insts to connect them to their 
    /// replacement value
    private typealias InlineRecord = [(source: Value, inlined: Value)]
    
    static func run(on function: Function) throws {
        
        for inst in function.instructions {
            
            switch inst {
            case let call as FunctionCallInst
                where call.function.isInlineable && call.function.shouldInline(at: .high):
                
                let block = call.function.blocks![0]
                
                try call.replace { explosion in
                    
                    // forward pass FIXME: should be through dominator tree
                    
                    var found: InlineRecord = [], params: [Param] = []
                    
                    // add params
                    for param in block.parameters ?? [] {
                        found.append((source: param, inlined: param.copy()))
                        params.append(param)
                    }
                    
                    // move instructions
                    for inst in block.instructions {
                        
                        let importedInst: Inst
                        
                        switch try inst.copy(using: &found) {
                        case let returnInst as ReturnInst:
                            importedInst = explosion.insert(inst:
                                VariableInst(operand: returnInst.returnValue,
                                             irName: call.function.name+".ret"))
                        case let inst:
                            importedInst = explosion.insert(inst: inst)
                        }
                        
                        for (index, arg) in importedInst.args.enumerated() {
                            guard let new = found.first(where: { $0.source === arg.value }) else { fatalError() }
                            importedInst.args[index] = Operand(new.inlined) // TODO: will this always work?
                        }
                    }
                    
                    for (arg, param) in zip(call.args, params) {
                        param.replaceAllUses(with: arg.value!)
                    }
                    
                }
                
            case let call as FunctionApplyInst:
                break // TODO
                
            default: // the inst isnt a call or apply
                break
            }
            
            
        }
        
        
    }
    
}

extension Inst {
    
    func copy() -> Self {
        fatalError("eek")
    }
    
    private func copy(using found: inout InlinePass.InlineRecord) throws -> Self {
        
        let i = copy()
        found.append((source: self, inlined: i))
        
        return i
    }
    
}




// copy to new location, then replace all users when we have the replacement

private extension BasicBlock {
    
    
    /// Creates a parentless basic block which is a copy of self
    func copy() -> BasicBlock {
        
        let params = parameters?.map { $0.copy() }
        let b = BasicBlock(name: name, parameters: params, parentFunction: nil)
        
        
        
        return b
    }
    
}

extension Param {
    
    // param has no params so a copy is clean
    func copy() -> Param {
        precondition(phi == nil) // cannot copy if we are in VIRLower
        return Param(paramName: paramName, type: type!)
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

