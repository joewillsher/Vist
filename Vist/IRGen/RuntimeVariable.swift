//
//  RuntimeVariable.swift
//  Vist
//
//  Created by Josef Willsher on 18/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


typealias IRGen = (builder: LLVMBuilderRef, module: LLVMModuleRef, isStdLib: Bool)

protocol RuntimeVariable: class {
    var type: LLVMTypeRef { get }
    var value: LLVMValueRef { get }
    var irName: String { get }
    
    var irGen: IRGen { get }
}

protocol MutableVariable: RuntimeVariable {
    var ptr: LLVMValueRef { get }
    var value: LLVMValueRef { get set }
}

extension Ty {
    
    func variableForPtr(ptr: LLVMValueRef, irGen: IRGen) throws -> RuntimeVariable {
        
        switch self {
        case let t as StructType:
            return MutableStructVariable(type: t, ptr: ptr, irName: "", irGen: irGen)
            
        case let c as ConceptType:
            return ExistentialVariable(ptr: ptr, conceptType: c, mutable: true, irName: "", irGen: irGen)
            
        case let type:
            return ReferenceVariable(type: type, ptr: ptr, irName: "", irGen: irGen)
        }
    }
    func variableForVal(val: LLVMValueRef, irGen: IRGen) throws -> RuntimeVariable {
        
        switch self {
        case let t as StructType:
            let v = MutableStructVariable.alloc(t, irGen: irGen)
            v.value = val
            return v
            
        case let e as ConceptType:
            return ExistentialVariable.assignFromExistential(val, conceptType: e, mutable: true, irGen: irGen)
            
        case let type:
            let v = ReferenceVariable.alloc(type, irName: "", irGen: irGen)
            v.value = val
            return v
        }
    }


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
final class ReferenceVariable: MutableVariable {
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
    convenience init(type: Ty, ptr: LLVMValueRef, irName: String, irGen: IRGen) {
        self.init(type: type.globalType(irGen.module), ptr: ptr, irName: irName, irGen: irGen)
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: Ty, irName: String, irGen: IRGen) -> ReferenceVariable {
        let ty = type.globalType(irGen.module)
        let ptr = LLVMBuildAlloca(irGen.builder, ty, irName)
        return ReferenceVariable(type: ty, ptr: ptr, irName: irName, irGen: irGen)
    }
}


/// A variable type passed by value, instances use SSA
final class StackVariable: RuntimeVariable {
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

/// Variables that can hold a mutable reference to self.
///
/// Self capturing functions use this by setting `parent` to the self pointer param
/// any calls to load from/store into this variable are forwarded to the parent's
/// member access functions
final class SelfReferencingMutableVariable: MutableVariable {
    var ptr: LLVMValueRef {
        return try! parent.ptrToPropertyNamed(name)
    }
    var type: LLVMTypeRef {
        return parent.typeOfPropertyNamed(name)!
    }
    
    /// unowned ref to struct this belongs to
    private unowned var parent: protocol<MutableVariable, StorageVariable>
    
    var irGen: IRGen
    var irName: String { return "\(parent.irName).\(name)" }
    let name: String
    
    init(propertyName name: String, parent: protocol<MutableVariable, StorageVariable>) {
        self.name = name
        self.parent = parent
        self.irGen = parent.irGen
    }
    
    var value: LLVMValueRef {
        get {
            return try! parent.loadPropertyNamed(self.name)
        }
        set {
            try! parent.store(newValue, inPropertyNamed: name)
        }
    }
    
}


