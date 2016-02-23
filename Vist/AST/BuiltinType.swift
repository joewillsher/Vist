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
    
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef {
        switch self {
        case .null:                     return nil
        case .void:                     return LLVMVoidType()
        case .int(let s):               return LLVMIntType(s)
        case .bool:                      return LLVMInt1Type()
        case .array(let el, let size):  return LLVMArrayType(el.globalType(module), size ?? 0)
        case .pointer(let to):          return LLVMPointerType(to.globalType(module), 0)
        case .opaquePointer:            return BuiltinType.pointer(to: BuiltinType.int(size: 8)).globalType(module)
        case .float(let s):
            switch s {
            case 16:                    return LLVMHalfType()
            case 32:                    return LLVMFloatType()
            case 64:                    return LLVMDoubleType()
            case 128:                   return LLVMFP128Type()
            default:                    fatalError(SemaError.invalidFloatType(s).description)
            }
        }
    }
    
    init?(_ str: String) {
        switch str {
        case "LLVM.Int", "LLVM.Int64":  self = .int(size: 64)
        case "LLVM.Null":               self = .null
        case "LLVM.Int32":              self = .int(size: 32)
        case "LLVM.Int16":              self = .int(size: 16)
        case "LLVM.Int8":               self = .int(size: 8)
        case "LLVM.Bool":               self = .bool
        case "LLVM.Double":             self = .float(size: 64)
        case "LLVM.Float":              self = .float(size: 32)
        case "Void":                    self = .void
        case "LLVM.String":             self = .array(el: BuiltinType.int(size: 8), size: nil)
        case _ where str.characters.first == "[" && str.characters.last == "]":
            guard let el = BuiltinType(String(str.characters.dropFirst().dropLast())) else { return nil }
            self = .array(el: el, size: nil)
            // hack: array type IR has no size which is wrong
        default: return nil
        }
    }
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

    
    var explicitName: String {
        switch self {
        case .null:                     return "LLVM.Null"
        case .void:                     return "LLVM.Void"
        case .int(let s):               return "LLVM.Int\(s)"
        case .bool:                     return "LLVM.Bool"
        case .array(let el, let size):  return "[\(size) x \(el.mangledName)]" // not implemented
        case .pointer(let to):          return "\(to.mangledName)*"            // will never be implemented
        case .opaquePointer:            return "ptr"
        case .float(let s):
            switch s {
            case 16:                    return "LLVM.Half"
            case 32:                    return "LLVM.Float"
            case 64:                    return "LLVM.Double"
            case 128:                   return "LLVM.FP128"
            default:                    fatalError("Bad float type")
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
        return { val in
            return LLVMConstInt(BuiltinType.int(size: UInt32(size)).globalType(nil), val, false)
        }
    }
    static func intGen(value: Swift.Int, size: Swift.Int) -> LLVMValueRef {
        return intGen(size: size)(UInt64(value))
    }
}
