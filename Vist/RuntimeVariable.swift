//
//  RuntimeVariable.swift
//  Vist
//
//  Created by Josef Willsher on 18/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


protocol RuntimeVariable {
    var type: LLVMTypeRef { get }
    
    func load(name: String) -> LLVMValueRef
    func isValid() -> Bool
}

protocol MutableVariable {
    func store(val: LLVMValueRef)
    var mutable: Bool { get }
}

/// A variable type passed by reference
/// Instances are called in IR using `load` and `store`
/// mem2reg optimisation pass moves these down to SSA register vars
class ReferenceVariable : RuntimeVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let mutable: Bool
    
    var builder: LLVMBuilderRef
    
    init(type: LLVMTypeRef, ptr: LLVMValueRef, mutable: Bool, builder: LLVMBuilderRef) {
        self.type = type
        self.mutable = mutable
        self.ptr = ptr
        self.builder = builder
    }
    
    func load(name: String = "") -> LLVMValueRef {
        return LLVMBuildLoad(builder, ptr, name)
    }
    
    func isValid() -> Bool {
        return ptr != nil
    }
    
    /// returns pointer to allocated memory
    class func alloc(builder: LLVMBuilderRef, type: LLVMTypeRef, name: String = "", mutable: Bool) -> ReferenceVariable {
        let ptr = LLVMBuildAlloca(builder, type, name)
        return ReferenceVariable(type: type, ptr: ptr, mutable: mutable, builder: builder)
    }
    
    func store(val: LLVMValueRef) {
        LLVMBuildStore(builder, val, ptr)
    }
    
    
}


/// A variable type passed by value
/// Instances use SSA
class StackVariable : RuntimeVariable {
    var type: LLVMTypeRef
    var val: LLVMValueRef
    var builder: LLVMBuilderRef
    
    init(val: LLVMValueRef, builder: LLVMBuilderRef) {
        self.type = LLVMTypeOf(val)
        self.val = val
        self.builder = builder
    }
    
    func load(name: String = "") -> LLVMValueRef {
        return val
    }
    
    func isValid() -> Bool {
        return val != nil
    }
}

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
        
        // TODO: Initialisation is O(n), make O(1)
        
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


