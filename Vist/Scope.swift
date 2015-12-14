//
//  Scope.swift
//  Vist
//
//  Created by Josef Willsher on 09/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation
//import LLVM

class Scope {
    
    private var runtimeVariables: [String: (LLVMValueRef, LLVMTypeRef)]
    private var functionTypes: [String: LLVMTypeRef]
    var block: LLVMBasicBlockRef, function: LLVMValueRef
    var parentScope: Scope?
    
    init(vars: [String: LLVMValueRef] = [:], functionTypes: [String: LLVMTypeRef] = [:], block: LLVMBasicBlockRef = nil, function: LLVMValueRef = nil, parentScope: Scope? = nil) {
        self.runtimeVariables = [:]
        self.functionTypes = [:]
        self.block = block
        self.parentScope = parentScope
        self.function = function
        
        functionTypes.forEach(addFunctionType)
        vars.forEach(addVariable)
    }
    
    func addVariable(name: String, val: LLVMValueRef) {
        runtimeVariables[name] = (val, LLVMTypeOf(val))
    }
    func addFunctionType(name: String, val: LLVMValueRef) {
        functionTypes[name] = val
    }
    
    
    func variable(name: String) throws -> LLVMValueRef {
        
        if let v = runtimeVariables[name] { return v.0 }
        
        let inParent = try parentScope?.variable(name)
        if let p = inParent where p != nil { return p }
        
        throw IRError.NoVariable(name)
    }
    
    func variableType(name: String) throws -> LLVMValueRef {
        if let v = runtimeVariables[name] { return v.1 }
        
        let inParent = try parentScope?.variable(name)
        if let p = inParent where p != nil { return p }
        
        throw IRError.NoVariable(name)
    }

    func functionType(name: String) throws -> LLVMValueRef {
        if let v = functionTypes[name] { return v }
        
        let inParent = try parentScope?.functionType(name)
        if let p = inParent where p != nil { return p }
        
        throw IRError.NoVariable(name)
    }

}


