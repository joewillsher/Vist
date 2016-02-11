//
//  ExistentialVariable.swift
//  Vist
//
//  Created by Josef Willsher on 10/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Polymorphic runtime variable of an object passed as an existential.
///
///
/// type Foo, of IR type, `{ i1 , i64 }` which implementwill be passed as `{ {i32} *, { i1 , i64 } }`
///
/// type at runtime i
///
final class ExistentialVariable : StructVariable, MutableVariable {
    
    /// The rutime type of self
    var conceptType: ConceptType
    var type: LLVMTypeRef
    
    /// pointer to start, everything stored in other places
    var ptr: LLVMValueRef
    
    var irName: String
    
    var irGen: IRGen
    var properties: [StructVariableProperty]
    
    
    
    init(ptr: LLVMValueRef, conceptType: ConceptType, irName: String, irGen: IRGen) {
        self.conceptType = conceptType
        self.ptr = ptr
        self.irName = irName
        self.irGen = irGen
        
        let ps = conceptType.requiredProperties.map { (name: $0.name, irType: $0.type.globalType(irGen.module)) } as [StructVariableProperty]
        self.properties = ps
        self.type = conceptType.globalType(irGen.module)
    }
    
    class func alloc(conceptType: ConceptType, fromExistential value: LLVMValueRef, irName: String = "", irGen: IRGen) -> ExistentialVariable {
        
        let exType = conceptType.globalType(irGen.module)
        let ptr = LLVMBuildAlloca(irGen.builder, exType, irName)
        LLVMBuildStore(irGen.builder, value, ptr)
        
        return ExistentialVariable(ptr: ptr, conceptType: conceptType, irName: irName, irGen: irGen)
    }
    
    class func alloc(structType: StructType, conceptType: ConceptType, initWithValue value: LLVMValueRef, irName: String = "", irGen: IRGen) throws -> ExistentialVariable {
        
        let exType = conceptType.globalType(irGen.module)
        let ptr = LLVMBuildAlloca(irGen.builder, exType, irName)
        let opaquePtrType = BuiltinType.OpaquePointer.globalType(irGen.module)
        
        let arrayPtr = LLVMBuildStructGEP(irGen.builder, ptr, 0, "\(irName).metadata")
        let structPtr = LLVMBuildStructGEP(irGen.builder, ptr, 1, "\(irName).opaque")
        let valueMem = LLVMBuildAlloca(irGen.builder, structType.globalType(irGen.module), "")
        
        let arr = try conceptType.existentialMetadataMapFor(structType, builder: irGen.builder)
        LLVMBuildStore(irGen.builder, arr, arrayPtr)
        LLVMBuildStore(irGen.builder, value, valueMem)
        let opaqueValueMem = LLVMBuildBitCast(irGen.builder, valueMem, opaquePtrType, "")
        LLVMBuildStore(irGen.builder, opaqueValueMem, structPtr)
        
        return ExistentialVariable(ptr: ptr, conceptType: conceptType, irName: irName, irGen: irGen)
    }
    
    
    
    
    
    private var _metadataPtr: LLVMValueRef = nil
    private var _opaqueInstancePointer: LLVMValueRef = nil
    
    
    /// Pointer to the metadata array
    private var metadataPtr: LLVMValueRef {
        if _metadataPtr != nil { return _metadataPtr }
        return LLVMBuildStructGEP(irGen.builder, ptr, 0, "\(irName).metadata_ptr") // i8**
    }
    
    /// Pointer to the instance of the wrapped type,
    private var opaqueInstancePointer: LLVMValueRef {
        if _opaqueInstancePointer != nil { return _opaqueInstancePointer }
        let structElementPointer = LLVMBuildStructGEP(irGen.builder, ptr, 1, "\(irName).element_pointer") // [n x i32]**
        return LLVMBuildLoad(irGen.builder, structElementPointer, "\(irName).opaque_instance_pointer") // [n x i32]*
    }
    
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef { // returns Foo
        
        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        guard let i = indexOfProperty(name) else { throw error(IRError.NoProperty(type: conceptType.name, property: name)) }
        let idxValue = LLVMConstInt(LLVMInt32Type(), UInt64(i), false) // i32
        
        let i32PtrType = BuiltinType.Pointer(to: BuiltinType.Int(size: 32)).globalType(irGen.module)
        let elementPtrType = LLVMPointerType(properties[i].irType, 0)
        
        let basePtr = LLVMBuildBitCast(irGen.builder, metadataPtr, i32PtrType, "metadata_base_ptr") // i32*
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, basePtr, [idxValue].ptr(), 1, "metadata_arr_el_ptr") // i32*
        let indexInSelf = LLVMBuildLoad(irGen.builder, pointerToArrayElement, "self_index") // i32
        
        let instanceMemberPtr = LLVMBuildGEP(irGen.builder, opaqueInstancePointer, [indexInSelf].ptr(), 1, "member_pointer") // i8*
        return LLVMBuildBitCast(irGen.builder, instanceMemberPtr, elementPtrType, "\(name).ptr") // Foo*
    }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, try ptrToPropertyNamed(name), name)
    }
    
}

