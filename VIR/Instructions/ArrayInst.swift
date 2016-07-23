//
//  ArrayInst.swift
//  Vist
//
//  Created by Josef Willsher on 28/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class ArrayInst : Inst {
    var values: [Operand]
    let arrayType: (mem: Type, size: Int)
    
    var type: Type? { return BuiltinType.array(el: arrayType.mem, size: arrayType.size) }
    
    var uses: [Operand] = []
    var args: [Operand]
    
    private init(values: [Operand], memType: Type, irName: String?) {
        self.values = values
        self.arrayType = (mem: memType, size: values.count)
        self.args = values
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        let v = values.map { value in value.valueName }
        return "\(name) = array [\(v.joined(separator: ", "))]\(useComment)"
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}

extension Builder {
    
    func buildArray(values: [Operand], memType: Type, irName: String? = nil) throws -> ArrayInst {
        guard values.index(where: {value in value.type != memType}) == nil else { fatalError("Not homogenous array") }
        return try _add(instruction: ArrayInst(values: values, memType: memType, irName: irName))
    }
}
