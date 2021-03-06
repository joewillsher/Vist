//
//  GenericType.swift
//  Vist
//
//  Created by Josef Willsher on 09/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class GenericType : NominalType {
    
    let name: String
    /// Concepts this generic type implements
    var concepts: [ConceptType]
    let parentName: String
    let isHeapAllocated = false
    
    init(name: String, concepts: [ConceptType], parentName: String) {
        self.name = name
        self.concepts = concepts
        self.parentName = parentName
    }
    
    static func fromConstraint(inScope scope: SemaScope) -> (ConstrainedType) throws -> GenericType {
        return { ty in
            if let c = ty.constraints.optionalMap({ scope.concept(named: $0) }) {
                return GenericType(name: ty.name, concepts: c, parentName: ty.parentName)
            }
            else {
                throw semaError(.paramsNotTyped)
            }
        }
    }
    
    var members: [StructMember] {
        return concepts.flatMap { $0.requiredProperties }
    }
    
    var methods: [StructMethod] {
        return concepts.flatMap { $0.requiredFunctions }
    }
    
    func lowered(module: Module) -> LLVMType {
        fatalError("implement this")
    }
    
    func importedType(in module: Module) -> Type {
        return GenericType(name: name, concepts: concepts.map { $0.importedType(in: module) as! ConceptType }, parentName: parentName)
    }
    
    var irName: String {
        return "\(parentName)\(name)"
    }
    
    var mangledName: String {
        return name
    }
    func machineType() -> AIRType { fatalError() }
}




