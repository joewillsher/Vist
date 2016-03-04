//
//  TypeAlias.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


class TypeAlias: Ty {
    var name: String
    var targetType: StorageType
    
    func lowerType(module: Module) -> LLVMTypeRef {
        if module.loweredModule == nil { return targetType.lowerType(module) }
        
        let found = getNamedType(targetType.irName, module.loweredModule)
        if found != nil { return found }
        
        let type = targetType.lowerType(module)
        let namedType = createNamedType(type, targetType.irName)
        
        return namedType
    }
    
    init(name: String, targetType: StorageType) {
        self.name = name
        self.targetType = targetType
    }
    
    var mangledName: String { return name }
}


