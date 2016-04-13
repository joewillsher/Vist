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
    
    private init(value: Operand, irName: String?) {
        self.value = value
        super.init(args: [value], irName: irName)
    }
    
    override var instVHIR: String {
        return "variable_decl \(name) = \(value.valueName) \(useComment)"
    }

}

extension Builder {
    
    func buildVariableDecl(value: Operand, irName: String? = nil) throws -> VariableInst {
        return try _add(VariableInst(value: value, irName: irName))
    }
}