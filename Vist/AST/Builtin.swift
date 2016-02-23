//
//  Builtin.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct Builtin {

    private static let intType = BuiltinType.int(size: 64)
    private static let int32Type = BuiltinType.int(size: 32)
    private static let doubleType = BuiltinType.float(size: 64)
    private static let boolType = BuiltinType.bool
    private static let voidType = BuiltinType.void
    
    static let IntBoolTupleType = TupleType(members: [intType, boolType])
    
    private static let functions: [(String, FnType)] = [
        // integer fns
        ("LLVM.i_add", FnType(params: [intType, intType], returns: IntBoolTupleType)), // overflowing intrinsic functions
        ("LLVM.i_sub", FnType(params: [intType, intType], returns: IntBoolTupleType)),
        ("LLVM.i_mul", FnType(params: [intType, intType], returns: IntBoolTupleType)),
        
        ("LLVM.i_div", FnType(params: [intType, intType], returns: intType)),
        ("LLVM.i_rem", FnType(params: [intType, intType], returns: intType)),
        
        ("LLVM.i_shr", FnType(params: [intType, intType], returns: intType)),
        ("LLVM.i_shl", FnType(params: [intType, intType], returns: intType)),
        ("LLVM.i_and", FnType(params: [intType, intType], returns: intType)),
        ("LLVM.i_or", FnType(params: [intType, intType], returns: intType)),
        ("LLVM.i_xor", FnType(params: [intType, intType], returns: intType)),

        ("LLVM.i_cmp_lt", FnType(params: [intType, intType], returns: boolType)),
        ("LLVM.i_cmp_lte", FnType(params: [intType, intType], returns: boolType)),
        ("LLVM.i_cmp_gt", FnType(params: [intType, intType], returns: boolType)),
        ("LLVM.i_cmp_gte", FnType(params: [intType, intType], returns: boolType)),
        ("LLVM.i_eq", FnType(params: [intType, intType], returns: boolType)),
        ("LLVM.i_neq", FnType(params: [intType, intType], returns: boolType)),
        
        // bool fns
        ("LLVM.b_and", FnType(params: [boolType, boolType], returns: boolType)),
        ("LLVM.b_or", FnType(params: [boolType, boolType], returns: boolType)),
        
        // float fns
        ("LLVM.f_add", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("LLVM.f_sub", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("LLVM.f_mul", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("LLVM.f_div", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("LLVM.f_rem", FnType(params: [doubleType, doubleType], returns: doubleType)),
        
        ("LLVM.f_cmp_lt", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("LLVM.f_cmp_lte", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("LLVM.f_cmp_gt", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("LLVM.f_cmp_gte", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("LLVM.f_eq", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("LLVM.f_neq", FnType(params: [doubleType, doubleType], returns: boolType)),
        
        // runtime fns
        ("_print", FnType(params: [intType], returns: voidType)),
        ("_print", FnType(params: [doubleType], returns: voidType)),
        ("_print", FnType(params: [boolType], returns: voidType)),
        ("_print", FnType(params: [int32Type], returns: voidType)),
        
        // intrinsic fns
        ("LLVM.trap", FnType(params: [], returns: voidType)),
        ("LLVM.expect", FnType(params: [boolType, boolType], returns: boolType))
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

