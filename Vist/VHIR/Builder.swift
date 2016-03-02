//
//  Builder.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class Builder {
    weak var module: Module?
    var inst: Inst?
    var block: BasicBlock?
    var function: Function?
    
    init(module: Module) {
        self.module = module
    }
}


extension Builder {
    
    func setInsertPoint(node: VHIR) throws {
        switch node {
        case let f as Function:
            guard let b = try? f.getLastBlock() else {
                function = f
                try addBasicBlock("entry")
                return
            }
            inst = b.instructions.last
            block = b
            function = f
            
        case let b as BasicBlock:
            inst = b.instructions.last
            block = b
            function = b.parentFunction
            
        case let i as Inst:
            inst = i
            block = i.parentBlock
            function = i.parentBlock?.parentFunction
        default:
            throw VHIRError.cannotMoveBuilderHere
        }
    }
    
    private func addToCurrentBlock(inst: Inst) throws {
        guard let block = block else { throw VHIRError.noParentBlock }
        inst.parentBlock = block
        try block.insert(inst)
        try setInsertPoint(inst)
    }
    
    func addBasicBlock(name: String, params: [Value]? = nil) throws -> BasicBlock {
        if let function = function, let b = function.blocks where !b.isEmpty {
            let bb = BasicBlock(name: name, parameters: params, parentFunction: function)
            function.blocks?.append(bb)
            block = bb
            return bb
        }
        else if let function = function {
            let fnParams = zip(function.paramNames, function.type.params).map(BBParam.init).map { $0 as Value }
            let bb = BasicBlock(name: name, parameters: fnParams + (params ?? []), parentFunction: function)
            function.blocks = [bb]
            block = bb
            return bb
        }
        else {
            throw VHIRError.noFunctionBody
        }
    }
    
    func createFunction(name: String, type: FnType, paramNames: [String]) throws -> Function {
        let f = Function(name: name, type: type, paramNames: paramNames)
        f.parentModule = module
        module?.addFunction(f)
        try setInsertPoint(f)
        return f
    }
    
    func createBuiltin(i: BuiltinInst, l: Operand, r: Operand, irName: String? = nil) throws -> BuiltinBinaryInst {
        let binInst = BuiltinBinaryInst(inst: i, l: l, r: r, irName: irName)
        try addToCurrentBlock(binInst)
        return binInst
    }
    
    func createReturnVoid() throws -> ReturnInst {
        return try createReturn(Operand(VoidValue()))
    }
    func createReturn(value: Operand, irName: String? = nil) throws -> ReturnInst {
        let retInst = ReturnInst(value: value, parentBlock: block, irName: irName)
        try addToCurrentBlock(retInst)
        return retInst
    }
    
    func createStruct(type: StructType, values: [Operand], irName: String? = nil) throws -> StructInitInst {
        let s = StructInitInst(type: type, args: values, irName: irName)
        try addToCurrentBlock(s)
        return s
    }
    
    
    private func buildBuiltinInt(val: Int, irName: String? = nil) throws-> IntLiteralInst {
        let v = IntLiteralInst(val: val, irName: irName)
        try addToCurrentBlock(v)
        return v
    }
    
    func buildIntLiteral(val: Int, irName: String? = nil) throws-> StructInitInst {
        let v = try buildBuiltinInt(val, irName: irName.map { "\($0).value" })
        return try createStruct(StdLib.intType, values: [Operand(v)], irName: irName)
    }
    
    func buildVariableDecl(value: Operand, irName: String? = nil) throws -> VariableInst {
        let v = VariableInst(value: value, irName: irName)
        try addToCurrentBlock(v)
        return v
    }
}
