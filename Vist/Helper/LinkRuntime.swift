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
    var f = LLVMGetFirstFunction(runtimeModule)
    
    while f != nil {
        
        let name = String.fromCString(LLVMGetValueName(f))!
        let n = Int(LLVMCountParams(f))
        
        guard name.characters.contains("_") else {
            f = LLVMGetNextFunction(f)
            continue
        }
        
        let types = UnsafeMutablePointer<LLVMTypeRef>.alloc(n)
        LLVMGetParamTypes(LLVMGetElementType(LLVMTypeOf(f)), types)
        
        var vistTypes: [Ty] = []
        
        for i in 0..<n {
            let b = BuiltinType(types.advancedBy(i).memory)!
            vistTypes.append(b)
        }
        
        LLVMSetValueName(f, name.demangleRuntimeName().mangle(vistTypes))
        
        f = LLVMGetNextFunction(f)
        types.dealloc(n)
    }

    
    LLVMLinkModules(module, runtimeModule, LLVMLinkerDestroySource, str)
}
