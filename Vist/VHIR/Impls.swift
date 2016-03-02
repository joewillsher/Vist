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
    var type: Ty?
    var instName: String = "return"
    weak var parentBlock: BasicBlock?
    
    init(value: Operand, parentBlock: BasicBlock?, irName: String? = nil) {
        self.value = value
        self.irName = irName
        self.parentBlock = parentBlock
    }    
}

final class IntLiteralInst: Inst {
    var value: IntLiteralValue
    
    var irName: String?
    var type: Ty? { return BuiltinType.int(size: 64) }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    var instName: String = "integer_literal"
    
    init(val: Int, irName: String? = nil) {
        self.value = IntLiteralValue(val: val)
        self.irName = irName
    }
}

final class StructInitInst: Inst {
    var args: [Operand]
    
    var irName: String?
    var type: Ty? { return module?.getOrAddType(structType) }
    var structType: StructType
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    var instName: String = "struct"
    
    init(type: StructType, args: [Operand], irName: String? = nil) {
        self.args = args
        self.irName = irName
        self.structType = type
    }
}

final class VariableInst: Inst {
    var value: Operand
    //var ownership: [OwnershipAttrs] // specify ref/val semantics
    // also memory management info stored
    
    var irName: String?
    var type: Ty?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    var instName: String = "variable_decl"
    
    init(value: Operand, irName: String? = nil) {
        self.value = value
        self.type = value.type
        self.irName = irName
    }
}


final class VoidValue: Value {
    var type: Ty? { return BuiltinType.void }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    var irName: String? = nil
    
    var name: String {
        get { return "()" }
        set { }
    }
}
final class IntLiteralValue: Value {
    var value: Int
    
    var irName: String?
    var type: Ty? { return BuiltinType.int(size: 64) }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(val: Int, irName: String? = nil) {
        self.value = val
        self.irName = irName
    }
}
