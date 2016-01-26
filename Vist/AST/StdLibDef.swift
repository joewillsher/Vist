//
//  StdLibDef.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// Holds functions, mangles them on initialisation and subscript
private struct FunctionContainer {
    
    private let functions: [String: FnType]
    private let types: [StructType]
    
    init (functions: [(String, FnType)], types: [StructType]) {
        var t: [String: FnType] = [:]
        
        for (n, ty) in functions {
            let mangled = n.mangle(ty.params)
            t[mangled] = ty
        }
        
        self.functions = t
        self.types = types
    }
    
    subscript(fn fn: String, types types: [Ty]) -> (String, FnType)? {
        get {
            let mangled = fn.mangle(types)
            guard let ty = functions[mangled] else { return nil }
            return (mangled, ty)
        }
    }
    subscript(type type: String) -> StructType? {
        get {
            if let i = types.indexOf({ $0.name == type }) { return types[i] } else { return nil }
        }
    }
}


final class StdLibFunctions {
    
    private static let IntType =    StructType(members: [("value", BuiltinType.Int(size: 64), true)],       methods: [], name: "Int")
    private static let BoolType =   StructType(members: [("value", BuiltinType.Bool, true)],                methods: [], name: "Bool")
    private static let DoubleType = StructType(members: [("value", BuiltinType.Float(size: 64), true)],     methods: [], name: "Double")
    private static let RangeType =  StructType(members: [("start", IntType, true), ("end", IntType, true)], methods: [], name: "Range")
    private static let VoidType =   BuiltinType.Void
    
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
        
        
        ("Int",     FnType(params: [BuiltinType.Int(size: 64)],   returns: IntType,    metadata: ["stdlib.init"])),
        ("Int",     FnType(params: [IntType],                     returns: IntType,    metadata: ["stdlib.init"])),
        ("Bool",    FnType(params: [BuiltinType.Bool],            returns: BoolType,   metadata: ["stdlib.init"])),
        ("Bool",    FnType(params: [BoolType],                    returns: IntType,    metadata: ["stdlib.init"])),
        ("Float",   FnType(params: [BuiltinType.Float(size: 64)], returns: DoubleType, metadata: ["stdlib.init"])),
        ("Float",   FnType(params: [DoubleType],                  returns: IntType,    metadata: ["stdlib.init"])),
        ("Range",   FnType(params: [IntType, IntType],            returns: RangeType,  metadata: ["stdlib.init"])),
        ("Range",   FnType(params: [RangeType],                   returns: RangeType,  metadata: ["stdlib.init"]))
    ]
    
    /// Container initialised with functions, provides subscript to look up functions by name and type
    private static let functionContainer = FunctionContainer(functions: functions, types: types)
    
    static func getStdLibType(id: String) -> StructType? {
        return functionContainer[type: id]
    }
    
    private static func getStdLibFunctionWithInitInfo(id: String, args: [Ty]) -> (String, FnType)? {
        return functionContainer[fn: id, types: args]
    }
    
    static func getStdLibFunction(id: String, args: [Ty]) -> (String, FnType)? {
        guard let fn = functionContainer[fn: id, types: args] else { return nil }
        return (fn.0, fn.1)
    }
    
    
    static func getFunctionIR(name: String, args: [Ty], module: LLVMModuleRef) -> (FnType, LLVMValueRef)? {
       
        if let (mangledName, type) = StdLibFunctions.getStdLibFunctionWithInitInfo(name, args: args) {
            let functionType = type.ir()
            
            let found = LLVMGetNamedFunction(module, mangledName)
            if found != nil { return (type, found) }
            
            // move to call site
            
            return (type, LLVMAddFunction(module, mangledName, functionType))
        }
        return nil
    }
    
    
}






