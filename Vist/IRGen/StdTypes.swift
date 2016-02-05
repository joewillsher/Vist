//
//  StdTypes.swift
//  Vist
//
//  Created by Josef Willsher on 14/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension COpaquePointer {
    
    func load(property: String, type: Ty?, builder: LLVMBuilderRef, irName: String? = nil) throws -> LLVMValueRef {
        if case let stdType as StructType = type {
            return try stdType.loadPropertyNamed(property, from: self, builder: builder, irName: irName)
        }
        else {
            throw error(IRError.NotStructType, userVisible: false)
        }
    }
}


extension StructType {
    
    private func indexOfProperty(name: String) -> Int? {
        return members.indexOf { $0.0 == name }
    }
    
    /// Builds load of named property from struct
    func loadPropertyNamed(name: String, from value: LLVMValueRef, builder: LLVMBuilderRef, irName: String? = nil) throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.NoPropertyNamed(type: name, property: self.name)) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), irName ?? name)
    }
    
    /// Initialises a builtin type from list of valuerefs
    func initialiseWithBuiltin(val: LLVMValueRef..., module: LLVMModuleRef, builder: LLVMBuilderRef, irName: String? = nil) -> LLVMValueRef {
        let tys = members.map { $0.1 }
        let initName = name.mangle(FnType(params: tys, returns: BuiltinType.Void/*we con’t care what this is, its not used in mangling*/))
        
        guard let (type, initialiser) = StdLib.getFunctionIR(name, args: tys, module: module) where initialiser != nil else { return nil }
        
        let args = val.ptr()
        defer { args.dealloc(members.count) }
        
        let call = LLVMBuildCall(builder, initialiser, args, 1, irName ?? "")
        type.addMetadata(call)
        return call
    }
    
}



