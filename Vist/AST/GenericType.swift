//
//  GenericType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct Concept {
    let name: String
    let requiredFunctions: [StructMethod] = [], requiredProperties: [StructMember] = []
}

extension StructType {
    
    func models(concept: Concept) -> Bool {
        for f in concept.requiredFunctions where !methods.contains({ $0.name == f.name && $0.type == f.type }) { return false }
        for p in concept.requiredProperties where !members.contains({ $0.name == p.name && $0.type == p.type }) { return false }
        return true
    }
}

func specialisationModelsConcepts(type: StructType, generic: GenericType) -> Bool {
    for c in generic.concepts where !type.models(c) { return false }
    return true
}


struct GenericType : Ty {
    
    let placeholderName: String
    /// Concepts this generic type implements
    let concepts: [Concept] = []
    
    
    
    
    
    
    func ir() -> LLVMTypeRef {
        return nil
    }
    
    var debugDescription: String {
        return placeholderName
    }
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



