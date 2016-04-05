//
//  Compile.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.NSTask
import class Foundation.NSPipe
import Foundation.NSString


struct CompileOptions : OptionSetType {
    
    let rawValue: Int
    init(rawValue: Int) { self.rawValue = rawValue }
    
    static let dumpAST = CompileOptions(rawValue: 1 << 0)
    static let dumpVHIR = CompileOptions(rawValue: 1 << 1)
    static let dumpLLVMIR = CompileOptions(rawValue: 1 << 2)
    static let dumpASM = CompileOptions(rawValue: 1 << 3)
    
    static let buildAndRun = CompileOptions(rawValue: 1 << 4)
    static let verbose = CompileOptions(rawValue: 1 << 5)
    static let preserveTempFiles = CompileOptions(rawValue: 1 << 6)

    static let disableStdLibInlinePass = CompileOptions(rawValue: 1 << 7)
    private static let runVHIROptPasses = CompileOptions(rawValue: 1 << 8)
    private static let runLLVMOptPasses = CompileOptions(rawValue: 1 << 9)
    static let aggressiveOptimisation = CompileOptions(rawValue: 1 << 10)
    /// No optimisations
    static let Onone: CompileOptions = []
    /// No optimisations, dont even inline stdlib symbols
    static let O0: CompileOptions = [disableStdLibInlinePass]
    /// Low opt level
    static let O: CompileOptions = [runVHIROptPasses, runLLVMOptPasses]
    /// High opt level
    static let Ohigh: CompileOptions = [O, aggressiveOptimisation]
    
    static let produceLib = CompileOptions(rawValue: 1 << 11)
    /// Compiles stdlib.vist
    private static let compileStdLib = CompileOptions(rawValue: 1 << 12)
    /// Parses the document as if it were the stdlib, exposing Builtin types and functions
    private static let parseStdLib = CompileOptions(rawValue: 1 << 13)
    /// Compiles the standard libary before the input files
    static let buildStdLib: CompileOptions = [compileStdLib, parseStdLib, produceLib, buildRuntime, linkWithRuntime, Ohigh]
    
    /// Compiles the runtime
    static let buildRuntime = CompileOptions(rawValue: 1 << 14)
    /// Links the input files with the runtime
    private static let linkWithRuntime = CompileOptions(rawValue: 1 << 15)
    /// Parse this file as stdlib code and link manually with runtime
    static let doNotLinkStdLib: CompileOptions = [linkWithRuntime, parseStdLib]
}

/// Compiles series of files
/// - parameter fileNames: The file paths to compile
/// - parameter inDirectory: The current working directory
/// - parameter out: Override stdout 
/// - parameter options: An option set of compilation flags
func compileDocuments(
    fileNames: [String],
    inDirectory currentDirectory: String,
    out: NSPipe? = nil,
    options: CompileOptions
    ) throws {
    
    var head: AST? = nil
    var all: [AST] = []
    
    let globalScope = SemaScope.globalScope(options.contains(.parseStdLib))
    
    for (index, fileName) in fileNames.enumerate() {
        
        let path = "\(currentDirectory)/\(fileName)"
        let doc = try String(contentsOfFile: path, encoding: NSUTF8StringEncoding)
        if options.contains(.verbose) { print("----------------------------SOURCE-----------------------------", doc, "\n\n-----------------------------TOKS------------------------------\n") }
        
        // Lex code
        let tokens = try doc.getTokens()
        
        if options.contains(.verbose) {
            tokens
                .map {"\($0.0): \t\t\t\t\t\($0.1.range.start)--\($0.1.range.end)"}
                .forEach { print($0) }
            print("\n\n------------------------------AST-------------------------------\n")
        }
        
        // parse tokens & generate AST
        let ast = try Parser.parseWith(tokens, isStdLib: options.contains(.parseStdLib))
        
        if options.contains(.dumpAST) { print(ast.astString); return }
        if options.contains(.verbose) { print(ast.astString) }
        
        if let h = head {
            head = try astLink(h, other: [ast])
        }
        
        if index == 0 {
            head = ast
        }
        else {
            all.append(ast)
        }
    }
    
    if options.contains(.verbose) { print("\n------------------------SEMA & LINK AST----------------------------\n") }
    
    guard let main = head else { fatalError("No main file supplied") }
    let ast = main
    
    // TODO: parralelise file compilation
    
    try sema(ast, globalScope: globalScope)
    if options.contains(.dumpAST) { print(ast.astString); return }
    if options.contains(.verbose) { print(ast.astString, "\n----------------------------VHIR GEN-------------------------------\n") }
    
    let file = fileNames.first!.stringByReplacingOccurrencesOfString(".vist", withString: "")
    
    
    let vhirModule = Module()
    
    try ast.emitVHIR(module: vhirModule, isLibrary: options.contains(.produceLib))
    try vhirModule.vhir.writeToFile("\(currentDirectory)/\(file)_.vhir", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.verbose) { print(vhirModule.vhir, "\n----------------------------VHIR OPT-------------------------------\n") }
    
    try vhirModule.runPasses(optLevel: options.optLevel())
    try vhirModule.vhir.writeToFile("\(currentDirectory)/\(file).vhir", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.dumpVHIR) { print(vhirModule.vhir); return }
    if options.contains(.verbose) { print(vhirModule.vhir) }
    
    
    var llvmModule = LLVMModuleCreateWithName(file)
    
    if options.contains(.linkWithRuntime) {
        linkWithRuntime(&llvmModule, withFile: "\(SOURCE_ROOT)/Vist/Runtime/runtime.bc")
    }
    configModule(llvmModule)
    
    defer {
        // remove files
        if !options.contains(.preserveTempFiles) {
            NSTask.execute(.rm,
                           files: ["\(file).ll", "\(file)_.ll", "\(file).s", "\(file).vhir", "\(file)_.vhir"],
                           cwd: currentDirectory)
        }
    }
    
    // Generate LLVM IR code for program
    if options.contains(.verbose) { print("\n-----------------------------IR LOWER------------------------------\n") }
    try vhirModule.vhirLower(llvmModule, isStdLib: options.contains(.parseStdLib))
    
    // print and write to file
    try String.fromCString(LLVMPrintModuleToString(llvmModule))?.writeToFile("\(currentDirectory)/\(file)_.ll", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.verbose) { LLVMDumpModule(llvmModule); print("\n\n----------------------------OPTIM----------------------------\n") }
    
    
    //run my optimisation passes
    
    if !options.contains(.disableStdLibInlinePass) {
        performLLVMOptimisations(llvmModule,
                                 Int32(options.optLevel().rawValue),
                                 options.contains(.compileStdLib))
    }
    try String.fromCString(LLVMPrintModuleToString(llvmModule))?.writeToFile("\(currentDirectory)/\(file).ll", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.runLLVMOptPasses) {
        NSTask.execute(.opt,
                       files: ["\(file).ll"],
                       outputName: "\(file).ll",
                       cwd: currentDirectory,
                       args: "-S", "-O3")
    }
    
    let llvmIR = try String(contentsOfFile: "\(currentDirectory)/\(file).ll", encoding: NSUTF8StringEncoding) ?? ""
    if options.contains(.dumpLLVMIR) { print(llvmIR); return }
    if options.contains(.verbose) { print(llvmIR, "\n\n----------------------------LINK-----------------------------\n") }
    
    if options.contains(.buildRuntime) {
        buildRuntime()
    }
    
    let libVistPath = "/usr/local/lib/libvist.dylib"
    
    if options.contains(.compileStdLib) {
        // .ll -> .dylib
        // to link against program
        NSTask.execute(.clang,
                       files: ["\(file).ll"],
                       outputName: libVistPath,
                       cwd: currentDirectory,
                       args: "-dynamiclib")
        
        // .ll -> .bc
        // for optimiser
        NSTask.execute(.assemble,
                       files: ["\(file).ll"],
                       cwd: currentDirectory)
        // TODO: install the vistc exec as a lib in /usr/local/lib
    }
    else {
        
        // .ll -> .s
        // for printing/saving
        NSTask.execute(.clang,
                       files: ["\(file).ll"],
                       cwd: currentDirectory,
                       args: "-S")
        
        let asm = try String(contentsOfFile: "\(currentDirectory)/\(file).s", encoding: NSUTF8StringEncoding)
        
        if options.contains(.dumpASM) { print(asm); return }
        if options.contains(.verbose) { print(asm) }
        
        
        let inputFiles = options.contains(.doNotLinkStdLib) ? ["\(file).ll"] : [libVistPath, "\(file).ll"]
        // .ll -> exec
        NSTask.execute(.clang,
                       files: inputFiles,
                       outputName: file,
                       cwd: currentDirectory)
        
        if options.contains(.buildAndRun) {
            if options.contains(.verbose) { print("\n\n-----------------------------RUN-----------------------------\n") }
            runExecutable(file, inDirectory: currentDirectory, out: out)
        }
        
    }
    
}


func runExecutable(
    file: String,
    inDirectory: String,
    out: NSPipe? = nil
    ) {
    
    /// Run the program
    let runTask = NSTask()
    runTask.currentDirectoryPath = inDirectory
    runTask.launchPath = "\(inDirectory)/\(file)"
    
    if let out = out {
        runTask.standardOutput = out
    }
    
    runTask.launch()
    runTask.waitUntilExit()
}


func buildRuntime() {
    
    let runtimeDirectory = "\(SOURCE_ROOT)/Vist/runtime"
    
    // .cpp -> .ll
    NSTask.execute(.clang,
                   files: ["runtime.cpp"],
                   cwd: runtimeDirectory,
                   args: "-S", "-emit-llvm", "-std=c++14")
    
    // .ll -> .bc
    NSTask.execute(.assemble,
                   files: ["runtime.ll"],
                   cwd: runtimeDirectory)
}


