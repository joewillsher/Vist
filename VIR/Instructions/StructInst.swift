//
//  StructInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/**
 Construct a struct object
 
 `%a = struct_init %Range, (%1:%Int, %2:$Int)`
 */
final class StructInitInst : Inst {
    
    var type: Type? { return module.getOrInsert(type: structType) }
    var structType: StructType
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(type: StructType, values: Value..., irName: String? = nil) {
        self.init(type: type, operands: values.map(Operand.init), irName: irName)
    }
    init(type: StructType, operands: [Operand], irName: String?) {
        self.structType = type
        self.args = operands
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = struct %\(structType.name), \(args.virValueTuple())\(useComment)"
    }
    
    func copy() -> StructInitInst {
        return StructInitInst(type: structType, operands: args.map { $0.formCopy() }, irName: irName)
    }
    
    var parentBlock: BasicBlock?
    var irName: String?
}


/**
 Extract an element from a struct -- this is loads the element
 
 - SeeAlso: StructElementPtrInst gets the ptr to an element of
            a struct reference
 
 `%a = struct_extract %1:%Range, !start`
 */
final class StructExtractInst : Inst {
    
    var object: Operand, propertyName: String
    var propertyType: Type, structType: StructType
    
    var uses: [Operand] = []
    var args: [Operand]
    
    /// - Precondition: `structType` is a `StructType` or `TypeAlias` storing a `StructType`
    /// - Precondition: `structType` has a member `property`
    /// - Note: The initialised StructExtractInst has the same type as the `property`
    ///         element of `structType`
    convenience init(object: Value, property: String, irName: String? = nil) throws {
        // get the underlying struct type
        guard let structType = try object.type?.getAsStructType() else {
            throw VIRError.noType(#file)
        }
        let propType = try structType.propertyType(name: property)
        
        self.init(object: Operand(object), property: property, structType: structType, propertyType: propType, irName: irName)
    }
    private init(object: Operand, property: String, structType: StructType, propertyType: Type, irName: String?) {
        self.object = object
        self.propertyName = property
        self.propertyType = propertyType
        self.structType = structType
        self.args = [object]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return propertyType }
    
    var vir: String {
        return "\(name) = struct_extract \(object.vir), !\(propertyName)\(useComment)"
    }
    
    func copy() -> StructExtractInst {
        return StructExtractInst(object: object.formCopy(), property: propertyName, structType: structType, propertyType: propertyType, irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        object = args[0]
    }
    
    var parentBlock: BasicBlock?
    var irName: String?
}


final class StructElementPtrInst : Inst, LValue {
    var object: PtrOperand, propertyName: String
    var propertyType: Type, structType: StructType
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(object: LValue, property: String, irName: String? = nil) throws {
        
        // get the underlying struct type
        guard let structType = try object.memType?.getAsStructType() else {
            throw VIRError.noType(#file)
        }
        let propertyType = try structType.propertyType(name: property)
        self.init(object: PtrOperand(object), property: property, structType: structType, propertyType: propertyType, irName: irName)
    }
    private init(object: PtrOperand, property: String, structType: StructType, propertyType: Type, irName: String?) {
        self.object = object
        self.propertyName = property
        self.propertyType = propertyType
        self.structType = structType
        self.args = [object]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return BuiltinType.pointer(to: propertyType) }
    var memType: Type? { return propertyType }
    
    var vir: String {
        return "\(name) = struct_element \(object.vir), !\(propertyName)\(useComment)"
    }
    
    func copy() -> StructElementPtrInst {
        return StructElementPtrInst(object: object.formCopy(), property: propertyName, structType: structType, propertyType: propertyType, irName: irName)
    }
    func setArgs(_ args: [Operand]) {
        object = args[0] as! PtrOperand
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

/// Project the instance ptr of a reference counted class box
final class ClassProjectInstanceInst : Inst, LValue {
    var object: PtrOperand
    var classType: ClassType
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(object: LValue, irName: String? = nil) throws {
        // get the underlying struct type
        guard let classType = try object.memType?.getAsClassType() else {
            throw VIRError.noType(#file)
        }
        self.init(object: PtrOperand(object), classType: classType, irName: irName)
    }
    private init(object: PtrOperand, classType: ClassType, irName: String?) {
        self.object = object
        self.classType = classType
        self.args = [object]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return BuiltinType.pointer(to: classType.storedType) }
    var memType: Type? { return classType.storedType }
    
    var vir: String {
        return "\(name) = class_project_instance \(object.vir)\(useComment)"
    }
    
    func copy() -> ClassProjectInstanceInst {
        return ClassProjectInstanceInst(object: object.formCopy(), classType: classType, irName: irName)
    }
    func setArgs(_ args: [Operand]) {
        object = args[0] as! PtrOperand
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

