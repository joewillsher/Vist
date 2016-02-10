//
//  ConceptType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct ConceptType : StorageType {
    
    let name: String
    let requiredFunctions: [StructMethod], requiredProperties: [StructMember]
    
    /// a pointer to array of self's properties' implementation indecies in the conformant
    /// followed by an opaque pointer to the conformant
    func ir() -> LLVMTypeRef {
        return StructType.withTypes([
            BuiltinType.Array(el: BuiltinType.Int(size: 32), size: UInt32(requiredProperties.count)),
            BuiltinType.OpaquePointer
            ]).ir()
    }
        
    var debugDescription: String {
        return name
    }
    
    var mangledTypeName: String {
        return "\(name).ex.ty"
    }
    
    var members: [StructMember] {
        return requiredProperties
    }
    
    var methods: [StructMethod] {
        return requiredFunctions
    }

}

