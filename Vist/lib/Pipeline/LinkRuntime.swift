//
//  LinkRuntime.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.NSTask
import class Foundation.NSFileManager

extension LLVMModule {
        
    /// Links modules, importing from `otherModule`
    func `import`(from otherModule: LLVMModule) {
        var str: UnsafeMutablePointer<Int8>? = UnsafeMutablePointer(allocatingCapacity: 1)
        LLVMLinkModules(module, otherModule.module, LLVMLinkerDestroySource, &str)
    }
    
    /// Link the module with another IR file
    /// - note: The file extension is used to determine whether to compile the file to
    func `import`(fromFile file: String, directory: String, demanglingSymbols: Bool = true) {
        
        let path: String
        
        switch file {
        case _ where file.hasSuffix(".bc"):
            path = "\(directory)/\(file)"
            break
        case _ where !file.hasSuffix(".ll"):
            // .cpp -> .ll
            NSTask.execute(exec: .clang,
                           files: ["Shims.c"],
                           outputName: "\(file).bc",
                           cwd: directory,
                           args: "-O3", "-S", "-emit-llvm")
            fallthrough
        default:
            // .ll -> .bc
            NSTask.execute(exec: .assemble,
                           files: ["\(file).bc"],
                           outputName: "\(file).bc",
                           cwd: directory)
            path = "\(directory)/\(file).bc"
        }
        
        let sourceModule = LLVMModule(path: path, name: file)
        
        defer {
            // we import the source into the target
            self.import(from: sourceModule)
            _ = try? NSFileManager.default().removeItem(atPath: path)
        }
        
        // mangle names
        guard demanglingSymbols else { return }
        
        for function in sourceModule.functions {
            let name = function.name!
            guard name.hasPrefix("vist$U") else { continue }
            function.name = name.demangleRuntimeName()
        }
        
    }
    
}
