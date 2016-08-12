//
//  ExistentialInst.swift
//  Vist
//
//  Created by Josef Willsher on 26/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Opening an existential box to get a pointer to a member
final class OpenExistentialPropertyInst: Inst, LValue {
    var existential: PtrOperand
    let propertyName: String, existentialType: ConceptType
    
    var propertyType: Type { return try! existentialType.propertyType(name: propertyName) }
    
    var memType: Type? { return propertyType }
    var type: Type? { return BuiltinType.pointer(to: propertyType) }
    
    var uses: [Operand] = []
    var args: [Operand]
    
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
        self.args = [existential]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = existential_open \(existential.valueName), !\(propertyName)\(useComment)"
    }
    
    func copy() -> OpenExistentialPropertyInst {
        return OpenExistentialPropertyInst(existential: existential.formCopy(), propertyName: propertyName, existentialType: existentialType, irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        existential = args[0] as! PtrOperand
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

/// Constructing an existential box from a struct.
///
/// When lowered it calculates the metadata for offsets and constructs
/// the struct's witness table
final class ExistentialConstructInst : Inst {
    var value: PtrOperand, existentialType: ConceptType
    
    var type: Type? { return existentialType.importedType(in: module) }
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(value: LValue, existentialType: ConceptType, irName: String? = nil) {
        self.init(value: PtrOperand(value), existentialType: existentialType, irName: irName)
    }
    
    private init(value: PtrOperand, existentialType: ConceptType, irName: String?) {
        self.value = value
        self.existentialType = existentialType
        self.args = [value]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = existential \(value.valueName) in #\(existentialType.explicitName)\(useComment)"
    }
    
    func copy() -> ExistentialConstructInst {
        return ExistentialConstructInst(value: value.formCopy(), existentialType: existentialType, irName: irName)
    }
    func setArgs(_ args: [Operand]) {
        value = args[0] as! PtrOperand
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

final class ExistentialWitnessInst : Inst, LValue {
    var existential: PtrOperand
    let methodName: String, argTypes: [Type], existentialType: ConceptType
    
    var methodType: FunctionType? { return existentialType.methods.first(where: {$0.name == methodName})?.type }
    var type: Type? { return memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return methodType }
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(existential: LValue, methodName: String, argTypes: [Type], existentialType: ConceptType, irName: String? = nil) {
        self.init(existential: PtrOperand(existential), methodName: methodName, argTypes: argTypes, existentialType: existentialType, irName: irName)
    }
    
    private init(existential: PtrOperand, methodName: String, argTypes: [Type], existentialType: ConceptType, irName: String?) {
        self.existential = existential
        self.methodName = methodName
        self.existentialType = existentialType
        self.argTypes = argTypes
        self.args = [existential]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = existential_witness \(existential.valueName), !\(methodName)\(useComment)"
    }
    
    func copy() -> ExistentialWitnessInst {
        return ExistentialWitnessInst(existential: existential.formCopy(), methodName: methodName, argTypes: argTypes, existentialType: existentialType, irName: irName)
    }
    func setArgs(_ args: [Operand]) {
        existential = args[0] as! PtrOperand
    }
    
    var parentBlock: BasicBlock?
    var irName: String?
}

/// Get the instance from the existential box, an i8*
final class ExistentialProjectInst : Inst, LValue {
    var existential: PtrOperand
    
    var type: Type? { return BuiltinType.opaquePointer }
    var memType: Type? { return BuiltinType.int(size: 8) }
    
    var uses: [Operand] = []
    var args: [Operand] = []
    
    convenience init(existential: LValue, irName: String? = nil) {
        self.init(existential: PtrOperand(existential), irName: irName)
    }
    
    private init(existential: PtrOperand, irName: String?) {
        self.existential = existential
        self.args = [existential]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = existential_project \(existential.valueName)\(useComment)"
    }
    
    func copy() -> ExistentialProjectInst {
        return ExistentialProjectInst(existential: existential.formCopy(), irName: irName)
    }
    func setArgs(_ args: [Operand]) {
        existential = args[0] as! PtrOperand
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

