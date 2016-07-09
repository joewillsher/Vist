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
    private typealias InlineRecord = [String: (source: Value, inlined: Value)]
    
    static func run(on function: Function) throws {
        
        for inst in function.instructions {
            try inline(inst, function: function)
        }
    }
    
    static func inline(_ inst: Inst, function: Function) throws {
        
        switch inst {
        case let call as FunctionCallInst
            where call.function.isInlineable && call.function.shouldInline(at: .high):
            
            let block = call.function.blocks![0]
            
            var record: InlineRecord = [:], params: [Param] = []
            
            try call.replace { explosion in
                
                // forward pass FIXME: should be through dominator tree
                
                // add params
                for param in block.parameters ?? [] {
                    let inlined = param.copy()
                    record[param.name] = (source: param, inlined: inlined)
                    params.append(inlined)
                }
                
                // move instructions
                for inst in block.instructions {
                    
                    let importedInst: Inst
                    
                    switch try inst.copy(using: &record) {
                    case let returnInst as ReturnInst:
                        importedInst = explosion.insert(inst:
                            VariableInst(operand: Operand(record[returnInst.returnValue.name]!.inlined),
                                         irName: call.function.name+".ret"))
//                    case let inst as FunctionCallInst:
//                        TODO: Recursive inlining, checking for cycles
                    case let inst:
                        importedInst = explosion.insert(inst: inst)
                        importedInst.args = importedInst.args.map { arg in
                            Operand(record[arg.name]!.inlined)
                        }
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

extension Inst {
        
    private func copy(using found: inout InlinePass.InlineRecord) throws -> Self {
        let i = copy()
        found[name] = (source: self, inlined: i)
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

