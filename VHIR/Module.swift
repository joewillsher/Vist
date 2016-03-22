//
//  Module.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// The module type, functions get put into this
final class Module: VHIRElement {
    private(set) var functions: Set<Function> = [], typeList: Set<TypeAlias> = []
    var builder: Builder!
    var loweredModule: LLVMModuleRef = nil
    var loweredBuilder: LLVMModuleRef = nil
    
    init() { builder = Builder(module: self) }
    var module: Module { return self }
}

extension Module {
    
    func insert(f: Function) {
        functions.insert(f)
    }
    
    func insertType(name: String, targetType: StorageType) {
        typeList.insert(TypeAlias(name: name, targetType: targetType))
    }
    func insert(alias: TypeAlias) {
        typeList.insert(alias)
    }
    
    /// Returns the module's definition of `type`
    func getOrInsert(type: Ty) -> TypeAlias {
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
    
    func dumpIR() { if loweredModule != nil { LLVMDumpModule(loweredModule) } else { print("module <NULL>") } }
    func dump() { print(vhir) }
}
