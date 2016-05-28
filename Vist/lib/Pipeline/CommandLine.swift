//
//  CommandLine.swift
//  Vist
//
//  Created by Josef Willsher on 30/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSPipe
import class Foundation.NSNumberFormatter
import CoreFoundation.CFDate
import class Foundation.NSString

public func compileWithOptions(flags: [String], inDirectory dir: String, out: NSPipe? = nil) throws {
    
    guard !flags.isEmpty else { fatalError("No input files") }
    
    let files = flags.filter { $0.containsString(".vist") }
    var compileOptions = CompileOptions(rawValue: 0)
    
    let map: [String: CompileOptions] = [
        "-verbose": .verbose,
        "-preserve": .preserveTempFiles,
        "-dump-ast": .dumpAST,
        "-emit-llvm": .dumpLLVMIR,
        "-emit-vir": .dumpVIR,
        "-emit-asm": .dumpASM,
        "-run": .buildAndRun,
        "-r": .buildAndRun,
        "-O0": .O0,
        "-O": .O,
        "-Ohigh": .Ohigh,
        "-lib": .produceLib,
        "-parse-stdlib": .doNotLinkStdLib,
        "-build-runtime": .buildRuntime,
        "-debug-runtime": .debugRuntime,
        "-run-preprocessor": .runPreprocessor,
    ]
    
    for flag in flags.flatMap({map[$0]}) {
        compileOptions.insert(flag)
    }
    let explicitName = flags
        .find { flag in flag.hasPrefix("-o") }
        .map { name in name.stringByReplacingOccurrencesOfString("-o", withString: "") }
    
    if flags.contains("-h") || flags.contains("-help") {
        print(
            "\nUSAGE:  vist [options] <input.vist>\n\nOPTIONS:\n" +
                "  -help -h\t\t- Print help\n" +
                "  -verbose -v\t\t- Print all stages of the compile\n" +
                "  -dump-ast\t\t- Dump syntax tree\n" +
                "  -emit-llvm\t\t- Print the LLVM IR file\n" +
                "  -emit-vir\t\t- Print the VIR file\n" +
                "  -emit-asm\t\t- print the assembly code\n" +
                "  -run -r\t\t- Run the program after compilation\n" +
                "  -oNAME -r\t\t- Define the output name to be NAME\n" +
                "  -build-stdlib\t\t- Build the standard library too\n" +
                "  -parse-stdlib\t\t- Compile the module as if it were the stdlib. This exposes Builtin functions and links the runtime directly\n" +
                "  -build-runtime\t- Build the runtime\n" +
                "  -debug-runtime\t- The runtime logs reference counting operations\n" +
                "  -preserve\t\t- Keep intermediate IR and ASM files")
    }
    else {
        #if DEBUG
            let s = CFAbsoluteTimeGetCurrent()
        #endif
        
        if flags.contains("-run-preprocessor") {
            
        }
        
        if flags.contains("-build-stdlib") {
            var o: CompileOptions = [.buildStdLib, .Ohigh]
            if o.contains(.verbose) { o.insert(.verbose) }
            try compileDocuments(["Int.vist", "Operators.vist", "Other.vist", "String.vist" ],
                                 inDirectory: "\(SOURCE_ROOT)/Vist/Stdlib",
                                 explicitName: "stdlib",
                                 options: o)
        }
        
        if !files.isEmpty {
            try compileDocuments(files,
                                 inDirectory: dir,
                                 explicitName: explicitName,
                                 out: out,
                                 options: compileOptions)
        }
        else if compileOptions.contains(.buildRuntime) {
            buildRuntime(debugRuntime: compileOptions.contains(.debugRuntime))
        }
        
        #if DEBUG
            let f = NSNumberFormatter() 
            f.maximumFractionDigits = 2
            f.minimumFractionDigits = 2
            print("\nCompile took: \(f.stringFromNumber(CFAbsoluteTimeGetCurrent() - s)!)s")
        #endif
    }
    
}

