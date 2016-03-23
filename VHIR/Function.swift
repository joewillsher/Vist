//
//  Function.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A VHIR function, has a type and is made of a series
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
}

private final class FunctionBody {
    private(set) var blocks: [BasicBlock]
    private(set) var params: [Param]
    unowned var parentFunction: Function
    
    private init(params: [Param], parentFunction: Function, blocks: [BasicBlock]) {
        self.params = params
        self.parentFunction = parentFunction
        self.blocks = blocks
    }
}

extension Function {
    
    var hasBody: Bool { return body != nil && (body?.blocks.isEmpty ?? false) }
    var blocks: [BasicBlock]? { return body?.blocks }
    var params: [Param]? { return body?.params }
    
    /// Creates the function body, and applies `paramNames` as the 
    /// args to the entry block
    ///
    /// - precondition: Body is undefined
    func defineBody(paramNames paramNames: [String]) throws {
        guard !hasBody else { throw VHIRError.hasBody }
        
        let params: [Param]
        
        switch type.callingConvention {
        case .method(let selfType):
            let selfParam = RefParam(paramName: "self", memType: selfType)
            let appliedParams = zip(paramNames, type.params.dropFirst().map{$0.usingTypesIn(module)}).map(Param.init)
            params = [selfParam] + appliedParams
            
        case .thin:
            params = zip(paramNames, type.params.map{$0.usingTypesIn(module)}).map(Param.init)
        }
        
        body = FunctionBody(params: params, parentFunction: self, blocks: [])
        
        let entry = try module.builder.buildFunctionEntryBlock(self)
        for p in params { p.parentBlock = entry }
    }
    
    var entryBlock: BasicBlock? { return body?.blocks.first }
    var lastBlock: BasicBlock? { return body?.blocks.last }
    
    /// The infex of `block` in `self`’s block list
    private func indexOf(block: BasicBlock) throws -> Int {
        if let index = blocks?.indexOf({$0 === block}) { return index } else { throw VHIRError.bbNotInFn }
    }
    
    /// Get the Param `name` for `self`
    func paramNamed(name: String) throws -> Param {
        if let p = try body?.blocks.first?.paramNamed(name) { return p } else { throw VHIRError.noParamNamed(name) }
    }
    
    func insert(block block: BasicBlock, atIndex index: Int) {
        body?.blocks.insert(block, atIndex: index)
    }
    func append(block block: BasicBlock) {
        body?.blocks.append(block)
    }
    
    func dumpIR() {
        if loweredFunction != nil { LLVMDumpValue(loweredFunction) } else { print("\(name) <NULL>") }
    }
    func dump() { print(vhir) }
    var module: Module { return parentModule }
}

extension BasicBlock {
    /// Removes this block from the parent function
    func removeFromParent() throws {
        parentFunction.body?.blocks.removeAtIndex(try parentFunction.indexOf(self))
    }
    /// Erases `self` from the parent function, cutting all references to
    /// it and all child instructions
    func eraseFromParent() throws {
        parentFunction = nil
        for inst in instructions {
            try inst.eraseFromParent()
        }
        try removeFromParent()
    }
    /// Moves `self` after the `after` block
    func move(after after: BasicBlock) throws {
        try removeFromParent()
        parentFunction.insert(block: self, atIndex: try parentFunction.indexOf(after).successor())
    }
    /// Moves `self` before the `before` block
    func move(before before: BasicBlock) throws {
        try removeFromParent()
        parentFunction.insert(block: self, atIndex: try parentFunction.indexOf(before).predecessor())
    }
}

extension Builder {
    
    /// Builds a function and adds it to the module. Declares a body and entry block
    func buildFunction(name: String, type: FnType, paramNames: [String]) throws -> Function {
        let f = try createFunctionPrototype(name, type: type)
        try f.defineBody(paramNames: paramNames)
        return f
    }
    /// Builds a function and adds it to the module. Declares a body and entry block
    func getOrBuildFunction(name: String, type: FnType, paramNames: [String]) throws -> Function {
        if let f = module.functionNamed(name) where !f.hasBody {
            try f.defineBody(paramNames: paramNames)
            return f
        }
        return try buildFunction(name, type: type, paramNames: paramNames)
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
        let type = type.usingTypesIn(module) as! FnType
        let function = Function(name: name, type: type.vhirType, module: module)
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


// implement hash and equality for functions
extension Function: Hashable, Equatable {
    var hashValue: Int { return name.hashValue }
}
@warn_unused_result
func == (lhs: Function, rhs: Function) -> Bool { return lhs === rhs }

