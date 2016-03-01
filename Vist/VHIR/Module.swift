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
    
    init() {
        builder = Builder(module: self)
    }
}

extension Module {
    func addFunction(f: Function) -> Function {
        functions.append(f)
        return f
    }

    func addType(name: String, targetType: Ty) {
        typeList.append(TypeAlias(name: name, targetType: targetType))
    }
}

