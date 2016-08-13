//
//  Metadata.swift
//  Vist
//
//  Created by Josef Willsher on 12/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol MetadataLower {
    var loweredMetadata: LLVMValue! { get set }
    func lowerMetadata(IGF: inout IRGenFunction) throws -> LLVMValue
}

extension VIRWitnessTable : MetadataLower {
    
    func lowerMetadata(IGF: inout IRGenFunction) throws -> LLVMValue {
        let val = LLVMValue.constNull(type: LLVMType.opaquePointer)
        loweredMetadata = val
        return val
    }
    
}

