//
//  Initialiser.swift
//  Vist
//
//  Created by Josef Willsher on 15/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension StructExpression {

    /// Returns an initialiser if all objects in `self` are given an initial value
    func implicitIntialiser() -> InitialiserExpression? {
        // filter out non initilaised values, return nil if not all values have an initial value
        let values = properties.filter { !($0.value is NullExpression) }.map { $0.value }
        let names = properties.map { $0.name }
        guard values.count == properties.count else { return nil }
        
        var initialisations: [Expression] = []
        for (val, name) in zip(values, names) {
            let variable = Variable(name: name)
            let m = MutationExpression(object: variable, value: val)
            initialisations.append(m)
        }
        
        let block = BlockExpression(expressions: initialisations)
        let body = FunctionImplementationExpression(params: TupleExpression.void(), body: block)
        
        let ty = FunctionType(args: TupleExpression.void(), returns: ValueType(name: name))
        
        let exp = InitialiserExpression(ty: ty, impl: body, parent: self)
        return exp
    }
    
    // TODO: Memberwise init
    /// Returns an initialiser for each element in the struct
//    func memberwiseInitialiser() -> InitialiserExpression {
//        
//        
//        
//    }
    
}


