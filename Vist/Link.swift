//
//  Link.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


/// Link the module with another IR file
func linkModule(inout module: LLVMModuleRef, withFile: String) {
    
//    let ir = try! String(contentsOfFile: withFile, encoding: NSUTF8StringEncoding)
    
    // for now just add the print function
    let t = LLVMFunctionType(LLVMVoidType(), [LLVMTypeRef]().ptr(), 0, LLVMBool(false))
    LLVMAddFunction(module, "_Z5printv", t)
    
    
}
