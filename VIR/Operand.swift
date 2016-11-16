//
//  Operand.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/**
 An argument type. `Inst`s take `Operand`.
 
 The operand is added to the argument's users list, and 
 allows functionality for modofying instruction sequences
 (for the opt passes).
 
 This also stores the value's lowered LLVM value, and
 when a LLVM value is calculated in IRLower all operands
 are updated to store that.
*/
class Operand : VIRTyped {
    /// The underlying value
    final var value: Value? {
        willSet {
            value?.removeUse(self)
            newValue?.addUse(self)
        }
    }
    /// The value using this operand
    final weak var user: Inst?
    
    convenience init(_ value: Value) {
        self.init(optionalValue: value)
    }
    
    deinit {
        value?.removeUse(self)
    }
    
    final fileprivate(set) var loweredValue: LLVMValue? = nil
    /// Set the LLVM value for uses of this operand
    func setLoweredValue(_ val: LLVMValue) {
        loweredValue = val
    }
    
    final private(set) var airValue: AIRValue? = nil
    func setAirValue(_ val: AIRValue) {
        airValue = val
    }
    
    init(optionalValue value: Value?) {
        self.value = value
        self.user = nil
        value?.uses.append(self)
//        value?.addUse(self) // FIXME(Swift bug): This crashes in -O
    }
    
    /// An operand pointing to nothing
    static func null() -> Operand {
        return Operand(optionalValue: nil)
    }
    
    var type: Type? { return value?.type }

    func formCopy(nullValue: Bool = false) -> Operand {
        return Operand(optionalValue: nullValue ? nil : value)
    }
}

extension Operand {
    func dumpIR() { if let loweredValue = loweredValue { LLVMDumpValue(loweredValue._value!) } else { print("<NULL>") } }
    func dumpIRType() { if let loweredValue = loweredValue { LLVMDumpTypeOf(loweredValue._value!) } else { print("<NULL TYPE>") } }
    
    /// Removes this `Operand` as a user of `value`
    func removeSelfAsUser() {
        value?.removeUse(self)
    }
}


/// An operand which stores a reference-backed lValue
final class PtrOperand : Operand {
    
    /// The stored lValue
    var memType: Type?
    
    convenience init(_ value: LValue) {
        self.init(optionalValue: value, memType: value.memType)
    }
    private init(optionalValue value: LValue?, memType: Type?) {
        self.memType = memType
        super.init(optionalValue: value)
    }
    
    override func formCopy(nullValue: Bool = false) -> PtrOperand {
        return PtrOperand(optionalValue: nullValue ? nil : lValue, memType: memType)
    }
    
    var lValue: LValue? {
        return (value as? LValue) ?? value.map { try! OpaqueLValue(rvalue: $0) }
    }
}


/// An operand which doesn't *use* the value they capture
final class FunctionOperand : Operand {
    
    convenience init(param: Param) {
        self.init(optionalValue: param)
        param.removeUse(self) // function operands shouldnt list null as a use
    }
    
    override func formCopy(nullValue: Bool = false) -> FunctionOperand {
        return FunctionOperand(optionalValue: nullValue ? nil : value)
    }
}


/// An operand applied to a block, loweredValue is lazily evaluated
/// so phi nodes can be created when they're needed and the values
/// are avaliable
class BlockOperand : Operand {
    
    init(optionalValue value: Value?, param: Param, block: BasicBlock) {
        self.param = param
        self.predBlock = block
        super.init(optionalValue: value)
    }
    
    final let param: Param
    /// Predecessor block -- where we are breaking from
    final unowned var predBlock: BasicBlock
    
    final override var type: Type? { return param.type }
    
    override func formCopy(nullValue: Bool = false) -> BlockOperand {
        return BlockOperand(optionalValue: nullValue ? nil : value, param: param, block: predBlock)
    }
    
    /// Sets the phi's value for the incoming block `self.predBlock`
    override func setLoweredValue(_ val: LLVMValue) {
        let incomingBlock = predBlock.loweredBlock
        // if there is no val we cannot add an incoming
        guard let incoming = incomingBlock else {
            loweredValue = nil
            return
        }
        // if we have already added this incoming, return
        if let i = incomingBlock, param.phiPreds.contains(i) { return }
        
        param.phiPreds.insert(incomingBlock!)
        param.phi!.addPhiIncoming([(val, incoming)])
        // set the phi use
        predBlock.loweredBlock!.addPhiUse(PhiTrackingOperand(param: param, val: param.phi!))
    }
    
    /// access to the underlying phi switch. Normal `setLoweredValue` 
    /// adds incomings to the phi
    final var phi: LLVMValue {
        get { return loweredValue! }
        set(phi) { loweredValue = phi }
    }
}

/// When performing a cast, we need to create this operand to apply
/// to the success block
final class CastResultBlockOperand : BlockOperand {
    
    override func formCopy(nullValue: Bool = false) -> CastResultBlockOperand {
        return CastResultBlockOperand(optionalValue: nullValue ? nil : value, param: param, block: predBlock)
    }
}


/// PhiTrackingOperand allows us to update the reference to a lowered
/// phi; each LLVM block holds a set of PhiTrackingOperands which
/// reference it, which they must update if they wish to split.
final class PhiTrackingOperand : Operand, Hashable {
    
    var param: Param? { return value as? Param }
    
    convenience init(param: Param, val: LLVMValue) {
        self.init(param)
        setLoweredValue(val)
    }
    
    override func setLoweredValue(_ val: LLVMValue) {
        (value as! Param).phi = val
        for use in param?.uses ?? [] {
            use.loweredValue = val
        }
        loweredValue = val
    }
    
    var hashValue: Int {
        return loweredValue?.hashValue ?? 0
    }
    static func == (l: PhiTrackingOperand, r: PhiTrackingOperand) -> Bool {
        return l === r
    }
}

