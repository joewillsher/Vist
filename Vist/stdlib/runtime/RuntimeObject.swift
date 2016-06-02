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
    func lower(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue
    
    /// - returns: The LLVM type of self
    /// - note: A helper function, implemented by all types
    func type(IGF: inout IRGenFunction) -> LLVMType
}
private protocol ArrayGenerator : RuntimeObject {
    func lowerArray(IGF: inout IRGenFunction, baseName: String, arrayCount: Int) throws -> LLVMValue
}

extension RuntimeObject {
    
    func lower(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        return try lowerAggr(IGF: &IGF, baseName: baseName)
    }
    
    func lowerAggr(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        
        // Will this fail because it returns type * ???
        if let g = IGF.module.global(named: baseName) {
            return g.value
        }
        let children = Mirror(reflecting: self).children
        
        func arrayCount(property label: String?) -> Int32? {
            guard let property = label where property.hasSuffix("Arr") else { return nil }
            guard let child = children.first(where: { child in child.label == "\(property)Count" }) else { return nil }
            return child.value as? Int32
        }
        
        // reflect chindren of self
        let c = try children
            .map { label, value in (label: label, value: value as! RuntimeObject) }
            .map { label, value -> LLVMValue in
                
                let newName = baseName + (label ?? "")
                    if case let ptr as ArrayGenerator = value, let c = arrayCount(property: label) {
                        return try ptr.lowerArray(IGF: &IGF, baseName: newName, arrayCount: Int(c))
                    }
                    else {
                        return try value.lower(IGF: &IGF, baseName: newName)
                    }
        }
        
        return try LLVMBuilder.constAggregate(type: type(IGF: &IGF),
                                              elements: c)
    }
    
    func getConstMetadata(IGF: inout IRGenFunction, name: String) throws -> LLVMValue {
        // if we can look it up by name, get it
        if let g = IGF.module.global(named: name) {
            return g.value
        }
            // ...otherwise, we lower it and make the global ptr ourselves
        else {
            let ptr = UnsafeMutablePointer.allocInit(value: self)
            let val = try lower(IGF: &IGF, baseName: name)
            return IGF.module.createGlobal(value: val, forPtr: ptr, baseName: name, IGF: &IGF).value
        }
    }
}
// MARK: Runtime types
extension ValueWitness : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType { return Runtime.valueWitnessType.lowered(module: Module()) }
    
    func lower(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        return try LLVMBuilder.constAggregate(type: type(IGF: &IGF), elements: [LLVMValue(ref: LLVMValueRef(witness))])
    }
}
extension TypeMetadata : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType { return Runtime.typeMetadataType.lowered(module: Module()) }
}
extension ConceptConformance : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType { return Runtime.conceptConformanceType.lowered(module: Module()) }
}
extension ExistentialObject : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType { return Runtime.existentialObjectType.lowered(module: Module()) }
}
extension WitnessTable : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType { return Runtime.witnessTableType.lowered(module: Module()) }
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
    
    func type(IGF: inout IRGenFunction) -> LLVMType {
        return UnsafeMutablePointer<Pointee>(self).type(IGF: &IGF)
    }
    func lower(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        return try UnsafeMutablePointer<Pointee>(self).lowerPointer(IGF: &IGF, baseName: baseName, arrayCount: nil)
    }
}
extension ImplicitlyUnwrappedOptional : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType {
        guard case let x as RuntimeObject = self else { fatalError() }
        return x.type(IGF: &IGF)
    }
    func lower(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        guard case let x as RuntimeObject = self else { fatalError() }
        return try x.lower(IGF: &IGF, baseName: baseName)
    }
}
extension Optional : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType {
        guard case let x as RuntimeObject = self else {
            return LLVMType.opaquePointer
        }
        return x.type(IGF: &IGF)
    }
    func lower(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        guard case let x as RuntimeObject = self else {
            return LLVMValue.constNull(type: type(IGF: &IGF))
        }
        return try x.lower(IGF: &IGF, baseName: baseName)
    }
}

extension UnsafeMutablePointer : RuntimeObject, ArrayGenerator {
    
    func type(IGF: inout IRGenFunction) -> LLVMType {
        return (pointee as? RuntimeObject)?.type(IGF: &IGF).getPointerType() ?? LLVMType.opaquePointer
    }
    
    func lower(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        return try lowerPointer(IGF: &IGF, baseName: baseName, arrayCount: nil)
    }
    private func lowerArray(IGF: inout IRGenFunction, baseName: String, arrayCount: Int) throws -> LLVMValue {
        return try lowerPointer(IGF: &IGF, baseName: baseName, arrayCount: arrayCount)
    }
    // pointer runtime vals allocate their pointee as a new LLVM global, then return the ptr
    private func lowerPointer(IGF: inout IRGenFunction, baseName: String, arrayCount: Int?) throws -> LLVMValue {
        return try getGlobal(IGF: &IGF, baseName: baseName, arrayCount: arrayCount).value
    }
    
    func lowerMemory(IGF: inout IRGenFunction, baseName: String) throws -> LLVMValue {
        
        switch pointee {
        case is Int8: // int8* is a string
            return LLVMValue.constString(value: String(cString: UnsafePointer<CChar>(self)))
            
        case let r as RuntimeObject:
            return try r.lower(IGF: &IGF, baseName: baseName)
            
        case is Void: // Swift's void pointers are opaque LLVM one
            return LLVMValue(ref: OpaquePointer(self))
            
        default:
            fatalError()
        }
    }
    
    /// Get or create a LLVM global from a pointer
    private func getGlobal(IGF: inout IRGenFunction, baseName: String, arrayCount: Int?) throws -> LLVMGlobalValue {
        
        // if its an array, gen the elements and add their pointers to a global array
        if let c = arrayCount {
            
            let children = try Swift.stride(from: self, to: advanced(by: c), by: 1).enumerated().map { index, element in
                try IGF.module.createLLVMGlobal(forPointer: element, baseName: "\(baseName)\(index)", IGF: &IGF).value
            }
            
            let v = LLVMValue.constArray(of: type(IGF: &IGF), vals: children)
            return IGF.module.createGlobal(value: v, forPtr: self, baseName: baseName, IGF: &IGF)
        }
            // otherwise just gen the element
        else {
            return try IGF.module.createLLVMGlobal(forPointer: self, baseName: baseName, IGF: &IGF)
        }
    }

}

extension Int32 : RuntimeObject {
    func type(IGF: inout IRGenFunction) -> LLVMType { return LLVMType.intType(size: 32) }
    func lower(IGF: inout IRGenFunction, baseName: String) -> LLVMValue { return LLVMValue.constInt(value: Int(self), size: 32) }
    
}



