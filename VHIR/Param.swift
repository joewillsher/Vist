//
//  Param.swift
//  Vist
//
//  Created by Josef Willsher on 21/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A parameter passed between blocks and functions
class Param : Value {
    var paramName: String
    var type: Type?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    var phi: LLVMValueRef = nil
    
    init(paramName: String, type: Type) {
        self.paramName = paramName
        self.type = type
    }
    var irName: String? {
        get { return paramName }
        set { if let v = newValue { paramName = v } }
    }
}

/// A param backed by a pointer
final class RefParam : Param, LValue {
    var memType: Type?
    
    init(paramName: String, memType: Type) {
        self.memType = memType
        super.init(paramName: paramName, type: BuiltinType.pointer(to: memType))
    }
    
}
