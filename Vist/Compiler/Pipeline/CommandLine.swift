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

public func compileWithOptions(flags: [String], inDirectory dir: String, out: NSPipe? = nil) throws {
    
    guard !flags.isEmpty else { fatalError("No input files") }
    
    let files = flags.filter { $0.containsString(".vist") }
    var compileOptions = CompileOptions(rawValue: 0)
    
    let map: [String: CompileOptions] = [
        "-verbose": .verbose,
        "-preserve": .preserveTempFiles,
        "-dump-ast": .dumpAST,
        "-emit-ir": .dumpLLVMIR,
        "-emit-vhir": .dumpVHIR,
        "-run": .buildAndRun,
        "-r": .buildAndRun,
        "-O0": .O0,
        "-O": .O,
        "-Ohigh": .Ohigh,
        "-disable-stdlib-inline": .disableStdLibInlinePass,
        "-lib": .produceLib,
        "-parse-stdlib": .doNotLinkStdLib,
        "-build-runtime": .buildRuntime,
    ]
    
    for flag in flags.flatMap({map[$0]}) {
        compileOptions.insert(flag)
    }
        
    if flags.contains("-h") || flags.contains("-help") {
        print(
            "USAGE:  vist [options] <input.vist>\n\nOPTIONS:\n" +
                "  -help -h\t\t- Print help\n" +
                "  -verbose -v\t\t- Print all stages of the compile\n" +
                "  -profile -p\t\t- Record time of program execution\n" +
                "  -dump-ast\t\t- Dump syntax tree\n" +
                "  -emit-ir\t\t- Print the LLVM IR file\n" +
                "  -emit-vhir\t\t- Print the VHIR file\n" +
                "  -emit-asm\t\t- print the assembly code\n" +
                "  -run -r\t\t- Run the program after compilation\n" +
                "  -build-stdlib\t\t- Build the standard library too\n" +
                "  -parse-stdlib\t\t- Compile the module as if it were the stdlib. This exposes Builtin functions and links the runtime directly\n" +
                "  -build-runtime\t- Build the runtime too\n" +
                "  -preserve\t\t- Keep intermediate IR and ASM files")
    }
    else if !files.isEmpty {
        #if DEBUG
            let s = CFAbsoluteTimeGetCurrent()
        #endif
        
        if flags.contains("-build-stdlib") {
            try compileDocuments(["stdlib.vist"],
                                 inDirectory: "\(SOURCE_ROOT)/Vist/Stdlib",
                                 options: .buildStdLib)
        }
        if !files.isEmpty {
            try compileDocuments(files,
                                 inDirectory: dir,
                                 out: out,
                                 options: compileOptions)
        }
        
        #if DEBUG
            let f = NSNumberFormatter()
            f.maximumFractionDigits = 2
            f.minimumFractionDigits = 2
            print("\nCompile took: \(f.stringFromNumber(CFAbsoluteTimeGetCurrent() - s)!)s")
        #endif
    }
    
}

