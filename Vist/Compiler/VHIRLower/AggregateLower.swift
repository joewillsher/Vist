//
//  AggregateLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

private extension CollectionType where Generator.Element == Operand {
    
    func initAggregateType(type: LLVMType, builder: LLVMBuilder, irName: String? = nil) throws -> LLVMValue {
        
        // creates an undef, then for each element in type, inserts the next element into it
        return try enumerate()
            .reduce(LLVMValue.undef(type)) { aggr, el in
                return try builder.buildInsertValue(value: el.element.loweredValue!,
                                                    in: aggr,
                                                    index: el.index,
                                                    name: irName)
        }
    }
    
}

extension TupleCreateInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        guard let t = type else { throw irGenError(.notStructType) }
        return try args.initAggregateType(t.lowerType(module), builder: module.loweredBuilder, irName: irName)
    }
}

extension StructInitInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        guard case let t as TypeAlias = type else { throw irGenError(.notStructType) }
        return try args.initAggregateType(t.lowerType(module), builder: module.loweredBuilder, irName: irName)
    }
}

extension TupleExtractInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildExtractValue(tuple.loweredValue!, index: elementIndex, name: irName)
    }
}

extension TupleElementPtrInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        return try module.loweredBuilder.buildStructGEP(tuple.loweredValue!, index: elementIndex, name: irName)
    }
}

extension StructExtractInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        let index = try structType.indexOfMemberNamed(propertyName)
        return try module.loweredBuilder.buildExtractValue(object.loweredValue!, index: index, name: irName)
    }
}

extension StructElementPtrInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        let index = try structType.indexOfMemberNamed(propertyName)
        return try module.loweredBuilder.buildStructGEP(object.loweredValue!, index: index, name: irName)
    }
}

