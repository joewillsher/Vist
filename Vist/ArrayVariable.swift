//
//  ArrayVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//




class ArrayVariable : RuntimeVariable {
    var elementType: LLVMTypeRef    // ty Type
    var arrayType: LLVMTypeRef // [sz x ty] Type
    
    var ptr: LLVMValueRef   // ty*
    var arr: LLVMValueRef   // [sz x ty]*
    var base: LLVMValueRef  // ty*
    var count: Int
    var mutable: Bool
    
    var builder: LLVMBuilderRef
    
    var type: LLVMTypeRef {
        return LLVMArrayType(elementType, UInt32(count))
    }
    
    func load(name: String = "") -> LLVMValueRef {
        return base
    }
    
    func isValid() -> Bool {
        return ptr != nil
    }
    
    func assignFrom(builder: LLVMBuilderRef, arr: ArrayVariable) {
        
        assert(elementType == arr.elementType)
        
        LLVMBuildStore(builder, arr.base, ptr)
        count = arr.count
        base = arr.base
        arrayType = arr.arrayType
    }
    
    init(ptr: LLVMValueRef, elType: LLVMTypeRef, arrType: LLVMTypeRef, builder: LLVMBuilderRef, vars: [LLVMValueRef]) {
        
        let pt = LLVMPointerType(elType, 0)
        // case array as ptr to get base pointer
        let base = LLVMBuildBitCast(builder, ptr, pt, "base")
        
        for n in 0..<vars.count {
            // llvm num type as the index
            let index = [LLVMConstInt(LLVMInt64Type(), UInt64(n), LLVMBool(false))].ptr()
            // Get pointer to element n
            let el = LLVMBuildGEP(builder, base, index, 1, "el\(n)")
            
            // load val into memory
            LLVMBuildStore(builder, vars[n], el)
        }
        
        self.elementType = elType
        self.base = base
        self.arr = ptr
        self.count = vars.count
        self.arrayType = arrType
        self.mutable = false
        self.ptr = nil
        self.builder = builder
    }
    
    func allocHead(builder: LLVMBuilderRef, name: String, mutable: Bool) {
        let pt = LLVMPointerType(elementType, 0)
        self.ptr = LLVMBuildAlloca(builder, pt, name)
        LLVMBuildStore(builder, base, self.ptr)
    }
    
    func ptrToElementAtIndex(i: LLVMValueRef) -> LLVMValueRef {
        
        return LLVMBuildGEP(builder, base, [i].ptr(), 1, "ptr")
    }
    
}


// TODO: Initially allocate a wider buffer than required if I can see it can change size in the future, use sema pass to add information about immutable arrays/strings etc.

// TODO: Eagerly deallocate the original array in a mutation

// TODO: Implement storage of array size inline, currently the runtime gets no information about array size, that’s all worked out by the compiler statically



