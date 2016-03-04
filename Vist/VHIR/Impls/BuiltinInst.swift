//
//  BuiltinInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class BuiltinBinaryInst: InstBase {
    let l: Operand, r: Operand

    override var type: Ty? { return l.type }
    let inst: BuiltinInst
    var instName: String { return inst.rawValue }
    
    private init(inst: BuiltinInst, l: Operand, r: Operand, irName: String? = nil) {
        self.inst = inst
        self.l = l
        self.r = r
        super.init()
        self.args = [l, r]
        self.irName = irName
    }
    
    override var instVHIR: String {
        let a = args.map{$0.valueName}
        let w = a.joinWithSeparator(", ")
        return "\(name) = \(instName) \(w) \(useComment)"
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