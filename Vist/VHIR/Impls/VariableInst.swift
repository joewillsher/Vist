//
//  VariableInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class VariableInst: Inst {
    var value: Operand
    //var ownership: [OwnershipAttrs] // specify ref/val semantics
    // also memory management info stored
    
    var irName: String?
    var type: Ty?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    var args: [Operand] { return [value] }
    
    private init(value: Operand, irName: String? = nil) {
        self.value = value
        self.type = value.type
        self.irName = irName
    }
}

extension Builder {
    
    func buildVariableDecl(value: Operand, irName: String? = nil) throws -> VariableInst {
        let v = VariableInst(value: value, irName: irName)
        try addToCurrentBlock(v)
        return v
    }
}