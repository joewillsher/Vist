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
        precondition(memType.isInModule())
        self.storedType = memType
        super.init(args: [], irName: irName)
    }
    
    override var type: Type? { return BuiltinType.pointer(to: storedType) }
    var memType: Type? { return storedType }
    
    override var instVIR: String {
        return "\(name) = alloc \(storedType.vir)\(useComment)"
    }
    
    override func copyInst() -> AllocInst {
        return AllocInst(memType: storedType, irName: irName)
    }
}
/**
 Store into a memory location
 
 `store %0 in %a: %*Int`
 */
final class StoreInst : InstBase {
    private(set) var address: PtrOperand, value: Operand
    
    convenience init(address: LValue, value: Value) {
        self.init(address: PtrOperand(address), value: Operand(value))
    }
    
    private init(address: PtrOperand, value: Operand) {
        self.address = address
        self.value = value
        super.init(args: [value, address], irName: nil)
    }
    
    override var type: Type? { return address.type }
    
    override var hasSideEffects: Bool {
        // it has side effects if someone else is using it
        // TODO: should look through dominating blocks for uses, uses before this inst should not be counted
//        return !address.uses.filter { $0 !== address }.isEmpty
        return true
    }
    
    override var instVIR: String {
        return "store \(value.name) in \(address.valueName)\(useComment)"
    }
    
    override func copyInst() -> StoreInst {
        return StoreInst(address: address.formCopy(), value: value.formCopy())
    }
    
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        (value, address) = (args[0], args[1] as! PtrOperand)
    }
}
/**
 Load from a memory location
 
 `%a = load %0: %*Int`
 */
final class LoadInst : InstBase {
    override var type: Type? { return address.memType }
    private(set) var address: PtrOperand
    
    convenience init(address: LValue, irName: String? = nil) {
        self.init(address: PtrOperand(address), irName: irName)
    }
    
    private init(address: PtrOperand, irName: String?) {
        self.address = address
        super.init(args: [self.address], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = load \(address.valueName)\(useComment)"
    }
    
    override func copyInst() -> LoadInst {
        return LoadInst(address: address.formCopy(), irName: irName)
    }
    
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        address = args[0] as! PtrOperand
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
    private(set) var newType: TypeAlias
    
    /// - note: the ptr will have type newType*
    convenience init(address: LValue, newType: TypeAlias, irName: String? = nil) {
        self.init(address: PtrOperand(address), newType: newType, irName: irName)
    }
    
    private init(address op: PtrOperand, newType: TypeAlias, irName: String?) {
        self.address = op
        self.newType = newType
        super.init(args: [op], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = bitcast \(address.valueName) to \(pointerType.explicitName)\(useComment)"
    }
    
    override func copyInst() -> BitcastInst {
        return BitcastInst(address: address.formCopy(), newType: newType, irName: irName)
    }
    
    override func setArgs(args: [Operand]) {
        super.setArgs(args: args)
        address = args[0] as! PtrOperand
    }
}





