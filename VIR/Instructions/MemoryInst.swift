//
//  Memory.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/**
 Allocate stack memory
 
 `%a = alloc %Int`
 */
final class AllocInst : InstBase, LValue {
    var storedType: Type
    
    /// - precondition: newType has types in this module
    init(memType: Type, irName: String? = nil) {
        precondition(memType is TypeAlias)
        self.storedType = memType
        super.init(args: [], irName: irName)
    }
    
    override var type: Type? { return BuiltinType.pointer(to: storedType) }
    var memType: Type? { return storedType }
    
    override var instVIR: String {
        return "\(name) = alloc \(storedType.vir) \(useComment)"
    }
}
/**
 Store into a memory location
 
 `store %0 in %a: %*Int`
 */
final class StoreInst : InstBase {
    private(set) var address: PtrOperand, value: Operand
    
    init(address: LValue, value: Value) {
        self.address = PtrOperand(address)
        self.value = Operand(value)
        super.init(args: [self.value, self.address], irName: nil)
    }
    
    override var type: Type? { return address.type }
    
    override var hasSideEffects: Bool { return true }
    
    override var instVIR: String {
        return "store \(value.name) in \(address.valueName) \(useComment)"
    }
}
/**
 Load from a memory location
 
 `%a = load %0: %*Int`
 */
final class LoadInst : InstBase {
    override var type: Type? { return address.memType }
    private(set) var address: PtrOperand
    
    init(address: LValue, irName: String? = nil) {
        precondition(address.memType is TypeAlias)
        self.address = PtrOperand(address)
        super.init(args: [self.address], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = load \(address.valueName) \(useComment)"
    }
}
/**
 Bitcast a memory location
 
 `%a = bitcast %0:%*Int to %*Builtin.Int`
 */
final class BitcastInst : InstBase, LValue {
    var pointerType: BuiltinType { return BuiltinType.pointer(to: newType) }
    override var type: Type? { return pointerType }
    var memType: Type? { return newType }
    /// The operand of the cast
    private(set) var address: PtrOperand
    /// The new memory type of the cast
    private(set) var newType: Type
    
    /// - precondition: newType has types in this module
    /// - note: the ptr will have type newType*
    init(address: LValue, newType: Type, irName: String? = nil) {
        precondition(newType is TypeAlias)
        let op = PtrOperand(address)
        self.address = op
        self.newType = newType
        super.init(args: [op], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = bitcast \(address.valueName) to \(pointerType.explicitName) \(useComment)"
    }
}





