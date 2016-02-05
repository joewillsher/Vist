//
//  Tests.swift
//  Tests
//
//  Created by Josef Willsher on 30/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import XCTest
import Foundation

let testDir = "\(SOURCE_ROOT)/Tests/TestCases"
let stdlibDir = "\(SOURCE_ROOT)/Vist/StdLib"
let runtimeDir = "\(SOURCE_ROOT)/Vist/Runtime"

// tests can define comments which define the expected output of the program
// `// test: 1 2` will add "1\n2\n" to the expected result of the program

/// Test cases for code snippets
///
final class Tests : XCTestCase {
    
    /// pipe used as the stdout of the test cases
    var pipe: NSPipe? = nil
    
    override func setUp() {
        super.setUp()
        pipe = NSPipe()
    }
}

/// Testing building the stdlib & runtime
///
final class CoreTests : XCTestCase {
}


// MARK: Test Cases

extension Tests {
    
    /// tests `if` statements & variables
    ///
    func testControlFlow() {
        let file = "Control.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Invalid output")
        }
        catch {
            XCTFail("Compilation failed  with error:\n\(error)\n\n")
        }
    }
    
    /// tests `for in` loops and `while` loops
    ///
    /// tests mutation
    ///
    func testLoops() {
        let file = "Loops.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Invalid output")
        }
        catch {
            XCTFail("Compilation failed  with error:\n\(error)\n\n")
        }
    }
    
    /// tests type sytem
    ///
    /// tests default initialisers & methods
    ///
    func testStackOf2Type() {
        let file = "StackOf2Type.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Invalid output")
        }
        catch {
            XCTFail("Compilation failed  with error:\n\(error)\n\n")
        }
    }   
    
    /// tests integer operations
    ///
    func testIntegerOps() {
        let file = "IntegerOps.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Invalid output")
            // TODO: locate part of file not correct
            // TODO: \ to escape
        }
        catch {
            XCTFail("Compilation failed  with error:\n\(error)\n\n")
        }
    }

}


extension CoreTests {
    
    /// Runs a compilation of the standard library
    ///
    func testStdLibCompile() {
        do {
            try compileWithOptions(["-build-stdlib"], inDirectory: stdlibDir)
            XCTAssertTrue(NSFileManager.defaultManager().fileExistsAtPath("\(runtimeDir)/runtime.bc"))
        }
        catch {
            XCTFail("Stdlib build failed with error:\n\(error)")
        }
    }
    
    func testRuntimeBuild() {
        do {
            try compileWithOptions(["-build-runtime"], inDirectory: runtimeDir)
            XCTAssertTrue(NSFileManager.defaultManager().fileExistsAtPath("\(stdlibDir)/stdlib.bc")) // file used by optimiser
            XCTAssertTrue(NSFileManager.defaultManager().fileExistsAtPath("\(stdlibDir)/stdlib.o")) // file used by linker
        }
        catch {
            XCTFail("Runtime build failed with error:\n\(error)")
        }
    }
    
    
}

