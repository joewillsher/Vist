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
func importFile(file: String, directory: String, inout into module: LLVMModule, demanglingSymbols: Bool = true) {
    
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
    
    let sourceModule = LLVMModule(path: path, name: file)
    
    defer {
        // we import the source into the target
        module.importFrom(sourceModule)
        _ = try? NSFileManager.defaultManager().removeItemAtPath(path)
    }
    
    // mangle names
    guard demanglingSymbols else { return }
    
    for function in sourceModule.functions {
        let name = String.fromCString(function.name!)!
        guard name.hasPrefix("vist$U") else { continue }
        function.name = name.demangleRuntimeName()
    }
    
}


