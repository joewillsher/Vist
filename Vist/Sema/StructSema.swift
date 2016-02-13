//
//  StructSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Structs
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let errorCollector = ErrorCollector()
        let structScope = SemaScope(parent: scope, returnType: nil) // cannot return from Struct scope
        
        // add generic params to scope
        structScope.genericParameters = genericParameters
        
        // maps over properties and gens types
        let members = try properties.flatMap { (a: VariableDecl) -> StructMember? in
            
            try a.typeForNode(structScope)
            guard let t = a.value._type else { throw error(SemaError.StructPropertyNotTyped(type: name, property: a.name), userVisible: false) }
            return (a.name, t, a.isMutable)
        }
        
        
        var ty = StructType(members: members, methods: [], name: name)
        
        scope[type: name] = ty
        self.type = ty
        
        let memberFunctions = try methods.flatMap { (f: FuncDecl) -> StructMethod? in
            
            try f.typeForNode(structScope)
            guard let t = f.fnType.type else { throw error(SemaError.StructMethodNotTyped(type: name, methodName: f.name), userVisible: false) }
            return (f.name.mangle(t, parentTypeName: name), t)
        }
        
        ty.methods = memberFunctions
        
        if let implicit = implicitIntialiser() {
            initialisers.append(implicit)
        }
        
        let memberwise = try memberwiseInitialiser()
        initialisers.append(memberwise)
        
        try initialisers.walkChildren(errorCollector) { node in
            try node.typeForNode(structScope)
        }
        
        for i in initialisers {
            scope[function: name] = i.ty.type
        }
        
        try errorCollector.throwIfErrors()
        
        return ty
    }
    
}

extension ConceptExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let conceptScope = SemaScope(parent: scope)
        let errorCollector = ErrorCollector()
        
        try requiredMethods.walkChildren(errorCollector) { method in
            try method.typeForNode(conceptScope)
        }
        try errorCollector.run {
            try requiredProperties.walkChildren(errorCollector) { method in
                try method.typeForNode(conceptScope)
            }
        }
        
        let methodTypes = try requiredMethods.walkChildren(errorCollector) { method throws -> StructMethod in
            if let t = method.fnType.type { return (method.name, t) }
            throw error(SemaError.StructMethodNotTyped(type: name, methodName: method.name))
        }
        let propertyTypes = try requiredProperties.walkChildren(errorCollector) { prop throws -> StructMember in
            if let t = prop.value._type { return (prop.name, t, true) }
            throw error(SemaError.StructPropertyNotTyped(type: name, property: prop.name))
        }
        
        let ty = ConceptType(name: name, requiredFunctions: methodTypes, requiredProperties: propertyTypes)
        
        scope[concept: name] = ty
        
        try errorCollector.throwIfErrors()
        
        self.type = ty
        return ty
    }
    
}



extension InitialiserDecl : DeclTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        guard
            let parentType = parent?.type,
            let parentName = parent?.name,
            let parentProperties = parent?.properties
            else { throw error(SemaError.InitialiserNotAssociatedWithType) }
        
        let params = try ty.params(scope)
        
        let t = FnType(params: params, returns: parentType)
        self.mangledName = parentName.mangle(t)
        
        scope[function: parentName] = t
        ty.type = t
        
        guard let impl = self.impl else {
            return
        }
        
        let initScope = SemaScope(parent: scope)
        
        // ad scope properties to initScope
        for p in parentProperties {
            
            guard let t = p.value._type else { throw error(SemaError.ParamsNotTyped, userVisible: false) }
            initScope[variable: p.name] = (type: t, mutable: true)
        }
        
        for (p, type) in zip(impl.params, try ty.params(scope)) {
            initScope[variable: p] = (type: type, mutable: false)
        }
        
        try impl.body.walkChildren { ex in
            try ex.typeForNode(initScope)
        }
        
    }
}

extension PropertyLookupExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        guard case let objType as StorageType = try object.typeForNode(scope) else { throw error(SemaError.NoTypeForStruct, userVisible: false) }
        
        let propertyType = try objType.propertyType(name)
        self._type = propertyType
        return propertyType
    }
    
}

extension MethodCallExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let ty = try object.typeForNode(scope)
        guard case let parentType as StructType = ty else { throw error(SemaError.NotStructType(ty), userVisible: false) }
        
        let args = try self.args.elements.map { try $0.typeForNode(scope) }
        
        guard let fnType = parentType.getMethod(name, argTypes: args) else { throw error(SemaError.NoFunction(name, args)) }
        
        self.mangledName = name.mangle(fnType, parentTypeName: parentType.name)
        
        // gen types for objects in call
        for arg in self.args.elements {
            try arg.typeForNode(scope)
        }
        
        // assign type to self and return
        self._type = fnType.returns
        self.structType = parentType
        return fnType.returns
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Tuples
//-------------------------------------------------------------------------------------------------------------------------

extension TupleExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        guard elements.count != 1 else { return BuiltinType.Void }
        
        let tys = try elements.map { try $0.typeForNode(scope) }
        
        let t = TupleType(members: tys)
        type = t
        return t
    }
}

extension TupleMemberLookupExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        guard case let objType as TupleType = try object.typeForNode(scope) else { throw error(SemaError.NoTypeForTuple, userVisible: false) }
        
        let propertyType = try objType.propertyType(index)
        self._type = propertyType
        return propertyType
    }
}




