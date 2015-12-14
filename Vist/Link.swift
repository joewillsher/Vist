//
//  Link.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


/// Link the module with another IR file
func linkModule(inout module: LLVMModuleRef, withFile file: String) {
    
//    let ir = try! String(contentsOfFile: withFile, encoding: NSUTF8StringEncoding)
    
    // for now just add the print function
//    let t = LLVMFunctionType(LLVMVoidType(), [LLVMTypeRef]().ptr(), 0, LLVMBool(false))
//    LLVMAddFunction(module, "print", t)
    
    let buffer = UnsafeMutablePointer<LLVMMemoryBufferRef>.alloc(1)
    let str = UnsafeMutablePointer<UnsafeMutablePointer<Int8>>.alloc(1)
    
    LLVMCreateMemoryBufferWithContentsOfFile(file, buffer, str)
    
    var stdLibModule = LLVMModuleCreateWithName("stdlib_module")
    
    LLVMGetBitcodeModule(buffer.memory, &stdLibModule, str)
    LLVMLinkModules(module, stdLibModule, LLVMLinkerDestroySource, str)
}
