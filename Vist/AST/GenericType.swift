//
//  GenericType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//




struct GenericType : StorageType {
    
    let name: String
    /// Concepts this generic type implements
    let concepts: [ConceptType] 
    
    
    var members: [StructMember] {
        return concepts.flatMap { $0.requiredProperties }
    }
    
    var methods: [StructMethod] {
        return concepts.flatMap { $0.requiredFunctions }
    }
    
    
    
    
    func ir() -> LLVMTypeRef {
        return nil
    }
    
    var debugDescription: String {
        return name
    }
}



extension StructType {
    
    func models(concept: ConceptType) -> Bool {
        for f in concept.requiredFunctions where !methods.contains({ $0.name == f.name && $0.type == f.type }) { return false }
        for p in concept.requiredProperties where !members.contains({ $0.name == p.name && $0.type == p.type }) { return false }
        return true
    }
}

func specialisationModelsConcepts(type: StructType, generic: GenericType) -> Bool {
    for c in generic.concepts where !type.models(c) { return false }
    return true
}

struct GenericSignature {
    
    let genericTypes: [GenericType]
    
    private func validGenericSpecialisation(types: [StructType]) -> Bool {
        return !zip(types, genericTypes).map(specialisationModelsConcepts).contains(false)
    }
    
    func specialiseTypeSignatureFrom(types: [StructType]) throws -> Ty {
        
        guard validGenericSpecialisation(types) else { throw error(SemaError.GenericSubstitutionInvalid) }
        
        
        
        
        return types.first!
    }

    
    func specialiseFunctionSignatureFrom(types: [StructType]) throws -> Ty {
        
        guard validGenericSpecialisation(types) else { throw error(SemaError.GenericSubstitutionInvalid) }
        
        return types.first!
    }

}



