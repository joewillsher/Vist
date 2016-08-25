//
//  VIRGenScope.swift
//  Vist
//
//  Created by Josef Willsher on 03/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A semantic scope, containing the declared vars for
/// the VIRGen phase.
final class VIRGenScope {
    private(set) var variables: [String: Accessor]
    private(set) weak var parent: VIRGenScope?
    private unowned var module: Module
    private(set) var function: Function?
    /// Deleagte for managing captured variables 
    var captureDelegate: CaptureDelegate?
    /// The point from which we entered this scope
    var breakPoint: Builder.InsertPoint?
    
    init(module: Module) {
        self.module = module
        self.variables = [:]
    }
    init(parent: VIRGenScope,
         function: Function?,
         captureDelegate: CaptureDelegate? = nil,
         breakPoint: Builder.InsertPoint? = nil) {
        self.parent = parent
        self.function = function
        self.variables = [:]
        self.module = parent.module
        self.captureDelegate = captureDelegate
        self.breakPoint = breakPoint ?? parent.breakPoint
    }
    /// Create a scope which captures from `parent`
    static func capturing(parent: VIRGenScope,
                          function: Function,
                          captureDelegate: CaptureDelegate,
                          breakPoint: Builder.InsertPoint) -> VIRGenScope {
        return VIRGenScope(parent: parent,
                     function: function, 
                     captureDelegate: captureDelegate,
                     breakPoint: breakPoint)
    }
    
    func insert(variable: Accessor, name: String) {
        variables[name] = variable
    }
    
    /// - Returns: The accessor of a variable named `name`
    /// - Note: Updates the capture handler if we read from a parent
    func variable(named name: String) throws -> Accessor? {
        if let v = variables[name] { return v }
        
        let foundInParent = try parent?.variable(named: name)
        if let f = foundInParent, let handler = captureDelegate {
            // if we have a capture handler, infor that it 
            // captures this accessor
            let accessor = try handler.capture(variable: f, scope: self, name: name)
            insert(variable: accessor, name: name)
            return accessor
        }
        return foundInParent
    }

    func removeVariable(named name: String) -> Accessor? {
        if let v = variables.removeValue(forKey: name) { return v }
        return parent?.removeVariable(named: name)
    }
    
    func isInScope(variable: Accessor) -> Bool {
        return variables.values.contains { $0 === variable }
    }
    
    /// Release all refcounted and captuted variables in this scope
    /// - parameter deleting: Whether to delete the scope's variables after releasing
    /// - parameter except: Do not release this variable
    func releaseVariables(deleting: Bool, except: Accessor? = nil) throws {
        if deleting {
            for (name, _) in variables {
                try variables.removeValue(forKey: name)?.release()
            }
        }
    }
    func removeVariables() {
        variables.removeAll()
    }
    
    
    
    
}


