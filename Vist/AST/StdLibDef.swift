//
//  StdLibDef.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct StdLibDef {
    
    private static let stdLibFunctions: [String: (BuiltinType, BuiltinType)] = [
        "print".mangle([BuiltinType.Int(size: 64)])    : (.Int(size: 64), .Void),
        "print".mangle([BuiltinType.Bool])             : (.Bool, .Void),
        "print".mangle([BuiltinType.Float(size: 64)])  : (.Float(size: 64), .Void),
        "print".mangle([BuiltinType.Float(size: 32)])  : (.Float(size: 32), .Void)
    ]
    
    private static func getFunction(param: BuiltinType, res: BuiltinType) -> FnType {
        return FnType(params: [param], returns: res)
    }
    
    
    static func getBuiltinFunction(id: String, args: [Ty]) -> (String, FnType)? {
        
        
        
        return nil
    }
    
}

