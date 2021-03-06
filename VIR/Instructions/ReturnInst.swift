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
final class ReturnInst : Inst {
    var returnValue: Operand
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(value: Value, parentBlock: BasicBlock?) {
        self.init(op: Operand(value))
        self.parentBlock = parentBlock
    }
    private init(op: Operand) {
        self.returnValue = op
        self.args = [op]
        initialiseArgs()
    }
    
    var vir: String {
        return "return \(returnValue.name) // id: \(name)"
    }
    
    var type: Type? { return nil }
    
    var hasSideEffects: Bool { return true }
    var isTerminator: Bool { return true }
    
    func setArgs(_ args: [Operand]) {
        returnValue = args[0]
    }
    
    func copy() -> ReturnInst {
        return ReturnInst(op: returnValue.formCopy())
    }
    
    var parentBlock: BasicBlock?
    var irName: String?
}


extension VIRBuilder {
    
    @discardableResult
    func buildReturnVoid() throws -> ReturnInst {
        let tuple = try build(TupleCreateInst(type: TupleType(members: []), elements: []))
        return try buildReturn(value: tuple)
    }
    
    @discardableResult
    func buildReturn(value: Value) throws -> ReturnInst {
        return try build(ReturnInst(value: value, parentBlock: insertPoint.block))
    }
}
