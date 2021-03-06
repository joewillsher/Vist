//
//  Initialiser.swift
//  Vist
//
//  Created by Josef Willsher on 15/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension TypeDecl {

    /// Returns an initialiser if all objects in `self` are given an initial value
    func implicitIntialiser() -> InitDecl? {
        // filter out non initilaised values, return nil if not all values have an initial value
        let properties = self.properties.flatMap { $0.declared }
        let values = properties.flatMap { $0.value }
        let names = properties.map { $0.name }
        guard values.count == properties.count else { return nil }
        
        var initialisations: [ASTNode] = []
        for (val, name) in zip(values, names) {
            let variable = VariableExpr(name: name)
            let m = MutationExpr(object: variable, value: val)
            initialisations.append(m)
        }
        
        let block = BlockExpr(exprs: initialisations, parameters: [])
        let body = FunctionBodyExpr(params: [], body: block)
        
        let ty = FunctionTypeRepr(paramType: .void,
                                  returnType: .type(name))
        
        return InitDecl(ty: ty, impl: body, parent: self, isImplicit: true)
    }
    
    /// Returns an initialiser for each element in the struct
    func memberwiseInitialiser() throws -> InitDecl? {
        // filter out non initilaised values, return nil if not all values have an initial value
        let properties = self.properties.flatMap { $0.declared }
        let names = properties.map { $0.name }
        
        guard let types = properties.optionalMap({ $0.type }) else {
            throw semaError(.noMemberwiseInit, userVisible: false)
        }
        
        // FIXME: we dont emit memberwise inits for types which dont contain just nominal types
        guard !types.contains(where: {type in (type is TupleType)}) else {
            return nil
        }
        
        var initialisations: [ASTNode] = []
        for (i, name) in names.enumerated() {
            let object = VariableExpr(name: name)
            let value = VariableExpr(name: "$\(i)")
            let m = MutationExpr(object: object, value: value)
            initialisations.append(m)
        }
        
        let params = (0..<names.count).map { "$\($0)" }
        let block = BlockExpr(exprs: initialisations, parameters: params)
        let body = FunctionBodyExpr(params: params, body: block)
        
        let ty = FunctionTypeRepr(paramType: TypeRepr(types: types),
                                  returnType: .type(name))
        return InitDecl(ty: ty,
                        impl: body,
                        parent: self,
                        isImplicit: true)
    }
    
}


