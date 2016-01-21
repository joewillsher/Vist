//
//  BuiltinDef.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct BuiltinDef {
    
    private static let builtinBinaryWithOverflowFunctions = [
        "LLVM.i_add": "llvm.sadd.with.overflow",
        "LLVM.i_sub": "llvm.ssub.with.overflow",
        "LLVM.i_mul": "llvm.smul.with.overflow"
    ]
    private static let builtinBinaryFunctions: [String: (BuiltinType, BuiltinType)] = [
        "LLVM.i_div": (.Int(size: 64), .Int(size: 64)),
        "LLVM.i_rem": (.Int(size: 64), .Int(size: 64)),

        "LLVM.i_cmp_lt": (.Int(size: 64), .Bool),
        "LLVM.i_cmp_lte": (.Int(size: 64), .Bool),
        "LLVM.i_cmp_gt": (.Int(size: 64), .Bool),
        "LLVM.i_cmp_gte": (.Int(size: 64), .Bool),
        "LLVM.i_eq": (.Int(size: 64), .Bool),
        "LLVM.i_neq": (.Int(size: 64), .Bool),

        
        "LLVM.b_and": (.Bool, .Bool),
        "LLVM.b_or": (.Bool, .Bool),
        
        
        "LLVM.f_add": (.Float(size: 64), .Float(size: 64)),
        "LLVM.f_sub": (.Float(size: 64), .Float(size: 64)),
        "LLVM.f_mul": (.Float(size: 64), .Float(size: 64)),
        "LLVM.f_div": (.Float(size: 64), .Float(size: 64)),
        "LLVM.f_rem": (.Float(size: 64), .Float(size: 64)),
        
        "LLVM.f_cmp_lt": (.Float(size: 64), .Bool),
        "LLVM.f_cmp_lte": (.Float(size: 64), .Bool),
        "LLVM.f_cmp_gt": (.Float(size: 64), .Bool),
        "LLVM.f_cmp_gte": (.Float(size: 64), .Bool),
        "LLVM.f_eq": (.Float(size: 64), .Bool),
        "LLVM.f_neq": (.Float(size: 64), .Bool)
    ]
    private static let runtimeFunctions: [String: (BuiltinType, BuiltinType)] = [
        "_print".mangle([BuiltinType.Int(size: 64)])    : (.Int(size: 64), .Void),
        "_print".mangle([BuiltinType.Bool])             : (.Bool, .Void),
        "_print".mangle([BuiltinType.Float(size: 64)])  : (.Float(size: 64), .Void),
        "_print".mangle([BuiltinType.Float(size: 32)])  : (.Float(size: 32), .Void)
    ]
    private static let intrinsicFunctions: [String: (BuiltinType, BuiltinType)] = [
        "LLVM.trap": (.Void, .Void)
    ]
    
    private static func getBinaryOperationWithOverflow(type: BuiltinType) -> FnType {
        let args = [type, type] as [Ty]
        let res = [type, BuiltinType.Bool] as [Ty]
        let resTuple = TupleType(members: res)
        return FnType(params: args, returns: resTuple)
    }
    private static func getBinaryOperation(param: BuiltinType, res: BuiltinType) -> FnType {
        let args = [param, param] as [Ty]
        return FnType(params: args, returns: res)
    }
    private static func getFunction(param: BuiltinType, res: BuiltinType) -> FnType {
        return FnType(params: [param], returns: res)
    }
    
    
    static func getBuiltinFunction(id: String, args: [Ty]) -> (String, FnType)? {
        
        if args.count == 2 && args[0] == args[1] {
            guard case let type as BuiltinType = args[0] else { return nil }
            
            if let name = builtinBinaryWithOverflowFunctions[id] {
                return (name, getBinaryOperationWithOverflow(type))
            }
            else if let (p, r) = builtinBinaryFunctions[id] {
                return (id, getBinaryOperation(p, res: r))
            }
        }
        else if args.count <= 1 {
            
            if let (p, r) = runtimeFunctions[id.mangle(args)] {
                return (id, getFunction(p, res: r))
            }
            else if let (p, r) = intrinsicFunctions[id] {
                return (id, getFunction(p, res: r))
            }
        }
        
        
        return nil
    }
    
}

