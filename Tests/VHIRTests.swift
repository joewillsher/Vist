//
//  VHIRTests.swift
//  Vist
//
//  Created by Josef Willsher on 28/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation
import XCTest


final class VHIRTests: XCTestCase {
    
    func testFunction() {
        
        let fnType = FunctionType(params: [IntType(size: 64), IntType(size: 64)], returns: IntType(size: 64))
        let fn = Function(name: "add", type: fnType, blocks: nil)
        
        
    }
    
}
