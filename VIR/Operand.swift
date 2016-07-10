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
    final var value: Value? {
        willSet(arg) {
            value?.removeUse(self)
            if let v = arg {
                v.addUse(self)
            }
        }
    }
    /// The value using this operand
    final weak var user: Value?
    
    convenience init(_ value: Value) {
        self.init(optionalValue: value)
    }
    
    deinit {
        value?.removeUse(self)
    }
    
    @available(*, unavailable, message: "`Operand` initialisers should not take `Operand`s")
    init(_ operand: Operand) { fatalError("`Operand` initialisers should not take `Operand`s") }
    
    final private(set) var loweredValue: LLVMValue? = nil
    /// Set the LLVM value for uses of this operand
    func setLoweredValue(_ val: LLVMValue) {
        loweredValue = val
    }
    
    init(optionalValue value: Value?) {
        self.value = value
        self.user = nil
        value?.addUse(self)
    }
    
    /// An operand pointing to nothing
    class func null() -> Operand {
        return Operand(optionalValue: nil)
    }
    
    var type: Type? { return value?.type }
    
    func formCopy() -> Operand {
        return Operand(optionalValue: value)
    }
    
    @available(*, unavailable, renamed: "Operand.formCopy")
    func copy() -> Self {
        return self
    }
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
    
    func dumpIR() { if let loweredValue = loweredValue { LLVMDumpValue(loweredValue._value!) } else { print("\(irName) <NULL>") } }
    func dumpIRType() { if let loweredValue = loweredValue { LLVMDumpTypeOf(loweredValue._value!) } else { print("\(irName).type <NULL>") } }
    
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
    
    convenience init(_ value: LValue) {
        self.init(optionalValue: value)
        self.memType = value.memType
    }
}


/// An operand which doesn't capture self to
final class FunctionOperand : Operand {
    
    convenience init(param: Param) {
        self.init(optionalValue: param)
        param.removeUse(self) // function operands shouldnt list null as a use
    }
}


/// An operand applied to a block, loweredValue is lazily evaluated
/// so phi nodes can be created when theyre needed, allowing their values
/// to be calculated
final class BlockOperand : Operand {
    
    convenience init(value: Value, param: Param) {
        self.init(optionalValue: value, param: param, block: value.parentBlock!)
    }
    
    init(optionalValue value: Value?, param: Param, block: BasicBlock) {
        self.param = param
        self.predBlock = block
        super.init(optionalValue: value)
    }
    
    let param: Param
    private unowned let predBlock: BasicBlock
    
    override var type: Type? { return param.type }
    
    /// Sets the phi's value for the incoming block `self.predBlock`
    override func setLoweredValue(_ val: LLVMValue) {
        guard val._value != nil else {
            loweredValue = nil
            return
        }
        var incoming = [val._value], incomingBlocks = [predBlock.loweredBlock?.block]
        LLVMAddIncoming(param.phi!._value!, &incoming, &incomingBlocks, 1)
    }
    
    /// access to the underlying phi switch. Normal `setLoweredValue` 
    /// adds incomings to the phi
    var phi: LLVMValue {
        get { return loweredValue! }
        set(phi) { loweredValue = phi }
    }
}

