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
final class ExistentialVariable : StructVariable {
    
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
    
    class func alloc(value: LLVMValueRef, conceptType: ConceptType, irName: String = "", irGen: IRGen) -> ExistentialVariable {
        
        let exType = conceptType.globalType(irGen.module)
        let ptr = LLVMBuildAlloca(irGen.builder, exType, irName)
        LLVMBuildStore(irGen.builder, value, ptr)
        
        return ExistentialVariable(ptr: ptr, conceptType: conceptType, irName: irName, irGen: irGen)
    }
    
    
    
    
    
    private var _metadataPtr: LLVMValueRef = nil
    private var _opaqueInstancePointer: LLVMValueRef = nil
    
    
    /// Pointer to the metadata array
    private var metadataPtr: LLVMValueRef {
        if _metadataPtr != nil { return _metadataPtr }
        return LLVMBuildStructGEP(irGen.builder, ptr, 0, "\(irName).metadata_ptr")
    }
    
    /// Pointer to the instance of the wrapped type
    private var opaqueInstancePointer: LLVMValueRef {
        if _opaqueInstancePointer != nil { return _opaqueInstancePointer }
        let structElementPointer = LLVMBuildStructGEP(irGen.builder, ptr, 1, "\(irName).element_pointer") // cache these 2 lines
        return LLVMBuildLoad(irGen.builder, structElementPointer, "\(irName).opaque_instance_pointer")
    }
    
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        guard let i = indexOfProperty(name) else { throw error(IRError.NoProperty(type: conceptType.name, property: name)) }
        let idxValue = LLVMConstInt(LLVMInt32Type(), UInt64(i), false)
        
        let pointerToArrayElement = LLVMBuildGEP(irGen.builder, metadataPtr, [idxValue].ptr(), 1, "metadata_arr_el_ptr")
        let indexInSelf = LLVMBuildLoad(irGen.builder, pointerToArrayElement, "self_index")
                
        let instanceMemberPtr = LLVMBuildGEP(irGen.builder, opaqueInstancePointer, [indexInSelf].ptr(), 1, "member_pointer")
        let bitcastMemberPointer = LLVMBuildBitCast(irGen.builder, instanceMemberPtr, LLVMPointerType(properties[i].irType, 0), "\(name).ptr")
        return bitcastMemberPointer
    }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, try ptrToPropertyNamed(name), name)
    }
    
    
    
    var value: LLVMValueRef {
        get {
            fatalError()
        }
        set {
            fatalError()
        }
    }
    
    
}

