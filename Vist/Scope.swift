//
//  Scope.swift
//  Vist
//
//  Created by Josef Willsher on 09/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation
import LLVM

class Scope {
    
    private var runtimeVariables: [String: (LLVMValueRef, LLVMTypeRef)]
    var block: LLVMBasicBlockRef
    
    init(vars: [String: LLVMValueRef] = [:], block: LLVMBasicBlockRef = nil) {
        self.runtimeVariables = [:]
        self.block = block
        vars.forEach(addVariable)
    }
    
    func addVariable(name: String, val: LLVMValueRef) {
        runtimeVariables[name] = (val, LLVMTypeOf(val))
    }
    func variable(name: String) throws -> LLVMValueRef {
        if let v = runtimeVariables[name] { return v.0 } else { throw IRError.NoVariable(name) }
    }
    func variableType(name: String) throws -> LLVMValueRef {
        if let v = runtimeVariables[name] { return v.1 } else { throw IRError.NoVariable(name) }
    }
}


