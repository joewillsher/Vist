//
//  OperandLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension Operand: VIRLower {
    
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        // if already lowered, we use that
        if let loweredValue = loweredValue {
            return loweredValue
        }
            // otherwise we lower it to LLVM IR
        else if case let lowerable as VIRLower = value {
            let v = try lowerable.virLower(&IGF)
            setLoweredValue(v)
            return v
        }
            // if it can't be lowered, throw an error
        else {
            throw error(IRLowerError.notLowerable(self))
        }
    }
}
