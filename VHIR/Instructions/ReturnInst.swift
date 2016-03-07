//
//  ReturnInst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class ReturnInst: InstBase {
    var value: Operand
    
    private init(value: Operand, parentBlock: BasicBlock?) {
        self.value = value
        super.init()
        self.parentBlock = parentBlock
        self.args = [value]
    }
    
    override var instVHIR: String {
        return "return \(value.name)"
    }
}


extension Builder {
    
    func buildReturnVoid() throws -> ReturnInst {
        return try buildReturn(Operand(createVoidLiteral()))
    }
    func buildReturn(value: Operand) throws -> ReturnInst {
        let retInst = ReturnInst(value: value, parentBlock: insertPoint.block)
        try addToCurrentBlock(retInst)
        return retInst
    }
}