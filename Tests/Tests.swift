//
//  Tests.swift
//  Tests
//
//  Created by Josef Willsher on 30/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import XCTest
import Foundation

// tests can define comments which define the expected output of the program
// `// OUT: 1 2` will add "1\n2\n" to the expected result of the program

protocol VistTest : class {
    var testDir: String { get }
    var stdlibDir: String { get }
    var runtimeDir: String { get }
    var virDir: String { get }
}

extension VistTest {
    var testDir: String { return "\(SOURCE_ROOT)/Tests/TestCases" }
    var stdlibDir: String { return "\(SOURCE_ROOT)/Vist/stdLib" }
    var runtimeDir: String { return "\(SOURCE_ROOT)/Vist/stdlib/runtime" }
    var virDir: String { return "\(SOURCE_ROOT)/Vist/VIR" }
    
    var libDir: String { return "/usr/local/lib" }
    var binDir: String { return "/usr/local/bin" }
}

/// Test the compilation and output of code samples
final class OutputTests : XCTestCase, VistTest {
    
    /// pipe used as the stdout of the test cases
    var pipe: NSPipe? = nil
    
    override func setUp() {
        super.setUp()
        pipe = NSPipe()
    }
}

final class RefCountingTests : XCTestCase, VistTest {
    
}

/// Tests runtime performance
final class RuntimePerformanceTests : XCTestCase, VistTest {
    
}

/// Testing building the stdlib & runtime
final class CoreTests : XCTestCase, VistTest {
    
}

/// Tests the error handling & type checking system
final class ErrorTests : XCTestCase, VistTest {
    
}




// MARK: Test Cases

extension OutputTests {
    
    /// Control.vist
    ///
    /// tests `if` statements, variables
    func testControlFlow() {
        let file = "Control"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// Loops.vist
    ///
    /// tests `for in` loops, `while` loops, mutation
    func testLoops() {
        let file = "Loops"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// Type.vist
    ///
    /// tests type sytem, default initialisers, & methods
    func testType() {
        let file = "Type"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// IntegerOps.vist
    ///
    /// tests integer operations
    func testIntegerOps() {
        let file = "IntegerOps"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// Function.vist
    ///
    /// tests function decls and calling, tuples & type param labels
    func testFunctions() {
        let file = "Function"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    
    /// Existential.vist
    ///
    /// Test concept existentials
    func testExistential() {
        let file = "Existential"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// Existential2.vist
    func testExistential2() {
        let file = "Existential2"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// Tuple.vist
    func testTuple() {
        let file = "Tuple"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// String.vist
    func testString() {
        let file = "String"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
    /// Preprocessor.vist
    func testPreprocessor() {
        let file = "Preprocessor"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "-run-preprocessor", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    /// Printable.vist
    func testPrintable() {
        let file = "Printable"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    /// Any.vist
    func testAny() {
        let file = "Any"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(file)")
    }
    
}

extension RefCountingTests {
    // TODO
}


extension RuntimePerformanceTests {
    
    /// LoopPerf.vist
    ///
    /// Analyses the performance of for-in loops
    func testLoop() {
        
        let fileName = "LoopPerf"
        do {
            try compile(withFlags: ["-Ohigh", "\(fileName).vist"], inDirectory: testDir)
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
        measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
            
            let runTask = NSTask()
            runTask.currentDirectoryPath = self.testDir
            runTask.launchPath = "\(self.testDir)/\(fileName)"
            runTask.standardOutput = NSFileHandle.nullDevice()
            
            self.startMeasuring()
            runTask.launch()
            runTask.waitUntilExit()
            self.stopMeasuring()
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(fileName)")
    }
    
    /// FunctionPerf.vist
    ///
    /// Test non memoised fibbonaci
    func testFunction() {
        
        let fileName = "FunctionPerf"
        do {
            try compile(withFlags: ["-Ohigh", "\(fileName).vist"], inDirectory: testDir)
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
        measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
            
            let runTask = NSTask()
            runTask.currentDirectoryPath = self.testDir
            runTask.launchPath = "\(self.testDir)/\(fileName)"
            runTask.standardOutput = NSFileHandle.nullDevice()
            
            self.startMeasuring()
            runTask.launch()
            runTask.waitUntilExit()
            self.stopMeasuring()
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(fileName)")
    }
    /// Random.vist
    ///
    /// Test a PRNG, very heavy on integer ops
    func testRandomNumber() {
        
        let fileName = "Random"
        do {
            try compile(withFlags: ["-Ohigh", "\(fileName).vist"], inDirectory: testDir)
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
        measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
            
            let runTask = NSTask()
            runTask.currentDirectoryPath = self.testDir
            runTask.launchPath = "\(self.testDir)/\(fileName)"
            runTask.standardOutput = NSFileHandle.nullDevice()
            
            self.startMeasuring()
            runTask.launch()
            runTask.waitUntilExit()
            self.stopMeasuring()
        }
        _ = try? NSFileManager.default().removeItem(atPath: "\(testDir)/\(fileName)")
    }

}




extension CoreTests {
    
    /// Runs a compilation of the standard library
    func testStdLibCompile() {
        _ = try? NSFileManager.default().removeItem(atPath: "\(libDir)/libvist.dylib")
        _ = try? NSFileManager.default().removeItem(atPath: "\(libDir)/libvistruntime.dylib")
        do {
            try compile(withFlags: ["-build-stdlib"], inDirectory: stdlibDir)
            XCTAssertTrue(NSFileManager.default().fileExists(atPath: "\(libDir)/libvist.dylib")) // stdlib used by linker
            XCTAssertTrue(NSFileManager.default().fileExists(atPath: "\(libDir)/libvistruntime.dylib")) // the vist runtime
        }
        catch {
            XCTFail("Stdlib build failed with error:\n\(error)\n\n")
        }
    }
    
    /// Builds the runtime
    func testRuntimeBuild() {
        _ = try? NSFileManager.default().removeItem(atPath: "\(libDir)/libvistruntime.dylib")
        do {
            try compile(withFlags: ["-build-runtime"], inDirectory: runtimeDir)
            XCTAssertTrue(NSFileManager.default().fileExists(atPath: "\(libDir)/libvistruntime.dylib")) // the vist runtime
        }
        catch {
            XCTFail("Runtime build failed with error:\n\(error)\n\n")
        }
    }
    
}


extension ErrorTests {
    
    func testVariableError() {
        let file = "VariableError.vist"
        
        do {
            try compile(withFlags: ["-Ohigh", file], inDirectory: testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }
    }
    
    func testTypeError() {
        let file = "TypeError.vist"
        
        do {
            try compile(withFlags: [file], inDirectory: testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }
    }
    
    func testExistentialError() {
        let file = "ExistentialError.vist"
        
        do {
            try compile(withFlags: [file], inDirectory: testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }

    }
    func testMutatingError() {
        let file = "MutatingError.vist"
        
        do {
            try compile(withFlags: [file], inDirectory: testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            
            print(error.parsedError)
            print(try! expectedTestCaseErrors(path: "\(testDir)/\(file)"))
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }
        
    }


}

