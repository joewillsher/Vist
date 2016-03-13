//
//  StructInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class StructInitInst: InstBase {
    
    override var type: Ty? { return module.getOrInsertAliasTo(structType) }
    var structType: StructType
    
    private init(type: StructType, args: [Operand], irName: String? = nil) {
        self.structType = type
//        super.init(args: args, uses: [], irName: irName)
        super.init()
        self.args = args
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = struct %\(type!.explicitName) \(args.vhirValueTuple()) \(useComment)"
    }
}

final class StructExtractInst: InstBase {
    
    override var type: Ty? { return propertyType }
    var object: Operand, propertyName: String
    var propertyType: Ty, structType: StructType
    
    private init(object: Operand, property: String, propertyType: Ty, structType: StructType, irName: String? = nil) {
        self.object = object
        self.propertyName = property
        self.propertyType = propertyType
        self.structType = structType
        super.init()
        self.args = [object]
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = struct_extract \(object.vhir), #\(structType.explicitName).\(propertyName) \(useComment)"
    }
}


extension Builder {
    func buildStructInit(type: StructType, values: Operand..., irName: String? = nil) throws -> StructInitInst {
        let s = StructInitInst(type: type, args: values, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
    func buildEmptyStruct(type: StructType, irName: String? = nil) throws -> StructInitInst {
        let s = StructInitInst(type: type, args: [], irName: irName)
        try addToCurrentBlock(s)
        return s
    }
    func buildStructExtract(object: Operand, property: String, irName: String? = nil) throws -> StructExtractInst {
        guard case let alias as TypeAlias = object.type, case let structType as StructType = alias.targetType else { throw VHIRError.noType }
        let elType = try structType.propertyType(property)
        let s = StructExtractInst(object: object, property: property, propertyType: elType.usingTypesIn(module), structType: structType, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
    
    // TODO: compound extracting
    // TODO: make stdlib struct messing in the compiler nicer

//    func buildStdlibStructExtract(object: Operand, type: String, property: String, irName: String? = nil) throws -> StructExtractInst {
//        guard case let alias as TypeAlias = object.type, case let structType as StructType = alias.targetType else { throw VHIRError.noType }
//        let elType = try structType.propertyType(property)
//        let s = StructExtractInst(object: object, property: property, propertyType: elType.usingTypesIn(module), structType: structType, irName: irName)
//        try addToCurrentBlock(s)
//        return s
//    }
}