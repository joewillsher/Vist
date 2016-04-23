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
    
    private init(memType: Type, irName: String?) {
        self.storedType = memType
        super.init(args: [], irName: irName)
    }
    
    override var type: Type? { return BuiltinType.pointer(to: storedType) }
    var memType: Type? { return storedType }
    
    override var instVIR: String {
        return "\(name) = alloc \(storedType) \(useComment)"
    }
}
/**
 Store into a memory location
 
 `store %0 in %a: %*Int`
 */
final class StoreInst : InstBase {
    override var type: Type? { return address.type }
    private(set) var address: PtrOperand, value: Operand
    
    private init(address: PtrOperand, value: Operand) {
        self.address = address
        self.value = value
        super.init(args: [value, address], irName: nil)
    }
    
    override var hasSideEffects: Bool { return true }
    
    override var instVIR: String {
        return "store \(value.name) in \(address) \(useComment)"
    }
}
/**
 Load from a memory location
 
 `%a = load %0: %*Int`
 */
final class LoadInst : InstBase {
    override var type: Type? { return address.memType }
    private(set) var address: PtrOperand
    
    private init(address: PtrOperand, irName: String?) {
        self.address = address
        super.init(args: [address], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = load \(address) \(useComment)"
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
    
    private init(address: PtrOperand, newType: Type, irName: String?) {
        self.address = address
        self.newType = newType
        super.init(args: [address], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = bitcast \(address) to \(pointerType) \(useComment)"
    }
}

extension Builder {
    
    func buildAlloc(type: Type, irName: String? = nil) throws -> AllocInst {
        let ty = type.usingTypesIn(module)
        return try _add(AllocInst(memType: ty, irName: irName))
    }
    func buildStore(val: Operand, in address: PtrOperand) throws -> StoreInst {
        guard val.type == address.memType else { fatalError() }
        return try _add(StoreInst(address: address, value: val))
    }
    func buildLoad(from address: PtrOperand, irName: String? = nil) throws -> LoadInst {
        return try _add(LoadInst(address: address, irName: irName))
    }
    /// Builds a bitcast instruction
    /// - parameter newType: The memory type to be cast to -- the ptr will have type newType*
    func buildBitcast(from address: PtrOperand, newType: Type, irName: String? = nil) throws -> BitcastInst {
        return try _add(BitcastInst(address: address, newType: newType.usingTypesIn(module), irName: irName))
    }
    
}




