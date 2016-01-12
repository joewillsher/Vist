//
//  Compile.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


public func compileDocuments(fileNames: [String],
    verbose: Bool = true,
    dumpAST: Bool = false,
    irOnly: Bool = false,
    asmOnly: Bool = false,
    buildOnly: Bool = false,
    profile: Bool = true,
    optim: Bool = true,
    preserve: Bool = false,
    generateLibrary: Bool = false,
    isStdLib: Bool = false)
    throws {
        
        let stdLibDirectory = "\(PROJECT_DIR)/Vist/stdlib"
        let runtimeDirectory = "\(PROJECT_DIR)/Vist/Runtime"
        let currentDirectory = isStdLib ? stdLibDirectory : NSTask().currentDirectoryPath
        
        var head: AST? = nil
        var all: [AST] = []
        
        let globalScope = SemaScope(parent: nil, returnType: nil)
        
        for (index, fileName) in fileNames.enumerate() {
            
            let path = "\(currentDirectory)/\(fileName)"
            let doc = try String(contentsOfFile: path, encoding: NSUTF8StringEncoding)
            if verbose { print("----------------------------SOURCE-----------------------------\n\n\(doc)\n\n\n-----------------------------TOKS------------------------------\n") }
            
            // http://llvm.org/docs/tutorial/LangImpl1.html#language
            
            
            // Lex code
            var lexer = Lexer(code: doc)
            let tokens = try lexer.getTokens()
            
            if verbose { tokens
                .map {"\($0.0): \t\t\t\t\t\($0.1.range.start)--\($0.1.range.end)"}
                .forEach { print($0) } }
            
            
            if verbose { print("\n\n------------------------------AST-------------------------------\n") }
            
            // parse tokens & generate AST
            var parser = Parser(tokens: tokens, isStdLib: true) // TODO: Update this when have better type support
            let ast = try parser.parse()
            if dumpAST { print(ast); return }
            if verbose { print(ast) }
            
            
            if let h = head {
                head = try astLink(h, other: [ast])
            }

            if index == 0 {
                head = ast
                
            } else {
                all.append(ast)
            }
        }
        
        if verbose { print("\n------------------------SEMA & LINK AST----------------------------\n") }
        
        guard let main = head else { fatalError("No main file supplied") }
        let ast = main
        
        
        let stdlib = StdLibExpose(isStdLib: isStdLib)
        
        // add ast info from stdlib to globalScope
        stdlib.astToSemaScope(scope: globalScope)
        
        try sema(ast, globalScope: globalScope)
        if verbose { print(ast) }
        
        let file = fileNames.first!.stringByReplacingOccurrencesOfString(".vist", withString: "")

        
        
        if verbose { print("\n\n-----------------------------LINK------------------------------") }
        
        var module = LLVMModuleCreateWithName("vist_module")
        // Create vist program module and link against the helper bytecode

        if isStdLib {
            
            linkModule(&module, withFile: "\(runtimeDirectory)/runtime.bc")
            
        } else {
            linkModule(&module, withFile: "\(stdLibDirectory)/stdlib.bc")
        }
        
        configModule(module)

        
        
        
        
        if verbose { print("\n---------------------------LLVM IR----------------------------\n") }
        
        // Generate LLVM IR code for program
        
        let s = StackFrame()
        
        stdlib.astToStackFrame(frame: s)
        
        try ast.IRGen(module: module, isLibrary: generateLibrary, stackFrame: s)
        
        // print and write to file
        let ir = String.fromCString(LLVMPrintModuleToString(module))!
        try ir.writeToFile("\(currentDirectory)/\(file)_.ll", atomically: true, encoding: NSUTF8StringEncoding)
        
        if verbose { print(ir) }
        
        
        if optim && !isStdLib {
            
            let flags = ["-O3"]
//            let flags = ["-inline"]
//            let flags = ["-mem2reg"]
            
            // Optimiser
            let optimTask = NSTask()
            optimTask.currentDirectoryPath = currentDirectory
            optimTask.launchPath = "/usr/local/Cellar/llvm/3.6.2/bin/opt"
            optimTask.arguments = ["-S"] + flags + ["-o", "\(file).ll", "\(file)_.ll"]
            
            optimTask.launch()
            optimTask.waitUntilExit()
            
            if verbose { print("\n\n----------------------------OPTIM----------------------------\n") }
            let ir = try String(contentsOfFile: "\(currentDirectory)/\(file).ll") ?? ""
            if irOnly { print(ir); return }
            if verbose { print(ir) }
            
        } else {
            
            let fileTask = NSTask()
            fileTask.currentDirectoryPath = currentDirectory
            fileTask.launchPath = "/usr/bin/touch"
            fileTask.arguments = ["\(file).ll"]
            
            fileTask.launch()
            fileTask.waitUntilExit()
            
            try ir.writeToFile("\(currentDirectory)/\(file).ll", atomically: true, encoding: NSUTF8StringEncoding)
        }
        
        if irOnly { return }
        
        
        
        
        if verbose { print("\n\n-----------------------------ASM-----------------------------\n") }
        

        if !isStdLib {
            /// compiles the LLVM IR to assembly
            let compileIRtoASMTask = NSTask()
            compileIRtoASMTask.currentDirectoryPath = currentDirectory
            compileIRtoASMTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/llc"
            compileIRtoASMTask.arguments = ["\(file).ll"]
            
            compileIRtoASMTask.launch()
            compileIRtoASMTask.waitUntilExit()
            
            let asm = try String(contentsOfFile: "\(currentDirectory)/\(file).s", encoding: NSUTF8StringEncoding)
            
            if asmOnly { print(asm); return }
            if verbose { print(asm) }
        }
        
        
        if generateLibrary || isStdLib {
            
//            let objFileTask = NSTask()
//            objFileTask.currentDirectoryPath = currentDirectory
//            objFileTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/clang"
//            objFileTask.arguments = ["-c", "\(file).ll"]
//            
//            objFileTask.launch()
//            objFileTask.waitUntilExit()
//            
//            let libGen = NSTask()
//            libGen.currentDirectoryPath = currentDirectory
//            libGen.launchPath = "/usr/bin/libtool"
//            libGen.arguments = ["-dynamic", "\(file).o", "-o", "\(file).dylib", "-lSystem"]
//            
//            libGen.launch()
//            libGen.waitUntilExit()
            
            let rmTask = NSTask()
            rmTask.currentDirectoryPath = currentDirectory
            rmTask.launchPath = "/bin/rm"
            rmTask.arguments = ["\(file)_.ll"]
            
            rmTask.launch()
            rmTask.waitUntilExit()
            
            let bitcodeTask = NSTask()
            bitcodeTask.currentDirectoryPath = currentDirectory
            bitcodeTask.launchPath = "/usr/local/Cellar/llvm/3.6.2/bin/llvm-as"
            bitcodeTask.arguments = ["\(file)_.ll", "-o", "\(file).bc"]
            
            bitcodeTask.launch()
            bitcodeTask.waitUntilExit()
            
            
        } else {
            
            /// Compile IR Code task
            let compileTask = NSTask()
            compileTask.currentDirectoryPath = currentDirectory
            compileTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/clang"
            compileTask.arguments = ["\(file).ll", "-o", "\(file)"]
            
            compileTask.launch()
            compileTask.waitUntilExit()
            
            if buildOnly { return }
            
            
            if verbose { print("\n\n-----------------------------RUN-----------------------------\n") }
            
            /// Run the program
            let runTask = NSTask()
            runTask.currentDirectoryPath = currentDirectory
            runTask.launchPath = "\(currentDirectory)/\(file)"
            
            
            runTask.launch()
            let t0 = CFAbsoluteTimeGetCurrent()
            
            runTask.waitUntilExit()
            
            if case .UncaughtSignal = runTask.terminationReason {
                print("**Fatal Error** program ended with exit code \(runTask.terminationStatus)")
            }
            
            if profile {
                let t = CFAbsoluteTimeGetCurrent() - t0 - 0.062
                let f = NSNumberFormatter()
                f.maximumFractionDigits = 2
                f.minimumFractionDigits = 2
                print("\n--------\nTime elapsed: \(f.stringFromNumber(t)!)s")
            }

        }
        
        
        
        // remove files
        if !preserve {
            for file in ["\(file).ll", "\(file)_.ll", "\(file).s"] {
                
                let rmTask = NSTask()
                rmTask.currentDirectoryPath = currentDirectory
                rmTask.launchPath = "/bin/rm"
                rmTask.arguments = [file]
                
                rmTask.launch()
                rmTask.waitUntilExit()
            }
        }
        
        

        
}



func buildRuntime() {
    
    let runtimeDirectory = "\(PROJECT_DIR)/Vist/Runtime"

    /// Generate LLVM IR File for the helper c++ code
    let runtimeIRGenTask = NSTask()
    runtimeIRGenTask.currentDirectoryPath = runtimeDirectory
    runtimeIRGenTask.launchPath = "/usr/bin/llvm-gcc"
    runtimeIRGenTask.arguments = ["runtime.cpp", "-S", "-emit-llvm"]
    
    runtimeIRGenTask.launch()
    runtimeIRGenTask.waitUntilExit()
    
    /// Turn that LLVM IR code into LLVM bytecode
    let assembleTask = NSTask()
    assembleTask.currentDirectoryPath = runtimeDirectory
    assembleTask.launchPath = "/usr/local/Cellar/llvm/3.6.2/bin/llvm-as"
    assembleTask.arguments = ["runtime.ll"]
    
    assembleTask.launch()
    assembleTask.waitUntilExit()
}


