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
    private(set) weak var parent: Scope?
    private unowned var module: Module
    private(set) var function: Function?
    var captureHandler: CaptureHandler?, breakPoint: Builder.InsertPoint?
    
    init(module: Module) {
        self.module = module
        self.variables = [:]
    }
    init(parent: Scope, function: Function?, captureHandler: CaptureHandler? = nil, breakPoint: Builder.InsertPoint? = nil) {
        self.parent = parent
        self.function = function
        self.variables = [:]
        self.module = parent.module
        self.captureHandler = captureHandler ?? parent.captureHandler
        self.breakPoint = breakPoint ?? parent.breakPoint
    }
    static func capturingScope(parent: Scope, function: Function, captureHandler: CaptureHandler, breakPoint: Builder.InsertPoint) -> Scope {
        return Scope(parent: parent, function: function, captureHandler: captureHandler, breakPoint: breakPoint)
    }
    
    func add(variable: Accessor, name: String) {
        variables[name] = variable
    }
    
    /// - Returns: The accessor of a variable named `name`
    /// - Note: Updates the capture handler if we read from a parent
    func variableNamed(name: String) throws -> Accessor? {
        if let v = variables[name] { return v }
        
        let foundInParent = try parent?.variableNamed(name)
        if let f = foundInParent, var handler = captureHandler {
            // if we have a capture handler, infor that it 
            // captures this accessor
            let accessor = try handler.addCapture(f, scope: self, name: name)
            add(accessor, name: name)
            return accessor
        }
        return foundInParent
    }

    func removeVariableNamed(name: String) -> Accessor? {
        if let v = variables.removeValueForKey(name) { return v }
        return parent?.removeVariableNamed(name)
    }
    
    func isInScope(variable: Accessor) -> Bool {
        return variables.values.contains { $0 === variable }
    }
    
    /// Release all refcounted variables in this scope
    /// - parameter deleting: Whether to delete the scope's variables after releasing
    /// - parameter except: Do not release this variable
    func releaseVariables(deleting deleting: Bool, except: Accessor? = nil) throws {
        for variable in variables.values
            where (except.map { $0 !== variable }) ?? true {
            try variable.releaseIfRefcounted()
        }
        if deleting { variables.removeAll() }
    }
    func removeVariables() {
        variables.removeAll()
    }
    
    deinit {
        if !variables.isEmpty { 
            try! releaseVariables(deleting: true)
        }
    }
}


