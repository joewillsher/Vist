//
//  ReturnInst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 A return inst, returns from the current function
 
 `return %a`
 */
final class ReturnInst : InstBase {
    var value: Operand
    
    init(value: Value, parentBlock: BasicBlock?) {
        let op = Operand(value)
        self.value = op
        super.init(args: [op], irName: nil)
        self.parentBlock = parentBlock
    }
    
    override var instVIR: String {
        return "return \(value.name)"
    }
    
    override var type: Type? { return nil }
    
    override var hasSideEffects: Bool { return true }
    override var isTerminator: Bool { return true }
}


extension Builder {
    
    @discardableResult
    func buildReturnVoid() throws -> ReturnInst {
        return try buildReturn(value: createVoidLiteral())
    }
    
    @discardableResult
    func buildReturn(value: Value) throws -> ReturnInst {
        return try build(inst: ReturnInst(value: value, parentBlock: insertPoint.block))
    }
}