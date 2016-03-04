//
//  Config.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

func configModule(module: LLVMModuleRef) {
    LLVMSetDataLayout(module, "e-m:o-i64:64-f80:128-n8:16:32:64-S128")
    LLVMSetTarget(module, "x86_64-apple-macosx10.11.0")
    // GC here?
}

