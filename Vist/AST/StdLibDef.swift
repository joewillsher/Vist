//
//  StdLibDef.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class StdLib {
    
    static let IntType =    StructType(members: [("value", BuiltinType.Int(size: 64), true)],       methods: [], name: "Int")
    static let BoolType =   StructType(members: [("value", BuiltinType.Bool, true)],                methods: [], name: "Bool")
    static let DoubleType = StructType(members: [("value", BuiltinType.Float(size: 64), true)],     methods: [], name: "Double")
    static let RangeType =  StructType(members: [("start", IntType, true), ("end", IntType, true)], methods: [], name: "Range")
    static let VoidType =   BuiltinType.Void
    
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
        ("print",      FnType(params: [BoolType],   returns: VoidType)),
        ("print",      FnType(params: [DoubleType], returns: VoidType)),
        ("assert",     FnType(params: [BoolType],   returns: VoidType)),
        ("fatalError", FnType(params: [],           returns: VoidType)),
        
        
        ("Int",     FnType(params: [BuiltinType.Int(size: 64)],   returns: IntType)),
        ("Int",     FnType(params: [IntType],                     returns: IntType)),
        ("Bool",    FnType(params: [BuiltinType.Bool],            returns: BoolType)),
        ("Bool",    FnType(params: [BoolType],                    returns: IntType)),
        ("Float",   FnType(params: [BuiltinType.Float(size: 64)], returns: DoubleType)),
        ("Float",   FnType(params: [DoubleType],                  returns: IntType)),
        ("Range",   FnType(params: [IntType, IntType],            returns: RangeType)),
        ("Range",   FnType(params: [RangeType],                   returns: RangeType))
    ]
    
    /// Container initialised with functions, provides subscript to look up functions by name and type
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
    /// - parameter id: Unmangled name
    ///
    /// - parameter args: Applied arg types
    ///
    /// - returns: An optional tuple of `(mangled-name, type)`
    ///
    static func getStdLibFunction(id: String, args: [Ty]) -> (String, FnType)? {
        guard let fn = functionContainer[fn: id, types: args] else { return nil }
        return (fn.0, fn.1)
    }
    
    
    /// Get the IR for a named function from the standard library
    ///
    /// - parameter id: Unmangled name
    ///
    /// - parameter args: Applied arg types
    ///
    /// - returns: An optional tuple of `(type, function-ir-ref)`
    ///
    static func getFunctionIR(name: String, args: [Ty], module: LLVMModuleRef) -> (FnType, LLVMValueRef)? {
       
        if let (mangledName, type) = StdLib.getStdLibFunctionWithInitInfo(name, args: args) {
            let functionType = type.ir()
            
            let found = LLVMGetNamedFunction(module, mangledName)
            if found != nil { return (type, found) }
            
            return (type, LLVMAddFunction(module, mangledName, functionType))
        }
        return nil
    }
    
    
}




