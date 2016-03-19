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
    func getter() throws -> RValue
}
/// An Accessor which allows setting, as well as self lookup by ptr
protocol GetSetAccessor: Accessor {
    func setter(val: Operand) throws
    func accessor() -> PtrOperand
}

/// Provides access to a value with backing memory. This value
final class RefAccessor: GetSetAccessor {
    
    private var value: LValue
    
    init(value: LValue) { self.value = value }
    
    func getter() throws -> RValue {
        return try value.module.builder.buildLoad(from: accessor())
    }
    
    func setter(val: Operand) throws {
        try value.module.builder.buildStore(val, in: accessor())
    }
    
    func accessor() -> PtrOperand { return PtrOperand(value) }
}

/// Provides access to values by exposing a getter which returns the value
final class ValAccessor: Accessor {
    
    private var value: RValue
    init(value: RValue) { self.value = value }
    
    func getter() -> RValue { return value }
}


// mutliple users share PtrOperand because this returns the same copy


