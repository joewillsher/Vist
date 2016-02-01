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
    
    // MARK: Test cases
    
    func testControlFlow() {
        do {
            try compileWithOptions(["-O", "Control.vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: "Control.vist"))
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
    func testForInLoops() {
        do {
            try compileWithOptions(["Loops.vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: "Loops.vist"))
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
    func testStackOf2Type() {
        do {
            try compileWithOptions(["-O", "StackOf2Type.vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: "StackOf2Type.vist"))
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
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

