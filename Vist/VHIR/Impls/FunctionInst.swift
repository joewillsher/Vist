//
//  FunctionInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class FunctionCallInst: Inst {
    var args: [Operand]
    var function: Function
    
    var irName: String?
    var type: Ty?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    private init(function: Function, args: [Operand], irName: String? = nil) {
        self.args = args
        self.irName = irName
        self.type = function.type.returns
        self.function = function
    }
}


extension Builder {
    
    func buildFunctionCall(function: Function, args: [Operand], irName: String? = nil) throws -> FunctionCallInst {
        let s = FunctionCallInst(function: function, args: args, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
}