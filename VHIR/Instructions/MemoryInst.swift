//
//  Memory.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class AllocInst : InstBase, Value {
    var storedType: Ty
    
    private init(memType: Ty, irName: String?) {
        self.storedType = memType
        super.init(args: [], irName: irName)
    }
    
    override var type: Ty? { return BuiltinType.pointer(to: storedType) }
    var memType: Ty? { return storedType }
    
    override var instVHIR: String {
        return "\(name) = alloc \(storedType) \(useComment)"
    }
}
final class StoreInst : InstBase {
    override var type: Ty? { return address.type }
    private(set) var address: PtrOperand, value: Operand
    
    private init(address: PtrOperand, value: Operand) {
        self.address = address
        self.value = value
        super.init(args: [value, address], irName: nil)
    }
    
    // TODO: rename 'can remove' or something
    override var hasSideEffects: Bool { return true }
    
    override var instVHIR: String {
        return "store \(value.name) in \(address) \(useComment)"
    }
}
final class LoadInst : InstBase {
    override var type: Ty? { return address.memType }
    private(set) var address: PtrOperand
    
    private init(address: PtrOperand, irName: String?) {
        self.address = address
        super.init(args: [address], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = load \(address) \(useComment)"
    }
}
final class BitcastInst : InstBase, Value {
    var pointerType: BuiltinType { return BuiltinType.pointer(to: newType) }
    override var type: Ty? { return pointerType }
    var memType: Ty? { return newType }
    /// The operand of the cast
    private(set) var address: PtrOperand
    /// The new memory type of the cast
    private(set) var newType: Ty
    
    private init(address: PtrOperand, newType: Ty, irName: String?) {
        self.address = address
        self.newType = newType
        super.init(args: [address], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = bitcast \(address) to \(pointerType) \(useComment)"
    }
}

extension Builder {
    
    func buildAlloc(type: Ty, irName: String? = nil) throws -> AllocInst {
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
    func buildBitcast(from address: PtrOperand, newType: Ty, irName: String? = nil) throws -> BitcastInst {
        return try _add(BitcastInst(address: address, newType: newType, irName: irName))
    }
    
}




