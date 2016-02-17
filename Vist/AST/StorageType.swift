//
//  StorageType.swift
//  Vist
//
//  Created by Josef Willsher on 16/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias StructMember = (name: String, type: Ty, mutable: Bool)
typealias StructMethod = (name: String, type: FnType)


protocol StorageType : Ty {
    var members: [StructMember] { get }
    var methods: [StructMethod] { get }
    func memberTypes(module: LLVMModuleRef) -> LLVMTypeRef
    
    var irName: String { get }
}

extension StorageType {
    
    func indexOfMemberNamed(name: String) throws -> Int {
        guard let i = members.indexOf({ $0.name == name }) else { throw error(SemaError.NoPropertyNamed(type: self.irName, property: name)) }
        return i
    }
    
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef {
        let found = getNamedType(irName, module)
        if found != nil { return found }
        
        let type = memberTypes(module)
        let namedType = createNamedType(type, irName)
        
        return namedType
    }
    
    func propertyType(name: String) throws -> Ty {
        return members[try indexOfMemberNamed(name)].type
    }
    
    func propertyMutable(name: String) throws -> Bool {
        return members[try indexOfMemberNamed(name)].mutable
    }
}
