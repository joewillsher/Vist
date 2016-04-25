//
//  ArrayInst.swift
//  Vist
//
//  Created by Josef Willsher on 28/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class ArrayInst : InstBase {
    var values: [Operand]
    let arrayType: (mem: Type, size: Int)
    
    override var type: Type? { return BuiltinType.array(el: arrayType.mem, size: arrayType.size) }
    
    private init(values: [Operand], memType: Type, irName: String?) {
        self.values = values
        self.arrayType = (mem: memType, size: values.count)
        super.init(args: values, irName: irName)
    }
    
    override var instVIR: String {
        let v = values.map { value in value.valueName }
        return "\(name) = array [\(v.joinWithSeparator(", "))] \(useComment)"
    }
    
}

extension Builder {
    
    func buildArray(values: [Operand], memType: Type, irName: String? = nil) throws -> ArrayInst {
        guard values.indexOf({value in value.type != memType}) == nil else { fatalError("Not homogenous array") }
        return try _add(ArrayInst(values: values, memType: memType, irName: irName))
    }
}


