//
//  RuntimeObject.swift
//  Vist
//
//  Created by Josef Willsher on 16/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation.NSString

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
private protocol ArrayGenerator : RuntimeObject {
    func lowerArray(inout IGF: IRGenFunction, baseName: String, arrayCount: Int) throws -> LLVMValue
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
        let children = Mirror(reflecting: self).children
        
        func arrayCount(property label: String?) -> Int32? {
            guard let property = label where property.hasSuffix("Arr") else { return nil }
            guard let child = children.find({ child in child.label == "\(property)Count" }) else { return nil }
            return child.value as? Int32
        }
        
        // reflect chindren of self
        let c = try children
            .map { label, value in (label: label, value: value as! RuntimeObject) }
            .map { label, value -> LLVMValue in
                
                let newName = baseName + (label ?? "")
                if shouldDescend(label) {
                    
                    if case let ptr as ArrayGenerator = value, let c = arrayCount(property: label) {
                        return try ptr.lowerArray(&IGF, baseName: newName, arrayCount: Int(c))
                    }
                    else {
                        return try value.lower(&IGF, baseName: newName)
                    }
                }
                else {
                    return value.getAlreadyDefinedOrNull(&IGF, baseName: newName)
                }
        }
        
        return try LLVMBuilder.constAggregate(type: type(&IGF),
                                              elements: c)
    }
    
    var uniquingSuffix: String { return "" }
    
    /// Creates a global LLVM metadata pointer from a const value
    private func getGlobalPointer(val: LLVMValue, baseName: String, inout IGF: IRGenFunction) -> LLVMGlobalValue {
        var global = LLVMGlobalValue(module: IGF.module, type: val.type, name: baseName + uniquingSuffix)
        global.initialiser = val
        global.isConstant = true
        return global
    }
    
    private func allocConstMetadata(inout IGF: IRGenFunction, name: String) throws -> LLVMGlobalValue {
        return getGlobalPointer(try lower(&IGF, baseName: name), baseName: name, IGF: &IGF)
    }
    
    func getConstMetadata(inout IGF: IRGenFunction, name: String) throws -> LLVMValue {
        if let g = IGF.module.global(named: name + uniquingSuffix) {
            return g.value
        }
        else {
            return try allocConstMetadata(&IGF, name: name).value
        }
    }
    
}
// MARK: Runtime types
extension ValueWitness : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.valueWitnessType.lowerType(Module()) }
    var uniquingSuffix: String { return "valwit" }
    func shouldDescend(label: String?) -> Bool {
        return false
    }

}
extension TypeMetadata : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.typeMetadataType.lowerType(Module()) }
    var uniquingSuffix: String { return "typemd" }
    
    func shouldDescend(label: String?) -> Bool {
        return label != "conceptConformanceArr"
    }
}
extension ConceptConformance : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.conceptConformanceType.lowerType(Module()) }
    var uniquingSuffix: String { return "conf" }
    
//    func shouldDescend(label: String?) -> Bool {
//        return label != "concept"
//    }
}
extension ExistentialObject : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.existentialObjectType.lowerType(Module()) }
    var uniquingSuffix: String { return "exist" }
    
    func shouldDescend(label: String?) -> Bool {
        return label != "conformanceArr"
    }
}
extension WitnessTable : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.witnessTableType.lowerType(Module()) }
    var uniquingSuffix: String { return "wittab" }
}

// MARK: Members of runtime types

//  when we can use conditional conformances, conform to Runtime object
//  differently for Memory == Int8, Void, & RuntimeObject

/*
 extension UnsafePointer : RuntimeObject where Memory == Int8 { // implement string
 extension UnsafeBytePointer : RuntimeObject { // implement void*
 extension UnsafeMutablePointer : RuntimeObject where Memory : RuntimeObject { // implement rest
 */


// forward 'const x*' to UnsafeMutablePointer implementation
extension UnsafePointer : RuntimeObject {
    
    func type(inout IGF: IRGenFunction) -> LLVMType {
        return UnsafeMutablePointer<Memory>.type(UnsafeMutablePointer(self))(&IGF)
    }
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        if memory is Int8 {
            let str = LLVMValue.constString(String.fromCString(UnsafePointer<CChar>(self))!)
            return getGlobalPointer(str, baseName: baseName, IGF: &IGF).value
        }
        else {
            return try UnsafeMutablePointer<Memory>(self).lowerPointer(&IGF, baseName: baseName, arrayCount: nil)
        }
    }
}


extension UnsafeMutablePointer : RuntimeObject, ArrayGenerator {
    
    func type(inout IGF: IRGenFunction) -> LLVMType {
        switch Memory.self {
        case is RuntimeObject:
            return (memory as! RuntimeObject).type(&IGF).getPointerType()
        default:
            return LLVMType.opaquePointer
        }
    }
    
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        return try lowerPointer(&IGF, baseName: baseName, arrayCount: nil)
    }
    private func lowerArray(inout IGF: IRGenFunction, baseName: String, arrayCount: Int) throws -> LLVMValue {
        return try lowerPointer(&IGF, baseName: baseName, arrayCount: arrayCount)
    }
    
    // pointer runtime vals allocate their pointee as a new LLVM global, then return the ptr
    func lowerPointer(inout IGF: IRGenFunction, baseName: String, arrayCount: Int?) throws -> LLVMValue {
        
        if self == nil {
            return LLVMValue.constNull(type: type(&IGF))
        }
        
        switch memory {
        case is Int8:
            let str = LLVMValue.constString(String.fromCString(UnsafePointer<CChar>(self))!)
            return getGlobalPointer(str, baseName: baseName, IGF: &IGF).value
            
        case let r as RuntimeObject:
            
            if let c = arrayCount {
                let children = try stride(through: advancedBy(c), by: 1).map {
                    try ($0.memory as! RuntimeObject).lower(&IGF, baseName: baseName)
                }
                let arr = LLVMValue.constArray(of: r.type(&IGF), vals: children)
                return getGlobalPointer(arr, baseName: baseName, IGF: &IGF).value
            }
            else {
                return getGlobalPointer(try r.lower(&IGF, baseName: baseName), baseName: baseName, IGF: &IGF).value
            }
            
            
        case is Swift.Void: // Swift's void pointers are opaque LLVM ones
            return LLVMValue(ref: COpaquePointer(self))
            // FIXME: All opaque pointers are null
            
        default:
            fatalError()
        }
    }
}

extension Int32 : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 32) }
    func lower(inout IGF: IRGenFunction, baseName: String) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 32) }
    
}



