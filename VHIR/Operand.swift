//
//  Operand.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


class Operand : Value {
    /// The underlying value
    var value: Value?
    weak var user: Inst?
    
    init(_ value: Value) {
        self.value = value
        value.addUse(self)
    }
    
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
final class PtrOperand : Operand, LValue {
    
    /// The stored lvalue
    var memType: Ty?
    
    init(_ value: LValue) {
        self.memType = value.memType
        super.init(value)
    }
    
    private init(rvalue: Value, memType: Ty) {
        self.memType = memType
        super.init(rvalue)
    }
    
    /// - precondition: `rval` is guaranteed to be an lvalue
    static func fromReferenceRValue(rval: Value) throws -> PtrOperand {
        guard case let type as BuiltinType = rval.type, case .pointer(let to) = type else { fatalError() }
        return PtrOperand(rvalue: rval, memType: to)
    }
}



/// An operand applied to a block, loweredValue is lazily evaluated
/// so phi nodes can be created when theyre needed, allowing their values
/// to be calculated
final class BlockOperand : Operand {
    
    init(value: Value, param: Param) {
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

