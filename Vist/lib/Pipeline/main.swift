//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//
import class Foundation.Process

do {
    let flags = Array(ProcessInfo().arguments.dropFirst())
    try compile(withFlags: flags, inDirectory: Process().currentDirectoryPath, out: nil)
}
catch {
    print(error, terminator: "\n\n")
}
