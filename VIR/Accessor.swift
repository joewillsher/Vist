//
//  Accessor.swift
//  Vist
//
//  Created by Josef Willsher on 12/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/**
 Provides means of reading a value from memory. A `getter` allows loading of a value.
 
 This exposes many methods for optionally refcounting the Accessor, they defualt to noops.
 */
protocol Accessor : class {
    
    /// Gets the value from the stored object
    /// - note: If the stored instance of type `storedType` is a
    ///         box then this is not equal to the result of calling
    ///         `aggregateGetter()`
    func getter() throws -> Value
    
    /// Returns copy of this acccessor with reference semantics
    /// - note: not guaranteed to be a reference to the original.
    func asReferenceAccessor() throws -> GetSetAccessor
    
    var storedType: Type? { get }
    
    /// Retrieve an independent copy of the object
    func getMemCopy() throws -> GetSetAccessor
    /// Get the whole object as-is
    func aggregateGetter() throws -> Value
    
    func release() throws
    func retain() throws
    func releaseUnowned() throws
    func dealloc() throws
    func deallocUnowned() throws
}

/// Provides access to values by exposing a getter which returns the value
final class ValAccessor : Accessor {
    
    private var value: Value
    init(value: Value) { self.value = value }
    
    func getter() -> Value { return value }
    
    /// Alloc a new accessor and store self into it.
    /// - returns: a reference backed *copy* of `self`
    func asReferenceAccessor() throws -> GetSetAccessor {
        return try value.allocGetSetAccessor()
    }
    
    var storedType: Type? { return value.type }
}

// Helper function for constructing a reference copy
extension Value {
    /// Builds a reference accessor which can store into & load from
    /// the memory it allocates
    func allocGetSetAccessor() throws -> GetSetAccessor {
        let accessor = RefAccessor(memory: try module.builder.buildAlloc(type!))
        try accessor.setter(Operand(self))
        return accessor
    }
}

extension Accessor {
    
    func getMemCopy() throws -> GetSetAccessor {
        return try aggregateGetter().accessor().asReferenceAccessor()
    }
    
    func release() { }
    func retain() { }
    func releaseUnowned() { }
    func dealloc() { }
    func deallocUnowned() { }
    
    func aggregateGetter() throws -> Value {
        return try getter()
    }
}







/// An Accessor which allows setting, as well as self lookup by ptr
protocol GetSetAccessor : Accessor {
    var mem: LValue { get }
    /// Stores `val` in the stored object
    func setter(val: Operand) throws
    /// The pointer to the stored object
    func reference() throws -> PtrOperand
    
    /// Return the aggregate reference -- not guaranteed to be the same
    /// as the location `reference` uses to access elements
    func aggregateReference() -> PtrOperand
        
    var module: Module { get }
}

extension GetSetAccessor {
    // if its already a red accessor we're done
    func asReferenceAccessor() throws -> GetSetAccessor { return self }
    
    var storedType: Type? { return mem.memType }
    
    func getter() throws -> Value {
        return try module.builder.buildLoad(from: reference())
    }
    
    func setter(val: Operand) throws {
        try module.builder.buildStore(val, in: reference())
    }
    
    // default impl of `reference` is a projection of the storage
    func reference() -> PtrOperand {
        return PtrOperand(mem)
    }
    // default impl of `aggregateReference` is the same as `reference`
    func aggregateReference() -> PtrOperand {
        return PtrOperand(mem)
    }
    
    func aggregateGetter() throws -> Value {
        return try module.builder.buildLoad(from: aggregateReference())
    }
    func aggregateSetter(val: Operand) throws {
        try module.builder.buildStore(val, in: aggregateReference())
    }
    
    var module: Module { return mem.module }
}







// MARK: Implementations


/// Provides access to a value with backing memory
final class RefAccessor : GetSetAccessor {
    var mem: LValue
    init(memory: LValue) { self.mem = memory }
}

/// Provides access to a global value with backing memory
final class GlobalRefAccessor : GetSetAccessor {
    var mem: LValue
    unowned var module: Module
    init(memory: LValue, module: Module) {
        self.mem = memory
        self.module = module
    }
}
/// Provides access to a global value with backing memory which
/// is a pointer to the object. Global object has type storedType**
/// and loads are
final class GlobalIndirectRefAccessor : GetSetAccessor {
    var mem: LValue
    unowned var module: Module
    
    init(memory: LValue, module: Module) {
        self.mem = memory
        self.module = module
    }
    
    private lazy var memsubsc: PtrOperand = { [unowned self] in
        try! PtrOperand.fromReferenceRValue(self.module.builder.buildLoad(from: PtrOperand(self.mem)))
    }()
    
    // the object reference is stored in self.mem, load it from there
    func reference() throws -> PtrOperand {
        return memsubsc
    }
    
    func aggregateReference() -> PtrOperand {
        return memsubsc
    }
}

/**
 An accessor whose memory is reference counted
 
 This exposes API to `alloc`, `retain`, `release`, and `dealloc` ref coutned
 heap pointers.
*/
final class RefCountedAccessor : GetSetAccessor {
    var mem: LValue
    
    init(refcountedBox: LValue, _reference: Value? = nil) {
        self.mem = refcountedBox
        self._reference = _reference
    }
    
    var _reference: Value? // lazy member reference
    
    /// Get the refcounted object
    private func _object() throws -> Value {
        return try module.builder.buildLoad(from: aggregateReference())
    }
    
    func reference() throws -> PtrOperand {
        if let r = _reference { return try PtrOperand.fromReferenceRValue(r) }
        
        let ref = try module.builder.buildStructElementPtr(aggregateReference(), property: "object")
        let load = try module.builder.buildLoad(from: PtrOperand(ref), irName: mem.irName.map { "\($0).instance" })
        
        return try PtrOperand.fromReferenceRValue(load)
    }
    
    /// A reference to the whole object
    func aggregateReference() -> PtrOperand {
        return PtrOperand(mem)
    }
    
    /// Getting the whole of a refcounted object means you are passing its structure.
    /// - returns: The identity of a ref counted object, which is its backing pointer
    func aggregateGetter() throws -> Value {
        return mem
    }
    
    /// Retain a reference, increment the ref count
    func retain() throws {
        try module.builder.buildRetain(aggregateReference())
    }
    
    /// Releases the object without decrementing the ref count.
    /// - note: Used in returns as the user of the return is expected
    ///         to either `retain` it or `deallocUnowned` it
    func releaseUnowned() throws {
        try module.builder.buildReleaseUnowned(aggregateReference())
    }
    
    /// Release a reference, decrement the ref count
    func release() throws {
        try module.builder.buildRelease(aggregateReference())
    }
    
    /// Deallocates the object
    func dealloc() throws {
        try module.builder.buildDeallocObject(aggregateReference())
    }
    
    /// Deallocates an unowned object if the ref count is 0
    func deallocUnowned() throws {
        try module.builder.buildDeallocUnownedObject(aggregateReference())
    }
    
    /// Capture another reference to the object and retain it
    func getMemCopy() throws -> GetSetAccessor {
        try retain()
        return RefCountedAccessor(refcountedBox: aggregateReference(), _reference: _reference)
    }

    // TODO: Implement getRefCount and ref_count builtin
//    func getRefCount() throws -> Value {
//        
//    }
    
    /// Allocate a heap object and retain it
    /// - returns: the object's accessor
    static func allocObject(type type: StructType, module: Module) throws -> RefCountedAccessor {
        
        let val = try module.builder.buildAllocObject(type, irName: "storage")
        let bc = try module.builder.buildBitcast(from: PtrOperand(val), newType: type.refCountedBox(module))
        
        let accessor = RefCountedAccessor(refcountedBox: bc)
        try accessor.retain()
        return accessor
    }
    
}


/// A Ref accessor whose accessor is evaluated on demand. Useful for values
/// which might not be used
final class LazyRefAccessor : GetSetAccessor {
    private var build: () throws -> LValue
    private lazy var val: LValue? = try? self.build()
    
    var mem: LValue {
        guard let v = val else {
            do {
                try build()
                fatalError()
            } catch {
                fatalError(String(error))
            }
            
        }
        return v
    }
    
    init(module: Module, fn: () throws -> LValue) {
        build = fn
        self.module = module
    }
    
    var module: Module
}


final class LazyAccessor : Accessor {
    private var build: () throws -> Value
    private lazy var val: Value? = try? self.build()
    
    var storedType: Type? { return val?.type }

    func getter() throws -> Value {
        guard let v = val else { fatalError() }
        return v
    }
    
    func asReferenceAccessor() throws -> GetSetAccessor {
        guard let v = val else { fatalError() }
        return try v.allocGetSetAccessor()
    }
    
    init(module: Module, fn: () throws -> Value) {
        build = fn
        self.module = module
    }
    
    var module: Module
}



