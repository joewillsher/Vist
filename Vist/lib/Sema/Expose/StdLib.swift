//
//  StdLibDef.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum StdLib {
    
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
    static let stringCoreType = StructType(
        members:   [
            ("base", BuiltinType.opaquePointer, true),
            ("capacityAndEncoding", intType, true)], methods: [], name: "_StringCore", isHeapAllocated: true)
    static let stringType = StructType(
        members:   [("_core", stringCoreType, false)],
        methods: [
            (name: "length", type: FunctionType(params: [], returns: intType), mutating: false),
            (name: "codeUnitAtIndex", type: FunctionType(params: [StdLib.intType], returns: BuiltinType.opaquePointer), mutating: false),
            (name: "generate", type: FunctionType(params: [], returns: BuiltinType.void, yieldType: utf8CodeUnitType), mutating: false),
            (name: "append", type: FunctionType(params: [_stringType], returns: BuiltinType.void), mutating: true),
        ], name: "String")
    private static let _stringType = StructType(members: [("_core", stringCoreType, false)], methods: [], name: "String")
    private static let voidType = BuiltinType.void
    
    static let metatypeType = StructType(members: [("_metadata", BuiltinType.opaquePointer, true)], methods: [(name: "size", type: FunctionType(params: [], returns: intType), mutating: false), (name: "name", type: FunctionType(params: [], returns: stringType), mutating: false)], name: "Metatype")
    
    private static let types = [intType, int32Type, boolType, doubleType, rangeType, utf8CodeUnitType, utf16CodeUnitType, stringType, metatypeType]
    private static let concepts = [printableConcept, anyConcept]
    
    static let printableConcept = ConceptType(name: "Printable", requiredFunctions: [(name: "description", type: FunctionType(params: [], returns: stringType), mutating: false)], requiredProperties: [])
    static let anyConcept = ConceptType(name: "Any", requiredFunctions: [], requiredProperties: [])
    
    private static let functions: [(String, FunctionType)] = [
        // int
        ("+", FunctionType(params: [intType, intType], returns: intType)),
        ("-", FunctionType(params: [intType, intType], returns: intType)),
        ("*", FunctionType(params: [intType, intType], returns: intType)),
        ("/", FunctionType(params: [intType, intType], returns: intType)),
        ("%", FunctionType(params: [intType, intType], returns: intType)),
        ("^", FunctionType(params: [intType, intType], returns: intType)),
        
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
        
        ("inc",FunctionType(params: [intType], returns: intType)),
        ("dec",FunctionType(params: [intType], returns: intType)),
        
        // bool
        ("&&", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("||", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("==", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("!=", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("not", FunctionType(params: [boolType], returns: boolType)),
        
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
        ("print",      FunctionType(params: [printableConcept], returns: voidType)),
        ("assert",     FunctionType(params: [boolType],   returns: voidType)),
        ("fatalError", FunctionType(params: [],           returns: voidType)),
        ("fatalError", FunctionType(params: [stringType], returns: voidType)),
        
        ("typeof",     FunctionType(params: [anyConcept],   returns: metatypeType)),
        
        // TODO: when we can link parallel compiled files' AST we 
        //       won't need to expose private stdlib function
        ("_print",      FunctionType(params: [stringType], returns: voidType)),
        
        // initialisers
        // ones which take Builtin types are used to wrap literals
        ("Int",     FunctionType(params: [BuiltinType.int(size: 64)],   returns: intType, callingConvention: .initialiser)),
        ("Int",     FunctionType(params: [intType],                     returns: intType, callingConvention: .initialiser)),
        ("Int32",   FunctionType(params: [BuiltinType.int(size: 32)],   returns: int32Type, callingConvention: .initialiser)),
        ("Int32",   FunctionType(params: [int32Type],                   returns: int32Type, callingConvention: .initialiser)),
        ("Bool",    FunctionType(params: [BuiltinType.bool],            returns: boolType, callingConvention: .initialiser)),
        ("Bool",    FunctionType(params: [boolType],                    returns: intType, callingConvention: .initialiser)),
        ("Double",  FunctionType(params: [BuiltinType.float(size: 64)], returns: doubleType, callingConvention: .initialiser)),
        ("Double",  FunctionType(params: [doubleType],                  returns: intType, callingConvention: .initialiser)),
        ("Range",   FunctionType(params: [intType, intType],            returns: rangeType, callingConvention: .initialiser)),
        ("Range",   FunctionType(params: [rangeType],                   returns: rangeType, callingConvention: .initialiser)),
        ("String",  FunctionType(params: [BuiltinType.opaquePointer, BuiltinType.int(size: 64), BuiltinType.bool], returns: stringType, callingConvention: .initialiser)),
        
        // shim fns
        ("vist_cshim_print", FunctionType(params: [BuiltinType.int(size: 64)], returns: voidType)),
        ("vist_cshim_print", FunctionType(params: [BuiltinType.float(size: 64)], returns: voidType)),
        ("vist_cshim_print", FunctionType(params: [BuiltinType.bool], returns: voidType)),
        ("vist_cshim_print", FunctionType(params: [BuiltinType.int(size: 32)], returns: voidType)),
        ("vist_cshim_putchar", FunctionType(params: [BuiltinType.int(size: 8)], returns: voidType)),
        ("vist_cshim_write", FunctionType(params: [BuiltinType.opaquePointer, BuiltinType.int(size: 64)], returns: voidType)),
        ("vist_cshim_strlen", FunctionType(params: [BuiltinType.opaquePointer], returns: BuiltinType.int(size: 64))),
    ]
    
    /// Container initialised with functions, provides subscript to look up functions by name and type
    ///
    /// Adds the `stdlib.call.optim` metadata tag to all of them
    private static let functionContainer = FunctionContainer(functions: functions, types: types, concepts: concepts)
    
    /// Returns the struct type of a named StdLib object
    static func type(name id: String) -> NominalType? {
        return functionContainer[type: id]
    }
    
    /// Get the type of a function from the standard library by mangled name
    /// - parameter mangledName: Mangled function name
    static func function(mangledName name: String) -> FunctionType? {
        return functionContainer.functions[name]
    }
    
    /// Get a named function from the standard library
    /// - parameter name: Unmangled name
    /// - parameter args: Applied arg types
    /// - parameter solver: the scope's constraint solver
    /// - returns: An optional tuple of `(mangledName, type)`
    static func function(name: String, args: [Type], base: NominalType?, solver: ConstraintSolver) -> Solution? {
        return functionContainer.lookupFunction(named: name, argTypes: args, base: base, solver: solver)
    }
}
