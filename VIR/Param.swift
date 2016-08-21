//
//  Param.swift
//  Vist
//
//  Created by Josef Willsher on 21/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum ParamConvention {
    case `in`, refIn, capture
    
    var name: String {
        switch self {
        case .in: return "@in"
        case .refIn: return "@in_ref"
        case .capture: return "@capture"
        }
    }
}

/// A parameter passed between blocks and functions
class Param : Value {
    var paramName: String
    var type: Type?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    let convention: ParamConvention = .in
    
    /// This param's incoming val
    var phi: LLVMValue? = nil
    /// list of predecessor blocks which have added their phi incoming
    var phiPreds: Set<LLVMBasicBlock> = []
    
    required init(paramName: String, type: Type) {
        self.paramName = paramName
        self.type = type
    }
    var irName: String? {
        get { return paramName }
        set { if let v = newValue { paramName = v } }
    }
    
    func updateUsesWithLoweredVal(_ val: LLVMValue) {
        phi = val
        for use in uses { use.setLoweredValue(val) }
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


