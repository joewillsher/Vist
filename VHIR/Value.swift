//
//  Value.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// An RValue, instruction results, literals, etc
protocol RValue: class, VHIRElement {
    /// An explicit name to give self in the ir repr
    var irName: String? { get set }
    
    var type: Ty? { get }
    
    /// The block containing `self`
    weak var parentBlock: BasicBlock! { get set }
    
    /// The list of uses of `self`. A collection of `Operand`
    /// instances whose `value`s point to self, to 
    var uses: [Operand] { get set }
    
    /// The formatted name as shown in IR
    var name: String { get set }
}

/// Appears on the LHS of an expressions. `a = 1`, `a.b.c`
///
/// Often abstracts over memory -- this can be accessed by a pointer.
/// This is needed for mutating the val or getting sub-elements by ref
protocol LValue: RValue {
    /// LValues provide storage which is abstract -- `memType` provides
    /// an interface to the underlying type, as `type` may return  type `*memType`
    var memType: Ty? { get }
}

extension RValue {
    
    /// Removes all `Operand` instances which point to `self`
    func removeAllUses() { uses.forEach(removeUse)  }
    
    /// Replaces all `Operand` instances which point to `self`
    /// with `val`
    func replaceAllUses(with val: RValue) {
         for use in uses { use.value = val }
    }
    
    /// Adds record of a user `use` to self’s users list
    func addUse(use: Operand) { uses.append(use) }
    
    /// Removes `use` from self’s uses record
    func removeUse(use: Operand) {
        guard let i = uses.indexOf({$0.value === self}) else { return }
        uses.removeAtIndex(i)
        use.value = nil
        use.user = nil
    }
    
    /// Adds the lowered val to all users
    func updateUsesWithLoweredVal(val: LLVMValueRef) {
        for use in uses { use.setLoweredValue(val) }
    }
    
    /// The accessor whose getter returns `self`
    var accessor: ValAccessor { return ValAccessor(value: self) }
    
    /// Builds a reference accessor which can store into & load from
    /// the memory it allocates
    func allocAccessor() throws -> GetSetAccessor {
        let accessor = RefAccessor(memory: try module.builder.buildAlloc(type!))
        try accessor.setter(Operand(self))
        return accessor
    }

    func dump() { print(vhir) }
    
    var module: Module { return parentBlock.module }
    var parentFunction: Function { return parentBlock.parentFunction }
    
    // TODO: fix this, its super inefficient -- cache nums and invalidate after function changes
    /// If `self` doesn't have an `irName`, this provides the 
    /// number to use in the ir repr
    private func getInstNumber() -> String? {
        
        var count = 0
        for inst in parentFunction.instructions {
            if case let o as Operand = self where o.value === inst { break }
            else if inst === self { break }
            // we dont want to provide a name for void exprs
            // remove iteration here, plus in instrs that could be void, remove the `%0 = `...
            if inst.irName == nil /*&& inst.type != BuiltinType.void*/ { count += 1 }
        }
        
        return String(count)
    }
    
    var name: String {
        get { return "%\(irName ?? getInstNumber() ?? "<null>")" }
        set { irName = newValue }
    }
}

extension LValue {
    var accessor: GetSetAccessor { return RefAccessor(memory: self) }
}



