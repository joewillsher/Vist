//
//  Operand.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class Operand: Value {
    /// The underlying value
    var value: Value?
    
    init(_ value: Value) {
        self.value = value
        value.addUse(self)
    }
    
    deinit {
        try! value?.removeUse(self)
    }
    
    var loweredValue: LLVMValueRef = nil
    
    // forward all interface to `value`
    var type: Ty? { return value?.type }
    var irName: String? {
        get { return value?.irName }
        set { value?.irName = newValue }
    }
    var parentBlock: BasicBlock? {
        get { return value?.parentBlock }
        set { value?.parentBlock = newValue }
    }
    var uses: [Operand] {
        get { return value?.uses ?? [] }
        set { value?.uses = newValue }
    }
    var name: String {
        get { return value!.name }
        set { value?.name = newValue }
    }
    
    var user: Inst? {
        return parentBlock?.userOfOperand(self)
    }
}
