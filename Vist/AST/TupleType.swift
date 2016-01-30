//
//  TupleType.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

// TODO: struct type and tuple type both 1 protocol

final class TupleType : Ty {
    var members: [Ty]
    
    init(members: [Ty]) {
        self.members = members
    }
    
    func ir() -> LLVMTypeRef {
        let arr = members
            .map { $0.ir() }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            false)
    }
    
    func propertyType(index: Int) throws -> Ty {
        return members[index]
    }

}


