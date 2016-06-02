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
        
        /// The index of `block` in `self`’s block list
        private func index(of block: BasicBlock) throws -> Int {
            if let index = blocks.index(where: {$0 === block}) { return index } else { throw VIRError.bbNotInFn }
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
    struct Attributes : OptionSet {
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
    var blocks: [BasicBlock]? {
        get { return body?.blocks }
        set { if let v = newValue { body?.blocks = v } }
    }
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
            let t = type.importedType(inModule: module)
            if case let bt as BuiltinType = t, case .pointer(let pointee) = bt {
                return RefParam(paramName: name, memType: pointee)
            }
            else {
                return Param(paramName: name, type: t)
            }
        }
        
        body = FunctionBody(params: params, parentFunction: self, blocks: [])
        
        let entry = try module.builder.buildEntryBlock(function: self)
        for p in params { p.parentBlock = entry }
    }
    
    /// The function's entry block
    /// - precondition: self `hasBody`
    var entryBlock: BasicBlock? { return body?.blocks.first }
    var lastBlock: BasicBlock? { return body?.blocks.last }
    
    /// The index of `block` in `self`’s block list
    private func index(of block: BasicBlock) throws -> Int {
        if let body = body { return try body.index(of: block) } else { throw VIRError.bbNotInFn }
    }

    /// Get the Param `name` from `self`
    func param(named name: String) throws -> Param {
        if let p = try body?.blocks.first?.param(named: name) { return p } else { throw VIRError.noParamNamed(name) }
    }
    
    func insert(block: BasicBlock, atIndex index: Int) {
        body?.blocks.insert(block, at: index)
    }
    /// Add basic block to end of `self`
    func append(block: BasicBlock) {
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
        if attrs.contains(.noreturn) { _ = attributes.insert(.noreturn) }
    }
    
    /// Return a reference to this function
    func buildFunctionPointer() -> PtrOperand {
        return PtrOperand(FunctionRef(toFunction: self, parentBlock: module.builder.insertPoint.block))
    }
    
    func getAsClosure() throws -> Closure {
        let type = self.type.cannonicalType(module: module)
        var ty = FunctionType(params: type.params,
                              returns: type.returns,
                              callingConvention: type.callingConvention,
                              yieldType: type.yieldType)
        ty.isCanonicalType = true
        let f = try module.builder.buildFunction(name: name,
                                                type: ty.cannonicalType(module: module),
                                                paramNames: params?.map{$0.paramName} ?? [])
        return Closure(_thunkOf: f)
    }
    
    func addParam(param: Param) throws {
        try entryBlock?.addEntryBlockParam(param: param)
    }
    
    func insertGlobalLifetime(_ lifetime: GlobalValue.Lifetime) {
        globalLifetimes.append(lifetime)
    }
    
    func removeGlobalLifetime(_ lifetime: GlobalValue.Lifetime) {
        if let i = globalLifetimes.index(where: {$0===lifetime}) {
            globalLifetimes.remove(at: i)
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
            try p.body?.blocks.remove(at: p.index(of: self))
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
    func move(after: BasicBlock) throws {
        guard let body = parentFunction?.body else { return }
        
        try body.blocks.remove(at: body.index(of: self))

        let new = try body.blocks.index(after: body.index(of: after))
        body.blocks.insert(self, at: new)
    }
    /// Moves `self` before the `before` block
    func move(before: BasicBlock) throws {
        guard let body = parentFunction?.body else { return }
        
        try body.blocks.remove(at: body.index(of: self))
        
        let new = try body.blocks.index(before: body.index(of: before))
        body.blocks.insert(self, at: new)
    }
}

extension Builder {
    
    /// Builds a function called `name` and adds it to the module
    func buildFunction(name: String, type: FunctionType, paramNames: [String], attrs: [FunctionAttributeExpr] = []) throws -> Function {
        let f = try buildFunctionPrototype(name: name, type: type, attrs: attrs)
        try f.defineBody(paramNames: paramNames)
        return f
    }
    
    /// Builds a unique function, modifying the name if there is a collision
    func buildUniqueFunction(name: String, type: FunctionType, paramNames: [String], attrs: [FunctionAttributeExpr] = []) throws -> Function {
        
        if let _ = module.function(named: name) {
            // if we already have a function with this name, we try again with a different name
            return try buildUniqueFunction(name: "\(name)2", type: type, paramNames: paramNames, attrs: attrs)
        }
        
        return try buildFunction(name: name, type: type, paramNames: paramNames, attrs: attrs)
    }
    
    /// Creates a function, building the prototype first if its not present
    func getOrBuildFunction(name: String, type: FunctionType, paramNames: [String], attrs: [FunctionAttributeExpr] = []) throws -> Function {
        precondition(paramNames.count == type.params.count)
        
        if let f = module.function(named: name) where !f.hasBody {
            try f.defineBody(paramNames: paramNames)
            return f
        }
        else {
            return try buildFunction(name: name, type: type, paramNames: paramNames, attrs: attrs)
        }
    }

    
    /// Builds an entry block for the function, passes the params of the function in
    func buildEntryBlock(function: Function) throws -> BasicBlock {
        let bb = BasicBlock(name: "entry", parameters: function.params, parentFunction: function)
        try bb.addEntryApplication(args: function.params!)
        function.body?.blocks.insert(bb, at: 0)
        insertPoint.block = bb
        return bb
    }
    
    /// Creates function prototype an adds to module
    @discardableResult
    func buildFunctionPrototype(name: String, type: FunctionType, attrs: [FunctionAttributeExpr] = []) throws -> Function {
        let type = type.cannonicalType(module: module).importedType(inModule: module) as! FunctionType
        let function = Function(name: name, type: type, module: module)
        function.applyAttributes(attrs: attrs)
        module.insert(function: function)
        return function
    }
    
}

extension Module {
    
    /// Returns the function from the module. Adds prototype it if not already there
    @discardableResult
    func getOrInsertFunction(named name: String, type: FunctionType, attrs: [FunctionAttributeExpr] = []) throws -> Function {
        if let f = function(named: name) { return f }
        return try builder.buildFunctionPrototype(name: name, type: type, attrs: attrs)
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
        return functions.first {$0.name == name}
    }
}


// implement hash and equality for functions
extension Function : Hashable, Equatable {
    var hashValue: Int { return name.hashValue }
}
@warn_unused_result
func == (lhs: Function, rhs: Function) -> Bool { return lhs === rhs }

