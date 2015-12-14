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
        
    let buffer = UnsafeMutablePointer<LLVMMemoryBufferRef>.alloc(1)
    let str = UnsafeMutablePointer<UnsafeMutablePointer<Int8>>.alloc(1)
    
    LLVMCreateMemoryBufferWithContentsOfFile(file, buffer, str)
    
    var helperModule = LLVMModuleCreateWithName("stdlib_module")
    
    LLVMGetBitcodeModule(buffer.memory, &helperModule, str)
    
    LLVMLinkModules(module, helperModule, LLVMLinkerDestroySource, str)
    
    LLVMDumpModule(module)
    
}
