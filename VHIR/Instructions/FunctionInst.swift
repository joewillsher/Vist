//
//  FunctionInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol VHIRFunctionCall : Inst, VHIRLower {
    var functionRef: LLVMValueRef { get }
    var functionType: FnType { get }
}


final class FunctionCallInst: InstBase, VHIRFunctionCall {
    var function: Function
    var returnType: Ty
    
    override var type: Ty? { return returnType }
    
    private init(function: Function, returnType: Ty, args: [Operand], irName: String?) {
        self.function = function
        self.returnType = returnType
        super.init(args: args, irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = call @\(function.name) \(args.vhirValueTuple()) \(useComment)"
    }
    override var hasSideEffects: Bool { return true }
    
    var functionRef: LLVMValueRef { return function.loweredFunction }
    var functionType: FnType { return function.type }
}

final class FunctionApplyInst: InstBase, VHIRFunctionCall {
    var function: PtrOperand
    var returnType: Ty
    
    override var type: Ty? { return returnType }
    
    private init(function: PtrOperand, returnType: Ty, args: [Operand], irName: String?) {
        self.function = function
        self.returnType = returnType
        super.init(args: args, irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = apply \(function.name) \(args.vhirValueTuple()) \(useComment)"
    }
    override var hasSideEffects: Bool { return true }
    
    var functionRef: LLVMValueRef { return function.loweredValue }
    var functionType: FnType { return function.memType as! FnType }
}


extension Builder {
    
    /// Calls a SIL function with given args
    func buildFunctionCall(function: Function, args: [Operand], irName: String? = nil) throws -> FunctionCallInst {
        return try _add(FunctionCallInst(function: function, returnType: function.type.returns, args: args, irName: irName))
    }
    /// Applies the args to a function ref
    func buildFunctionApply(function: PtrOperand, returnType: Ty, args: [Operand], irName: String? = nil) throws -> FunctionApplyInst {
        return try _add(FunctionApplyInst(function: function, returnType: returnType, args: args, irName: irName))
    }
}