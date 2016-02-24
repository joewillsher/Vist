//
//  StorageVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


typealias StorageVariableProperty = (name: String, irType: LLVMTypeRef)
typealias StorageVariableMethod = (mangledName: String, irType: LLVMTypeRef)

/// An object which is an abstract type, including structs,
/// tuples, and existentials
protocol ContainerVariable: RuntimeVariable {
    var ptr: LLVMValueRef { get }
    var properties: [StorageVariableProperty] { get }
}

extension ContainerVariable {
    var value: LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, ptr, irName)
    }
}
extension ContainerVariable where Self: MutableVariable {
    
    var value: LLVMValueRef {
        get {
            return LLVMBuildLoad(irGen.builder, ptr, irName)
        }
        set {
            LLVMBuildStore(irGen.builder, newValue, ptr)
        }
    }
}


/// An object with a struct interface, i.e. it allows element
/// access by strings and can define methods
protocol StorageVariable: ContainerVariable {
    var typeName: String { get }
    var methods: [StorageVariableMethod] { get }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef
    
    func ptrToMethodNamed(name: String, fnType: FnType) throws -> LLVMValueRef
    
    /// ptr to the underlying object, for structs this is
    /// identical to `ptr`
    var instancePtr: LLVMValueRef { get }
}

protocol TupleVariable: ContainerVariable {
    func loadElementAtIndex(index: Int) throws -> LLVMValueRef
    func ptrToElementAtIndex(index: Int) -> LLVMValueRef
}




// Default implementations of functions, these make sense as how
// a struct-type object would typically allow member/method access

extension StorageVariable {
    
    // helper functions, cannot be overriden
    func indexOfPropertyNamed(name: String) -> Int? {
        return properties.indexOf { $0.name == name }
    }
    func indexOfMethodHavingMangledName(mangledName: String) -> Int? {
        return methods.indexOf { $0.mangledName == mangledName }
    }
    func typeOfPropertyNamed(name: String) -> LLVMTypeRef? {
        return indexOfPropertyNamed(name).map { properties[$0].irType }
    }
    
    // member access 
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfPropertyNamed(name) else { throw semaError(.noPropertyNamed(type: irName, property: name)) }
        return LLVMBuildStructGEP(irGen.builder, ptr, UInt32(i), "\(irName).\(name).ptr")
    }
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, try ptrToPropertyNamed(name), "\(irName).\(name)")
    }
    
    // method access
    func ptrToMethodNamed(name: String, fnType: FnType) -> LLVMValueRef {
        return LLVMGetNamedFunction(irGen.module, name.mangle(fnType.params, parentTypeName: typeName))
    }
    
    // the instance ptr defaults to self
    var instancePtr: LLVMValueRef {
        return ptr
    }
    
    func variableForPropertyNamed(name: String, type: Ty?) throws -> RuntimeVariable {
        
        switch type {
        case let t as StructType:
            return MutableStructVariable(type: t, ptr: try ptrToPropertyNamed(name), irName: "", irGen: irGen)

        case let c as ConceptType:
            return ExistentialVariable(ptr: try ptrToPropertyNamed(name), conceptType: c, mutable: true, irName: "", irGen: irGen)
            
        case let type?:
            return ReferenceVariable(type: type, ptr: try ptrToPropertyNamed(name), irName: "", irGen: irGen)
            
        default:
            throw irGenError(.notTyped, userVisible: false)
        }
    }

}

extension TupleVariable {
    
    func ptrToElementAtIndex(index: Int) -> LLVMValueRef {
        return LLVMBuildStructGEP(irGen.builder, ptr, UInt32(index), "\(irName).\(index).ptr")
    }
    
    func loadElementAtIndex(index: Int) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, ptrToElementAtIndex(index), "\(irName).\(index)")
    }
    
    func variableForElementAtIndex(index: Int, type: Ty?) throws -> RuntimeVariable {
        
        switch type {
        case let t as StructType:
            return MutableStructVariable(type: t, ptr: ptrToElementAtIndex(index), irName: "", irGen: irGen)
            
        case let c as ConceptType:
            return ExistentialVariable(ptr: ptrToElementAtIndex(index), conceptType: c, mutable: true, irName: "", irGen: irGen)
            
        case let type?:
            return ReferenceVariable(type: type, ptr: ptrToElementAtIndex(index), irName: "", irGen: irGen)
            
        default:
            throw irGenError(.notTyped, userVisible: false)
        }
    }
    
}


// mutable container member store functions
// these cannot be oberriden but they call on the function which allows
// element access

extension StorageVariable where Self: MutableVariable {
    
    func store(val: LLVMValueRef, inPropertyNamed name: String) throws {
        LLVMBuildStore(irGen.builder, val, try ptrToPropertyNamed(name))
    }
}

extension TupleVariable where Self: MutableVariable {
    
    func store(val: LLVMValueRef, inElementAtIndex index: Int) throws {
        guard index < properties.count else { throw irGenError(.noTupleMemberAt(index)) }
        LLVMBuildStore(irGen.builder, val, ptrToElementAtIndex(index))
    }
}




// MARK: Implementations

/// A mutable struct IR variable
final class MutableStructVariable: StorageVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let irName: String
    let typeName: String
    
    var irGen: IRGen
    var properties: [StorageVariableProperty], methods: [StorageVariableMethod]
    
    init(type: StructType, ptr: LLVMValueRef, irName: String, irGen: IRGen) {
        self.type = type.globalType(irGen.module)
        self.typeName = type.name
        self.ptr = ptr
        self.irGen = irGen
        self.properties = type.members.lower(module: irGen.module)
        self.methods = type.methods.lower(selfType: type, module: irGen.module)
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: StructType, irName: String = "", irGen: IRGen) -> MutableStructVariable {
        let ptr = LLVMBuildAlloca(irGen.builder, type.globalType(irGen.module), irName)
        return MutableStructVariable(type: type, ptr: ptr, irName: irName, irGen: irGen)
    }
    
}

/// A mutable tuple IR variable
final class MutableTupleVariable: TupleVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let irName: String
    
    var irGen: IRGen
    var properties: [StorageVariableProperty]
    
    init(type: TupleType, ptr: LLVMValueRef, irName: String, irGen: IRGen) {
        self.type = type.globalType(irGen.module)
        self.ptr = ptr
        self.irGen = irGen
        self.properties = type.members.enumerate().map { (name: String($0), irType: $1.globalType(irGen.module)) }
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: TupleType, irName: String = "", irGen: IRGen) -> MutableTupleVariable {
        let ptr = LLVMBuildAlloca(irGen.builder, type.globalType(irGen.module), irName)
        return MutableTupleVariable(type: type, ptr: ptr, irName: irName, irGen: irGen)
    }
    
}


// FIXME: ALlow this to generate a ptr if it needs to
/// function param variable for storage types, load *by value* not ptr
final class ParameterStorageVariable: StorageVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef = nil // cannot access through this
    let irName: String
    let typeName: String
    
    var value: LLVMValueRef
    
    var irGen: IRGen
    var properties: [StorageVariableProperty], methods: [StorageVariableMethod]
    
    init(val: LLVMValueRef, type: StructType, irName: String, irGen: IRGen) {
        
        self.properties = type.members.lower(module: irGen.module)
        self.methods = type.methods.lower(selfType: type, module: irGen.module)

        self.type = type.globalType(irGen.module)
        self.typeName = type.name
        self.irGen = irGen
        self.value = val
        self.irName = irName
    }
    
    // override StorageVariable's loadPropertyNamed(_:) function to
    // just extract the value from our value, and not use the pointer
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfPropertyNamed(name) else { throw irGenError(.noProperty(type: typeName, property: name)) }
        return LLVMBuildExtractValue(irGen.builder, value, UInt32(i), "\(irName).\(name)")
    }
    
    // cannot get props by ptr
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfPropertyNamed(name), ty = typeOfPropertyNamed(name) else { throw irGenError(.noProperty(type: typeName, property: name)) }
        let val = LLVMBuildExtractValue(irGen.builder, value, UInt32(i), "\(irName).\(name)")
        let ptr = LLVMBuildAlloca(irGen.builder, ty, "\(irName).\(name)")
        LLVMBuildStore(irGen.builder, val, ptr)
        return ptr
    }
    
    
}






