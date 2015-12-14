//
//  Config.swift
//  Vist
//
//  Created by Josef Willsher on 13/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

func configModule(module: LLVMModuleRef) {
    
    let target = UnsafeMutablePointer<LLVMTargetRef>.alloc(1)
    LLVMGetTargetFromTriple("x86_64-apple-macosx10.11.0", target, nil)
    
    // remove IR’s metadata
    let a = LLVMGetNamedMetadataNumOperands(module, "llvm.ident")
    
    let ptr = UnsafeMutablePointer<LLVMValueRef>.alloc(1)
    
////    LLVMGetNamedMetadataOperands(module, "attributes #0", ptr)
//    
//    let vals = [LLVMValueRef]().ptr()
//    
//    let node = LLVMMDNode(vals, 0)
//    
////    LLVMAddNamedMetadataOperand(module, "llvm.ident", node)
//    
//    let c = LLVMGetMDKindID("llvm.ident", 1)
//    
////    LLVMSetMetadata(<#T##Val: LLVMValueRef##LLVMValueRef#>, <#T##KindID: UInt32##UInt32#>, <#T##Node: LLVMValueRef##LLVMValueRef#>)
//    
//    LLVMSetMetadata(<#T##Val: LLVMValueRef##LLVMValueRef#>, <#T##KindID: UInt32##UInt32#>, <#T##Node: LLVMValueRef##LLVMValueRef#>)
//    
//    LLVMErase
//    
//    let m = LLVMGetMetadata(module, c)
//
    
//    print(c)
//    
//    LLVMDumpModule(module)
    
    
    
}

