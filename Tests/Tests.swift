//
//  Tests.swift
//  Tests
//
//  Created by Josef Willsher on 30/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import XCTest

private let testDir = "\(SOURCE_ROOT)/Tests/TestCases"


class Tests: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here
    }
    
    override func tearDown() {
        // Put teardown code here
        super.tearDown()
    }
    
    // MARK: Test cases
    
    func testControlFlow() {
        self.measureBlock {
            do {
                try compileWithOptions(["-O", "Control.vist"], inDirectory: testDir)
            }
            catch {
                print(error)
                XCTFail()
            }
        }
    }
    
    
    
    
}
