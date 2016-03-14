//
//  ArrayVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//




class ArrayVariable: RuntimeVariable {
    private var elementType: LLVMTypeRef    // ty Type
    private var arrayType: LLVMTypeRef // [sz x ty] Type
    
    var ptr: LLVMValueRef   // ty*
    private var arr: LLVMValueRef   // [sz x ty]*
    private var base: LLVMValueRef  // ty*
    private var count: Int
    var mutable: Bool
    
    var irGen: IRGen
    var irName: String
    
    var type: LLVMTypeRef {
        return LLVMArrayType(elementType, UInt32(count))
    }
    
    func load(irName name: String = "") -> LLVMValueRef {
        return base
    }
    
    var value: LLVMValueRef {
        get {
            return base
        }
    }
    
    func assignFrom(arr: ArrayVariable) {
        
        precondition(elementType == arr.elementType)
        
        LLVMBuildStore(irGen.builder, arr.base, ptr)
        count = arr.count
        base = arr.base
        arrayType = arr.arrayType
    }
    
    init(ptr: LLVMValueRef, elType: LLVMTypeRef, arrType: LLVMTypeRef, irName: String = "", irGen: IRGen, vars: [LLVMValueRef]) {
        
        let pt = LLVMPointerType(elType, 0)
        // case array as ptr to get base pointer
        let base = LLVMBuildBitCast(irGen.builder, ptr, pt, "base")
        
        for n in 0..<vars.count {
            // llvm num type as the index
            let index = [LLVMConstInt(LLVMInt64Type(), UInt64(n), false)].ptr()
            // Get pointer to element n
            let el = LLVMBuildGEP(irGen.builder, base, index, 1, "el\(n)")
            
            // load val into memory
            LLVMBuildStore(irGen.builder, vars[n], el)
            index.dealloc(1)
        }
        
        self.elementType = elType
        self.base = base
        self.arr = ptr
        self.count = vars.count
        self.arrayType = arrType
        self.mutable = false
        self.ptr = nil
        self.irGen = irGen
        self.irName = irName
    }
    
    func allocHead(builder: LLVMBuilderRef, name: String, mutable: Bool) {
        let pt = LLVMPointerType(elementType, 0)
        self.ptr = LLVMBuildAlloca(builder, pt, name)
        LLVMBuildStore(builder, base, self.ptr)
    }
    
    private func ptrToElementAtIndex(index: LLVMValueRef) -> LLVMValueRef {
        let el = [index].ptr()
        defer { el.dealloc(1) }
        return LLVMBuildGEP(irGen.builder, base, el, 1, "ptr")
    }
    
    func loadElementAtIndex(index: LLVMValueRef) -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, ptrToElementAtIndex(index), "element")
    }
    
    func store(val: LLVMValueRef, inElementAtIndex index: LLVMValueRef) {
        LLVMBuildStore(irGen.builder, val, ptrToElementAtIndex(index))
    }
    
}


// TODO: Initially allocate a wider buffer than required if I can see it can change size in the future, use sema pass to add information about immutable arrays/strings etc.

// TODO: Eagerly deallocate the original array in a mutation

// TODO: Implement storage of array size inline, currently the runtime gets no information about array size, that’s all worked out by the compiler statically



