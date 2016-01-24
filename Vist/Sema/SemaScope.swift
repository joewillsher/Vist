//
//  SemaScope.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

final class SemaScope {
    
    private var variables: [String: Ty]
    private var functions: [String: FnType]
    private var types: [String: StructType]
    let isStdLib: Bool
    var returnType: Ty?
    let parent: SemaScope?
    
    
    // TODO: make this the AST context
    /// Hint about what type the object should have
    ///
    /// Used for blocks’ types
    var objectType: Ty?
    
    subscript (variable variable: String) -> Ty? {
        get {
            if let v = variables[variable] { return v }
            return parent?[variable: variable]
        }
        set {
            variables[variable] = newValue
        }
    }
    subscript (function function: String, paramTypes types: [Ty]) -> FnType? {
        get {
            if let v = functions[raw: function, paramTypes: types] { return v }
            return parent?[function: function, paramTypes: types]
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
            if let t = StdLibFunctions.getStdLibType(type) { return t }
            if let v = types[type] { return v }
            return parent?[type: type]
        }
        set {
            types[type] = newValue
        }
    }
    
    init(parent: SemaScope, returnType: Ty? = BuiltinType.Void) {
        self.parent = parent
        self.returnType = returnType
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.isStdLib = parent.isStdLib
    }
    init(parent: SemaScope?, returnType: Ty? = BuiltinType.Void, isStdLib: Bool) {
        self.parent = parent
        self.returnType = returnType
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.isStdLib = isStdLib
    }

    init(isStdLib: Bool) {
        self.parent = nil
        self.returnType = BuiltinType.Void
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
        self.isStdLib = isStdLib
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

