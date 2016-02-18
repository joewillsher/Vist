//
//  LLVMPtrWrapper.swift
//  Vist
//
//  Created by Josef Willsher on 14/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol LLVMValue: class {
    var value: LLVMValueRef { get set }
    init(value: LLVMValueRef)
}

extension LLVMValue {
    
    func dump() { // if != nil
        LLVMDumpValue(value)
    }
    
}

final class LLVMIntValue {
    var value: LLVMValueRef
    
    init(value: LLVMValueRef) {
        self.value = value
    }
    
}

