//
//  Error.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// A vist error -- implements ErrorType and CustomStringConvertible
typealias VistError = Error & CustomStringConvertible

/// Error function -- always rethrows the error passed to it
///
/// In debug builds it prints the file & line in the compiler that threw the error.
///
/// In release builds it crashes if the error is an internal logic failure
///
/// If a source location is defined, the result is wrapped in a `PositionedError` struct
func error(_ err: VistError, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    
    var error: VistError
    #if TEST
        error = err
    #elseif DEBUG
        error = DebugError(error: err, userVisible: userVisible, file: file, line: line, function: function)
    #else
        if !userVisible {
            fatalError("Compiler assertion failed \(err)", file: file, line: line)
        }
        else {
            error = err
        }
    #endif
    
    if let loc = loc { // if a source is provided, put the error in a PositionedError
        return PositionedError(error: error, range: loc)
    } else {
        return error
    }
}

func semaError(_ err: SemaError, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    return error(err, loc: loc, userVisible: userVisible, file: file, line: line, function: function)
}
func parseError(_ err: ParseError, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    return error(err, loc: loc, userVisible: userVisible, file: file, line: line, function: function)
}
/// IRGen error default `userVisible` is false
func irGenError(_ err: IRError, loc: SourceRange? = nil, userVisible: Bool = false, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    return error(err, loc: loc, userVisible: userVisible, file: file, line: line, function: function)
}



/// Any error wrapper type, allows equality operator to be defined
/// on these functions by looking at their stored error
protocol ErrorWrapper : VistError {
    var error: VistError { get }
}

/// An error object, which describes the error and contains the source location information
struct PositionedError : ErrorWrapper {
    let error: VistError
    let range: SourceRange?
    
    var description: String {
        return "\(range?.description ?? ""):\t\(error)"
    }
}

struct DebugError : ErrorWrapper {
    let error: VistError
    let userVisible: Bool
    let file: StaticString, line: UInt, function: String
    
    var description: String {
        return "\(userVisible ? "Vist error" : "Internal logic error"): \((error))\n\t~Error in '\(function)' on line \(line) of \(file)~"
    }
}


/// A collection of errors, conforming to ErrorType so it can be thrown
struct ErrorCollection : VistError {
    let errors: [VistError]
    
    // flattens any child ErrorCollections
    var description: String {
        #if TEST
            let prefix = "\(errors.count) errors found:\n", linePrefix = " -"
        #else
            let prefix = "", linePrefix = ""
        #endif
        
        return prefix + errors.map { err in
            if case let coll as ErrorCollection = err {
                return coll.errors.map { "\(linePrefix)\($0)" }.joined(separator: "\n")
            }
            else { return "\(linePrefix)\(err)" }
            }.joined(separator: "\n")
    }
}

extension Collection where
    Iterator.Element == VistError,
    Index == Int
{
    func throwIfErrors() throws {
        if count == 1 { throw self[0] }
        if !isEmpty { throw ErrorCollection(errors: Array(self)) }
    }
}



