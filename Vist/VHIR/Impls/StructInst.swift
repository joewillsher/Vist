//
//  StructInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class StructInitInst: Inst {
    var args: [Operand]
    
    var irName: String?
    var type: Ty? { return module?.getOrAddType(structType) }
    var structType: StructType
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    private init(type: StructType, args: [Operand], irName: String? = nil) {
        self.args = args
        self.irName = irName
        self.structType = type
    }
}

extension Builder {
    func buildStructInit(type: StructType, values: [Operand], irName: String? = nil) throws -> StructInitInst {
        let s = StructInitInst(type: type, args: values, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
}