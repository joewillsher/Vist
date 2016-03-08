//
//  Value.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A value, instruction results, literals, etc
protocol Value: class, VHIRElement {
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

extension Value {
    
    func dump() { print(vhir) }
    
    var module: Module { return parentBlock.module }
    var parentFunction: Function { return parentBlock.parentFunction }
    
    /// Removes all `Operand` instances which point to `self`
    func removeAllUses() {
        for use in uses { use.value = nil }
        uses.removeAll()
    }
    
    /// Replaces all `Operand` instances which point to `self`
    /// with `val`
    func replaceAllUsesWith(val: Value) {
        let u = uses
        removeAllUses()
        
        for use in u {
            use.value = val
            addUse(use)
        }
    }
    
    /// Adds record of this use to self
    func addUse(use: Operand) {
        uses.append(use)
    }
    
    /// Removes `use` from self's uses record
    func removeUse(use: Operand) throws {
        guard let i = uses.indexOf({$0.value === self}) else { throw VHIRError.noUse }
        uses.removeAtIndex(i)
    }
    
    /// Adds the lowered val to all users
    func updateUsesWithLoweredVal(val: LLVMValueRef) {
        for use in uses {
            use.loweredValue = val
        }
    }
    
    /// If `self` doesn't have an `irName`, this provides the 
    /// number to use in the ir repr
    func getInstNumber() -> String? {
        guard let blocks = parentBlock.parentFunction.blocks else { return nil }
        
        var count = 0
        blockLoop: for block in blocks {
            instLoop: for inst in block.instructions {
                if case let o as Operand = self where o.value === inst { break blockLoop }
                if inst === self { break blockLoop }
                // we dont want to provide a name for void exprs
                // remove iteration here, plus in instrs that could be void, remove the `%0 = `...
                if inst.irName == nil /*&& inst.type != BuiltinType.void*/ { count += 1 }
            }
        }
        
        return String(count)
    }
    
    // MARK: implement protocol methods
    
    var name: String {
        get { return "%\(irName ?? getInstNumber() ?? "<null>")" }
        set { irName = newValue }
    }
}
