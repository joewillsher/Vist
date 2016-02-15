//
//  RuntimeVariable.swift
//  Vist
//
//  Created by Josef Willsher on 18/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


typealias IRGen = (builder: LLVMBuilderRef, module: LLVMModuleRef, isStdLib: Bool)

protocol RuntimeVariable : class {
    var type: LLVMTypeRef { get }
    var value: LLVMValueRef { get }
    var irName: String { get }
    
    var irGen: IRGen { get }
}

protocol MutableVariable : RuntimeVariable {
    var ptr: LLVMValueRef { get }
    var value: LLVMValueRef { get set }
}

extension MutableVariable {
    
    var value: LLVMValueRef {
        get {
            return LLVMBuildLoad(irGen.builder, ptr, irName)
        }
        set {
            LLVMBuildStore(irGen.builder, newValue, ptr)
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
    
    let irGen: IRGen
    let irName: String
    
    init(type: LLVMTypeRef, ptr: LLVMValueRef, irName: String, irGen: IRGen) {
        self.type = type
        self.ptr = ptr
        self.irGen = irGen
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: LLVMTypeRef, irName: String, irGen: IRGen) -> ReferenceVariable {
        let ptr = LLVMBuildAlloca(irGen.builder, type, irName)
        return ReferenceVariable(type: type, ptr: ptr, irName: irName, irGen: irGen)
    }
}


/// A variable type passed by value
///
/// Instances use SSA
final class StackVariable : RuntimeVariable {
    var type: LLVMTypeRef
    var val: LLVMValueRef
    
    var irGen: IRGen
    let irName: String
    
    init(val: LLVMValueRef, irName: String, irGen: IRGen) {
        self.type = LLVMTypeOf(val)
        self.val = val
        self.irGen = irGen
        self.irName = irName
    }
    
    var value: LLVMValueRef {
        return val
    }
    
    func isValid() -> Bool {
        return val != nil
    }
}

