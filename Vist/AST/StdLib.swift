//
//  StdLibDef.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct StdLib {
    
    static let IntType =    StructType(members:   [("value", BuiltinType.int(size: 64), true)],       methods: [], name: "Int")
    static let Int32Type =    StructType(members: [("value", BuiltinType.int(size: 32), true)],       methods: [], name: "Int32")
    static let BoolType =   StructType(members:   [("value", BuiltinType.bool, true)],                methods: [], name: "Bool")
    static let DoubleType = StructType(members:   [("value", BuiltinType.float(size: 64), true)],     methods: [], name: "Double")
    static let RangeType =  StructType(members:   [("start", IntType, true), ("end", IntType, true)], methods: [], name: "Range")
    private static let VoidType =   BuiltinType.void
    
    private static let types: [StructType] = [IntType, BoolType, DoubleType, RangeType]
    
    private static let functions: [(String, FnType)] = [
        // int
        ("+", FnType(params: [IntType, IntType], returns: IntType)),
        ("-", FnType(params: [IntType, IntType], returns: IntType)),
        ("*", FnType(params: [IntType, IntType], returns: IntType)),
        ("/", FnType(params: [IntType, IntType], returns: IntType)),
        ("%", FnType(params: [IntType, IntType], returns: IntType)),
        
        (">",  FnType(params: [IntType, IntType], returns: BoolType)),
        (">=", FnType(params: [IntType, IntType], returns: BoolType)),
        ("<",  FnType(params: [IntType, IntType], returns: BoolType)),
        ("<=", FnType(params: [IntType, IntType], returns: BoolType)),
        ("==", FnType(params: [IntType, IntType], returns: BoolType)),
        ("!=", FnType(params: [IntType, IntType], returns: BoolType)),
        
        // bool
        ("&&", FnType(params: [BoolType, BoolType], returns: BoolType)),
        ("||", FnType(params: [BoolType, BoolType], returns: BoolType)),
        
        // double
        ("+", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("-", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("*", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("/", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("%", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        
        (">",  FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        (">=", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("<",  FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("<=", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("==", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("!=", FnType(params: [DoubleType, DoubleType], returns: BoolType)),

        // range
        ("...", FnType(params: [IntType, IntType], returns: RangeType)),
        ("..<", FnType(params: [IntType, IntType], returns: RangeType)),
        
        
        
        // fns
        ("print",      FnType(params: [IntType],    returns: VoidType)),
        ("print",      FnType(params: [Int32Type], returns: VoidType)),
        ("print",      FnType(params: [BoolType],   returns: VoidType)),
        ("print",      FnType(params: [DoubleType], returns: VoidType)),
        ("assert",     FnType(params: [BoolType],   returns: VoidType)),
        ("fatalError", FnType(params: [],           returns: VoidType)),
        
        
//         initialisers
        // ones which take Builtin types are used to wrap literals
        ("Int",     FnType(params: [BuiltinType.int(size: 64)],   returns: IntType)),
        ("Int",     FnType(params: [IntType],                     returns: IntType)),
        ("Int32",   FnType(params: [BuiltinType.int(size: 32)],   returns: Int32Type)),
        ("Int32",   FnType(params: [Int32Type],                   returns: Int32Type)),
        ("Bool",    FnType(params: [BuiltinType.bool],            returns: BoolType)),
        ("Bool",    FnType(params: [BoolType],                    returns: IntType)),
        ("Float",   FnType(params: [BuiltinType.float(size: 64)], returns: DoubleType)),
        ("Float",   FnType(params: [DoubleType],                  returns: IntType)),
        ("Range",   FnType(params: [IntType, IntType],            returns: RangeType)),
        ("Range",   FnType(params: [RangeType],                   returns: RangeType))
    ]
    
    /// Container initialised with functions, provides subscript to look up functions by name and type
    ///
    /// Adds the `stdlib.call.optim` metadata tag to all of them
    ///
    private static let functionContainer = FunctionContainer(functions: functions, types: types, metadata: ["stdlib.call.optim"])
    
    
    private static func getStdLibFunctionWithInitInfo(id: String, args: [Ty]) -> (String, FnType)? {
        return functionContainer[fn: id, types: args]
    }
    
    
    // MARK: Exposed functions
    
    /// Returns the struct type of a named StdLib object
    ///
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
    ///
    static func getStdLibFunction(name: String, args: [Ty]) -> (mangledName: String, type: FnType)? {
        return functionContainer[fn: name, types: args]
    }    
    
    /// Get the IR for a named function from the standard library
    ///
    /// - parameter id: mangled name
    ///
    /// - returns: An optional tuple of `(type, functionIRRef)`
    ///
    static func getFunctionIR(mangledName: String, module: LLVMModuleRef) -> (type: FnType, functionIR: LLVMValueRef)? {
        guard let (mangledName, type) = functionContainer[mangledName: mangledName] else { return nil }
        let functionType = type.globalType(module)
        
        let found = LLVMGetNamedFunction(module, mangledName)
        if found != nil { return (type, found) }
        
        return (type, LLVMAddFunction(module, mangledName, functionType))
    }

}




