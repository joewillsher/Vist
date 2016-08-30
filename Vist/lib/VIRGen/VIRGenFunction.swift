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
    
    var module: Module { return builder.module }
    
    init(scope: VIRGenScope, builder: Builder) {
        self.scope = scope
        self.builder = builder
    }
    
    /// Emits a tempory allocation as a managed value; its cleanup
    /// depends on the type stored
    func emitTempAlloc(memType: Type) throws -> Managed<AllocInst> {
        return try builder.buildUnmanaged(AllocInst(memType: memType.importedType(in: builder.module)), gen: self)
    }
    
    func cleanup() throws {
        for m in managedValues.reversed() {
            if m.hasCleanup, let cleanup = m.getCleanup() {
                try cleanup(self, m)
            }
        }
        managedValues.removeAll()
    }
    
    func createManaged<ManagedType : ManagedValue>(_ managed: ManagedType) -> ManagedType {
        managedValues.append(managed)
        return managed
    }
}

protocol ManagedValue {
    var value: Value { get }
    var hasCleanup: Bool { get set }
    var isIndirect: Bool { get }
    var type: Type { get }
    var erased: AnyManagedValue { get }
}
struct Managed<Val : Value> : ManagedValue {
    
    let managedValue: Val
    let isIndirect: Bool
    let type: Type
    
    var hasCleanup: Bool
    
    var value: Value { return managedValue }
    
    private init(_ value: Val, hasCleanup: Bool = true) {
        self.managedValue = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType!.getConcreteNominalType() ?? value.type!.getCannonicalType()
        self.hasCleanup = hasCleanup
    }
    
    var erased: AnyManagedValue { return AnyManagedValue(erasing: self) }
    
    mutating func forward(_ gen: VIRGenFunction) -> Val {
        forwardCleanup(gen)
        return managedValue
    }
    
    static func forUnmanaged(_ value: Val, gen: VIRGenFunction) -> Managed<Val> {
        return gen.createManaged(Managed(value))
    }
    static func forLValue(_ value: Val, gen: VIRGenFunction) -> Managed<Val> {
        return gen.createManaged(Managed(value, hasCleanup: false))
    }
    static func forManaged(_ value: Val, hasCleanup: Bool, gen: VIRGenFunction) -> Managed<Val> {
        return gen.createManaged(Managed(value, hasCleanup: hasCleanup))
    }
}

struct AnyManagedValue : ManagedValue {
    
    let managedValue: Value
    let isIndirect: Bool
    let type: Type
    
    var hasCleanup: Bool
    
    var value: Value { return managedValue }
    
    /// init creates cleanup
    private init(_ value: Value, hasCleanup: Bool = true) {
        self.managedValue = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType!.getConcreteNominalType() ?? value.type!.getCannonicalType()
        self.hasCleanup = hasCleanup
    }
    
    init<Val : Value>(erasing managed: Managed<Val>) {
        self.managedValue = managed.managedValue
        self.isIndirect = managed.isIndirect
        self.type = managed.type
        self.hasCleanup = managed.hasCleanup
    }
    var erased: AnyManagedValue { return self }
    
    static func forUnmanaged(_ value: Value, gen: VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value))
    }
    /// Like lvalue params, not just any reference
    static func forLValue(_ value: LValue, gen: VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value, hasCleanup: false))
    }
}

extension ManagedValue {
    
    /// Return the type of the val stored
    var rawType: Type {
        return value.type!
    }
    
    func getCleanup() -> Cleanup? {
        if !type.isTrivial() {
            if isIndirect {
                return { vgf, val in
                    try vgf.builder.build(DestroyAddrInst(addr: val.lValue))
                    try vgf.builder.build(DeallocStackInst(address: val.lValue))
                }
            }
            return { vgf, val in
                try vgf.builder.build(DestroyValInst(val: val.value))
            }
        }
        else if isIndirect {
            if type.isHeapAllocated {
                return { vgf, val in
                    try vgf.builder.build(ReleaseInst(val: val.lValue, unowned: false))
                    try vgf.builder.build(DeallocStackInst(address: val.lValue))
                }
            }
            return { vgf, val in
                try vgf.builder.build(DeallocStackInst(address: val.lValue))
            }
        }
        return nil
    }
    
    /// `managed` says `returnValue` will clear it up
    static func forwardingCleanup<ManagedType : ManagedValue>(value: Value,
                                  hasCleanup: Bool,
                                  from managed: inout ManagedType,
                                  gen: VIRGenFunction) -> ManagedValue {
        managed.forwardCleanup(gen)
        return gen.createManaged(AnyManagedValue(value, hasCleanup: hasCleanup))
    }
    /// `managed` says `returnValue` will clear it up
    static func forwardingCleanup<Val : Value, ManagedType : ManagedValue>(value: Val,
                                  hasCleanup: Bool,
                                  from managed: inout ManagedType,
                                  gen: VIRGenFunction) -> Managed<Val> {
        managed.forwardCleanup(gen)
        return gen.createManaged(Managed(value, hasCleanup: hasCleanup))
    }
    
    var lValue: LValue { return (value as? LValue) ?? (try! OpaqueLValue(rvalue: value)) }
    
    
    mutating func forwardCleanup(_ gen: VIRGenFunction) {
        hasCleanup = false
        
        // update the VIRGenFunction
        for index in 0..<gen.managedValues.count
            where gen.managedValues[index].value === self.value {
                gen.managedValues[index] = self
        }
    }
    /// Disable this managed value's cleanup, the user of `forward` must
    /// take care to cleanup this val
    mutating func forward(_ gen: VIRGenFunction) -> Value {
        forwardCleanup(gen)
        return value
    }
    
    /// Disable this managed value's cleanup, the user of `forward` must
    /// take care to cleanup this lval
    mutating func forwardLValue(_ gen: VIRGenFunction) -> LValue {
        forwardCleanup(gen)
        return lValue
    }
    
    func borrow() throws -> Self {
        return self
    }
    mutating func copy(gen: VIRGenFunction) throws -> AnyManagedValue {
        // if it isnt a ptr type
        guard isIndirect, let type = self.type.getPointeeType(), !type.isTrivial() else {
            if self.type.isTrivial() {
                return self.erased // return a copy
            }
            // if its not trivial, the copy must be a ptr backed one so
            // we can copy_addr it
            var mem = try gen.emitTempAlloc(memType: self.type).erased
            // - forward self into a temp alloc
            try forward(into: &mem, gen: gen)
            let copiedMem = try gen.emitTempAlloc(memType: self.type)
            try mem.copy(into: copiedMem, gen: gen)
            return copiedMem.erased
        }
        if type.isAddressOnly {
            try gen.builder.build(RetainInst(val: lValue))
            return self.erased // return a retained copy
        }
        
        // this creates the new cleanup
        let mem = try gen.emitTempAlloc(memType: type)
        try gen.builder.build(CopyAddrInst(addr: lValue,
                                           out: mem.lValue))
        return mem.erased
    }
    func copy(into dest: ManagedValue, gen: VIRGenFunction) throws {
        if type.isAddressOnly {
            try gen.builder.build(RetainInst(val: lValue))
        }
        if isIndirect {
            try gen.builder.build(CopyAddrInst(addr: lValue,
                                               out: dest.lValue))
        }
        else {
            try gen.builder.build(StoreInst(address: dest.lValue, value: value))
        }
    }
    
    /// Assigns this value to `dest`, removing this val's cleanup
    mutating func forward<Man : ManagedValue>(into dest: inout Man, gen: VIRGenFunction) throws {
        forwardCleanup(gen)
        // if they are the same indirection level
        if rawType == dest.rawType {
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
    mutating func coerceCopy(to targetType: Type, gen: VIRGenFunction) throws -> AnyManagedValue {
        var new = try copy(gen: gen)
        try new.forwardCoerce(to: targetType, gen: gen)
        return new
    }
    
    /// Creates a managed value abstracting `self.value` with its own clearup which has the formal type `type`
    ///
    /// This can transform the value by:
    /// - changing the indirection: loading from an indirect value if a loaded type is required
    ///   or storing into new memory if a more indirect type is
    /// - Wrapping the inst in its own existentital container
    /// - note: when changing indirection, we can only coerce 1 different ptr level
    mutating func coerceCopyToValue(gen: VIRGenFunction) throws -> AnyManagedValue {
        var new = try copy(gen: gen)
        try new.forwardCoerceToValue(gen: gen)
        return new
    }
    
}

extension AnyManagedValue {
    
    mutating func forwardCoerceToValue(gen: VIRGenFunction) throws {
        defer { forwardCleanup(gen) }
        // dig through pointer levels until its raw type is not a ptr
        while isIndirect, rawType.isPointerType() {
            // forward the temp's cleanup to the next load
            self = try gen.builder.buildManaged(LoadInst(address: forwardLValue(gen)), hasCleanup: hasCleanup, gen: gen).erased
        }
    }
    /// Forms `self` into a managed value abstracting an object of type `targetType`
    mutating func forwardCoerce(to targetType: Type, gen: VIRGenFunction) throws {
        guard targetType != rawType else {
            // if no work is needed
            return
        }
        
        // if we want to load; decreasing the indirection level
        if isIndirect, let pointee = rawType.getPointeeType(), pointee == targetType {
            self = try gen.builder.buildManaged(LoadInst(address: forwardLValue(gen)), hasCleanup: hasCleanup, gen: gen).erased
            return
        }
        // if we want to store; increasing the indirection level
        if let pointee = targetType.getPointeeType(), pointee == rawType {
            var alloc = try gen.builder.buildManaged(AllocInst(memType: pointee.importedType(in: gen.builder.module)),
                                                     hasCleanup: hasCleanup,
                                                     gen: gen).erased
            try forward(into: &alloc, gen: gen)
            self = alloc
            return
        }
        
        if targetType.getBasePointeeType().isConceptType() {
            let conceptType = try targetType.getBasePointeeType().getAsConceptType()
            // coerce self's managed val to a value type
            try forwardCoerceToValue(gen: gen)
            assert(rawType is NominalType)
            assert((rawType as! NominalType).models(concept: conceptType))
            // form an existential by forwarding self's cleanup to it
            self = try gen.builder.buildManaged(ExistentialConstructInst(value: forward(gen),
                                                                         existentialType: conceptType,
                                                                         module: gen.module),
                                                hasCleanup: hasCleanup,
                                                gen: gen).erased
            // coerce the existential to the target type; this should just change the
            // indirection level as self.type is Concept*
            try forwardCoerce(to: targetType, gen: gen)
            return
        }
        
        fatalError("Could not coerce \(rawType.prettyName) to \(targetType.prettyName)")
    }
    
}

extension Builder {
    func buildUnmanaged<I : Inst>(_ inst: I, gen: VIRGenFunction) throws -> Managed<I> {
        try addToCurrentBlock(inst: inst)
        return Managed<I>.forUnmanaged(inst, gen: gen)
    }
    func buildManaged<I : Inst>(_ inst: I, hasCleanup: Bool = false, gen: VIRGenFunction) throws -> Managed<I> {
        try addToCurrentBlock(inst: inst)
        return Managed<I>.forManaged(inst, hasCleanup: hasCleanup, gen: gen)
    }
    func buildUnmanagedLValue<I : Inst>(_ inst: I, gen: VIRGenFunction) throws -> Managed<I> {
        try addToCurrentBlock(inst: inst)
        return Managed<I>.forLValue(inst, gen: gen)
    }
}
