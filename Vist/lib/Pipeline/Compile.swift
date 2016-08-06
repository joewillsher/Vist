//
//  Compile.swift
//  Vist
//
//  Created by Josef Willsher on 08/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import class Foundation.Task
import class Foundation.Pipe
import class Foundation.FileManager
import class Foundation.FileHandle
import class Foundation.NSString
import struct Foundation.URL

import Dispatch


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
    static let buildStdLib: CompileOptions = [compileStdLib, parseStdLib, produceLib, buildRuntime, linkWithRuntime, Ohigh, preserveTempFiles]
    
    /// Compiles the runtime
    static let buildRuntime = CompileOptions(rawValue: 1 << 14)
    static let debugRuntime = CompileOptions(rawValue: 1 << 15)
    /// Links the input files with the runtime
    private static let linkWithRuntime = CompileOptions(rawValue: 1 << 16)
    /// Parse this file as stdlib code and link manually with runtime
    static let doNotLinkStdLib: CompileOptions = [buildRuntime, linkWithRuntime, parseStdLib]
    
    static let disableInline = CompileOptions(rawValue: 1 << 17)
    
    static let runPreprocessor = CompileOptions(rawValue: 1 << 18)
}



private func parseFiles(_ names: [String],
                        inDirectory dir: String,
                        options: CompileOptions
    ) throws -> [AST] {
    
    var asts: [String: AST] = [:]
    /// The queue used to access asts
    /// - uses must be synchronous
    let astQueue = DispatchQueue(label: "com.vist.ast-array")
    
    // collections storing thrown parse errors
    var errors: [VistError] = [], unhandledError: Error? = nil
    
    /// The dispatch group we put parse threads in
    let parseGroup = DispatchGroup()
    
    for name in names {
        
        let parseQueue = DispatchQueue(label: "com.vist.parse")
        // On a seperate queue, parse the file
        // dispatch onto parse group
        parseQueue.async(group: parseGroup) {
            do {
                // Run preprocessor
                var fileName = name
                if options.contains(.runPreprocessor) {
                    runPreprocessor(file: &fileName, cwd: dir)
                }
                // if we run preprocessor, clean up previst file
                defer {
                    if options.contains(.runPreprocessor) { try! FileManager.default.removeItem(atPath: "\(dir)/\(fileName)") }
                }
                
                // get file contents
                let path = "\(dir)/\(fileName)"
                let doc = try String(contentsOfFile: path, encoding: .utf8)
                
                // Lex code
                let tokens = try doc.getTokens()
                
                // parse tokens & generate AST
                let ast = try Parser.parse(withTokens: tokens, isStdLib: options.contains(.parseStdLib))
                
                if options.contains(.verbose) { // log
                    print("------------------------------AST-------------------------------", ast.astDescription())
                }
                
                // on ast queue, synchronously write this AST
                astQueue.sync {
                    asts[fileName] = ast
                }
            }
            catch let e as VistError {
                // if there's an error we know about, add it to the error array
                // on the astQueue synchronously
                astQueue.sync { errors.append(e) }
            }
            catch let e {
                // ...otherwise just assign to the unhandled one
                astQueue.sync { unhandledError = e }
            }
        }
    }

    // wait for parsing to finish
    parseGroup.wait()
    
    // handle any errors
    try astQueue.sync(execute: {errors}).throwIfErrors()
    if let e = astQueue.sync(execute: {unhandledError}) { throw e }
    
    // synchrnonoslt
    return astQueue.sync { Array(asts.values) }
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
    output: URL? = nil,
    options: CompileOptions
    ) throws {
    
    /// Custom print that writes into the out pipe if its specifed
    func print(_ string: String...) {
        let s = string.joined(separator: " ")
        if let o = output {
            try! FileHandle(forWritingTo: o).write((s+"\n").data(using: .utf8)!)
        }
        else { Swift.print(s) }
    }
    
    // MARK: Parse
    let astList = try parseFiles(fileNames, inDirectory: currentDirectory, options: options)
    
    // collect all ast nodes into a single ast object
    let ast = astList.reduce(AST(exprs: [])) { i, x in
        AST(exprs: i.exprs + x.exprs)
    }
    
    if options.contains(.verbose) { ast.dump() }
    
    
    // MARK: Sema
    if options.contains(.verbose) {
        print("\n------------------------SEMA & LINK AST----------------------------\n")
    }
    
    let globalScope = SemaScope.globalScope(isStdLib: options.contains(.parseStdLib))
    
    try ast.sema(globalScope: globalScope)
    
    if options.contains(.dumpAST) { ast.dump(); return }
    if options.contains(.verbose) { ast.dump() }
    
    // MARK: VIR Gen
    if options.contains(.verbose) {
        ast.dump()
        print("\n----------------------------VIR GEN-------------------------------\n")
    }
    
    // get file title
    let file = explicitName ?? fileNames.first!
        .replacingOccurrences(of: ".vist", with: "")
        .replacingOccurrences(of: ".previst", with: "")
    
    // create module and gen vir
    let virModule = Module()
    try ast.emitVIR(module: virModule, isLibrary: options.contains(.produceLib))
    
    // write out
    let unoptVIRPath = "\(currentDirectory)/\(file)_.vir"
    try virModule.vir.write(toFile: unoptVIRPath, atomically: true, encoding: .utf8)
    defer {
        if !options.contains(.preserveTempFiles) { try! FileManager.default.removeItem(atPath: unoptVIRPath) }
    }
    
    if options.contains(.verbose) {
        print(virModule.vir)
    }
    
    #if DEBUG
        try virModule.verify()
    #endif
    
    // MARK: VIR Optimiser
    if options.contains(.verbose) {
        print("\n----------------------------VIR OPT-------------------------------\n")
    }

    // run optimiser
    try PassManager(module: virModule, optLevel: options.optLevel(), opts: options)
        .runPasses()
    
    // write out
    let optVIRPath = "\(currentDirectory)/\(file).vir"
    try virModule.vir.write(toFile: optVIRPath, atomically: true, encoding: .utf8)
    defer {
        if !options.contains(.preserveTempFiles) { try! FileManager.default.removeItem(atPath: optVIRPath) }
    }
    
    if options.contains(.verbose) {
        print(virModule.vir)
    }
    
    #if DEBUG
        try virModule.verify()
    #endif
    
    if options.contains(.dumpVIR) {
        print(virModule.vir)
        return
    }

    
    // MARK: Build runtime
    if options.contains(.buildRuntime) {
        buildRuntime(debugRuntime: options.contains(.debugRuntime))
    }
    
    
    // MARK: LLVM Generation
    var llvmModule = LLVMModule(name: file)
    
    // import runtime module if needed
    let stdlibDirectory = "\(SOURCE_ROOT)/Vist/stdlib"
    if options.contains(.linkWithRuntime) {
        llvmModule.import(fromFile: "shims.c", directory: stdlibDirectory)
    }
    
    // set triple
    llvmModule.dataLayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
    llvmModule.target = "x86_64-apple-macosx10.12.0"
    
//    defer {
//        // remove files on scope exit
//        if !options.contains(.preserveTempFiles) {
//            for file in ["\(file).ll", "\(file)_.ll", "\(file).s", "\(file).vir", "\(file)_.vir"] {
//                _ = try? FileManager.default.removeItem(atPath: "\(currentDirectory)/\(file)")
//            }
//        }
//    }
    
    // Generate LLVM IR code for program
    if options.contains(.verbose) {
        print("\n-----------------------------IR LOWER------------------------------\n")
    }
    try virModule.virLower(module: llvmModule, isStdLib: options.contains(.parseStdLib))
    
    // print and write to file
    let unoptimisedIR = llvmModule.description()
    let unoptIRPath = "\(currentDirectory)/\(file)_.ll"
    try unoptimisedIR.write(toFile: unoptIRPath, atomically: true, encoding: String.Encoding.utf8)
    defer {
        if !options.contains(.preserveTempFiles) { try! FileManager.default.removeItem(atPath: unoptIRPath) }
    }

    
    // MARK: LLVM Optimiser
    if options.contains(.verbose) {
        print(unoptimisedIR, "\n\n----------------------------OPTIM----------------------------\n")
    }
    
    // run LLVM opt passes
    try performLLVMOptimisations(llvmModule.getModule(),
                                 Int32(options.optLevel().rawValue),
                                 options.contains(.compileStdLib))
    
    // write out
    let optimisedIR = llvmModule.description()
    let optIRPath = "\(currentDirectory)/\(file).ll"
    try optimisedIR.write(toFile: optIRPath, atomically: true, encoding: .utf8)
    defer {
        if !options.contains(.preserveTempFiles) { try! FileManager.default.removeItem(atPath: optIRPath) }
    }
    
    if options.contains(.dumpLLVMIR) {
        print(optimisedIR)
        return
    }
    if options.contains(.verbose) {
        print(optimisedIR, "\n\n----------------------------LINK-----------------------------\n")
    }
    
    
    // MARK: Link and assemble
    let libVistPath = "/usr/local/lib/libvist.dylib"
    let libVistRuntimePath = "/usr/local/lib/libvistruntime.dylib"
    
    // if its the stdlin, produce a dylib
    if options.contains(.compileStdLib) {
        
        // .ll -> .dylib
        // to link against program
        Task.execute(exec: .clang,
                       files: [libVistRuntimePath, "\(file).ll"],
                       outputName: libVistPath,
                       cwd: currentDirectory,
                       args: "-dynamiclib")
    }
    else {
        
        let wantsDumpASM = options.contains(.dumpASM), verboseOutput = options.contains(.verbose)
        
        // if the output requires asm, we compile to it first
        if wantsDumpASM || verboseOutput {
            // .ll -> .s
            // for printing/saving
            Task.execute(exec: .clang,
                         files: ["\(file).ll"],
                         cwd: currentDirectory,
                         args: "-S")
            let asmPath = "\(currentDirectory)/\(file).s"
            let asm = try String(contentsOfFile: asmPath, encoding: .utf8)
            defer {
                if !options.contains(.preserveTempFiles) { try! FileManager.default.removeItem(atPath: asmPath) }
            }
            
            print(asm)
            if wantsDumpASM { return }
        }
        
        // get the input for the clang binary
        let inputFiles = options.contains(.doNotLinkStdLib) ?
            ["\(file).ll"] :
            [libVistRuntimePath, libVistPath, "\(file).ll"]
        // .ll -> exec
        Task.execute(exec: .clang,
                     files: inputFiles,
                     outputName: file,
                     cwd: currentDirectory)
        
        if options.contains(.buildAndRun) {
            if options.contains(.verbose) { print("\n\n-----------------------------RUN-----------------------------\n") }
            runExecutable(file: file, inDirectory: currentDirectory, output: output)
        }
        
    }
    
}


func runExecutable(
    file: String,
    inDirectory: String,
    output: URL? = nil
    ) {
    
    /// Run the program
    let runTask = Task()
    runTask.currentDirectoryPath = inDirectory
    runTask.launchPath = "\(inDirectory)/\(file)"
    
    if let out = output {
        try! runTask.standardOutput = FileHandle(forWritingTo: out)
    }
    
    runTask.launch()
    runTask.waitUntilExit()
    
    if case .uncaughtSignal = runTask.terminationReason {
        let message = "Program terminated with exit code: \(runTask.terminationStatus)"
        if let o = output {
            try! FileHandle(forWritingTo: o).write(message.data(using: .utf8)!)
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
    Task.execute(exec: .clang,
                 files: ["runtime.cpp", "Metadata.cpp", "RefcountedObject.cpp"],
                 outputName: libVistRuntimePath,
                 cwd: runtimeDirectory,
                 args: "-dynamiclib", "-std=c++14", "-O3", "-lstdc++", "-includeruntime.h", debug ? "-DREFCOUNT_DEBUG" : "")
}

func runPreprocessor(file: inout String, cwd: String) {
    
    let preprocessor = "\(SOURCE_ROOT)/Vist/lib/Pipeline/Preprocessor.sh"
    
    Task.execute(execName: preprocessor, files: [file], cwd: cwd, args: [])
    
    file = "\(file).previst"
}


