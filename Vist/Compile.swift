//
//  Compile.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


func compileDocument(fileName: String, verbose: Bool = true, irOnly: Bool = false, asmOnly: Bool = false, buildOnly: Bool = false) throws {
    
    let file = fileName.stringByReplacingOccurrencesOfString(".vist", withString: "")
    let currentDirectory = NSTask().currentDirectoryPath
    
    
    
    
    let doc = try String(contentsOfFile: fileName, encoding: NSUTF8StringEncoding)
    if verbose { print("------------------SOURCE-------------------\n\n\(doc)\n\n\n-------------------TOKS--------------------\n") }
    
    // http://llvm.org/docs/tutorial/LangImpl1.html#language
    
    
    // Lex code
    var lexer = Lexer(code: doc)
    let tokens = try lexer.getTokens()
    
    if verbose { tokens
        .map {"\($0.0): \t\t\t\t\t\($0.1.range.start)--\($0.1.range.end)"}
        .forEach { print($0) } }
    
    
    
    
    
    
    
    
    if verbose { print("\n\n--------------------AST---------------------\n") }

    // parse tokens & generate AST
    var parser = Parser(tokens: tokens)
    let ast = try parser.parse()
    if verbose { print(ast.description()) }
    
    
    
    
    
    if verbose { print("\n\n-------------------LINK--------------------\n") }

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
    
    
    
    
    
    
    
    
    if verbose { print("\n\n-----------------LLVM IR------------------\n") }
    
    // Generate LLVM IR code for program
    try ast.IRGen(module: module)
    
    configModule(module)
    
    // print and write to file
    let ir = String.fromCString(LLVMPrintModuleToString(module))!
    if verbose { print(ir) }
    try ir.writeToFile("\(file).ll", atomically: true, encoding: NSUTF8StringEncoding)
    
    if irOnly { return }
    
    
    
    
    if verbose { print("\n\n-------------------ASM-------------------\n") }

    /// compiles the LLVM IR to assembly
    let compileIRtoASMTask = NSTask()
    compileIRtoASMTask.currentDirectoryPath = currentDirectory
    compileIRtoASMTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/llc"
    compileIRtoASMTask.arguments = ["\(file).ll"]
    
    compileIRtoASMTask.launch()
    compileIRtoASMTask.waitUntilExit()
    
    let asm = try String(contentsOfFile: "\(file).s", encoding: NSUTF8StringEncoding)
    if verbose { print(asm) }

    if asmOnly { return }
    
    
    /// Compile IR Code task
    let compileTask = NSTask()
    compileTask.currentDirectoryPath = currentDirectory
    compileTask.launchPath = "/usr/local/Cellar/llvm36/3.6.2/lib/llvm-3.6/bin/clang"
    compileTask.arguments = ["\(file).ll", "-o", "\(file)"]
    
    compileTask.launch()
    compileTask.waitUntilExit()
    
    if buildOnly { return }
    
    
    
    
    
    
    if verbose { print("\n\n-------------------RUN-------------------\n") }
    
    /// Run the program
    let runTask = NSTask()
    runTask.currentDirectoryPath = currentDirectory
    runTask.launchPath = "\(currentDirectory)/\(file)"
    
    runTask.launch()
    runTask.waitUntilExit()
    
}




