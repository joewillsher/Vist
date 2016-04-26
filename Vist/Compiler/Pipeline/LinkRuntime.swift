//
//  LinkRuntime.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.NSTask
import class Foundation.NSFileManager

/// Link the module with another IR file
/// - note: The file extension matters, the file is compiled to a bc file and linked
func importFile(file: String, directory: String, inout into module: LLVMModuleRef, demanglingSymbols: Bool = true) {
    
    let path: String

    switch file {
    case _ where file.hasSuffix(".bc"):
        path = "\(directory)/\(file)"
        break
    case _ where !file.hasSuffix(".ll"):
        // .cpp -> .ll
        NSTask.execute(.clang,
                       files: ["Shims.c"],
                       outputName: "\(file).bc",
                       cwd: directory,
                       args: "-O3", "-S", "-emit-llvm")
        fallthrough
    default:
        // .ll -> .bc
        NSTask.execute(.assemble,
                       files: ["\(file).bc"],
                       outputName: "\(file).bc",
                       cwd: directory)
        path = "\(directory)/\(file).bc"
    }
    
    let buffer = UnsafeMutablePointer<LLVMMemoryBufferRef>.alloc(1)
    let str = UnsafeMutablePointer<UnsafeMutablePointer<Int8>>.alloc(1)
    
    LLVMCreateMemoryBufferWithContentsOfFile(path, buffer, str)
    
    var runtimeModule = LLVMModuleCreateWithName(file)
    
    LLVMGetBitcodeModule(buffer.memory, &runtimeModule, str)
    
    // mangle names
    if demanglingSymbols {
        var function = LLVMGetFirstFunction(runtimeModule)
        
        while function != nil {
            defer { function = LLVMGetNextFunction(function) }
            
            let name = String.fromCString(LLVMGetValueName(function))!
            guard name.hasPrefix("vist$U") else { continue }
            
            LLVMSetValueName(function, name.demangleRuntimeName())
        }
    }
    
    LLVMLinkModules(module, runtimeModule, LLVMLinkerDestroySource, str)
    
    _ = try? NSFileManager.defaultManager().removeItemAtPath(path)
}
