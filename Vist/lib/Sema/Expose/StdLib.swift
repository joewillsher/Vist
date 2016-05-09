//
//  StdLibDef.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct StdLib {
    
    static let intType =    StructType(members:   [("value", BuiltinType.int(size: 64), true)],       methods: [], name: "Int")
    static let int32Type =  StructType(members:   [("value", BuiltinType.int(size: 32), true)],       methods: [], name: "Int32")
    static let boolType =   StructType(members:   [("value", BuiltinType.bool, true)],                methods: [], name: "Bool")
    static let doubleType = StructType(members:   [("value", BuiltinType.float(size: 64), true)],     methods: [], name: "Double")
    static let rangeType =  StructType(
        members:   [
            ("start", intType, true),
            ("end", intType, true)],
        methods: [
            (name: "generate", type: FunctionType(params: [], returns: BuiltinType.void, yieldType: intType), mutating: false),
        ], name: "Range")
    
    static let utf8CodeUnitType = StructType(members:    [("unit", BuiltinType.int(size: 8), true)],     methods: [], name: "UTF8CodeUnit")
    static let utf16CodeUnitType = StructType(members:   [("unit", BuiltinType.int(size: 8), true)],     methods: [], name: "UTF16CodeUnit")
    static let stringType = StructType(
        members:   [
            ("base", BuiltinType.opaquePointer, true),
            ("length", intType, true),
            ("_capacityAndEncoding", intType, true)],
        methods: [
            (name: "isUTF8Encoded", type: FunctionType(params: [], returns: boolType), mutating: false),
            (name: "bufferCapacity", type: FunctionType(params: [], returns: intType), mutating: false),
            (name: "codeUnitAtIndex", type: FunctionType(params: [StdLib.intType], returns: BuiltinType.opaquePointer), mutating: false),
            (name: "generate", type: FunctionType(params: [], returns: BuiltinType.void, yieldType: utf8CodeUnitType), mutating: false),
        ], name: "String")
    private static let voidType = BuiltinType.void
    
    private static let types = [intType, boolType, doubleType, rangeType, utf8CodeUnitType, utf16CodeUnitType, stringType]
    
    //    private static let concepts: [ConceptType] = [ConceptType(name: "Generator", requiredFunctions: [("generate", FunctionType(params: [], returns: intType))], requiredProperties: [])]
    
    private static let functions: [(String, FunctionType)] = [
        // int
        ("+", FunctionType(params: [intType, intType], returns: intType, callingConvention: .thin)),
        ("-", FunctionType(params: [intType, intType], returns: intType)),
        ("*", FunctionType(params: [intType, intType], returns: intType)),
        ("/", FunctionType(params: [intType, intType], returns: intType)),
        ("%", FunctionType(params: [intType, intType], returns: intType)),
        
        (">>", FunctionType(params: [intType, intType], returns: intType)),
        ("<<", FunctionType(params: [intType, intType], returns: intType)),
        ("~&", FunctionType(params: [intType, intType], returns: intType)),
        ("~|", FunctionType(params: [intType, intType], returns: intType)),
        ("~^", FunctionType(params: [intType, intType], returns: intType)),
        
        (">",  FunctionType(params: [intType, intType], returns: boolType)),
        (">=", FunctionType(params: [intType, intType], returns: boolType)),
        ("<",  FunctionType(params: [intType, intType], returns: boolType)),
        ("<=", FunctionType(params: [intType, intType], returns: boolType)),
        ("==", FunctionType(params: [intType, intType], returns: boolType)),
        ("!=", FunctionType(params: [intType, intType], returns: boolType)),
        
        // bool
        ("&&", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("||", FunctionType(params: [boolType, boolType], returns: boolType)),
        
        // double
        ("+", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("-", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("*", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("/", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("%", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        
        (">",  FunctionType(params: [doubleType, doubleType], returns: boolType)),
        (">=", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("<",  FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("<=", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("==", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("!=", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        
        // range
        ("...", FunctionType(params: [intType, intType], returns: rangeType)),
        ("..<", FunctionType(params: [intType, intType], returns: rangeType)),
        
        // pointer
        ("+", FunctionType(params: [BuiltinType.opaquePointer, intType], returns: BuiltinType.opaquePointer)),
        ("-", FunctionType(params: [BuiltinType.opaquePointer, intType], returns: BuiltinType.opaquePointer)),
        
        // fns
        ("print",      FunctionType(params: [intType],    returns: voidType)),
        ("print",      FunctionType(params: [int32Type], returns: voidType)),
        ("print",      FunctionType(params: [boolType],   returns: voidType)),
        ("print",      FunctionType(params: [doubleType], returns: voidType)),
        ("print",      FunctionType(params: [stringType], returns: voidType)),
        ("assert",     FunctionType(params: [boolType],   returns: voidType)),
        ("fatalError", FunctionType(params: [],           returns: voidType)),
        
        
        //         initialisers
        // ones which take Builtin types are used to wrap literals
        ("Int",     FunctionType(params: [BuiltinType.int(size: 64)],   returns: intType)),
        ("Int",     FunctionType(params: [intType],                     returns: intType)),
        ("Int32",   FunctionType(params: [BuiltinType.int(size: 32)],   returns: int32Type)),
        ("Int32",   FunctionType(params: [int32Type],                   returns: int32Type)),
        ("Bool",    FunctionType(params: [BuiltinType.bool],            returns: boolType)),
        ("Bool",    FunctionType(params: [boolType],                    returns: intType)),
        ("Float",   FunctionType(params: [BuiltinType.float(size: 64)], returns: doubleType)),
        ("Float",   FunctionType(params: [doubleType],                  returns: intType)),
        ("Range",   FunctionType(params: [intType, intType],            returns: rangeType)),
        ("Range",   FunctionType(params: [rangeType],                   returns: rangeType)),
        ("String",  FunctionType(params: [BuiltinType.opaquePointer, BuiltinType.int(size: 64), BuiltinType.bool], returns: stringType)),
        ]
    
    /// Container initialised with functions, provides subscript to look up functions by name and type
    ///
    /// Adds the `stdlib.call.optim` metadata tag to all of them
    private static let functionContainer = FunctionContainer(functions: functions, types: types, metadata: ["stdlib.call.optim"])
    
    
    private static func getStdLibFunctionWithInitInfo(id: String, args: [Type]) -> (String, FunctionType)? {
        return functionContainer[fn: id, types: args]
    }
    
    
    // MARK: Exposed functions
    
    /// Returns the struct type of a named StdLib object
    static func type(name id: String) -> StructType? {
        return functionContainer[type: id]
    }
    
    /// Get the type of a function from the standard library by mangled name
    /// - parameter mangledName: Mangled function name
    static func function(mangledName name: String) -> FunctionType? {
        return functionContainer[mangledName: name]?.type
    }
    
    /// Get a named function from the standard library
    /// - parameter name: Unmangled name
    /// - parameter args: Applied arg types
    /// - returns: An optional tuple of `(mangledName, type)`
    static func function(name name: String, args: [Type]) -> (mangledName: String, type: FunctionType)? {
        return functionContainer[fn: name, types: args]
    }
}
