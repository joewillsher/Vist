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
    fileprivate(set) var variables: [String: ManagedValue]
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
    
    // TODO: move managed value scope info here
    
    /// - Returns: The accessor of a variable named `name`
    /// - Note: Updates the capture handler if we read from a parent
    fileprivate func variable(named name: String) throws -> ManagedValue? {
        if let v = variables[name] { return v }
        
        let foundInParent = try parent?.variable(named: name)
        if let f = foundInParent, let handler = captureDelegate {
            // if we have a capture handler, infor that it 
            // captures this accessor
            let accessor = try handler.capture(variable: f, scope: self, name: name)
            variables[name] = accessor
            return accessor
        }
        return foundInParent
    }
}

extension VIRGenFunction {
    func addVariable(_ variable: ManagedValue, name: String) {
        managedValues.append(variable)
        scope.variables[name] = variable
    }
    func variable(named name: String) throws -> ManagedValue? {
        return try scope.variable(named: name)
    }
    
}

