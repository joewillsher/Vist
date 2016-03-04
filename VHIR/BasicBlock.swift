//
//  BasicBlock.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A collection of instructions
///
/// Params are passed into the phi nodes as
/// parameters ala swift
final class BasicBlock: VHIRElement {
    var name: String
    var parameters: [Value]?
    var instructions: [Inst]
    var parentFunction: Function
    
    init(name: String, parameters: [Value]?, parentFunction: Function) {
        self.name = name
        self.parameters = parameters
        self.instructions = []
        self.parentFunction = parentFunction
    }
    
    func insert(inst: Inst, after: Inst? = nil) throws {
        if let after = after {
            instructions.insert(inst, atIndex: try indexOfInst(after).successor())
        }
        else {
            instructions.append(inst)
        }
    }
    func paramNamed(name: String) throws -> Operand {
        guard let i = parameters?.indexOf({$0.irName == name}), let p = parameters?[i] else { throw VHIRError.noParamNamed(name) }
        return Operand(p)
    }
    func set(inst: Inst, newValue: Inst) throws {
        instructions[try indexOfInst(inst)] = newValue
    }
    func remove(inst: Inst) throws {
        instructions.removeAtIndex(try indexOfInst(inst))
    }

    private func indexOfInst(inst: Inst) throws -> Int {
        guard let i = instructions.indexOf({ $0 === inst }) else { throw VHIRError.instNotInBB }
        return i
    }
    
    private func instAtIndex(index: Int) -> Inst {
        return instructions[index]
    }
    
    /// Returns the instruction using the operand
    func userOfOperand(operand: Operand) -> Inst? {
        let f = instructions.indexOf { inst in inst.args.contains { arg in arg === operand } }
        return f.map { instructions[$0] }
    }
}


final class BBParam: Value {
    var irName: String?
    var type: Ty?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(irName: String, type: Ty) {
        self.irName = irName
        self.type = type
    }
}

