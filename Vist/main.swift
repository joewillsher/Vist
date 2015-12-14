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
    let ir = args.contains("-emit-ir")
    let asm = args.contains("-emit-asm")
    let b = args.contains("-build-only") || args.contains("-b")
    
    if a.contains("-h") || a.contains("-help") {
        
        print("USAGE:  vist [options] <input.vist>\n\nOPTIONS:\n  -help -h\t\t- Print help\n  -verbose -v\t\t- Print all stages of the compile\n  -emit-ir\t\t- Only generate LLVM IR file\n  -emit-asm\t\t- Only generate assembly code\n  -build-only -b\t- Do not run the program")
        
    } else {
        
        try compileDocument(doc, verbose: verbose, irOnly: ir, asmOnly: asm, buildOnly: b)
        print("\n")
    }
    
    
} catch {
    print(error)
}

