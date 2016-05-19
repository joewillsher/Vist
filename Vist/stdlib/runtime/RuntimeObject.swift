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
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue
    
    /// - returns: The LLVM type of self
    /// - note: A helper function, implemented by all types
    func type(inout IGF: IRGenFunction) -> LLVMType
    
    /// The global's is applied this suffix
    var uniquingSuffix: String { get }
    
    /// Should keep recursing the tree
    func shouldDescend(label: String?) -> Bool
}

extension RuntimeObject {
    
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        return try lowerAggr(&IGF, baseName: baseName)
    }
    
    func shouldDescend(label: String?) -> Bool { return true }
    
    /// If we're not descending -- look for a current impl or just use a null value
    func getAlreadyDefinedOrNull(inout IGF: IRGenFunction, baseName: String) -> LLVMValue {
        if let g = IGF.module.global(named: baseName + uniquingSuffix) {
            return g.value
        }
        else {
            return LLVMValue.constNull(type: type(&IGF))
        }
    }
    
    func lowerAggr(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        
        // Will this fail because it returns type * ???
        if let g = IGF.module.global(named: baseName + uniquingSuffix) {
            return g.value
        }
        
        // reflect chindren of self
        let children = try Mirror(reflecting: self)
            .children
            .map { label, value in (label: label, value: value as! RuntimeObject) }
            .map { label, value -> LLVMValue in
                
                if shouldDescend(label) {
                    return try value.lower(&IGF, baseName: baseName)
                }
                else {
                    return value.getAlreadyDefinedOrNull(&IGF, baseName: baseName)
                }
        }
        
        return try LLVMBuilder.constAggregate(type: type(&IGF),
                                              elements: children)
    }
    
    /// Creates a global LLVM metadata pointer from a const value
    private func getGlobalPointer(val: LLVMValue, baseName: String, inout IGF: IRGenFunction) -> LLVMGlobalValue {
        var global = LLVMGlobalValue(module: IGF.module, type: val.type, name: baseName + uniquingSuffix)
        global.initialiser = val
        global.isConstant = true
        return global
    }
    
    func allocConstMetadata(inout IGF: IRGenFunction, name: String) throws -> LLVMGlobalValue {
        return getGlobalPointer(try lower(&IGF, baseName: name), baseName: name, IGF: &IGF)
    }
    
}
// MARK: Runtime types
extension ValueWitness : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.valueWitnessType.lowerType(Module()) }
    var uniquingSuffix: String { return "valwit" }
}
extension TypeMetadata : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.typeMetadataType.lowerType(Module()) }
    var uniquingSuffix: String { return "typemd" }
    
    func shouldDescend(label: String?) -> Bool {
        return !(label == "conceptConformances" && numConformances == 0)
    }
}
extension ConceptConformance : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.conceptConformanceType.lowerType(Module()) }
    var uniquingSuffix: String { return "conf" }
}
extension ExistentialObject : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.existentialObjectType.lowerType(Module()) }
    var uniquingSuffix: String { return "exist" }
}
extension WitnessTable : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.witnessTableType.lowerType(Module()) }
    var uniquingSuffix: String { return "wittab" }
    
    // hook for testing
    func __lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMGlobalValue {
        let v = try lower(&IGF, baseName: baseName)
        return getGlobalPointer(v, baseName: baseName, IGF: &IGF)
//        IGF.module.dump()
        
        // # Empty witness table lowered to LLVM globals:
        //
        // @ptr = constant { i8* } zeroinitializer
        // @wt = constant { { i8* }*, i32 } { { i8* }* @ptr, i32 0 }
    }
}

// MARK: Members of runtime types

extension UnsafeMutablePointer : RuntimeObject {
    
    func type(inout IGF: IRGenFunction) -> LLVMType {
        switch Memory.self {
        case is RuntimeObject:
            return (memory as! RuntimeObject).type(&IGF).getPointerType()
        default:
            return LLVMType.opaquePointer
        }
    }
    
    // pointer runtime vals allocate their pointee as a new LLVM global, then return the ptr
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        
        if self == nil {
            return LLVMValue.constNull(type: type(&IGF))
        }
        
        switch memory {
        case is Int8:
            let str = LLVMValue.constString(String.fromCString(UnsafePointer<CChar>(self))!)
            return getGlobalPointer(str, baseName: "\(baseName)name", IGF: &IGF).value
            
        case let r as RuntimeObject:
            return getGlobalPointer(try r.lower(&IGF, baseName: baseName), baseName: "ptr", IGF: &IGF).value
            
        case is Swift.Void: // Swift's void pointers are opaque LLVM ones
            return LLVMValue.constNull(type: LLVMType.opaquePointer)
            // FIXME: All opaque pointers are null
            
        default:
            fatalError()
        }
    }
    
    var uniquingSuffix: String { return "" }
    
}

extension Int32 : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 32) }
    func lower(inout IGF: IRGenFunction, baseName: String) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 32) }
    
    var uniquingSuffix: String { return "" }
}
//extension Int64 : RuntimeObject {
//    private func type(inout IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 64) }
//    private func lower(inout IGF: IRGenFunction, baseName: String) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 64) }
//}


extension TypeMetadata {
    
    func getName() -> String {
        return String.fromCString(name)!
    }
    
}



