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
        return "\(n)\(mappedChars())_\(type.mangledName)"
    }
    func mangle(type: [Ty], parentTypeName: String? = nil) -> String {
        return mangle(FnType(params: type, returns: BuiltinType.Void/*Doesnt matter*/), parentTypeName: parentTypeName)
    }
    
    private static var mangleMap: [(Character, Character)] = [
        ("_", "U"),
        ("-", "M"),
        ("+", "P"),
        ("|", "O"),
        ("&", "N"),
        ("$", "V"),
        ("*", "A"),
        ("<", "L"),
        (">", "G"),
        ("=", "E"),
        ("/", "D")
    ]
    
    private func mappedChars() -> String {
        var resStr: [Character] = []
        
        for c in characters {
            if let replacement = String.mangleMap.indexOf({$0.0 == c}) {
                resStr.append("-")
                resStr.append(String.mangleMap[replacement].1)
            }
            else {
                resStr.append(c)
            }
        }
        return String(resStr)
    }
    
    func demangleName() -> String {
        let name = String(characters.prefixUpTo(characters.indexOf("_")!))
        var resStr: [Character] = []
        var pred: Character? = nil
        
        for c in name.characters {
            
            if c != "-" {
                if let original = String.mangleMap.indexOf({$0.1 == c}) where pred == "-" {
                    resStr.append(String.mangleMap[original].0)
                } else {
                    resStr.append(c)
                }
            }
            
            pred = c
        }
        
        return String(resStr)
    }
    
    func demangleRuntimeName() -> String {
        return String(characters.prefixUpTo(characters.indexOf("_") ?? characters.startIndex)).stringByReplacingOccurrencesOfString("$", withString: "_")
    }
    
}

func implicitParamName<I: IntegerType>(n: I) -> String { return "$\(n)"}

extension IntegerType {
    func implicitParamName() -> String { return "$\(self)"}
}

