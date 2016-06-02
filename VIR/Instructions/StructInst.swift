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
    
    init(type: StructType, values: Value..., irName: String? = nil) {
        self.structType = type
        super.init(args: values.map(Operand.init), irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = struct %\(structType.name), \(args.virValueTuple()) \(useComment)"
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
    init(object: Value, property: String, irName: String? = nil) throws {
        
        // get the underlying struct type
        guard let structType = try object.type?.getAsStructType() else {
            throw VIRError.noType(#file)
        }
        
        self.object = Operand(object)
        self.propertyName = property
        self.propertyType = try structType.propertyType(name: property)
        self.structType = structType
        super.init(args: [self.object], irName: irName)
    }
    
    override var type: Type? { return propertyType }
    
    override var instVIR: String {
        return "\(name) = struct_extract \(object.vir), !\(propertyName) \(useComment)"
    }
}


final class StructElementPtrInst : InstBase, LValue {
    var object: PtrOperand, propertyName: String
    var propertyType: Type, structType: StructType
    
    init(object: LValue, property: String, irName: String? = nil) throws {
        
        // get the underlying struct type
        guard let structType = try object.memType?.getAsStructType() else {
            throw VIRError.noType(#file)
        }
        
        self.object = PtrOperand(object)
        self.propertyName = property
        self.propertyType = try structType.propertyType(name: property)
        self.structType = structType
        super.init(args: [self.object], irName: irName)
    }
    
    override var type: Type? { return BuiltinType.pointer(to: propertyType) }
    var memType: Type? { return propertyType }
    
    override var instVIR: String {
        return "\(name) = struct_element \(object.vir), !\(propertyName) \(useComment)"
    }
}

