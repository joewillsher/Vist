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
protocol CaptureDelegate : class {
    var captured: [ManagedValue] { get }
    /// The delegate action to capture a vairable
    func capture(variable: ManagedValue, identifier: VIRGenScope.VariableKey, gen: VIRGenFunction) throws -> ManagedValue
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
        let type = function.type.cannonicalType(module: function.module)
        var ty = FunctionType(params: type.params,
                              returns: type.returns,
                              callingConvention: type.callingConvention,
                              yieldType: type.yieldType)
        ty.isCanonicalType = true
        let f = try function.module.builder.buildFunction(name: function.name,
                                                          type: ty.cannonicalType(module: function.module),
                                                          paramNames: function.params?.map{$0.paramName} ?? [])
        return Self(_thunkOf: f)
    }
}



/**
 An anonymous function, wrapping a funtion thunk allows reabstraction.
 
 Closures can capture variables, and do so by gaining a thick type.
 */
final class Closure : ThunkFunction, VIRElement {
    let thunk: Function
    var function: Function { return thunk }
    var captured: [ManagedValue] = []
    fileprivate(set) var capturedGlobals: [GlobalValue] = []
    
    var thunkName = ""
    var name: String { return (thunkName+thunk.name).mangle(type: thunk.type)  }
    
    init(_thunkOf thunk: Function) {
        self.thunk = thunk
    }
}



extension Closure : CaptureDelegate {
    
    func capture(variable: ManagedValue, identifier: VIRGenScope.VariableKey, gen: VIRGenFunction) throws -> ManagedValue {
        
        let initialInsert = module.builder.insertPoint
        module.builder.insertPoint = gen.scope.breakPoint!
        
        var decl = try gen.parent!.variable(identifier)!
        let type = variable.type.importedType(in: module)
        
        let g = GlobalValue(name: "\(identifier.name).globlstorage", type: type, module: module)
        // store val at call site
        let val = try decl.coerceCopyToValue(gen: gen)
        try module.builder.build(StoreInst(address: g, value: val.value))
        // move back into closure
        module.builder.insertPoint = initialInsert
        let load = try gen.builder.buildManaged(LoadInst(address: g, irName: "\(identifier.name).local"), hasCleanup: false, gen: gen)
        capturedGlobals.append(g)
        module.globalValues.insert(g)
        return load
    }
    
    
    var vir: String { return thunk.vir }
    var module: Module { return thunk.module }
}


