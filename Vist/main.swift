//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


do {
    
    let args = Process.arguments.dropFirst()
    let doc = args.first!
    let verbose = args.dropFirst().contains("-v")
    
    try compileDocument(doc, verbose: verbose)
    
    // http://llvm.org/releases/2.6/docs/tutorial/JITTutorial1.html
    
    // do implemetation of this here to get IR Gen going
    print("\n")
    
    
} catch {
    print(error)
}

