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
// `// test: 1 2` will add "1\n2\n" to the expected result of the program

protocol VistTest: class {
    var testDir: String { get }
    var stdlibDir: String { get }
    var runtimeDir: String { get }
    var virDir: String { get }
}

extension VistTest {
    var testDir: String { return "\(SOURCE_ROOT)/Tests/TestCases" }
    var stdlibDir: String { return "\(SOURCE_ROOT)/Vist/stdLib" }
    var runtimeDir: String { return "\(SOURCE_ROOT)/Vist/Runtime" }
    var virDir: String { return "\(SOURCE_ROOT)/Vist/VIR" }
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


private func deleteFile(name: String, inDirectory direc: String) {
    let t = NSTask()
    t.currentDirectoryPath = direc
    t.launchPath = "/bin/rm"
    t.arguments = [name]
    t.launch()
    t.waitUntilExit()
}









// MARK: Test Cases

extension OutputTests {
    
    /// Control.vist
    ///
    /// tests `if` statements, variables
    func testControlFlow() {
        let file = "Control.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Loops.vist
    ///
    /// tests `for in` loops, `while` loops, mutation
    func testLoops() {
        let file = "Loops.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Type.vist
    ///
    /// tests type sytem, default initialisers, & methods
    func testType() {
        let file = "Type.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// IntegerOps.vist
    ///
    /// tests integer operations
    func testIntegerOps() {
        let file = "IntegerOps.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Function.vist
    ///
    /// tests function decls and calling, tuples & type param labels
    func testFunctions() {
        let file = "Function.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    
    /// Existential.vist
    ///
    /// Test concept existentials
    func testExistential() {
        let file = "Existential.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Existential2.vist
    func testExistential2() {
        let file = "Existential.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    
    /// Tuple.vist
    func testTuple() {
        let file = "Tuple.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }

    /// String.vist
    func testString() {
        let file = "String.vist"
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir, out: pipe)
            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    

}

extension RefCountingTests {
    // TODO
}


extension RuntimePerformanceTests {
    
    /// LoopPerf.vist
    ///
    /// Builds file and analyses performance of resulting binary
    func testLoop() {
        
        let fileName = "LoopPerf"
        do {
            try compileWithOptions(["-build-only", "-Ohigh", "-disable-stdlib-inline¯", "\(fileName).vist"], inDirectory: testDir)
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
        measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
            
            let runTask = NSTask()
            runTask.currentDirectoryPath = self.testDir
            runTask.launchPath = "\(self.testDir)/\(fileName)"
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
    func testFunction() {
        
        let fileName = "FunctionPerf"
        do {
            try compileWithOptions([ "-build-only", "-Ohigh", "-disable-stdlib-inline¯", "\(fileName).vist"], inDirectory: testDir)
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
        measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
            
            let runTask = NSTask()
            runTask.currentDirectoryPath = self.testDir
            runTask.launchPath = "\(self.testDir)/\(fileName)"
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
    func testStdLibCompile() {
        deleteFile("stdlib.bc", inDirectory: stdlibDir)
        deleteFile("stdlib.o", inDirectory: stdlibDir)
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
    func testRuntimeBuild() {
        deleteFile("runtime.bc", inDirectory: runtimeDir)
        do {
            try compileWithOptions(["-build-runtime"], inDirectory: runtimeDir)
            XCTAssertTrue(NSFileManager.defaultManager().fileExistsAtPath("\(runtimeDir)/runtime.bc"))
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
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir)
            XCTFail("Errors not caught")
        }
        catch {
            let e = ErrorCollection(errors: [
                SemaError.noVariable("b"),
                SemaError.noVariable("a"),
                SemaError.noFunction("print", [StdLib.intType, StdLib.intType]),
                ErrorCollection(errors: [
                    SemaError.noVariable("v"),
                    SemaError.noFunction("+", [StdLib.intType, StdLib.boolType]),
                    SemaError.wrongFunctionReturnType(applied: StdLib.doubleType, expected: StdLib.intType)
                    ]),
                SemaError.noVariable("print"),
                SemaError.immutableVariable(name: "x", type: "Int"),
                SemaError.invalidRedeclaration("x"),
                SemaError.immutableProperty(p: "a", ty: "Foo"),
                SemaError.invalidTypeRedeclaration("Foo")
                ])
            
            XCTAssertNotNil(error as? ErrorCollection)
            XCTAssert(e.description == (error as! ErrorCollection).description)
        }
        
    }
    
    func testTypeError() {
        let file = "TypeError.vist"
        
        do {
            try compileWithOptions(["-Ohigh", "-disable-stdlib-inline¯", file], inDirectory: testDir)
            XCTFail("Errors not caught")
        }
        catch {
            let e = ErrorCollection(errors: [
                SemaError.immutableVariable(name: "imm", type: "Foo"),
                SemaError.immutableVariable(name: "imm", type: "Foo"),
                SemaError.immutableProperty(p: "a", ty: "Foo"),
                SemaError.noPropertyNamed(type: "Foo", property: "x"),
                SemaError.immutableVariable(name: "tup", type: "Int.Int.tuple"),
                SemaError.noTupleElement(index: 3, size: 2)
                ])
            
            XCTAssertNotNil(error as? ErrorCollection)
            XCTAssert(e.description == (error as! ErrorCollection).description)
        }
    }

}

