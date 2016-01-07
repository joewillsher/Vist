//
//  StructVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


/// A struct object
protocol StructVariable : class, RuntimeVariable {
    var type: LLVMTypeRef { get }
    var ptr: LLVMValueRef { get set }
    
    var mutable: Bool { get }
    
    func load(name: String) -> LLVMValueRef
    func isValid() -> Bool
    
    var builder: LLVMBuilderRef { get set }
    var properties: [(String, LLVMTypeRef, Bool)] { get set }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef
    func store(val: LLVMValueRef, inPropertyNamed name: String) throws
    
}

extension StructVariable {
    
    func indexOfProperty(name: String) -> Int? {
        return properties.indexOf { $0.0 == name }
    }
    
    func propertyIsMutable(name: String) throws -> Bool {
        guard let i = indexOfProperty(name) else { throw SemaError.NoPropertyNamed(name) }
        return properties[i].2
    }
}




class MutableStructVariable : StructVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let mutable: Bool
    
    var builder: LLVMBuilderRef
    var properties: [(String, LLVMTypeRef, Bool)]
    
    required init(type: LLVMTypeRef, ptr: LLVMValueRef, mutable: Bool, builder: LLVMBuilderRef, properties: [(String, LLVMTypeRef, Bool)]) {
        self.type = type
        self.mutable = mutable
        self.ptr = ptr
        self.builder = builder
        self.properties = properties
    }
    
    /// returns pointer to allocated memory
    class func alloc(builder: LLVMBuilderRef, type: LLVMTypeRef, name: String = "", mutable: Bool, properties: [(String, LLVMTypeRef, Bool)]) -> MutableStructVariable {
        let ptr = LLVMBuildAlloca(builder, type, name)
        return MutableStructVariable(type: type, ptr: ptr, mutable: mutable, builder: builder, properties: properties)
    }
    
    private func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw SemaError.NoPropertyNamed(name) }
        
        return LLVMBuildStructGEP(builder, ptr, UInt32(i), "\(name)_ptr")
    }
    
    func isValid() -> Bool {
        return ptr != nil
    }

    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(builder, try ptrToPropertyNamed(name), "\(name)")
    }
    
    func store(val: LLVMValueRef, inPropertyNamed name: String) throws {
        LLVMBuildStore(builder, val, try ptrToPropertyNamed(name))
    }
    
    func store(val: LLVMValueRef) {
        LLVMBuildStore(builder, val, ptr)
    }
    
    func load(name: String = "") -> LLVMValueRef {
        return LLVMBuildLoad(builder, ptr, name)
    }
    
}

/// Struct param, load from value not ptr
class ParameterStructVariable : StructVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef = nil
    let mutable: Bool = false
    
    var value: LLVMValueRef
    
    var builder: LLVMBuilderRef
    var properties: [(String, LLVMTypeRef, Bool)]
    
    required init(type: LLVMTypeRef, val: LLVMValueRef, builder: LLVMBuilderRef, properties: [(String, LLVMTypeRef, Bool)]) {
        self.type = type
        self.builder = builder
        self.properties = properties
        self.value = val
    }
    
    func load(name: String) -> LLVMValueRef {
        return value
    }
    
    func isValid() -> Bool {
        return value != nil
    }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw SemaError.NoPropertyNamed(name) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), name)
    }
    
    func store(val: LLVMValueRef, inPropertyNamed name: String) throws {
        throw SemaError.CannotStoreInParameterStruct
    }
    
}




/// Variable kind referenced by initialisers
final class AssignablePropertyVariable : MutableVariable {
    var type: LLVMTypeRef = nil // dont care -- initialiser has this info
    var name: String
    let mutable = true // initialiser can always assign
    private unowned var str: StructVariable // unowned ref to struct this belongs to
    
    init(name: String, str: StructVariable) {
        self.name = name
        self.str = str
    }
    
    func store(val: LLVMValueRef) throws {
        try str.store(val, inPropertyNamed: name)
    }
    
    func load(name: String) throws -> LLVMValueRef {
        return try str.loadPropertyNamed(self.name)
    }
    
    func isValid() -> Bool {
        return true
    }
}




