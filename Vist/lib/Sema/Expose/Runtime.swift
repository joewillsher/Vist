//
//  Runtime.swift
//  Vist
//
//  Created by Josef Willsher on 06/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// The builtin functions
enum Runtime {
    private static let intType = BuiltinType.int(size: 64)
    private static let int32Type = BuiltinType.int(size: 32)
    private static let int16Type = BuiltinType.int(size: 16)
    private static let int8Type = BuiltinType.int(size: 8)
    private static let doubleType = BuiltinType.float(size: 64)
    private static let boolType = BuiltinType.bool
    private static let voidType = BuiltinType.void
    private static let opaquePointerType = BuiltinType.opaquePointer
    
    static let refcountedObjectType = StructType.withTypes([BuiltinType.opaquePointer, int32Type], name: "Refcounted")
    static let refcountedObjectPointerType = BuiltinType.pointer(to: refcountedObjectType)

    private static let __typeMetadataType = StructType.withTypes([BuiltinType.pointer(to: BuiltinType.pointer(to: conceptConformanceType)), int32Type, BuiltinType.pointer(to: int8Type)], name: "TypeMetadata")
    
    
    static let valueWitnessType = StructType.withTypes([BuiltinType.opaquePointer], name: "Witness")
    static let conceptConformanceType = StructType.withTypes([BuiltinType.opaquePointer/*TypeMetadata *concept*/, BuiltinType.pointer(to: int32Type), int32Type, BuiltinType.pointer(to: witnessTableType)], name: "Conformance")
    static let witnessTableType = StructType.withTypes([BuiltinType.pointer(to: valueWitnessType), int32Type], name: "WitnessTable")
    static let typeMetadataType = StructType.withTypes([BuiltinType.pointer(to: BuiltinType.pointer(to: conceptConformanceType)), int32Type, BuiltinType.pointer(to: int8Type)], name: "Metadata")
    static let existentialObjectType = StructType.withTypes([BuiltinType.opaquePointer, int32Type, BuiltinType.pointer(to: BuiltinType.pointer(to: conceptConformanceType))], name: "Existential")
    
    struct Function {
        let name: String, type: FunctionType
        
        static let allocObject = Function(name: "vist_allocObject", type: FunctionType(params: [int32Type], returns: refcountedObjectPointerType))
        static let deallocObject = Function(name: "vist_deallocObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        static let retainObject  = Function(name: "vist_retainObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        static let releaseObject  = Function(name: "vist_releaseObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        static let releaseUnownedObject = Function(name: "vist_releaseUnownedObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        static let deallocUnownedObject = Function(name: "vist_deallocUnownedObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        
        static let setYieldTarget = Function(name: "vist_setYieldTarget", type: FunctionType(params: [], returns: boolType))
        static let yieldUnwind = Function(name: "vist_yieldUnwind", type: FunctionType(params: [], returns: voidType))
        
        static let getWitnessMethod = Function(name: "vist_getWitnessMethod", type: FunctionType(params: [BuiltinType.pointer(to: existentialObjectType), int32Type, int32Type], returns: Builtin.opaquePointerType))
        static let getPropertyOffset = Function(name: "vist_getPropertyOffset", type: FunctionType(params: [BuiltinType.pointer(to: existentialObjectType), int32Type, int32Type], returns: Builtin.int32Type))
        static let constructExistential = Function(name: "vist_constructExistential", type: FunctionType(params: [BuiltinType.pointer(to: conceptConformanceType), BuiltinType.opaquePointer], returns:
            BuiltinType.pointer(to:
            existentialObjectType
            )
            ))
    }
}

