//
//  RefCountInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

// MARK: Reference counting instructions

/**
 Allocate ref counted object on the heap. Lowered to a call
 of `vist_allocObject(size)`
 
 `%a = alloc_object %Foo.refcounted`
 */
final class AllocObjectInst : Inst, LValue {
    var storedType: StructType
    
    var uses: [Operand] = []
    var args: [Operand] = []
    
    init(memType: StructType, irName: String? = nil) {
        self.storedType = memType
        self.irName = irName
    }
    
    var refType: Type { return storedType.refCountedBox(module: module) }
    var type: Type? { return memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return refType }
    
    var vir: String {
        return "\(name) = alloc_object \(refType.vir)\(useComment)"
    }
    
    func copy() -> AllocObjectInst {
        return AllocObjectInst(memType: storedType, irName: irName)
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}

/**
 Retain a refcounted object - increments the ref count. Lowered to
 a call of `vist_retainObject()`
 
 `retain_object %0:%Foo.refcounted`
 */
final class RetainInst : Inst {
    var object: PtrOperand
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(val: LValue, irName: String? = nil) {
        self.init(object: PtrOperand(val), irName: irName)
    }
    
    private init(object: PtrOperand, irName: String?) {
        self.object = object
        self.args = [object]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return object.memType }
    
    var hasSideEffects: Bool { return true }
    
    var vir: String {
        return "\(name) = retain_object \(object.valueName)\(useComment)"
    }
    
    func copy() -> RetainInst {
        return RetainInst(object: object.formCopy(), irName: irName)
    }
    func setArgs(_ args: [Operand]) {
        object = args[0] as! PtrOperand
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}

/**
 Release a refcounted object - decrements the ref count and, if not
 unowned, it is dealloced if it falls to 0. Lowered to a call of
 `vist_releaseObject()` or `vist_releaseUnownedObject`
 
 ```
 release_object %0:%Foo.refcounted
 release_unowned_object %0:%Foo.refcounted
 ```
 */
final class ReleaseInst : Inst {
    var object: PtrOperand, unowned: Bool
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(val: LValue, unowned: Bool, irName: String? = nil) {
        self.init(object: PtrOperand(val), unowned: unowned, irName: irName)
    }
    
    private init(object: PtrOperand, unowned: Bool, irName: String?) {
        self.object = object
        self.unowned = unowned
        self.args = [object]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return object.memType }
    
    var hasSideEffects: Bool { return true }
    
    var vir: String {
        return "\(name) = \(unowned ? "release_unowned_object" : "release_object") \(object.valueName)\(useComment)"
    }
    weak var parentBlock: BasicBlock?
    var irName: String?
}

/**
 Dealloc a refcounted object - if unowned only deallocs if the refcount 
 is 0. Lowered to a call of `vist_deallocObject()` or `vist_deallocUnownedObject()`
 
 ```
 dealloc_object %0:%Foo.refcounted
 dealloc_unowned_object %0:%Foo.refcounted
 ```
 */
final class DeallocObjectInst : Inst {
    var object: PtrOperand, unowned: Bool
    
    var uses: [Operand] = []
    var args: [Operand]

    convenience init(val: LValue, unowned: Bool, irName: String? = nil) {
        self.init(object: PtrOperand(val), unowned: unowned, irName: irName)
    }
    
    private init(object: PtrOperand, unowned: Bool, irName: String?) {
        self.object = object
        self.unowned = unowned
        self.args = [object]
        initialiseArgs()
        self.irName = irName
    }
    
    var type: Type? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return object.memType }
    
    var hasSideEffects: Bool { return true }
    
    var vir: String {
        return "\(name) = \(unowned ? "dealloc_unowned_object" : "dealloc_object") \(object.valueName)\(useComment)"
    }
    weak var parentBlock: BasicBlock?
    var irName: String?
}


