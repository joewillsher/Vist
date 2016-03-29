//
//  ExistentialInst.swift
//  Vist
//
//  Created by Josef Willsher on 26/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Opening an existential box to extract a member
final class ExistentialPropertyInst: InstBase {
    var existential: PtrOperand
    let propertyName: String, existentialType: ConceptType
    
    override var type: Ty? { return try? existentialType.propertyType(propertyName) }
    
    private init(existential: PtrOperand, propertyName: String, existentialType: ConceptType, irName: String?) {
        self.existential = existential
        self.propertyName = propertyName
        self.existentialType = existentialType
        super.init(args: [existential], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = existential_open \(existential.valueName) #\(propertyName) \(useComment)"
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
        return "\(name) = existential_box \(value.valueName) in %\(existentialType.name) \(useComment)"
    }
    
}

final class ExistentialWitnessMethodInst: InstBase, LValue {
    var existential: PtrOperand
    let methodName: String, argTypes: [Ty], existentialType: ConceptType
    
    var methodType: FnType? { return existentialType.getMethodType(methodName, argTypes: argTypes) }
    override var type: Ty? { return memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Ty? { return methodType }
    
    private init(existential: PtrOperand, methodName: String, argTypes: [Ty], existentialType: ConceptType, irName: String?) {
        self.existential = existential
        self.methodName = methodName
        self.existentialType = existentialType
        self.argTypes = argTypes
        super.init(args: [existential], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = existential_witness \(existential.valueName) #\(methodName) \(useComment)"
    }
    
}

extension Builder {
    
    func buildOpenExistential(value: PtrOperand, propertyName: String, irName: String? = nil) throws -> ExistentialPropertyInst {
        guard case let alias as TypeAlias = value.memType, case let existentialType as ConceptType = alias.targetType else { fatalError() }
        return try _add(ExistentialPropertyInst(existential: value, propertyName: propertyName, existentialType: existentialType, irName: irName))
    }
    /// Builds an existential from a definite object.
    func buildExistentialBox(value: PtrOperand, existentialType: ConceptType, irName: String? = nil) throws -> ExistentialConstructInst {
        return try _add(ExistentialConstructInst(value: value, existentialType: existentialType, irName: irName))
    }
    /// Builds an existential from a definite object.
    func buildExistentialWitnessMethod(existential: PtrOperand, methodName: String, argTypes: [Ty], existentialType: ConceptType, irName: String? = nil) throws -> ExistentialWitnessMethodInst {
        return try _add(ExistentialWitnessMethodInst(existential: existential, methodName: methodName, argTypes: argTypes, existentialType: existentialType, irName: irName))
    }
}

