//
//  Scope.swift
//  Vist
//
//  Created by Josef Willsher on 03/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A semantic scope, containing the declared vars for
/// the VHIRGen phase.
final class Scope {
    private var variables: [String: Accessor]
    private weak var parent: Scope?
    private unowned var module: Module
    
    init(module: Module) {
        self.module = module
        self.variables = [:]
    }
    init(parent: Scope) {
        self.parent = parent
        self.variables = [:]
        self.module = parent.module
    }
    
    func add(variable: Accessor, name: String) {
        variables[name] = variable
    }
    
    func variableNamed(name: String) -> Accessor? {
        if let v = variables[name] { return v }
        return parent?.variableNamed(name)
    }

    func removeVariableNamed(name: String) -> Accessor? {
        if let v = variables.removeValueForKey(name) { return v }
        return parent?.removeVariableNamed(name)
    }

    func releaseVariables(deleting deleting: Bool = true) throws {
        for variable in variables.values {
            try variable.releaseIfRefcounted()
        }
        if deleting { variables.removeAll() }
    }
    func removeVariables() {
        variables.removeAll()
    }
    
    deinit {
        if !variables.isEmpty { 
            try! releaseVariables()
        }
    }
}


