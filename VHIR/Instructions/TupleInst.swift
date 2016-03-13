//
//  TupleInst.swift
//  Vist
//
//  Created by Josef Willsher on 06/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class TupleCreateInst: InstBase {
    
    override var type: Ty? { return tupleType }
    var tupleType: TupleType, elements: [Operand]
    
    private init(type: TupleType, elements: [Operand], irName: String? = nil) {
        self.tupleType = type
        self.elements = elements
        super.init()
        self.args = elements
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = tuple \(args.vhirValueTuple()) \(useComment)"
    }
}

final class TupleExtractInst: InstBase, LValue {
    
    override var type: Ty? { return elementType }
    var tuple: Operand, elementIndex: Int
    var elementType: Ty
    
    private init(tuple: Operand, index: Int, elementType: Ty, irName: String? = nil) {
        self.tuple = tuple
        self.elementIndex = index
        self.elementType = elementType
        super.init()
        self.args = [tuple]
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = tuple_extract \(tuple.vhir), \(elementIndex) \(useComment)"
    }
}
final class TupleInsertInst: InstBase, LValue {
    override var type: Ty? { return elementType }
    var tuple: Operand, value: Operand, elementIndex: Int
    var elementType: Ty
    
    private init(tuple: Operand, value: Operand, index: Int, elementType: Ty, irName: String? = nil) {
        self.tuple = tuple
        self.value = value
        self.elementIndex = index
        self.elementType = elementType
        super.init()
        self.args = [tuple]
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = tuple_insert \(tuple.vhir), \(elementIndex) \(useComment)"
    }
}

extension Builder {
    func buildTupleCreate(type: TupleType, elements: [Operand], irName: String? = nil) throws -> TupleCreateInst {
        let s = TupleCreateInst(type: type.usingTypesIn(module) as! TupleType, elements: elements, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
    func buildTupleExtract(tuple: Operand, index: Int, irName: String? = nil) throws -> TupleExtractInst {
        guard let elType = try (tuple.type as? TupleType)?.propertyType(index) else { throw VHIRError.noType }
        let s = TupleExtractInst(tuple: tuple, index: index, elementType: elType.usingTypesIn(module), irName: irName)
        try addToCurrentBlock(s)
        return s
    }
    func buildTupleInsert(tuple: Operand, val: Operand, index: Int, irName: String? = nil) throws -> TupleInsertInst {
        guard let elType = try (tuple.type as? TupleType)?.propertyType(index) else { throw VHIRError.noType }
        let s = TupleInsertInst(tuple: tuple, value: val, index: index, elementType: elType, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
}
