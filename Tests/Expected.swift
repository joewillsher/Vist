//
//  Expected.swift
//  Vist
//
//  Created by Josef Willsher on 31/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSString


private func getCommentsFromFile(atPath path: String) throws -> [String] {
    let contents = try String(contentsOfFile: path)
    let toks = try contents.getTokens()
    
    return toks.flatMap { tok -> String? in if case .comment(let c) = tok.0 { return c } else { return nil } }
}

func expectedTestCaseOutput(path: String) -> String? {
    guard let contents = try? String(contentsOfFile: path) else { return nil }
    guard let toks = try? contents.getTokens() else { return nil }
    
    let comments = toks
        .flatMap { tok -> String? in if case .comment(let c) = tok.0 { return c } else { return nil } }
        .filter { comment in comment.hasPrefix(" OUT: ") }
        .flatMap { comment in comment
            .replacingOccurrences(of: " OUT: ", with: "")
            .replacingOccurrences(of: " ", with: "\n") }
    
    return comments.joined(separator: "\n") + "\n"
}

func expectedTestCaseErrors(path: String) throws -> String {
    let comments = try getCommentsFromFile(atPath: path)
        .filter { comment in comment.hasPrefix(" ERROR: ") }
        .flatMap { comment in comment
            .replacingOccurrences(of: " ERROR: ", with: "") }
    
    return comments.joined(separator: "\n")
}

func expectedTestCaseVIR(path: String) throws -> [String] {
    return try expectedTestCaseBlock(name: "VIR", path: path)
}
func expectedTestCaseAST(path: String) throws -> [String] {
    return try expectedTestCaseBlock(name: "AST", path: path)
}
func expectedTestCaseLLVM(path: String) throws -> [String] {
    return try expectedTestCaseBlock(name: "LLVM", path: path)
}
func expectedTestCaseOutput(prefix: String, path: String) throws -> [String] {
    return try expectedTestCaseBlock(name: prefix, path: path)
}



/// - parameter name: The name of the start of the line: AST/VIR/LLVM
func expectedTestCaseBlock(name: String, path: String) throws -> [String] {
    let comments = try getCommentsFromFile(atPath: path)
    
    var virBlocks: [String] = [], i = comments.startIndex
    
    // parse comments like:
    
    // VIR-CHECK:
    // VIR: func @main : &thin () -> #Builtin.Void {
    // VIR: $entry:
    // VIR:   %0 = int_literal 222  	// user: %1
    // VIR:   %1 = struct %Int, (%0: #Builtin.Int64)  	// user: %2
    // VIR:   %2 = call @Foo_tI (%1: #Int)  	// user: %f
    // VIR:   variable_decl %f = %2: #Foo  	// users: %3, %4
    // VIR:   %3 = call @Baz_tFoo (%f: #Foo)  	// user: %b
    // VIR:   variable_decl %b = %3: #Baz
    // VIR:   %4 = struct_extract %f: #Foo, !x  	// user: %u
    // VIR:   variable_decl %u = %4: #Int  	// user: %5
    // VIR:   %5 = call @print_tI (%u: #Int)
    // VIR:   return ()
    // VIR: }
    
    while i < comments.endIndex {
        
        let c = comments[i]
        i += 1
        guard c.hasPrefix(" \(name)-CHECK:") else { continue }
        
        var blockLines: [String] = []
        
        while i < comments.endIndex, comments[i].hasPrefix(" \(name): ") {
            blockLines.append(comments[i].replacingOccurrences(of: " \(name): ", with: ""))
            i += 1
        }
        
        virBlocks.append(blockLines.joined(separator: "\n"))
    }
    
    return virBlocks
}




extension ErrorProtocol where Self : VistError {
    
    /// Remove coments around error message, leave just the errors 
    /// to compare with the test case comments
    var parsedError: String {
        return "\(self)"
            .replacingOccurrences(of: "\n -", with: "\n")
            .components(separatedBy: "\n").filter { !$0.hasSuffix(" errors found:") }
            .joined(separator: "\n")
    }
    
}

func getCommentsForFile(path: String) throws -> [String] {
    let contents = try String(contentsOfFile: path)
    let toks = try contents.getTokens()
    
    return toks.flatMap { tok in
        if case .comment(let c) = tok.0 { return c } else { return nil }
    }
}

func getRunSettings(path: String) throws -> [String] {
    guard let comment = try getCommentsFromFile(atPath: path).first, comment.hasPrefix(" RUN: ") else { return [] }
    return comment
        .replacingOccurrences(of: " RUN: ", with: "")
        .components(separatedBy: " ")
}
func getTestPrefix(path: String) throws -> String? {
    return try getCommentsFromFile(atPath: path)
        .filter { comment in  comment.hasPrefix(" CHECK: ") }
        .flatMap { $0.components(separatedBy: " ").first }
        .first
}


struct OutputError : ErrorProtocol { let reason: String }

/// Check that the multi line output matches
func multiLineOutput(_ output: String, matches expected: [String]) throws -> Bool {
    let outputLines = output.components(separatedBy: "\n")
    
    // for each block of expected IR
    nextExpectedBlock: for expectedBlock in expected {
        let expectedLines = expectedBlock.components(separatedBy: "\n")
        
        // loop over the output and look for its start
        nextLine: for (i, el) in outputLines.enumerated() where expectedLines.first == el {
            
            let searchRange = outputLines[outputLines.startIndex.advanced(by: i)..<outputLines.endIndex]
            for (expected, output) in zip(expectedLines, searchRange) where expected != output {
                throw OutputError(reason: "Line \(output) is not equal to \(expected)")
            }
            
            break nextExpectedBlock
        }
        
        // diagnose a faliaure to find it
        throw OutputError(reason: "Did not find matching IR: \(expectedLines.first)")
    }
    
    return true
}



