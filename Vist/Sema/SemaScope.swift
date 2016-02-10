//
//  SemaScope.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

typealias Variable = (type: Ty, mutable: Bool)

final class SemaScope {
    
    private var variables: [String: Variable]
    private var functions: [String: FnType]
    private var types: [String: StructType]
    var concepts: [String: ConceptType]
    let isStdLib: Bool
    var returnType: Ty?
    let parent: SemaScope?
    
    var genericParameters: [ConstrainedType]? = nil
    
    
    // TODO: make this the AST context
    /// Hint about what type the object should have
    ///
    /// Used for blocks’ types
    var semaContext: Ty?
    
    subscript (variable variable: String) -> Variable? {
        get {
            if let v = variables[variable] { return v }
            return parent?[variable: variable]
        }
        set {
            variables[variable] = newValue
        }
    }

    /// Gets a function from name and argument types
    ///
    /// Looks for function in the stdlib (if not compiling it) then
    /// in the builtin functions, then it looks through this scope,
    /// then searches parent scopes, throwing if not found
    ///
    func function(name: String, argTypes: [Ty]) throws -> (String, FnType) {

        if let stdLibFunction = StdLib.getStdLibFunction(name, args: argTypes) where !isStdLib {
            return stdLibFunction
        }
        else if let builtinFunction = Builtin.getBuiltinFunction(name, argTypes: argTypes) where isStdLib {
            return builtinFunction
        }
        else if let localFunctionType = functions[raw: name, paramTypes: argTypes] {
            return (name.mangle(argTypes), localFunctionType)
        }
        else if let inParent = try parent?.function(name, argTypes: argTypes) {
            return inParent
        }
        // error handling
        else if let f = self[function: name] {
            throw error(SemaError.WrongFunctionApplications(name: name, applied: argTypes, expected: f.params))
        }
        else {
            throw error(SemaError.NoFunction(name, argTypes))
        }
    }
    
    subscript (function function: String) -> FnType? {
        get {
            if let v = functions[raw: function] { return v }
            return parent?[function: function]
        }
        set {
            functions[function.mangle(newValue!)] = newValue
        }
    }
    subscript (type type: String) -> StructType? {
        get {
            if let t = StdLib.getStdLibType(type) {
                return t
            }
            else if let v = types[type] {
                return v
            }
//            else if let g = genericParameters, let i = genericParameters?.indexOf({$0.type == type}) {
//                
//                let type = g[i]
//                guard let concepts = type.constraints.optionalMap({ self[concept: $0] }) else { return nil }
//                
//                let requiredProperties = concepts.flatMap { $0.requiredProperties }
//                let requiredFunctions = concepts.flatMap { $0.requiredFunctions }
//                
//                return StructType(members: requiredProperties, methods: requiredFunctions, name: type.0)
//            }
            return parent?[type: type]
        }
        set {
            types[type] = newValue
        }
    }
    subscript (concept concept: String) -> ConceptType? {
        get {
            if let c = concepts[concept] { return c }
            return parent?[concept: concept]
        }
        set {
            concepts[concept] = newValue
        }
    }
    
    init(parent: SemaScope, returnType: Ty? = BuiltinType.Void, semaContext: Ty? = nil) {
        self.parent = parent
        self.returnType = returnType
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.concepts = [:]
        self.isStdLib = parent.isStdLib
    }
    
    // used by the global scope & non capturing static function
    /// Declares a type without a parent
    private init(returnType: Ty? = BuiltinType.Void, isStdLib: Bool, semaContext: Ty? = nil) {
        self.parent = nil
        self.returnType = returnType
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
    
    /// Creates a scope assocoiated with its parent which cannot read from its func, var, & type tables
    static func nonCapturingScope(parent: SemaScope, returnType: Ty? = BuiltinType.Void, semaContext: Ty? = nil) -> SemaScope {
        return SemaScope(returnType: returnType, isStdLib: parent.isStdLib, semaContext: semaContext)
    }
    
    /// Types including parents’ types
    var allTypes: LazyMapCollection<Dictionary<String, StructType>, StructType> {
        return types + parent?.types
    }
}

/// Append 2 dictionaries and return their lazy value collection
private func +
    <Key, Value>
    (
    lhs: Dictionary<Key, Value>,
    rhs: Dictionary<Key, Value>?
    ) -> LazyMapCollection<Dictionary<Key, Value>, Value>
{
    var u: [Key: Value] = [:]
    
    for (k, v) in lhs {
        u[k] = v
    }
    if let rhs = rhs {
        for (k, v) in rhs {
            u[k] = v
        }
    }
    return u.values
}




extension CollectionType
    where
    Generator.Element == (String, FnType)
{
    /// Subscript for unmangled names
    ///
    /// Function name is required to be between underscores at the start _foo_...
    subscript(raw raw: String, paramTypes types: [Ty]) -> FnType? {
        get {
            
            for (k, v) in self {
                if k.demangleName() == raw && v.params == types { return v }
            }
            return nil
        }
    }
    
    subscript(raw raw: String) -> FnType? {
        get {
            for (k, v) in self {
                if k.demangleName() == raw { return v }
            }
            return nil
        }
    }
    
}

