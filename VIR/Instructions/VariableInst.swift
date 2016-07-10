//
//  VariableInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class VariableInst : InstBase {
    var value: Operand
    //var attrs: [OwnershipAttrs] // specify ref/val semantics
    // also memory management info stored
    
    override var type: Type? { return value.type }
    
    convenience init(value: Value, irName: String? = nil) {
        self.init(operand: Operand(value), irName: irName)
    }
    init(operand: Operand, irName: String?) {
        self.value = operand
        super.init(args: [value], irName: irName)
    }
    
    override var instVIR: String {
        return "variable_decl \(name) = \(value.valueName)\(useComment)"
    }
    
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        value = args[0]
    }
    
    override func copyInst() -> VariableInst {
        return VariableInst(operand: value.formCopy(), irName: irName)
    }
}

extension Builder {
    
    func buildVariableDecl(value: Operand, irName: String? = nil) throws -> VariableInst {
        return try _add(instruction: VariableInst(value: value, irName: irName))
    }
}
