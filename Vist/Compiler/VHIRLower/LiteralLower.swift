//
//  LiteralLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation.NSString

extension IntLiteralInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), UInt64(value.value), false)
    }
}
extension BoolLiteralInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMConstInt(type!.lowerType(module), value.value ? 1 : 0, false)
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
    var numberOfCodeUnits: Int {
        switch encoding {
        case .utf8: return utf8.count
        case .utf16: return utf16.count
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

extension StringLiteralInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let str = LLVMBuildGlobalString(irGen.builder, value.value, "")
        return LLVMBuildBitCast(irGen.builder, str, BuiltinType.opaquePointer.lowerType(module), irName ?? "")
    }
}


extension StructInitInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard case let t as TypeAlias = type else { throw irGenError(.notStructType) }
        var val = LLVMGetUndef(t.lowerType(module))
        
        for (i, el) in args.enumerate() {
            val = LLVMBuildInsertValue(irGen.builder, val, el.loweredValue, UInt32(i), irName ?? "")
        }
        
        return val
    }
}
