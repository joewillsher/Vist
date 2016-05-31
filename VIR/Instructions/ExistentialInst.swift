//
//  ExistentialInst.swift
//  Vist
//
//  Created by Josef Willsher on 26/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Opening an existential box to get a pointer to a member
final class OpenExistentialPropertyInst: InstBase, LValue {
    var existential: PtrOperand
    let propertyName: String, existentialType: ConceptType
    
    var propertyType: Type { return try! existentialType.propertyType(propertyName) }
    
    var memType: Type? { return propertyType }
    override var type: Type? { return BuiltinType.pointer(to: propertyType) }
    
    init(existential: LValue, propertyName: String, irName: String? = nil) throws {
        
        guard let existentialType = try existential.memType?.getAsConceptType() else { fatalError() }
        
        let op = PtrOperand(existential)
        self.existential = op
        self.propertyName = propertyName
        self.existentialType = existentialType
        super.init(args: [op], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential_open \(existential.valueName), !\(propertyName) \(useComment)"
    }
}

/// Constructing an existential box from a struct.
///
/// When lowered it calculates the metadata for offsets and constructs
/// the struct's witness table
final class ExistentialConstructInst : InstBase {
    var value: PtrOperand, existentialType: ConceptType
    
    override var type: Type? { return existentialType.usingTypesIn(module) }
    
    private init(value: PtrOperand, existentialType: ConceptType, irName: String?) {
        self.value = value
        self.existentialType = existentialType
        super.init(args: [value], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential \(value.valueName) in #\(existentialType.explicitName) \(useComment)"
    }
    
}

final class ExistentialWitnessInst : InstBase, LValue {
    var existential: PtrOperand
    let methodName: String, argTypes: [Type], existentialType: ConceptType
    
    var methodType: FunctionType? { return try? existentialType.methodType(methodNamed: methodName, argTypes: argTypes) }
    override var type: Type? { return memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return methodType }
    
    private init(existential: PtrOperand, methodName: String, argTypes: [Type], existentialType: ConceptType, irName: String?) {
        self.existential = existential
        self.methodName = methodName
        self.existentialType = existentialType
        self.argTypes = argTypes
        super.init(args: [existential], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential_witness \(existential.valueName), !\(methodName) \(useComment)"
    }
    
}

/// Get the instance from the existential box, an i8*
final class ExistentialProjectInst : InstBase, LValue {
    var existential: PtrOperand
    
    override var type: Type? { return BuiltinType.opaquePointer }
    var memType: Type? { return BuiltinType.int(size: 8) }
    
    private init(existential: PtrOperand, irName: String?) {
        self.existential = existential
        super.init(args: [existential], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential_project \(existential.valueName) \(useComment)"
    }
    
}


extension Builder {
    
    /// Builds an existential from a definite object.
    func buildExistentialBox(value: PtrOperand, existentialType: ConceptType, irName: String? = nil) throws -> ExistentialConstructInst {
        return try _add(ExistentialConstructInst(value: value, existentialType: existentialType, irName: irName))
    }
    /// Builds an existential from a definite object.
    func buildExistentialWitnessMethod(existential: PtrOperand, methodName: String, argTypes: [Type], existentialType: ConceptType, irName: String? = nil) throws -> ExistentialWitnessInst {
        return try _add(ExistentialWitnessInst(existential: existential, methodName: methodName, argTypes: argTypes, existentialType: existentialType, irName: irName))
    }
    func buildExistentialUnbox(value: PtrOperand, irName: String? = nil) throws -> ExistentialProjectInst {
        return try _add(ExistentialProjectInst(existential: value, irName: irName))
    }

}

