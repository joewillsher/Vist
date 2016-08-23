//
//  VariableInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class VariableInst : Inst {
    var value: Operand
    
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
        return "variable \(name) = \(value.valueName)\(useComment)"
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

final class VariableAddrInst : Inst, LValue {
    var addr: PtrOperand
    
    var uses: [Operand] = []
    var args: [Operand]
    
    var type: Type? { return addr.type }
    var memType: Type? { return addr.memType }
    
    convenience init(addr: LValue, irName: String? = nil) {
        self.init(operand: PtrOperand(addr), irName: irName)
    }
    private init(operand: PtrOperand, irName: String?) {
        self.addr = operand
        self.args = [operand]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "variable_addr \(name) = \(addr.valueName)\(useComment)"
    }
    
    func setArgs(_ args: [Operand]) {
        addr = args[0] as! PtrOperand
    }
    
    func copy() -> VariableAddrInst {
        return VariableAddrInst(operand: addr.formCopy(), irName: irName)
    }
    var parentBlock: BasicBlock?
    var irName: String?
}


