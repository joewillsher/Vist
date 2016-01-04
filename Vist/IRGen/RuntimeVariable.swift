//
//  RuntimeVariable.swift
//  Vist
//
//  Created by Josef Willsher on 18/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


protocol RuntimeVariable {
    var type: LLVMTypeRef { get }
    
    func load(name: String) throws -> LLVMValueRef
    func isValid() -> Bool
}

protocol MutableVariable : RuntimeVariable {
    func store(val: LLVMValueRef) throws
    var mutable: Bool { get }
}

/// A variable type passed by reference
///
/// Instances are called in IR using `load` and `store`
///
/// mem2reg optimisation pass moves these down to SSA register vars
final class ReferenceVariable : MutableVariable {
    var type: LLVMTypeRef
    private var ptr: LLVMValueRef
    let mutable: Bool
    
    private var builder: LLVMBuilderRef
    
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
///
/// Instances use SSA
final class StackVariable : RuntimeVariable {
    var type: LLVMTypeRef
    private var val: LLVMValueRef
    
    private var builder: LLVMBuilderRef
    
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

