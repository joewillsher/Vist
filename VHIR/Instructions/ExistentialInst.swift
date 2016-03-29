//
//  ExistentialInst.swift
//  Vist
//
//  Created by Josef Willsher on 26/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Opening an existential box to extract a member
final class ExistentialPropertyInst: InstBase {
    var value: PtrOperand
    let propertyName: String, existentialType: ConceptType
    
    override var type: Ty? { return try? existentialType.propertyType(propertyName) }
    
    private init(value: PtrOperand, propertyName: String, existentialType: ConceptType, irName: String?) {
        self.value = value
        self.propertyName = propertyName
        self.existentialType = existentialType
        super.init(args: [value], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = existential_open \(value.valueName) #\(propertyName) \(useComment)"
    }
}

/// Constructing an existential box from a struct.
///
/// When lowered it calculates the metadata for offsets and constructs
/// the struct's witness table
final class ExistentialConstructInst: InstBase {
    var value: PtrOperand, existentialType: ConceptType
    
    override var type: Ty? { return existentialType.usingTypesIn(module) }
    
    private init(value: PtrOperand, existentialType: ConceptType, irName: String?) {
        self.value = value
        self.existentialType = existentialType
        super.init(args: [value], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = existential_box \(value.valueName) as %\(existentialType.name) \(useComment)"
    }
    
}

//final class ExistentialWitnessMethodInst: InstBase {
//    var value: PtrOperand
//    
//    override var type: Ty? { return value.type }
//    
//    private init(value: Operand, irName: String?) {
//        self.value = value
//        super.init(args: [value], irName: irName)
//    }
//    
//    override var instVHIR: String {
//        return "\(name) = existential_witness \(value.valueName) #\(propertyName) \(useComment)"
//    }
//    
//}

extension Builder {
    
    func buildOpenExistential(value: PtrOperand, propertyName: String, irName: String? = nil) throws -> ExistentialPropertyInst {
        guard case let alias as TypeAlias = value.memType, case let existentialType as ConceptType = alias.targetType else { fatalError() }
        return try _add(ExistentialPropertyInst(value: value, propertyName: propertyName, existentialType: existentialType, irName: irName))
    }
    /// Builds an existential from a definite object.
    func buildExistentialBox(value: PtrOperand, existentialType: ConceptType, irName: String? = nil) throws -> ExistentialConstructInst {
        return try _add(ExistentialConstructInst(value: value, existentialType: existentialType, irName: irName))
    }
}

