//
//  BuiltinType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



enum BuiltinType : Type {
    case null, void
    case int(size: Int), float(size: Int), bool
    indirect case array(el: Type, size: Int?)
    indirect case pointer(to: Type)
    case opaquePointer
    
    func lowered(module: Module) -> LLVMType {
        switch self {
        case .null:                     return .null
        case .void:                     return .void
        case .int(let s):               return .intType(size: s)
        case .bool:                     return .bool
        case .array(let el, let size):  return .arrayType(element: el.lowered(module: module), size: size ?? 0)
        case .pointer(let to):          return to.lowered(module: module).getPointerType()
        case .opaquePointer:            return .opaquePointer
        case .float(let s):
            switch s {
            case 16:                    return .half
            case 32:                    return .single
            case 64:                    return .double
//            case 128:                   return LLVMFP128Type()
            default:                    fatalError(SemaError.invalidFloatType(s).description)
            }
        }
    }

    
    init?(_ str: String) {
        switch str {
        case "Builtin.Int", "Builtin.Int64":self = .int(size: 64)
        case "Builtin.Null":               self = .null
        case "Builtin.Int32":              self = .int(size: 32)
        case "Builtin.Int16":              self = .int(size: 16)
        case "Builtin.Int8":               self = .int(size: 8)
        case "Builtin.Bool":               self = .bool
        case "Builtin.Double":             self = .float(size: 64)
        case "Builtin.Float":              self = .float(size: 32)
        case "Void":                       self = .void
        case "Builtin.OpaquePointer":      self = .opaquePointer
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
        case .array(let el, let size):  return "[\(size) x \(el.explicitName)]" // not implemented
        case .pointer(let to):          return "*\(to.explicitName)"
        case .opaquePointer:            return "Builtin.OpaquePointer"
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
    
    func importedType(inModule module: Module) -> Type {
        switch self {
        case .pointer(let pointee): return BuiltinType.pointer(to: pointee.importedType(inModule: module))
        default: return self
        }
    }
    
    func isInModule() -> Bool {
        switch self {
        case .pointer(let to):
            return to.isInModule()
        default:
            return true
        }
    }
}

extension BuiltinType : Equatable { }

@warn_unused_result
func == (lhs: BuiltinType, rhs: BuiltinType) -> Bool {
    return lhs.explicitName == rhs.explicitName
}

