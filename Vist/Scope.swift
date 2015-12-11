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
    
    var runtimeVariables: [String: LLVMValueRef]
    var block: LLVMBasicBlockRef
    
    init(vars: [String: LLVMValueRef], block: LLVMBasicBlockRef) {
        runtimeVariables = vars
        self.block = block
    }
}


