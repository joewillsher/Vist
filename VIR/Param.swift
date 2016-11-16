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
    
    let convention: Convention?
    
    /// This param's incoming val
    var phi: LLVMValue? = nil
    /// list of predecessor blocks which have added their phi incoming
    var phiPreds: Set<LLVMBasicBlock> = []
    
    required init(paramName: String, type: Type, convention: Convention? = nil) {
        self.paramName = paramName
        self.type = type
        
        if case BuiltinType.pointer = type {
            self.convention = convention ?? .in
        }
        else {
            self.convention = nil
        }
    }
    var irName: String? {
        get { return paramName }
        set { if let v = newValue { paramName = v } }
    }
    
    func updateUsesWithLoweredVal(_ val: LLVMValue) {
        phi = val
        for use in uses { use.setLoweredValue(val) }
    }
    
    enum Convention {
        case `in`, out, `inout`
        
        var name: String {
            switch self {
            case .in: return "@in"
            case .out: return "@out"
            case .inout: return "@inout"
            }
        }
    }
    
    /// Returns a managed value for this param, the clearup depends on the
    /// param convention
    func managed(gen: VIRGenFunction, hasCleanup: Bool = true) -> AnyManagedValue {
        switch convention {
        case .in?, nil:
            return Managed<Param>.forManaged(self, hasCleanup: hasCleanup, gen: gen).erased
        case .out?, .inout?:
            return Managed<RefParam>.forLValue(self as! RefParam, gen: gen).erased
        }
    }
}

/// A param backed by a pointer
final class RefParam : Param, LValue {
    var memType: Type?
    
    /// - parameter type: The memType of the reference param
    required init(paramName: String, type memType: Type, convention: Convention? = nil) {
        self.memType = memType
        super.init(paramName: paramName, type: BuiltinType.pointer(to: memType), convention: convention)
    }
    
}

extension Param {
    
    // param has no params so a copy is clean
    func copy() -> Self {
        assert(phi == nil) // cannot copy if we are in VIRLower
        return type(of: self).init(paramName: paramName, type: type!, convention: convention)
    }
}

extension Param : Hashable {
    var hashValue: Int { return name.hashValue }
    static func == (l: Param, r: Param) -> Bool {
        return l === r
    }
}


