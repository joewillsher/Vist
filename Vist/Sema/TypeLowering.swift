//
//  TypeLowering.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol LLVMTyped : Printable, CustomDebugStringConvertible {
    func ir() throws -> LLVMTypeRef
}


enum LLVMType : LLVMTyped {
    case Null, Void
    case Int(size: UInt32), Float(size: UInt32), Bool
    indirect case Array(el: LLVMTyped, size: UInt32?)
    indirect case Pointer(to: LLVMTyped)
    // TODO: Implement Tuple types (as struct)
    
    func ir() throws -> LLVMTypeRef {
        switch self {
        case .Null:                     return nil
        case .Void:                     return LLVMVoidType()
        case .Int(let s):               return LLVMIntType(s)
        case Bool:                      return LLVMInt1Type()
        case .Array(let el, let size):  return LLVMArrayType(try el.ir(), size ?? 0)
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
        case "String": self = .Array(el: LLVMType.Int(size: 8), size: nil)
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
    
    func ir() throws -> LLVMTypeRef {
        
        let r: LLVMTypeRef
        if let _ = returns as? LLVMFnType {
            r = try LLVMType.Pointer(to: returns).ir()
        } else {
            r = try returns.ir()
        }
        
        return LLVMFunctionType(
            r,
            try nonVoid.map{try $0.ir()}.ptr(),
            UInt32(nonVoid.count),
            LLVMBool(false))
    }
    
    
    var nonVoid: [LLVMTyped]  {
        return params.filter { if case LLVMType.Void = $0 { return false } else { return true } }
    }
}

extension LLVMFnType {
    
    static func fn(name: String, typeSignature: String) throws -> (String, LLVMFnType) {
        var l = Lexer(code: "func \(name): \(typeSignature)")
        var p = Parser(tokens: try l.getTokens())
        
        var a = try p.parse()
        try variableTypeSema(forScopeExpression: &a)
        let f = a.expressions[0] as! FunctionPrototypeExpression
        let t = f.fnType.type as! LLVMFnType
        
        return (name, t)
    }
    
}


final class LLVMStType : LLVMTyped {
    let members: [(String, LLVMType, Bool)]
    let methods: [(String, LLVMFnType)]
    
    init(members: [(String, LLVMType, Bool)], methods: [(String, LLVMFnType)]) {
        self.members = members
        self.methods = methods
    }
    
    func ir() throws -> LLVMTypeRef {
        let arr = try members
            .map { try $0.1.ir() }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            LLVMBool(false))
    }
    
    func propertyType(name: String) throws -> LLVMType? {
        guard let i = (members.indexOf { $0.0 == name }) else { throw SemaError.NoPropertyNamed(name) }
        return members[i].1
    }
}



func ir(val: LLVMTyped) throws -> LLVMValueRef {
    return try val.ir()
}


@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: T, rhs: T)
    -> Bool {
        let l = (try? lhs.ir()), r = (try? rhs.ir())
        if let l = l, let r = r { return l == r } else { return false }
}
@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: LLVMTyped?, rhs: T)
    -> Bool {
        let l = (try? lhs?.ir()), r = (try? rhs.ir())
        if let l = l, let r = r { return l == r } else { return false }
}
@warn_unused_result
func ==
    (lhs: LLVMTyped, rhs: LLVMTyped)
    -> Bool {
        let l = (try? lhs.ir()), r = (try? rhs.ir())
        if let l = l, let r = r { return l == r } else { return false }
}
@warn_unused_result
func ==
    (lhs: [LLVMTyped], rhs: [LLVMTyped])
    -> Bool {
        if lhs.count != rhs.count { return false }
        
        for (l,r) in zip(lhs,rhs) {
            let ll = (try? l.ir()), rr = (try? r.ir())
            if let l = ll, let r = rr where l == r { return true }
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

