//
//  Verify.swift
//  Vist
//
//  Created by Josef Willsher on 16/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension Module {
    
    func verify() throws {
        for function in functions where function.hasBody {
            try function.verify()
        }
    }
}

extension Function {
    
    func verify() throws {
        guard let blocks = blocks else { return  }
        
        for block in blocks {
            for inst in block.instructions {
                // check operands are alive
                for arg in inst.args {
                    
                    guard let val = arg.value else {
                        throw VIRVerifierError.nilArg(in: inst)
                    }
                    guard let parent = val.parentFunction else {
                        if val is VoidLiteralValue || val is GlobalValue { continue }
                        throw VIRVerifierError.nilParentFunction(of: inst)
                    }
                    guard parent == val.parentFunction || arg.value is VoidLiteralValue else {
                        throw VIRVerifierError.crossFunctionArg(inst: inst, arg: val, otherFn: val.parentFunction)
                    }
                }
                // check the users are alive
                for use in inst.uses {
                    
                    guard let user = use.user else {
                        throw VIRVerifierError.nilUser(of: inst)
                    }
                    guard let parent = user.parentFunction else {
                        throw VIRVerifierError.nilParentFunctionOfUser(of: inst)
                    }
                    guard parent == user.parentFunction else {
                        throw VIRVerifierError.crossFunctionArg(inst: user, arg: inst, otherFn: inst.parentFunction)
                    }
                    assert(use.user != nil,
                           "\(inst.valueName) : \(inst.dynamicType) has a null user")
                    assert(use.user?.parentFunction == self,
                           "\(inst.valueName) : \(inst.dynamicType) is referenced from another function ('\(use.user?.parentFunction?.name ?? "nil")')")
                }
            }
            
            // check the block's exit is a control flow inst
            if let last = block.instructions.last {
                guard last.isTerminator else {
                    throw VIRVerifierError.notTerminator(last)
                }
                // TODO: Proper comparison of inst types -- `!=` checks for conformance
                //       and is not an equality operations
                if case let ret as ReturnInst = last, ret.returnValue.type != ret.parentFunction?.type.returns {
                    throw VIRVerifierError.mismatchedReturn(last)
                }
    
            }
        }

    }
}

enum VIRVerifierError : VistError {
    
    case nilArg(in: Inst), nilParentFunction(of: Inst)
    case crossFunctionArg(inst: Inst, arg: Value, otherFn: Function?)
    
    case nilUser(of: Inst), nilParentFunctionOfUser(of: Inst)
    
    case notTerminator(Inst), mismatchedReturn(Inst)
    
    var description: String {
        let errorInst: Inst
        let message: String
        
        switch self {
        case .nilArg(let inst):
            errorInst = inst
            message = "inst has nil operand"
        case .nilParentFunction(let inst):
            errorInst = inst
            message = "inst has no parent function"
        case .crossFunctionArg(let inst, let arg, let otherFn):
            errorInst = inst
            message = "inst has arg '\(arg.valueName)' which references value in other function '\(otherFn?.name)'"
            
        case .nilUser(let inst):
            errorInst = inst
            message = "inst had nil user"
        case .nilParentFunctionOfUser(let inst):
            errorInst = inst
            message = "inst's user has no parent function"
            
        case .notTerminator(let inst):
            errorInst = inst
            message = "last inst in a block must be a terminator"
        case .mismatchedReturn(let inst):
            errorInst = inst
            message = "function return has wrong type"
        }
        
        let fn = (errorInst.parentFunction?.vir ?? "").components(separatedBy: "\n").joined(separator: "\n\t~ ")
        return "\n\nVIR verification failed: \(message)\nError in instruction:\n\t\(errorInst.vir)\nError in function:\n\(fn)"
    }
    
}




