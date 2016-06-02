//
//  Compile.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.NSTask
import class Foundation.NSPipe
import class Foundation.NSFileManager
import Foundation.NSString


struct CompileOptions : OptionSet {
    
    let rawValue: Int
    init(rawValue: Int) { self.rawValue = rawValue }
    
    static let dumpAST = CompileOptions(rawValue: 1 << 1)
    static let dumpVIR = CompileOptions(rawValue: 1 << 2)
    static let dumpLLVMIR = CompileOptions(rawValue: 1 << 3)
    static let dumpASM = CompileOptions(rawValue: 1 << 4)
    
    static let buildAndRun = CompileOptions(rawValue: 1 << 5)
    static let verbose = CompileOptions(rawValue: 1 << 6)
    static let preserveTempFiles = CompileOptions(rawValue: 1 << 7)

    /// No optimisations
    static let O0: CompileOptions = CompileOptions(rawValue: 1 << 8)
    /// Low opt level
    static let O: CompileOptions = CompileOptions(rawValue: 1 << 9)
    /// High opt level
    static let Ohigh: CompileOptions = CompileOptions(rawValue: 1 << 10)
    
    static let produceLib = CompileOptions(rawValue: 1 << 11)
    /// Compiles stdlib.vist
    private static let compileStdLib = CompileOptions(rawValue: 1 << 12)
    /// Parses the document as if it were the stdlib, exposing Builtin types and functions
    private static let parseStdLib = CompileOptions(rawValue: 1 << 13)
    /// Compiles the standard libary before the input files
    static let buildStdLib: CompileOptions = [compileStdLib, parseStdLib, produceLib, buildRuntime, linkWithRuntime, Ohigh, verbose, preserveTempFiles]
    
    /// Compiles the runtime
    static let buildRuntime = CompileOptions(rawValue: 1 << 14)
    static let debugRuntime = CompileOptions(rawValue: 1 << 15)
    /// Links the input files with the runtime
    private static let linkWithRuntime = CompileOptions(rawValue: 1 << 16)
    /// Parse this file as stdlib code and link manually with runtime
    static let doNotLinkStdLib: CompileOptions = [buildRuntime, linkWithRuntime, parseStdLib]
    
    static let runPreprocessor = CompileOptions(rawValue: 1 << 17)
}

/// Compiles series of files
/// - parameter fileNames: The file paths to compile
/// - parameter inDirectory: The current working directory
/// - parameter out: Override stdout 
/// - parameter options: An option set of compilation flags
func compileDocuments(
    fileNames: [String],
    inDirectory currentDirectory: String,
    explicitName: String? = nil,
    out: NSPipe? = nil,
    options: CompileOptions
    ) throws {
    
    /// Custom print that writes into the out pipe if its specifed
    func print(_ string: String...) {
        let s = string.joined(separator: " ")
        if let o = out { o.fileHandleForWriting.write((s+"\n").data(using: NSUTF8StringEncoding)!) }
        else { Swift.print(s) }
    }
    
    var head: AST? = nil
    var all: [AST] = [], names: [String] = []
    
    let globalScope = SemaScope.globalScope(isStdLib: options.contains(.parseStdLib))
    
    for (index, name) in fileNames.enumerated() {
        
        var fileName = name
        if options.contains(.runPreprocessor) {
            runPreprocessor(file: &fileName, cwd: currentDirectory)
        }
        
        let path = "\(currentDirectory)/\(fileName)"
        let doc = try String(contentsOfFile: path, encoding: NSUTF8StringEncoding)
        
        // Lex code
        let tokens = try doc.getTokens()
        
        if options.contains(.verbose) {
            print("------------------------------AST-------------------------------")
        }
        
        // parse tokens & generate AST
        let ast = try Parser.parse(withTokens: tokens, isStdLib: options.contains(.parseStdLib))
        
        if options.contains(.dumpAST) { ast.dump(); return }
        if options.contains(.verbose) { ast.dump() }
        
        if let h = head {
            h.exprs.append(contentsOf: ast.exprs)
        }
        
        if index == 0 {
            head = ast
        }
        else {
            all.append(ast)
        }
        names.append(fileName)
    }
    
    if options.contains(.verbose) {
        print("\n------------------------SEMA & LINK AST----------------------------\n")
    }
    
    guard let main = head else {
        fatalError("No main file supplied")
    }
    let ast = main
    
    // TODO: parralelise file compilation
    
    try ast.sema(globalScope: globalScope)
    if options.contains(.dumpAST) {
        ast.dump()
        return
    }
    if options.contains(.verbose) {
        ast.dump()
        print("\n----------------------------VIR GEN-------------------------------\n")
    }
    
    let file = explicitName ?? names.first!
        .replacingOccurrences(of: ".vist", with: "")
        .replacingOccurrences(of: ".previst", with: "")
    let virModule = Module()
    
    try ast.emitVIR(module: virModule, isLibrary: options.contains(.produceLib))
    try virModule.vir.write(toFile: "\(currentDirectory)/\(file)_.vir", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.verbose) {
        print(virModule.vir, "\n----------------------------VIR OPT-------------------------------\n")
    }
    
    try virModule.runPasses(optLevel: options.optLevel())
    try virModule.vir.write(toFile: "\(currentDirectory)/\(file).vir", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.dumpVIR) { print(virModule.vir); return }
    if options.contains(.verbose) { print(virModule.vir) }
    
    if options.contains(.buildRuntime) {
        buildRuntime(debugRuntime: options.contains(.debugRuntime))
    }
    
    let stdlibDirectory = "\(SOURCE_ROOT)/Vist/stdlib"
    
    var llvmModule = LLVMModule(name: file)
    if options.contains(.linkWithRuntime) {
        llvmModule.import(fromFile: "shims.c", directory: stdlibDirectory)
    }
    llvmModule.dataLayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
    llvmModule.target = "x86_64-apple-macosx10.11.0"
    
    defer {
        // remove files
        if !options.contains(.preserveTempFiles) {
            for file in ["\(file).ll", "\(file)_.ll", "\(file).s", "\(file).vir", "\(file)_.vir"] {
                _ = try? NSFileManager.default().removeItem(atPath: "\(currentDirectory)/\(file)")
            }
            if options.contains(.runPreprocessor) {
                for file in names {
                    _ = try? NSFileManager.default().removeItem(atPath: "\(currentDirectory)/\(file)")
                }
            }
        }
    }
    
    // Generate LLVM IR code for program
    if options.contains(.verbose) {
        print("\n-----------------------------IR LOWER------------------------------\n")
    }
    try virModule.virLower(module: llvmModule, isStdLib: options.contains(.parseStdLib))
    
    // print and write to file
    let unoptimisedIR = llvmModule.description()
    try unoptimisedIR.write(toFile: "\(currentDirectory)/\(file)_.ll", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.verbose) {
        print(unoptimisedIR, "\n\n----------------------------OPTIM----------------------------\n")
    }
    
    //run my optimisation passes
    
    try performLLVMOptimisations(llvmModule.getModule(),
                                 Int32(options.optLevel().rawValue),
                                 options.contains(.compileStdLib))
    
    let optimisedIR = llvmModule.description()
    try optimisedIR.write(toFile: "\(currentDirectory)/\(file).ll", atomically: true, encoding: NSUTF8StringEncoding)
    
    if options.contains(.dumpLLVMIR) {
        print(optimisedIR); return
    }
    if options.contains(.verbose) {
        print(optimisedIR, "\n\n----------------------------LINK-----------------------------\n")
    }
    
    let libVistPath = "/usr/local/lib/libvist.dylib"
    let libVistRuntimePath = "/usr/local/lib/libvistruntime.dylib"
    
    if options.contains(.compileStdLib) {
        
        // .ll -> .dylib
        // to link against program
        NSTask.execute(exec: .clang,
                       files: [libVistRuntimePath, "\(file).ll"],
                       outputName: libVistPath,
                       cwd: currentDirectory,
                       args: "-dynamiclib")
    }
    else {
        // .ll -> .s
        // for printing/saving
        NSTask.execute(exec: .clang,
                       files: ["\(file).ll"],
                       cwd: currentDirectory,
                       args: "-S")
        
        let asm = try String(contentsOfFile: "\(currentDirectory)/\(file).s", encoding: NSUTF8StringEncoding)
        
        if options.contains(.dumpASM) { print(asm); return }
        if options.contains(.verbose) { print(asm) }
        
        
        let inputFiles = options.contains(.doNotLinkStdLib) ? ["\(file).ll"] : [libVistRuntimePath, libVistPath, "\(file).ll"]
        // .ll -> exec
        NSTask.execute(exec: .clang,
                       files: inputFiles,
                       outputName: file,
                       cwd: currentDirectory)
        
        if options.contains(.buildAndRun) {
            if options.contains(.verbose) { print("\n\n-----------------------------RUN-----------------------------\n") }
            runExecutable(file: file, inDirectory: currentDirectory, out: out)
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
    
    if case .uncaughtSignal = runTask.terminationReason {
        let message = "Program terminated with exit code: \(runTask.terminationStatus)"
        if let o = out {
            o.fileHandleForWriting.write(message.data(using: NSUTF8StringEncoding)!)
        }
        else {
            print(message)
        }
    }
}


func buildRuntime(debugRuntime debug: Bool) {
    
    let runtimeDirectory = "\(SOURCE_ROOT)/Vist/stdlib/runtime"
    let libVistRuntimePath = "/usr/local/lib/libvistruntime.dylib"
        
    // .cpp -> .dylib
    // to link against program
    NSTask.execute(exec: .sysclang,
                   files: ["runtime.cpp", "Metadata.cpp", "RefcountedObject.cpp"],
                   outputName: libVistRuntimePath,
                   cwd: runtimeDirectory,
                   args: "-dynamiclib", "-std=c++14", "-lstdc++", "-includeruntime.hh", debug ? "-DREFCOUNT_DEBUG" : "")
}

func runPreprocessor(file: inout String, cwd: String) {
    
    let preprocessor = "\(SOURCE_ROOT)/Vist/lib/Pipeline/Preprocessor.sh"
    
    NSTask.execute(execName: preprocessor, files: [file], cwd: cwd, args: [])
    
    file = "\(file).previst"
}


