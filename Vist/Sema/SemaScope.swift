//
//  SemaScope.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

class SemaScope {
    
    var variables: [String: LLVMTyped]
    var functions: [String: LLVMFnType]
    var types: [String: LLVMStType]
    var returnType: LLVMTyped?
    let parent: SemaScope?
    
    /// Hint about what type the object should have
    ///
    /// Used for blocks’ types
    var objectType: LLVMTyped?
    
    subscript (variable variable: String) -> LLVMTyped? {
        get {
            if let v = variables[variable] { return v }
            return parent?[variable: variable]
        }
        set {
            variables[variable] = newValue
        }
    }
    subscript (function function: String, paramTypes types: [LLVMTyped]) -> LLVMFnType? {
        get {
            if let v = functions[raw: function, paramTypes: types] { return v }
            return parent?[function: function, paramTypes: types]
        }
    }
    subscript (function function: String) -> LLVMFnType? {
        get {
            if let v = functions[raw: function] { return v }
            return parent?[function: function]
        }
        set {
            functions[function.mangle(newValue!)] = newValue
        }
    }
    subscript (type type: String) -> LLVMStType? {
        get {
            if let v = types[type] { return v }
            return parent?[type: type]
        }
        set {
            types[type] = newValue
        }
    }
    
    init(parent: SemaScope?, returnType: LLVMTyped? = LLVMType.Void) {
        self.parent = parent
        self.returnType = returnType
        self.variables = [:]
        self.functions = [:]
        self.types = [:]
    }
}

extension DictionaryLiteralConvertible
    where
    Key == String,
    Value == LLVMFnType,
    Self : SequenceType,
    Self.Generator.Element == (Key, Value)
{
    
    /// Subscript for unmangled names
    ///
    /// Function name is required to be between underscores at the start _foo_...
    subscript(raw raw: String, paramTypes types: [LLVMTyped]) -> Value? {
        get {
            for (k, v) in self {
                if k.demangleName() == raw && v.params == types { return v }
            }
            return nil
        }
    }
    
    subscript(raw raw: String) -> Value? {
        get {
            for (k, v) in self {
                if k.demangleName() == raw { return v }
            }
            return nil
        }
    }

    
}


