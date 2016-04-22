//
//  AggregateLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension TupleCreateInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        guard let t = type else { throw irGenError(.notStructType) }
        var val = LLVMGetUndef(t.lowerType(module))
        
        for (i, el) in args.enumerate() {
            val = LLVMBuildInsertValue(irGen.builder, val, el.loweredValue, UInt32(i), irName ?? "")
        }
        
        return val
    }
}

extension TupleExtractInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildExtractValue(irGen.builder, tuple.loweredValue, UInt32(elementIndex), irName ?? "")
    }
}

extension TupleElementPtrInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        return LLVMBuildStructGEP(irGen.builder, tuple.loweredValue, UInt32(elementIndex), irName ?? "")
    }
}

extension StructExtractInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let index = try structType.indexOfMemberNamed(propertyName)
        return LLVMBuildExtractValue(irGen.builder, object.loweredValue, UInt32(index), irName ?? "")
    }
}

extension StructElementPtrInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValueRef {
        let index = try structType.indexOfMemberNamed(propertyName)
        return LLVMBuildStructGEP(irGen.builder, object.loweredValue, UInt32(index), irName ?? "")
    }
}

