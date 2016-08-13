//
//  WitnessTable.swift
//  Vist
//
//  Created by Josef Willsher on 12/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class VIRWitnessTable : VIRElement {
    let type: NominalType
    let concept: ConceptType
    
    var loweredMetadata: LLVMValue!
    
    static func create(module: Module, type concrete: NominalType, conforms concept: ConceptType) -> VIRWitnessTable {
        
        // if the module already has this
        if let found = module.witnessTables.first(where: {
            $0.type.name == concrete.name && $0.concept.name == concept.name
        }) {
            return found
        }
        let table = VIRWitnessTable(type: concrete, conforms: concept)
        module.witnessTables.append(table)
        return table
    }
    
    private init(type concrete: NominalType, conforms concept: ConceptType) {
        
        self.type = concrete
        self.concept = concept
        
        for conceptFn in concept.requiredFunctions {
            let witness = concrete.methods.first(where: { $0.name.demangleName() == conceptFn.name.demangleName() && $0.type == conceptFn.type })!
            table[conceptFn.name] = witness.name
        }
    }
    
    /// maps concept-method-name : witness-method-name
    private var table: [String: String] = [:]
    
    func getWitness(name: String, module: Module) throws -> PtrOperand {
        guard let witness = table[name] else { fatalError("No witness recorded") }
        guard let function = module.function(named: witness) else { fatalError("Undefined witness") }
        return function.buildFunctionPointer()
    }
    func getOffset(name: String, module: Module) throws -> Int {
        let index = type.members.index(where: { $0.name == name })!
        return type.lowered(module: module).offsetOfElement(at: index, module: module.loweredModule)
    }
    
    var vir: String {
        return "witness_table \(type.name) conforms \(concept.name) {\n" +
               table.map { "  #\($0.key) : @\($0.value)" }.joined(separator: "\n") +
               "\n}"
    }
    
}

final class VIRConceptConformance {
    
    
    
}



