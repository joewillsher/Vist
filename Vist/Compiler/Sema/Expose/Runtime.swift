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
    
    private static let functions: [(String, FnType)] = [
        // runtime fns
        ("vist_print", FnType(params: [intType], returns: voidType)),
        ("vist_print", FnType(params: [doubleType], returns: voidType)),
        ("vist_print", FnType(params: [boolType], returns: voidType)),
        ("vist_print", FnType(params: [int32Type], returns: voidType)),
    ]
//    private static let unmangled: [(String, FnType)] = [
        // runtime fns
//        ("vist_alloc", FnType(params: [Builtin.pointer(to: intType)], returns: voidType)),
//    ]
    
    private static let functionContainer = FunctionContainer(functions: functions, types: [])
//    private static let unmangledContainer = FunctionContainer(functions: unmangled, types: [], mangleFunctionNames: false)
    
    /// Get a builtin function by name
    ///
    /// - parameter name: Unmangled name
    ///
    /// - parameter args: Applied arg types
    ///
    /// - returns: An optional tuple of `(mangledName, type)`
    ///
    static func functionNamed(name: String, argTypes args: [Ty]) -> (mangledName: String, type: FnType)? {
        return functionContainer[fn: name, types: args]
    }
}

