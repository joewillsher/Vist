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
    let scope: VIRGenScope, builder: VIRBuilder
    
    var module: Module { return builder.module }
    
    init(scope: VIRGenScope, builder: VIRBuilder) {
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
    var id: Int { get }
    var hasCleanup: Bool { get set }
    var isIndirect: Bool { get }
    var type: Type { get }
    var erased: AnyManagedValue { get }
}
struct Managed<Val : Value> : ManagedValue {
    
    let managedValue: Val
    let isIndirect: Bool
    let type: Type
    let id: Int
    
    var hasCleanup: Bool
    
    var value: Value { return managedValue }
    
    private init(_ value: Val, hasCleanup: Bool = true) {
        self.managedValue = value
        self.isIndirect = value.isIndirect
        self.type = value.type!.getBasePointeeType().getConcreteNominalType() ?? value.type!.getCannonicalType()
        self.hasCleanup = hasCleanup
        self.id = 0
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
    
    func unique() -> AnyManagedValue {
        return AnyManagedValue(managedValue: managedValue, isIndirect: isIndirect, type: type, id: id+1, hasCleanup: hasCleanup)
    }
}

struct AnyManagedValue : ManagedValue {
    
    let managedValue: Value
    let isIndirect: Bool
    let type: Type
    
    let id: Int
    var hasCleanup: Bool
    
    var value: Value { return managedValue }
    
    /// init creates cleanup
    private init(_ value: Value, hasCleanup: Bool = true) {
        self.managedValue = value
        self.isIndirect = value.isIndirect
        self.type = value.type!.getBasePointeeType().getConcreteNominalType() ?? value.type!.getCannonicalType()
        self.hasCleanup = hasCleanup
        self.id = 0
    }
    
    init<Val : Value>(erasing managed: Managed<Val>) {
        self.managedValue = managed.managedValue
        self.isIndirect = managed.isIndirect
        self.type = managed.type
        self.hasCleanup = managed.hasCleanup
        self.id = 0
    }
    var erased: AnyManagedValue { return self }
    
    static func forUnmanaged(_ value: Value, gen: VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value))
    }
    /// Like lvalue params, not just any reference
    static func forLValue(_ value: LValue, gen: VIRGenFunction) -> AnyManagedValue {
        return gen.createManaged(AnyManagedValue(value, hasCleanup: false))
    }
    fileprivate init(managedValue: Value, isIndirect: Bool, type: Type, id: Int, hasCleanup: Bool) {
        self.managedValue = managedValue
        self.isIndirect = isIndirect
        self.type = type
        self.id = id+1
        self.hasCleanup = hasCleanup
    }
}

extension ManagedValue {
    
    /// Return the type of the val stored
    var rawType: Type {
        return value.type!
    }
    /// - returns: an erased version with a different id
    func unique() -> AnyManagedValue {
        return AnyManagedValue(managedValue: value, isIndirect: isIndirect, type: type, id: id+1, hasCleanup: hasCleanup)
    }
    func getCleanup() -> Cleanup? {
        if !type.isTrivial() {
            if type.isClassType(), isIndirect {
                return { vgf, val in
                    try vgf.builder.build(ReleaseInst(object: val.lValue))
                }
            }
            if isIndirect {
                return { vgf, val in
                    try vgf.builder.build(DestroyAddrInst(addr: val.lValue))
                }
            }
            return { vgf, val in
                // no-op
                try vgf.builder.build(DestroyValInst(val: val.value))
            }
        }
        else if isIndirect {
            if type.isClassType() {
                return { vgf, val in
                    try vgf.builder.build(ReleaseInst(object: val.lValue))
                }
            }
            return { vgf, val in
                // no-op
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
            where gen.managedValues[index].value === self.value && gen.managedValues[index].id == self.id {
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
            // return a copy if the type can be trivially copied
            if self.type.isTrivial() {
                return self.unique()
            }
            // retain and return the original, if we have a class
            if isIndirect, self.type.isClassType() {
                try gen.builder.build(RetainInst(object: lValue))
                return self.unique()
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
        // if it is a class, retain and return the original
        if isIndirect, type.isClassType() {
            try gen.builder.build(RetainInst(object: lValue))
            return self.erased // return a retained copy
        }
        
        // this creates the new cleanup
        let mem = try gen.emitTempAlloc(memType: type)
        try gen.builder.build(CopyAddrInst(addr: lValue,
                                           out: mem.lValue))
        return mem.erased
    }
    func copy(into dest: ManagedValue, gen: VIRGenFunction) throws {
        // retain any class instances
        if isIndirect, type.isClassType() {
            try gen.builder.build(RetainInst(object: lValue))
        }
        // copy/move it to the new mem
        if isIndirect {
            try gen.builder.build(CopyAddrInst(addr: lValue,
                                               out: dest.lValue))
        } else {
            try gen.builder.build(StoreInst(address: dest.lValue, value: value))
        }
    }
    
    /// Assigns this value to `dest`, removing this val's cleanup
    mutating func forward<Man : ManagedValue>(into dest: inout Man, gen: VIRGenFunction) throws {
        forwardCleanup(gen)
        // if they are the same indirection level, copy_addr
        if rawType == dest.rawType {
            try gen.builder.build(CopyAddrInst(addr: lValue,
                                               out: dest.lValue))
        } else {
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
        // dig through pointer levels until its raw type is not a ptr
        while isIndirect, rawType.isPointerType() {
            // forward the temp's cleanup to the next load
            self = try gen.builder.buildManaged(LoadInst(address: forwardLValue(gen)), hasCleanup: hasCleanup, gen: gen).erased
            forwardCleanup(gen)
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
            let load = try gen.builder.buildManaged(LoadInst(address: lValue), hasCleanup: hasCleanup, gen: gen).erased
            forwardCleanup(gen)
            self = load
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
            // if it isnt a class type...
            if !type.isClassType() {
                // ...coerce self's managed val to a value type
                try forwardCoerceToValue(gen: gen)
                assert(rawType is NominalType)
            }
            let conceptType = try targetType.getBasePointeeType().getAsConceptType()
            assert((type as! NominalType).models(concept: conceptType))
            // form an existential by forwarding self's cleanup to it
            let ex = try gen.builder.buildManaged(ExistentialConstructInst(value: value,
                                                                           existentialType: conceptType,
                                                                           module: gen.module),
                                                  hasCleanup: hasCleanup,
                                                  gen: gen).erased
            forwardCleanup(gen)
            self = ex
            // coerce the existential to the target type; this should just change the
            // indirection level as self.type is Concept*
            try forwardCoerce(to: targetType, gen: gen)
            return
        }
        
        fatalError("Could not coerce \(rawType.prettyName) to \(targetType.prettyName)")
    }
    
}

extension VIRBuilder {
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
