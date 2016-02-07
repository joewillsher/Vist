//
//  StructType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


typealias StructMember = (name: String, type: Ty, mutable: Bool)
typealias StructMethod = (name: String, type: FnType)

final class StructType : Ty {
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
    
    private func indexOfTypeNamed(name: String) throws -> Int {
        guard let i = members.indexOf({ $0.name == name }) else { throw error(SemaError.NoPropertyNamed(type: self.name, property: name)) }
        return i
    }
    
    func propertyType(name: String) throws -> Ty {
        return members[try indexOfTypeNamed(name)].type
    }

    func propertyMutable(name: String) throws -> Bool {
        return members[try indexOfTypeNamed(name)].mutable
    }

    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
}

extension StructType {
    
    subscript (function function: String, paramTypes types: [Ty]) -> FnType? {
        get {
            return methods[raw: "\(name).\(function)", paramTypes: types]
        }
    }
}


