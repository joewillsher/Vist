//
//  Folding.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 ## Constant folding for builtin instructions on literals.
 
 By this point in the optimisation pipeline we have inlined calls & simplified
 many struct/memory instructions -- here we statically evaluate builtin instructions
 which work on literals.
 
 ***
 ### Example
 
 ```
 %0 = int_literal 1
 %1 = int_literal 2
 %i_add = builtin i_add %0: #Builtin.Int64, %1: #Builtin.Int64
 %overflow = tuple_extract %i_add: (#Builtin.Int64, #Builtin.Bool), !1
 cond_fail %overflow: #Builtin.Bool
 %value = tuple_extract %i_add: (#Builtin.Int64, #Builtin.Bool), !0
 %3 = struct %Int, (%value: #Builtin.Int64)
 ```
 becomes
 ```
 %0 = int_literal 3
 %1 = struct %Int, (%0: #Builtin.Int64)
 ```
 This is because the `builtin i_add` inst takes 2 literals, so we can 
 replace its uses with (3, false). This pass propagates the `3` and the
 `false` to the `cond_fail` and the `struct` init inst which allow it to
 remove the overflow check completely.
 */
enum ConstantFoldingPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    static let name = "const-fold"
    
    static func run(on function: Function) throws {
        
        for case let inst as BuiltinInstCall in function.instructions {
            let block = inst.parentBlock!
            
            switch inst.inst {
            case .iadd, .isub, .imul:
                guard
                    case let lhs as IntLiteralInst = inst.args[0].value,
                    case let rhs as IntLiteralInst = inst.args[1].value else { break }
                
                // get the value & whether it overflowed
                let (val, overflow): (Int, Bool)
                switch inst.inst {
                case .iadd: (val, overflow) = Int.addWithOverflow(lhs.value, rhs.value)
                case .isub: (val, overflow) = Int.subtractWithOverflow(lhs.value, rhs.value)
                case .imul: (val, overflow) = Int.multiplyWithOverflow(lhs.value, rhs.value)
                default: fatalError("not an int overflowing arithmetic inst")
                }
                
                // add replacement literals
                let literalVal = IntLiteralInst(val: val, size: 64)
                try block.insert(inst: literalVal, after: inst)
                let literalOverflow = BoolLiteralInst(val: overflow)
                try block.insert(inst: literalOverflow, after: inst)
                
                OptStatistics.overflowingArithmeticOpsFolded += 1
                
                // All uses must be tuple extracts
                guard let uses = inst.uses.optionalMap({ $0.user as? TupleExtractInst }) else {
                    // if the tuple is used directly (for some reason?) we construct 
                    // a literal tuple to pass in
                    let tuple = TupleCreateInst(type:
                        TupleType(members: [StdLib.intType, StdLib.boolType]),
                                  elements: [literalVal, literalOverflow])
                    try block.insert(inst: tuple, after: inst)
                    try inst.eraseFromParent(replacingAllUsesWith: tuple)
                    break
                }
                
                // Replace overflow check uses to check a literal
                let overflowUses = uses.filter { $0.elementIndex == 1 }
                for overflowCheck in overflowUses {
                    try overflowCheck.eraseFromParent(replacingAllUsesWith: literalOverflow)
                }
                // Replace users extracting the value with a literal
                let valueUses = uses.filter { $0.elementIndex == 0 }
                for valueInst in valueUses {
                    try valueInst.eraseFromParent(replacingAllUsesWith: literalVal)
                }
                
                OptStatistics.arithmeticOpsFolded += 1
                
            case .condfail:
                guard case let cond as BoolLiteralInst = inst.args[0].value else { break }
                
                // if it always overflows, replace with a trap
                if cond.value {
                    let trap = BuiltinInstCall.trapInst()
                    try block.insert(inst: trap, after: inst)
                    try inst.eraseFromParent()
                }
                // or remove if it is always false
                else {
                    try inst.eraseFromParent()
                }
                OptStatistics.overflowChecksFolded += 1
                
            case .ilte, .ilt, .igte, .igt, .ieq, .ineq:
                guard
                    case let lhs as IntLiteralInst = inst.args[0].value,
                    case let rhs as IntLiteralInst = inst.args[1].value else { break }
                assert(lhs.size == rhs.size)
                
                let op: (Int, Int) -> Bool
                switch inst.inst {
                case .ilte: op = (<=)
                case .ilt: op = (<)
                case .igte: op = (>=)
                case .igt: op = (>)
                case .ieq: op = (==)
                case .ineq: op = (!=)
                default: fatalError("Not an int comparison inst")
                }
                
                let resultLiteral = BoolLiteralInst(val: op(lhs.value, rhs.value))
                try block.insert(inst: resultLiteral, after: inst)
                try inst.eraseFromParent(replacingAllUsesWith: resultLiteral)
                
                OptStatistics.arithmeticOpsFolded += 1
                
            case .ishl, .ishr, .iand, .ixor, .ior, .idiv, .irem, .iaddunchecked, .ipow:
                guard
                    case let lhs as IntLiteralInst = inst.args[0].value,
                    case let rhs as IntLiteralInst = inst.args[1].value else { break }
                assert(lhs.size == rhs.size)
                
                let op: (Int, Int) -> Int
                switch inst.inst {
                case .idiv: op = (/)
                case .irem: op = (%)
                case .ipow: op = { Int(pow(Double($0), Double($1))) }
                case .ishl: op = (<<)
                case .ishr: op = (>>)
                case .iand: op = (&)
                case .ior:  op = (|)
                case .ixor: op = (^)
                case .iaddunchecked: op = (&+)
                default: fatalError("Not a trunc inst")
                }
                
                let resultLiteral = IntLiteralInst(val: op(lhs.value, rhs.value), size: lhs.size)
                try block.insert(inst: resultLiteral, after: inst)
                try inst.eraseFromParent(replacingAllUsesWith: resultLiteral)
                
                OptStatistics.arithmeticOpsFolded += 1
                
            case .trunc8, .trunc16, .trunc32:
                guard case let val as IntLiteralInst = inst.args[0].value else { break }
                
                let size: Int
                switch inst.inst {
                case .trunc8: size = 8
                case .trunc16: size = 16
                case .trunc32: size = 32
                default: fatalError("Not an int inst")
                }
                let literal = IntLiteralInst(val: val.value, size: size)
                try block.insert(inst: literal, after: inst)
                try inst.eraseFromParent(replacingAllUsesWith: literal)
                
                OptStatistics.arithmeticOpsFolded += 1
                
            default:
                break // not implemented
            }
        }
    }
}

extension OptStatistics {
    static var overflowingArithmeticOpsFolded = 0
    static var arithmeticOpsFolded = 0
    static var overflowChecksFolded = 0
}

