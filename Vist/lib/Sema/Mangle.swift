//
//  Mangle.swift
//  Vist
//
//  Created by Josef Willsher on 04/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSString

extension String {
    
    func mangle(type: FunctionType) -> String {
        return "_V\(mappedChars())_\(type.mangledName)"
    }
//    func mangle(params type: [Type]) -> String {
//        return mangle(type: FunctionType(params: type, returns: BuiltinType.void/*Doesnt matter*/))
//    }
    
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
        ("/", "S"),
        ("~", "T"),
        ("^", "R"),
        ("%", "C"),
        (".", "D"),
        ("!", "B"),
    ]
    
    private func mappedChars() -> String {
        var resStr: [Character] = []
        
        for c in characters {
            if let replacement = String.mangleMap.index(where: {$0.0 == c}) {
                resStr.append("-")
                resStr.append(String.mangleMap[replacement].1)
            }
            else {
                resStr.append(c)
            }
        }
        return String(resStr)
    }
    
    /// returns the raw name, getting rid of type info at end, 
    /// (and type prefix for methods)
    func demangleName() -> String {
        // is this a mangled string
        guard hasPrefix("_V") else { return self }
        let r = characters.index(characters.startIndex, offsetBy: 2)
        let consider = characters.suffix(from: r)
        guard let ui = consider.index(of: "_") else { return self }
        let nameString = String(consider[consider.startIndex..<ui])
        
        var resStr: [Character] = []
        var pred: Character? = nil
        
        for c in nameString.characters {
            if c != "-" {
                if let original = String.mangleMap.index(where: {$0.1 == c}), pred == "-" {
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
        guard hasPrefix("_V") else { return self }
        return replacingOccurrences(of: "$", with: "-")
    }
    
}

