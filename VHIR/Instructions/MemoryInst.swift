//
//  Memory.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class Address: LValue {
    var irName: String? = nil
    let memType: Ty
    /// the allocation which created self
    private weak var allocation: AllocInst!
    
    var type: Ty? { return BuiltinType.pointer(to: memType) }
    
    private init(memType: Ty) {
        self.memType = memType
    }
    
    /// The block containing `self`
    weak var parentBlock: BasicBlock!
    
    var vhir: String { return allocation.valueName }
    
    var loweredAddress: LLVMValueRef = nil
    var uses: [Operand] = []
}


final class AllocInst: InstBase {
    override var type: Ty? { return BuiltinType.pointer(to: address.memType) }
    var address: Address
    
    private init(address: Address, irName: String?) {
        self.address = address
        super.init(args: [], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = alloc \(address.memType) \(useComment)"
    }
}
final class StoreInst: InstBase {
    override var type: Ty? { return BuiltinType.pointer(to: address.memType) }
    private(set) var address: Address, value: Operand
    
    private init(address: Address, value: Operand) {
        self.address = address
        self.value = value
        super.init(args: [value, Operand(address.allocation)], irName: nil)
//        self.uses.append(Operand(address.allocation))
    }
    
    override var hasSideEffects: Bool { return true }
    override var instVHIR: String {
        return "\(name) = store \(value.name) in \(address) \(useComment)"
    }
}
final class LoadInst: InstBase {
    override var type: Ty? { return BuiltinType.pointer(to: address.memType) }
    private(set) var address: Address
    
    private init(address: Address, irName: String?) {
        self.address = address
        super.init(args: [Operand(address.allocation)], irName: irName)
//        self.uses.append(Operand(address.allocation))
    }
    
    override var instVHIR: String {
        return "\(name) = load \(address) \(useComment)"
    }
}


extension Builder {
    
    func buildAlloc(type: Ty, irName: String? = nil) throws -> AllocInst {
        let address = addressOfType(type.usingTypesIn(module))
        let alloc = AllocInst(address: address, irName: irName)
        address.allocation = alloc
        try addToCurrentBlock(alloc)
        return alloc
    }
    func buildStore(val: Operand, to address: Address) throws -> StoreInst {
        let store = StoreInst(address: address, value: val)
        try addToCurrentBlock(store)
        return store
    }
    func buildLoad(from address: Address, irName: String? = nil) throws -> LoadInst {
        let load = LoadInst(address: address, irName: irName)
        try addToCurrentBlock(load)
        return load
    }
    
    private func addressOfType(type: Ty) -> Address {
        let addr = Address(memType: type)
        addr.parentBlock = insertPoint.block
        return addr
    }
}




