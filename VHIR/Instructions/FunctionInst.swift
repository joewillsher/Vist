//
//  FunctionInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


enum FunctionCallRef {
    case direct(Function)
    case pointer(PtrOperand)
    
    var name: String {
        switch self {
        case .direct(let function): return "@\(function.name)"
        case .pointer(let ptr): return ptr.name
        }
    }
    var loweredValue: LLVMValueRef {
        switch self {
        case .direct(let function): return LLVMGetNamedFunction(function.module.loweredModule, name)
        case .pointer(let ptr): return ptr.loweredValue
        }
    }
    var type: FnType {
        switch self {
        case .direct(let function): return function.type
        case .pointer(let ptr): return ptr.memType as! FnType
        }
    }
}

final class FunctionCallInst: InstBase {
    var function: FunctionCallRef
    var returnType: Ty
    
    override var type: Ty? { return returnType }
    
    private init(function: FunctionCallRef, returnType: Ty, args: [Operand], irName: String?) {
        self.function = function
        self.returnType = returnType
        super.init(args: args, irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = call \(function.name) \(args.vhirValueTuple()) \(useComment)"
    }
    
    override var hasSideEffects: Bool { return true }
}


extension Builder {
    
    func buildFunctionCall(function: Function, args: [Operand], irName: String? = nil) throws -> FunctionCallInst {
        return try _add(FunctionCallInst(function: .direct(function), returnType: function.type.returns, args: args, irName: irName))
    }

    func buildFunctionCall(function: PtrOperand, returnType: Ty, args: [Operand], irName: String? = nil) throws -> FunctionCallInst {
        return try _add(FunctionCallInst(function: .pointer(function), returnType: returnType, args: args, irName: irName))
    }
}