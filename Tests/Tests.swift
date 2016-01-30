//
//  Tests.swift
//  Tests
//
//  Created by Josef Willsher on 30/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import XCTest
import Foundation

private let testDir = "\(SOURCE_ROOT)/Tests/TestCases"
private let stdlibDir = "\(SOURCE_ROOT)/Vist/StdLib"


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
            XCTAssertEqual(pipe?.string, "100\n")
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
    func testForInLoops() {
        do {
            try compileWithOptions(["-O", "Loops.vist"], inDirectory: testDir, out: pipe)
            print(pipe?.string)
            XCTAssertEqual(pipe?.string, "1\n2\n3\n")
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }
    
    func testStackOf2Type() {
        do {
            try compileWithOptions(["-O", "StackOf2Type.vist"], inDirectory: testDir, out: pipe)
            print(pipe?.string)
            XCTAssertEqual(pipe?.string, "22\n3\ntrue\n")
        }
        catch {
            print(error)
            XCTFail("Compilation failed")
        }
    }

    func testStdLibCompile() {
//        self.measureBlock {
            do {
                try compileWithOptions(["-O", "-build-stdlib"], inDirectory: stdlibDir, out: nil)
            }
            catch {
                print(error)
                XCTFail("Compilation failed")
            }
//        }
    }
    
    
}

