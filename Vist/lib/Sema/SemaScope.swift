//
//  SemaScope.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

typealias Variable = (type: Type, mutable: Bool, isImmutableCapture: Bool)

final class SemaScope {
    
    private var variables: [String: Variable]
    private var functions: [String: FunctionType]
    private var types: [String: NominalType]
    var concepts: [String: ConceptType]
    let isStdLib: Bool
    var returnType: Type?, isYield: Bool
    let parent: SemaScope?
    
    var genericParameters: [ConstrainedType]? = nil
    
    
    // TODO: make this the AST context
    /// Hint about what type the object should have
    ///
    /// Used for blocks’ types
    var semaContext: Type?
    
    /// Lookup the varibale called `name`
    func variable(named name: String) -> Variable? {
        if let v = variables[name] { return v }
        return parent?.variable(named: name)
    }
    func addVariable(variable: Variable, name: String) {
        variables[name] = variable
    }
    /// Whether *this* scope contains a named variable
    func thisScopeContainsVariable(named: String) -> Bool {
        return variables.contains { $0.0 == named }
    }

    /// Gets a function from name and argument types
    ///
    /// Looks for function in the stdlib (if not compiling it) then
    /// in the builtin functions, then it looks through this scope,
    /// then searches parent scopes, throwing if not found
    ///
    func function(named name: String, argTypes: [Type]) throws -> (mangledName: String, type: FunctionType) {
        // lookup from stdlib/builtin
        if let stdLibFunction = StdLib.function(name: name, args: argTypes) { return stdLibFunction }
        else if let builtinFunction = Builtin.function(name: name, argTypes: argTypes), isStdLib { return builtinFunction }
            // otherwise we search the user scopes recursively
        else { return try recursivelyLookupFunction(named: name, argTypes: argTypes) }
    }
    
    /// Recursvively searches this scope and its parents
    /// - note: should only be called *after* looking up in stdlib/builtin
    private func recursivelyLookupFunction(named name: String, argTypes: [Type]) throws -> (mangledName: String, type: FunctionType) {
        if let inScope = functions.function(havingUnmangledName: name, paramTypes: argTypes) { return inScope }
            // lookup from parents
        else if let inParent = try parent?.function(named: name, argTypes: argTypes) { return inParent }
            // otherwise we havent found a match :(
        else { throw semaError(.noFunction(name, argTypes)) }
    }
    
    func addFunction(name: String, type: FunctionType) {
        functions[name.mangle(type: type)] = type
    }
    
    func type(named name: String) -> NominalType? {
        // lookup from this scope, its parents, then stldib
        return recursivelyLookupType(named: name) ??
            StdLib.type(name: name)
    }
    
    /// Recursvively searches this scope and its parents
    /// - note: should only be called *after* looking up in stdlib/builtin
    private func recursivelyLookupType(named name: String) -> NominalType? {
        if let v = types[name] {
            return v
        }
        else if let g = genericParameters, let i = genericParameters?.index(where: {$0.name == name}) {
            return try? GenericType.fromConstraint(inScope: self)(constraint: g[i])
        }
        else if let existential = concepts[name] {
            return existential
        }
        else {
            return parent?.recursivelyLookupType(named: name)
        }
    }
    
    func addType(_ type: NominalType, name: String) {
        types[name] = type
    }
    
    func concept(named name: String) -> ConceptType? {
        if let c = concepts[name] { return c }
        return parent?.concept(named: name)
    }
    func addConcept(_ concept: ConceptType, name: String) {
        concepts[name] = concept
    }
    
    init(parent: SemaScope, returnType: Type? = BuiltinType.void, isYield: Bool = false, semaContext: Type? = nil) {
        self.parent = parent
        self.returnType = returnType
        self.isYield = isYield
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.concepts = [:]
        self.isStdLib = parent.isStdLib
    }
    
    // used by the global scope & non capturing static function
    /// Declares a type without a parent
    private init(returnType: Type? = BuiltinType.void, isStdLib: Bool, semaContext: Type? = nil) {
        self.parent = nil
        self.returnType = returnType
        self.isYield = false
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.concepts = [:]
        self.isStdLib = isStdLib
    }
    
    /// Constructs the global SemaScope for a module
    static func globalScope(isStdLib: Bool) -> SemaScope {
        return SemaScope(isStdLib: isStdLib)
    }
    
    /// Creates a scope associated with its parent which cannot read from its func, var, & type tables
    static func nonCapturingScope(parent: SemaScope, returnType: Type? = BuiltinType.void, isYield: Bool = false, semaContext: Type? = nil) -> SemaScope {
        return SemaScope(returnType: returnType, isStdLib: parent.isStdLib, semaContext: semaContext)
    }
    
    static func capturingScope(parent: SemaScope, overrideReturnType: Optional<Type?> = nil) -> SemaScope {
        return SemaScope(parent: parent,
                         returnType: overrideReturnType ?? parent.returnType,
                         isYield: parent.isYield,
                         semaContext: parent.semaContext)
    }
}


extension Collection where
    Iterator.Element == (key: String, value: FunctionType)
{
    /// Look up the function from this mangled collection by the unmangled name and param types
    /// - returns: the mangled name and the type of the matching function
    func function(havingUnmangledName raw: String, paramTypes types: [Type]) -> (mangledName: String, type: FunctionType)? {
        return first(where: { k, v in
            k.demangleName() == raw &&
                v.params.elementsEqual(types, by: ==)
        }).map { f in
            return (mangledName: raw.mangle(type: f.value), type: f.value)
        }
    }
}

