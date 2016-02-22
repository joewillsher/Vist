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

extension StructExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let errorCollector = ErrorCollector()
        let structScope = SemaScope(parent: scope, returnType: nil) // cannot return from Struct scope
        
        try errorCollector.run {
            if let _ = scope[type: name] {
                throw semaError(.invalidTypeRedeclaration(name))
            }
        }
        
        // add generic params to scope
        structScope.genericParameters = genericParameters
        
        // maps over properties and gens types
        let members = try properties.flatMap { (a: VariableDecl) -> StructMember? in
            return try errorCollector.run {
                try a.typeForNode(structScope)
                guard let t = a.value._type else { throw semaError(.structPropertyNotTyped(type: name, property: a.name), userVisible: false) }
                return (a.name, t, a.isMutable)
            }
        }
        
        var ty = StructType(members: members, methods: [], name: name)
        
        try errorCollector.run {
            ty.genericTypes = try genericParameters.map(GenericType.fromConstraint(inScope: scope))
        }
        
        let memberFunctions = try methods.flatMap { (f: FuncDecl) -> StructMethod? in
            return try errorCollector.run {
                try f.typeForNode(structScope)
                guard let t = f.fnType.type else { throw semaError(.structMethodNotTyped(type: name, methodName: f.name), userVisible: false) }
                return (f.name.mangle(t, parentTypeName: name), t)
            }
        }
        
        ty.methods = memberFunctions
        
        scope[type: name] = ty
        self.type = ty

        if let implicit = implicitIntialiser() {
            initialisers.append(implicit)
        }
        
        try errorCollector.run {
            let memberwise = try memberwiseInitialiser()
            initialisers.append(memberwise)
        }
        try initialisers.walkChildren(errorCollector) { node in
            try node.typeForNode(structScope)
        }
        
        for  i in initialisers {
            if let initialiserType = i.ty.type {
                scope.addFunction(name, type: initialiserType)
            }
        }
        
        try errorCollector.throwIfErrors()
        
        return ty
    }
    
}

extension ConceptExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let conceptScope = SemaScope(parent: scope)
        let errorCollector = ErrorCollector()
        
        try requiredMethods.walkChildren(errorCollector) { method in
            try method.typeForNode(conceptScope)
        }
        try requiredProperties.walkChildren(errorCollector) { property in
            try property.typeForNode(conceptScope)
        }
        
        let methodTypes = try requiredMethods.walkChildren(errorCollector) { method throws -> StructMethod in
            if let t = method.fnType.type { return (method.name, t) }
            throw semaError(.structMethodNotTyped(type: name, methodName: method.name))
        }
        let propertyTypes = try requiredProperties.walkChildren(errorCollector) { prop throws -> StructMember in
            if let t = prop.value._type { return (prop.name, t, true) }
            throw semaError(.structPropertyNotTyped(type: name, property: prop.name))
        }
        
        let ty = ConceptType(name: name, requiredFunctions: methodTypes, requiredProperties: propertyTypes)
        
        scope[concept: name] = ty
        
        try errorCollector.throwIfErrors()
        
        self.type = ty
        return ty
    }
    
}



extension InitialiserDecl: DeclTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        guard
            let parentType = parent?.type,
            let parentName = parent?.name,
            let parentProperties = parent?.properties
            else { throw semaError(.initialiserNotAssociatedWithType) }
        
        let params = try ty.params(scope)
        
        let initialiserFunctionType = FnType(params: params, returns: parentType)
        self.mangledName = parentName.mangle(initialiserFunctionType)
        
        scope.addFunction(parentName, type: initialiserFunctionType)
        ty.type = initialiserFunctionType
        
        guard let impl = self.impl else {
            return // if no body, we're done
        }
        
        // Do sema on params, body, and expose self and its properties into the scope
        
        let initScope = SemaScope(parent: scope)
        
        // ad scope properties to initScope
        for p in parentProperties {
            guard let propType = p.value._type else { throw semaError(.paramsNotTyped, userVisible: false) }
            initScope[variable: p.name] = (type: propType, mutable: true)
        }
        
        for (p, type) in zip(impl.params, try ty.params(scope)) {
            initScope[variable: p] = (type: type, mutable: false)
        }
        
        try impl.body.walkChildren { ex in
            try ex.typeForNode(initScope)
        }
        
    }
}

extension PropertyLookupExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        guard case let objType as StorageType = try object.typeForNode(scope) else { throw semaError(.noTypeForStruct, userVisible: false) }
        
        let propertyType = try objType.propertyType(propertyName)
        self._type = propertyType
        return propertyType
    }
    
}

extension MethodCallExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let ty = try object.typeForNode(scope)
        guard case let parentType as StorageType = ty else { throw semaError(.notStructType(ty), userVisible: false) }
        
        let args = try self.args.elements.map { try $0.typeForNode(scope) }
        
        guard let fnType = parentType.getMethodType(name, argTypes: args) else { throw semaError(.noFunction(name, args)) }
        mangledName = name.mangle(fnType, parentTypeName: parentType.name)
        
        // gen types for objects in call
        for arg in self.args.elements {
            try arg.typeForNode(scope)
        }
        
        // assign type to self and return
        self._type = fnType.returns
        self.fnType = fnType
        self.structType = parentType
        return fnType.returns
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Tuples
//-------------------------------------------------------------------------------------------------------------------------

extension TupleExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        guard elements.count != 0 else { return BuiltinType.void }
        
        let tys = try elements.map { try $0.typeForNode(scope) }
        let t = TupleType(members: tys)
        type = t
        return t
    }
}

extension TupleMemberLookupExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        guard case let objType as TupleType = try object.typeForNode(scope) else { throw semaError(.noTypeForTuple, userVisible: false) }
        
        let propertyType = try objType.propertyType(index)
        self._type = propertyType
        return propertyType
    }
}




