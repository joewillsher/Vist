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
    var name: String { get }
    
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
}




class MutableStructVariable : StructVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let name: String
    
    var builder: LLVMBuilderRef
    var properties: [(String, LLVMTypeRef, Bool)]
    
    required init(type: LLVMTypeRef, ptr: LLVMValueRef, name: String, builder: LLVMBuilderRef, properties: [(String, LLVMTypeRef, Bool)]) {
        self.type = type
        self.ptr = ptr
        self.builder = builder
        self.properties = properties
        self.name = name
    }
    
    /// returns pointer to allocated memory
    class func alloc(builder: LLVMBuilderRef, type: LLVMTypeRef, name: String = "", properties: [(String, LLVMTypeRef, Bool)]) -> MutableStructVariable {
        let ptr = LLVMBuildAlloca(builder, type, name)
        return MutableStructVariable(type: type, ptr: ptr, name: name, builder: builder, properties: properties)
    }
    
    private func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.NoPropertyNamed(type: self.name, property: name)) }
        
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

/// function param struct, load by value not ptr
class ParameterStructVariable : StructVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef = nil
    let name: String
    
    var value: LLVMValueRef
    
    var builder: LLVMBuilderRef
    var properties: [(String, LLVMTypeRef, Bool)]
    
    required init(type: LLVMTypeRef, val: LLVMValueRef, builder: LLVMBuilderRef, name: String, properties: [(String, LLVMTypeRef, Bool)]) {
        self.type = type
        self.builder = builder
        self.properties = properties
        self.value = val
        self.name = name
    }
    
    func load(name: String) -> LLVMValueRef {
        return value
    }
    
    func isValid() -> Bool {
        return value != nil
    }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.NoPropertyNamed(type: self.name, property: name)) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), name)
        // TODO: if its a struct with 1 element, make this a bitcast tbh
        // TODO: opt pass to transform successive extracts/insertvalues to bitcasts
    }
    
    func store(val: LLVMValueRef, inPropertyNamed name: String) throws {
        throw error(SemaError.CannotStoreInParameterStruct(propertyName: name))
    }
    
}



// rename to StructPropertyVariable
/// Variable kind referenced by initialisers
final class StructPropertyVariable : MutableVariable {
    var type: LLVMTypeRef = nil // dont care -- initialiser has this info
    var name: String
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




