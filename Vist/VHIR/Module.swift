//
//  Module.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// The module type, functions get put into this
final class Module: VHIR {
    var functions: [Function] = []
    var typeList: [TypeAlias] = []
    var builder: Builder!
    var loweredModule: LLVMModuleRef = nil
    
    init() {
        builder = Builder(module: self)
    }
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
    
    func getOrAddFunction(name: String, type: FnType) throws -> Function {
        if let f = functionNamed(name, paramTypes: type.params) { return f }
        return try builder.createFunctionPrototype(name, type: type)
    }
    
    func getStdLibFunction(name: String, argTypes: [Ty]) throws -> Function? {
        guard let (mangledName, fnTy) = StdLib.getStdLibFunction(name, args: argTypes) else { return nil }
        return try builder.createFunctionPrototype(mangledName, type: fnTy)
    }
    
    func functionNamed(name: String, paramTypes: [Ty]) -> Function? {
        return functions.indexOf({$0.name == name && $0.type.params.elementsEqual(paramTypes, isEquivalent: ==)}).map { functions[$0] }
    }
}

