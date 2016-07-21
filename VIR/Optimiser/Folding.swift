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
                
                let (val, overflow) = try foldOverflowingArithmeticOperation(inst.inst,
                                                                             lhs: lhs.value.value, rhs: rhs.value.value)
                // All uses must be tuple extracts
                guard let uses = inst.uses.optionalMap(transform: { $0.user as? TupleExtractInst }) else { break }
                
                let overflowUses = uses.filter { $0.elementIndex == 1 }
                let valueUses = uses.filter { $0.elementIndex == 0 }
                
                for overflowCheck in overflowUses {
                    let literal = BoolLiteralInst(val: overflow)
                    try block.insert(inst: literal, after: overflowCheck)
                    try overflowCheck.eraseFromParent(replacingAllUsesWith: literal)
                }
                for valueInst in valueUses {
                    let literal = IntLiteralInst(val: val, size: 64)
                    try block.insert(inst: literal, after: valueInst)
                    try valueInst.eraseFromParent(replacingAllUsesWith: literal)
                }
                
            case .condfail:
                guard case let cond as BoolLiteralInst = inst.args[0].value else { break }
                
                // if it always overflows, replace with a trap
                if cond.value.value {
                    let trap = try BuiltinInstCall(inst: .trap, args: [])
                    try block.insert(inst: trap, after: inst)
                    try inst.eraseFromParent()
                }
                // or remove if it is always false
                else {
                    try inst.eraseFromParent()
                }
                
            default:
                break // not implemented
            }
        }
    }
    
    private static func foldOverflowingArithmeticOperation(_ op: BuiltinInst, lhs: Int, rhs: Int) throws -> (Int, overflow: Bool) {
        switch op {
        case .iadd: return Int.addWithOverflow(lhs, rhs)
        case .isub: return Int.subtractWithOverflow(lhs, rhs)
        case .imul: return Int.multiplyWithOverflow(lhs, rhs)
        default: preconditionFailure("not an overflowing inst call")
        }
    }

}

