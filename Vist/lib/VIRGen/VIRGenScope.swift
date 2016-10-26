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
    fileprivate(set) var variables: [VariableKey: ManagedValue]
    private(set) weak var parent: VIRGenScope?
    private unowned var module: Module
    private(set) var function: Function?
    /// Deleagte for managing captured variables 
    var captureDelegate: CaptureDelegate?
    /// The point from which we entered this scope
    var breakPoint: VIRBuilder.InsertPoint?
    
    init(module: Module) {
        self.module = module
        self.variables = [:]
    }
    init(parent: VIRGenScope,
         function: Function?,
         captureDelegate: CaptureDelegate? = nil,
         breakPoint: VIRBuilder.InsertPoint? = nil) {
        self.parent = parent
        self.function = function
        self.variables = [:]
        self.module = parent.module
        self.captureDelegate = captureDelegate
        self.breakPoint = breakPoint ?? parent.breakPoint
    }
    /// Create a scope which captures from `parent`
    static func capturing(_ parent: VIRGenScope,
                          function: Function,
                          captureDelegate: CaptureDelegate,
                          breakPoint: VIRBuilder.InsertPoint) -> VIRGenScope {
        return VIRGenScope(parent: parent,
                     function: function, 
                     captureDelegate: captureDelegate,
                     breakPoint: breakPoint)
    }
    
    enum VariableKey : Hashable {
        case identifier(String), `self`
        
        var hashValue: Int {
            switch self {
            case .identifier(let s): return s.hashValue
            case .self: return 0
            }
        }
        static func == (l: VariableKey, r: VariableKey) -> Bool {
            switch (l, r) {
            case (.identifier(let li), .identifier(let ri)): return li == ri
            case (.self, .self): return true
            default: return false
            }
        }
        var name: String {
            switch self {
            case .identifier(let s): return s
            case .self: return "self"
            }
        }
    }
    
}

extension VIRGenFunction {
    /// - Note: Updates the capture handler if we read from a parent
    func variable(named name: String) throws -> ManagedValue? {
        return try variable(.identifier(name))
    }
    /// - Returns: The accessor of a variable named `name`
    /// - Note: Updates the capture handler if we read from a parent
    func variable(_ v: VIRGenScope.VariableKey) throws -> ManagedValue? {
        if let v = scope.variables[v] { return v }
        
        let foundInParent = try parent?.variable(v)
        if let f = foundInParent, let handler = scope.captureDelegate {
            // if we have a capture handler, infor that it
            // captures this accessor
            let accessor = try handler.capture(variable: f, identifier: v, gen: self)
            scope.variables[v] = accessor
            return accessor
        }
        return foundInParent
    }
    func addVariable(_ variable: ManagedValue, name: String) {
        scope.variables[.identifier(name)] = variable
    }
    func addVariable(_ variable: ManagedValue, identifier: VIRGenScope.VariableKey) {
        scope.variables[identifier] = variable
    }
}

