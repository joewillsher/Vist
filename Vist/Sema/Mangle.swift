//
//  Mangle.swift
//  Vist
//
//  Created by Josef Willsher on 04/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation


extension String {
    
    func mangle(type: LLVMFnType, parentTypeName: String? = nil) -> String {
        return "_\(sansUnderscores())_\(type.debugDescription)"
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



extension LLVMType : CustomStringConvertible, CustomDebugStringConvertible {
    
    var description: String {
        switch self {
        case .Null:                     return "Null"
        case .Void:                     return "Void"
        case .Int(let s):               return "Int\(s)"
        case .Bool:                     return "Bool"
        case .Array(let el, let size):  return "[\(size) x \(el)]"
        case .Pointer(let to):          return "\(to)*"
        case .Float(let s):
            switch s {
            case 16:                    return "Half"
            case 32:                    return "Float"
            case 64:                    return "Double"
            case 128:                   return "FP128"
            default:                    return "<<invalid type>>"
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
        case .Float(let s):             return "FP\(s)"
        }
    }
}

extension LLVMStType : CustomStringConvertible, CustomDebugStringConvertible {
    
    var description: String {
        let arr = members
            .map { $0.1.description }
            .joinWithSeparator(", ")
        return "Struct(\(arr))"
    }
    
    var debugDescription: String {
        let arr = members
            .map { $0.1.debugDescription }
            .joinWithSeparator(".")
        return "S.\(arr)"
    }
}

extension LLVMFnType : CustomDebugStringConvertible {
    
    var debugDescription: String {
        
        var str = ""
        
        for p in params {
            str += "\(p.debugDescription)"
        }
        
        return str
    }
    
}
