//
//  Mangle.swift
//  Vist
//
//  Created by Josef Willsher on 04/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation


extension String {
    
    func mangle(type: FnType, parentTypeName: String? = nil) -> String {
        let n = parentTypeName == nil ? "" : "\(parentTypeName!)."
        return "_\(n)\(sansUnderscores())_\(type.debugDescription)"
    }
    func mangle(type: [Ty], parentTypeName: String? = nil) -> String {
        return mangle(FnType(params: type, returns: BuiltinType.Void/*Doesnt matter*/), parentTypeName: parentTypeName)
    }
    
    
    func sansUnderscores() -> String {
        return stringByReplacingOccurrencesOfString("_", withString: "$")
    }
    
    // TODO: Add globalinit to mangled names for initalisers
    func demangleName() -> String {
        let kk = characters.dropFirst()
        return String(kk.prefixUpTo(kk.indexOf("_")!))
            .stringByReplacingOccurrencesOfString("$", withString: "_")
    }
}

func implicitParamName<I : IntegerType>(n: I) -> String { return "$\(n)"}

extension IntegerType {
    func implicitParamName() -> String { return "$\(self)"}
}

extension BuiltinType : CustomStringConvertible, CustomDebugStringConvertible {
    
    var description: String {
        switch self {
        case .Null:                     return "LLVM.Null"
        case .Void:                     return "LLVM.Void"
        case .Int(let s):               return "LLVM.Int\(s)"
        case .Bool:                     return "LLVM.Bool"
        case .Array(let el, let size):  return "[\(size) x \(el)]" // not implemented
        case .Pointer(let to):          return "\(to)*"            // will never be implemented
        case .Float(let s):
            switch s {
            case 16:                    return "LLVM.Half"
            case 32:                    return "LLVM.Float"
            case 64:                    return "LLVM.Double"
            case 128:                   return "LLVM.FP128"
            default:                    fatalError("Bad float type")
            }
        }
    }
    
    var debugDescription: String {
        switch self {
        case .Null:                     return "N"
        case .Void:                     return "V"
        case .Int(let s):               return "i\(s)"
        case Bool:                      return "b"
        case .Array(let el, _):         return "A\(el.debugDescription)"
        case .Pointer(let to):          return "P\(to.debugDescription)"
        case .Float(let s):             return "f\(s)"
        }
    }
}

extension StructType: CustomStringConvertible, CustomDebugStringConvertible {
    
    var description: String {
        return name
    }
    
    var debugDescription: String {
        let arr = members
            .map { $0.1.debugDescription }
            .joinWithSeparator(".")
        return "S.\(arr)"
    }
}

extension FnType: CustomDebugStringConvertible {
    
    var debugDescription: String {
        return params
            .map { $0.debugDescription }
            .joinWithSeparator("_")
    }
}

extension TupleType {
    
    var description: String {
        let u = members.map { $0.description }
        return "(" + u.joinWithSeparator(", ") + ")"
    }
    
    var debugDescription: String {
        let arr = members
            .map { $0.debugDescription }
            .joinWithSeparator(".")
        return "S.\(arr)"
    }
}

