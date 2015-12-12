//
//  LLVMHelp.swift
//  Vist
//
//  Created by Josef Willsher on 07/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation
import LLVM

extension LLVMBool {
    init(_ b: Bool) {
        self.init(b ? 1 : 0)
    }
}
