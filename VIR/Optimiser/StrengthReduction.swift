//
//  StrengthReduction.swift
//  Vist
//
//  Created by Josef Willsher on 12/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum StrengthReductionPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    static let name = "strength-reduce"
    
    static func run(on function: Function) throws {
        for block in function.dominator.analysis {
            for case let inst as BuiltinInstCall in block.instructions {
                switch inst.inst {
                case .idiv:
                    guard case let literal as IntLiteralInst = inst.args[1].value, literal.value.isPowerOf2 else {
                        continue
                    }
                    let shval = IntLiteralInst(val: Int(log2(Double(literal.value))), size: literal.size)
                    let newCall = try BuiltinInstCall(inst: .ishr, args: [inst.args[0].value!, shval])
                    
                    try block.insert(inst: shval, after: inst)
                    try block.insert(inst: newCall, after: inst)
                    try inst.eraseFromParent(replacingAllUsesWith: newCall)
                    
                case .imul:
                    // TODO: commutative
                    guard case let literal as IntLiteralInst = inst.args[1].value, literal.value.isPowerOf2 else {
                        continue
                    }
                    let shval = IntLiteralInst(val: Int(log2(Double(literal.value))), size: literal.size)
                    let newCall = try BuiltinInstCall(inst: .ishl, args: [inst.args[0].value!, shval])
                    
                    try block.insert(inst: shval, after: inst)
                    try block.insert(inst: newCall, after: inst)
                    try inst.eraseFromParent(replacingAllUsesWith: newCall)
                    
                case .ipow:
                    guard case let literal as IntLiteralInst = inst.args[1].value else {
                        continue
                    }
                    switch literal.value {
                    case 0:
                        let one = IntLiteralInst(val: 1, size: literal.size)
                        try block.insert(inst: one, after: inst)
                        try inst.eraseFromParent(replacingAllUsesWith: one)
                    case 1:
                        try inst.eraseFromParent(replacingAllUsesWith: inst.args[0].value)
                    default:
                        break
                    }
                    
                default:
                    break
                }
            }
        }
    }
}

private extension Int {
    var isPowerOf2: Bool {
        guard self > 0 else { return false }
        var v = self
        while v & 1 == 0 { v >>= 1 }
        return v == 0
    }
}

