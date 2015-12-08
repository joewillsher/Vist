//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//




do {
    
    try compileDocument(Process.arguments.dropFirst().last!)
    
} catch {
    print(error)
}

