//
//  Runtime.swift
//  Vist
//
//  Created by Josef Willsher on 06/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// The builtin functions
struct Runtime {
    private static let intType = BuiltinType.int(size: 64)
    private static let int32Type = BuiltinType.int(size: 32)
    private static let doubleType = BuiltinType.float(size: 64)
    private static let boolType = BuiltinType.bool
    private static let voidType = BuiltinType.void
    private static let opaquePointerType = BuiltinType.opaquePointer
    
    static let refcountedObjectType = StructType.withTypes([BuiltinType.opaquePointer, BuiltinType.int(size: 32)], name: "RefcountedObject")
    static let refcountedObjectPointerType = BuiltinType.pointer(to: refcountedObjectType)
    
    private static let functions: [(String, FunctionType)] = [
        // runtime fns
        ("vist_print", FunctionType(params: [intType], returns: voidType)),
        ("vist_print", FunctionType(params: [doubleType], returns: voidType)),
        ("vist_print", FunctionType(params: [boolType], returns: voidType)),
        ("vist_print", FunctionType(params: [int32Type], returns: voidType)),
        ("vist_cshim_putchar", FunctionType(params: [BuiltinType.int(size: 8)], returns: voidType)),
        ("vist_cshim_write", FunctionType(params: [opaquePointerType, intType], returns: voidType)),
    ]
    private static let unmangled: [(String, FunctionType)] = [
        ("vist_allocObject", FunctionType(params: [int32Type], returns: refcountedObjectPointerType)),
        ("vist_deallocObject", FunctionType(params: [refcountedObjectPointerType], returns: voidType)),
        ("vist_retainObject", FunctionType(params: [refcountedObjectPointerType], returns: voidType)),
        ("vist_releaseObject", FunctionType(params: [refcountedObjectPointerType], returns: voidType)),
        ("vist_releaseUnownedObject", FunctionType(params: [refcountedObjectPointerType], returns: voidType)),
        ("vist_deallocUnownedObject", FunctionType(params: [refcountedObjectPointerType], returns: voidType)),
        ("vist_setYieldTarget", FunctionType(params: [], returns: boolType)),
        ("vist_yieldUnwind", FunctionType(params: [], returns: voidType)),
    ]
    
    private static let functionContainer = FunctionContainer(functions: functions, types: [])
    private static let unmangledContainer = FunctionContainer(functions: unmangled, types: [], mangleFunctionNames: false)
    
    /// Get a builtin function by name
    /// - parameter name: Unmangled name
    /// - parameter args: Applied arg types
    /// - returns: An optional tuple of `(mangledName, type)`
    static func functionNamed(name: String, argTypes args: [Type]) -> (mangledName: String, type: FunctionType)? {
        return functionContainer[fn: name, types: args]
    }
    
    /// Get a builtin function by name
    /// - parameter name: Unmangled name
    /// - parameter args: Applied arg types
    /// - returns: An optional tuple of `(mangledName, type)`
    static func unmangledFunctionNamed(name: String) -> (mangledName: String, type: FunctionType)? {
        return unmangledContainer[mangledName: name]
    }
    
}

