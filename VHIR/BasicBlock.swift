//
//  BasicBlock.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// The application of a block -- can either be
/// and entry block or a block you break to
final class BlockApplication {
    
    static func entry(params: [Param]?) -> BlockApplication { return BlockApplication(params: params?.map(Operand.init), predecessor: nil) }
    static func body(predecessor: BasicBlock, params: [BlockOperand]?) -> BlockApplication { return BlockApplication(params: params, predecessor: predecessor) }
    
    var args: [Operand]?
    var predecessor: BasicBlock?
    
    var phi: LLVMValueRef?
    
    init(params: [Operand]?, predecessor: BasicBlock?) {
        self.args = params
        self.predecessor = predecessor
    }
    
    var isEntry: Bool { return predecessor == nil }
}



/// A collection of instructions
///
/// Params are passed between blocks in parameters, blocks can
/// reference insts in other blocks. The entry block of a function
/// is called with params of the function
final class BasicBlock: VHIRElement {
    var name: String
    private(set) var instructions: [Inst] = []
    weak var parentFunction: Function!
    var loweredBlock: LLVMValueRef = nil
    
    // block params are `Param`s
    // block args are `Operand`s
    let parameters: [Param]?
    private(set) var applications: [BlockApplication]
    var predecessors: [BasicBlock] { return applications.flatMap { $0.predecessor } }
    
    init(name: String, parameters: [Param]?, parentFunction: Function) {
        self.name = name
        self.parameters = parameters
        self.parentFunction = parentFunction
        applications = []
    }
    
    func insert(inst: Inst, after: Inst) throws {
        instructions.insert(inst, atIndex: try indexOfInst(after).successor())
    }
    func append(inst: Inst) {
        instructions.append(inst)
    }
    
    func paramNamed(name: String) throws -> Param {
        guard let param = parameters?.find({ $0.paramName == name }) else { throw VHIRError.noParamNamed(name) }
        return param
    }
    func appliedArgsForParam(param: Param) throws -> [BlockOperand] {
        
        guard let i = parameters?.indexOf({$0 === param}),
            let args = applications.optionalMap({ $0.args?[i] as? BlockOperand })
            else { throw VHIRError.noParamNamed(param.name) }
        
        return args
    }
    
    /// Adds the entry application to a block -- used by Function builder
    func addEntryApplication(args: [Param]) throws {
        applications.insert(.entry(args), atIndex: 0)
    }
    
    /// Applies the parameters to this block, `from` sepecifies the
    /// predecessor to associate these `params` with
    func addApplication(from block: BasicBlock, args: [BlockOperand]?) throws {
        // make sure application is correctly typed
        if let vals = parameters?.optionalMap({$0.type}) {
            guard let equal = args?.optionalMap({ $0.type })?.elementsEqual(vals, isEquivalent: ==)
                where equal else { throw VHIRError.paramsNotTyped }
        }
        else { guard args == nil else { throw VHIRError.paramsNotTyped }}
        
        applications.append(.body(block, params: args))
    }
    private func indexOfInst(inst: Inst) throws -> Int {
        guard let i = instructions.indexOf({ $0 === inst }) else { throw VHIRError.instNotInBB }
        return i
    }
    
    // instructions
    func set(inst: Inst, newValue: Inst) throws {
        instructions[try indexOfInst(inst)] = newValue
    }
    func remove(inst: Inst) throws {
        instructions.removeAtIndex(try indexOfInst(inst))
        inst.parentBlock = nil
    }
    
    var module: Module { return parentFunction.module }
}

extension Builder {
    
    /// Appends this block to the function. Thus does not modify the insert
    /// point, make any breaks to this block, or apply any params to it
    func appendBasicBlock(name name: String, parameters: [Param]? = nil) throws -> BasicBlock {
        guard let function = insertPoint.function, let b = function.blocks where !b.isEmpty else { throw VHIRError.noFunctionBody }
        
        let bb = BasicBlock(name: name, parameters: parameters, parentFunction: function)
        bb.appendToParent()
        for p in parameters ?? [] { p.parentBlock = bb }
        return bb
    }
}


