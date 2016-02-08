//
//  StructVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


typealias StructVariableProperty = (name: String, irType: LLVMTypeRef)

protocol ContainerVariable : class, RuntimeVariable {
    var ptr: LLVMValueRef { get }
    
    var properties: [StructVariableProperty] { get }
}

extension ContainerVariable {
    
    var value: LLVMValueRef {
        get {
            return LLVMBuildLoad(builder, ptr, irName)
        }
    }
}
extension ContainerVariable where Self : MutableVariable {
    
    var value: LLVMValueRef {
        get {
            return LLVMBuildLoad(builder, ptr, irName)
        }
        set {
            LLVMBuildStore(builder, newValue, ptr)
        }
    }
}


/// A struct object
protocol StructVariable : ContainerVariable {
    func loadPropertyNamed(name: String) throws -> LLVMValueRef
}

protocol TupleVariable : ContainerVariable {
    func loadPropertyAtIndex(index: Int) throws -> LLVMValueRef
}






extension StructVariable {
    
    func indexOfProperty(name: String) -> Int? {
        return properties.indexOf { $0.0 == name }
    }
    
    private func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.NoPropertyNamed(type: irName, property: name)) }
        
        return LLVMBuildStructGEP(builder, ptr, UInt32(i), "\(irName).\(name).ptr")
    }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(builder, try ptrToPropertyNamed(name), "\(irName).\(name)")
    }
    
}

extension TupleVariable {
    
    private func ptrToElementAtIndex(index: Int) -> LLVMValueRef {
        return LLVMBuildStructGEP(builder, ptr, UInt32(index), "\(irName).\(index).ptr")
    }
    
    func loadPropertyAtIndex(index: Int) throws -> LLVMValueRef {
        return LLVMBuildLoad(builder, ptrToElementAtIndex(index), "\(irName).\(index)")
    }
    
}



extension StructVariable where Self : MutableVariable {
    
    func store(val: LLVMValueRef, inPropertyNamed name: String) throws {
        LLVMBuildStore(builder, val, try ptrToPropertyNamed(name))
    }
}

extension TupleVariable where Self : MutableVariable {
    
    func store(val: LLVMValueRef, inPropertyAtIndex index: Int) throws {
        guard index < properties.count else { throw error(IRError.NoTupleMemberAt(index)) }
        LLVMBuildStore(builder, val, ptrToElementAtIndex(index))
    }
}








final class MutableStructVariable : StructVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let irName: String
    let typeName: String
    
    var builder: LLVMBuilderRef
    var properties: [StructVariableProperty]
    
    init(type: StructType, ptr: LLVMValueRef, irName: String, builder: LLVMBuilderRef) {
        self.type = type.ir()
        self.typeName = type.name
        self.ptr = ptr
        self.builder = builder
        self.properties = type.members.map { (name: $0.name, irType: $0.type.ir()) }
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: StructType, irName: String = "", builder: LLVMBuilderRef) -> MutableStructVariable {
        let ptr = LLVMBuildAlloca(builder, type.ir(), irName)
        return MutableStructVariable(type: type, ptr: ptr, irName: irName, builder: builder)
    }
    
}

final class MutableTupleVariable : TupleVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let irName: String
    
    var builder: LLVMBuilderRef
    var properties: [StructVariableProperty]
    
    private init(type: TupleType, ptr: LLVMValueRef, irName: String, builder: LLVMBuilderRef, properties: [StructVariableProperty]) {
        self.type = type.ir()
        self.ptr = ptr
        self.builder = builder
        self.properties = properties
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: TupleType, irName: String = "", builder: LLVMBuilderRef) -> MutableTupleVariable {
        let ps = type.members.enumerate().map { (name: String($0), irType: $1.ir()) } as [StructVariableProperty]
        
        let ptr = LLVMBuildAlloca(builder, type.ir(), irName)
        return MutableTupleVariable(type: type, ptr: ptr, irName: irName, builder: builder, properties: ps)
    }
    
}



/// function param struct, load by value not ptr
final class ParameterStructVariable : StructVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef = nil
    let irName: String
    
    var value: LLVMValueRef
    
    var builder: LLVMBuilderRef
    var properties: [StructVariableProperty]
    
    init(val: LLVMValueRef, type: StructType, irName: String, builder: LLVMBuilderRef) {
        
        let ps = type.members.map { (name: $0.name, irType: $0.type.ir()) } as [StructVariableProperty]
        
        self.type = type.ir()
        self.builder = builder
        self.properties = ps
        self.value = val
        self.irName = irName
    }
    
    // override StructVariable's loadPropertyNamed(_:) function to
    // just extract the value from our value, and not use the pointer
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.NoPropertyNamed(type: irName, property: name)) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), name)
    }
}



/// Variables that can hold a mutable reference to self
///
/// Initialisers can do this easily because *"self"* is declared in the function
///
/// Self capturing functions use this by setting `parent` to the self pointer param 
final class SelfReferencingMutableVariable : MutableVariable {
    var ptr: LLVMValueRef = nil
    var type: LLVMTypeRef = nil // dont care -- initialiser has this info
    private unowned var parent: protocol<MutableVariable, StructVariable> // unowned ref to struct this belongs to
    var builder: LLVMBuilderRef
    var irName: String { return "\(parent.irName).\(name)" }
    let name: String
    
    init(propertyName name: String, parent: protocol<MutableVariable, StructVariable>) {
        self.name = name
        self.parent = parent
        self.builder = parent.builder
    }
    
    var value: LLVMValueRef  {
        get {
            return try! parent.loadPropertyNamed(self.name)
        }
        set {
            try! parent.store(newValue, inPropertyNamed: name)
        }
    }
    
}




