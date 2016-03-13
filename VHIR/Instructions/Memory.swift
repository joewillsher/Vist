//
//  Memory.swift
//  Vist
//
//  Created by Josef Willsher on 13/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class AllocInst: InstBase {
    override var type: Ty? { return BuiltinType.pointer(to: address.memType) }
    private(set) var address: Address
    
    private init(address: Address, irName: String?) {
        self.address = address
        super.init()
        self.args = []
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = alloc %\(address.memType) \(useComment)"
    }
}
final class StoreInst: InstBase {
    override var type: Ty? { return BuiltinType.pointer(to: address.memType) }
    private(set) var address: Address, value: Operand
    
    private init(address: Address, value: Operand) {
        self.address = address
        self.value = value
        super.init()
        self.args = [value]
    }
    
    override var hasSideEffects: Bool { return true }
    override var instVHIR: String {
        return "\(name) = store \(value.name) in \(address.name) \(useComment)"
    }
}
final class LoadInst: InstBase {
    override var type: Ty? { return BuiltinType.pointer(to: address.memType) }
    private(set) var address: Address
    
    private init(address: Address, irName: String?) {
        self.address = address
        super.init()
        self.args = []
        self.irName = irName
    }
    
    override var instVHIR: String {
        return "\(name) = load \(address) \(useComment)"
    }
}


extension Builder {
    
    func buildAlloc(type: Ty, irName: String? = nil) throws -> AllocInst {
        let address = addressOfType(type.usingTypesIn(module))
        let v = AllocInst(address: address, irName: irName)
        try addToCurrentBlock(v)
        return v
    }
    func buildStore(val: Operand, to address: Address) throws -> StoreInst {
        let v = StoreInst(address: address, value: val)
        try addToCurrentBlock(v)
        return v
    }
    func buildLoad(from address: Address, irName: String? = nil) throws -> LoadInst {
        let v = LoadInst(address: address, irName: irName)
        try addToCurrentBlock(v)
        return v
    }
}



