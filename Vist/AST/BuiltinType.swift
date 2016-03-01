//
//  BuiltinType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



enum BuiltinType: Ty {
    case null, void
    case int(size: UInt32), float(size: UInt32), bool
    indirect case array(el: Ty, size: UInt32?)
    indirect case pointer(to: Ty)
    case opaquePointer
    
    init?(_ type: LLVMTypeRef) {
        switch type {
        case LLVMVoidType(): self = .void
        case LLVMInt32Type(): self = .int(size: 32)
        case LLVMInt64Type(): self = .int(size: 64)
        case LLVMInt1Type(): self = .bool
        case LLVMDoubleType(): self = .float(size: 64)
        case LLVMFloatType(): self = .float(size: 32)
        default: return nil
        }
    }

    init?(_ str: String) {
        switch str {
        case "Builtin.Int", "Builtin.Int64":  self = .int(size: 64)
        case "Builtin.Null":               self = .null
        case "Builtin.Int32":              self = .int(size: 32)
        case "Builtin.Int16":              self = .int(size: 16)
        case "Builtin.Int8":               self = .int(size: 8)
        case "Builtin.Bool":               self = .bool
        case "Builtin.Double":             self = .float(size: 64)
        case "Builtin.Float":              self = .float(size: 32)
        case "Void":                       self = .void
        case "Builtin.String":             self = .array(el: BuiltinType.int(size: 8), size: nil)
        case _ where str.characters.first == "[" && str.characters.last == "]":
            guard let el = BuiltinType(String(str.characters.dropFirst().dropLast())) else { return nil }
            self = .array(el: el, size: nil)
            // hack: array type IR has no size which is wrong
        default: return nil
        }
    }
    
    var explicitName: String {
        switch self {
        case .null:                     return "Builtin.Null"
        case .void:                     return "Builtin.Void"
        case .int(let s):               return "Builtin.Int\(s)"
        case .bool:                     return "Builtin.Bool"
        case .array(let el, let size):  return "[\(size) x \(el.mangledName)]" // not implemented
        case .pointer(let to):          return "\(to.mangledName)*"            // will never be implemented
        case .opaquePointer:            return "ptr"
        case .float(let s):
            switch s {
            case 16:                    return "Builtin.Half"
            case 32:                    return "Builtin.Float"
            case 64:                    return "Builtin.Double"
            case 128:                   return "Builtin.FP128"
            default:                    fatalError(SemaError.invalidFloatType(s).description)
            }
        }
    }
    
    var mangledName: String {
        switch self {
        case .null:                     return "N"
        case .void:                     return "V"
        case .int(let s):               return "i\(s)"
        case .bool:                     return "b"
        case .array(let el, _):         return "A\(el.mangledName)"
        case .pointer(let to):          return "P\(to.mangledName)"
        case .float(let s):             return "f\(s)"
        case .opaquePointer:            return "op"
        }
    }
    
    static func intGen(size size: Swift.Int) -> UInt64 -> LLVMValueRef {
        fatalError("TODO: shouldnt be reachable as working on VHIR")
    }
    static func intGen(value: Swift.Int, size: Swift.Int) -> LLVMValueRef {
        fatalError("TODO: shouldnt be reachable as working on VHIR")
    }
}
