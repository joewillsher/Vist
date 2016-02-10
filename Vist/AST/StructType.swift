//
//  StructType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


typealias StructMember = (name: String, type: Ty, mutable: Bool)
typealias StructMethod = (name: String, type: FnType)


protocol StorageType : Ty {
    var name: String { get }
    var members: [StructMember] { get }
    var methods: [StructMethod] { get }
}

extension StorageType {
    
    private func indexOfMemberNamed(name: String) throws -> Int {
        guard let i = members.indexOf({ $0.name == name }) else { throw error(SemaError.NoPropertyNamed(type: self.name, property: name)) }
        return i
    }
    
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef {
        
        let found = getNamedType(mangledTypeName, module)
        if found != nil { return found }
        
        let type = memberTypes(module)
        let namedType = createNamedType(type, mangledTypeName)
        
        return namedType
    }
    
    func memberTypes(module: LLVMModuleRef) -> LLVMTypeRef {
        let arr = members
            .map { $0.type.globalType(module) }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            false)
    }
    
    func propertyType(name: String) throws -> Ty {
        return members[try indexOfMemberNamed(name)].type
    }
    
    func propertyMutable(name: String) throws -> Bool {
        return members[try indexOfMemberNamed(name)].mutable
    }
}


struct StructType : StorageType {
    let name: String
    let members: [StructMember]
    var methods: [StructMethod]
    
    
    init(members: [StructMember], methods: [StructMethod], name: String) {
        self.name = name
        self.members = members
        self.methods = methods
    }
    
    func ir() -> LLVMTypeRef {
        let arr = members
            .map { $0.type.ir() }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            false)
    }
    
    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    
    static func withTypes(tys: [Ty]) -> StructType {
        return StructType(members: tys.map { (name: "", type: $0, mutable: true) }, methods: [], name: "")
    }
}

extension StructType {
    
    func getMethod(methodName : String, argTypes types: [Ty]) -> FnType? {
        return methods[raw: "\(name).\(methodName)", paramTypes: types]
    }
}



