//
//  Accessor.swift
//  Vist
//
//  Created by Josef Willsher on 12/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// Provides means of reading a value from memory
///
/// A `getter` allows loading of a value, and conformants may also provide a ``setter
protocol Accessor {
    /// Gets the value from the stored object
    func getter() throws -> RValue
    /// Returns copy of this acccessor with reference semantics
    /// - note: not guaranteed to be a reference to the original.
    func asReferenceAccessor() throws -> GetSetAccessor
    
    var storedType: Ty? { get }
}


/// An Accessor which allows setting, as well as self lookup by ptr
protocol GetSetAccessor : Accessor {
    var mem: Value { get }
    /// Stores `val` in the stored object
    func setter(val: Operand) throws
    /// The pointer to the stored object
    func reference() -> PtrOperand
}

extension GetSetAccessor {
    // if its already a red accessor we're done
    func asReferenceAccessor() throws -> GetSetAccessor { return self }
    
    var storedType: Ty? { return mem.memType }
    
    func getter() throws -> RValue {
        return try mem.module.builder.buildLoad(from: reference())
    }
    
    func setter(val: Operand) throws {
        try mem.module.builder.buildStore(val, in: reference())
    }
    
    func reference() -> PtrOperand { return PtrOperand(mem) }
}

// TODO: this
// should getter return an operand/ptroperand
// make `try getter().allocGetSetAccessor()` try `value.allocGetSetAccessor()`

// MARK: Implementations

/// Provides access to values by exposing a getter which returns the value
final class ValAccessor : Accessor {
    
    private var value: RValue
    init(value: RValue) { self.value = value }
    
    func getter() -> RValue { return value }
    
    /// Alloc a new accessor and store self into it.
    /// - returns: a reference backed *copy* of `self`
    func asReferenceAccessor() throws -> GetSetAccessor {
        return try getter().allocGetSetAccessor()
    }
    
    var storedType: Ty? { return value.type }
}

// Helper function for constructing a reference copy
private extension RValue {
    /// Builds a reference accessor which can store into & load from
    /// the memory it allocates
    func allocGetSetAccessor() throws -> GetSetAccessor {
        let accessor = RefAccessor(memory: try module.builder.buildAlloc(type!))
        try accessor.setter(Operand(self))
        return accessor
    }
}


/// Provides access to a value with backing memory
final class RefAccessor : GetSetAccessor {
    var mem: Value
    init(memory: Value) { self.mem = memory }
}

/// A Ref accessor whose accessor is evaluated on demand. Useful for values
/// which might not be used
final class LazyRefAccessor : GetSetAccessor {
    private var build: () throws -> Value
    private var val: Value?
    
    var mem: Value {
        if let v = val { return v }
        val = try! build()
        return val!
    }
    
    init(fn: () throws -> Value) { build = fn }
}


// mutliple users share PtrOperand because this returns the same copy


