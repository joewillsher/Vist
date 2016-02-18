//
//  StructVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


typealias StructVariableProperty = (name: String, irType: LLVMTypeRef)

protocol ContainerVariable: RuntimeVariable {
    var ptr: LLVMValueRef { get }
    
    var properties: [StructVariableProperty] { get }
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
protocol StructVariable: ContainerVariable {
    func loadPropertyNamed(name: String) throws -> LLVMValueRef
}

protocol TupleVariable: ContainerVariable {
    func loadPropertyAtIndex(index: Int) throws -> LLVMValueRef
}






extension StructVariable {
    
    func indexOfProperty(name: String) -> Int? {
        return properties.indexOf { $0.0 == name }
    }
    
    func ptrToPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.noPropertyNamed(type: irName, property: name)) }
        
        return LLVMBuildStructGEP(irGen.builder, ptr, UInt32(i), "\(irName).\(name).ptr")
    }
    
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, try ptrToPropertyNamed(name), "\(irName).\(name)")
    }
    
}

extension TupleVariable {
    
    private func ptrToElementAtIndex(index: Int) -> LLVMValueRef {
        return LLVMBuildStructGEP(irGen.builder, ptr, UInt32(index), "\(irName).\(index).ptr")
    }
    
    func loadPropertyAtIndex(index: Int) throws -> LLVMValueRef {
        return LLVMBuildLoad(irGen.builder, ptrToElementAtIndex(index), "\(irName).\(index)")
    }
    
}



extension StructVariable where Self: MutableVariable {
    
    func store(val: LLVMValueRef, inPropertyNamed name: String) throws {
        LLVMBuildStore(irGen.builder, val, try ptrToPropertyNamed(name))
    }
}

extension TupleVariable where Self: MutableVariable {
    
    func store(val: LLVMValueRef, inPropertyAtIndex index: Int) throws {
        guard index < properties.count else { throw error(IRError.NoTupleMemberAt(index)) }
        LLVMBuildStore(irGen.builder, val, ptrToElementAtIndex(index))
    }
}





final class MutableStructVariable: StructVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let irName: String
    let typeName: String
    
    var irGen: IRGen
    var properties: [StructVariableProperty]
    
    init(type: StructType, ptr: LLVMValueRef, irName: String, irGen: IRGen) {
        self.type = type.globalType(irGen.module)
        self.typeName = type.name
        self.ptr = ptr
        self.irGen = irGen
        self.properties = type.members.map { (name: $0.name, irType: $0.type.globalType(irGen.module)) }
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: StructType, irName: String = "", irGen: IRGen) -> MutableStructVariable {
        let ptr = LLVMBuildAlloca(irGen.builder, type.globalType(irGen.module), irName)
        return MutableStructVariable(type: type, ptr: ptr, irName: irName, irGen: irGen)
    }
    
}

final class MutableTupleVariable: TupleVariable, MutableVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef
    let irName: String
    
    var irGen: IRGen
    var properties: [StructVariableProperty]
    
    private init(type: TupleType, ptr: LLVMValueRef, irName: String, irGen: IRGen, properties: [StructVariableProperty]) {
        self.type = type.globalType(irGen.module)
        self.ptr = ptr
        self.irGen = irGen
        self.properties = properties
        self.irName = irName
    }
    
    /// returns pointer to allocated memory
    class func alloc(type: TupleType, irName: String = "", irGen: IRGen) -> MutableTupleVariable {
        let ps = type.members.enumerate().map { (name: String($0), irType: $1.globalType(irGen.module)) } as [StructVariableProperty]
        
        let ptr = LLVMBuildAlloca(irGen.builder, type.globalType(irGen.module), irName)
        return MutableTupleVariable(type: type, ptr: ptr, irName: irName, irGen: irGen, properties: ps)
    }
    
}



/// function param struct, load by value not ptr
final class ParameterStructVariable: StructVariable {
    var type: LLVMTypeRef
    var ptr: LLVMValueRef = nil
    let irName: String
    
    var value: LLVMValueRef
    
    var irGen: IRGen
    var properties: [StructVariableProperty]
    
    init(val: LLVMValueRef, type: StructType, irName: String, irGen: IRGen) {
        
        let ps = type.members.map { (name: $0.name, irType: $0.type.globalType(irGen.module)) } as [StructVariableProperty]
        
        self.type = type.globalType(irGen.module)
        self.irGen = irGen
        self.properties = ps
        self.value = val
        self.irName = irName
    }
    
    // override StructVariable's loadPropertyNamed(_:) function to
    // just extract the value from our value, and not use the pointer
    func loadPropertyNamed(name: String) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.noPropertyNamed(type: irName, property: name)) }
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
    private unowned var parent: protocol<MutableVariable, StructVariable>
    
    var irGen: IRGen
    var irName: String { return "\(parent.irName).\(name)" }
    let name: String
    
    init(propertyName name: String, parent: protocol<MutableVariable, StructVariable>) {
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




