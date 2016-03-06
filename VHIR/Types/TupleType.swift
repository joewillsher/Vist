//
//  TupleType.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class TupleType: Ty {
    var members: [Ty]
    
    init(members: [Ty]) {
        self.members = members
    }
    
    func lowerType(module: Module) -> LLVMTypeRef {
        let arr = members
            .map { $0.lowerType(module) }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            false)
    }
    func lowerType(module: LLVMModuleRef) -> LLVMTypeRef {
        let arr = members
            .map { $0.lowerType(module) }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            false)
    }
    
    func usingTypesIn(module: Module) -> Ty {
        return TupleType(members: members.map { $0.usingTypesIn(module) })
    }
    
    func propertyType(index: Int) throws -> Ty {
        guard index < members.count else { throw semaError(.noTupleElement(index: index, size: members.count)) }
        return members[index]
    }
    
    var mangledName: String {
        return members
            .map { $0.mangledName }
            .joinWithSeparator(".") + ".tuple"
    }

}


