//
//  ReturnInst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



final class ReturnInst: Inst {
    var value: Operand
    var irName: String? = nil
    
    var uses: [Operand] = []
    var args: [Operand] { return [value] }
    var type: Ty?
    weak var parentBlock: BasicBlock?
    
    private init(value: Operand, parentBlock: BasicBlock?) {
        self.value = value
        self.parentBlock = parentBlock
    }    
}


extension Builder {
    
    func buildReturnVoid() throws -> ReturnInst {
        return try buildReturn(Operand(VoidLiteralValue()))
    }
    func buildReturn(value: Operand) throws -> ReturnInst {
        let retInst = ReturnInst(value: value, parentBlock: block)
        try addToCurrentBlock(retInst)
        return retInst
    }
}