//
//  Task.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.Task

enum Exec: String {
    case sysclang = "/usr/bin/clang"
    case clang = "/usr/local/Cellar/llvm/3.8.1/bin/clang"
    case opt = "/usr/local/bin/opt"
    case assemble = "/usr/local/bin/llvm-as"
    
    //static let ass = AS_PATH
}

extension Task {
    class func execute(execName exec: String, files: [String], outputName: String? = nil, cwd: String, args: [String]) {
        
        var a = args
        if let n = outputName { a.append(contentsOf: ["-o", n]) }
        a.append(contentsOf: files)
        
        let task = Task()
        task.currentDirectoryPath = cwd
        task.launchPath = exec
        task.arguments = a
        
        task.launch()
        task.waitUntilExit()
    }
    class func execute(exec: Exec, files: [String], outputName: String? = nil, cwd: String, args: String...) {
        Task.execute(execName: exec.rawValue, files: files, outputName: outputName, cwd: cwd, args: args)
    }
}

// TODO: Treat warnings as errors in these executes
