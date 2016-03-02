//
//  BuiltinInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class BuiltinBinaryInst: Inst {
    let l: Operand, r: Operand
    var irName: String?
    
    var uses: [Operand] = []
    var args: [Operand] { return [l, r] }
    var type: Ty? { return l.type }
    let inst: BuiltinInst
    var instName: String { return inst.rawValue }
    weak var parentBlock: BasicBlock?
    
    private init(inst: BuiltinInst, l: Operand, r: Operand, irName: String? = nil) {
        self.inst = inst
        self.l = l
        self.r = r
        self.irName = irName
    }
}

enum BuiltinInst: String {
    case iadd = "i_add", isub = "i_sub", imul = "i_mul"
}


extension Builder {
    
    func buildBuiltin(i: BuiltinInst, l: Operand, r: Operand, irName: String? = nil) throws -> BuiltinBinaryInst {
        let binInst = BuiltinBinaryInst(inst: i, l: l, r: r, irName: irName)
        try addToCurrentBlock(binInst)
        return binInst
    }
}