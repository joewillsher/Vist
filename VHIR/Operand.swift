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
    init(_ operand: Operand) { fatalError("`Operand` initialisers should not take `Operand`s") }
    
    private(set) var loweredValue: LLVMValueRef = nil
    func setLoweredValue(val: LLVMValueRef) { loweredValue = val }

    var type: Type? { return value?.type }
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


/// An operand which stores a reference-backed lvalue. Can itself
/// be used as an lvalue
final class PtrOperand : Operand, LValue {
    
    /// The stored lvalue
    var memType: Type?
    
    init(_ value: LValue) {
        self.memType = value.memType
        super.init(value)
    }
    
    /// Init from rvalue
    /// - precondition: `memType` is the type of `rvalue`'s memory and 
    ///                 is guaranteed to be a pointer type
    private init(rvalue: Value, memType: Type) {
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
    
    override var type: Type? { return param.type }
    
    /// Sets the phi's value for the incoming block `self.predBlock`
    override func setLoweredValue(val: LLVMValueRef) {
        guard val != nil else {
            loweredValue = nil
            return
        }
        var incoming = [val], incomingBlocks = [predBlock.loweredBlock]
        LLVMAddIncoming(param.phi, &incoming, &incomingBlocks, 1)
    }
    
    /// access to the underlying phi switch. Normal `setLoweredValue` 
    /// adds incomings to the phi
    var phi: LLVMValueRef {
        get { return loweredValue }
        set(phi) { loweredValue = phi }
    }
}

