//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


let SRCROOT = "/Users/JoeWillsher/Developer/Vist"

do {
    print("\n")
    try compileDocument(Process.arguments.dropFirst().last!)
    print("\n")
    
    // http://llvm.org/releases/2.6/docs/tutorial/JITTutorial1.html
    
    // do implemetation of this here to get IR Gen going
    
} catch {
    print(error)
}

