//
//  Error.swift
//  Vist
//
//  Created by Josef Willsher on 01/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// A vist error -- implements ErrorType and CustomStringConvertible
typealias VistError = protocol<ErrorType, CustomStringConvertible>

/// Error function -- always rethrows the error passed to it
///
/// In debug builds it prints the file & line in the compiler that threw the error.
///
/// In release builds it crashes if the error is an internal logic failure
///
/// If a source location is defined, the result is wrapped in a `PositionedError` struct
func error(err: VistError, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    
    var error = err
    
    #if DEBUG
        error = DebugError(error: error, userVisible: userVisible, file: file, line: line, function: function)
    #else
        if !userVisible {
            fatalError("Compiler assertion failed \(err)", file: file, line: line)
        }
    #endif
    
    if let loc = loc { // if a source is provided, put the error in a PositionedError
        return PositionedError(error: error, range: loc)
    } else {
        return error
    }
}

func semaError(err: SemaError, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    return error(err, loc: loc, userVisible: userVisible, file: file, line: line, function: function)
}
func parseError(err: ParseError, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    return error(err, loc: loc, userVisible: userVisible, file: file, line: line, function: function)
}
func irGenError(err: IRError, loc: SourceRange? = nil, userVisible: Bool = true, file: StaticString = #file, line: UInt = #line, function: String = #function) -> VistError {
    return error(err, loc: loc, userVisible: userVisible, file: file, line: line, function: function)
}



/// Any error wrapper type, allows equality operator to be defined
/// on these functions by looking at their stored error
protocol ErrorWrapper: VistError {
    var error: VistError { get }
}

/// An error object, which describes the error and contains the source location information
struct PositionedError: ErrorWrapper {
    let error: VistError
    let range: SourceRange?
    
    var description: String {
        return "\(range?.description ?? ""):\t\(error)"
    }
}

struct DebugError: ErrorWrapper {
    let error: VistError
    let userVisible: Bool
    let file: StaticString, line: UInt, function: String
    
    var description: String {
        return "\(userVisible ? "Vist error" : "Internal logic error"): \((error)).\n\t~Error in '\(function)' on line \(line) of \(file)~"
    }
}


/// A collection of errors, conforming to ErrorType so it can be thrown
struct ErrorCollection: VistError {
    let errors: [VistError]
    
    // flattens any child ErrorCollections
    var description: String {
        return "\(errors.count) errors found:\n"
            + errors.map { err in
            if case let coll as ErrorCollection = err {
                return coll.errors.map { " -\($0)" }.joinWithSeparator("\n")
            }
            else { return " -\(err)" }
            }.joinWithSeparator("\n")
    }
}

extension CollectionType where
    Generator.Element == VistError,
    Index == Int
{
    func throwIfErrors() throws {
        if count == 1 { throw self[0] }
        if !isEmpty { throw ErrorCollection(errors: Array(self)) }
    }
}


