//
//  StructInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class StructInitInst: InstBase {
    
    override var type: Ty? { return module.getOrAddType(structType) }
    var structType: StructType
    
    private init(type: StructType, args: [Operand], irName: String? = nil) {
        self.structType = type
        super.init()
        self.args = args
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = struct %\(type!.explicitName) \(args.vhirValueTuple()) \(useComment)"
    }
}



extension Builder {
    func buildStructInit(type: StructType, values: [Operand], irName: String? = nil) throws -> StructInitInst {
        let s = StructInitInst(type: type, args: values, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
}