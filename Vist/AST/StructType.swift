//
//  StructType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct StructType : StorageType {
    let name: String
    let members: [StructMember]
    var methods: [StructMethod]
    var genericTypes: [GenericType] = []
    
    init(members: [StructMember], methods: [StructMethod], name: String) {
        self.name = name
        self.members = members
        self.methods = methods
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
    
    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    
    static func withTypes(tys: [Ty]) -> StructType {
        return StructType(members: tys.map { (name: "", type: $0, mutable: true) }, methods: [], name: "")
    }
        
    func getMethod(methodName : String, argTypes types: [Ty]) -> FnType? {
        return methods[raw: "\(name).\(methodName)", paramTypes: types]
    }
    
    var irName: String {
        return "\(name).st"
    }
    
    var mangledName: String {
        return name
    }
    
}



