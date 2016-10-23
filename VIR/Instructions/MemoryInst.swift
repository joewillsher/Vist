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
final class AllocInst : Inst, LValue {
    var storedType: Type
    
    var uses: [Operand] = []
    var args: [Operand] = []
    
    /// - precondition: newType has types in this module
    init(memType: Type, irName: String? = nil) {
        precondition(memType.isInModule())
        self.storedType = memType
        self.irName = irName
    }
    
    var type: Type? { return BuiltinType.pointer(to: storedType) }
    var memType: Type? { return storedType }
    
    var vir: String {
        return "\(name) = alloc \(storedType.vir)\(useComment)"
    }
    
    func copy() -> AllocInst {
        return AllocInst(memType: storedType, irName: irName)
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}

/**
 Store into a memory location
 
 `store %0 in %a: %*Int`
 */
final class StoreInst : Inst {
    private(set) var address: PtrOperand, value: Operand
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(address: LValue, value: Value) {
        self.init(address: PtrOperand(address), value: Operand(value))
    }
    
    private init(address: PtrOperand, value: Operand) {
        self.address = address
        self.value = value
        self.args = [value, address]
        initialiseArgs()
    }
    
    var type: Type? { return address.type }
    
    var hasSideEffects: Bool {
        // it has side effects if someone else is using it
        // TODO: should look through dominating blocks for uses, uses before this inst should not be counted
//        return !address.uses.filter { $0 !== address }.isEmpty
        return true
    }
    
    var vir: String {
        return "store \(value.name) in \(address.valueName)\(useComment) // id: \(name)"
    }
    
    func copy() -> StoreInst {
        return StoreInst(address: address.formCopy(), value: value.formCopy())
    }
    
    func setArgs(_ args: [Operand]) {
        (value, address) = (args[0], args[1] as! PtrOperand)
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}
/**
 Load from a memory location
 
 `%a = load %0: %*Int`
 */
final class LoadInst : Inst {
    var type: Type? { return address.memType }
    private(set) var address: PtrOperand
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(address: LValue, irName: String? = nil) {
        self.init(address: PtrOperand(address), irName: irName)
    }
    
    private init(address: PtrOperand, irName: String?) {
        self.address = address
        self.args = [address]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = load \(address.valueName)\(useComment)"
    }
    
    func copy() -> LoadInst {
        return LoadInst(address: address.formCopy(), irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        address = args[0] as! PtrOperand
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}
/**
 Bitcast a memory location
 
 `%a = bitcast %0:%*Int to %*Builtin.Int`
 */
final class BitcastInst : Inst, LValue {
    var pointerType: BuiltinType { return BuiltinType.pointer(to: newType) }
    var type: Type? { return pointerType }
    var memType: Type? { return newType }
    /// The operand of the cast
    private(set) var address: PtrOperand
    /// The new memory type of the cast
    private(set) var newType: ModuleType
    
    var uses: [Operand] = []
    var args: [Operand]
    
    /// - note: the ptr will have type newType*
    convenience init(address: LValue, newType: ModuleType, irName: String? = nil) {
        self.init(address: PtrOperand(address), newType: newType, irName: irName)
    }
    
    private init(address op: PtrOperand, newType: ModuleType, irName: String?) {
        self.address = op
        self.newType = newType
        args = [op]
        initialiseArgs()
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = bitcast \(address.valueName) to \(pointerType.explicitName)\(useComment)"
    }
    
    func copy() -> BitcastInst {
        return BitcastInst(address: address.formCopy(), newType: newType, irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        address = args[0] as! PtrOperand
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}

/// Destroys the value stored in this addr; it frees existential buffers,
/// and calls destructors of any elements stored in it
final class DestroyAddrInst : Inst {
    var addr: PtrOperand
    
    var type: Type? { return nil }
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(addr: LValue, irName: String? = nil) throws {
        self.init(addr: PtrOperand(addr), irName: irName)
    }
    
    private init(addr: PtrOperand, irName: String?) {
        self.addr = addr
        self.args = [addr]
        initialiseArgs()
        self.irName = irName
    }
    
    var hasSideEffects: Bool { return true }
    
    var vir: String {
        return "destroy_addr \(addr.valueName)\(useComment) // id: \(name)"
    }
    
    func copy() -> DestroyAddrInst {
        return DestroyAddrInst(addr: addr.formCopy(), irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        addr = args[0] as! PtrOperand
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

/// Same as `DestroyAddrInst` but can operate on a value
final class DestroyValInst : Inst {
    var val: Operand
    
    var type: Type? { return nil }
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(val: Value, irName: String? = nil) throws {
        self.init(val: Operand(val), irName: irName)
    }
    
    private init(val: Operand, irName: String?) {
        self.val = val
        self.args = [val]
        initialiseArgs()
        self.irName = irName
    }
    
    var hasSideEffects: Bool { return true }
    
    var vir: String {
        return "destroy_val \(val.valueName)\(useComment) // id: \(name)"
    }
    
    func copy() -> DestroyValInst {
        return DestroyValInst(val: val.formCopy(), irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        val = args[0]
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

final class CopyAddrInst : Inst {
    var addr: PtrOperand
    var outAddr: PtrOperand
    
    var type: Type? { return nil }
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(addr: LValue, out: LValue, irName: String? = nil) throws {
        self.init(addr: PtrOperand(addr), out: PtrOperand(out), irName: irName)
    }
    
    private init(addr: PtrOperand, out: PtrOperand, irName: String?) {
        self.addr = addr
        self.outAddr = out
        self.args = [addr, out]
        initialiseArgs()
        self.irName = irName
    }
    var hasSideEffects: Bool { return true }
    
    var vir: String {
        return "copy_addr \(addr.valueName) to \(outAddr.valueName) // id: \(name)"
    }
    
    func copy() -> CopyAddrInst {
        return CopyAddrInst(addr: addr.formCopy(), out: outAddr.formCopy(), irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        addr = args[0] as! PtrOperand
        outAddr = args[1] as! PtrOperand
    }
    var parentBlock: BasicBlock?
    var irName: String?
}
final class DeallocStackInst : Inst {
    private(set) var address: PtrOperand
    
    var type: Type? { return nil }
    
    var uses: [Operand] = []
    var args: [Operand]
    
    convenience init(address: LValue, irName: String? = nil) {
        self.init(address: PtrOperand(address), irName: irName)
    }
    
    private init(address: PtrOperand, irName: String?) {
        self.address = address
        self.args = [address]
        initialiseArgs()
        self.irName = irName
    }
    
    var hasSideEffects: Bool { return true }
    
    var vir: String {
        return "dealloc_stack \(address.valueName) // id: \(name)"
    }
    
    func copy() -> DeallocStackInst {
        return DeallocStackInst(address: address.formCopy(), irName: irName)
    }
    
    func setArgs(_ args: [Operand]) {
        address = args[0] as! PtrOperand
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}

