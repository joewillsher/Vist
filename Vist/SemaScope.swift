//
//  SemaScope.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

class SemaScope<VarType> {
    
    var variables: [String: VarType]
    let parent: SemaScope<VarType>?
    
    subscript (name: String) -> VarType? {
        get {
            if let v = variables[name] { return v }
            return parent?[name]
        }
        set {
            variables[name] = newValue
        }
    }
    
    func addVariable(type: VarType, name: String) {
        variables[name] = type
    }
    
    init(parent: SemaScope?) {
        self.parent = parent
        self.variables = [:]
    }
}

