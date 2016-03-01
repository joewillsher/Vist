//
//  Impls.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



final class BBParam: Value {
    var irName: String?
    var type: Ty?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(irName: String, type: Ty) {
        self.irName = irName
        self.type = type
    }
}

final class BuiltinBinaryInst: Inst {
    let l: Operand, r: Operand
    var irName: String?
    
    var uses: [Operand] = []
    var args: [Operand] { return [l, r] }
    var type: Ty? { return l.type }
    let inst: BuiltinInst
    var instName: String { return inst.rawValue }
    weak var parentBlock: BasicBlock?
    
    init(inst: BuiltinInst, l: Operand, r: Operand, irName: String? = nil) {
        self.inst = inst
        self.l = l
        self.r = r
        self.irName = irName
    }
}

enum BuiltinInst: String {
    case iadd = "i_add", isub = "i_sub", imul = "i_mul"
}

final class ReturnInst: Inst {
    var value: Operand
    var irName: String?
    
    var uses: [Operand] = []
    var args: [Operand] { return [value] }
    var type: Ty?
    var instName: String = "return"
    weak var parentBlock: BasicBlock?
    
    init(value: Operand, parentBlock: BasicBlock?) {
        self.value = value
        self.parentBlock = parentBlock
    }
    
    var vhir: String {
        return "return %\(value.name)"
    }
    
}


final class IntValue: Value {
    var irName: String?
    var type: Ty? { return BuiltinType.int(size: 32) }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(irName: String, parentBlock: BasicBlock?) {
        self.irName = irName
        self.parentBlock = parentBlock
    }
}
