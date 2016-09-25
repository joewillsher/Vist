//
//  Builtin.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// The builtin functions
struct Builtin {
    static let intType = BuiltinType.int(size: 64)
    static let int32Type = BuiltinType.int(size: 32)
    static let int16Type = BuiltinType.int(size: 16)
    static let int8Type = BuiltinType.int(size: 8)
    static let doubleType = BuiltinType.float(size: 64)
    static let boolType = BuiltinType.bool
    static let voidType = BuiltinType.void
    static let opaquePointerType = BuiltinType.opaquePointer
    
    static let intBoolTupleType = TupleType(members: [intType, boolType])
    
    private static let functions: [(String, FunctionType)] = [
        // integer fns
        ("Builtin.i_add", FunctionType(params: [intType, intType], returns: intBoolTupleType)), // overflowing intrinsic functions
        ("Builtin.i_sub", FunctionType(params: [intType, intType], returns: intBoolTupleType)),
        ("Builtin.i_mul", FunctionType(params: [intType, intType], returns: intBoolTupleType)),
        
        ("Builtin.i_div", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_rem", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_add_unchecked", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_mul_overflow", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_pow", FunctionType(params: [intType, intType], returns: intType)),
        
        ("Builtin.i_shr", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_shl", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_and", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_or", FunctionType(params: [intType, intType], returns: intType)),
        ("Builtin.i_xor", FunctionType(params: [intType, intType], returns: intType)),

        ("Builtin.i_cmp_lt", FunctionType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_cmp_lte", FunctionType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_cmp_gt", FunctionType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_cmp_gte", FunctionType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_eq", FunctionType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_neq", FunctionType(params: [intType, intType], returns: boolType)),
        
        // bool fns
        ("Builtin.b_and", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("Builtin.b_or", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("Builtin.b_eq", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("Builtin.b_neq", FunctionType(params: [boolType, boolType], returns: boolType)),
        ("Builtin.b_not", FunctionType(params: [boolType], returns: boolType)),
        
        // float fns
        ("Builtin.f_add", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_sub", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_mul", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_div", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_rem", FunctionType(params: [doubleType, doubleType], returns: doubleType)),
        
        ("Builtin.f_cmp_lt", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_cmp_lte", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_cmp_gt", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_cmp_gte", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_eq", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_neq", FunctionType(params: [doubleType, doubleType], returns: boolType)),
        
        // intrinsic fns
        ("Builtin.trap", FunctionType(params: [], returns: voidType)),
        ("Builtin.cond_fail", FunctionType(params: [boolType], returns: voidType)),
        ("Builtin.expect", FunctionType(params: [boolType, boolType], returns: boolType)),
        
        ("Builtin.stack_alloc", FunctionType(params: [intType], returns: opaquePointerType)),
        ("Builtin.heap_alloc", FunctionType(params: [intType], returns: opaquePointerType)),
        ("Builtin.mem_copy", FunctionType(params: [opaquePointerType, opaquePointerType, intType], returns: voidType)),
        ("Builtin.advance_pointer", FunctionType(params: [opaquePointerType, intType], returns: opaquePointerType)),
        ("Builtin.opaque_load", FunctionType(params: [opaquePointerType], returns: BuiltinType.int(size: 8))),
        ("Builtin.opaque_store", FunctionType(params: [opaquePointerType, int8Type], returns: voidType)),
        ("Builtin.heap_free", FunctionType(params: [opaquePointerType], returns: voidType)),
        
        ("Builtin.with_ptr", FunctionType(params: [StdLib.anyConcept], returns: opaquePointerType)),
        
        ("Builtin.trunc_int_8", FunctionType(params: [intType], returns: int8Type)),
        ("Builtin.trunc_int_8", FunctionType(params: [int32Type], returns: int8Type)),
        ("Builtin.trunc_int_8", FunctionType(params: [int16Type], returns: int8Type)),
        ("Builtin.trunc_int_16", FunctionType(params: [intType], returns: int16Type)),
        ("Builtin.trunc_int_16", FunctionType(params: [int32Type], returns: int16Type)),
        ("Builtin.trunc_int_32", FunctionType(params: [intType], returns: int32Type)),
    ]
    
    private static let functionContainer = FunctionContainer(functions: functions, types: [])

    /// Get a builtin function by name
    /// - parameter name: Unmangled name
    /// - parameter args: Applied arg types
    /// - returns: An optional tuple of `(mangledName, type)`
    static func function(name: String, argTypes args: [Type], solver: ConstraintSolver) -> Solution? {
        return functionContainer.lookupFunction(named: name, argTypes: args, solver: solver)
    }
}

