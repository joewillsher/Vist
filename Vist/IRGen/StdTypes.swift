//
//  StdTypes.swift
//  Vist
//
//  Created by Josef Willsher on 14/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension COpaquePointer {
    
    func load(property: String, type: LLVMTyped?, builder: LLVMBuilderRef) throws -> LLVMValueRef {
        if let stdType = type as? StructType {
            return try stdType.loadPropertyNamed(property, from: self, builder: builder)
        }
        else {
            fatalError("Stdlib type \(type!.description) has no property \(property)")
        }
    }
}


extension StructType {
    
    private func indexOfProperty(name: String) -> Int? {
        return members.indexOf { $0.0 == name }
    }
    
    func loadPropertyNamed(name: String, from value: LLVMValueRef, builder: LLVMBuilderRef) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw SemaError.NoPropertyNamed(name) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), name)
    }
    
    func initialiseWithBuiltin(val: LLVMValueRef..., module: LLVMModuleRef, builder: LLVMBuilderRef) -> LLVMValueRef {
        let initName = name.mangle(FnType(params: members.map { $0.1 }, returns: NativeType.Void/*we con’t care what this is, its not used in mangling*/))
        let initialiser = LLVMGetNamedFunction(module, initName)
        let args = val.ptr()
        defer { args.dealloc(members.count) }
        guard initialiser != nil else { fatalError("No initialiser for \(name)") }
        return LLVMBuildCall(builder, initialiser, args, 1, "")
    }
    
}



