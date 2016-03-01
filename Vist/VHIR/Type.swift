//
//  Type.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


class TypeAlias: Ty {
    var name: String
    var targetType: Ty
    
    init(name: String, targetType: Ty) {
        self.name = name
        self.targetType = targetType
    }
    
    var vhir: String { return "type %\(name) = \(targetType.vhir)" }
    var mangledName: String { return name }
}


