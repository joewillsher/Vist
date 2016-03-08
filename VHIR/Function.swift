//
//  Function.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

private final class FunctionBody {
    var blocks: [BasicBlock]
    var params: [BBParam]
    unowned var parentFunction: Function
    
    private init(params: [BBParam], parentFunction: Function, blocks: [BasicBlock]) {
        self.params = params
        self.parentFunction = parentFunction
        self.blocks = blocks
    }
}


/// A VHIR function, has a type and ismade of a series
/// of basic blocks
final class Function: VHIRElement {
    var name: String
    var type: FnType
    private var body: FunctionBody?
    private unowned var parentModule: Module
    
    var loweredFunction: LLVMValueRef = nil
    
    private init(name: String, type: FnType, module: Module) {
        self.name = name
        self.parentModule = module
        self.type = type
    }
    
    var hasBody: Bool { return body != nil && body?.blocks.isEmpty ?? false }
    var blocks: [BasicBlock]? { return body?.blocks }
    var params: [BBParam]? { return body?.params }
    
    /// Creates the function body, and applies `paramNames` as the 
    /// args to the entry block
    func defineBody(paramNames paramNames: [String]) throws {
        guard !hasBody else { throw VHIRError.hasBody }
        let params = zip(paramNames, type.params.map{$0.usingTypesIn(module)}).map(BBParam.init)
        body = FunctionBody(params: params, parentFunction: self, blocks: [])
        let entry = try module.builder.buildFunctionEntryBlock(self)
        params.forEach { $0.parentBlock = entry }
    }
    
    var entryBlock: BasicBlock? {
        guard let first = body?.blocks.first else { return nil }
        return first
    }
    var lastBlock: BasicBlock? {
        guard let last = body?.blocks.last else { return nil }
        return last
    }
    private func indexOf(block: BasicBlock) throws -> Int {
        guard let index = blocks?.indexOf({$0 === block}) else { throw VHIRError.bbNotInFn }
        return index
    }
    
    func paramNamed(name: String) throws -> BBParam {
        guard let p = try body?.blocks.first?.paramNamed(name) else { throw VHIRError.noParamNamed(name) }
        return p
    }
    
    func dumpIR() { if loweredFunction != nil { LLVMDumpValue(loweredFunction) } else { print("\(name) <NULL>") } }
    var module: Module { return parentModule }
}

extension BasicBlock {
    func removeFromParent() throws {
        parentFunction.body?.blocks.removeAtIndex(try parentFunction.indexOf(self))
        parentFunction = nil
    }
    func moveAfter(after: BasicBlock) throws {
        try removeFromParent()
        parentFunction.body?.blocks.insert(self, atIndex: try parentFunction.indexOf(after).successor())
    }
    func moveBefore(before: BasicBlock) throws {
        try removeFromParent()
        parentFunction.body?.blocks.insert(self, atIndex: try parentFunction.indexOf(before).predecessor())
    }
    func appendToParent() {
        parentFunction.body?.blocks.append(self)
    }
}

extension Builder {
    
    /// Builds a function and adds it to the module. Declares a body and entry block
    func buildFunction(name: String, type: FnType, paramNames: [String]) throws -> Function {
        let f = try createFunctionPrototype(name, type: type)
        try f.defineBody(paramNames: paramNames)
        try setInsertPoint(f)
        return f
    }
    
    /// Builds an entry block for the function, passes the params of the function in
    func buildFunctionEntryBlock(function: Function) throws -> BasicBlock {
        let bb = BasicBlock(name: "entry", parameters: function.params, parentFunction: function)
        try bb.addEntryApplication(function.params!)
        function.body?.blocks.insert(bb, atIndex: 0)
        try setInsertPoint(bb)
        return bb
    }
    
    /// Creates function prototype an adds to module
    func createFunctionPrototype(name: String, type: FnType) throws -> Function {
        let function = Function(name: name, type: type.usingTypesIn(module) as! FnType, module: module)
        module.insert(function)
        return function
    }
    
}

extension Module {
    
    /// Returns the function from the module. Adds prototype it if not already there
    func getOrInsertFunctionNamed(name: String, type: FnType) throws -> Function {
        if let f = functionNamed(name) { return f }
        return try builder.createFunctionPrototype(name, type: type)
    }
    
    /// Returns a stdlib function, updating the module fn list if needed
    func stdLibFunctionNamed(name: String, argTypes: [Ty]) throws -> Function? {
        guard let (mangledName, fnTy) = StdLib.functionNamed(name, args: argTypes) else { return nil }
        return try getOrInsertFunctionNamed(mangledName, type: fnTy)
    }
    
    /// Returns a stdlib function, updating the module fn list if needed
    func runtimeFunctionNamed(name: String, argTypes: [Ty]) throws -> Function? {
        guard let (mangledName, fnTy) = Runtime.functionNamed(name, argTypes: argTypes) else { return nil }
        return try getOrInsertFunctionNamed(mangledName, type: fnTy)
    }
    
    /// Returns a function from the module by name
    func functionNamed(name: String) -> Function? {
        return functions.indexOf({$0.name == name}).map { functions[$0] }
    }
}


