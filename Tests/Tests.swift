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

// tests can define comments which define the expected output of the program
// `// test: 1 2` will add "1\n2\n" to the expected result of the program

class Tests : XCTestCase {
    
    /// pipe used as the stdout of the test cases
    var pipe: NSPipe? = nil
    
    override func setUp() {
        super.setUp()
        pipe = NSPipe()
    }
    
    // MARK: Test Cases
    
    /// tests `if` statements & variables
    ///
    func testControlFlow() {
        let file = "Control.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file))
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
    /// tests `for in` loops and `while` loops
    /// tests mutation
    ///
    func testLoops() {
        let file = "Loops.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file))
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
    /// tests type sytem
    /// tests default initialisers & methods
    ///
    func testStackOf2Type() {
        let file = "StackOf2Type.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file))
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }   
    
//    func testArray() {
//        let file = "Array.vist"
//        do {
//            try compileWithOptions([file], inDirectory: testDir, out: pipe)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file))
//        }
//        catch {
//            print(error)
//            XCTFail("Compilation failed")
//        }
//    }

    /// Runs a compilation of the standard library
    ///
    func testStdLibCompile() {
        do {
            try compileWithOptions(["-O", "-build-stdlib"], inDirectory: stdlibDir, out: nil)
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
    
}

