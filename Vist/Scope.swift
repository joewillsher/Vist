//
//  Scope.swift
//  Vist
//
//  Created by Josef Willsher on 09/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation
import LLVM

class ScopeManager {
    
    var runtimeVariables: [String: LLVMValueRef] = [:]
    
    var scopes: [ScopeManager] = []
    
}


