//
//  Inliner.swift
//  Vist
//
//  Created by Josef Willsher on 20/06/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Inline pass inlines single block functions
struct InlinePass : OptimisationPass {
    
    typealias PassTarget = Module
    static let minOptLevel: OptLevel = .low
    
    static func run(on module: Module) throws {
        try module.functions.forEach(run(on:))
    }
    
    private static func run(on function: Function) throws {
        
        guard !function.hasHadInline else { return }
        function.hasHadInline = true
        
        for inst in function.instructions {
            switch inst {
            case let call as FunctionCallInst:
                // inline that function first
                try run(on: call.function)
                var explosion = Explosion(replacing: call)
                // if it was inlined, replace the inst
                if try inline(call, explosion: &explosion) {
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
    static func inline(_ call: FunctionCallInst, explosion: inout Explosion<FunctionCallInst>) throws -> Bool {
        
        guard call.function.isInlineable && call.function.shouldInline(at: .high) else {
            return false
        }
        
        let block = call.function.blocks![0]
        var alreadyInlined: [String: Value] = [:]
        
        // add params
        for (arg, param) in zip(call.args, block.parameters ?? []) {
            alreadyInlined[param.name] = arg.value!
        }
        
        func getValue(replacing val: Operand) -> Value {
            return alreadyInlined[val.name]
                ?? val.value!.copy() // if its not in the block (a literal) we can copy it as is
        }
        
        // forward pass FIXME: should be through dominator tree
        // move instructions
        for sourceInst in block.instructions {
            
            switch try sourceInst.copy(recordingIn: &alreadyInlined) {
            case let returnInst as ReturnInst:
                let inlinedInst = getValue(replacing: returnInst.returnValue)
                explosion.insertTail(inlinedInst)
                break // return must be last inst in block
                
            case let inlinedInst:
                
                // fix up the user of the inst's args
                inlinedInst.setInstArgs(args: inlinedInst.args.map { arg in
                    let operand = arg.formCopy(nullValue: true)
                    let v = getValue(replacing: arg)
                    arg.value = nil
                    arg.user = nil
                    operand.value = v
                    operand.user = inlinedInst
                    return operand
                })
                // modify name
                if let n = inlinedInst.irName {
                    inlinedInst.irName = "\(call.function.name.demangleName()).\(n)"
                }
                
                call.function.dump()
                
                // add the inst
                explosion.insert(inst: inlinedInst)
            }
        }
        
        return true
    }
    
}

private extension Inst {
    
    func copy(recordingIn found: inout [String: Value]) throws -> Self {
        let i = copy()
        found[name] = i
        return i
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

