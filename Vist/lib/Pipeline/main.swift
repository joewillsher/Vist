//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//
import class Foundation.NSTask

do {
    let flags = Array(Process.arguments.dropFirst())
    try compile(withFlags: flags, inDirectory: NSTask().currentDirectoryPath)
}
catch let error as VistError {
    print(error, terminator: "\n\n")
}
catch {
    print(error, terminator: "\n\n")
}
