//
//  Impls.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol Type: VHIR {
}

final class BBParam: Value {
    var irName: String?
    var type: Type?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(irName: String, type: Type) {
        self.irName = irName
        self.type = type
    }
}

final class IntType: Type {
    let size: Int
    
    init(size: Int) { self.size = size }
}
final class FunctionType: Type {
    let params: [Type], returns: Type
    
    init(params: [Type], returns: Type) {
        self.params = params
        self.returns = returns
    }
}

final class BinaryInst: Inst {
    let l: Operand, r: Operand
    var irName: String?
    
    var uses: [Operand] = []
    var args: [Operand] { return [l, r] }
    var type: Type? { return l.type }
    let instName: String
    weak var parentBlock: BasicBlock?
    
    init(name: String, l: Operand, r: Operand, irName: String? = nil) {
        self.instName = name
        self.l = l
        self.r = r
        self.irName = irName
    }
}

final class ReturnInst: Inst {
    var value: Operand
    var irName: String?
    
    var uses: [Operand] = []
    var args: [Operand] { return [value] }
    var type: Type? = nil
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
    var type: Type? { return IntType(size: 64) }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(irName: String, parentBlock: BasicBlock?) {
        self.irName = irName
        self.parentBlock = parentBlock
    }
}
