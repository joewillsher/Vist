//
//  LValue.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A VIR value: instructions, literals, params, function refs
///              globals
protocol Value : class, VIRTyped, VIRElement {
    /// An explicit name to give self in the ir repr
    var irName: String? { get set }
    
    /// The block containing `self`
    weak var parentBlock: BasicBlock? { get set }
    
    /// The list of uses of `self`. A collection of `Operand`
    /// instances whose `value`s point to self, the operand's
    /// user is the inst which takes `self`
    var uses: [Operand] { get set }
    
    /// The formatted name as shown in IR
    var name: String { get set }
    
    var module: Module { get }
    
    func copy() -> Self
    
    func updateUsesWithLoweredVal(_: LLVMValue)
    func updateUsesWithAIR(_: AIRValue)
    
    func getAs<I : Inst>(_ type: I.Type) -> I?
}

/// A typed VIR object
protocol VIRTyped {
    var type: Type? { get }
}

/**
 Appears on the LHS of an expressions. `a = 1`, `a.b.c`
 
 Often abstracts over memory -- this can be accessed by a pointer.
 This is needed for mutating the val or getting sub-elements by ref
*/
protocol LValue : Value {
    /// LValues provide storage which is abstract -- `memType` provides
    /// an interface to the underlying type, as `type` may return  type `*memType`
    var memType: Type? { get }
}

/**
 for mapping getter for type -- cant do
 `let a = params.optionalMap(Value.type) else { throw ...`
 so we can `let a = params.map(Value.getType(of:))`
 */
func getType(of val: VIRTyped) throws -> Type { if let t = val.type { return t } else { throw irGenError(.typeNotFound, userVisible: false) } }

extension Value {
    
    func copy() -> Self { return self }
    
    /// Adds record of a user `use` to self’s users list
    func addUse(_ use: Operand) {
        uses.append(use)
    }
    
    /// Removes `use` from self’s uses record
    func removeUse(_ use: Operand) {
        //guard let i = uses.index(where: {$0.value === self}) else { return }
        guard let i = uses.index(where: {$0 === use}) else { return }
        uses.remove(at: i)
    }
    
    /// Adds the lowered val to all users
    func updateUsesWithLoweredVal(_ val: LLVMValue) {
        for use in uses { use.setLoweredValue(val) }
    }
    /// Adds the lowered val to all users
    func updateUsesWithAIR(_ air: AIRValue) {
        for use in uses { use.setAirValue(air) }
    }
    
    func dump() { print(vir) }
    
    var module: Module { return parentBlock!.module }
    var parentFunction: Function? { return parentBlock?.parentFunction }
    
    // TODO: fix this, its super inefficient -- cache nums and invalidate after function changes
    /// If `self` doesn't have an `irName`, this provides the 
    /// number to use in the ir repr
    private func getInstNumber() -> String? {
        
        var count = 0
        guard let instructions = parentFunction?.instructions else { return nil }
        
        for val in instructions {
            if val === self {
                return String(count)
            }
            if val.irName == nil { count += 1 }
        }
        
        return nil
    }
    
    var name: String {
        get { return "%\(irName ?? getInstNumber() ?? "<null>")" }
        set { irName = newValue }
    }
    var unformattedName: String {
        return irName ?? getInstNumber() ?? "<null>"
    }
    /// Does this value have a pointer type
    var isIndirect: Bool {
        if self is LValue { return true }
        if case let b as BuiltinType = type, case .pointer = b { return true }
        return false
    }
}

/// A value known to be an LValue, under the hood is an 
/// rvalue with a pointer type
final class OpaqueLValue : LValue {
    
    /// The rvalue
    private(set) var value: Value
    private var storedType: Type
    
    /// Init from rvalue
    /// - precondition: `memType` is the type of `rvalue`'s memory and
    ///                 is guaranteed to be a pointer type
    init(rvalue: Value) throws {
        self.value = rvalue
        guard case let type as BuiltinType = rvalue.type, case .pointer(let to) = type else { throw VIRError.noType(#file) }
        self.storedType = to
    }
    
    var type: Type? { return BuiltinType.pointer(to: storedType) }
    var memType: Type? { return storedType }

    var parentBlock: BasicBlock? {
        get { return value.parentBlock }
        set { value.parentBlock = newValue }
    }
    var name: String {
        get { return value.name }
        set { value.name = newValue }
    }
    var uses: [Operand] {
        get { return value.uses }
        set { value.uses = newValue }
    }
    var irName: String? {
        get { return value.irName }
        set { value.irName = newValue }
    }
}

