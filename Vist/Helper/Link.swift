//
//  Link.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//



/// Link the module with another IR file
func linkModule(inout module: LLVMModuleRef, withFile file: String) {
        
    let buffer = UnsafeMutablePointer<LLVMMemoryBufferRef>.alloc(1)
    let str = UnsafeMutablePointer<UnsafeMutablePointer<Int8>>.alloc(1)
    
    LLVMCreateMemoryBufferWithContentsOfFile(file, buffer, str)
    
    var helperModule = LLVMModuleCreateWithName("_module")
    
//    while true {
//        let f = LLVMGetNamedFunction(helperModule, "main")
//        if f == nil { break }
//        LLVMDeleteFunction(f)
//    }
    
    LLVMGetBitcodeModule(buffer.memory, &helperModule, str)
    
//    var f = LLVMGetFirstFunction(helperModule)
//    
//    while f != nil {
//        
//        let n = String.fromCString(LLVMGetValueName(f))
//        print(n)
//        LLVMSetValueName(f, <#T##Name: UnsafePointer<Int8>##UnsafePointer<Int8>#>)
//
//        f = LLVMGetNextFunction(f)
//
//    }
//    
    
    LLVMLinkModules(module, helperModule, LLVMLinkerDestroySource, str)
    
    
    // Special cases for helper functions
    
//    let print = LLVMGetNamedFunction(module, "print")
//    
//    LLVMAddFunctionAttr(print, LLVMAlwaysInlineAttribute)
//    
}
