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

/// Equality operator for error types
///
/// Extends the default one, and allows matching of boxed errors against non boxed ones
///
@warn_unused_result
func == (lhs: ErrorType, rhs: ErrorType) -> Bool {
    switch (lhs, rhs) {
    case (let l as PositionedError, let r as PositionedError):
        return l.error == r.error
        
    case (let l as PositionedError, _):
        return l.error == rhs
        
    case (_, let r as PositionedError):
        return r.error == lhs
        
    default:
        return lhs._code == rhs._code
    }
}


/// Allows matching of pattern against a boxed pattern
///
/// `catch let error where unwrap(ParseError.NoTypeName, ParseError.NoIdentifier)(error) {...`
///
/// - parameter errors: A series of errors to match against
///
/// - returns: A function which takes an error instance and matches against the applied errors
func unwrap(errors: ErrorType...) -> ErrorType -> Bool {
    return { value in
        return errors.contains { $0 == value }
    }
}



