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
        let type = variable.storedType!
        
        let initialInsert = module.builder.insertPoint
        module.builder.insertPoint = scope.breakPoint!
        
        let decl = try scope.parent!.variableNamed(name)!
        let g = GlobalValue(name: "\(name).global", type: type)
        try module.builder.buildStore(Operand(decl.aggregateGetter()), in: PtrOperand(g))
        
        let accessor = GlobalRefAccessor(memory: g, module: function.module)
        scope.add(accessor, name: name)
        module.globalValues.insert(g)
        
        module.builder.insertPoint = initialInsert
        
        return accessor
    }
//    
//    mutating func removeCapture(variable: Accessor) throws {
//        let c: [Type], s: Type?, m: Bool?
//        if case .thick(let captured) = thunk.type.callingConvention {
//            c = captured
//            s = nil
//            m = nil
//        }
//        else if case .thickMethod(let sType, let mut, let captured) = thunk.type.callingConvention {
//            c = captured
//            s = sType
//            m = mut
//        }
//        else { fatalError() }
//        
//        
//        let i = captured.indexOf { capture in capture === variable }!
//        let a = c.enumerate().filter({$0.0 != i}).map({$0.1})
//        captured.removeAtIndex(i)
//        if case .thickMethod(let s, let m, _) = thunk.type.callingConvention {
//            thunk.type.callingConvention = .thin
//        }
//        else {
//            thunk.type.callingConvention = .thick(capturing: a)
//        }
//    }
    
    var vhir: String { return thunk.vhir }
    var module: Module { return thunk.module }
}


