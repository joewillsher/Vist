//
//  RuntimeObject.swift
//  Vist
//
//  Created by Josef Willsher on 16/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 runtime.h defines a bunch of structs for use in the runtime
 
 We conform these types (as well as types they use, like `UnsafeMutablePointer`, `UInt32` etc.) to `RuntimeObject`
 
 This allows (Swift code in) the vist compiler to construct the metadata *as is used in the runtime* by
 constructing a tree of `RuntimeObject`s, and using the `lower(_:)` method on it to generate the const LLVM IR.
 
 This IR is included as metadata (i.e. global variables in the data section of the exec) in the output Vist module
*/
private protocol RuntimeObject {
    
    /// Genrate the Const LLVM pointer value
    /// - note: Default implementation introspects the Self Swift type and 
    ///         generates a const LLVM aggregate pointer if the child types
    ///         also conform to RuntimeObject
    func lower(IGF: IRGenFunction) throws -> LLVMValue
    
    /// - returns: The LLVM type of self
    /// - note: A helper function, implemented by all types
    func type(IGF: IRGenFunction) -> LLVMType
}

private extension RuntimeObject {
    
    func lower(IGF: IRGenFunction) throws -> LLVMValue {
        
        let children = Mirror(reflecting: self).children.map {$0.value as! RuntimeObject}
        return try LLVMBuilder.constAggregate(type: type(IGF),
                                              elements: children.map { try $0.lower(IGF) })
    }
    
    /// Creates a global LLVM metadata pointer from a const value
    private func getGlobalPointer(val: LLVMValue, name: String, IGF: IRGenFunction) -> LLVMGlobalValue {
        var global = LLVMGlobalValue(module: IGF.module, type: type(IGF), name: name)
        global.initialiser = val
        global.isConstant = true
        return global
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
    private func type(IGF: IRGenFunction) -> LLVMType { return Runtime.conceptConformanceType.lowerType(Module()) }
}
extension ExistentialObject : RuntimeObject {
    private func type(IGF: IRGenFunction) -> LLVMType { return Runtime.existentialObjectType.lowerType(Module()) }
}
extension WitnessTable : RuntimeObject {
    private func type(IGF: IRGenFunction) -> LLVMType { return Runtime.witnessTableType.lowerType(Module()) }
    
    // hook for testing
    func __lower(IGF: IRGenFunction) throws {
        let v = try lower(IGF)
        getGlobalPointer(v, name: "wt", IGF: IGF)
        IGF.module.dump()
        
        // # Empty witness table lowered to LLVM globals:
        //
        // @ptr = constant { i8* } zeroinitializer
        // @wt = constant { { i8* }*, i32 } { { i8* }* @ptr, i32 0 }
    }
}

// MARK: Members of runtime types
extension UnsafeMutablePointer : RuntimeObject {
    private func type(IGF: IRGenFunction) -> LLVMType {
        switch memory {
        case let r as RuntimeObject:
            return r.type(IGF)
        case is Swift.Void:
            return LLVMType.opaquePointer
        default:
            fatalError()
        }
    }
    // pointer runtime vals allocate their pointee as a new LLVM global, then return the ptr
    private func lower(IGF: IRGenFunction) throws -> LLVMValue {
        switch memory {
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
    private func type(IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 32) }
    private func lower(IGF: IRGenFunction) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 32) }
}
extension Int64 : RuntimeObject {
    private func type(IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 64) }
    private func lower(IGF: IRGenFunction) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 64) }
}




