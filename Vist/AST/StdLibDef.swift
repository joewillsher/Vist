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
    
    init (types: [(String, FnType)]) {
        var t: [String: FnType] = [:]
        
        for (n, ty) in types {
            let mangled = n.mangle(ty.params)
            t[mangled] = ty
        }
        functions = t
    }
    
    subscript(fn fn: String, types types: [Ty]) -> (String, FnType)? {
        get {
            let mangled = fn.mangle(types)
            guard let ty = functions[mangled] else { return nil }
            return (mangled, ty)
        }
    }
}


final class StdLibFunctions {
    
    private static let IntType = StructType(members: [("value", BuiltinType.Int(size: 64), true)], methods: [], name: "Int")
    private static let BoolType = StructType(members: [("value", BuiltinType.Bool, true)], methods: [], name: "Bool")
    private static let FloatType = StructType(members: [("value", BuiltinType.Float(size: 64), true)], methods: [], name: "Float")
    private static let RangeType = StructType(members: [("start", BuiltinType.Int(size: 64), true), ("end", BuiltinType.Int(size: 64), true)], methods: [], name: "Range")
    private static let VoidType = BuiltinType.Void
   
    private static let functions: [(String, FnType)] = [
        // int
        ("+", FnType(params: [IntType, IntType], returns: IntType)),
        ("-", FnType(params: [IntType, IntType], returns: IntType)),
        ("*", FnType(params: [IntType, IntType], returns: IntType)),
        ("/", FnType(params: [IntType, IntType], returns: IntType)),
        ("%", FnType(params: [IntType, IntType], returns: IntType)),
        
        (">", FnType(params: [IntType, IntType], returns: BoolType)),
        (">=", FnType(params: [IntType, IntType], returns: BoolType)),
        ("<", FnType(params: [IntType, IntType], returns: BoolType)),
        ("<=", FnType(params: [IntType, IntType], returns: BoolType)),
        ("==", FnType(params: [IntType, IntType], returns: BoolType)),
        ("!=", FnType(params: [IntType, IntType], returns: BoolType)),
        
        // bool
        ("&&", FnType(params: [BoolType, BoolType], returns: BoolType)),
        ("||", FnType(params: [BoolType, BoolType], returns: BoolType)),
        
        // double
        ("+", FnType(params: [FloatType, FloatType], returns: FloatType)),
        ("-", FnType(params: [FloatType, FloatType], returns: FloatType)),
        ("*", FnType(params: [FloatType, FloatType], returns: FloatType)),
        ("/", FnType(params: [FloatType, FloatType], returns: FloatType)),
        ("%", FnType(params: [FloatType, FloatType], returns: FloatType)),
        
        (">", FnType(params: [FloatType, FloatType], returns: BoolType)),
        (">=", FnType(params: [FloatType, FloatType], returns: BoolType)),
        ("<", FnType(params: [FloatType, FloatType], returns: BoolType)),
        ("<=", FnType(params: [FloatType, FloatType], returns: BoolType)),
        ("==", FnType(params: [FloatType, FloatType], returns: BoolType)),
        ("!=", FnType(params: [FloatType, FloatType], returns: BoolType)),

        // range
        ("...", FnType(params: [IntType, IntType], returns: RangeType)),
        ("..<", FnType(params: [IntType, IntType], returns: RangeType)),
        
        
        
        // fns
        ("print", FnType(params: [IntType], returns: VoidType)),
        ("print", FnType(params: [BoolType], returns: VoidType)),
        ("print", FnType(params: [FloatType], returns: VoidType)),
        ("assert", FnType(params: [BoolType], returns: VoidType)),
        ("fatalError", FnType(params: [], returns: VoidType)),
        
        
        ("Int", FnType(params: [BuiltinType.Int(size: 64)], returns: IntType)),
        ("Int", FnType(params: [IntType], returns: IntType)),
        ("Bool", FnType(params: [BuiltinType.Bool], returns: BoolType)),
        ("Bool", FnType(params: [BoolType], returns: IntType)),
        ("Float", FnType(params: [BuiltinType.Float(size: 64)], returns: FloatType)),
        ("Float", FnType(params: [FloatType], returns: IntType))
    ]
    
    /// Container initialised with functions, provides subscript to look up functions by name and type
    private static let functionContainer = FunctionContainer(types: functions)
    
    
    
    
    
    static func getStdLibFunction(id: String, args: [Ty]) -> (String, FnType)? {
        return functionContainer[fn: id, types: args]
    }
    
    static func getFunctionIR(name: String, args: [Ty], module: LLVMModuleRef) -> LLVMValueRef? {
       
        if let (mangledName, type) = StdLibFunctions.getStdLibFunction(name, args: args) {
            let functionType = type.ir()
            
            let a = LLVMGetNamedFunction(module, mangledName)
            if a != nil { return a }
            
            return LLVMAddFunction(module, mangledName, functionType)
        }
        return nil
    }
    
    
}






