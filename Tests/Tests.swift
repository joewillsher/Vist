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
final class OutputTests : XCTestCase {
    
    /// pipe used as the stdout of the test cases
    var pipe: NSPipe? = nil
    
    override func setUp() {
        super.setUp()
        pipe = NSPipe()
    }
}

/// Tests regarding runtime performance
///
final class RuntimePerformanceTests : XCTestCase {
    
}

/// Testing building the stdlib & runtime
///
final class CoreTests : XCTestCase {
    
}

/// Tests the error catching system
///
final class ErrorTests : XCTestCase {
    
}


// MARK: Test Cases

extension OutputTests {
    
    /// Control.vist
    ///
    /// tests `if` statements, variables
    ///
    func testControlFlow() {
        let file = "Control.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Loops.vist
    ///
    /// tests `for in` loops, `while` loops, mutation
    ///
    func testLoops() {
        let file = "Loops.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Type.vist
    ///
    /// tests type sytem, default initialisers, & methods
    ///
    func testType() {
        let file = "Type.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }   
    
    /// IntegerOps.vist
    ///
    /// tests integer operations
    ///
    func testIntegerOps() {
        let file = "IntegerOps.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Function.vist
    ///
    /// tests function decls and calling, tuples & type param labels
    ///
    func testFunctions() {
        let file = "Function.vist"
        do {
            try compileWithOptions(["-O", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(file: file), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
}


extension RuntimePerformanceTests {
    
    /// LoopPerf.vist
    ///
    /// Builds file and analyses performance of resulting binary
    ///
    func testLoop() {
        
        let fileName = "LoopPerf"
        do {
            try compileWithOptions(["-O", "-build-only", "\(fileName).vist"], inDirectory: testDir)
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
        measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
            
            let runTask = NSTask()
            runTask.currentDirectoryPath = testDir
            runTask.launchPath = "\(testDir)/\(fileName)"
            runTask.standardOutput = NSFileHandle.fileHandleWithNullDevice()
            
            self.startMeasuring()
            runTask.launch()
            runTask.waitUntilExit()
            self.stopMeasuring()
        }
    }
    
    /// FunctionPerf.vist
    ///
    /// Test non memoised fibbonaci
    ///
    func testFunction() {
        
        let fileName = "FunctionPerf"
        do {
            try compileWithOptions(["-O", "-build-only", "\(fileName).vist"], inDirectory: testDir)
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
        measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
            
            let runTask = NSTask()
            runTask.currentDirectoryPath = testDir
            runTask.launchPath = "\(testDir)/\(fileName)"
            runTask.standardOutput = NSFileHandle.fileHandleWithNullDevice()
            
            self.startMeasuring()
            runTask.launch()
            runTask.waitUntilExit()
            self.stopMeasuring()
        }
    }
    
}




extension CoreTests {
    
    /// Runs a compilation of the standard library
    ///
    func testStdLibCompile() {
        do {
            try compileWithOptions(["-build-stdlib"], inDirectory: stdlibDir)
            XCTAssertTrue(NSFileManager.defaultManager().fileExistsAtPath("\(stdlibDir)/stdlib.bc")) // file used by optimiser
            XCTAssertTrue(NSFileManager.defaultManager().fileExistsAtPath("\(stdlibDir)/stdlib.o")) // file used by linker
        }
        catch {
            XCTFail("Stdlib build failed with error:\n\(error)\n\n")
        }
    }
    
    /// Builds the runtime
    ///
    func testRuntimeBuild() {
        do {
            try compileWithOptions(["-build-runtime"], inDirectory: runtimeDir)
            XCTAssertTrue(NSFileManager.defaultManager().fileExistsAtPath("\(runtimeDir)/runtime.bc"))
        }
        catch {
            XCTFail("Runtime build failed with error:\n\(error)\n\n")
        }
    }
    
    
}

