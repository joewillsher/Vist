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
    var parameters: [Operand]?
    var instructions: [Inst]
    unowned var parentFunction: Function
    
    init(name: String, parameters: [Operand]?, parentFunction: Function) {
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
        p.parentBlock = self
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
    
    /// Returns the instruction using the operand
    func userOfOperand(operand: Operand) -> Inst? {
        let f = instructions.indexOf { inst in inst.args.contains { arg in arg === operand } }
        return f.map { instructions[$0] }
    }
    
    var module: Module { return parentFunction.module }
}

extension Builder {
    
    /// Appends this block to the function and sets it to the insert point
    func addBasicBlock(name: String, params: [Operand]? = nil) throws -> BasicBlock {
        guard let function = insertPoint.function, let b = function.blocks where !b.isEmpty else { throw VHIRError.noFunctionBody }
        let bb = BasicBlock(name: name, parameters: params, parentFunction: function)
        function.blocks?.append(bb)
        try setInsertPoint(bb)
        return bb
    }
}


final class BBParam: Value {
    var irName: String?
    var type: Ty?
    weak var parentBlock: BasicBlock!
    var uses: [Operand] = []
    
    init(irName: String, type: Ty) {
        self.irName = irName
        self.type = type
    }
}

