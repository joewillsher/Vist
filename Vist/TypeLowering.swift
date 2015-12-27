//
//  TypeLowering.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol LLVMTypedIR {
    func ir() throws -> LLVMTypeRef
}


enum LLVMType : LLVMTypedIR {
    case Null, Void
    case Int(size: UInt32), Float(size: UInt32), Bool
    indirect case Array(el: LLVMType, size: UInt32), Pointer(to: LLVMType)
    
    func ir() throws -> LLVMTypeRef {
        switch self {
        case .Null:                     return nil
        case .Void:                     return LLVMVoidType()
        case .Int(let s):               return LLVMIntType(s)
        case Bool:                      return LLVMInt1Type()
        case .Array(let el, let size):  return LLVMArrayType(try el.ir(), size)
        case .Pointer(let to):          return LLVMPointerType(try to.ir(), 0)
        case .Float(let s):
            switch s {
            case 16:                    return LLVMHalfType()
            case 32:                    return LLVMFloatType()
            case 64:                    return LLVMDoubleType()
            case 128:                   return LLVMFP128Type()
            default:                    throw SemaError.InvalidType(self)
            }
        }
    }
    
    init?(_ str: String) {
        switch str {
        case "Int", "Int64": self = .Int(size: 64)
        case "Int32": self = .Int(size: 32)
        case "Int16": self = .Int(size: 16)
        case "Int8": self = .Int(size: 8)
        case "Bool": self = .Bool
        case "Double": self = .Float(size: 64)
        case "Float": self = .Float(size: 32)
        case "Void": self = .Void
        default: return nil
        }
    }
}

struct LLVMFnType : LLVMTypedIR {
    let params: [LLVMType]
    let returns: LLVMType
    
    func ir() throws -> LLVMTypeRef {
        return LLVMFunctionType(
            try returns.ir(),
            try params.map{try $0.ir()}.ptr(),
            UInt32(params.count),
            LLVMBool(false))
    }
}

