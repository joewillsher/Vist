//
//  Command.swift
//  Vist
//
//  Created by Josef Willsher on 25/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSTask

protocol Command {
    var path: String { get }
    var currentDirectory: String { get }
    var args: [String] { get }
}

struct ClangCommand: Command {
    let path = "/usr/local/Cellar/llvm/3.6.2/bin/clang-3.6"
    let files: [String]
    let execName: String?
    let currentDirectory: String
    let args: [String]
    
    @warn_unused_result
    init(files: [String], execName: String? = nil, cwd: String, args: String...) {
        self.files = files
        self.currentDirectory = cwd
        self.execName = execName
        self.args = args
    }
    
    func exectute() {
        let task = NSTask()
        task.currentDirectoryPath = currentDirectory
        task.launchPath = path
        var a = args
        if let n = execName { a.appendContentsOf(["-o", n]) }
        a.appendContentsOf(files)
        task.arguments = a
        
        task.launch()
        task.waitUntilExit()
    }

}

