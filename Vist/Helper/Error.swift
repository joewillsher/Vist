//
//  Error.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// Error function -- always rethrows the error passed to it
///
/// In debug builds it prints the file & line in the compiler that threw the error.
///
/// In release builds it crashes if the error is an internal logic failure
///
func error<Error : ErrorType>(err: Error, userVisible: Bool = true, file: StaticString = __FILE__, line: UInt = __LINE__) -> Error {
    
    #if DEBUG
        print("Vist error in ‘\(file)’, line \(line)")
        return err
    #else
        if userVisible {
            return err
        }
        else {
            fatalError("Compiler assertion failed \(err)", file: file, line: line)
        }
    #endif
    
}
