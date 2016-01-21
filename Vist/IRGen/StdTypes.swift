//
//  StdTypes.swift
//  Vist
//
//  Created by Josef Willsher on 14/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension COpaquePointer {
    
    func load(property: String, type: Ty?, builder: LLVMBuilderRef) throws -> LLVMValueRef {
        if case let stdType as StructType = type {
            return try stdType.loadPropertyNamed(property, from: self, builder: builder)
        }
        else {
            fatalError("not a struct type")
        }
    }
}


extension StructType {
    
    private func indexOfProperty(name: String) -> Int? {
        return members.indexOf { $0.0 == name }
    }
    
    /// Builds load of named property from struct
    func loadPropertyNamed(name: String, from value: LLVMValueRef, builder: LLVMBuilderRef) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw SemaError.NoPropertyNamed(name) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), name)
    }
    
    /// Initialises a builtin type from list of valuerefs
    func initialiseWithBuiltin(val: LLVMValueRef..., module: LLVMModuleRef, builder: LLVMBuilderRef) -> LLVMValueRef {
        let initName = name.mangle(FnType(params: members.map { $0.1 }, returns: BuiltinType.Void/*we con’t care what this is, its not used in mangling*/))
        let initialiser = LLVMGetNamedFunction(module, initName)
        guard initialiser != nil else { fatalError("No initialiser for \(name)") }
        let args = val.ptr()
        defer { args.dealloc(members.count) }
        return LLVMBuildCall(builder, initialiser, args, 1, "")
    }
    
}



