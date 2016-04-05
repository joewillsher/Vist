//
//  ReturnInst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class ReturnInst : InstBase {
    var value: Operand
    
    private init(value: Operand, parentBlock: BasicBlock?) {
        self.value = value
        super.init(args: [value], irName: nil)
        self.parentBlock = parentBlock
    }
    
    override var instVHIR: String {
        return "return \(value.name)"
    }
    
    override var type: Ty? { return nil }
    
    override var hasSideEffects: Bool { return true }
    override var isTerminator: Bool { return true }
}


extension Builder {
    
    func buildReturnVoid() throws -> ReturnInst {
        return try buildReturn(Operand(createVoidLiteral()))
    }
    func buildReturn(value: Operand) throws -> ReturnInst {
        return try _add(ReturnInst(value: value, parentBlock: insertPoint.block))
    }
}