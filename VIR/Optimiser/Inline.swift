//
//  Inliner.swift
//  Vist
//
//  Created by Josef Willsher on 20/06/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// Inline pass inlines single block functions
enum InlinePass : OptimisationPass {
    
    typealias PassTarget = Module
    static let minOptLevel: OptLevel = .low
    static let name = "inline"
    
    /// Inline functions in `module`
    /// - note: entrypoint for the inline pass
    static func run(on module: Module) throws {
        try module.functions.forEach(run(on:))
    }
    
    /// Run the inline opt on `function`
    private static func run(on function: Function) throws {
        // if we have already inlined this function, don't attempt to do it again
        //  - this prevents cyclic inlining & unnecessary work for scanning an
        //    already optimised block
        guard !function.hasHadInline else { return }
        // Mark as inlined
        function.hasHadInline = true
        
        // run the inline pass
        try runInline(on: function)
        
        // if it marked that it wants to go again, do it
        if !function.hasHadInline {
            try runInline(on: function)
        }
    }
    
    /// Run the inline without checking whether the function body wants it
    private static func runInline(on function: Function) throws {
        for inst in function.instructions {
            
            let function: Function
            let call: VIRFunctionCall
            
            if case let callInst as FunctionCallInst = inst {
                function = callInst.function
                call = callInst
            }
            else if case let applyInst as FunctionApplyInst = inst, let fn = applyInst.getAppliedFunction() {
                function = fn
                call = applyInst
            }
            else {
                continue
            }
            
            guard function.inlineRequirement != .never else { continue }
            
            // ...inline the called function's body first...
            try run(on: function)
            // ...then inline this call.
            var explosion = Explosion(replacing: call)
            if try inline(call, calledFunction: function, explosion: &explosion) {
                // If it was inlined, replace the inst with the explosion
                try explosion.replaceInst()
            }
        }
    }
    
    /// - returns: whether the call was inlined
    static func inline(_ call: VIRFunctionCall, calledFunction: Function, explosion: inout Explosion) throws -> Bool {
        
        // Can we inline this call?
        // FIXME: Inlining multi block functions. (May need a dom tree analysis pass to do this)
        guard calledFunction.isInlineable, calledFunction.shouldInline(at: .high) else {
            return false
        }
        
        let block = calledFunction.blocks![0]
        var alreadyInlined: [String: Value] = [:]
        
        // Add params
        for (arg, param) in zip(call.functionArgs, block.parameters ?? []) {
            alreadyInlined[param.name] = arg.value!
        }
        
        /// Get the inlined value to replace the original inst's operand
        func getValue(replacing val: Operand) -> Value {
            return alreadyInlined[val.name] // get the operand from the list of inlined vals
                ?? val.value!.copy() // if its not in the block (it's a literal and) we can copy it as is
        }
        
        // Forward pass through block insts
        // FIXME: Should be through dominator tree in a multi block
        for sourceInst in block.instructions {
            
            // Create a copy of the instruction
            let inlinedInst = sourceInst.copy()
            // ...and record it by name
            alreadyInlined[sourceInst.name] = inlinedInst
            
            switch inlinedInst {
                // return insts simply want passing out as the tail of the inlined vals.
                // Its users are fixed at the end of the explosion's inlining
            case let returnInst as ReturnInst:
                let args = returnInst.args
                let inlinedRetVal = getValue(replacing: returnInst.returnValue)
                for arg in args {
                    arg.value = nil; arg.user = nil
                }
                explosion.insertTail(inlinedRetVal)
                break // return must be last inst in block
                
            default:
                // fix-up the user of the inst's args
                inlinedInst.setInstArgs(args: inlinedInst.args.map { arg in
                    let operand = arg.formCopy(nullValue: true)
                    let v = getValue(replacing: arg)
                    arg.value = nil; arg.user = nil
                    operand.value = v
                    operand.user = inlinedInst
                    return operand
                })
                // Modify name of inlined var (just to make it more descriptive)
                // "%var" --> "%demangled.var"
                if let n = inlinedInst.irName {
                    inlinedInst.irName = "\(calledFunction.name.demangleName()).\(n)"
                }
                
                // Add the inst
                explosion.insert(inst: inlinedInst)
            }
            
            // if we inlined an apply, we can try inlining again
            if inlinedInst is FunctionApplyInst {
                call.parentFunction?.hasHadInline = false
            }
            
        }
        
        return true
    }
}

private extension Function {
    
    /// Can we inline this function?
    var isInlineable: Bool {
        return blocks.map { $0.count <= 1 } ?? false
    }
    
    // TODO: Determine whether this function is favourable to inline
    /// Do we want to inline this function at `optLevel`
    func shouldInline(at optLevel: OptLevel) -> Bool {
        return true
    }
}

private extension FunctionApplyInst {
    func getAppliedFunction() -> Function? {
        switch function.value {
        case let ref as FunctionRef:
            return ref.function
        case let refInst as FunctionRefInst:
            return (refInst.function.value as? FunctionRef).map { $0.function }
        default:
            return nil
        }
    }
}
