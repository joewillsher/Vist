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
 the LLVM constant folder statically fold expressions, as well as speeding up the resulting 
 code by reducing call/ret overhead
 
 The VIR:
 
 `%4 = call @-T-R_tII (%1: #Int, %3: #Int)`
 
 is expanded to:
 
 ```
 %4 = struct_extract %1: #Int, !value
 %5 = struct_extract %3: #Int, !value
 %i_xor = builtin i_xor %4: #Builtin.Int64, %5: #Builtin.Int64
 %6 = struct %I (%i_xor: #Builtin.Int64)
 ```
 */
enum StdLibInlinePass : OptimisationPass {
    
    typealias PassTarget = Module
    
    // Aggressive opt should only be enabled in -Ohigh
    static let minOptLevel: OptLevel = .high
    static let name = "stdlib-inline"
    
    // Run the opt -- called on each function by the pass manager
    static func run(on module: Module) throws  {
        
        for function in module.functions {
            
            for case let call as FunctionCallInst in function.instructions {
                
                /// Explode the call to a simple arithmetic op
                /// - parameter returnType: Specify the return type, if none specified then the input type is used
                ///                         as the return type
                func replaceWithBuiltin(_ inst: BuiltinInst, returnType: StructType? = nil) throws {
                    try call.replace { explosion in
                        let extracted = try call.args.map { arg in
                            try explosion.insert(inst: StructExtractInst(object: arg.value!, property: "value")) as Value
                        }
                        let virInst = try explosion.insert(inst: BuiltinInstCall(inst: inst, args: extracted, irName: inst.rawValue))
                        
                        let structType = try call.function.type.returns.getAsStructType()
                        explosion.insertTail(StructInitInst(type: returnType ?? structType, values: virInst, irName: call.irName))
                    }
                    OptStatistics.stdlibCallsInlined += 1
                }
                
                /// Explode the call to an overflow checking op
                func replaceWithOverflowCheckedBuiltin(_ inst: BuiltinInst) throws {
                    try call.replace { explosion in
                        let extracted = try call.args.map { arg in
                            try explosion.insert(inst: StructExtractInst(object: arg.value!, property: "value")) as Value
                        }
                        let virInst = try explosion.insert(inst: BuiltinInstCall(inst: inst, args: extracted, irName: inst.rawValue))
                        
                        let checkBit = try explosion.insert(inst: TupleExtractInst(tuple: virInst, index: 1, irName: "overflow"))
                        try explosion.insert(inst: BuiltinInstCall(inst: .condfail, args: [checkBit]))
                        
                        let structType = try call.function.type.returns.getAsStructType()
                        let val = try explosion.insert(inst: TupleExtractInst(tuple: virInst, index: 0, irName: "value"))
                        explosion.insertTail(StructInitInst(type: structType, values: val, irName: call.irName))
                    }
                    OptStatistics.overflowCheckedStdlibCallsInlined += 1
                }
                
                // Now we switch over the mangled function name, if its a stdlib
                // one we know how to explode, do it!
                
                switch call.function.name {
                case "-A_tII": // l * r
                    try replaceWithOverflowCheckedBuiltin(.imul)
                case "-P_tII": // l + r
                    try replaceWithOverflowCheckedBuiltin(.iadd)
                case "-M_tII": // l - r
                    try replaceWithOverflowCheckedBuiltin(.isub)
                case "-S_tII": // l / r
                    try replaceWithBuiltin(.idiv)
                case "-C_tII": // l % r
                    try replaceWithBuiltin(.irem)
                case "-T-R_tII": // l ~^ r
                    try replaceWithBuiltin(.ixor)
                case "-L-L_tII": // l << r
                    try replaceWithBuiltin(.ishl)
                case "-G-G_tII": // l >> r
                    try replaceWithBuiltin(.ishr)
                case "-T-N_tII": // l ~& r
                    try replaceWithBuiltin(.iand)
                case "-T-O_tII": // l ~| r
                    try replaceWithBuiltin(.ior)
                case "-T-R_tII": // l ~^ r
                    try replaceWithBuiltin(.ixor)
                    
                case "-L_tII": // l < r
                    try replaceWithBuiltin(.ilt, returnType: StdLib.boolType)
                case "-G_tII": // l > r
                    try replaceWithBuiltin(.igt, returnType: StdLib.boolType)
                case "-L-E_tII": // l <= r
                    try replaceWithBuiltin(.ilte, returnType: StdLib.boolType)
                case "-G-E_tII": // l >= r
                    try replaceWithBuiltin(.igte, returnType: StdLib.boolType)
                case "-E-E_tII": // l == r
                    try replaceWithBuiltin(.ieq, returnType: StdLib.boolType)
                case "-B-E_tII": // l != r
                    try replaceWithBuiltin(.ineq, returnType: StdLib.boolType)
                    
                case "-N-N_tBB": // l && r
                    try replaceWithBuiltin(.and, returnType: StdLib.boolType)
                case "-O-O_tBB": // l || r
                    try replaceWithBuiltin(.or, returnType: StdLib.boolType)
                    
                default:
                    break // not a stdlib function so we're done
                }
                
            }
        }
        
    }
}

extension OptStatistics {
    static var stdlibCallsInlined = 0
    static var overflowCheckedStdlibCallsInlined = 0
}


/*
 So the vist
 ```
 func add :: Int Int -> Int = (a b) do return a + b
 ```
 
 instead of becoming
 ```
 _add_tII:                               ## @add_tII
	.cfi_startproc
 ## BB#0:                                ## %entry
	pushq	%rbp
 Ltmp6:
	.cfi_def_cfa_offset 16
 Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
 Ltmp8:
	.cfi_def_cfa_register %rbp
	callq	"_-P_tII"                   ## FUNCTION CALL TO _-P_tII
	popq	%rbp
	retq
	.cfi_endproc
 ```
 
 becomes
 
 ```
 _add_tII:                               ## @add_tII
 ## BB#0:                                ## %entry
	pushq	%rbp
	movq	%rsp, %rbp
	addq	%rsi, %rdi
	seto	%al
	movq	%rdi, -8(%rbp)          ## 8-byte Spill
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jo	LBB2_2
 ## BB#1:                                ## %entry.cont
	movq	-8(%rbp), %rax          ## 8-byte Reload
	popq	%rbp
	retq
 LBB2_2:                                 ## %add.trap
	ud2
 ```
 */



