//
//  FunctionContainer.swift
//  Vist
//
//  Created by Josef Willsher on 27/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// Holds functions, mangles them on initialisation and subscript
///
/// Used to tell the compiler about functions
///
struct FunctionContainer {
    
    private let functions: [String: FunctionType]
    private let types: [StructType]
    private let concepts: [ConceptType]
    
    /**
     Initialiser takes a collection of tuples.
     
     Tuples are of the unmangled name and the type object
     
     Optionally takes an array of metadata to apply to all functions
     */
    init (functions: [(String, FunctionType)],
          types: [StructType],
          concepts: [ConceptType] = [],
          metadata: [String] = [],
          mangleFunctionNames: Bool = true) {
        var functionTypes: [String: FunctionType] = [:]
        
        for (n, ty) in functions {
            let mangled = mangleFunctionNames ? n.mangle(type: ty) : n
            functionTypes[mangled] = ty
        }
        
        let typesWithMethods = types.map { t -> StructType in
            let type = t
            type.methods = type.methods.map { m in (m.name, m.type.asMethod(withSelf: t, mutating: m.mutating), m.mutating) }
            for m in type.methods { // add methods to function table
                var type = m.type
                if let y = type.yieldType {
                    type.setGeneratorVariantType(yielding: y)
                }
                functionTypes[m.name.mangle(type: m.type)] = type
            }
            return type
        }
        
        self.functions = functionTypes
        self.types = typesWithMethods
        self.concepts = concepts
    }
    
    /// Get a named function
    /// - parameter named: Unmangled name
    /// - parameter argTypes: Applied arg types
    /// - returns: An optional tuple of `(mangledName, type)`
    func lookupFunction(named fn: String, argTypes types: [Type], solver: ConstraintSolver) -> Solution? {
        return functions.function(havingUnmangledName: fn, argTypes: types, solver: solver)
    }
    /// unmangled
    subscript(mangledName mangledName: String) -> Solution? {
        return functions[mangledName].map { (mangledName, $0) }
    }
    
    /// Returns type from type name
    subscript(type type: String) -> NominalType? {
        if let s = types.first(where: { $0.name == type }) { return s }
        if let c = concepts.first(where: { $0.name == type }) { return c }
        return nil
    }
    
}

