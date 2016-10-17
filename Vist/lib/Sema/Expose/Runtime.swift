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
    
    static let refcountedObjectType = StructType.withTypes([BuiltinType.opaquePointer, int32Type, BuiltinType.opaquePointer], name: "vist.class_box")
    static let refcountedObjectPointerType = BuiltinType.pointer(to: refcountedObjectType)

    private static let __typeMetadataType = StructType.withTypes([conceptConformanceType.ptrType().ptrType(), int32Type, int32Type, BuiltinType.opaquePointer, boolType, BuiltinType.opaquePointer, BuiltinType.opaquePointer, BuiltinType.opaquePointer], name: "vist._metadata")
    
    
    static let valueWitnessType = StructType.withTypes([BuiltinType.opaquePointer], name: "vist.witness")
    static let conceptConformanceType = StructType.withTypes([BuiltinType.opaquePointer/*TypeMetadata *concept*/, int32Type.ptrType(), int32Type, witnessTableType.ptrType()], name: "vist.conformance")
    static let witnessTableType = StructType.withTypes([valueWitnessType.ptrType(), int32Type], name: "vist.witness_table")
    static let typeMetadataType = StructType.withTypes([
        /*conformances=*/conceptConformanceType.ptrType().ptrType(), /*numconformances=*/int32Type, /*size=*/int32Type,
        /*name=*/BuiltinType.opaquePointer, /*isreftype=*/boolType,
        /*destructor=*/BuiltinType.opaquePointer, /*deinit=*/BuiltinType.opaquePointer, /*copyconstructor=*/BuiltinType.opaquePointer],
                                                       name: "vist.metadata")
    static let existentialObjectType = StructType.withTypes([BuiltinType.wordType, int32Type, conceptConformanceType.ptrType().ptrType(), typeMetadataType], name: "vist.existential")
    
    struct Function {
        let name: String, type: FunctionType
        
        // as is described [here](http://llvm.org/devmtg/2014-10/Videos/Skip%20The%20FFI!%20Embedding%20Clang%20for%20C-360.mov)
        // we cannot have a runtime function which uses anything other than a int or int sized pointer, or clang
        // will not emit a simple mapping from clang type -> IR type and our call will fail
        
        static let destroyExistentialBuffer = Function(name: "vist_deallocExistentialBuffer", type: FunctionType(params: [existentialObjectType.ptrType()], returns: BuiltinType.void))

        static let allocObject = Function(name: "vist_allocObject", type: FunctionType(params: [typeMetadataType.ptrType()], returns: refcountedObjectPointerType))
        static let deallocObject = Function(name: "vist_deallocObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        static let retainObject  = Function(name: "vist_retainObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        static let releaseObject  = Function(name: "vist_releaseObject", type: FunctionType(params: [refcountedObjectPointerType], returns: voidType))
        
        static let setYieldTarget = Function(name: "vist_setYieldTarget", type: FunctionType(params: [], returns: boolType))
        static let yieldUnwind = Function(name: "vist_yieldUnwind", type: FunctionType(params: [], returns: voidType))
        
        static let getWitnessMethod = Function(name: "vist_getWitnessMethod",
                                               type: FunctionType(params: [existentialObjectType.ptrType(), int32Type, int32Type], returns: Builtin.opaquePointerType))
        static let getPropertyProjection = Function(name: "vist_getPropertyProjection",
                                                    type: FunctionType(params: [existentialObjectType.ptrType(), int32Type, int32Type], returns: Builtin.opaquePointerType))
        static let getBufferProjection = Function(name: "vist_getExistentialBufferProjection",
                                                  type: FunctionType(params: [existentialObjectType.ptrType()], returns: Builtin.opaquePointerType))
        
        // vist_constructExistential has type '(ExistentialObjectType) -> ExistentialObjectType', but is lowered to
        // define void @testLayout(%struct.ExistentialObject* noalias nocapture sret, %struct.ExistentialObject* byval nocapture readonly align 8)
        // so we cannot use this from swift. Change this so it stores into a ptr param
        static let constructExistential = Function(name: "vist_constructExistential", type:
            FunctionType(params: [conceptConformanceType.ptrType(), /*instance=*/BuiltinType.opaquePointer,
                                  typeMetadataType.ptrType(), /*is nonlocal=*/BuiltinType.bool,
                                  /*out param=*/existentialObjectType.ptrType()], returns: BuiltinType.void))
        
        static let exportExistentialBuffer = Function(name: "vist_exportExistentialBuffer", type: FunctionType(params: [existentialObjectType.ptrType()], returns: BuiltinType.void))
        static let copyExistentialBuffer = Function(name: "vist_copyExistentialBuffer", type: FunctionType(params: [existentialObjectType.ptrType(), existentialObjectType.ptrType()], returns: BuiltinType.void))
        static let castExistentialToConcrete = Function(name: "vist_castExistentialToConcrete", type: FunctionType(params: [existentialObjectType.ptrType(), typeMetadataType.ptrType(), opaquePointerType], returns: BuiltinType.bool))
        static let castExistentialToConcept = Function(name: "vist_castExistentialToConcept", type: FunctionType(params: [existentialObjectType.ptrType(), typeMetadataType.ptrType(), existentialObjectType.ptrType()], returns: BuiltinType.bool))

    }
}

