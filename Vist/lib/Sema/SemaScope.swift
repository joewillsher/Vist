//
//  SemaScope.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

typealias Variable = (type: Type, mutable: Bool, isImmutableCapture: Bool)
typealias Solution = (mangledName: String, type: FunctionType)

final class SemaScope {
    
    private var variables: [String: Variable]
    private var functions: [String: FunctionType]
    private var types: [String: NominalType]
    var concepts: [String: ConceptType]
    let isStdLib: Bool
    var returnType: Type?, isYield: Bool
    let parent: SemaScope?
    let constraintSolver: ConstraintSolver
    
    var genericParameters: [ConstrainedType]? = nil
    
    /// Hint about what type the object should have
    ///
    /// Used for blocks’ types
    var semaContext: Type?
    var name: String?
    
    /// Lookup the varibale called `name`
    func variable(named name: String) -> Variable? {
        if let v = variables[name] { return v }
        return parent?.variable(named: name)
    }
    func addVariable(variable: Variable, name: String) {
        variables[name] = variable
        // if it is a closure, add to the function table too
        if case let fnTy as FunctionType = variable.type {
            addFunction(name: name, type: fnTy)
        }
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
    func function(named name: String, argTypes: [Type], base: NominalType? = nil) throws -> Solution {
        // lookup from stdlib/builtin
        if let stdLibFunction = StdLib.function(name: name, args: argTypes, base: base, solver: constraintSolver) { return stdLibFunction }
        else if isStdLib, let builtinFunction = Builtin.function(name: name, argTypes: argTypes, solver: constraintSolver) { return builtinFunction }
            // otherwise we search the user scopes recursively
        return try recursivelyLookupFunction(named: name, argTypes: argTypes, base: base)
    }
    
    /// Recursvively searches this scope and its parents
    /// - note: should only be called *after* looking up in stdlib/builtin
    private func recursivelyLookupFunction(named name: String, argTypes: [Type], base: NominalType?) throws -> Solution {
        if let inScope = functions.function(havingUnmangledName: name, argTypes: argTypes, base: base, solver: constraintSolver) { return inScope }
            // lookup from parents
        else if let inParent = try parent?.recursivelyLookupFunction(named: name, argTypes: argTypes, base: base) { return inParent }
            // otherwise we havent found a match :(
        throw semaError(.noFunction(name, argTypes))
    }
    
    func addFunction(mangledName: String, type: FunctionType) {
        functions[mangledName] = type
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
    
    init(parent: SemaScope, returnType: Type? = BuiltinType.void, isYield: Bool = false, semaContext: Type? = nil, name: String? = nil) {
        self.parent = parent
        self.returnType = returnType
        self.semaContext = semaContext
        self.name = name
        self.isYield = isYield
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.concepts = [:]
        self.isStdLib = parent.isStdLib
        self.constraintSolver = parent.constraintSolver
    }
    
    // used by the global scope & non capturing static function
    /// Declares a type without a parent
    private init(returnType: Type? = BuiltinType.void,
                 isStdLib: Bool,
                 context: Type? = nil,
                 name: String? = nil,
                 constraintSolver: ConstraintSolver = ConstraintSolver()) {
        self.parent = nil
        self.returnType = returnType
        self.semaContext = context
        self.name = name
        self.isYield = false
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.concepts = [:]
        self.isStdLib = isStdLib
        self.constraintSolver = constraintSolver
    }
    
    /// Constructs the global SemaScope for a module
    static func globalScope(isStdLib: Bool) -> SemaScope {
        return SemaScope(isStdLib: isStdLib)
    }
    
    /// Creates a scope associated with its parent which cannot read from its func, var, & type tables
    static func nonCapturingScope(parent: SemaScope,
                                  returnType: Type? = BuiltinType.void,
                                  isYield: Bool = false,
                                  context: (context: Type, name: String)? = nil) -> SemaScope {
        return SemaScope(returnType: returnType,
                         isStdLib: parent.isStdLib,
                         context: context?.context,
                         name: context?.name)
    }
    
    static func capturingScope(parent: SemaScope,
                               overrideReturnType: Optional<Type?> = nil,
                               context: Type? = nil,
                               scopeName: String? = nil) -> SemaScope {
        return SemaScope(parent: parent,
                         returnType: overrideReturnType ?? parent.returnType,
                         isYield: parent.isYield,
                         semaContext: context ?? parent.semaContext,
                         name: scopeName ?? parent.name)
    }
}


