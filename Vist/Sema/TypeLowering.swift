//
//  TypeLowering.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol LLVMTyped : Printable, CustomDebugStringConvertible {
    func ir() -> LLVMTypeRef
    
    var isStdBool: Bool { get }
    var isStdInt: Bool { get }
    var isStdRange: Bool { get }
}

extension LLVMTyped {
    var isStdBool: Bool {
        return false
    }
    var isStdInt: Bool {
        return false
    }
    var isStdRange: Bool {
        return false
    }
}


enum LLVMType : LLVMTyped {
    case Null, Void
    case Int(size: UInt32), Float(size: UInt32), Bool
    indirect case Array(el: LLVMTyped, size: UInt32?)
    indirect case Pointer(to: LLVMTyped)
    // TODO: Implement Tuple types (as struct)
    
    func ir() -> LLVMTypeRef {
        switch self {
        case .Null:                     return nil
        case .Void:                     return LLVMVoidType()
        case .Int(let s):               return LLVMIntType(s)
        case Bool:                      return LLVMInt1Type()
        case .Array(let el, let size):  return LLVMArrayType(el.ir(), size ?? 0)
        case .Pointer(let to):          return LLVMPointerType(to.ir(), 0)
        case .Float(let s):
            switch s {
            case 16:                    return LLVMHalfType()
            case 32:                    return LLVMFloatType()
            case 64:                    return LLVMDoubleType()
            case 128:                   return LLVMFP128Type()
            default:                    fatalError("Invalid float type")
            }
        }
    }
    
    init?(_ str: String) {
        switch str {
        case "LLVM.Int", "LLVM.Int64":  self = .Int(size: 64)
        case "LLVM.Int32":              self = .Int(size: 32)
        case "LLVM.Int16":              self = .Int(size: 16)
        case "LLVM.Int8":               self = .Int(size: 8)
        case "LLVM.Bool":               self = .Bool
        case "LLVM.Double":             self = .Float(size: 64)
        case "LLVM.Float":              self = .Float(size: 32)
        case "Void":                    self = .Void
        case "LLVM.String":             self = .Array(el: LLVMType.Int(size: 8), size: nil)
        case _ where str.characters.first == "[" && str.characters.last == "]":
            guard let el = LLVMType(String(str.characters.dropFirst().dropLast())) else { return nil }
                                        self = .Array(el: el, size: nil)
            // hack: array type IR has no size which is wrong
        default: return nil
        }
    }
}

struct LLVMFnType : LLVMTyped {
    let params: [LLVMTyped]
    let returns: LLVMTyped
    
    func ir() -> LLVMTypeRef {
        
        let r: LLVMTypeRef
        if let _ = returns as? LLVMFnType {
            r = LLVMType.Pointer(to: returns).ir()
        }
        else {
            r = returns.ir()
        }
        
        return LLVMFunctionType(
            r,
            nonVoid.map{$0.ir()}.ptr(),
            UInt32(nonVoid.count),
            LLVMBool(false))
    }
    
    
    var nonVoid: [LLVMTyped]  {
        return params.filter { if case LLVMType.Void = $0 { return false } else { return true } }
    }
}


final class LLVMStType : LLVMTyped {
    let name: String
    let members: [(String, LLVMTyped, Bool)]
    let methods: [(String, LLVMFnType)]
    
    init(members: [(String, LLVMTyped, Bool)], methods: [(String, LLVMFnType)], name: String) {
        self.name = name
        self.members = members
        self.methods = methods
    }
    
    func ir() -> LLVMTypeRef {
        let arr = members
            .map { $0.1.ir() }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            LLVMBool(false))
    }
    
    func propertyType(name: String) throws -> LLVMTyped? {
        guard let i = (members.indexOf { $0.0 == name }) else { throw SemaError.NoPropertyNamed(name) }
        return members[i].1
    }
    
    static func named(n: String) -> LLVMStType { return LLVMStType(members: [], methods: [], name: n) }
    static func withProperties(ps: [LLVMTyped], gen: (Int -> String) = { _ in ""}) -> LLVMStType { return LLVMStType(members: ps.enumerate().map {(gen($0), $1, false)}, methods: [], name: "") }
    
    var isStdBool: Bool {
        return name == "Bool" && members[0].0 == "value"
    }
    var isStdInt: Bool {
        return name == "Int" && members[0].0 == "value"
    }
    var isStdRange: Bool {
        return name == "Range" && members[0].0 == "start" && members[1].0 == "end"
    }
}

@warn_unused_result
func == (lhs: LLVMStType, rhs: LLVMStType) -> Bool {
    return lhs.name == rhs.name
}



func ir(val: LLVMTyped) throws -> LLVMValueRef {
    return val.ir()
}


@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: T, rhs: T)
    -> Bool {
        return lhs.ir() == rhs.ir()
}
@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: LLVMTyped?, rhs: T)
    -> Bool {
        return lhs?.ir() == rhs.ir()
}
@warn_unused_result
func ==
    (lhs: LLVMTyped, rhs: LLVMTyped)
    -> Bool {
        return lhs.ir() == rhs.ir()
}
@warn_unused_result
func ==
    (lhs: [LLVMTyped], rhs: [LLVMTyped])
    -> Bool {
        if lhs.isEmpty && rhs.isEmpty { return true }
        if lhs.count != rhs.count { return false }
        
        for (l,r) in zip(lhs,rhs) {
            if l == r { return true }
        }
        return false
}
extension CollectionType {
    func mapAs<T>(_: T.Type) -> [T] {
        return flatMap { $0 as? T }
    }
}


extension LLVMType : Equatable {}
extension LLVMFnType : Equatable {}

