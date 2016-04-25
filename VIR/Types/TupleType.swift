//
//  TupleType.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class TupleType : Type {
    var members: [Type]
    
    init(members: [Type]) {
        self.members = members
    }
    
    func lowerType(module: Module) -> LLVMType {
        var arr = members.map { $0.lowerType(module).type }
        return LLVMType(ref: LLVMStructType(&arr, UInt32(members.count), false))
    }
    
    func usingTypesIn(module: Module) -> Type {
        return TupleType(members: members.map { $0.usingTypesIn(module) })
    }
    
    func propertyType(index: Int) throws -> Type {
        guard index < members.count else { throw semaError(.noTupleElement(index: index, size: members.count)) }
        return members[index]
    }
    
    var mangledName: String {
        return members
            .map { $0.mangledName }
            .joinWithSeparator("") + "_"
    }

}

extension TupleType : Equatable { }

@warn_unused_result
func == (lhs: TupleType, rhs: TupleType) -> Bool {
    return lhs.members.elementsEqual(rhs.members, isEquivalent: ==)
}

