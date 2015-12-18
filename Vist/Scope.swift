//
//  Scope.swift
//  Vist
//
//  Created by Josef Willsher on 09/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation
//import LLVM





// TODO: Seperate types for vars
// make a common protocol which defines different interfaces
// 2 types, one for reference vals, and one for immutable shit
// make the runtimeVariables object in `Scope` a heterogeneous dict of these
// make this object responsible for generating the LLVM IR code for its getting and setting to make the `variable.codeGen(...)` function call a method on the protocol


class Scope {
    
    private var runtimeVariables: [String: StackVariable]
    private var functionTypes: [String: LLVMTypeRef]
    var block: LLVMBasicBlockRef, function: LLVMValueRef
    var parentScope: Scope?
    
    init(vars: [String: StackVariable] = [:], functionTypes: [String: LLVMTypeRef] = [:], block: LLVMBasicBlockRef = nil, function: LLVMValueRef = nil, parentScope: Scope? = nil) {
        self.runtimeVariables = [:]
        self.functionTypes = [:]
        self.block = block
        self.parentScope = parentScope
        self.function = function
        
        functionTypes.forEach(addFunctionType)
        vars.forEach { addVariable($0.0, val: $0.1) }
    }
    
    func addVariable(name: String, val: StackVariable) {
        runtimeVariables[name] = val
    }
    func addFunctionType(name: String, val: LLVMValueRef) {
        functionTypes[name] = val
    }
    
    
    func variable(name: String) throws -> StackVariable {
        
        if let v = runtimeVariables[name] where v.isValid() { return v }
        
        let inParent = try parentScope?.variable(name)
        if let p = inParent where p.isValid() { return p }
        
        throw IRError.NoVariable(name)
    }
    
//    func variableType(name: String) throws -> LLVMTypeRef {
//        if let v = runtimeVariables[name] { return v.1 }
//        
//        let inParent = try parentScope?.variableType(name)
//        if let p = inParent where p != nil { return p }
//        
//        throw IRError.NoVariable(name)
//    }
//    func variableMutable(name: String) throws -> Bool {
//        if let v = runtimeVariables[name] { return v.2 }
//        
//        let inParent = try parentScope?.variableMutable(name)
//        if let p = inParent { return p }
//        
//        throw IRError.NoVariable(name)
//    }

    func functionType(name: String) throws -> LLVMValueRef {
        if let v = functionTypes[name] { return v }
        
        let inParent = try parentScope?.functionType(name)
        if let p = inParent where p != nil { return p }
        
        throw IRError.NoVariable(name)
    }
    
//    func mutateVariable(name: String, setValue val: LLVMValueRef) throws {
//        
//        var ref = try variable(name), type = try variableType(name)
//        
//        guard try variableMutable(name) else { throw IRError.NotMutable }
//        guard type == LLVMTypeOf(val) else { throw IRError.MisMatchedTypes }
//        
//        ref = val
//    }
//    
    
}


