//
//  Compile.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


func compileDocument(fileName: String, verbose: Bool = true) throws {
    
    let currentDirectory = NSTask().currentDirectoryPath
    
    let doc = try String(contentsOfFile: fileName, encoding: NSUTF8StringEncoding)
    if verbose { print("------------------SOURCE-------------------\n\n\(doc)\n\n\n-------------------TOKS--------------------\n") }
    
    // http://llvm.org/docs/tutorial/LangImpl1.html#language
    
    var lexer = Lexer(code: doc)
    let tokens = try lexer.getTokens()
    
    if verbose { tokens
        .map {"\($0.0): \t\t\t\t\t\($0.1.range.start)--\($0.1.range.end)"}
        .forEach { print($0) } }
    
    var parser = Parser(tokens: tokens)
    
    if verbose { print("\n\n--------------------AST---------------------\n") }
    let ast = try parser.parse()
    if verbose { print(ast.description()) }
    
    if verbose { print("\n\n-----------------LLVM IR------------------\n") }
    
    let (module, main) = try ast.IRGen()
    runModule(module, mainFn: main)

    let ir = String.fromCString(LLVMPrintModuleToString(module))!
    if verbose { print(ir) }
    try ir.writeToFile("example.ll", atomically: true, encoding: NSUTF8StringEncoding)
    
    
    
    if verbose { print("\n\n-------------------LINK------------------\n") }
    
    let stdlibIRGenTask = NSTask()
    stdlibIRGenTask.currentDirectoryPath = currentDirectory
    stdlibIRGenTask.launchPath = "/usr/bin/llvm-gcc"
    stdlibIRGenTask.arguments = ["stdlib.cpp", "-S", "-emit-llvm"]
    
    stdlibIRGenTask.launch()
    stdlibIRGenTask.waitUntilExit()
    
    
    let linkTask = NSTask()
    linkTask.currentDirectoryPath = currentDirectory
    linkTask.launchPath = "/usr/local/Cellar/llvm/3.6.2/bin/llvm-link"
    linkTask.arguments = ["stdlib.ll", "example.ll", "-S", "-o", "linked.ll"]
    
    linkTask.launch()
    linkTask.waitUntilExit()
    
    let linked = try String(contentsOfFile: "linked.ll", encoding: NSUTF8StringEncoding)
    if verbose { print(linked) }
    
    
    if verbose { print("\n\n-------------------ASM-------------------\n") }

    let compileIRTask = NSTask()
    compileIRTask.currentDirectoryPath = currentDirectory
    compileIRTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/llc"
    compileIRTask.arguments = ["linked.ll"]
    
    compileIRTask.launch()
    compileIRTask.waitUntilExit()
    
    let asm = try String(contentsOfFile: "linked.s", encoding: NSUTF8StringEncoding)
    if verbose { print(asm) }

    
    
    
    let compileASMTask = NSTask()
    compileASMTask.currentDirectoryPath = currentDirectory
    compileASMTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/clang"
    compileASMTask.arguments = ["linked.ll", "-o", "exec"]
    
    compileASMTask.launch()
    compileASMTask.waitUntilExit()
    
    if verbose { print("\n\n-------------------RUN-------------------\n") }
    
    
    let runTask = NSTask()
    runTask.currentDirectoryPath = currentDirectory
    runTask.launchPath = "\(currentDirectory)/exec"
    
    runTask.launch()
    runTask.waitUntilExit()
    
}




