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
    
    var instHasSideEffects: Bool {
        // it has side effects if someone else is using it
        // TODO: should look through dominating blocks for uses, uses before this inst should not be counted
//        return !address.uses.filter { $0 !== address }.isEmpty
        return true
    }
    
    var vir: String {
        return "store \(value.name) in \(address.valueName)\(useComment)"
    }
    
    func copy() -> StoreInst {
        return StoreInst(address: address.formCopy(), value: value.formCopy())
    }
    
    func setArgs(args: [Operand]) {
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
    
    func setArgs(args: [Operand]) {
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
    private(set) var newType: TypeAlias
    
    var uses: [Operand] = []
    var args: [Operand]
    
    /// - note: the ptr will have type newType*
    convenience init(address: LValue, newType: TypeAlias, irName: String? = nil) {
        self.init(address: PtrOperand(address), newType: newType, irName: irName)
    }
    
    private init(address op: PtrOperand, newType: TypeAlias, irName: String?) {
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
    
    func setArgs(args: [Operand]) {
        address = args[0] as! PtrOperand
    }
    
    weak var parentBlock: BasicBlock?
    var irName: String?
}





