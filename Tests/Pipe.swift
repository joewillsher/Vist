//
//  Pipe.swift
//  Vist
//
//  Created by Josef Willsher on 30/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.Pipe
import Foundation.NSString

extension Pipe {
    
    var string: String {
        guard let printed = String(data: fileHandleForReading.readDataToEndOfFile(), encoding: .utf8) else { fatalError("No stdout") }
        return printed
    }
    
}
