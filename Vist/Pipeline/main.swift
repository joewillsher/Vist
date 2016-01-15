//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//
import Foundation

do {
    let ar = Process.arguments
    var a = Process.arguments.dropFirst()
    
    let c = a.count
    var i = c
    while let head = a.last where head.containsString("vist") {
        a = a.dropLast()
        i -= 1
    }
    let r = i...(c-1)
    let files = Array(ar[(i+1)...c])
    
    let verbose = a.contains("-verbose") || a.contains("-v")
    let ast = a.contains("-dump-ast")
    let ir = a.contains("-emit-ir")
    let asm = a.contains("-emit-asm")
    let b = a.contains("-build-only") || a.contains("-b")
    let profile = a.contains("-profile") || a.contains("-p")
    let o = a.contains("-O")
    let lib = a.contains("-lib") // undocumented
    let buildStdLib = a.contains("-build-stdlib")
    let preserveIntermediate = a.contains("-preserve")
    
    if a.contains("-build-runtime") {
        buildRuntime()
    }
    
    if a.contains("-h") || a.contains("-help") {
        
        print(
            "USAGE:  vist [options] <input.vist>\n\nOPTIONS:\n" +
            "  -help -h\t\t- Print help\n" +
            "  -verbose -v\t\t- Print all stages of the compile\n" +
            "  -profile -p\t\t- Record time of program execution\n" +
            "  -dump-ast\t\t- Dump syntax tree\n" +
            "  -emit-ir\t\t- Only generate LLVM IR file\n" +
            "  -emit-asm\t\t- Only generate assembly code\n" +
            "  -build-only -b\t- Do not run the program\n" +
            "  -build-stdlib\t\t- Build the standard library too\n" +
            "  -build-runtime\t\t- Build the runtime too\n" +
            "  -preserve\t\t- Keep intermediate LLVM IR and ASM files")
    }
    else {    
        #if DEBUG
            let s = CFAbsoluteTimeGetCurrent()
        #endif
        
        if buildStdLib {
            try compileDocuments(["stdlib.vist"],
                verbose: verbose,
                dumpAST: ast,
                irOnly: ir,
                asmOnly: asm,
                buildOnly: true,
                profile: false,
                optim: true,
                preserve: true,
                generateLibrary: true,
                isStdLib: true
            )
        }
        
        try compileDocuments(files,
            verbose: verbose,
            dumpAST: ast,
            irOnly: ir,
            asmOnly: asm,
            buildOnly: b,
            profile: profile,
            optim: o,
            preserve: preserveIntermediate,
            generateLibrary: lib,
            isStdLib: false
        )
        
        #if DEBUG
            print("Compile took \(CFAbsoluteTimeGetCurrent() - s)s")
        #endif
    }
    
    
} catch {
    print(error)
}


