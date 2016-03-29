//
//  ExistentialVariable.swift
//  Vist
//
//  Created by Josef Willsher on 10/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/** ### Polymorphic runtime variable of an object passed as an existential
 
 Stores information about how to access the concept's storage using a metadata array (of `i32`).
 The `n`th index in this array holds the position of that variable in the storage's struct.
 
 ***
 
 So the type
 ```
 type Foo {
    var x: Bool
    var y: Int
 }
 ```
 Has a LLVM type of `{ i1, i64 }`. The concept
 ```
 concept Bar {
    var y: Int
 }
 ```
 Can be used existentailly—for example the funtion `func addBars :: Bar Bar -> Int = ...`
 
 When used existentially, `Bar` has a type `{ [1 x i32], i8* }`. The first element is the metadata array
 and the second the opaque pointer to the conforman. It is type erased because its type is not statically known.
 
 One can lookup `y` from the existential `Bar` object. We statically look up what index in `Bar` `y` is. At
 runtime we lookup this element in the metadata array, and its value tells us which element to look at in our
 type pointer.
 
 The metadata array is occupied with this mapping when the existential is allocated from a known struct type.
 */
final class ExistentialVariable: StorageVariable, MutableVariable {
    
    /// The rutime type of self
    var conceptType: ConceptType
    var type: LLVMTypeRef
    /// pointer to start, everything stored in other places
    var ptr: LLVMValueRef
    var irName: String, typeName: String
    var irGen: IRGen
    var properties: [StorageVariableProperty], methods: [StorageVariableMethod]
    
    /// If mutable, ptrs to elements can be cached
    let mutable: Bool
    var cachedElementPtrs: [String: LLVMValueRef] = [:]
    
    
    init(ptr: LLVMValueRef, conceptType: ConceptType, mutable: Bool, propertyMetadataBasePtr: LLVMValueRef = nil, opaqueInstancePointer: LLVMValueRef = nil, methodMetadataBasePtr: LLVMValueRef = nil, irName: String, irGen: IRGen) {
        self.conceptType = conceptType
        self.ptr = ptr
        self.typeName = conceptType.name
        self.irName = irName
        self.irGen = irGen
        self.mutable = mutable
        
        self._propertyMetadataBasePtr = propertyMetadataBasePtr
        self._opaqueInstancePointer = opaqueInstancePointer
        self._methodMetadataBasePtr = methodMetadataBasePtr
        
        self.properties = conceptType.requiredProperties.lower(module: irGen.module)
        self.methods = conceptType.requiredFunctions.lower(selfType: conceptType, module: irGen.module)
        self.type = conceptType.lowerType(irGen.module)
    }
    
    /// Allocator from another existential object
    class func assignFromExistential(value: LLVMValueRef, conceptType: ConceptType, mutable: Bool, irName: String = "", irGen: IRGen) -> ExistentialVariable {
        
        let exType = conceptType.lowerType(irGen.module)
        let ptr = LLVMBuildAlloca(irGen.builder, exType, irName)
        LLVMBuildStore(irGen.builder, value, ptr)
        
        return ExistentialVariable(ptr: ptr, conceptType: conceptType, mutable: mutable, irName: irName, irGen: irGen)
    }
    
    /// Allocator from a non existential, Struct object
    ///
    /// This generates the runtime metadata and stores an opaque pointer to the struct instance
    class func alloc(structType: StructType, conceptType: ConceptType, initWithValue value: LLVMValueRef, mutable: Bool, irName: String = "", irGen: IRGen) throws -> ExistentialVariable {
        let valueMem = LLVMBuildAlloca(irGen.builder, structType.lowerType(irGen.module), "")
        return try ExistentialVariable.alloc(structType, conceptType: conceptType, initFromPtr: valueMem, initWithValue: value, mutable: mutable, irGen: irGen)
    }
    
    /// Allocator from a struct object with a known destination ptr
    class func alloc(structType: StructType, conceptType: ConceptType, initFromPtr: LLVMValueRef, initWithValue value: LLVMValueRef, mutable: Bool, irName: String = "", irGen: IRGen) throws -> ExistentialVariable {
        
        let exType = conceptType.lowerType(irGen.module)
        let ptr = LLVMBuildAlloca(irGen.builder, exType, irName)
        let opaquePtrType = BuiltinType.opaquePointer.lowerType(irGen.module)
        
        let propArrayPtr = LLVMBuildStructGEP(irGen.builder, ptr, 0, "\(irName).prop_metadata") // [n x i32]*
        let methodArrayPtr = LLVMBuildStructGEP(irGen.builder, ptr, 1, "\(irName).method_metadata") // [n x i8*]*
        let structPtr = LLVMBuildStructGEP(irGen.builder, ptr, 2, "\(irName).opaque") // i8**
        
//        let propArr = try conceptType.existentialPropertyMetadataFor(structType, irGen: irGen)
//        LLVMBuildStore(irGen.builder, propArr, propArrayPtr)
        
        let methodArr = try conceptType.existentialMethodMetadataFor(structType, irGen: irGen)
        LLVMBuildStore(irGen.builder, methodArr, methodArrayPtr)
        
        LLVMBuildStore(irGen.builder, value, initFromPtr)
        let opaqueValueMem = LLVMBuildBitCast(irGen.builder, initFromPtr, opaquePtrType, "")
        LLVMBuildStore(irGen.builder, opaqueValueMem, structPtr)
        
        return ExistentialVariable(ptr: ptr, conceptType: conceptType, mutable: mutable, opaqueInstancePointer: opaqueValueMem, irName: irName, irGen: irGen)
    }
    
    /// Returns a pointer to the element at offset `offset` from the opaque
    /// element pointer
    private func getElementPtrAtOffset(offset: LLVMValueRef, ofType elementType: LLVMTypeRef, irName: String = "") -> LLVMValueRef {
        let offset = [offset].ptr()
        defer { offset.dealloc(1) }
        let instanceMemberPtr = LLVMBuildGEP(irGen.builder, opaqueInstancePointer, offset, 1, "") // i8*
        return LLVMBuildBitCast(irGen.builder, instanceMemberPtr, elementType, "\(irName).ptr") // ElTy*
    }
    
    // MARK: instance member ptrs
    // lazy so they arent recomputed
    
    private var _propertyMetadataBasePtr: LLVMValueRef
    private var _methodMetadataBasePtr: LLVMValueRef
    private var _opaqueInstancePointer: LLVMValueRef
    
    /// Pointer to the property metadata array: `i32*`
    private var propertyMetadataBasePtr: LLVMValueRef {
        get {
            if _propertyMetadataBasePtr != nil { return _propertyMetadataBasePtr }
            let i32PtrType = BuiltinType.pointer(to: BuiltinType.int(size: 32)).lowerType(irGen.module)
            let arr = LLVMBuildStructGEP(irGen.builder, ptr, 0, "\(irName).metadata_ptr") // [n x i32]*
            let v = LLVMBuildBitCast(irGen.builder, arr, i32PtrType, "metadata_base_ptr") // i32*
            _propertyMetadataBasePtr = v
            return v
        }
        set {
            _propertyMetadataBasePtr = newValue
        }
    }
    
    /// Pointer to the function vtable array: `i8**`
    private var methodMetadataBasePtr: LLVMValueRef {
        get {
            if _methodMetadataBasePtr != nil { return _methodMetadataBasePtr }
            let opaquePtrType = BuiltinType.pointer(to: BuiltinType.opaquePointer).lowerType(irGen.module)
            let arr = LLVMBuildStructGEP(irGen.builder, ptr, 1, "\(irName).vtable_ptr") // [n x i8*]*
            let v = LLVMBuildBitCast(irGen.builder, arr, opaquePtrType, "\(irName).vtable_base_ptr") // i8**
            _methodMetadataBasePtr = v
            return v
        }
        set {
            _methodMetadataBasePtr = newValue
        }
    }
    
    /// Pointer to the instance of the wrapped type: `i8*`
    private var opaqueInstancePointer: LLVMValueRef {
        get {
            if _opaqueInstancePointer != nil { return _opaqueInstancePointer }
            let structElementPointer = LLVMBuildStructGEP(irGen.builder, ptr, 2, "\(irName).element_pointer") // i8**
            let v = LLVMBuildLoad(irGen.builder, structElementPointer, "\(irName).opaque_instance_pointer") // i8*
            _opaqueInstancePointer = v
            return v
        }
        set {
            _opaqueInstancePointer = newValue
        }
    }
    
    var instancePtr: LLVMValueRef {
        return opaqueInstancePointer
    }
    
    // MARK: override StorageVariable methods for getting props/methods
    
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef { // returns ElTy
        // if immutable, look up this ptr from the cache
        if let v = cachedElementPtrs[name] where !mutable { return v }
        
        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        guard let i = indexOfPropertyNamed(name) else { throw irGenError(.noProperty(type: conceptType.name, property: name)) }
        
        let indexValue = LLVMConstInt(LLVMInt32Type(), UInt64(i), false) // i32
        let index = [indexValue].ptr()
        defer { index.dealloc(1) }
        
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, propertyMetadataBasePtr, index, 1, "") // i32*
        let offset = LLVMBuildLoad(irGen.builder, pointerToArrayElement, "") // i32
                
        let elementPtrType = LLVMPointerType(properties[i].irType, 0) // ElTy.Type
        let ptr = getElementPtrAtOffset(offset, ofType: elementPtrType, irName: name) // ElTy*
        
        if !mutable { cachedElementPtrs[name] = ptr }
        return ptr
    }
    
    func ptrToMethodNamed(name: String, fnType: FnType) throws -> LLVMValueRef {
        
        let mangledName = name.mangle(fnType.params, parentTypeName: typeName)
        guard let i = indexOfMethodHavingMangledName(mangledName) else { throw irGenError(.noMethod(type: typeName, methodName: name)) }
        
        let indexValue = LLVMConstInt(LLVMInt32Type(), UInt64(i), false) // i32
        let index = [indexValue].ptr()
        defer { index.dealloc(1) }
        
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, methodMetadataBasePtr, index, 1, "") // i8**
        let functionPointer = LLVMBuildLoad(irGen.builder, pointerToArrayElement, "") // i8*
        
        let functionType = BuiltinType.pointer(to: fnType.withOpaqueParent()).lowerType(irGen.module)
        let bitCast = LLVMBuildBitCast(irGen.builder, functionPointer, functionType, name) // fntype*
        return bitCast
    }
    
}

