//
//  StructType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct StructType: StorageType {
    let name: String
    let members: [StructMember]
    var methods: [StructMethod]
    var genericTypes: [GenericType] = []
    var concepts: [ConceptType] = []
        
    init(members: [StructMember], methods: [StructMethod], name: String) {
        self.name = name
        self.members = members
        self.methods = methods
    }
    
    func lowerType(module: Module) -> LLVMTypeRef {
        let arr = members
            .map { $0.type.lowerType(module) }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            false)
    }
    func lowerType(module: LLVMModuleRef) -> LLVMTypeRef {
        
        // if no module is defined, we can only return the raw type
        if module == nil { return lowerType(module) }
        
        let found = getNamedType(irName, module)
        if found != nil { return found }
        
        let type = lowerType(Module())
        let namedType = createNamedType(type, irName)
        
        return namedType
    }
    
    func usingTypesIn(module: Module) -> Ty {
        return module.getOrAddType(self)
    }

    
    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    
    static func withTypes(tys: [Ty]) -> StructType {
        return StructType(members: tys.map { (name: "", type: $0, mutable: true) }, methods: [], name: "")
    }
    
    var irName: String {
        return "\(name).st"
    }
    
    var mangledName: String {
        return name
    }
    
}


