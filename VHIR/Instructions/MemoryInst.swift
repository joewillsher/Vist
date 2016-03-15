//
//  Memory.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class AllocInst: InstBase, LValue {
    override var type: Ty? { return memType }
    var memType: Ty
    
    private init(memType: Ty, irName: String?) {
        self.memType = memType
        super.init(args: [], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = alloc \(memType) \(useComment)"
    }
}
final class StoreInst: InstBase {
    override var type: Ty? { return address.type }
    private(set) var address: PtrOperand, value: Operand
    
    private init(address: PtrOperand, value: Operand) {
        self.address = address
        self.value = value
        super.init(args: [value, address], irName: nil)
    }
    
    override var hasSideEffects: Bool { return true }
    override var instVHIR: String {
        return "store \(value.name) in \(address) \(useComment)"
    }
}
final class LoadInst: InstBase {
    override var type: Ty? { return address.type }
    private(set) var address: PtrOperand
    
    private init(address: PtrOperand, irName: String?) {
        self.address = address
        super.init(args: [address], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = load \(address) \(useComment)"
    }
}


extension Builder {
    
    func buildAlloc(type: Ty, irName: String? = nil) throws -> AllocInst {
        let ty = type.usingTypesIn(module)
        let alloc = AllocInst(memType: ty, irName: irName)
        try addToCurrentBlock(alloc)
        return alloc
    }
    func buildStore(val: Operand, in address: PtrOperand) throws -> StoreInst {
        let store = StoreInst(address: address, value: val)
        try addToCurrentBlock(store)
        return store
    }
    func buildLoad(from address: PtrOperand, irName: String? = nil) throws -> LoadInst {
        let load = LoadInst(address: address, irName: irName)
        try addToCurrentBlock(load)
        return load
    }
    
}




