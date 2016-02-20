//
//  StdTypes.swift
//  Vist
//
//  Created by Josef Willsher on 14/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension COpaquePointer {
    
    func load(property: String, fromType type: Ty?, builder: LLVMBuilderRef, irName: String = "") throws -> LLVMValueRef {
        if case let stdType as StructType = type {
            return try stdType.loadPropertyNamed(property, from: self, builder: builder, irName: irName)
        }
        else {
            throw error(IRError.NotStructType, userVisible: false)
        }
    }
    func load(index: Int, fromType type: Ty?, builder: LLVMBuilderRef, irName: String = "") throws -> LLVMValueRef {
        if case let stdType as TupleType = type {
            return try stdType.loadPropertyAtIndex(index, from: self, builder: builder, irName: irName)
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
    private func loadPropertyNamed(name: String, from value: LLVMValueRef, builder: LLVMBuilderRef, irName: String = "") throws -> LLVMValueRef {
        guard let i = indexOfProperty(name) else { throw error(SemaError.noPropertyNamed(type: name, property: self.name)) }
        return LLVMBuildExtractValue(builder, value, UInt32(i), irName)
    }
    
    /// Initialises a stdtype from a list of its members' ir
    ///
    /// Provides compiler the interface of std types' initialiser
    ///
    /// Returns the result of a function call to the initialise
    ///
    func initialiseStdTypeFromBuiltinMembers(val: LLVMValueRef..., irGen: IRGen, irName: String = "") -> LLVMValueRef {
        let tys = members.map { $0.1 }
        let initName = name.mangle(FnType(params: tys, returns: BuiltinType.Void/*we con’t care what this is, its not used in mangling*/))
        
        guard let (type, initialiser) = StdLib.getFunctionIR(initName, module: irGen.module) where initialiser != nil else { return nil }
        
        let args = val.ptr()
        defer { args.dealloc(members.count) }
        
        let call = LLVMBuildCall(irGen.builder, initialiser, args, UInt32(val.count), irName)
        type.addMetadataTo(call)
        
        return call
    }
    
}


extension TupleType {
    
    /// Builds load of named property from struct
    private func loadPropertyAtIndex(index: Int, from value: LLVMValueRef, builder: LLVMBuilderRef, irName: String = "") throws -> LLVMValueRef {
        guard index < self.members.count else { throw error(IRError.NoTupleMemberAt(index)) }
        return LLVMBuildExtractValue(builder, value, UInt32(index), irName)
    }

}

