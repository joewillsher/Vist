//
//  Run.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

func runModule(module: LLVMModuleRef, mainFn: LLVMValueRef) {
    
    let target = UnsafeMutablePointer<LLVMTargetRef>.alloc(1)
    LLVMGetTargetFromTriple("x86_64-apple-macosx10.11.0", target, nil)
    
    
    
}

