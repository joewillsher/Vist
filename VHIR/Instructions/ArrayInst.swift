//
//  ArrayInst.swift
//  Vist
//
//  Created by Josef Willsher on 28/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class ArrayInst: InstBase {
    var values: [Operand]
    let arrayType: (mem: Ty, size: Int)
    
    override var type: Ty? { return BuiltinType.array(el: arrayType.mem, size: UInt32(arrayType.size)) }
    
    private init(values: [Operand], memType: Ty, irName: String?) {
        self.values = values
        self.arrayType = (mem: memType, size: values.count)
        super.init(args: values, irName: irName)
    }
    
    override var instVHIR: String {
        let v = values.map { $0.valueName }
        return "\(name) = array [\(v.joinWithSeparator(", "))] \(useComment)"
    }
    
}

extension Builder {
    
    func buildArray(values: [Operand], memType: Ty, irName: String? = nil) throws -> ArrayInst {
        guard values.indexOf({$0.type != memType}) == nil else { fatalError("Not homogenous array") }
        return try _add(ArrayInst(values: values, memType: memType, irName: irName))
    }
}


