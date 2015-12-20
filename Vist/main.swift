//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


do {
    
    let a = Process.arguments.dropFirst()
    let doc = a.last!
    let args = a.dropLast()
    let verbose = args.contains("-verbose") || args.contains("-v")
    let ast = args.contains("-dump-ast")
    let ir = args.contains("-emit-ir")
    let asm = args.contains("-emit-asm")
    let b = args.contains("-build-only") || args.contains("-b")
    let profile = args.contains("-profile") || args.contains("-p")
    
    if a.contains("-h") || a.contains("-help") {
        
        print("USAGE:  vist [options] <input.vist>\n\nOPTIONS:\n  -help -h\t\t- Print help\n  -verbose -v\t\t- Print all stages of the compile\n  -profile -p\t\t- Record time of program execution\n  -dump-ast\t\t- Dump syntax tree\n  -emit-ir\t\t- Only generate LLVM IR file\n  -emit-asm\t\t- Only generate assembly code\n  -build-only -b\t- Do not run the program")
        
    } else {
        
        try compileDocument(doc, verbose: verbose, dumpAST: ast, irOnly: ir, asmOnly: asm, buildOnly: b, profile: profile)
        
        print("\n")
    }
    
    
} catch {
    print(error)
}

