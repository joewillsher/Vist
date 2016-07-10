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
    
    var phi: LLVMValue? = nil
    
    required init(paramName: String, type: Type) {
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
    
    /// - parameter type: The memType of the reference param
    required init(paramName: String, type memType: Type) {
        self.memType = memType
        super.init(paramName: paramName, type: BuiltinType.pointer(to: memType))
    }
    
}

extension Param {
    
    // param has no params so a copy is clean
    func copy() -> Self {
        assert(phi == nil) // cannot copy if we are in VIRLower
        return self.dynamicType.init(paramName: paramName, type: type!)
    }
}


