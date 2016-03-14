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
    func accessor() -> Address
}

/// Provides access to a value with backing memory. This value
final class RefAccessor: GetSetAccessor {
    
    private var addr: Address
    
    init(_ addr: Address) { self.addr = addr }
    
    func getter() throws -> RValue {
        return try addr.module.builder.buildLoad(from: addr)
    }
    
    func setter(val: Operand) throws {
        try addr.module.builder.buildStore(val, to: addr)
    }
    
    func accessor() -> Address { return addr }
}

/// Provides access to values by exposing a getter which returns the value
final class ValAccessor: Accessor {
    
    private var value: RValue
    init(_ value: RValue) { self.value = value }
    
    func getter() -> RValue { return value }
}


/*
 So far my question of ‘how do I implement mutation’ has yielded the answer

 ‘Well i need to define rvalues and lvalues, then define a Accessor protocol which exposes a getter. NamedStorage and ReferenceStorage conform to it, and reference storage also exposes a setter and a memory accessor (which return the underlying address). when vhirgen’ed rvalues return any Accessor, so the value can be extracted using the getter, and lvalues return the reference storage’ which can be used by users — to store into during mutations, or to get sub elements in member lookups (using the memory accessor)

 so a variable is a NamedVariable if its immutable, and a reference one if it is mutable. mutation is defined by storing in its memory location
 */






