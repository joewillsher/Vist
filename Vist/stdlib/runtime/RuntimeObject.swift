//
//  RuntimeObject.swift
//  Vist
//
//  Created by Josef Willsher on 16/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/**
 runtime.h defines a bunch of structs for use in the runtime
 
 We conform these types (as well as types they use, like `UnsafeMutablePointer`, `Int32` etc.) to `RuntimeObject`
 
 This allows (Swift code in) the vist compiler to construct the metadata *as is used in the runtime* by
 constructing a tree of `RuntimeObject`s, and using the `lower(_:)` method on it to generate the const LLVM IR.
 
 This IR is included as metadata (i.e. global variables in the data section of the exec) in the output Vist module
*/
protocol RuntimeObject {
    
    /// Genrate the Const LLVM pointer value
    /// - note: Default implementation introspects the Self Swift type and 
    ///         generates a const LLVM aggregate pointer if the child types
    ///         also conform to RuntimeObject
    func lower(IGF: IRGenFunction) throws -> LLVMValue
    
    /// - returns: The LLVM type of self
    /// - note: A helper function, implemented by all types
    func type(IGF: IRGenFunction) -> LLVMType
}

extension RuntimeObject {
    
    func lower(IGF: IRGenFunction) throws -> LLVMValue {
        
        // reflect chindren of self
        let children = try Mirror(reflecting: self)
            .children
            .map {$0.value as! RuntimeObject}
            .map { try $0.lower(IGF) }
        
        return try LLVMBuilder.constAggregate(type: type(IGF),
                                              elements: children)
    }
    
    /// Creates a global LLVM metadata pointer from a const value
    private func getGlobalPointer(val: LLVMValue, name: String, IGF: IRGenFunction) -> LLVMGlobalValue {
        var global = LLVMGlobalValue(module: IGF.module, type: val.type, name: name)
        global.initialiser = val
        global.isConstant = true
        return global
    }
    
    func allocConstMetadata(IGF: IRGenFunction, name: String) throws -> LLVMGlobalValue {
        return getGlobalPointer(try lower(IGF), name: name, IGF: IGF)
    }
    
}
// MARK: Runtime types
extension ValueWitness : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return Runtime.valueWitnessType.lowerType(Module()) }
}
extension TypeMetadata : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return Runtime.typeMetadataType.lowerType(Module()) }
}
extension ConceptConformance : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return Runtime.conceptConformanceType.lowerType(Module()) }
}
extension ExistentialObject : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return Runtime.existentialObjectType.lowerType(Module()) }
}
extension WitnessTable : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return Runtime.witnessTableType.lowerType(Module()) }
    
    // hook for testing
    func __lower(IGF: IRGenFunction) throws -> LLVMGlobalValue {
        let v = try lower(IGF)
        return getGlobalPointer(v, name: "wt", IGF: IGF)
//        IGF.module.dump()
        
        // # Empty witness table lowered to LLVM globals:
        //
        // @ptr = constant { i8* } zeroinitializer
        // @wt = constant { { i8* }*, i32 } { { i8* }* @ptr, i32 0 }
    }
}

// MARK: Members of runtime types

extension UnsafeMutablePointer : RuntimeObject {
    
    func type(IGF: IRGenFunction) -> LLVMType {
        switch Memory.self {
        case is RuntimeObject:
            return (memory as! RuntimeObject).type(IGF).getPointerType()
        default:
            return LLVMType.opaquePointer
        }
    }
    
    // pointer runtime vals allocate their pointee as a new LLVM global, then return the ptr
    func lower(IGF: IRGenFunction) throws -> LLVMValue {
        guard self != nil else {
            return LLVMValue.constNull(type: type(IGF))
        }
//        if case let v as UnsafeMutablePointer = memory {
//            memory.
//        }
        
        print(hashValue)
        
        switch memory {
        case is Int8:
            return try IGF.builder.buildGlobalString(String.fromCString(UnsafeMutablePointer<CChar>(self))!)
            
        case let r as RuntimeObject:
            return getGlobalPointer(try r.lower(IGF), name: "ptr", IGF: IGF).value
            
        case is Swift.Void: // Swift's void pointers are opaque LLVM ones
            return LLVMValue.constNull(type: LLVMType.opaquePointer)
            // FIXME: All opaque pointers are null
            
        default:
            fatalError()
        }
    }
}

extension Int32 : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 32) }
    func lower(IGF: IRGenFunction) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 32) }
}
//extension Int64 : RuntimeObject {
//    private func type(IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 64) }
//    private func lower(IGF: IRGenFunction) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 64) }
//}




