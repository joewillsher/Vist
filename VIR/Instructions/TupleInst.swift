//
//  TupleInst.swift
//  Vist
//
//  Created by Josef Willsher on 06/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class TupleCreateInst : InstBase {
    var tupleType: TupleType, elements: [Operand]
    
    /// - precondition: `type` has been included in the module using
    ///                 `type.usingTypesIn(module)`
    init(type: TupleType, elements: [Value], irName: String? = nil) {
        self.tupleType = type//.usingTypesIn(module) as! TupleType
        let els = elements.map(Operand.init)
        self.elements = els
        super.init(args: els, irName: irName)
    }
    
    override var type: Type? { return tupleType }
    
    override var instVIR: String {
        return "\(name) = tuple \(args.virValueTuple()) \(useComment)"
    }
}

final class TupleExtractInst : InstBase {
    var tuple: Operand, elementIndex: Int
    var elementType: Type
    
    /// - precondition: Tuple has an element at `index`
    init(tuple: Value, index: Int, irName: String? = nil) throws {
        
        guard let elType = try tuple.type?.getAsTupleType().propertyType(index) else {
            throw VIRError.noType(#file)
        }
        
        let op = Operand(tuple)
        self.tuple = op
        self.elementIndex = index
        self.elementType = elType
        super.init(args: [op], irName: irName)
    }
    
    override var type: Type? { return elementType }
    
    override var instVIR: String {
        return "\(name) = tuple_extract \(tuple.valueName), !\(elementIndex) \(useComment)"
    }
}


final class TupleElementPtrInst : InstBase, LValue {
    var tuple: PtrOperand, elementIndex: Int
    var elementType: Type
    
    private init(tuple: PtrOperand, index: Int, elementType: Type, irName: String?) {
        self.tuple = tuple
        self.elementIndex = index
        self.elementType = elementType
        super.init(args: [tuple], irName: irName)
    }
    
    override var type: Type? { return BuiltinType.pointer(to: elementType) }
    var memType: Type? { return elementType }

    override var instVIR: String {
        return "\(name) = tuple_element \(tuple.valueName), !\(elementIndex) \(useComment)"
    }
}


extension Builder {
    /// Get the ptr to a tuple’s element
    func buildTupleElementPtr(tuple: PtrOperand, index: Int, irName: String? = nil) throws -> TupleElementPtrInst {
        guard let elType = try (tuple.memType as? TupleType)?.propertyType(index) else { throw VIRError.noType(#file) }
        return try _add(TupleElementPtrInst(tuple: tuple, index: index, elementType: elType.usingTypesIn(module), irName: irName))
    }
}
