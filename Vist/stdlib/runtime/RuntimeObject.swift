//
//  RuntimeObject.swift
//  Vist
//
//  Created by Josef Willsher on 16/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation.NSString

/**
 runtime.hh defines a bunch of structs for use in the runtime
 
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
}
private protocol ArrayGenerator : RuntimeObject {
    func lowerArray(inout IGF: IRGenFunction, baseName: String, arrayCount: Int) throws -> LLVMValue
}

extension RuntimeObject {
    
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        return try lowerAggr(&IGF, baseName: baseName)
    }
    
    func lowerAggr(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        
        // Will this fail because it returns type * ???
        if let g = IGF.module.global(named: baseName) {
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
                    if case let ptr as ArrayGenerator = value, let c = arrayCount(property: label) {
                        return try ptr.lowerArray(&IGF, baseName: newName, arrayCount: Int(c))
                    }
                    else {
                        return try value.lower(&IGF, baseName: newName)
                    }
        }
        
        return try LLVMBuilder.constAggregate(type: type(&IGF),
                                              elements: c)
    }
    
    func getConstMetadata(inout IGF: IRGenFunction, name: String) throws -> LLVMValue {
        // if we can look it up by name, get it
        if let g = IGF.module.global(named: name) {
            return g.value
        }
            // ...otherwise, we lower it and make the global ptr ourselves
        else {
            let ptr = UnsafeMutablePointer.allocInit(self)
            let val = try lower(&IGF, baseName: name)
            return IGF.module.createGlobal(val, forPtr: ptr, baseName: name, IGF: &IGF).value
        }
    }
}
// MARK: Runtime types
extension ValueWitness : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.valueWitnessType.lowerType(Module()) }
    
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        return try LLVMBuilder.constAggregate(type: type(&IGF), elements: [LLVMValue(ref: LLVMValueRef(witness))])
    }
}
extension TypeMetadata : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.typeMetadataType.lowerType(Module()) }
}
extension ConceptConformance : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.conceptConformanceType.lowerType(Module()) }
}
extension ExistentialObject : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.existentialObjectType.lowerType(Module()) }
}
extension WitnessTable : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return Runtime.witnessTableType.lowerType(Module()) }
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
        return try UnsafeMutablePointer<Memory>(self).lowerPointer(&IGF, baseName: baseName, arrayCount: nil)
    }
}

extension UnsafeMutablePointer : RuntimeObject, ArrayGenerator {
    
    func type(inout IGF: IRGenFunction) -> LLVMType {
        return (memory as? RuntimeObject)?.type(&IGF).getPointerType() ?? LLVMType.opaquePointer
    }
    
    func lower(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        return try lowerPointer(&IGF, baseName: baseName, arrayCount: nil)
    }
    private func lowerArray(inout IGF: IRGenFunction, baseName: String, arrayCount: Int) throws -> LLVMValue {
        return try lowerPointer(&IGF, baseName: baseName, arrayCount: arrayCount)
    }
    // pointer runtime vals allocate their pointee as a new LLVM global, then return the ptr
    private func lowerPointer(inout IGF: IRGenFunction, baseName: String, arrayCount: Int?) throws -> LLVMValue {
        if self == nil { return LLVMValue.constNull(type: type(&IGF)) }
        return try getGlobal(&IGF, baseName: baseName, arrayCount: arrayCount).value
    }
    
    func lowerMemory(inout IGF: IRGenFunction, baseName: String) throws -> LLVMValue {
        
        switch memory {
        case is Int8: // int8* is a string
            return LLVMValue.constString(String.fromCString(UnsafePointer<CChar>(self))!)
            
        case let r as RuntimeObject:
            return try r.lower(&IGF, baseName: baseName)
            
        case is Void: // Swift's void pointers are opaque LLVM ones
            return LLVMValue(ref: COpaquePointer(self))
            
        default:
            fatalError()
        }
    }
    
    /// Get or create a LLVM global from a pointer
    private func getGlobal(inout IGF: IRGenFunction, baseName: String, arrayCount: Int?) throws -> LLVMGlobalValue {
        
        // if its an array, gen the elements and add their pointers to a global array
        if let c = arrayCount {
            
            let children = try stride(to: advancedBy(c), by: 1).enumerate().map { index, element in
                try IGF.module.createLLVMGlobal(forPointer: self, baseName: "\(baseName)\(index)", IGF: &IGF).value
            }
            
            let v = LLVMValue.constArray(of: type(&IGF), vals: children)
            return IGF.module.createGlobal(v, forPtr: self, baseName: baseName, IGF: &IGF)
        }
            // otherwise just gen the element
        else {
            return try IGF.module.createLLVMGlobal(forPointer: self, baseName: baseName, IGF: &IGF)
        }
    }

}

extension Int32 : RuntimeObject {
    func type(inout IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 32) }
    func lower(inout IGF: IRGenFunction, baseName: String) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 32) }
    
}



