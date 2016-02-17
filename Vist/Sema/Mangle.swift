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
        return "_\(n)\(sansUnderscores())_\(type.mangledName)"
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

