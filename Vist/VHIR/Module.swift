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
    private var _builder: Builder?
}

extension Module {
    var builder: Builder { return _builder ?? Builder(module: self) }
    
    func addFunction(name: String, type: FnType, paramNames: [String]) throws -> Function {
        let f = Function(name: name, type: type, paramNames: paramNames)
        functions.append(f)
        return f
    }

    func addType(name: String, targetType: Ty) {
        typeList.append(TypeAlias(name: name, targetType: targetType))
    }
}

