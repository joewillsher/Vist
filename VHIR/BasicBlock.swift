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

/// A collection of instructions
///
/// Params are passed into the phi nodes as
/// parameters ala swift
final class BasicBlock: VHIRElement {
    var name: String
    var instructions: [Inst] = []
    unowned var parentFunction: Function
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
    
    func insert(inst: Inst, after: Inst? = nil) throws {
        if let after = after {
            instructions.insert(inst, atIndex: try indexOfInst(after).successor())
        }
        else {
            instructions.append(inst)
        }
    }
    func paramNamed(name: String) throws -> Operand {
        
        for application in applications {
            switch application {
            case .entry(let params):
                guard let i = params.indexOf({ $0.paramName == name }) else { throw VHIRError.noParamNamed(name) }
                return Operand(params[i])
                
            case .body:
                guard let operand = parameters?.indexOf({$0.paramName == name}) else { throw VHIRError.noParamNamed(name) }
                return Operand(parameters![operand])
            }
        }
        throw VHIRError.noParamNamed(name)
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
    
    
    
    // instructions
    func set(inst: Inst, newValue: Inst) throws {
        instructions[try indexOfInst(inst)] = newValue
    }
    func remove(inst: Inst) throws {
        instructions.removeAtIndex(try indexOfInst(inst))
    }
    
    // moving and structure
    /// Returns the instruction using the operand
    func userOfOperand(operand: Operand) -> Inst? {
        let f = instructions.indexOf { inst in inst.args.contains { arg in arg === operand } }
        return f.map { instructions[$0] }
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
    
    
    var module: Module { return parentFunction.module }
}

extension Builder {
    
    /// Appends this block to the function. Thus does not modify the insert
    /// point, make any breaks to this block, or apply any params to it
    func addBasicBlock(name: String, parameters: [BBParam]? = nil) throws -> BasicBlock {
        guard let function = insertPoint.function, let b = function.blocks where !b.isEmpty else { throw VHIRError.noFunctionBody }
        
        let bb = BasicBlock(name: name, parameters: parameters, parentFunction: function)
        function.blocks?.append(bb)
        return bb
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
        set { _ = newValue.map { paramName = $0 } }
    }
}

