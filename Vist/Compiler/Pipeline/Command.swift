//
//  Command.swift
//  Vist
//
//  Created by Josef Willsher on 25/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSTask

enum Exec: String {
    case clang = "/usr/local/Cellar/llvm/3.6.2/bin/clang-3.6"
    case rm = "/bin/rm"
    case opt = "/usr/local/Cellar/llvm/3.6.2/bin/opt"
    case assemble = "/usr/local/Cellar/llvm/3.6.2/bin/llvm-as"
}

final class Command {
    var path: String
    let files: [String]
    let outputName: String?
    let currentDirectory: String
    let args: [String]
    
    @warn_unused_result
    init(_ exec: Exec, files: [String], execName: String? = nil, cwd: String, args: String...) {
        self.files = files
        self.path = exec.rawValue
        self.currentDirectory = cwd
        self.outputName = execName
        self.args = args
    }
    
    func exectute() {
        let task = NSTask()
        task.currentDirectoryPath = currentDirectory
        task.launchPath = path
        var a = args
        if let n = outputName { a.appendContentsOf(["-o", n]) }
        a.appendContentsOf(files)
        task.arguments = a
        
        task.launch()
        task.waitUntilExit()
    }
}


