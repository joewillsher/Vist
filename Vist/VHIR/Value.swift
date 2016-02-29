//
//  Value.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class Operand: Value {
    var value: Value?
    
    init(_ value: Value) {
        self.value = value
        value.addUse(self)
    }
    
    deinit {
        value?.removeUse(self)
    }
    
    var irName: String? {
        get { return value?.irName }
        set { value?.irName = newValue }
    }
    var type: Type? { return value?.type }
    var parentBlock: BasicBlock? { return value?.parentBlock }
    var uses: [Operand] {
        get { return value?.uses ?? [] }
        set { value?.uses = newValue }
    }
}

/// A value, instruction results, literals, etc
protocol Value: VHIR {
    var irName: String? { get set }
    var type: Type? { get }
    weak var parentBlock: BasicBlock? { get }
    var uses: [Operand] { get set }
}

extension Inst {
    
    func removeFromParent() throws {
        removeAllUses()
        try parentBlock?.remove(self)
    }
    
}

extension Value {
    
    func removeAllUses() {
        for use in uses { use.value = nil }
        uses.removeAll()
    }
    
    func addUse(use: Operand) {
        uses.append(use)
    }
    
    func removeUse(use: Operand) {
        if let i = uses.indexOf({$0 === self}) { uses.removeAtIndex(i) }
    }
    
    func replaceAllUsesWith(val: Value) {
        let u = uses
        removeAllUses()
        
        for use in u {
            use.value = val
        }
    }
    
    
    
    func getInstNumber() -> String? {
        guard let blocks = parentBlock?.parentFunction.blocks else { return nil }
        
        var count = 0
        blockLoop: for block in blocks {
            for inst in block.instructions {
                if case let o as Operand = self where o.value === inst { break blockLoop }
                if inst === self { break blockLoop }
                if inst.irName == nil { count += 1 }
            }
        }
        
        return String(count)
    }
    var name: String {
        get { return irName ?? getInstNumber() ?? "<null>" }
        set { irName = newValue }
    }
    var vhir: String { return valueName }    
}
