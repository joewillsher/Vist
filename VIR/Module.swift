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
    - A `Builder` instance which can be used to modify the module by adding
      instructions
    - During lowering it holds a reference to a LLVM module and builder
 */
final class Module : VIRElement {
    private(set) var functions: Set<Function> = [], typeList: Set<TypeAlias> = []
    var globalValues: Set<GlobalValue> = []
    var builder: Builder!
    var loweredModule: LLVMModule! = nil
    var loweredBuilder: LLVMBuilder! = nil
    
    init() { builder = Builder(module: self) }
    var module: Module { return self }
}

extension Module {
    
    /// Insert function to the module
    func insert(f: Function) {
        functions.insert(f)
    }
    
    /// Insert a type to the module
    func insert(targetType: StorageType, name: String) {
        typeList.insert(TypeAlias(name: name, targetType: targetType))
    }
    
    /// Insert a defined typealias to the module
    private func insert(alias: TypeAlias) {
        typeList.insert(alias)
    }
    
    /// Returns the module's definition of `type`
    func getOrInsert(type: Type) -> TypeAlias {
        if case let t as StorageType = type, let found = typeList.find({$0.targetType.name == t.name}) {
            return found
        }
        else if case let alias as TypeAlias = type, let found = typeList.find(alias) {
            return found
        }
        else if case let t as TypeAlias = type.usingTypesIn(module) {
            insert(t)
            return t
        }
        else {
            fatalError("Not storage type")
        }
    }
    
    func typeNamed(name: String) -> TypeAlias? {
        return typeList.find {$0.name == name}
    }
    
    func dumpIR() { loweredModule?.dump() }
    func dump() { print(vir) }
}
