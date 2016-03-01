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
    static let rangeType =  StructType(members:   [("start", intType, true), ("end", intType, true)], methods: [], name: "Range")
    private static let voidType = BuiltinType.void
    
    private static let types: [StructType] = [intType, boolType, doubleType, rangeType]
    
    private static let functions: [(String, FnType)] = [
        // int
        ("+", FnType(params: [intType, intType], returns: intType)),
        ("-", FnType(params: [intType, intType], returns: intType)),
        ("*", FnType(params: [intType, intType], returns: intType)),
        ("/", FnType(params: [intType, intType], returns: intType)),
        ("%", FnType(params: [intType, intType], returns: intType)),
        
        (">>", FnType(params: [intType, intType], returns: intType)),
        ("<<", FnType(params: [intType, intType], returns: intType)),
        ("~&", FnType(params: [intType, intType], returns: intType)),
        ("~|", FnType(params: [intType, intType], returns: intType)),
        ("~^", FnType(params: [intType, intType], returns: intType)),
        
        (">",  FnType(params: [intType, intType], returns: boolType)),
        (">=", FnType(params: [intType, intType], returns: boolType)),
        ("<",  FnType(params: [intType, intType], returns: boolType)),
        ("<=", FnType(params: [intType, intType], returns: boolType)),
        ("==", FnType(params: [intType, intType], returns: boolType)),
        ("!=", FnType(params: [intType, intType], returns: boolType)),
        
        // bool
        ("&&", FnType(params: [boolType, boolType], returns: boolType)),
        ("||", FnType(params: [boolType, boolType], returns: boolType)),
        
        // double
        ("+", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("-", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("*", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("/", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("%", FnType(params: [doubleType, doubleType], returns: doubleType)),
        
        (">",  FnType(params: [doubleType, doubleType], returns: boolType)),
        (">=", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("<",  FnType(params: [doubleType, doubleType], returns: boolType)),
        ("<=", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("==", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("!=", FnType(params: [doubleType, doubleType], returns: boolType)),

        // range
        ("...", FnType(params: [intType, intType], returns: rangeType)),
        ("..<", FnType(params: [intType, intType], returns: rangeType)),
        
        
        
        // fns
        ("print",      FnType(params: [intType],    returns: voidType)),
        ("print",      FnType(params: [int32Type], returns: voidType)),
        ("print",      FnType(params: [boolType],   returns: voidType)),
        ("print",      FnType(params: [doubleType], returns: voidType)),
        ("assert",     FnType(params: [boolType],   returns: voidType)),
        ("fatalError", FnType(params: [],           returns: voidType)),
        
        
//         initialisers
        // ones which take Builtin types are used to wrap literals
        ("Int",     FnType(params: [BuiltinType.int(size: 64)],   returns: intType)),
        ("Int",     FnType(params: [intType],                     returns: intType)),
        ("Int32",   FnType(params: [BuiltinType.int(size: 32)],   returns: int32Type)),
        ("Int32",   FnType(params: [int32Type],                   returns: int32Type)),
        ("Bool",    FnType(params: [BuiltinType.bool],            returns: boolType)),
        ("Bool",    FnType(params: [boolType],                    returns: intType)),
        ("Float",   FnType(params: [BuiltinType.float(size: 64)], returns: doubleType)),
        ("Float",   FnType(params: [doubleType],                  returns: intType)),
        ("Range",   FnType(params: [intType, intType],            returns: rangeType)),
        ("Range",   FnType(params: [rangeType],                   returns: rangeType))
    ]
    
    /// Container initialised with functions, provides subscript to look up functions by name and type
    ///
    /// Adds the `stdlib.call.optim` metadata tag to all of them
    private static let functionContainer = FunctionContainer(functions: functions, types: types, metadata: ["stdlib.call.optim"])
    
    
    private static func getStdLibFunctionWithInitInfo(id: String, args: [Ty]) -> (String, FnType)? {
        return functionContainer[fn: id, types: args]
    }
    
    
    // MARK: Exposed functions
    
    /// Returns the struct type of a named StdLib object
    static func getStdLibType(id: String) -> StructType? {
        return functionContainer[type: id]
    }

    /// Get a named function from the standard library
    ///
    /// - parameter name: Unmangled name
    ///
    /// - parameter args: Applied arg types
    ///
    /// - returns: An optional tuple of `(mangledName, type)`
    static func getStdLibFunction(name: String, args: [Ty]) -> (mangledName: String, type: FnType)? {
        return functionContainer[fn: name, types: args]
    }    
    
    /// Get the IR for a named function from the standard library
    ///
    /// - parameter id: mangled name
    ///
    /// - returns: An optional tuple of `(type, functionIRRef)`
    static func getFunctionIR(mangledName: String, module: LLVMModuleRef) -> (type: FnType, functionIR: LLVMValueRef)? {
        guard let (mangledName, type) = functionContainer[mangledName: mangledName] else { return nil }
        let functionType = type.globalType(module)
        
        let found = LLVMGetNamedFunction(module, mangledName)
        if found != nil { return (type, found) }
        
        return (type, LLVMAddFunction(module, mangledName, functionType))
    }

}




