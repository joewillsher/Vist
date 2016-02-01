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
/// If a source location is defined, the result is wrapped in a `PositionedError` struct
///
func error(err: ErrorType, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = __FILE__, line: UInt = __LINE__) -> ErrorType {
    
    #if DEBUG
        print("Vist error in line \(line) of \(file)")
    #else
        if !userVisible {
            fatalError("Compiler assertion failed \(err)", file: file, line: line)
        }
    #endif

    if let loc = loc { // if a source is provided, put the error in a PositionedError
        return PositionedError(error: err, range: loc)
    } else {
        return err
    }
}

/// An error object, which describes the error and contains the source location information
///
struct PositionedError : ErrorType, CustomStringConvertible {
    let error: ErrorType
    let range: SourceRange?
    
    var description: String {
        if let printable = error as? CustomStringConvertible {
            return "\(range?.description ?? ""): \(printable.description)"
        }
        else {
            return "\(range?.description ?? ""): \(self._domain)"
        }
    }
    
}

