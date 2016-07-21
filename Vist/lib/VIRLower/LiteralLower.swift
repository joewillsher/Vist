//
//  LiteralLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation.NSString

extension IntLiteralInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return LLVMValue.constInt(value: value, size: size)
    }
}
extension BoolLiteralInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        return LLVMValue.constBool(value: value)
    }
}

extension StringLiteralInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let str = try IGF.builder.buildGlobalString(value: value)
        return try IGF.builder.buildBitcast(value: str, to: BuiltinType.opaquePointer.lowered(module: module))
    }
}

