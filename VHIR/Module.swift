//
//  Module.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// The module type, functions get put into this
final class Module: VHIRElement {
    private(set) var functions: [Function] = [], typeList: [TypeAlias] = [], builder: Builder!
    var loweredModule: LLVMModuleRef = nil
    
    init() { builder = Builder(module: self) }
    var module: Module { return self }
}

extension Module {
    
    func insert(f: Function) {
        functions.append(f)
    }
    
    func insert(name: String, targetType: StorageType) {
        typeList.append(TypeAlias(name: name, targetType: targetType))
    }
    
    /// Returns the module's definition of `type`
    func getOrInsertAliasTo(type: StorageType) -> TypeAlias {
        if let definedType = typeList.find({$0.targetType.name == type.name}) {
            return definedType
        }
        else {
            insert(type.name, targetType: type)
            return getOrInsertAliasTo(type)
        }
    }
    
    func dumpIR() { if loweredModule != nil { LLVMDumpModule(loweredModule) } else { print("module <NULL>") } }
    func dump() { print(vhir) }
}
