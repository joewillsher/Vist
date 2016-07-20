//
//  Tests.swift
//  Tests
//
//  Created by Josef Willsher on 30/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import XCTest
//import class Foundation.Pipe
import class Foundation.FileManager
import struct Foundation.URL

// tests can define comments which define the expected output of the program
// `// OUT: 1 2` will add "1\n2\n" to the expected result of the program

protocol VistTest : class {
    static var testDir: String { get }
    static var stdlibDir: String { get }
    static var runtimeDir: String { get }
    static var virDir: String { get }
}

extension VistTest {
    static var testDir: String { return "\(SOURCE_ROOT)/Tests/TestCases" }
    static var stdlibDir: String { return "\(SOURCE_ROOT)/Vist/stdLib" }
    static var runtimeDir: String { return "\(SOURCE_ROOT)/Vist/stdlib/runtime" }
    static var virDir: String { return "\(SOURCE_ROOT)/Vist/VIR" }
    
    static var libDir: String { return "/usr/local/lib" }
    static var binDir: String { return "/usr/local/bin" }
}

/// Test the compilation and output of code samples
final class OutputTests : XCTestCase, VistTest {
}

//final class _AutomatedTests : XCTestCase, VistTest {
//    
//    let files: [String]
//    
//    override init() {
//        files = try! _AutomatedTests.files(dir: _AutomatedTests.testDir)
//        
//        super.init()
//    }
//    
//    private static func files(dir: String) throws -> [String] {
//        return try FileManager.default.contentsOfDirectory(atPath: dir)
//            + FileManager.default.subpathsOfDirectory(atPath: dir).flatMap { try files(dir: $0) }
//    }
//    
//}

protocol CheckingTest : VistTest { }
extension CheckingTest {
    func _testFile(name: String) -> Bool {
        let path = "\(Self.testDir)/\(name).vist"
        let temp = URL(fileURLWithPath: "\(path).tmp")
        guard FileManager.default.createFile(atPath: temp.path!, contents: nil, attributes: nil) else { fatalError() }
        defer { try! FileManager.default.removeItem(at: temp) }
        
        do {
            let flags = try getRunSettings(path: path) + ["\(name).vist"]
            let prefix = try getTestPrefix(path: path)!
            do {
                try compile(withFlags: flags, inDirectory: Self.testDir, out: temp)
                
                let expected = try expectedTestCaseOutput(prefix: prefix, path: path)
                let output = try String(contentsOf: temp)
                
                return try multiLineOutput(output, matches: expected)
            }
            catch {
                XCTFail("Test failed with error: \(error)")
            }
        }
        catch {
            XCTFail("Inforrectly formatted test case: \(error)")
        }
        return false
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

/// Tests the optimiser
final class OptimiserTests : XCTestCase, VistTest, CheckingTest {
    
}

final class VIRGenTests : XCTestCase, VistTest, CheckingTest {
    
}
final class LLVMTests : XCTestCase, VistTest {
    
}


// MARK: Test Cases

extension OutputTests {
    
    /// Control.vist
    ///
    /// tests `if` statements, variables
    func testControlFlow() {
        let file = "Control"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Loops.vist
    ///
    /// tests `for in` loops, `while` loops, mutation
    func testLoops() {
        let file = "Loops"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Type.vist
    ///
    /// tests type sytem, default initialisers, & methods
    func testType() {
        let file = "Type"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// IntegerOps.vist
    ///
    /// tests integer operations
    func testIntegerOps() {
        let file = "IntegerOps"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Function.vist
    ///
    /// tests function decls and calling, tuples & type param labels
    func testFunctions() {
        let file = "Function"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    
    /// Existential.vist
    ///
    /// Test concept existentials -- runtime & LLVM functions for extracting & metadata
    func testExistential() {
        let file = "Existential"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Existential2.vist
    func testExistential2() {
//        let file = "Existential2"
//        do {
//            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(testDir)/\(file).vist"), "Incorrect output")
//            try! FileManager.default.removeItem(atPath: "\(testDir)/\(file)")
//        }
//        catch {
//            XCTFail("Compilation failed with error:\n\(error)\n\n")
//        }
    }
    
    /// Tuple.vist
    func testTuple() {
        let file = "Tuple"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// String.vist
    func testString() {
        let file = "String"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// Preprocessor.vist
    func testPreprocessor() {
        let file = "Preprocessor"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "-run-preprocessor", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    /// Printable.vist
    func testPrintable() {
        let file = "Printable"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    /// Any.vist
    func testAny() {
        let file = "Any"
        do {
            try compile(withFlags: ["-Ohigh", "-r", "\(file).vist"], inDirectory: OutputTests.testDir)
//            XCTAssertEqual(pipe?.string, expectedTestCaseOutput(path: "\(OutputTests.testDir)/\(file).vist"), "Incorrect output")
            try! FileManager.default.removeItem(atPath: "\(OutputTests.testDir)/\(file)")
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
    /// Analyses the performance of for-in loops
    func testLoop() {
        
        let fileName = "LoopPerf"
        do {
            try compile(withFlags: ["-Ohigh", "\(fileName).vist"], inDirectory: RuntimePerformanceTests.testDir)
            
            measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
                
                let runTask = Task()
                runTask.currentDirectoryPath = RuntimePerformanceTests.testDir
                runTask.launchPath = "\(RuntimePerformanceTests.testDir)/\(fileName)"
                runTask.standardOutput = FileHandle.withNullDevice
                
                self.startMeasuring()
                runTask.launch()
                runTask.waitUntilExit()
                self.stopMeasuring()
            }
            
            try! FileManager.default.removeItem(atPath: "\(RuntimePerformanceTests.testDir)/\(fileName)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }
    
    /// FunctionPerf.vist
    ///
    /// Test non memoised fibbonaci
    func testFunction() {
        
        let fileName = "FunctionPerf"
        do {
            try compile(withFlags: ["-Ohigh", "\(fileName).vist"], inDirectory: RuntimePerformanceTests.testDir)
            
            measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
                
                let runTask = Task()
                runTask.currentDirectoryPath = RuntimePerformanceTests.testDir
                runTask.launchPath = "\(RuntimePerformanceTests.testDir)/\(fileName)"
                runTask.standardOutput = FileHandle.withNullDevice
                
                self.startMeasuring()
                runTask.launch()
                runTask.waitUntilExit()
                self.stopMeasuring()
            }
            
            try! FileManager.default.removeItem(atPath: "\(RuntimePerformanceTests.testDir)/\(fileName)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
        
    }
    /// Random.vist
    ///
    /// Test a PRNG, very heavy on integer ops
    func testRandomNumber() {
        
        let fileName = "Random"
        do {
            try compile(withFlags: ["-Ohigh", "\(fileName).vist"], inDirectory: RuntimePerformanceTests.testDir)
            
            measureMetrics(RuntimePerformanceTests.defaultPerformanceMetrics(), automaticallyStartMeasuring: false) {
                
                let runTask = Task()
                runTask.currentDirectoryPath = RuntimePerformanceTests.testDir
                runTask.launchPath = "\(RuntimePerformanceTests.testDir)/\(fileName)"
                runTask.standardOutput = FileHandle.withNullDevice
                
                self.startMeasuring()
                runTask.launch()
                runTask.waitUntilExit()
                self.stopMeasuring()
            }
            
            _ = try? FileManager.default.removeItem(atPath: "\(RuntimePerformanceTests.testDir)/\(fileName)")
        }
        catch {
            XCTFail("Compilation failed with error:\n\(error)\n\n")
        }
    }

}




extension CoreTests {
    
    /// Runs a compilation of the standard library
    func testStdLibCompile() {
        _ = try? FileManager.default.removeItem(atPath: "\(CoreTests.libDir)/libvist.dylib")
        _ = try? FileManager.default.removeItem(atPath: "\(CoreTests.libDir)/libvistruntime.dylib")
        do {
            try compile(withFlags: ["-build-stdlib"], inDirectory: CoreTests.stdlibDir)
            XCTAssertTrue(FileManager.default.fileExists(atPath: "\(CoreTests.libDir)/libvist.dylib")) // stdlib used by linker
            XCTAssertTrue(FileManager.default.fileExists(atPath: "\(CoreTests.libDir)/libvistruntime.dylib")) // the vist runtime
        }
        catch {
            XCTFail("Stdlib build failed with error:\n\(error)\n\n")
        }
    }
    
    /// Builds the runtime
    func testRuntimeBuild() {
        _ = try? FileManager.default.removeItem(atPath: "\(CoreTests.libDir)/libvistruntime.dylib")
        do {
            try compile(withFlags: ["-build-runtime"], inDirectory: CoreTests.runtimeDir)
            XCTAssertTrue(FileManager.default.fileExists(atPath: "\(CoreTests.libDir)/libvistruntime.dylib")) // the vist runtime
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
            try compile(withFlags: ["-Ohigh", file], inDirectory: ErrorTests.testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(ErrorTests.testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }
    }
    
    func testTypeError() {
        let file = "TypeError.vist"
        
        do {
            try compile(withFlags: [file], inDirectory: ErrorTests.testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(ErrorTests.testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }
    }
    
    func testExistentialError() {
        let file = "ExistentialError.vist"
        
        do {
            try compile(withFlags: [file], inDirectory: ErrorTests.testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(ErrorTests.testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }

    }
    func testMutatingError() {
        let file = "MutatingError.vist"
        
        do {
            try compile(withFlags: [file], inDirectory: ErrorTests.testDir)
            XCTFail("Errors not caught")
        }
        catch let error as VistError {
            XCTAssertEqual(error.parsedError, try! expectedTestCaseErrors(path: "\(ErrorTests.testDir)/\(file)"), "Incorrect output")
        }
        catch {
            XCTFail("Unknown Error: \(error)")
        }
        
    }


}


extension OptimiserTests {
    
    func testDCE() {
        XCTAssert(_testFile(name: "DCE"))
    }
    func testStdlibInlineVIR() {
        XCTAssert(_testFile(name: "StdlibInline-vir"))
    }
    func testStdlibInlineLLVM() {
        XCTAssert(_testFile(name: "StdlibInline-llvm"))
    }
    func testInlinerSimple() {
        XCTAssert(_testFile(name: "InlineSimple"))
    }
    func testStructFlattenVIR() {
        XCTAssert(_testFile(name: "StructFlatten"))
    }
}

extension VIRGenTests {
    
    func testFunctionVIRGen() {
        XCTAssert(_testFile(name: "FnCallVIR"))
    }
    
    func testExistentialReturn() {
        XCTAssert(_testFile(name: "ExistentialReturn-vir"))
    }
    
}

extension LLVMTests {
    
    func testMetadata() {
        
        let file = "Existential", path = "\(LLVMTests.testDir)/\(file).vist"
        
        let flags = try! getRunSettings(path: path) + ["\(file).vist"]
        do {
            try compile(withFlags: flags, inDirectory: LLVMTests.testDir)
            
            let expected = try expectedTestCaseLLVM(path: path)
            let output = try String(contentsOfFile: "\(VIRGenTests.testDir)/\(file).ll")
            
            try XCTAssert(multiLineOutput(output, matches: expected))
        }
        catch {
            XCTFail("\(error)")
        }
    }
    
    func testStrings() {
        
        let file = "String", path = "\(LLVMTests.testDir)/\(file).vist"
        
        let flags = try! getRunSettings(path: path) + ["\(file).vist"]
        do {
            try compile(withFlags: flags, inDirectory: LLVMTests.testDir)
            
            let expected = try expectedTestCaseLLVM(path: path)
            let output = try String(contentsOfFile: "\(LLVMTests.testDir)/\(file).ll")
            
            try XCTAssert(multiLineOutput(output, matches: expected))
        }
        catch {
            XCTFail("\(error)")
        }
    }

}



