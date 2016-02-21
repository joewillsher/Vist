//
//  LLVMPtrWrapper.swift
//  Vist
//
//  Created by Josef Willsher on 14/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol LLVMValue: class {
    var value: LLVMValueRef { get set }
    init(value: LLVMValueRef)
}

extension LLVMValue {
    
    func dump() { // if != nil
        LLVMDumpValue(value)
    }
    
}

final class LLVMIntValue {
    var value: LLVMValueRef
    
    init(value: LLVMValueRef) {
        self.value = value
    }
    
}


final class LLVMBuilder {
    var builder: LLVMModuleRef
    init(_ builder: LLVMModuleRef) { self.builder = builder }
    
    /// Create an array of `elementType` with values `values`
    ///
    /// - returns: A pointer of type `[n x el]*`
    func buildArrayOf(elementType: LLVMTypeRef, values: [LLVMValueRef]) -> LLVMValueRef {
        
        let arrType = LLVMArrayType(elementType, UInt32(values.count))
        let ptr = LLVMBuildAlloca(builder, arrType, "metadata") // [n x el]*
        let elPtrType = LLVMPointerType(elementType, 0)
        let basePtr = LLVMBuildBitCast(builder, ptr, elPtrType, "") // el*
        
        for (i, offset) in values.enumerate() {
            // Get pointer to element n
            let val = [BuiltinType.intGen(size: 32)(i)].ptr()
            defer { val.dealloc(1) }
            
            let el = LLVMBuildGEP(builder, basePtr, val, 1, "el.\(i)")
            let bcElPtr = LLVMBuildBitCast(builder, el, elPtrType, "el.ptr.\(i)")
            // load val into memory
            LLVMBuildStore(builder, offset, bcElPtr)
        }
        
        return LLVMBuildLoad(builder, ptr, "")

    }
}

