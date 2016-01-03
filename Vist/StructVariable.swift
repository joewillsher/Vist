//
//  StructVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


class StructVariable : RuntimeVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let mutable: Bool
    
    var builder: LLVMBuilderRef
    var properties: [(String, LLVMTypeRef)]
    
    func indexOfProperty(name: String) -> Int? {
        return properties.indexOf { $0.0 == name }
    }
    
    
    init(type: LLVMTypeRef, ptr: LLVMValueRef, mutable: Bool, builder: LLVMBuilderRef, properties: [(String, LLVMTypeRef)]) {
        self.type = type
        self.mutable = mutable
        self.ptr = ptr
        self.builder = builder
        self.properties = properties
    }
    
    func load(name: String = "") -> LLVMValueRef {
        return LLVMBuildLoad(builder, ptr, name)
    }
    
    func isValid() -> Bool {
        return ptr != nil
    }
    
    /// returns pointer to allocated memory
    class func alloc(builder: LLVMBuilderRef, type: LLVMTypeRef, name: String = "", mutable: Bool, properties: [(String, LLVMTypeRef)]) -> StructVariable {
        let ptr = LLVMBuildAlloca(builder, type, name)
        return StructVariable(type: type, ptr: ptr, mutable: mutable, builder: builder, properties: properties)
    }
    
    func store(val: LLVMValueRef) {
        LLVMBuildStore(builder, val, ptr)
    }
    
    private func ptrToElementNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw SemaError.NoPropertyNamed(name) }
        
        return LLVMBuildStructGEP(builder, ptr, UInt32(i), "ptr")
    }
    
    func loadElementNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(builder, try ptrToElementNamed(name), "element")
    }
    
    func store(val: LLVMValueRef, inElementnamed name: String) throws {
        LLVMBuildStore(builder, val, try ptrToElementNamed(name))
    }
    
    
}

final class AssignablePropertyVariable : RuntimeVariable, MutableVariable {
    var type: LLVMTypeRef = nil
    var name: String
    let mutable = true
    private unowned var str: StructVariable
    
    init(name: String, str: StructVariable) {
        self.name = name
        self.str = str
    }
    
    func store(val: LLVMValueRef) throws {
        try str.store(val, inElementnamed: name)
    }
    
    func load(name: String) throws -> LLVMValueRef {
        return try str.loadElementNamed(self.name)
    }
    
    func isValid() -> Bool {
        return true
    }
}







