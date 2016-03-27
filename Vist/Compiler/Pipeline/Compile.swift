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

// ugh, preprocessor macros broke in 2.2. to fix use `PROJECT_DIR`
private let llvmDirectory = "/usr/local/Cellar/llvm/3.6.2/bin"
private let stdLibDirectory = "\(SOURCE_ROOT)/Vist/stdlib"

// IDEA to have multiple file compilation:
//   - A FunctionPrototype AST object which is added to ast of other files
//   - When IRGen'd it adds the function decl to the module
//      - Is this how a FnDecl behaves with nil impl already?
//   - Also need a way to do this out-of-order so all functions (and types) are defined first

func compileDocuments(
    fileNames: [String],
    inDirectory: String,
    out: NSPipe? = nil,
    verbose: Bool = true,
    dumpAST: Bool = false,
    irOnly: Bool = false,
    asmOnly: Bool = false,
    buildOnly: Bool = false,
    profile: Bool = true,
    optim: Bool = true,
    preserve: Bool = false,
    generateLibrary: Bool = false,
    isStdLib: Bool = false,
    parseStdLib: Bool = false)
    throws {
        
        let currentDirectory = isStdLib ? stdLibDirectory: inDirectory
        
        var head: AST? = nil
        var all: [AST] = []
        
        let globalScope = SemaScope.globalScope(isStdLib || parseStdLib)
        
        for (index, fileName) in fileNames.enumerate() {
            
            let path = "\(currentDirectory)/\(fileName)"
            let doc = try String(contentsOfFile: path, encoding: NSUTF8StringEncoding)
            if verbose { print("----------------------------SOURCE-----------------------------\n\(doc)\n\n\n-----------------------------TOKS------------------------------\n") }
            
            // Lex code
            let tokens = try doc.getTokens()
            
            if verbose { tokens
                .map {"\($0.0): \t\t\t\t\t\($0.1.range.start)--\($0.1.range.end)"}
                .forEach { print($0) } }
            
            
            if verbose { print("\n\n------------------------------AST-------------------------------\n") }
            
            // parse tokens & generate AST
            let ast = try Parser.parseWith(tokens, isStdLib: isStdLib || parseStdLib)
            
            if dumpAST { print(ast.astString); return }
            if verbose { print(ast.astString) }
            
            
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
        
        if verbose { print("\n------------------------SEMA & LINK AST----------------------------\n") }
        
        guard let main = head else { fatalError("No main file supplied") }
        let ast = main
        
        // TODO: parralelise file compilation
        
        try sema(ast, globalScope: globalScope)
        if verbose { print(ast.astString) }
        
        let file = fileNames.first!.stringByReplacingOccurrencesOfString(".vist", withString: "")
        
        
        let vhirModule = Module()
        
        if verbose { print("\n----------------------------VHIR GEN-------------------------------\n") }
        
        try ast.emitVHIR(module: vhirModule, isLibrary: generateLibrary)
        try vhirModule.vhir.writeToFile("\(currentDirectory)/\(file)_.vhir", atomically: true, encoding: NSUTF8StringEncoding)
        
        if verbose { print(vhirModule.vhir) }
        
        if verbose { print("\n----------------------------VHIR OPT-------------------------------\n") }
        
        try vhirModule.runPasses(optLevel:.high)
        
        try vhirModule.vhir.writeToFile("\(currentDirectory)/\(file).vhir", atomically: true, encoding: NSUTF8StringEncoding)
        if verbose { print(vhirModule.vhir) }
        
        
        var llvmModule = LLVMModuleCreateWithName("vist_module")
        
        if isStdLib {
            linkWithRuntime(&llvmModule, withFile: "\(SOURCE_ROOT)/Vist/Runtime/runtime.bc")
        }
        configModule(llvmModule)
        
        defer {
            // remove files
            if !preserve {
                Command(.rm,
                        files: ["\(file).ll", "\(file)_.ll", "\(file).s", "\(file).vhir", "\(file)_.vhir"],
                        cwd: currentDirectory).exectute()
            }
        }
        
        // Generate LLVM IR code for program
        if verbose { print("\n-----------------------------IR LOWER------------------------------\n") }
        try vhirModule.vhirLower(llvmModule, isStdLib: isStdLib || parseStdLib)
        
        // print and write to file
        try String.fromCString(LLVMPrintModuleToString(llvmModule))?.writeToFile("\(currentDirectory)/\(file)_.ll", atomically: true, encoding: NSUTF8StringEncoding)
        
        if verbose { LLVMDumpModule(llvmModule) }
        
        
        //run my optimisation passes
        
        if verbose { print("\n\n----------------------------OPTIM----------------------------\n") }
        
        
        if optim || isStdLib {
            performLLVMOptimisations(llvmModule, 3, isStdLib)
            try String.fromCString(LLVMPrintModuleToString(llvmModule))?.writeToFile("\(currentDirectory)/\(file).ll", atomically: true, encoding: NSUTF8StringEncoding)
            
            Command(.opt,
                    files: ["\(file).ll"],
                    execName: "\(file).ll",
                    cwd: currentDirectory,
                    args: "-S", "-O3").exectute()
        }
        else {
            performLLVMOptimisations(llvmModule, 0, false)
            try String.fromCString(LLVMPrintModuleToString(llvmModule))?.writeToFile("\(currentDirectory)/\(file).ll", atomically: true, encoding: NSUTF8StringEncoding)
        }
        
        if verbose { print(try String(contentsOfFile: "\(currentDirectory)/\(file).ll", encoding: NSUTF8StringEncoding) ?? "") }
        if irOnly { return }
        
        
        
        if verbose { print("\n\n----------------------------LINK-----------------------------\n") }
        

        if isStdLib {
            // generate .o file to link against program
            Command(.clang,
                    files: ["\(file).ll"],
                    cwd: currentDirectory,
                    args: "-c").exectute()
            
            // generate .bc file for optimiser
            Command(.assemble,
                    files: ["\(file).ll"],
                    cwd: currentDirectory).exectute()
            // TODO: install the vistc exec as a lib in /usr/local/lib
        }
        else {
            
            /// compiles the LLVM IR to assembly
            Command(.clang,
                    files: ["\(file).ll"],
                    cwd: currentDirectory,
                    args: "-S").exectute()
            
            let asm = try String(contentsOfFile: "\(currentDirectory)/\(file).s", encoding: NSUTF8StringEncoding)
            
            if asmOnly { print(asm); return }
            if verbose { print(asm) }
            
            
            /// link file to stdlib and compile
            Command(.clang,
                    files: ["\(stdLibDirectory)/stdlib.o", "\(file).ll"],
                    execName: file,
                    cwd: currentDirectory).exectute()
            if buildOnly { return }
            
            if verbose { print("\n\n-----------------------------RUN-----------------------------\n") }
            
            /// Run the program
            let runTask = NSTask()
            runTask.currentDirectoryPath = currentDirectory
            runTask.launchPath = "\(currentDirectory)/\(file)"
            
            if let out = out {
                runTask.standardOutput = out
            }
            
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
                print("\n------------------\nTime elapsed: \(f.stringFromNumber(t)!)s")
            }
            
        }
        
}



func buildRuntime() {
    
    let runtimeDirectory = "\(SOURCE_ROOT)/Vist/Runtime"
    
    /// Generate LLVM IR File for the helper c++ code
    Command(.clang,
            files: ["runtime.cpp"],
            cwd: runtimeDirectory,
            args: "-S", "-emit-llvm").exectute()
    
    /// Turn that LLVM IR code into LLVM bytecode
    Command(.assemble,
            files: ["runtime.ll"],
            cwd: runtimeDirectory).exectute()
}


