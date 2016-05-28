import class Foundation.NSTask

enum Exec: String {
    case clang = "/usr/local/Cellar/llvm/3.6.2/bin/clang-3.6"
    case sysclang = "/usr/bin/clang"
    case opt = "/usr/local/Cellar/llvm/3.6.2/bin/opt"
    case assemble = "/usr/local/Cellar/llvm/3.6.2/bin/llvm-as"
}

extension NSTask {
    class func execute(execName exec: String, files: [String], outputName: String? = nil, cwd: String, args: [String]) {
        
        var a = args
        if let n = outputName { a.appendContentsOf(["-o", n]) }
        a.appendContentsOf(files)
        
        let task = NSTask()
        task.currentDirectoryPath = cwd
        task.launchPath = exec
        task.arguments = a
        
        task.launch()
        task.waitUntilExit()
    }
    class func execute(exec: Exec, files: [String], outputName: String? = nil, cwd: String, args: String...) {
        NSTask.execute(execName: exec.rawValue, files: files, outputName: outputName, cwd: cwd, args: args)
    }
}