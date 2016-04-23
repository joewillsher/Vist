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
final class AllocObjectInst : InstBase, LValue {
    var storedType: StructType
    
    private init(memType: StructType, irName: String?) {
        self.storedType = memType
        super.init(args: [], irName: irName)
    }
    
    var refType: Type { return storedType.refCountedBox(module).usingTypesIn(module) }
    override var type: Type? { return memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return Runtime.refcountedObjectType.usingTypesIn(module) }
    
    override var instVIR: String {
        return "\(name) = alloc_object \(refType) \(useComment)"
    }
}

/**
 Retain a refcounted object - increments the ref count. Lowered to
 a call of `vist_retainObject()`
 
 `retain_object %0:%Foo.refcounted`
 */
final class RetainInst : InstBase {
    var object: PtrOperand
    
    private init(object: PtrOperand, irName: String?) {
        self.object = object
        super.init(args: [object], irName: irName)
    }
    
    override var type: Type? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return object.memType }
    
    override var instHasSideEffects: Bool { return true }
    
    override var instVIR: String {
        return "\(name) = retain_object \(object) \(useComment)"
    }
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
final class ReleaseInst : InstBase {
    var object: PtrOperand, unowned: Bool
    
    private init(object: PtrOperand, unowned: Bool, irName: String?) {
        self.object = object
        self.unowned = unowned
        super.init(args: [object], irName: irName)
    }
    
    override var type: Type? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return object.memType }
    
    override var instHasSideEffects: Bool { return true }
    
    override var instVIR: String {
        return "\(name) = \(unowned ? "release_unowned_object" : "release_object") \(object) \(useComment)"
    }
}

/**
 Dealloc a refcounted object - if unowned only deallocs if the refcount 
 is 0. Lowered to a call of `vist_deallocObject()` or `vist_deallocUnownedObject()`
 
 ```
 dealloc_object %0:%Foo.refcounted
 dealloc_unowned_object %0:%Foo.refcounted
 ```
 */
final class DeallocObjectInst : InstBase {
    var object: PtrOperand, unowned: Bool
    
    private init(object: PtrOperand, unowned: Bool, irName: String?) {
        self.object = object
        self.unowned = unowned
        super.init(args: [object], irName: irName)
    }
    
    override var type: Type? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Type? { return object.memType }
    
    override var instHasSideEffects: Bool { return true }
    
    override var instVIR: String {
        return "\(name) = \(unowned ? "dealloc_unowned_object" : "dealloc_object") \(object) \(useComment)"
    }
}

extension Builder {
    
    func buildAllocObject(type: StructType, irName: String? = nil) throws -> AllocObjectInst {
        return try _add(AllocObjectInst(memType: type, irName: irName))
    }
    func buildRetain(object: PtrOperand, irName: String? = nil) throws -> RetainInst {
        return try _add(RetainInst(object: object, irName: irName))
    }
    func buildRelease(object: PtrOperand, irName: String? = nil) throws -> ReleaseInst {
        return try _add(ReleaseInst(object: object, unowned: false, irName: irName))
    }
    func buildReleaseUnowned(object: PtrOperand, irName: String? = nil) throws -> ReleaseInst {
        return try _add(ReleaseInst(object: object, unowned: true, irName: irName))
    }
    func buildDeallocObject(object: PtrOperand, irName: String? = nil) throws -> DeallocObjectInst {
        return try _add(DeallocObjectInst(object: object, unowned: false, irName: irName))
    }
    func buildDeallocUnownedObject(object: PtrOperand, irName: String? = nil) throws -> DeallocObjectInst {
        return try _add(DeallocObjectInst(object: object, unowned: true, irName: irName))
    }
}


