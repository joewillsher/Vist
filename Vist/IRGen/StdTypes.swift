//
//  StdTypes.swift
//  Vist
//
//  Created by Josef Willsher on 14/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension StackFrame {
    
    func load(object: LLVMValueRef, type: String, property: String, builder: LLVMBuilderRef) throws -> LLVMValueRef {
        let stdType = try self.type(type)
        return try stdType.loadPropertyNamed(property, from: object, builder: builder)
    }
    
}


extension LLVMStType {
    
    private func indexOfProperty(name: String) -> Int? {
        return members.indexOf { $0.0 == name }
    }
    
    func loadPropertyNamed(name: String, from value: LLVMValueRef, builder: LLVMBuilderRef) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw SemaError.NoPropertyNamed(name) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), name)
    }
    
}
