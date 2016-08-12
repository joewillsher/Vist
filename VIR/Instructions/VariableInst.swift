//
//  VariableInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class VariableInst : Inst {
    var value: Operand
    //var attrs: [OwnershipAttrs] // specify ref/val semantics
    // also memory management info stored
    
    var uses: [Operand] = []
    var args: [Operand]
    
    var type: Type? { return value.type }
    
    convenience init(value: Value, irName: String? = nil) {
        self.init(operand: Operand(value), irName: irName)
    }
    private init(operand: Operand, irName: String?) {
        self.value = operand
        self.args = [operand]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "variable_decl \(name) = \(value.valueName)\(useComment)"
    }
    
    func setArgs(_ args: [Operand]) {
        value = args[0]
    }
    
    func copy() -> VariableInst {
        return VariableInst(operand: value.formCopy(), irName: irName)
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

