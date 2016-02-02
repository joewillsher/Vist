//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//
import Foundation

do {
    let flags = Array(Process.arguments.dropFirst())
    try compileWithOptions(flags, inDirectory: NSTask().currentDirectoryPath)
}
catch let error where unwrap(ParseError.NoTypeName, ParseError.NoIdentifier)(error) {
    // handle specific errors
    print(error)
}
catch {
    print(error)
}


