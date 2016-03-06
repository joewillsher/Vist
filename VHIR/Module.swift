//
//  Module.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// The module type, functions get put into this
final class Module: VHIRElement {
    var functions: [Function] = []
    var typeList: [TypeAlias] = []
    var builder: Builder!
    var loweredModule: LLVMModuleRef = nil
    
    init() {
        builder = Builder(module: self)
    }
    
    var module: Module { return self }
}

extension Module {
    func addFunction(f: Function) -> Function {
        functions.append(f)
        return f
    }
    
    func addType(name: String, targetType: StorageType) {
        typeList.append(TypeAlias(name: name, targetType: targetType))
    }
    
    /// Returns the module's definition of `type`
    func getOrAddType(type: StorageType) -> TypeAlias {
        if let t = typeList.indexOf({$0.targetType == type}) {
            return typeList[t]
        }
        else {
            addType(type.name, targetType: type)
            return getOrAddType(type)
        }
    }
    
    /// Returns the function from the module. Adds prototype it if not already there
    func getOrAddFunction(name: String, type: FnType) throws -> Function {
        if let f = functionNamed(name) { return f }
        return try builder.createFunctionPrototype(name, type: type)
    }
    
    /// Returns a stdlib function, updating the module fn list if needed
    func stdLibFunctionNamed(name: String, argTypes: [Ty]) throws -> Function? {
        guard let (mangledName, fnTy) = StdLib.getStdLibFunction(name, args: argTypes) else { return nil }
        return try getOrAddFunction(mangledName, type: fnTy)
    }
    
    /// Returns a function from the module by name
    func functionNamed(name: String) -> Function? {
        return functions.indexOf({$0.name == name}).map { functions[$0] }
    }
    
    func dumpIR() { if loweredModule != nil { LLVMDumpValue(loweredModule) } else { print("module <NULL>") } }
}

