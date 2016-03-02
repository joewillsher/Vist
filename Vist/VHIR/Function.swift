//
//  Function.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

private final class FunctionImpl {
    var paramNames: [String]
    var blocks: [BasicBlock]
    
    init(paramNames: [String], blocks: [BasicBlock]) {
        self.paramNames = paramNames
        self.blocks = blocks
    }
}


/// A VHIR function, has a type and ismade of a series
/// of basic blocks
final class Function: VHIR {
    var name: String
    var type: FnType
    private var impl: FunctionImpl?
    unowned var parentModule: Module
    
    private init(name: String, type: FnType, module: Module) {
        self.name = name
        self.parentModule = module
        self.type = type.usingTypesIn(module)
    }
    
    var hasBody: Bool { return (impl?.blocks.count != 0) ?? false }
    var blocks: [BasicBlock]? {
        get { return impl?.blocks }
        set { _ = newValue.map { impl?.blocks = $0 } }
    }
    
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
    
}

extension FnType {
    func usingTypesIn(module: Module) -> FnType {
        let params = self.params.map { ($0 as? StorageType).map { module.getOrAddType($0) } ?? $0 }
        let returns = (self.returns as? StorageType).map { module.getOrAddType($0) } ?? self.returns
        return FnType(params: params, returns: returns, metadata: metadata, callingConvention: callingConvention)
    }
}

extension Builder {
    
    func buildFunction(name: String, type: FnType, paramNames: [String]) throws -> Function {
        let f = try createFunctionPrototype(name, type: type)
        try buildFunctionEntryBlock(f, paramNames: paramNames)
        try setInsertPoint(f)
        return f
    }
    
    func buildFunctionEntryBlock(function: Function, paramNames: [String]) throws {
        let fnParams = zip(paramNames, function.type.params).map(BBParam.init).map { $0 as Value }
        let bb = BasicBlock(name: "entry", parameters: fnParams, parentFunction: function)
        function.impl = FunctionImpl(paramNames: paramNames, blocks: [bb])
        try setInsertPoint(bb)
    }
    
    /// Creates function prototype an adds to module
    func createFunctionPrototype(name: String, type: FnType) throws -> Function {
        guard let module = module else { throw VHIRError.noModule }
        let f = Function(name: name, type: type, module: module)
        module.addFunction(f)
        return f
    }
    
}




