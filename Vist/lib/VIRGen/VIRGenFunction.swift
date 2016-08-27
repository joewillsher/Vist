//
//  VIRGenFunction.swift
//  Vist
//
//  Created by Josef Willsher on 26/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias Cleanup = (VIRGenFunction, ManagedValue) throws -> ()

struct VIRGenFunction {
    var managedValues: [ManagedValue] = []
    let scope: VIRGenScope, builder: Builder
    
    init(scope: VIRGenScope, builder: Builder) {
        self.scope = scope
        self.builder = builder
    }
    
    /// Emits a tempory allocation as a managed value; its cleanup
    /// depends on the type stored
    mutating func emitTempAlloc(memType: Type) throws -> Managed<AllocInst> {
        let alloc = try builder.build(inst: AllocInst(memType: memType.importedType(in: builder.module)))
        return createManaged(Managed<AllocInst>.forUnmanaged(alloc, gen: &self))
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
    
}

protocol ManagedValue {
    var value: Value { get }
    var cleanup: Cleanup? { get set }
    var isIndirect: Bool { get }
    var type: Type { get }
}
struct Managed<Val : Value> : ManagedValue {
    
    let val: Val
    let isIndirect: Bool
    let type: Type
    
    var cleanup: Cleanup?
    
    var value: Value { return val }
    
    private init(_ value: Val) {
        self.val = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = Managed.cleanupFor(value, type: type, isIndirect: isIndirect)
    }
    private init(value: Val, cleanup: Cleanup?) {
        self.val = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = cleanup
    }
}

struct AnyManagedValue : ManagedValue {
    
    let value: Value
    let isIndirect: Bool
    let type: Type
    
    var cleanup: Cleanup?
    
    /// init creates cleanup
    private init(_ value: Value) {
        self.value = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = AnyManagedValue.cleanupFor(value, type: type, isIndirect: isIndirect)
    }
    private init(value: Value, cleanup: Cleanup?) {
        self.value = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = cleanup
    }
}

extension ManagedValue {
    
    static func cleanupFor(_ value: Value, type: Type, isIndirect: Bool) -> Cleanup? {
        if type.isConceptType(), isIndirect {
            return { vgf, val in
                try vgf.builder.build(inst: DestroyAddrInst(addr: val.lValue))
                try vgf.builder.build(inst: DeallocStackInst(address: val.lValue))
            }
        }
        else if isIndirect {
            return { vgf, val in
                try vgf.builder.build(inst: DeallocStackInst(address: val.lValue))
            }
        }
        return nil
    }
    
    static func forUnmanaged(_ value: Value, gen: inout VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value))
    }
    static func forUnmanaged<Val : Value>(_ value: Val, gen: inout VIRGenFunction) -> Managed<Val> {
        return gen.createManaged(Managed(value))
    }
    /// Like lvalue params, not just any reference
    static func forLValue(_ value: LValue, gen: inout VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value: value, cleanup: nil))
    }
    static func forLValue<Val : LValue>(_ value: Val, gen: inout VIRGenFunction) -> Managed<Val> {
        return gen.createManaged(Managed(value: value, cleanup: nil))
    }
    
    /// `managed` says `returnValue` will clear it up
    static func forwardingCleanup<ManagedType : ManagedValue>(value: Value,
                                  cleanup: Cleanup,
                                  from managed: inout ManagedType,
                                  gen: inout VIRGenFunction) -> ManagedValue {
        managed.forwardCleanup()
        return gen.createManaged(AnyManagedValue(value: value, cleanup: cleanup))
    }
    /// `managed` says `returnValue` will clear it up
    static func forwardingCleanup<Val : Value, ManagedType : ManagedValue>(value: Val,
                                  cleanup: Cleanup,
                                  from managed: inout ManagedType,
                                  gen: inout VIRGenFunction) -> Managed<Val> {
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
    
    func borrow() throws -> ManagedValue {
        return self
    }
    func copy(gen: inout VIRGenFunction) throws -> ManagedValue {
        guard isIndirect, let type = self.type.getPointeeType(), !type.isTrivial() else {
            return self // return a copy
        }
        if type.isAddressOnly {
            try gen.builder.build(inst: RetainInst(val: lValue))
            return self // return a copy
        }
        
        let mem = try gen.emitTempAlloc(memType: type)
        try gen.builder.build(inst: CopyAddrInst(addr: lValue,
                                                 out: mem.lValue))
        return mem
    }
    func copy(into dest: ManagedValue, gen: inout VIRGenFunction) throws {
        if type.isAddressOnly {
            try gen.builder.build(inst: RetainInst(val: lValue))
        }
        
        try gen.builder.build(inst: CopyAddrInst(addr: lValue,
                                                 out: dest.lValue))
    }
    
    /// Assigns this value to `dest`, removing this val's cleanup
    mutating func forward(into dest: ManagedValue, gen: inout VIRGenFunction) throws {
        forwardCleanup()
        if isIndirect {
            try gen.builder.build(inst: CopyAddrInst(addr: lValue,
                                                     out: dest.lValue))
        }
        else {
            try gen.builder.build(inst: StoreInst(address: dest.lValue,
                                                  value: value))
        }
    }
    
}

extension ManagedValue {
    
    /// Creates a managed value abstracting `self.value` which is of value type
    func coerceToValue(gen: inout VIRGenFunction) throws -> ManagedValue {
        let cpy = try copy(gen: &gen)
        // if we already have the value type, return the copy
        guard isIndirect else { return cpy }
        // otherwise load once to get it
        return try gen.builder.buildManaged(inst: LoadInst(address: cpy.lValue), gen: &gen)
    }
    
    /// Creates a managed value abstracting `self.value` with its own clearup which has the formal type `type`
    ///
    /// This can transform the value by:
    /// - changing the indirection: loading from an indirect value if a loaded type is required
    ///   or storing into new memory if a more indirect type is
    /// - Wrapping the inst in its own existentital container
    /// - note: when changing indirection, we can only coerce 1 different ptr level
    func coerce(to targetType: Type, gen: inout VIRGenFunction) throws -> ManagedValue {
        // if no work is needed, return
        guard targetType != type else {
            return try copy(gen: &gen)
        }
        
        // if we want to load; decreasing the indirection level
        if isIndirect, let pointee = type.getPointeeType(), pointee == targetType {
            var cpy = try copy(gen: &gen)
            return try gen.builder.buildManaged(inst: LoadInst(address: cpy.forwardLValue()), gen: &gen)
        }
        // if we want to store; increasing the indirection level
        if let pointee = targetType.getPointeeType(), pointee == type {
            let alloc = try gen.emitTempAlloc(memType: pointee)
            try copy(into: alloc, gen: &gen)
            return alloc
        }
        
        if targetType.isConceptType() {
            let conceptType = try targetType.getAsConceptType()
            // Create a copy of this value, and forward its clearup to the existential
            var taken = try coerceToValue(gen: &gen)
            return try gen.builder.buildManaged(inst: ExistentialConstructInst(value: taken.forward(),
                                                                               existentialType: conceptType,
                                                                               module: gen.builder.module),
                                                gen: &gen)
        }
        
        fatalError("Could not coerce \(type.prettyName) to \(targetType.prettyName)")
    }
    
}


