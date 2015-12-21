//
//  Compile.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


func compileDocument(fileName: String, verbose: Bool = true, dumpAST: Bool = false, irOnly: Bool = false, asmOnly: Bool = false, buildOnly: Bool = false, profile: Bool = true, optim: Bool = true) throws {
    
    let file = fileName.stringByReplacingOccurrencesOfString(".vist", withString: "")
    let currentDirectory = NSTask().currentDirectoryPath
    
    
    
    
    let doc = try String(contentsOfFile: fileName, encoding: NSUTF8StringEncoding)
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
    var parser = Parser(tokens: tokens)
    let ast = try parser.parse()
    if dumpAST { print(ast.description()); return }
    if verbose { print(ast.description()) }
    
    
    
    
    if verbose { print("\n\n-----------------------------LINK------------------------------\n") }

    /// Generate LLVM IR File for the helper c++ code
    let helperIRGenTask = NSTask()
    helperIRGenTask.currentDirectoryPath = currentDirectory
    helperIRGenTask.launchPath = "/usr/bin/llvm-gcc"
    helperIRGenTask.arguments = ["helper.cpp", "-S", "-emit-llvm"]
    
    helperIRGenTask.launch()
    helperIRGenTask.waitUntilExit()
    
    /// Turn that LLVM IR code into LLVM bytecode
    let assembleTask = NSTask()
    assembleTask.currentDirectoryPath = currentDirectory
    assembleTask.launchPath = "/usr/local/Cellar/llvm/3.6.2/bin/llvm-as"
    assembleTask.arguments = ["helper.ll"]
    
    assembleTask.launch()
    assembleTask.waitUntilExit()
    
    
    // Create vist program module and link against the helper bytecode
    var module = LLVMModuleCreateWithName("vist_module")
    linkModule(&module, withFile: "helper.bc")
    configModule(module)
    
//    if verbose { LLVMDumpModule(module) }
    
    
    
    
    
    
    
    if verbose { print("\n\n---------------------------LLVM IR----------------------------\n") }
    
    // Generate LLVM IR code for program
    try ast.IRGen(module: module)
    
    configModule(module)
    
    // print and write to file
    let ir = String.fromCString(LLVMPrintModuleToString(module))!
    try ir.writeToFile("\(file).ll", atomically: true, encoding: NSUTF8StringEncoding)
    
    if verbose { print(ir) }
    
    
    if optim {
        
        let flags = [
            "-mem2reg",
            "-loop-unroll",
            "-constprop",
            "-correlated-propagation",
            "-consthoist",
            "-inline",
            "-instcombine",
            "-instsimplify",
            "-load-combine",
            "-loop-reduce",
            "-loop-vectorize",
            "-tailcallelim"
        ]
        
        // Optimiser
        let optimTask = NSTask()
        optimTask.currentDirectoryPath = currentDirectory
        optimTask.launchPath = "/usr/local/Cellar/llvm/3.6.2/bin/opt"
        optimTask.arguments = ["-S"] + flags + ["-o", "\(file)_optim.ll", "\(file).ll"]
        
        optimTask.launch()
        optimTask.waitUntilExit()
        
        if verbose { print("\n\n----------------------------OPTIM----------------------------\n") }
        let ir = try String(contentsOfFile: "\(file)_optim.ll")
        if irOnly { print(ir); return }
        if verbose { print(ir) }
    }
    
    if irOnly { return }

    
    
    
    if verbose { print("\n\n-----------------------------ASM-----------------------------\n") }

    /// compiles the LLVM IR to assembly
    let compileIRtoASMTask = NSTask()
    compileIRtoASMTask.currentDirectoryPath = currentDirectory
    compileIRtoASMTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/llc"
    compileIRtoASMTask.arguments = ["\(file)_optim.ll"]
    
    compileIRtoASMTask.launch()
    compileIRtoASMTask.waitUntilExit()
    
    let asm = try String(contentsOfFile: "\(file)_optim.s", encoding: NSUTF8StringEncoding)

    if asmOnly { print(asm); return }
    if verbose { print(asm) }
    
    
    
    /// Compile IR Code task
    let compileTask = NSTask()
    compileTask.currentDirectoryPath = currentDirectory
    compileTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/clang"
    compileTask.arguments = ["\(file)_optim.ll", "-o", "\(file)"]
    
    compileTask.launch()
    compileTask.waitUntilExit()
    
    if buildOnly { return }
    
    
    
    
    
    if verbose { print("\n\n-----------------------------RUN-----------------------------\n") }
    
    /// Run the program
    let runTask = NSTask()
    runTask.currentDirectoryPath = currentDirectory
    runTask.launchPath = "\(currentDirectory)/\(file)"
    
    let t0 = CFAbsoluteTimeGetCurrent()
    
    runTask.launch()
    runTask.waitUntilExit()
    
    if profile {
        let t = CFAbsoluteTimeGetCurrent() - t0
        print("\n--------\nTime elapsed: \(t)s")
    }

}




