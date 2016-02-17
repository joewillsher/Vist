//
//  Builtin.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct Builtin {

    static let IntType = BuiltinType.Int(size: 64)
    static let Int32Type = BuiltinType.Int(size: 32)
    static let DoubleType = BuiltinType.Float(size: 64)
    static let BoolType = BuiltinType.Bool
    static let VoidType = BuiltinType.Void
    
    static let IntBoolTupleType = TupleType(members: [IntType, BoolType])
    
    private static let functions: [(String, FnType)] = [
        // integer fns
        ("LLVM.i_add", FnType(params: [IntType, IntType], returns: IntBoolTupleType)), // overflowing intrinsic functions
        ("LLVM.i_sub", FnType(params: [IntType, IntType], returns: IntBoolTupleType)),
        ("LLVM.i_mul", FnType(params: [IntType, IntType], returns: IntBoolTupleType)),
        
        ("LLVM.i_div", FnType(params: [IntType, IntType], returns: IntType)),
        ("LLVM.i_rem", FnType(params: [IntType, IntType], returns: IntType)),
        
        ("LLVM.i_cmp_lt", FnType(params: [IntType, IntType], returns: BoolType)),
        ("LLVM.i_cmp_lte", FnType(params: [IntType, IntType], returns: BoolType)),
        ("LLVM.i_cmp_gt", FnType(params: [IntType, IntType], returns: BoolType)),
        ("LLVM.i_cmp_gte", FnType(params: [IntType, IntType], returns: BoolType)),
        ("LLVM.i_eq", FnType(params: [IntType, IntType], returns: BoolType)),
        ("LLVM.i_neq", FnType(params: [IntType, IntType], returns: BoolType)),
        
        // bool fns
        ("LLVM.b_and", FnType(params: [BoolType, BoolType], returns: BoolType)),
        ("LLVM.b_or", FnType(params: [BoolType, BoolType], returns: BoolType)),
        
        // float fns
        ("LLVM.f_add", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("LLVM.f_sub", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("LLVM.f_mul", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("LLVM.f_div", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        ("LLVM.f_rem", FnType(params: [DoubleType, DoubleType], returns: DoubleType)),
        
        ("LLVM.f_cmp_lt", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("LLVM.f_cmp_lte", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("LLVM.f_cmp_gt", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("LLVM.f_cmp_gte", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("LLVM.f_eq", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        ("LLVM.f_neq", FnType(params: [DoubleType, DoubleType], returns: BoolType)),
        
        // runtime fns
        ("_print", FnType(params: [IntType], returns: VoidType)),
        ("_print", FnType(params: [DoubleType], returns: VoidType)),
        ("_print", FnType(params: [BoolType], returns: VoidType)),
        ("_print", FnType(params: [Int32Type], returns: VoidType)),
        
        // intrinsic fns
        ("LLVM.trap", FnType(params: [], returns: VoidType))
    ]
    
    private static let functionContainer = FunctionContainer(functions: functions, types: [])

    /// Get a builtin function by name
    ///
    /// - parameter name: Unmangled name
    ///
    /// - parameter args: Applied arg types
    ///
    /// - returns: An optional tuple of `(mangledName, type)`
    ///
    static func getBuiltinFunction(name: String, argTypes args: [Ty]) -> (mangledName: String, type: FnType)? {
        return functionContainer[fn: name, types: args]
    }
}

