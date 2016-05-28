//
//  Function.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A VIR function, has a type and is made of a series
/// of basic blocks
final class Function : VIRElement {
    /// The mangled function name
    var name: String
    /// The cannonical type
    var type: FunctionType
    /// A function body. If nil this function is a prototype
    private var body: FunctionBody?
    
    private unowned var parentModule: Module
    var uses: [Operand] = []
    
    // Attrs
    var visibility: Visibility = .`internal`
    var inline: InlineRequirement = .`default`
    var attributes: Attributes = []
    
    private(set) var globalLifetimes: [GlobalValue.Lifetime] = []
    
    /// The LLVM function this is lowered to
    var loweredFunction: LLVMFunction? = nil {
        // update function ref operands
        didSet {
            guard let loweredFunction = loweredFunction else { return }
            for user in uses { user.updateUsesWithLoweredVal(loweredFunction.function) }
        }
    }
    /// The block self's errors should jmp to
    var _condFailBlock: LLVMBasicBlock? = nil
    
    
    private init(name: String, type: FunctionType, module: Module) {
        self.name = name
        self.parentModule = module
        self.type = type
    }
    
    /// A `Function`'s body. This contains the parameters and basic block list
    private final class FunctionBody {
        var blocks: [BasicBlock], params: [Param]
        /// The block self is a member of
        unowned let parentFunction: Function
        
        private init(params: [Param], parentFunction: Function, blocks: [BasicBlock]) {
            self.params = params
            self.parentFunction = parentFunction
            self.blocks = blocks
        }
    }
    
    /// The VIR visibility
    enum Visibility {
        case `private`, `internal`, `public`
    }
    /// How the inliner should handle this function
    enum InlineRequirement {
        case `default`, always, never//, earlyAndAlways
    }
    /// Other attributes
    struct Attributes : OptionSetType {
        let rawValue: Int
        init(rawValue: Int) { self.rawValue = rawValue }
        
        static var noreturn = Attributes(rawValue: 1 << 0)
        static var readnone = Attributes(rawValue: 1 << 1)
    }
}


extension Function {
    
    /// Whether this function has a defined body
    var hasBody: Bool { return body != nil && (body?.blocks.isEmpty ?? false) }
    /// The list of blocks in this function
    /// - precondition: self `hasBody`
    var blocks: [BasicBlock]? { return body?.blocks }
    /// The list of params to this function
    /// - precondition: self `hasBody`
    var params: [Param]? { return body?.params }
    
    /// Creates the function body, and applies `paramNames` as the 
    /// args to the entry block
    /// - precondition: Body is undefined
    func defineBody(paramNames pNames: [String]) throws {
        guard !hasBody else { throw VIRError.hasBody }
        
        let paramNames: [String]
        
        if case .method = type.callingConvention {
            paramNames = ["self"] + pNames
        }
        else {
            paramNames = pNames
        }
        
        // values for the explicit params
        let params = zip(paramNames, type.params).map { name, type -> Param in
            let t = type.usingTypesIn(module)
            if case let bt as BuiltinType = t, case .pointer(let pointee) = bt {
                return RefParam(paramName: name, memType: pointee)
            }
            else {
                return Param(paramName: name, type: t)
            }
        }
        
        body = FunctionBody(params: params, parentFunction: self, blocks: [])
        
        let entry = try module.builder.buildFunctionEntryBlock(self)
        for p in params { p.parentBlock = entry }
    }
    
    /// The function's entry block
    /// - precondition: self `hasBody`
    var entryBlock: BasicBlock? { return body?.blocks.first }
    var lastBlock: BasicBlock? { return body?.blocks.last }
    
    /// The index of `block` in `self`’s block list
    private func indexOf(block: BasicBlock) throws -> Int {
        if let index = blocks?.indexOf({$0 === block}) { return index } else { throw VIRError.bbNotInFn }
    }
    
    /// Get the Param `name` from `self`
    func paramNamed(name: String) throws -> Param {
        if let p = try body?.blocks.first?.paramNamed(name) { return p } else { throw VIRError.noParamNamed(name) }
    }
    
    func insert(block block: BasicBlock, atIndex index: Int) {
        body?.blocks.insert(block, atIndex: index)
    }
    /// Add basic block to end of `self`
    func append(block block: BasicBlock) {
        body?.blocks.append(block)
    }
    
    /// Apply AST attributes to set linkage, inline status, and attrs
    private func applyAttributes(attrs: [FunctionAttributeExpr]) {
        // linkage
        if attrs.contains(.`private`) { visibility = .`private` }
        else if attrs.contains(.`public`) { visibility = .`public` }
        
        // inline attrs
        if attrs.contains(.inline) { inline = .always }
        else if attrs.contains(.noinline) { inline = .never }
        
        // other attrs
        if attrs.contains(.noreturn) { attributes.insert(.noreturn) }
    }

    /// Return a reference to this function
    func buildFunctionPointer() -> PtrOperand {
        return PtrOperand(FunctionRef(toFunction: self, parentBlock: module.builder.insertPoint.block))
    }
    
    func getAsClosure() throws -> Closure {
        let type = self.type.cannonicalType(module)
        var ty = FunctionType(params: type.params,
                              returns: type.returns,
                              callingConvention: type.callingConvention,
                              yieldType: type.yieldType)
        ty.isCanonicalType = true
        let f = try module.builder.buildFunction(name,
                                                type: ty.cannonicalType(module),
                                                paramNames: params?.map{$0.paramName} ?? [])
        return Closure(_thunkOf: f)
    }
    
    func addParam(param: Param) throws {
        try entryBlock?.addEntryBlockParam(param)
    }
    
    func insertGlobalLifetime(lifetime: GlobalValue.Lifetime) {
        globalLifetimes.append(lifetime)
    }
    
    func removeGlobalLifetime(lifetime: GlobalValue.Lifetime) {
        if let i = globalLifetimes.indexOf({$0===lifetime}) {
            globalLifetimes.removeAtIndex(i)
        }
    }
    
    func dumpIR() { loweredFunction?.function.dump() }
    func dump() { print(vir) }
    var module: Module { return parentModule }
}


/// A function ref lvalue, this allows functions to be treated as values
final class FunctionRef : LValue {
//    unowned
    let function: Function
    
    private init(toFunction function: Function, parentBlock: BasicBlock?) {
        self.function = function
        self.parentBlock = parentBlock
        self.irName = function.name
    }
    
    var irName: String?
    
    var memType: Type? { return function.type }
    var type: Type? { return BuiltinType.pointer(to: function.type) }
    
    weak var parentBlock: BasicBlock?
    
    var uses: [Operand] {
        get { return function.uses }
        set(uses) { function.uses = uses }
    }
    
}

extension BasicBlock {
    /// Removes this block from the parent function
    func removeFromParent() throws {
        if let p = parentFunction {
            try p.body?.blocks.removeAtIndex(p.indexOf(self))
        }
    }
    /// Erases `self` from the parent function, cutting all references to
    /// it and all child instructions
    func eraseFromParent() throws {
        for inst in instructions {
            try inst.eraseFromParent()
        }
        try removeFromParent()
        parentFunction = nil
    }
    /// Moves `self` after the `after` block
    func move(after after: BasicBlock) throws {
        if let p = parentFunction {
            try p.body?.blocks.removeAtIndex(p.indexOf(self))
            p.insert(block: self, atIndex: try p.indexOf(after).successor())
        }
    }
    /// Moves `self` before the `before` block
    func move(before before: BasicBlock) throws {
        if let p = parentFunction {
            try p.body?.blocks.removeAtIndex(p.indexOf(self))
            p.insert(block: self, atIndex: try p.indexOf(before).predecessor())
        }
    }
}

extension Builder {
    
    /// Builds a function and adds it to the module. Declares a body and entry block
    func buildFunction(name: String, type: FunctionType, paramNames: [String], attrs: [FunctionAttributeExpr] = []) throws -> Function {
        let f = try createFunctionPrototype(name: name, type: type, attrs: attrs)
        try f.defineBody(paramNames: paramNames)
        return f
    }
    /// Builds a function and adds it to the module. Declares a body and entry block
    func getOrBuildFunction(name: String, type: FunctionType, paramNames: [String], attrs: [FunctionAttributeExpr] = []) throws -> Function {
        assert(paramNames.count == type.params.count)
        
        if let f = module.function(named: name) where !f.hasBody {
            try f.defineBody(paramNames: paramNames)
            return f
        }
        else {
            return try buildFunction(name, type: type, paramNames: paramNames, attrs: attrs)
        }
    }

    
    /// Builds an entry block for the function, passes the params of the function in
    func buildFunctionEntryBlock(function: Function) throws -> BasicBlock {
        let bb = BasicBlock(name: "entry", parameters: function.params, parentFunction: function)
        try bb.addEntryApplication(function.params!)
        function.body?.blocks.insert(bb, atIndex: 0)
        insertPoint.block = bb
        return bb
    }
    
    /// Creates function prototype an adds to module
    func createFunctionPrototype(name name: String, type: FunctionType, attrs: [FunctionAttributeExpr] = []) throws -> Function {
        let type = type.cannonicalType(module).usingTypesIn(module) as! FunctionType
        let function = Function(name: name, type: type, module: module)
        function.applyAttributes(attrs)
        module.insert(function)
        return function
    }
    
}

extension Module {
    
    /// Returns the function from the module. Adds prototype it if not already there
    func getOrInsertFunction(named name: String, type: FunctionType, attrs: [FunctionAttributeExpr] = []) throws -> Function {
        if let f = function(named: name) { return f }
        return try builder.createFunctionPrototype(name: name, type: type, attrs: attrs)
    }
    
    /// Returns a stdlib function, updating the module fn list if needed
    func getOrInsertStdLibFunction(named name: String, argTypes: [Type]) throws -> Function? {
        guard let (mangledName, fnTy) = StdLib.function(name: name, args: argTypes) else { return nil }
        return try getOrInsertFunction(named: mangledName, type: fnTy)
    }
    /// Returns a stdlib function, updating the module fn list if needed
    func getOrInsertStdLibFunction(mangledName name: String) throws -> Function? {
        guard let fnTy = StdLib.function(mangledName: name) else { return nil }
        return try getOrInsertFunction(named: name, type: fnTy)
    }
    
    /// Returns a runtime function, updating the module fn list if needed
    func getOrInsertRuntimeFunction(named name: String, argTypes: [Type]) throws -> Function? {
        guard let (mangledName, fnTy) = Runtime.function(name: name, argTypes: argTypes) else { return nil }
        return try getOrInsertFunction(named: mangledName, type: fnTy)
    }
    /// Returns a raw, unmangled runtime function, updating the module fn list if needed
    func getOrInsertRawRuntimeFunction(named name: String) throws -> Function? {
        guard let (mangledName, fnTy) = Runtime.function(mangledName: name) else { return nil }
        return try getOrInsertFunction(named: mangledName, type: fnTy)
    }
    
    /// Returns a function from the module by name
    func function(named name: String) -> Function? {
        return functions.find {$0.name == name}
    }
}


// implement hash and equality for functions
extension Function : Hashable, Equatable {
    var hashValue: Int { return name.hashValue }
}
@warn_unused_result
func == (lhs: Function, rhs: Function) -> Bool { return lhs === rhs }

