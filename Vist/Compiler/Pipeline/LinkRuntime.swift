//
//  LinkRuntime.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


/// Link the module with another IR file
func linkWithRuntime(inout module: LLVMModuleRef, withFile file: String) {
        
    let buffer = UnsafeMutablePointer<LLVMMemoryBufferRef>.alloc(1)
    let str = UnsafeMutablePointer<UnsafeMutablePointer<Int8>>.alloc(1)
    
    LLVMCreateMemoryBufferWithContentsOfFile(file, buffer, str)
    
    var runtimeModule = LLVMModuleCreateWithName("_module")
    
    LLVMGetBitcodeModule(buffer.memory, &runtimeModule, str)
    
    // mangle names
    var function = LLVMGetFirstFunction(runtimeModule)
    
    while function != nil {
        defer { function = LLVMGetNextFunction(function) }
        
        let name = String.fromCString(LLVMGetValueName(function))!
        guard name.hasPrefix("vist$U") else { continue }
        
        LLVMSetValueName(function, name.demangleRuntimeName())
    }
    
    LLVMLinkModules(module, runtimeModule, LLVMLinkerDestroySource, str)
}
