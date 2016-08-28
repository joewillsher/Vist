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
    func capture(variable: ManagedValue, scope: VIRGenScope, name: String) throws -> ManagedValue
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
    
    func capture(variable: ManagedValue, scope: VIRGenScope, name: String) throws -> ManagedValue {
//        // add to self capture list
//        // update function
//        
//        let initialInsert = module.builder.insertPoint
//        defer { module.builder.insertPoint = initialInsert }
//        module.builder.insertPoint = scope.breakPoint!
//
//        let g: GlobalValue, accessor: IndirectAccessor
//        
//        if
//            case let variableAccessor as IndirectAccessor = variable,
//            case let decl as IndirectAccessor = try scope.parent?.variable(named: name),
//            let type = variableAccessor.mem.type {
//           
//            g = GlobalValue(name: "\(name).globlstorage", type: type, module: module)
//            try module.builder.build(StoreInst(address: g, value: decl.aggregateReference()))
//            accessor = GlobalIndirectRefAccessor(memory: g, module: function.module)
//        }
//        else if
//            let type = variable.storedType,
//            let decl = try scope.parent?.variable(named: name) {
//            
//            g = GlobalValue(name: "\(name).globl", type: type, module: module)
//            try module.builder.build(StoreInst(address: g, value: decl.aggregateGetValue()))
//            accessor = GlobalRefAccessor(memory: g, module: function.module)
//        }
//        else {
//            fatalError()
//        }
//        
//        scope.insert(variable: accessor, name: name)
//        captured.append(variable)
//        capturedGlobals.append(g)
//        module.globalValues.insert(g)
//        return accessor
        return variable
    }
    
    
    var vir: String { return thunk.vir }
    var module: Module { return thunk.module }
}


