//
//  BuiltinInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class BuiltinBinaryInst: InstBase {
    let l: Operand, r: Operand

    override var type: Ty? { return returnType }
    let inst: BuiltinInst
    var instName: String { return inst.rawValue }
    var returnType: Ty
    
    private init(inst: BuiltinInst, l: Operand, r: Operand, returnType: Ty, irName: String? = nil) {
        self.inst = inst
        self.l = l
        self.r = r
        self.returnType = returnType
        super.init()
        self.args = [l, r]
        self.irName = irName
    }
    
    override var instVHIR: String {
        let a = args.map{$0.valueName}
        let w = a.joinWithSeparator(", ")
        return "\(name) = builtin \(instName) \(w) \(useComment)"
    }
    
}

enum BuiltinInst: String {
    case iadd = "i_add", isub = "i_sub", imul = "i_mul"
}


extension Builder {
    
    func buildBuiltin(i: BuiltinInst, l: Operand, r: Operand, returnType: Ty, irName: String? = nil) throws -> BuiltinBinaryInst {
        let binInst = BuiltinBinaryInst(inst: i, l: l, r: r, returnType: returnType, irName: irName)
        try addToCurrentBlock(binInst)
        return binInst
    }
}