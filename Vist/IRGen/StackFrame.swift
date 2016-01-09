//
//  StackFrame.swift
//  Vist
//
//  Created by Josef Willsher on 09/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


/// A stack frame, used by irgen to lookup variables, function types and return pointers (via function)
final class StackFrame {
    
    private var runtimeVariables: [String: RuntimeVariable]
    private var functionTypes: [String: LLVMTypeRef]
    private var types: [String: LLVMStType]
    var block: LLVMBasicBlockRef, function: LLVMValueRef
    var parentStackFrame: StackFrame?
    
    init(vars: [String: RuntimeVariable] = [:], functionTypes: [String: LLVMTypeRef] = [:], types: [String: LLVMStType] = [:], block: LLVMBasicBlockRef = nil, function: LLVMValueRef = nil, parentStackFrame: StackFrame? = nil) {
        self.runtimeVariables = [:]
        self.functionTypes = [:]
        self.types = [:]
        self.block = block
        self.parentStackFrame = parentStackFrame
        self.function = function
        
        functionTypes.forEach(addFunctionType)
        vars.forEach { addVariable($0.0, val: $0.1) }
        types.forEach { addType($0.0, val: $0.1) }
    }
    
    func addVariable(name: String, val: RuntimeVariable) {
        runtimeVariables[name] = val
    }
    func addFunctionType(name: String, val: LLVMValueRef) {
        functionTypes[name] = val
    }
    func addType(name: String, val: LLVMStType) {
        types[name] = val
    }
    
    /// Return a variable
    /// If not in this scope, parent scopes are recursively searched
    func variable(name: String) throws -> RuntimeVariable {
        
        if let v = runtimeVariables[name] where v.isValid() { return v }
        
        let inParent = try parentStackFrame?.variable(name)
        if let p = inParent where p.isValid() { return p }
        
        throw IRError.NoVariable(name)
    }

    func functionType(name: String) throws -> LLVMValueRef {
        if let v = functionTypes[name] { return v }
        
        let inParent = try parentStackFrame?.functionType(name)
        if let p = inParent where p != nil { return p }
        
        throw IRError.NoFunction(name)
    }
    
    func type(name: String) throws -> LLVMStType {
        if let v = types[name] { return v }
        
        let inParent = try parentStackFrame?.type(name)
        if let p = inParent { return p }
        
        throw IRError.NoType(name)
    }

}


