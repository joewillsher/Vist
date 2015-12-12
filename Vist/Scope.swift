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
    var block: LLVMBasicBlockRef, function: LLVMValueRef
    var parentScope: Scope?
    
    init(vars: [String: LLVMValueRef] = [:], block: LLVMBasicBlockRef = nil, function: LLVMValueRef = nil, parentScope: Scope? = nil) {
        self.runtimeVariables = [:]
        self.block = block
        self.parentScope = parentScope
        self.function = function
        vars.forEach(addVariable)
    }
    
    func addVariable(name: String, val: LLVMValueRef) {
        runtimeVariables[name] = (val, LLVMTypeOf(val))
    }
    
    func variable(name: String) throws -> LLVMValueRef {
        
        if let v = runtimeVariables[name] { return v.0 }
        
        let inParent = try parentScope?.variable(name)
        if inParent != nil { return inParent! }
        
        throw IRError.NoVariable(name)
    }
    
    func variableType(name: String) throws -> LLVMValueRef {
        if let v = runtimeVariables[name] { return v.1 }
        
        let inParent = try parentScope?.variable(name)
        if inParent != nil { return inParent! }
        
        throw IRError.NoVariable(name)
    }
}


