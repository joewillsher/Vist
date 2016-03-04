//
//  Scope.swift
//  Vist
//
//  Created by Josef Willsher on 03/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A semantic scope, housing the declared vars
final class Scope {
    private var variables: [String: Value]
    weak var parent: Scope?
    
    init(parent: Scope? = nil) {
        self.parent = parent
        self.variables = [:]
    }
    
    func add(variable: Value, name: String) {
        variables[name] = variable
    }
    
    func variableNamed(name: String) -> Value? {
        if let v = variables[name] { return v }
        return parent?.variableNamed(name)
    }
    
}


