//
//  Scope.swift
//  Vist
//
//  Created by Josef Willsher on 09/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


/// A stack frame, used by irgen to lookup variables, function types and return pointers (via function)
class Scope {
    
    private var runtimeVariables: [String: RuntimeVariable]
    private var functionTypes: [String: LLVMTypeRef]
    var block: LLVMBasicBlockRef, function: LLVMValueRef
    var parentScope: Scope?
    
    init(vars: [String: RuntimeVariable] = [:], functionTypes: [String: LLVMTypeRef] = [:], block: LLVMBasicBlockRef = nil, function: LLVMValueRef = nil, parentScope: Scope? = nil) {
        self.runtimeVariables = [:]
        self.functionTypes = [:]
        self.block = block
        self.parentScope = parentScope
        self.function = function
        
        functionTypes.forEach(addFunctionType)
        vars.forEach { addVariable($0.0, val: $0.1) }
    }
    
    func addVariable(name: String, val: RuntimeVariable) {
        runtimeVariables[name] = val
    }
    func addFunctionType(name: String, val: LLVMValueRef) {
        functionTypes[name] = val
    }
    
    /// Return a variable
    /// If not in this scope, parent scopes are recursively searched
    func variable(name: String) throws -> RuntimeVariable {
        
        if let v = runtimeVariables[name] where v.isValid() { return v }
        
        let inParent = try parentScope?.variable(name)
        if let p = inParent where p.isValid() { return p }
        
        throw IRError.NoVariable(name)
    }

    func functionType(name: String) throws -> LLVMValueRef {
        if let v = functionTypes[name] { return v }
        
        let inParent = try parentScope?.functionType(name)
        if let p = inParent where p != nil { return p }
        
        throw IRError.NoVariable(name)
    }
        
}


