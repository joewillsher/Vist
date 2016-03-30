//
//  Operand.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


class Operand: RValue {
    /// The underlying value
    var value: RValue?
    weak var user: Inst?
    
    init(_ value: RValue) {
        self.value = value
        value.addUse(self)
    }
    private init() { }
    
    deinit {
        value?.removeUse(self)
    }

    @available(*, unavailable, message="`Operand` initialisers should not take `Operand`s")
    init(_ operand: Operand) { fatalError() }
    
    private(set) var loweredValue: LLVMValueRef = nil
    func setLoweredValue(val: LLVMValueRef) { loweredValue = val }

    var type: Ty? { return value?.type }
}

extension Operand {
    // forward all interface to `value`
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
        get { return value?.name ?? "<null>" }
        set { value?.name = newValue }
    }
    var operandName: String { return "<operand of \(name) by \(user?.name)>" }
    
    func dumpIR() { if loweredValue != nil { LLVMDumpValue(loweredValue) } else { print("\(irName) <NULL>") } }
    func dumpIRType() { if loweredValue != nil { LLVMDumpTypeOf(loweredValue) } else { print("\(irName).type <NULL>") } }
    
    /// Removes this `Operand` as a user of `value`
    func removeSelfAsUser() {
        value?.removeUse(self)
    }
}


/// An operand which stores a reference-backed lvalue
final class PtrOperand: Operand, LValue {
    
    /// The stored lvalue
    var _value: LValue?
    override var value: RValue? {
        get { return _value }
        set { _value = newValue as? LValue }
    }
    var memType: Ty? { return _value?.memType }
    
    init(_ value: LValue) {
        self._value = value
        super.init()
        value.addUse(self)
    }
}



/// An operand applied to a block, loweredValue is lazily evaluated
/// so phi nodes can be created when theyre needed, allowing their values
/// to be calculated
final class BlockOperand: Operand {
    
    init(value: RValue, param: Param) {
        self.param = param
        self.predBlock = value.parentBlock!
        super.init(value)
    }
    
    let param: Param
    private unowned let predBlock: BasicBlock
    
    override var type: Ty? { return param.type }
    
    /// Sets the phi's value for the incoming block `self.predBlock`
    override func setLoweredValue(val: LLVMValueRef) {
        guard val != nil else {
            loweredValue = nil
            return
        }
        let incoming = [val].ptr(), incomingBlocks = [predBlock.loweredBlock].ptr()
        defer { incoming.destroy(); incomingBlocks.destroy() }
        LLVMAddIncoming(param.phi, incoming, incomingBlocks, 1)
    }
    
    /// access to the underlying phi switch. Normal `setLoweredValue` 
    /// adds incomings to the phi
    var phi: LLVMValueRef {
        get { return loweredValue }
        set(phi) { loweredValue = phi }
    }
}

