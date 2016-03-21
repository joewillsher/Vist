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
}
/// An Accessor which allows setting, as well as self lookup by ptr
protocol GetSetAccessor: Accessor {
    /// Stores `val` in the stored object
    func setter(val: Operand) throws
    /// The pointer to the stored object
    func reference() -> PtrOperand
}

/// Provides access to a value with backing memory. This value
final class RefAccessor: GetSetAccessor {
    
    private var value: LValue
    
    init(value: LValue) { self.value = value }
    
    func getter() throws -> RValue {
        return try value.module.builder.buildLoad(from: reference())
    }
    
    func setter(val: Operand) throws {
        try value.module.builder.buildStore(val, in: reference())
    }
    
    func reference() -> PtrOperand { return PtrOperand(value) }
}

/// Provides access to values by exposing a getter which returns the value
final class ValAccessor: Accessor {
    
    private var value: RValue
    init(value: RValue) { self.value = value }
    
    func getter() -> RValue { return value }
}


// mutliple users share PtrOperand because this returns the same copy


