//
//  StorageVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


typealias StorageVariableProperty = (name: String, irType: LLVMTypeRef)
typealias StorageVariableMethod = (mangledName: String, irType: LLVMTypeRef)

protocol ContainerVariable: RuntimeVariable {
    var ptr: LLVMValueRef { get }
    var properties: [StorageVariableProperty] { get }
}

extension ContainerVariable {
    
    var value: LLVMValueRef {
        get {
            return LLVMBuildLoad(irGen.builder, ptr, irName)
        }
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


/// A struct object
protocol StorageVariable: ContainerVariable {
    var typeName: String { get }
    var methods: [StorageVariableMethod] { get }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef
    
    func ptrToMethodNamed(name: String, fnType: FnType) throws -> LLVMValueRef
    
    var instancePtr: LLVMValueRef { get }
}

protocol TupleVariable: ContainerVariable {
    func loadElementAtIndex(index: Int) throws -> LLVMValueRef
    func ptrToElementAtIndex(index: Int) -> LLVMValueRef
}






extension StorageVariable {
    
    func indexOfPropertyNamed(name: String) -> Int? {
        return properties.indexOf { $0.name == name }
    }
    func indexOfMethodHavingMangledName(mangledName: String) -> Int? {
        return methods.indexOf { $0.mangledName == mangledName }
    }
    
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfPropertyNamed(name) else { throw semaError(.noPropertyNamed(type: irName, property: name)) }
        return LLVMBuildStructGEP(irGen.builder, ptr, UInt32(i), "\(irName).\(name).ptr")
    }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, try ptrToPropertyNamed(name), "\(irName).\(name)")
    }
    
    func ptrToMethodNamed(name: String, fnType: FnType) -> LLVMValueRef {
        return LLVMGetNamedFunction(irGen.module, name.mangle(fnType.params, parentTypeName: typeName))
    }
    
    var instancePtr: LLVMValueRef {
        return ptr
    }
}

extension TupleVariable {
    
    func ptrToElementAtIndex(index: Int) -> LLVMValueRef {
        return LLVMBuildStructGEP(irGen.builder, ptr, UInt32(index), "\(irName).\(index).ptr")
    }
    
    func loadElementAtIndex(index: Int) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, ptrToElementAtIndex(index), "\(irName).\(index)")
    }
    
}



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





final class MutableStorageVariable: StorageVariable, MutableVariable {
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
    class func alloc(type: StructType, irName: String = "", irGen: IRGen) -> MutableStorageVariable {
        let ptr = LLVMBuildAlloca(irGen.builder, type.globalType(irGen.module), irName)
        return MutableStorageVariable(type: type, ptr: ptr, irName: irName, irGen: irGen)
    }
    
}

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



/// function param struct, load by value not ptr
final class ParameterStorageVariable: StorageVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef = nil
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
        guard let i = indexOfPropertyNamed(name) else { throw semaError(.noPropertyNamed(type: irName, property: name)) }
        return LLVMBuildExtractValue(irGen.builder, value, UInt32(i), name)
    }
}



/// Variables that can hold a mutable reference to self
///
/// Initialisers can do this easily because *"self"* is declared in the function
///
/// Self capturing functions use this by setting `parent` to the self pointer param 
final class SelfReferencingMutableVariable: MutableVariable {
    var ptr: LLVMValueRef {
        return try! parent.ptrToPropertyNamed(name)
    }
    var type: LLVMTypeRef {
        return nil
    }
    
    /// unowned ref to struct this belongs to
    private unowned var parent: protocol<MutableVariable, StorageVariable>
    
    var irGen: IRGen
    var irName: String { return "\(parent.irName).\(name)" }
    let name: String
    
    init(propertyName name: String, parent: protocol<MutableVariable, StorageVariable>) {
        self.name = name
        self.parent = parent
        self.irGen = parent.irGen
    }
    
    var value: LLVMValueRef {
        get {
            return try! parent.loadPropertyNamed(self.name)
        }
        set {
            try! parent.store(newValue, inPropertyNamed: name)
        }
    }
    
}




