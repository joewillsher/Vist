//
//  NSTask.swift
//  Vist
//
//  Created by Josef Willsher on 25/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSTask

enum Exec: String {
    case clang = "/usr/local/Cellar/llvm/3.6.2/bin/clang-3.6"
    case sysclang = "/usr/bin/clang"
    case rm = "/bin/rm"
    case opt = "/usr/local/Cellar/llvm/3.6.2/bin/opt"
    case assemble = "/usr/local/Cellar/llvm/3.6.2/bin/llvm-as"
}

extension NSTask {
    class func execute(exec: Exec, files: [String], outputName: String? = nil, cwd: String, args: String...) {
        
        var a = args
        if let n = outputName { a.appendContentsOf(["-o", n]) }
        a.appendContentsOf(files)
        
        let task = NSTask()
        task.currentDirectoryPath = cwd
        task.launchPath = exec.rawValue
        task.arguments = a
        
        task.launch()
        task.waitUntilExit()
    }
}


