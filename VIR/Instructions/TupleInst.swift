//
//  TupleInst.swift
//  Vist
//
//  Created by Josef Willsher on 06/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class TupleCreateInst : Inst {
    var tupleType: TupleType, elements: [Operand]
    
    var uses: [Operand] = []
    var args: [Operand]
    
    /// - precondition: `type` has been included in the module using
    ///                 `type.importedType(in: module)`
    init(type: TupleType, elements: [Value], irName: String? = nil) {
        self.tupleType = type//.importedType(in: module) as! TupleType
        let els = elements.map(Operand.init)
        self.elements = els
        args = els
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return tupleType }
    
    var vir: String {
        return "\(name) = tuple \(args.virValueTuple())\(useComment)"
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

final class TupleExtractInst : Inst {
    var tuple: Operand, elementIndex: Int
    var elementType: Type
    
    var uses: [Operand] = []
    var args: [Operand]
    
    /// - precondition: Tuple has an element at `index`
    convenience init(tuple: Value, index: Int, irName: String? = nil) throws {
        guard let elType = try tuple.type?.getAsTupleType().elementType(at: index) else {
            throw VIRError.noType(#file)
        }
        self.init(op: Operand(tuple), index: index, elType: elType, irName: irName)
    }
    
    private init(op: Operand, index: Int, elType: Type, irName: String?) {
        let op = op
        self.tuple = op
        self.elementIndex = index
        self.elementType = elType
        self.args = [op]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return elementType }
    
    var vir: String {
        return "\(name) = tuple_extract \(tuple.valueName), !\(elementIndex)\(useComment)"
    }
    
    func copy() -> TupleExtractInst {
        return TupleExtractInst(op: tuple.formCopy(), index: elementIndex, elType: elementType, irName: irName)
    }
    func setArgs(args: [Operand]) {
        tuple = args[0]
    }
    var parentBlock: BasicBlock?
    var irName: String?
}


final class TupleElementPtrInst : Inst, LValue {
    var tuple: PtrOperand, elementIndex: Int
    var elementType: Type
    
    var uses: [Operand] = []
    var args: [Operand]
    
    init(tuple: LValue, index: Int, irName: String? = nil) throws {
        
        guard let elType = try tuple.memType?.getAsTupleType().elementType(at: index) else {
            throw VIRError.noType(#file)
        }

        let op = PtrOperand(tuple)
        self.tuple = op
        self.elementIndex = index
        self.elementType = elType
        self.args = [op]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return BuiltinType.pointer(to: elementType) }
    var memType: Type? { return elementType }

    var vir: String {
        return "\(name) = tuple_element \(tuple.valueName), !\(elementIndex)\(useComment)"
    }
    var parentBlock: BasicBlock?
    var irName: String?
}
