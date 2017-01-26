//
//  AggregateLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension TupleCreateInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        guard let t = type else {
            throw irGenError(.notStructType)
        }
        return try igf.builder.buildAggregate(type: t.lowered(module: module),
                                              elements: args.map { $0.loweredValue! },
                                              irName: irName)
    }
}

extension StructInitInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        guard case let t as ModuleType = type else {
            throw irGenError(.notStructType)
        }
        return try igf.builder.buildAggregate(type: t.lowered(module: module),
                                              elements: args.map { $0.loweredValue! },
                                              irName: irName)
    }
}

extension TupleExtractInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        return try igf.builder.buildExtractValue(from: tuple.loweredValue!, index: elementIndex, name: irName)
    }
}

extension TupleElementPtrInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        return try igf.builder.buildStructGEP(ofAggregate: tuple.loweredValue!, index: elementIndex, name: irName)
    }
}

extension StructExtractInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let index = try structType.index(ofMemberNamed: propertyName)
        return try igf.builder.buildExtractValue(from: object.loweredValue!, index: index, name: irName)
    }
}

extension StructElementPtrInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let index = try structType.index(ofMemberNamed: propertyName)
        return try igf.builder.buildStructGEP(ofAggregate: object.loweredValue!, index: index, name: irName)
    }
}
extension ClassProjectInstanceInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let member = try igf.builder.buildStructGEP(ofAggregate: object.loweredValue!, index: 0)
        return try igf.builder.buildLoad(from: member, name: irName)
    }
}
extension ClassGetRefCountInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let member = try igf.builder.buildStructGEP(ofAggregate: object.loweredValue!, index: 1)
        return try igf.builder.buildLoad(from: member, name: irName)
    }
}
