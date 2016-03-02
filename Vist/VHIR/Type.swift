//
//  Type.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


class TypeAlias: Ty {
    var name: String
    var targetType: StorageType
    
    func lowerType(module: Module) -> LLVMTypeRef {
        return targetType.lowerType(module)
    }
    
    init(name: String, targetType: StorageType) {
        self.name = name
        self.targetType = targetType
    }
    
    var mangledName: String { return name }
}


