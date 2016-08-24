//
//  Accessor.swift
//  Vist
//
//  Created by Josef Willsher on 12/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

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
final class ValAccessor : Accessor {
    
    private var value: Value
    init(value: Value) { self.value = value }
    
    func getValue() -> Value { return value }
    
    /// Alloc a new accessor and store self into it.
    /// - returns: a reference backed *copy* of `self`
    func referenceBacked() throws -> IndirectAccessor {
        return try value.allocReferenceBackedAccessor()
    }
    
    var storedType: Type? { return value.type }
    var module: Module { return value.module }
}

// Helper function for constructing a reference copy
extension Value {
    
    /// Builds a reference accessor which can store into & load from
    /// the memory it allocates
    func allocReferenceBackedAccessor() throws -> IndirectAccessor {
        guard let memType = type?.importedType(in: module) else { throw VIRError.noType(#file) }
        let accessor = RefAccessor(memory: try module.builder.build(inst: AllocInst(memType: memType)))
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
        return try ExistentialRefAccessor(memory: module.builder.build(inst: CopyAddrInst(addr: mem)))
    }
    
    func getEscapingValue() throws -> Value {
        // make sure this buffer is exported
        try module.builder.build(inst: ExistentialExportBufferInst(existential: mem))
        return try module.builder.build(inst: LoadInst(address: mem))
    }
    
    
}





/// An Accessor which allows setting, as well as self lookup by ptr
protocol IndirectAccessor : Accessor {
    var mem: LValue { get }
    /// Stores `val` in the stored object
    func setValue(_ val: Value) throws
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
    
    func setValue(_ val: Value) throws {
        try module.builder.build(inst: StoreInst(address: lValueReference(), value: val))
    }
    
    // default impl of `reference` is a projection of the storage
    func reference() throws -> LValue {
        return try module.builder.build(inst: CopyAddrInst(addr: mem))
    }
    func lValueReference() throws -> LValue {
        return mem
    }
    
    // default impl of `aggregateReference` is the same as `reference`
    func aggregateReference() throws -> LValue {
        return try module.builder.build(inst: CopyAddrInst(addr: mem))
    }
    
    func aggregateGetValue() throws -> Value {
        return try module.builder.build(inst: LoadInst(address: aggregateReference()))
    }
    func aggregateSetter(val: Value) throws {
        try module.builder.build(inst: StoreInst(address: aggregateReference(), value: val))
    }
    
    var module: Module { return mem.module }
    
    
    func release() throws {
        try module.builder.build(inst: DestroyAddrInst(addr: mem))
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


final class LazyAccessor : Accessor {
    private var build: () throws -> Value
    private lazy var val: Value? = try? self.build()
    
    var storedType: Type? { return val?.type }

    func getValue() throws -> Value {
        guard let v = val else { fatalError() }
        return v
    }
    
    func referenceBacked() throws -> IndirectAccessor {
        guard let v = val else { fatalError() }
        return try v.allocReferenceBackedAccessor()
    }
    
    init(module: Module, fn: () throws -> Value) {
        self.build = fn
        self.module = module
    }
    var module: Module
}



