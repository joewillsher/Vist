//
//  Module.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 The module -- the single container of state in a compilation.
 
 This contians a record of
    - Defined functions, using their mangled names and cannonical types
    - A list of nominal types for the module.
    - A `VIRBuilder` instance which can be used to modify the module by adding
      instructions
    - During lowering it holds a reference to a LLVM module and builder
 */
final class Module : VIRElement {
    private(set) var functions: Set<Function> = []
    var typeList: [String: TypeAlias] = [:]
    var witnessTables: [VIRWitnessTable] = []
    var globalValues: Set<GlobalValue> = []
    var builder: VIRBuilder!
    var loweredModule: LLVMModule! = nil
    var loweredBuilder: LLVMBuilder! = nil
    
    init() { self.builder = VIRBuilder(module: self) }
    
    var module: Module { return self }
    
    
    /// Insert function to the module
    func insert(function f: Function) {
        functions.insert(f)
    }
    
    /// Insert a type to the module
    func insert(targetType: NominalType, name: String) {
        typeList[name] = TypeAlias(name: name, targetType: targetType)
    }
    
    /// Insert a defined typealias to the module
    private func insert(alias: TypeAlias) {
        typeList[alias.name] = alias
    }
    
    /// Returns the module's definition of `type`
    @discardableResult
    func getOrInsert(type: Type) -> TypeAlias {
        // if it exists, return it
        if case let t as NominalType = type, let found = typeList[t.name] {
            return found
        }
        
        let t = type.importedType(in: module) as! TypeAlias
        insert(alias: t)
        return t
    }
    
    func type(named name: String) -> TypeAlias? {
        return typeList[name]
    }
    
    func global(named name: String) -> GlobalValue? {
        return globalValues.first { $0.globalName == name }
    }
    
    func dumpIR() { loweredModule?.dump() }
    func dump() { print(vir) }
    
    var hasLoweredModule: Bool {
        return loweredModule != nil
    }
}
