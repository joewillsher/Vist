//
//  Function.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

private final class FunctionImpl {
    var blocks: [BasicBlock]
    var params: [BBParam]
    
    init(paramNames: [String], type: FnType, blocks: [BasicBlock]) {
        params = zip(paramNames, type.params).map(BBParam.init)
        self.blocks = blocks
    }
}


/// A VHIR function, has a type and ismade of a series
/// of basic blocks
final class Function: VHIRElement {
    var name: String
    var type: FnType
    private var impl: FunctionImpl?
    private unowned var parentModule: Module
    
    var loweredFunction: LLVMValueRef = nil
    
    private init(name: String, type: FnType, module: Module) {
        self.name = name
        self.parentModule = module
        self.type = type
    }
    
    var hasBody: Bool { return (impl?.blocks.count != 0) ?? false }
    var blocks: [BasicBlock]? {
        get { return impl?.blocks }
        set { _ = newValue.map { impl?.blocks = $0 } }
    }
    var params: [BBParam]? { return impl?.params }
    
    func getEntryBlock() throws -> BasicBlock {
        guard let first = impl?.blocks.first else { throw VHIRError.noFunctionBody }
        return first
    }
    func getLastBlock() throws -> BasicBlock {
        guard let last = impl?.blocks.last else { throw VHIRError.noFunctionBody }
        return last
    }
    
    func paramNamed(name: String) throws -> Operand {
        guard let p = try impl?.blocks.first?.paramNamed(name) else { throw VHIRError.noParamNamed(name) }
        return p
    }
    
    func dumpIR() { if loweredFunction != nil { LLVMDumpValue(loweredFunction) } else { print("\(name) <NULL>") } }
    
    var module: Module { return parentModule }
}

extension Builder {
    
    /// Builds a function and adds it to the module. Declares a body and entry block
    func buildFunction(name: String, type: FnType, paramNames: [String]) throws -> Function {
        let f = try createFunctionPrototype(name, type: type)
        try buildFunctionEntryBlock(f, paramNames: paramNames)
        try setInsertPoint(f)
        return f
    }
    
    /// Builds an entry block for the function, passes the params of the function in
    func buildFunctionEntryBlock(function: Function, paramNames: [String]) throws {
        function.impl = FunctionImpl(paramNames: paramNames, type: function.type, blocks: [])
        let bb = BasicBlock(name: "entry", parameters: function.params!.map(Operand.init), parentFunction: function)
        function.blocks = [bb]
        try setInsertPoint(bb)
    }
    
    /// Creates function prototype an adds to module
    func createFunctionPrototype(name: String, type: FnType) throws -> Function {
        let f = Function(name: name, type: type.usingTypesIn(module) as! FnType, module: module)
        module.addFunction(f)
        return f
    }
    
}




