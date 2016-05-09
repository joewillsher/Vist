//
//  LiteralLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation.NSString

extension IntLiteralInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        return LLVMValue.constInt(value.value, size: size)
    }
}
extension BoolLiteralInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        return LLVMValue.constBool(value.value)
    }
}

extension String {
    
    enum Encoding : Int { case utf8 = 1, utf16 = 2 }
    
    var encoding: Encoding {
        switch smallestEncoding {
        case NSUTF16StringEncoding: return .utf16
        default: return .utf8
        }
    }
}
extension String.Encoding : CustomStringConvertible {
    var description: String {
        switch self {
        case .utf8: return "utf8"
        case .utf16: return "utf16"
        }
    }
}

extension StringLiteralInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        let str = try IGF.builder.buildGlobalString(value.value)
        return try IGF.builder.buildBitcast(value: str, to: BuiltinType.opaquePointer.lowerType(module))
    }
}

