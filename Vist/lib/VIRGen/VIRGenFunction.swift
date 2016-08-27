//
//  VIRGenFunction.swift
//  Vist
//
//  Created by Josef Willsher on 26/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias Cleanup = (VIRGenFunction, ManagedValue) throws -> ()

final class VIRGenFunction {
    var managedValues: [ManagedValue] = []
    let scope: VIRGenScope, builder: Builder
    
    init(scope: VIRGenScope, builder: Builder) {
        self.scope = scope
        self.builder = builder
    }
    
    /// Emits a tempory allocation as a managed value; its cleanup
    /// depends on the type stored
    mutating func emitTempAlloc(memType: Type) throws -> Managed<AllocInst> {
        let alloc = try builder.build(AllocInst(memType: memType.importedType(in: builder.module)))
        return createManaged(Managed<AllocInst>.forUnmanaged(alloc, gen: self))
    }
    
    mutating func cleanup() throws {
        for m in managedValues.reversed() {
            if let cleanup = m.cleanup {
                try cleanup(self, m)
            }
        }
        managedValues.removeAll()
    }
    
    mutating func createManaged<ManagedType : ManagedValue>(_ managed: ManagedType) -> ManagedType {
        managedValues.append(managed)
        return managed
    }
    
    func variable(named name: String) -> AnyManagedValue? {
        return managedValues.first { $0.value.name == name }?.erased
    }
    
}

protocol ManagedValue {
    var value: Value { get }
    var cleanup: Cleanup? { get set }
    var isIndirect: Bool { get }
    var type: Type { get }
    var erased: AnyManagedValue { get }
}
struct Managed<Val : Value> : ManagedValue {
    
    let managedValue: Val
    let isIndirect: Bool
    let type: Type
    
    var cleanup: Cleanup?
    
    var value: Value { return managedValue }
    
    private init(_ value: Val) {
        self.managedValue = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = Managed.cleanupFor(value, type: type, isIndirect: isIndirect)
    }
    private init(value: Val, cleanup: Cleanup?) {
        self.managedValue = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = cleanup
    }
    
    var erased: AnyManagedValue { return AnyManagedValue(erasing: self) }
}

struct AnyManagedValue : ManagedValue {
    
    let managedValue: Value
    let isIndirect: Bool
    let type: Type
    
    var cleanup: Cleanup?
    
    var value: Value { return managedValue }
    
    /// init creates cleanup
    private init(_ value: Value) {
        self.managedValue = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = AnyManagedValue.cleanupFor(value, type: type, isIndirect: isIndirect)
    }
    private init(value: Value, cleanup: Cleanup?) {
        self.managedValue = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = cleanup
    }
    
    init<Val : Value>(erasing managed: Managed<Val>) {
        self.managedValue = managed.managedValue
        self.isIndirect = managed.isIndirect
        self.type = managed.type
        self.cleanup = managed.cleanup
    }
    var erased: AnyManagedValue { return self }
}

extension ManagedValue {
    
    /// Return the type of the val stored
    var rawType: Type {
        return value.type!
    }
    
    static func cleanupFor(_ value: Value, type: Type, isIndirect: Bool) -> Cleanup? {
        if type.isConceptType(), isIndirect {
            return { vgf, val in
                try vgf.builder.build(DestroyAddrInst(addr: val.lValue))
                try vgf.builder.build(DeallocStackInst(address: val.lValue))
            }
        }
        else if isIndirect {
            return { vgf, val in
                try vgf.builder.build(DeallocStackInst(address: val.lValue))
            }
        }
        return nil
    }
    
    static func forUnmanaged(_ value: Value, gen: VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value))
    }
    static func forUnmanaged<Val : Value>(_ value: Val, gen: VIRGenFunction) -> Managed<Val> {
        return gen.createManaged(Managed(value))
    }
    /// Like lvalue params, not just any reference
    static func forLValue(_ value: LValue, gen: VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value: value, cleanup: nil))
    }
    static func forLValue<Val : LValue>(_ value: Val, gen: VIRGenFunction) -> Managed<Val> {
        return gen.createManaged(Managed(value: value, cleanup: nil))
    }
    
    /// `managed` says `returnValue` will clear it up
    static func forwardingCleanup<ManagedType : ManagedValue>(value: Value,
                                  cleanup: Cleanup,
                                  from managed: inout ManagedType,
                                  gen: VIRGenFunction) -> ManagedValue {
        managed.forwardCleanup()
        return gen.createManaged(AnyManagedValue(value: value, cleanup: cleanup))
    }
    /// `managed` says `returnValue` will clear it up
    static func forwardingCleanup<Val : Value, ManagedType : ManagedValue>(value: Val,
                                  cleanup: Cleanup,
                                  from managed: inout ManagedType,
                                  gen: VIRGenFunction) -> Managed<Val> {
        managed.forwardCleanup()
        return gen.createManaged(Managed(value: value, cleanup: cleanup))
    }
    
    var lValue: LValue { return value as! LValue }
    
    
    mutating func forwardCleanup() {
        cleanup = nil
    }
    /// Disable this managed value's cleanup, the user of `forward` must
    /// take care to cleanup this val
    mutating func forward() -> Value {
        forwardCleanup()
        return value
    }
    
    /// Disable this managed value's cleanup, the user of `forward` must
    /// take care to cleanup this lval
    mutating func forwardLValue() -> LValue {
        forwardCleanup()
        return lValue
    }
    
    func borrow() throws -> Self {
        return self
    }
    func copy(gen: VIRGenFunction) throws -> AnyManagedValue {
        guard isIndirect, let type = self.type.getPointeeType(), !type.isTrivial() else {
            return self.erased // return a copy
        }
        if type.isAddressOnly {
            try gen.builder.build(RetainInst(val: lValue))
            return self.erased // return a retained copy
        }
        
        let mem = try gen.emitTempAlloc(memType: type)
        try gen.builder.build(CopyAddrInst(addr: lValue,
                                           out: mem.lValue))
        return mem.erased
    }
    func copy(into dest: ManagedValue, gen: VIRGenFunction) throws {
        if type.isAddressOnly {
            try gen.builder.build(RetainInst(val: lValue))
        }
        
        try gen.builder.build(CopyAddrInst(addr: lValue,
                                           out: dest.lValue))
    }
    
    /// Assigns this value to `dest`, removing this val's cleanup
    mutating func forward(into dest: ManagedValue, gen: VIRGenFunction) throws {
        forwardCleanup()
        if isIndirect {
            try gen.builder.build(CopyAddrInst(addr: lValue,
                                               out: dest.lValue))
        }
        else {
            try gen.builder.build(StoreInst(address: dest.lValue,
                                            value: value))
        }
    }
    
}

extension ManagedValue {
    
    /// Creates a managed value abstracting `self.value` which is of value type
    func coerceToValue(gen: VIRGenFunction) throws -> AnyManagedValue {
        let cpy = try copy(gen: gen)
        // if we already have the value type, return the copy
        guard isIndirect else { return cpy.erased }
        // otherwise load once to get it
        return try gen.builder.buildManaged(LoadInst(address: cpy.lValue), gen: gen).erased
    }
    
    /// Creates a managed value abstracting `self.value` with its own clearup which has the formal type `type`
    ///
    /// This can transform the value by:
    /// - changing the indirection: loading from an indirect value if a loaded type is required
    ///   or storing into new memory if a more indirect type is
    /// - Wrapping the inst in its own existentital container
    /// - note: when changing indirection, we can only coerce 1 different ptr level
    func coerce(to targetType: Type, gen: VIRGenFunction) throws -> AnyManagedValue {
        // if no work is needed, return
        guard targetType != type else {
            return try copy(gen: gen)
        }
        
        // if we want to load; decreasing the indirection level
        if isIndirect, let pointee = type.getPointeeType(), pointee == targetType {
            var cpy = try copy(gen: gen)
            return try gen.builder.buildManaged(LoadInst(address: cpy.forwardLValue()), gen: gen).erased
        }
        // if we want to store; increasing the indirection level
        if let pointee = targetType.getPointeeType(), pointee == type {
            let alloc = try gen.emitTempAlloc(memType: pointee)
            try copy(into: alloc, gen: gen)
            return alloc.erased
        }
        
        if targetType.isConceptType() {
            let conceptType = try targetType.getAsConceptType()
            // Create a copy of this value, and forward its clearup to the existential
            var taken = try coerceToValue(gen: gen)
            return try gen.builder.buildManaged(ExistentialConstructInst(value: taken.forward(),
                                                                         existentialType: conceptType,
                                                                         module: gen.builder.module),
                                                gen: gen).erased
        }
        
        fatalError("Could not coerce \(type.prettyName) to \(targetType.prettyName)")
    }
    
}


