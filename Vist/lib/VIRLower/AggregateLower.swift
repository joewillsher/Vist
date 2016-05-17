//
//  AggregateLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension TupleCreateInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        guard let t = type else { throw irGenError(.notStructType) }
        return try IGF.builder.buildAggregate(type: t.lowerType(module),
                                              elements: args.map { $0.loweredValue! },
                                              irName: irName)
    }
}

extension StructInitInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        guard case let t as TypeAlias = type else { throw irGenError(.notStructType) }
        return try IGF.builder.buildAggregate(type: t.lowerType(module),
                                              elements: args.map { $0.loweredValue! },
                                              irName: irName)
    }
}

extension TupleExtractInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildExtractValue(tuple.loweredValue!, index: elementIndex, name: irName)
    }
}

extension TupleElementPtrInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        return try IGF.builder.buildStructGEP(tuple.loweredValue!, index: elementIndex, name: irName)
    }
}

extension StructExtractInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        let index = try structType.indexOfMemberNamed(propertyName)
        return try IGF.builder.buildExtractValue(object.loweredValue!, index: index, name: irName)
    }
}

extension StructElementPtrInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        let index = try structType.indexOfMemberNamed(propertyName)
        return try IGF.builder.buildStructGEP(object.loweredValue!, index: index, name: irName)
    }
}

