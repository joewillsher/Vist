//
//  Closure.swift
//  Vist
//
//  Created by Josef Willsher on 15/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 A protocol which manages usages of Accessors. `addCapture` is called
 when the handler is asked to capture this accessor into the scope
 so it can be used as a semantic variable here.
 */
protocol CaptureHandler : class {
    var captured: [Accessor] { get }
    func addCapture(variable: Accessor, scope: Scope, name: String) throws -> Accessor
}

/// A thunk object -- wraps a function. Can be used for captruing scopes
/// and partial application
protocol ThunkFunction {
    var function: Function { get }
    init(_thunkOf: Function)
}
extension ThunkFunction {
    /// Form a thunk which wraps `function`
    /// - note: Changing this will affect the wrapped function, only
    ///         use if this is the intended behaviour
    static func wrapping(function: Function) -> Self {
        return Self(_thunkOf: function)
    }
    /// Form a new thunk object from `function`
    static func createFrom(function: Function) throws -> Self {
        let type = function.type.cannonicalType(function.module)
        var ty = FunctionType(params: type.params,
                              returns: type.returns,
                              callingConvention: type.callingConvention,
                              yieldType: type.yieldType)
        ty.isCanonicalType = true
        let f = try function.module.builder.buildFunction(function.name,
                                                          type: ty.cannonicalType(function.module),
                                                          paramNames: function.params?.map{$0.paramName} ?? [])
        return Self(_thunkOf: f)
    }
}



/**
 An anonymous function, wrapping a funtion thunk allows reabstraction.
 
 Closures can capture variables, and do so by gaining a thick type.
 */
final class Closure : ThunkFunction, VHIRElement {
    let thunk: Function
    var function: Function { return thunk }
    var captured: [Accessor] = []
    private(set) var capturedGlobals: [GlobalValue] = []
    
    var thunkName = ""
    var name: String { return (thunkName+thunk.name).mangle(thunk.type)  }
    
    init(_thunkOf thunk: Function) {
        self.thunk = thunk
    }
}



extension Closure : CaptureHandler {
    
    func addCapture(variable: Accessor, scope: Scope, name: String) throws -> Accessor {
        // add to self capture list
        // update function
        
        let initialInsert = module.builder.insertPoint
        defer { module.builder.insertPoint = initialInsert }
        module.builder.insertPoint = scope.breakPoint!

        let g: GlobalValue, accessor: GetSetAccessor
        
        if
            case let variableAccessor as GetSetAccessor = variable,
            case let decl as GetSetAccessor = try scope.parent?.variableNamed(name),
            let type = variableAccessor.mem.type {
           
            g = GlobalValue(name: "\(name).globlstorage", type: type)
            try module.builder.buildStore(decl.aggregateReference(), in: PtrOperand(g))
            accessor = GlobalIndirectRefAccessor(memory: g, module: function.module)
        }
        else if
            let type = variable.storedType,
            let decl = try scope.parent?.variableNamed(name) {
            
            g = GlobalValue(name: "\(name).globl", type: type)
            try module.builder.buildStore(Operand(decl.aggregateGetter()), in: PtrOperand(g))
            accessor = GlobalRefAccessor(memory: g, module: function.module)
        }
        else {
            fatalError()
        }
        
        scope.insert(accessor, name: name)
        captured.append(variable)
        capturedGlobals.append(g)
        module.globalValues.insert(g)
        return accessor
    }
    
    
    var vhir: String { return thunk.vhir }
    var module: Module { return thunk.module }
}


