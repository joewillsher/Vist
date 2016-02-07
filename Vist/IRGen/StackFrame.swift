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
    private var types: [String: StructType]
    var block: LLVMBasicBlockRef, function: LLVMValueRef
    var parentStackFrame: StackFrame?
    private var _isStdLib: Bool?
    
    init(vars: [String: RuntimeVariable] = [:], functionTypes: [String: LLVMTypeRef] = [:], types: [String: StructType] = [:], block: LLVMBasicBlockRef = nil, function: LLVMValueRef = nil, parentStackFrame: StackFrame? = nil, _isStdLib: Bool? = nil) {
        self.runtimeVariables = [:]
        self.functionTypes = [:]
        self.types = [:]
        self.block = block
        self.parentStackFrame = parentStackFrame
        self.function = function
        self._isStdLib = _isStdLib ?? parentStackFrame?._isStdLib
        
        functionTypes.forEach { addFunctionType($1, named: $0) }
        vars.forEach { addVariable($1, named: $0) }
        types.forEach { addType($1, named: $0) }
    }
    
    func addVariable(val: RuntimeVariable, named name: String) {
        runtimeVariables[name] = val
    }
    func addFunctionType(val: LLVMValueRef, named name: String) {
        functionTypes[name] = val
    }
    func addType(val: StructType, named name: String) {
        types[name] = val
    }
    
    /// Return a variable
    /// If not in this scope, parent scopes are recursively searched
    func variable(name: String) throws -> RuntimeVariable {
        
        if let v = runtimeVariables[name] { return v }
        
        let inParent = try parentStackFrame?.variable(name)
        if let p = inParent { return p }
        
        throw error(IRError.NoVariable(name))
    }

    func functionType(name: String) throws -> LLVMValueRef {
        if let v = functionTypes[name] { return v }
        
        let inParent = try parentStackFrame?.functionType(name)
        if let p = inParent where p != nil { return p }
        
        throw error(IRError.NoFunction(name))
    }
    
    func type(name: String) throws -> StructType {
        if let t = StdLib.getStdLibType(name) { return t }
        if let v = types[name] { return v }
        
        let inParent = try parentStackFrame?.type(name)
        if let p = inParent { return p }
        
        throw error(IRError.NoType(name))
    }
    
    /// Whether this module is the standard library
    var isStdLib: Bool {
        return parentStackFrame?.isStdLib ?? _isStdLib!
    }
    
}


