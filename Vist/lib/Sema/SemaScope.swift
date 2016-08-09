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
    func function(named name: String, argTypes: [Type]) throws -> Solution {
        // lookup from stdlib/builtin
        if let stdLibFunction = StdLib.function(name: name, args: argTypes, solver: constraintSolver) { return stdLibFunction }
        else if isStdLib, let builtinFunction = Builtin.function(name: name, argTypes: argTypes) { return builtinFunction }
            // otherwise we search the user scopes recursively
        else { return try recursivelyLookupFunction(named: name, argTypes: argTypes) }
    }
    
    /// Recursvively searches this scope and its parents
    /// - note: should only be called *after* looking up in stdlib/builtin
    private func recursivelyLookupFunction(named name: String, argTypes: [Type]) throws -> Solution {
        if let inScope = functions.function(havingUnmangledName: name, argTypes: argTypes, solver: constraintSolver) { return inScope }
            // lookup from parents
        else if let inParent = try parent?.function(named: name, argTypes: argTypes) { return inParent }
            // otherwise we havent found a match :(
        throw semaError(.noFunction(name, argTypes))
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


extension Collection where
    Iterator.Element == (key: String, value: FunctionType)
{
    /// Look up the function from this mangled collection by the unmangled name and param types
    /// - returns: the mangled name and the type of the matching function
    func function(havingUnmangledName appliedName: String,
                  argTypes: [Type],
                  solver: ConstraintSolver)
        -> Solution?
    {
        var solutions: [Solution] = []
        // type variables in the args means we have to search all overloads to
        // form the disjoin overload set
        let reqiresFullSweep = argTypes.contains(where: {$0 is TypeVariable})
        // the return type variable -- only used when we are sweeping the whole set
        let returnTv: TypeVariable! = reqiresFullSweep ? solver.getTypeVariable() : nil
        
        functionSearch: for (fnName, fnType) in self {
            
            // base names match
            guard fnName.demangleName() == appliedName else {
                continue functionSearch
            }
            
            // arg types satisfy the params
            for (type, constraint) in zip(argTypes, fnType.params) {
                guard type.canAddConstraint(constraint, solver: solver) else {
                    continue functionSearch
                }
            }
            
            if reqiresFullSweep {
                // add the constraints
                for (type, constraint) in zip(argTypes, fnType.params) {
                    try! type.addConstraint(constraint, solver: solver)
                }
                try! returnTv.addConstraint(fnType.returns, solver: solver)
                
                let overload = (mangledName: appliedName.mangle(type: fnType), type: fnType)
                solutions.append(overload)
            }
            else {
                // if we are not using type variables, we can return the first
                // matching solution
                return (mangledName: appliedName.mangle(type: fnType), type: fnType)
            }
        }
        
        // if no overloads were found
        if solutions.isEmpty || !reqiresFullSweep { return nil }
        
        // the return type depends on the chosen overload
        let fnType = FunctionType(params: argTypes, returns: returnTv)
        // return the constrained solution
        return (mangledName: appliedName.mangle(type: fnType), type: fnType)
    }
}

