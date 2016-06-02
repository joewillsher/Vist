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
    
    func lowered(module: Module) -> LLVMType {
        var arr = members.map { $0.lowered(module: module).type }
        return LLVMType(ref: LLVMStructType(&arr, UInt32(members.count), false))
    }
    
    func importedType(inModule module: Module) -> Type {
        return TupleType(members: members.map { $0.importedType(inModule: module) })
    }
    
    /// Returns the type of the tuple element at `index`
    func elementType(at index: Int) throws -> Type {
        guard index < members.count else { throw semaError(.noTupleElement(index: index, size: members.count)) }
        return members[index]
    }
    
    var mangledName: String {
        return members
            .map { $0.mangledName }
            .joined(separator: "") + "_"
    }
    
    func isInModule() -> Bool {
        return !members.map { $0.isInModule() }.contains(false)
    }

}

extension TupleType : Equatable { }

@warn_unused_result
func == (lhs: TupleType, rhs: TupleType) -> Bool {
    return lhs.members.elementsEqual(rhs.members, isEquivalent: ==)
}

