//
//  TypeLowering.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol LLVMTyped : Printable {
    func ir() throws -> LLVMTypeRef
}


enum LLVMType : LLVMTyped {
    case Null, Void
    case Int(size: UInt32), Float(size: UInt32), Bool
    indirect case Array(el: LLVMTyped, size: UInt32)
    indirect case Pointer(to: LLVMTyped)
    indirect case Struct(members: [LLVMType], methods: [LLVMFnType])
    
    // TODO: Implement Tuple types
    
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
        case .Struct(let members, _):
            let arr = try members
                .map { try $0.ir() }
                .ptr()
                                        return LLVMStructType(arr, UInt32(members.count), LLVMBool(false))
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

struct LLVMFnType : LLVMTyped {
    let params: [LLVMType]
    let returns: LLVMTyped
    
    func ir() throws -> LLVMTypeRef {
        return LLVMFunctionType(
            try returns.ir(),
            try params.map{try $0.ir()}.ptr(),
            UInt32(params.count),
            LLVMBool(false))
    }
}


extension LLVMType : CustomStringConvertible {
    
    var description: String {
        switch self {
        case .Null:                     return "Null"
        case .Void:                     return "Void"
        case .Int(let s):               return "Int\(s)"
        case Bool:                      return "Bool"
        case .Array(let el, let size):  return "[\(size) x \(el)"
        case .Pointer(let to):          return "\(to)*"
        case .Float(let s):
            switch s {
            case 16:                    return "Half"
            case 32:                    return "Float"
            case 64:                    return "Double"
            case 128:                   return "FP128"
            default:                    return ""
            }
        case .Struct(let members, _):
            let arr = members
                .map { $0.description }
                .joinWithSeparator(", ")
                                        return "Struct(\(arr))"
        }
    }
}





