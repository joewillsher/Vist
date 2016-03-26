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
    
    let verbose = flags.contains("-verbose") || flags.contains("-v")
    let ast = flags.contains("-dump-ast")
    let ir = flags.contains("-emit-ir")
    let asm = flags.contains("-emit-asm")
    let b = flags.contains("-build-only") || flags.contains("-b")
    let profile = flags.contains("-profile") || flags.contains("-p")
    let o = flags.contains("-O")
    let lib = flags.contains("-lib") // undocumented
    let buildStdLib = flags.contains("-build-stdlib")
    let parseStdLib = flags.contains("-parse-stdlib")
    let oldIRGen = flags.contains("-irgen-old")
    let preserveIntermediate = flags.contains("-preserve")
    
    if flags.contains("-build-runtime") {
        buildRuntime()
    }
    
    if flags.contains("-h") || flags.contains("-help") {
        
        print(
            "USAGE:  vist [options] <input.vist>\n\nOPTIONS:\n" +
                "  -help -h\t\t- Print help\n" +
                "  -verbose -v\t\t- Print all stages of the compile\n" +
                "  -profile -p\t\t- Record time of program execution\n" +
                "  -old-irgen\t\t- Use the old IRGen pass instead of VHIR\n" +
                "  -dump-ast\t\t- Dump syntax tree\n" +
                "  -emit-ir\t\t- Only generate LLVM IR file\n" +
                "  -emit-asm\t\t- Only generate assembly code\n" +
                "  -build-only -b\t- Do not run the program\n" +
                "  -build-stdlib\t\t- Build the standard library too\n" +
                "  -parse-stdlib\t\t- Compile the module as if it were the stdlib. This exposes Builtin functions\n" +
                "  -build-runtime\t\t- Build the runtime too\n" +
                "  -preserve\t\t- Keep intermediate LLVM IR and ASM files")
    }
    else if !files.isEmpty || buildStdLib {
        #if DEBUG
            let s = CFAbsoluteTimeGetCurrent()
        #endif
        
        if buildStdLib {
            try compileDocuments(["stdlib.vist"],
                                 inDirectory: "",
                                 out: out,
                                 verbose: verbose,
                                 dumpAST: ast,
                                 irOnly: ir,
                                 asmOnly: asm,
                                 buildOnly: true,
                                 profile: false,
                                 optim: true,
                                 preserve: true,
                                 generateLibrary: true,
                                 isStdLib: true,
                                 parseStdLib: true,
                                 oldIRGen: true)
        }
        if !files.isEmpty {
            try compileDocuments(files,
                                 inDirectory: dir,
                                 out: out,
                                 verbose: verbose,
                                 dumpAST: ast,
                                 irOnly: ir,
                                 asmOnly: asm,
                                 buildOnly: b,
                                 profile: profile,
                                 optim: o,
                                 preserve: preserveIntermediate,
                                 generateLibrary: lib,
                                 isStdLib: false,
                                 parseStdLib: parseStdLib,
                                 oldIRGen: oldIRGen)
        }
        
        #if DEBUG
            let f = NSNumberFormatter()
            f.maximumFractionDigits = 2
            f.minimumFractionDigits = 2
            print("Compile took: \(f.stringFromNumber(CFAbsoluteTimeGetCurrent() - s)!)s")
        #endif
    }
    
}
