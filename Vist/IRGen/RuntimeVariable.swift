//
//  RuntimeVariable.swift
//  Vist
//
//  Created by Josef Willsher on 18/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


protocol RuntimeVariable : class {
    var type: LLVMTypeRef { get }
    var value: LLVMValueRef { get }
    var irName: String { get }
    
    var builder: LLVMBuilderRef { get }
}

protocol MutableVariable : RuntimeVariable {
    var ptr: LLVMValueRef { get }
    var value: LLVMValueRef { get set }
}

extension MutableVariable {
    
    var value: LLVMValueRef {
        get {
            return LLVMBuildLoad(builder, ptr, irName)
        }
        set {
            LLVMBuildStore(builder, newValue, ptr)
        }
    }
    
}

/// A variable type passed by reference
///
/// Instances are called in IR using `load` and `store`
///
/// mem2reg optimisation pass moves these down to SSA register vars
final class ReferenceVariable : MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    
    let builder: LLVMBuilderRef
    let irName: String
    
    init(type: LLVMTypeRef, ptr: LLVMValueRef, irName: String, builder: LLVMBuilderRef) {
        self.type = type
        self.ptr = ptr
        self.builder = builder
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: LLVMTypeRef, irName: String, builder: LLVMBuilderRef) -> ReferenceVariable {
        let ptr = LLVMBuildAlloca(builder, type, irName)
        return ReferenceVariable(type: type, ptr: ptr, irName: irName, builder: builder)
    }
}


/// A variable type passed by value
///
/// Instances use SSA
final class StackVariable : RuntimeVariable {
    var type: LLVMTypeRef
    var val: LLVMValueRef
    
    var builder: LLVMBuilderRef
    let irName: String
    
    init(val: LLVMValueRef, irName: String, builder: LLVMBuilderRef) {
        self.type = LLVMTypeOf(val)
        self.val = val
        self.builder = builder
        self.irName = irName
    }
    
    var value: LLVMValueRef {
        return val
    }
    
    func isValid() -> Bool {
        return val != nil
    }
}

