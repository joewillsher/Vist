//
//  BasicBlock.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// The application of a block -- can either be
/// and entry block or a block you break to
private enum BlockApplication {
    case entry(params: [BBParam])
    case body(predecessor: BasicBlock, params: [Operand]?)
    
    var params: [Operand]? {
        switch self {
        case .entry(let params): return params.map(Operand.init)
        case .body(_, let params): return params
        }
    }
    var predecessor: BasicBlock? {
        switch self {
        case .body(let predecessor, _): return predecessor
        case .entry: return nil
        }
    }
}

final class BBParam: Value {
    var paramName: String
    var type: Ty?
    weak var parentBlock: BasicBlock!
    var uses: [Operand] = []
    
    init(paramName: String, type: Ty) {
        self.paramName = paramName
        self.type = type
    }
    var irName: String? {
        get { return paramName }
        set { if let v = newValue { paramName = v } }
    }
}


/// A collection of instructions
///
/// Params are passed into the phi nodes as
/// parameters ala swift
final class BasicBlock: VHIRElement {
    var name: String
    private(set) var instructions: [Inst] = []
    weak var parentFunction: Function!
    var loweredBlock: LLVMValueRef = nil
    
    // block params are `BBParam`s
    // block args are `Operand`s
    let parameters: [BBParam]?
    private var applications: [BlockApplication]
    var predecessors: [BasicBlock] { return applications.flatMap { $0.predecessor } }
    
    init(name: String, parameters: [BBParam]?, parentFunction: Function) {
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
    
    func paramNamed(name: String) throws -> BBParam {
        guard let param = parameters?.find({ $0.paramName == name }) else { throw VHIRError.noParamNamed(name) }
        return param
    }
    
    /// Adds the entry application to a block -- used by Function builder
    func addEntryApplication(args: [BBParam]) throws {
        applications.insert(.entry(params: args), atIndex: 0)
    }
    
    /// Applies the parameters to this block, `from` sepecifies the
    /// predecessor to associate these `params` with
    func addApplication(from block: BasicBlock, args: [Operand]?) throws {
        // make sure application is correctly typed
        if let vals = parameters?.optionalMap({$0.type}) {
            guard let equal = args?.optionalMap({ $0.type })?.elementsEqual(vals, isEquivalent: ==)
                where equal else { throw VHIRError.paramsNotTyped }
        }
        else { guard args == nil else { throw VHIRError.paramsNotTyped }}
        
        applications.append(.body(predecessor: block, params: args))
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
    
    // instructions
    func set(inst: Inst, newValue: Inst) throws {
        instructions[try indexOfInst(inst)] = newValue
    }
    func remove(inst: Inst) throws {
        instructions.removeAtIndex(try indexOfInst(inst))
    }

    
    var module: Module { return parentFunction.module }
}

extension Builder {
    
    /// Appends this block to the function. Thus does not modify the insert
    /// point, make any breaks to this block, or apply any params to it
    func appendBasicBlock(name: String, parameters: [BBParam]? = nil) throws -> BasicBlock {
        guard let function = insertPoint.function, let b = function.blocks where !b.isEmpty else { throw VHIRError.noFunctionBody }
        
        let bb = BasicBlock(name: name, parameters: parameters, parentFunction: function)
        bb.appendToParent()
        return bb
    }
}


