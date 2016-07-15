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
    
    var propertyType: Type { return try! existentialType.propertyType(name: propertyName) }
    
    var memType: Type? { return propertyType }
    override var type: Type? { return BuiltinType.pointer(to: propertyType) }
    
    convenience init(existential: LValue, propertyName: String, irName: String? = nil) throws {
        
        guard let existentialType = try existential.memType?.getAsConceptType() else {
            fatalError("todo throw -- not existential type")
        }
        self.init(existential: PtrOperand(existential), propertyName: propertyName, existentialType: existentialType, irName: irName)
    }
    
    private init(existential: PtrOperand, propertyName: String, existentialType: ConceptType, irName: String?) {
        self.existential = existential
        self.propertyName = propertyName
        self.existentialType = existentialType
        super.init(args: [existential], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential_open \(existential.valueName), !\(propertyName)\(useComment)"
    }
    
    override func copyInst() -> OpenExistentialPropertyInst {
        return OpenExistentialPropertyInst(existential: existential.formCopy(), propertyName: propertyName, existentialType: existentialType, irName: irName)
    }
    
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        existential = args[0] as! PtrOperand
    }
}

/// Constructing an existential box from a struct.
///
/// When lowered it calculates the metadata for offsets and constructs
/// the struct's witness table
final class ExistentialConstructInst : InstBase {
    var value: PtrOperand, existentialType: ConceptType
    
    override var type: Type? { return existentialType.importedType(in: module) }
    
    convenience init(value: LValue, existentialType: ConceptType, irName: String? = nil) {
        self.init(value: PtrOperand(value), existentialType: existentialType, irName: irName)
    }
    
    private init(value: PtrOperand, existentialType: ConceptType, irName: String?) {
        self.value = value
        self.existentialType = existentialType
        super.init(args: [value], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential \(value.valueName) in #\(existentialType.explicitName)\(useComment)"
    }
    
    override func copyInst() -> ExistentialConstructInst {
        return ExistentialConstructInst(value: value.formCopy(), existentialType: existentialType, irName: irName)
    }
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        value = args[0] as! PtrOperand
    }
}

final class ExistentialWitnessInst : InstBase, LValue {
    var existential: PtrOperand
    let methodName: String, argTypes: [Type], existentialType: ConceptType
    
    var methodType: FunctionType? { return try? existentialType.methodType(methodNamed: methodName, argTypes: argTypes) }
    override var type: Type? { return memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return methodType }
    
    convenience init(existential: LValue, methodName: String, argTypes: [Type], existentialType: ConceptType, irName: String? = nil) {
        self.init(existential: PtrOperand(existential), methodName: methodName, argTypes: argTypes, existentialType: existentialType, irName: irName)
    }
    
    private init(existential: PtrOperand, methodName: String, argTypes: [Type], existentialType: ConceptType, irName: String?) {
        self.existential = existential
        self.methodName = methodName
        self.existentialType = existentialType
        self.argTypes = argTypes
        super.init(args: [existential], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential_witness \(existential.valueName), !\(methodName)\(useComment)"
    }
    
    override func copyInst() -> ExistentialWitnessInst {
        return ExistentialWitnessInst(existential: existential.formCopy(), methodName: methodName, argTypes: argTypes, existentialType: existentialType, irName: irName)
    }
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        existential = args[0] as! PtrOperand
    }
}

/// Get the instance from the existential box, an i8*
final class ExistentialProjectInst : InstBase, LValue {
    var existential: PtrOperand
    
    override var type: Type? { return BuiltinType.opaquePointer }
    var memType: Type? { return BuiltinType.int(size: 8) }
    
    convenience init(existential: LValue, irName: String? = nil) {
        self.init(existential: PtrOperand(existential), irName: irName)
    }

    private init(existential: PtrOperand, irName: String?) {
        self.existential = existential
        super.init(args: [existential], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = existential_project \(existential.valueName)\(useComment)"
    }
    
    override func copyInst() -> ExistentialProjectInst {
        return ExistentialProjectInst(existential: existential.formCopy(), irName: irName)
    }
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        existential = args[0] as! PtrOperand
    }
}

