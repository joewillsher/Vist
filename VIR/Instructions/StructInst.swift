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
final class StructInitInst : InstBase {
    
    override var type: Type? { return module.getOrInsert(type: structType) }
    var structType: StructType
    
    convenience init(type: StructType, values: Value..., irName: String? = nil) {
        self.init(type: type, operands: values.map(Operand.init), irName: irName)
    }
    private init(type: StructType, operands: [Operand], irName: String?) {
        self.structType = type
        super.init(args: operands, irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = struct %\(structType.name), \(args.virValueTuple())\(useComment)"
    }
    
    override func copyInst() -> StructInitInst {
        return StructInitInst(type: structType, operands: args.map { $0.formCopy() }, irName: irName)
    }
}


/**
 Extract an element from a struct -- this is loads the element
 
 - SeeAlso: StructElementPtrInst gets the ptr to an element of
            a struct reference
 
 `%a = struct_extract %1:%Range, !start`
 */
final class StructExtractInst : InstBase {
    
    var object: Operand, propertyName: String
    var propertyType: Type, structType: StructType
    
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
        
        super.init(args: [self.object], irName: irName)
    }
    
    override var type: Type? { return propertyType }
    
    override var instVIR: String {
        return "\(name) = struct_extract \(object.vir), !\(propertyName)\(useComment)"
    }
    
    override func copyInst() -> StructExtractInst {
        return StructExtractInst(object: object.formCopy(), property: propertyName, structType: structType, propertyType: propertyType, irName: irName)
    }
    
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        object = args[0]
    }
}


final class StructElementPtrInst : InstBase, LValue {
    var object: PtrOperand, propertyName: String
    var propertyType: Type, structType: StructType
    
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
        super.init(args: [object], irName: irName)
    }
    
    override var type: Type? { return BuiltinType.pointer(to: propertyType) }
    var memType: Type? { return propertyType }
    
    override var instVIR: String {
        return "\(name) = struct_element \(object.vir), !\(propertyName)\(useComment)"
    }
    
    override func copyInst() -> StructElementPtrInst {
        return StructElementPtrInst(object: object.formCopy(), property: propertyName, structType: structType, propertyType: propertyType, irName: irName)
    }
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        object = args[0] as! PtrOperand
    }
}

