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
    static let doubleType = BuiltinType.float(size: 64)
    static let boolType = BuiltinType.bool
    static let voidType = BuiltinType.void
    static let opaquePointerType = BuiltinType.opaquePointer
    
    static let intBoolTupleType = TupleType(members: [intType, boolType])
    
    private static let functions: [(String, FnType)] = [
        // integer fns
        ("Builtin.i_add", FnType(params: [intType, intType], returns: intBoolTupleType)), // overflowing intrinsic functions
        ("Builtin.i_sub", FnType(params: [intType, intType], returns: intBoolTupleType)),
        ("Builtin.i_mul", FnType(params: [intType, intType], returns: intBoolTupleType)),
        
        ("Builtin.i_div", FnType(params: [intType, intType], returns: intType)),
        ("Builtin.i_rem", FnType(params: [intType, intType], returns: intType)),
        
        ("Builtin.i_shr", FnType(params: [intType, intType], returns: intType)),
        ("Builtin.i_shl", FnType(params: [intType, intType], returns: intType)),
        ("Builtin.i_and", FnType(params: [intType, intType], returns: intType)),
        ("Builtin.i_or", FnType(params: [intType, intType], returns: intType)),
        ("Builtin.i_xor", FnType(params: [intType, intType], returns: intType)),

        ("Builtin.i_cmp_lt", FnType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_cmp_lte", FnType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_cmp_gt", FnType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_cmp_gte", FnType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_eq", FnType(params: [intType, intType], returns: boolType)),
        ("Builtin.i_neq", FnType(params: [intType, intType], returns: boolType)),
        
        // bool fns
        ("Builtin.b_and", FnType(params: [boolType, boolType], returns: boolType)),
        ("Builtin.b_or", FnType(params: [boolType, boolType], returns: boolType)),
        
        // float fns
        ("Builtin.f_add", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_sub", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_mul", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_div", FnType(params: [doubleType, doubleType], returns: doubleType)),
        ("Builtin.f_rem", FnType(params: [doubleType, doubleType], returns: doubleType)),
        
        ("Builtin.f_cmp_lt", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_cmp_lte", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_cmp_gt", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_cmp_gte", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_eq", FnType(params: [doubleType, doubleType], returns: boolType)),
        ("Builtin.f_neq", FnType(params: [doubleType, doubleType], returns: boolType)),
                
        // intrinsic fns
        ("Builtin.trap", FnType(params: [], returns: voidType)),
        ("Builtin.cond_fail", FnType(params: [boolType], returns: voidType)),
        ("Builtin.expect", FnType(params: [boolType, boolType], returns: boolType)),
        
        ("Builtin.stack_alloc", FnType(params: [intType], returns: opaquePointerType)),
        ("Builtin.heap_alloc", FnType(params: [intType], returns: opaquePointerType)),
        ("Builtin.mem_copy", FnType(params: [opaquePointerType, opaquePointerType, intType], returns: voidType)),
        ("Builtin.advance_pointer", FnType(params: [opaquePointerType, intType], returns: opaquePointerType)),
        ("Builtin.opaque_load", FnType(params: [opaquePointerType], returns: BuiltinType.int(size: 8))),
    ]
    
    private static let functionContainer = FunctionContainer(functions: functions, types: [])

    /// Get a builtin function by name
    /// - parameter name: Unmangled name
    /// - parameter args: Applied arg types
    /// - returns: An optional tuple of `(mangledName, type)`
    static func functionNamed(name: String, argTypes args: [Ty]) -> (mangledName: String, type: FnType)? {
        return functionContainer[fn: name, types: args]
    }
}

