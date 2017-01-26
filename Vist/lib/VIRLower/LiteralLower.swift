//
//  LiteralLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension IntLiteralInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        return LLVMValue.constInt(value: value, size: size)
    }
}
extension BoolLiteralInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        return LLVMValue.constBool(value: value)
    }
}

extension StringLiteralInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let str = try igf.builder.buildGlobalString(value: value)
        return try igf.builder.buildBitcast(value: str, to: .opaquePointer)
    }
}

