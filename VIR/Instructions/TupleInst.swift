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
    ///                 `type.importedType(inModule: module)`
    init(type: TupleType, elements: [Value], irName: String? = nil) {
        self.tupleType = type//.importedType(inModule: module) as! TupleType
        let els = elements.map(Operand.init)
        self.elements = els
        super.init(args: els, irName: irName)
    }
    
    override var type: Type? { return tupleType }
    
    override var instVIR: String {
        return "\(name) = tuple \(args.virValueTuple())\(useComment)"
    }
}

final class TupleExtractInst : InstBase {
    var tuple: Operand, elementIndex: Int
    var elementType: Type
    
    /// - precondition: Tuple has an element at `index`
    init(tuple: Value, index: Int, irName: String? = nil) throws {
        
        guard let elType = try tuple.type?.getAsTupleType().elementType(at: index) else {
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
        return "\(name) = tuple_extract \(tuple.valueName), !\(elementIndex)\(useComment)"
    }
}


final class TupleElementPtrInst : InstBase, LValue {
    var tuple: PtrOperand, elementIndex: Int
    var elementType: Type
    
    init(tuple: LValue, index: Int, irName: String? = nil) throws {
        
        guard let elType = try tuple.memType?.getAsTupleType().elementType(at: index) else {
            throw VIRError.noType(#file)
        }

        let op = PtrOperand(tuple)
        self.tuple = op
        self.elementIndex = index
        self.elementType = elType
        super.init(args: [op], irName: irName)
    }
    
    override var type: Type? { return BuiltinType.pointer(to: elementType) }
    var memType: Type? { return elementType }

    override var instVIR: String {
        return "\(name) = tuple_element \(tuple.valueName), !\(elementIndex)\(useComment)"
    }
}
