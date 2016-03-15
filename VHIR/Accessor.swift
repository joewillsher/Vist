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
    func accessor() -> Operand
}

/// Provides access to a value with backing memory. This value
final class RefAccessor: GetSetAccessor {
    
    private var addr: PtrOperand
    
    init(_ addr: PtrOperand) { self.addr = addr }
    
    func getter() throws -> RValue {
        return try addr.module.builder.buildLoad(from: addr)
    }
    
    func setter(val: Operand) throws {
        try addr.module.builder.buildStore(val, in: addr)
    }
    
    func accessor() -> Operand { return addr }
}

/// Provides access to values by exposing a getter which returns the value
final class ValAccessor: Accessor {
    
    private var value: RValue
    init(_ value: RValue) { self.value = value }
    
    func getter() -> RValue { return value }
}





