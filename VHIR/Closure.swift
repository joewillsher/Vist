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
protocol CaptureHandler {
    mutating func addCapture(variable: Accessor, scope: Scope, name: String) throws -> Accessor
//    mutating func removeCapture(variable: Accessor) throws
}

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
struct Closure : ThunkFunction, VHIRElement {
    let thunk: Function
    var function: Function { return thunk }
    private(set) var captured: [Accessor] = []
    
    var thunkName = ""
    var name: String { return (thunkName+thunk.name).mangle(thunk.type)  }
    
    init(_thunkOf thunk: Function) {
        self.thunk = thunk
    }
}

final class GlobalValue : LValue {
    
    init(name: String, type: Type) {
        self.globalType = type
        self.globalName = name
    }
    
    var globalType: Type, globalName: String
    
    var memType: Type? { return globalType }
    var type: Type? { return BuiltinType.pointer(to: globalType) }
    
    weak var parentBlock: BasicBlock? = nil
    
    var uses: [Operand] = []
    
    var irName: String? {
        get { return globalName }
        set { }
    }
    var vhir: String { return "\(name): \(globalType)" }
}
extension GlobalValue : Hashable, Equatable {
    var hashValue: Int { return name.hashValue }
}
func == (lhs: GlobalValue, rhs: GlobalValue) -> Bool {
    return lhs.globalName == rhs.globalName
}



extension Closure : CaptureHandler {
    
    mutating func addCapture(variable: Accessor, scope: Scope, name: String) throws -> Accessor {
        // add to self capture list
        captured.append(variable)
        // update function
        
        let initialInsert = module.builder.insertPoint
        defer { module.builder.insertPoint = initialInsert }
        module.builder.insertPoint = scope.breakPoint!

        if
            case let accessor as GetSetAccessor = variable,
            case let decl as GetSetAccessor = try scope.parent?.variableNamed(name),
            let type = accessor.mem.type {
           
            let g = GlobalValue(name: "\(name).globlstorage", type: type)
            try module.builder.buildStore(decl.reference(), in: PtrOperand(g))
            
            let accessor = GlobalIndirectRefAccessor(memory: g, module: function.module)
            
            scope.add(accessor, name: name)
            module.globalValues.insert(g)
            return accessor
        }
        else if
            let type = variable.storedType,
            let decl = try scope.parent?.variableNamed(name) {
            
            let g = GlobalValue(name: "\(name).globl", type: type)
            try module.builder.buildStore(Operand(decl.aggregateGetter()), in: PtrOperand(g))

            let accessor = GlobalRefAccessor(memory: g, module: function.module)
            scope.add(accessor, name: name)
            module.globalValues.insert(g)
            return accessor
        }
        else {
            fatalError()
        }
        
    }
    
    var vhir: String { return thunk.vhir }
    var module: Module { return thunk.module }
}


