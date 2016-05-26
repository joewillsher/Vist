//
//  StdLibInline.swift
//  Vist
//
//  Created by Josef Willsher on 26/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/**
 An optimisation pass to inline simple stdlib functions.
 
 Operators in vist are implemented in the stdlib, which stops the compiler inlining them.
 Here we manually convert a function call to a bunch of operators to their VIR. This lets 
 the LLVM constant folder statically fold expressions
 
 `%4 = call @-T-R_tII (%1: #Int, %3: #Int)`
 
 becomes
 
 ```
 %4 = struct_extract %1: #Int, !value
 %5 = struct_extract %3: #Int, !value
 %i_xor = builtin i_xor %4: #Builtin.Int64, %5: #Builtin.Int64
 %6 = struct %I (%i_xor: #Builtin.Int64)
 ```
 */
struct StdLibInlinePass : OptimisationPass {
    
    static var minOptLevel: OptLevel = .high
    
    func runOn(function: Function) throws {
        
        for case let call as FunctionCallInst in function.instructions {
            
            func replaceWithBuiltin(inst: BuiltinInst, elType: BuiltinType) throws {
                try call.replace { explosion in
                    let structType = try call.function.type.returns.getAsStructType()
                    let extracted = call.args.map { arg in
                        explosion.insert(StructExtractInst(object: arg, property: "value", propertyType: elType, structType: structType))
                    }
                    let virInst = explosion.insert(BuiltinInstCall(inst: inst, args: extracted, irName: inst.rawValue)!)
                    
                    explosion.insert(StructInitInst(type: structType, args: [virInst], irName: call.irName))
                }
            }
            
            func replaceWithOverflowCheckedBuiltin(inst: BuiltinInst, elType: BuiltinType) throws {
                try call.replace { explosion in
                    let structType = try call.function.type.returns.getAsStructType()
                    let extracted = call.args.map { arg in
                        explosion.insert(StructExtractInst(object: arg, property: "value", propertyType: elType, structType: structType))
                    }
                    let virInst = explosion.insert(BuiltinInstCall(inst: inst, args: extracted, irName: inst.rawValue)!)
                    
                    let checkBit = explosion.insert(TupleExtractInst(tuple: virInst, index: 1, elementType: BuiltinType.bool, irName: "overflow"))
                    explosion.insert(BuiltinInstCall(inst: .condfail, args: [checkBit])!)
                    
                    let val = explosion.insert(TupleExtractInst(tuple: virInst, index: 0, elementType: elType, irName: "value"))
                    explosion.insert(StructInitInst(type: structType, args: [val], irName: call.irName))
                }
            }
            
            switch call.function.name {
            case "-A_tII": // l * r
                try replaceWithOverflowCheckedBuiltin(.imul, elType: .int(size: 64))
            case "-P_tII": // l + r
                try replaceWithOverflowCheckedBuiltin(.iadd, elType: .int(size: 64))
            case "-M_tII": // l - r
                try replaceWithOverflowCheckedBuiltin(.isub, elType: .int(size: 64))
            case "-T-R_tII": // l ~^ r
                try replaceWithBuiltin(.ixor, elType: .int(size: 64))
            case "-L-L_tII": // l << r
                try replaceWithBuiltin(.ishl, elType: .int(size: 64))
            case "-G-G_tII": // l >> r
                try replaceWithBuiltin(.ishr, elType: .int(size: 64))
            case "-T-N_tII": // l ~^ r
                try replaceWithBuiltin(.iand, elType: .int(size: 64))
            case "-T-O_tII": // l ~| r
                try replaceWithBuiltin(.ior, elType: .int(size: 64))
            default:
                break // not a stdlib function
            }
            
        }
    }
}



