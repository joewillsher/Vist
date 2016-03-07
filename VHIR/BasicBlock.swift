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
    var instructions: [Inst], predecessors: [BasicBlock]
    unowned var parentFunction: Function
    var loweredBlock: LLVMValueRef = nil
    
    init(name: String, parameters: [Operand]?, parentFunction: Function, predecessors: [BasicBlock]) {
        self.name = name
        self.parameters = parameters
        self.instructions = []
        self.parentFunction = parentFunction
        self.predecessors = predecessors
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
    
    func removeFromParent() throws {
        parentFunction.blocks?.removeAtIndex(try parentFunction.indexOfBlock(self))
    }
    func moveAfter(after: BasicBlock) throws {
        try removeFromParent()
        parentFunction.blocks?.insert(self, atIndex: try parentFunction.indexOfBlock(after).successor())
    }
    func moveBefore(before: BasicBlock) throws {
        try removeFromParent()
        parentFunction.blocks?.insert(self, atIndex: try parentFunction.indexOfBlock(before).predecessor())
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
    ///
    /// - parameter name:   The block name
    /// - parameter params: Params to pass into the block
    /// - parameter predecessor:    Define an explicit predecessor block -- if none
    ///                             are defined it will use the fn's last block
    func addBasicBlock(name: String, params: [Operand]? = nil, predecessor: BasicBlock? = nil) throws -> BasicBlock {
        guard let function = insertPoint.function, let b = function.blocks where !b.isEmpty else { throw VHIRError.noFunctionBody }
        
        let pred =  (predecessor ?? b.last).map { [$0] } ?? []
        let bb = BasicBlock(name: name, parameters: params, parentFunction: function, predecessors: pred)
        function.blocks?.append(bb)
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

