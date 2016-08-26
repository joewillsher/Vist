//
//  Accessor.swift
//  Vist
//
//  Created by Josef Willsher on 12/03/2016.
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
    mutating func emitTempAlloc(memType: Type) throws -> ManagedValue {
        let alloc = try builder.build(inst: AllocInst(memType: memType.importedType(in: builder.module)))
        return createManaged(ManagedValue(value: alloc))
    }
    
    mutating func cleanup() throws {
        for m in managedValues.reversed() {
            if let cleanup = m.cleanup {
                try cleanup(self, m)
            }
        }
        managedValues.removeAll()
    }
    
    mutating func createManaged(_ managed: ManagedValue) -> ManagedValue {
        managedValues.append(managed)
        return managed
    }
    
}

struct ManagedValue {
    
    let value: Value
    let isIndirect: Bool
    let type: Type
    
    var cleanup: Cleanup?
    
    private init(value: Value) {
        self.value = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        if type.isConceptType(), isIndirect {
            cleanup = CleanupManager.destroyAddrCleanup
        }
        else if isIndirect {
            cleanup = CleanupManager.addrCleanup
        }
        else {
            cleanup = nil
        }
    }
    
    private init(value: Value, cleanup: Cleanup?) {
        self.value = value
        self.isIndirect = value is LValue
        self.type = (value as? LValue)?.memType ?? value.type!
        self.cleanup = cleanup
    }
    
    init(value: Value, cleanup: Cleanup) {
        self.init(value: value, cleanup: cleanup)
    }
    
    static func forUnmanaged(_ value: Value, gen: inout VIRGenFunction) -> ManagedValue {
        return gen.createManaged(ManagedValue(value: value))
    }
    /// Like lvalue params, not just any reference
    static func forLValue(_ value: Value, gen: inout VIRGenFunction) -> ManagedValue {
        return gen.createManaged(ManagedValue(value: value, cleanup: nil))
    }

    /// `managed` says `returnValue` will clear it up
    static func forwardingCleanup(value: Value, cleanup: Cleanup, from managed: inout ManagedValue, gen: inout VIRGenFunction) -> ManagedValue {
        managed.forwardCleanup()
        return gen.createManaged(ManagedValue(value: value, cleanup: cleanup))
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
    mutating func coerceToValue(gen: inout VIRGenFunction) throws -> ManagedValue {
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
    mutating func coerce(to targetType: Type, gen: inout VIRGenFunction) throws -> ManagedValue {
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









final class CleanupManager {
    
    var cleanups: [Cleanup] = []
    
//    static let releaseCleanup: Cleanup = { vgf, val in
//        _ = try vgf.builder.build(inst: RetainInst(val: OpaqueLValue(rvalue: val)))
//    }
    
    static let destroyAddrCleanup: Cleanup = { vgf, val in
        try vgf.builder.build(inst: DestroyAddrInst(addr: val.lValue))
        try vgf.builder.build(inst: DeallocStackInst(address: val.lValue))
    }
    static let addrCleanup: Cleanup = { vgf, val in
        try vgf.builder.build(inst: DeallocStackInst(address: val.lValue))
    }

    
}












/**
 Provides means of reading a value from memory. A `getter` allows loading of a value.
 
 This exposes many methods for optionally refcounting the Accessor, they defualt to noops.
 */
protocol Accessor : class {
    
    /// Gets the value from the stored object
    /// - note: If the stored instance of type `storedType` is a
    ///         box then this is not equal to the result of calling
    ///         `aggregateGetValue()`
    func getValue() throws -> Value
    
    /// Returns the stored value, including its box
    func aggregateGetValue() throws -> Value
    
    var storedType: Type? { get }
    
    /// Form a copy of `self`
    func getMemCopy() throws -> IndirectAccessor
    
    /// Returns an accessor abstracring the same value but with reference semantics
    /// - note: the returned accessor is not guaranteed to be a reference to the
    ///          original, mutating it may not affect `self`
    func referenceBacked() throws -> IndirectAccessor
    
    /// A scope releases control of this accessor
    func release() throws
    /// Release the temp result of a coersion -- this isn't added to a scope
    /// so cannot be released any other way
    func releaseCoercionTemp() throws
    func retain() throws
    func releaseUnowned() throws
    func dealloc() throws
    func deallocUnowned() throws
    
    func owningAccessor() throws -> Accessor
    func getEscapingValue() throws -> Value
    
    var module: Module { get }
}

/// Provides access to values by exposing a getter which returns the value
final class ValAccessor : ByValueAccessor, Accessor {
    
    var value: Value
    init(value: Value) { self.value = value }
    
    func getValue() -> Value { return value }
    
    /// Alloc a new accessor and store self into it.
    /// - returns: a reference backed *copy* of `self`
    func referenceBacked() throws -> IndirectAccessor {
        return try allocReferenceBackedAccessor()
    }
    
    var storedType: Type? { return value.type }
    var module: Module { return value.module }
}

// Helper function for constructing a reference copy
private extension ByValueAccessor {
    
    /// Builds a reference accessor which can store into & load from
    /// the memory it allocates
    func allocReferenceBackedAccessor() throws -> IndirectAccessor {
        guard let memType = value.type?.importedType(in: module) else {
            throw VIRError.noType(#file)
        }
        let accessor = RefAccessor(memory: try value.module.builder.build(inst: AllocInst(memType: memType)))
        try accessor.setValue(self)
        return accessor
    }
}

extension Accessor {
    
    func getMemCopy() throws -> IndirectAccessor {
        return try aggregateGetValue().accessor().referenceBacked()
    }
    
    func owningAccessor() throws -> Accessor {
        return self
    }
    
    func retain() { }
    func release() throws {
        try module.builder.build(inst: DestroyValInst(val: getValue()))
    }
    func releaseUnowned() { }
    func dealloc() { }
    func deallocUnowned() { }
    func releaseCoercionTemp() { }
    
    func aggregateGetValue() throws -> Value {
        return try getValue()
    }
    
    /// The type system needs to coerce a type into another. Here we insert the
    /// instructions to do so. For example:
    ///
    /// `func foo :: AConcept = ...` is called as `foo aConformant`. If aConformant
    /// is not already an existential we must construct one.
    func coercedAccessor(to expectedType: Type?, module: Module) throws -> Accessor {
        
        // if the function expects an existential, we construct one
        if case let existentialType as ConceptType = expectedType?.getConcreteNominalType(),
            // dont box it if it is already boxed
            storedType?.mangledName != existentialType.mangledName {
            let mem = try module.builder.build(inst: ExistentialConstructInst(value: aggregateGetValue(),
                                                                              existentialType: existentialType,
                                                                              module: module))
            return try ExistentialRefAccessor(memory: mem)
        }
        else {
            return self
        }
    }
    
    func getEscapingValue() throws -> Value {
        return try getValue()
    }
}


/// How was this accessor added to the scope?
enum AccessorPassing {
    /// Passed up from a lower scope, like in a param
    case up
    /// Declared in this scope
    case owning
    /// Passed down from another scope, through a return value
    /// or @out param
    case down
}

final class ExistentialRefAccessor : IndirectAccessor {
    
    var mem: LValue
    let passing: AccessorPassing
    
    init(memory: LValue) throws {
        self.mem = memory
        
        if memory is ExistentialConstructInst {
            passing = .owning
        }
        else {
            var p = AccessorPassing.owning
            for case let use as StoreInst in memory.uses.map({$0.user}) {
                if use.value.value is Param {
                    p = .up
                }
                else if use.value.value is VIRFunctionCall {
                    p = .down
                }
            }
            passing = p
        }
    }
    /// allocates memory and defensively exports it
    init(value: Value, type: ConceptType, module: Module) throws {
        let mem = try module.builder.build(inst: AllocInst(memType: type.importedType(in: module)))
        try module.builder.build(inst: StoreInst(address: mem, value: value))
//        try module.builder.build(inst: ExistentialExportBufferInst(existential: mem))
        self.mem = mem
        self.passing = value is Param ? .down : .owning
    }
    
    func release() throws {
        // If this accessor abstracts the allocation, we can delete it when this scope
        // releases its use
        if passing == .owning || passing == .down {
            try module.builder.build(inst: DestroyAddrInst(addr: mem))
        }
    }
//    func releaseCoercionTemp() throws {
//        try module.builder.build(inst: DestroyAddrInst(existential: mem))
//    }
    
    func aggregateGetValue() throws -> Value {
        return try getValue()
    }
    
    func getMemCopy() throws -> IndirectAccessor {
        let outMem = try module.builder.build(inst: AllocInst(memType: storedType!.importedType(in: module)))
        try module.builder.build(inst: CopyAddrInst(addr: mem, out: outMem))
        return try ExistentialRefAccessor(memory: outMem)
    }
    
    func getEscapingValue() throws -> Value {
        // make sure this buffer is exported
//        try module.builder.build(inst: ExistentialExportBufferInst(existential: mem))
        return try module.builder.build(inst: LoadInst(address: reference()))
    }
    
    
}



private protocol ByValueAccessor : Accessor {
    var value: Value { get }
}

/// An Accessor which allows setting, as well as self lookup by ptr
protocol IndirectAccessor : Accessor {
    var mem: LValue { get }
    /// Stores `val` in the stored object
    func setValue(_ val: Accessor) throws
    /// The pointer to the stored object
    func reference() throws -> LValue
    
    /// A reference into the original value's memory
    func lValueReference() throws -> LValue
    
    /// Return the aggregate reference -- not guaranteed to be the same
    /// as the location `reference` uses to access elements
    func aggregateReference() throws -> LValue
        
}

extension IndirectAccessor {
    // if its already a red accessor we're done
    func referenceBacked() throws -> IndirectAccessor { return self }
    
    var storedType: Type? { return mem.memType }
    
    func getValue() throws -> Value {
        return try module.builder.build(inst: LoadInst(address: reference()))
    }
    
    func setValue(_ accessor: Accessor) throws {
        try module.builder.build(inst: StoreInst(address: lValueReference(),
                                                 value: projectsEscapingMemory() ?
                                                    accessor.getEscapingValue() :
                                                    accessor.aggregateGetValue()))
    }
    
    // default impl of `reference` is a projection of the storage
    func reference() throws -> LValue {
        let outMem = try module.builder.build(inst: AllocInst(memType: storedType!.importedType(in: module)))
        try module.builder.build(inst: CopyAddrInst(addr: mem, out: outMem))
        return outMem
    }
    func lValueReference() throws -> LValue {
        return mem
    }
    
    // default impl of `aggregateReference` is the same as `reference`
    func aggregateReference() throws -> LValue {
        return try reference()
    }
    
    func aggregateGetValue() throws -> Value {
        return try module.builder.build(inst: LoadInst(address: aggregateReference()))
    }
    func aggregateSetter(val: Value) throws {
        try module.builder.build(inst: StoreInst(address: aggregateReference(), value: val))
    }
    
    var module: Module { return mem.module }
    
    
    func release() throws {
        mem.dump()
        if !projectsEscapingMemory() {
            try module.builder.build(inst: DestroyAddrInst(addr: mem))
        }
    }
    
    func getMemCopy() throws -> IndirectAccessor {
        return try aggregateReference().accessor().referenceBacked()
    }
    
    /// Just loads from the val
    func getEscapingValue() throws -> Value {
        return try module.builder.build(inst: LoadInst(address: mem))
    }
    
}







/// Provides access to a value with backing memory
final class RefAccessor : IndirectAccessor {
    var mem: LValue
    init(memory: LValue) { self.mem = memory }
}

/// Provides access to a global value with backing memory
final class GlobalRefAccessor : IndirectAccessor {
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
final class GlobalIndirectRefAccessor : IndirectAccessor {
    var mem: LValue
    unowned var module: Module
    
    init(memory: LValue, module: Module) {
        self.mem = memory
        self.module = module
    }
    
    private lazy var memsubsc: LValue = { [unowned self] in
        let mem = try! self.module.builder.build(inst: LoadInst(address: self.mem))
        return try! OpaqueLValue(rvalue: mem)
    }()
    
    // the object reference is stored in self.mem, load it from there
    func reference() throws -> LValue {
        return memsubsc
    }
    
    func aggregateReference() -> LValue {
        return memsubsc
    }
}


/**
 An accessor whose memory is reference counted
 
 This exposes API to `alloc`, `retain`, `release`, and `dealloc` ref coutned
 heap pointers.
*/
final class RefCountedAccessor : IndirectAccessor {
    
    var mem: LValue
    init(refcountedBox: LValue, _reference: OpaqueLValue? = nil) {
        self.mem = refcountedBox
        self._reference = _reference
    }
    
    var _reference: OpaqueLValue? // lazy member reference
    func reference() throws -> LValue {
        if let r = _reference { return r }
        
        let ref = try module.builder.build(inst: StructElementPtrInst(object: mem, property: "object"))
        let load = try module.builder.build(inst: LoadInst(address: ref, irName: mem.irName.+"instance"))
        
        return try OpaqueLValue(rvalue: load)
    }
    func lValueReference() throws -> LValue {
        return try reference()
    }
    
    func aggregateReference() -> LValue {
        return mem
    }
    
    func aggregateGetValue() throws -> Value {
        return mem
    }
    
    /// Retain a reference, increment the ref count
    func retain() throws {
        try module.builder.build(inst: RetainInst(val: aggregateReference()))
    }
    
    /// Releases the object without decrementing the ref count.
    /// - note: Used in returns as the user of the return is expected
    ///         to either `retain` it or `deallocUnowned` it
    func releaseUnowned() throws {
        try module.builder.build(inst: ReleaseInst(val: aggregateReference(), unowned: true))
    }
    
    /// Release a reference, decrement the ref count
    func release() throws {
        try module.builder.build(inst: ReleaseInst(val: aggregateReference(), unowned: false))
    }
    
    /// Deallocates the object
    func dealloc() throws {
        try module.builder.build(inst: DeallocObjectInst(val: aggregateReference(), unowned: false))
    }
    
    /// Deallocates an unowned object if the ref count is 0
    func deallocUnowned() throws {
        try module.builder.build(inst: DeallocObjectInst(val: aggregateReference(), unowned: true))
    }
    
    /// Capture another reference to the object and retain it
    func getMemCopy() throws -> IndirectAccessor {
        try retain()
        return RefCountedAccessor(refcountedBox: aggregateReference(), _reference: _reference)
    }

    // TODO: Implement getRefCount and ref_count builtin
//    func getRefCount() throws -> Value {
//        
//    }
    
    /// Allocate a heap object and retain it
    /// - returns: the object's accessor
    static func allocObject(type: StructType, module: Module) throws -> RefCountedAccessor {
        
        let val = try module.builder.build(inst: AllocObjectInst(memType: type, irName: "storage"))
//        let targetType = type.importedType(in: module) as! TypeAlias
//        let bc = try module.builder.build(inst: BitcastInst(address: val, newType: targetType))
        
        let accessor = RefCountedAccessor(refcountedBox: val)
        try accessor.retain()
        return accessor
    }
    
}


/// A Ref accessor whose accessor is evaluated on demand. Useful for values
/// which might not be used
final class LazyRefAccessor : IndirectAccessor {
    private var build: () throws -> LValue
    private lazy var val: LValue? = try? self.build()
    
    var mem: LValue {
        guard let v = val else { fatalError() }
        return v
    }
    
    init(fn: () throws -> LValue) { build = fn }
}


final class LazyAccessor : ByValueAccessor, Accessor {
    private var build: () throws -> Value
    private lazy var val: Value? = try? self.build()
    
    private var value: Value { return val! }
    
    var storedType: Type? { return val?.type }

    func getValue() throws -> Value {
        guard let v = val else { fatalError() }
        return v
    }
    
    func referenceBacked() throws -> IndirectAccessor {
        return try allocReferenceBackedAccessor()
    }
    
    init(module: Module, fn: () throws -> Value) {
        self.build = fn
        self.module = module
    }
    var module: Module
}



