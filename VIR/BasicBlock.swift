//
//  BasicBlock.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/**
 A collection of instructions
 
 Params are passed between blocks in parameters, blocks can
 reference insts in other blocks. The entry block of a function
 is called with params of the function
 */
final class BasicBlock : VIRElement {
    /// A name for the block
    var name: String
    /// The collection of instructions in this block
    fileprivate(set) var instructions: [Inst] = []
    
    weak var parentFunction: Function?
    var loweredBlock: LLVMBasicBlock? = nil
    
    /// The params passed into the block, a list of params
    var parameters: [Param]?

    /// The applications to this block. A list of predecessors
    /// and the arguments they applied
    fileprivate(set) var applications: [BlockApplication]
    
    /// A list of the predecessor blocks. These blocks broke to `self`
    var predecessors: [BasicBlock] { return applications.flatMap { application in application.predecessor } }
    var successors: [BasicBlock] = []
    
    init(name: String, parameters: [Param]?, parentFunction: Function?) {
        self.name = name
        self.parameters = parameters
        self.parentFunction = parentFunction
        self.applications = []
    }
    
    /// The application of a block, how you jump into the block. `nil` preds
    /// and breakInst implies it it an entry block
    final class BlockApplication {
        var args: [Operand]?, predecessor: BasicBlock?, breakInst: BreakInstruction?
        
        init(params: [Operand]?, predecessor: BasicBlock?, breakInst: BreakInstruction?) {
            self.args = params
            self.predecessor = predecessor
            self.breakInst = breakInst
        }
        
    }
}


extension BasicBlock {
    
    func insert(inst: Inst, after: Inst) throws {
        let i = try index(of: after)
        instructions.insert(inst, at: instructions.index(after: i))
        inst.parentBlock = self
    }
    func append(_ inst: Inst) {
        instructions.append(inst)
        inst.parentBlock = self
    }
    
    /// Get param named `name` or throw
    func param(named name: String) throws -> Param {
        guard let param = parameters?.first(where: { param in param.paramName == name }) else { throw VIRError.noParamNamed(name) }
        return param
    }
    
    /// Get an array of the arguments that were applied for `param`
    func blockArgs(for param: Param) throws -> [BlockOperand] {
        
        guard let paramIndex = parameters?.index(where: { blockParam in blockParam === param}),
            let args = applications.optionalMap({ application in application.args?[paramIndex] as? BlockOperand })
            else { throw VIRError.noParamNamed(param.name) }
        
        return args
    }
    
    /// Adds the entry application to a block -- used by Function builder
    func addEntryApplication(args: [Param]) throws {
        applications.insert(.entry(params: args), at: 0)
    }
    
    /// Applies the parameters to this block, `from` sepecifies the
    /// predecessor to associate these `params` with
    func addApplication(from block: BasicBlock, args: [BlockOperand]?, breakInst: BreakInstruction) throws {
        
        // make sure application is correctly typed
        if let vals = try parameters?.map(getType(of:)) {
            guard let equal = try args?.map(getType(of:)).elementsEqual(vals, by: ==), equal else {
                throw VIRError.paramsNotTyped
            }
        }
        else { guard args == nil else { throw VIRError.paramsNotTyped }}
        
        applications.append(.body(predecessor: block, params: args, breakInst: breakInst))
        block.successors.append(self)
    }
    
    func removeApplication(break breakInst: BreakInstruction) throws {
        
        guard let i = applications.index(where: { application in
            application.breakInst === breakInst
        }) else { fatalError() }
        
        applications.remove(at: i)
        
        // remove these blocks as successors
        for succ in breakInst.successors {
            let i = successors.index { $0 === succ.block }!
            successors.remove(at: i)
        }
    }
    
    /// Helper, the index of `inst` in self or throw
    func index(of inst: Inst) throws -> Int {
        guard let i = instructions.index(where: { $0 === inst }) else { throw VIRError.instNotInBB }
        return i
    }
    
    // instructions
    func set(inst: Inst, newValue: Inst) throws {
        instructions[try index(of: inst)] = newValue
    }
    
    /// Remove `inst` from self
    /// - precondition: `inst` is a member of `self`
    func remove(inst: Inst) throws {
        try instructions.remove(at: index(of: inst))
        inst.parentBlock = nil
    }
    
    /// Adds a param to the block
    /// - precondition: This block is an entry block
    func addEntryBlockParam(_ param: Param) throws {
        guard let entry = applications.first, entry.isEntry else { fatalError() }
        parameters?.append(param)
        entry.args?.append(Operand(param))
    }
    
    /// - returns: whether this block's instructions contains `inst`
    func contains(_ inst: Inst) -> Bool {
        return instructions.contains { $0 === inst }
    }
    
    var module: Module { return parentFunction!.module }
    func dump() { print(vir) }
    
    
    /// Creates a parentless basic block which is a copy of self
    func copy() -> BasicBlock {
        let params = parameters?.map { $0.copy() }
        return BasicBlock(name: name, parameters: params, parentFunction: nil)
    }
}

extension BasicBlock.BlockApplication {
    /// Get an entry instance
    static func entry(params: [Param]?) -> BasicBlock.BlockApplication {
        return BasicBlock.BlockApplication(params: params?.map(FunctionOperand.init(param:)), predecessor: nil, breakInst: nil)
    }
    /// Get a non entry instance
    static func body(predecessor: BasicBlock, params: [BlockOperand]?, breakInst: BreakInstruction) -> BasicBlock.BlockApplication {
        return BasicBlock.BlockApplication(params: params, predecessor: predecessor, breakInst: breakInst)
    }
    /// is self an entry application
    var isEntry: Bool { return predecessor == nil }
}

extension Builder {
    
    /// Appends this block to the function. Thus does not modify the insert
    /// point, make any breaks to this block, or apply any params to it
    func appendBasicBlock(name: String, parameters: [Param]? = nil) throws -> BasicBlock {
        guard let function = insertPoint.function, let b = function.blocks, !b.isEmpty else { throw VIRError.noFunctionBody }
        
        let bb = BasicBlock(name: name, parameters: parameters, parentFunction: function)
        function.append(block: bb)
        for p in parameters ?? [] { p.parentBlock = bb }
        return bb
    }
}


extension Inst {
    
    /// The successor to `self`
    func successor() throws -> Inst? {
        return try parentBlock.map { parent in
            let x = try parent.index(of: self)
            return parent.instructions[parent.instructions.index(after: x)]
        }
    }
    /// The predecessor of `self`
    func predecessor() throws -> Inst? {
        return try parentBlock.map { parent in
            let x = try parent.index(of: self)
            return parent.instructions[parent.instructions.index(before: x)]
        }
    }
    
}
