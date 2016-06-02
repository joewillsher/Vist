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
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        let errorCollector = ErrorCollector()
        let structScope = SemaScope(parent: scope, returnType: nil) // cannot return from Struct scope
        
        try errorCollector.run {
            // if its a redeclaration, throw (unless we're in the tdlib)
            if let _ = scope.type(named: name) where !scope.isStdLib {
                throw semaError(.invalidTypeRedeclaration(name))
            }
        }
        
        // add generic params to scope
        structScope.genericParameters = genericParameters
        
        // maps over properties and gens types
        let members = try properties.flatMap { (a: VariableDecl) -> StructMember? in
            return try errorCollector.run {
                try a.typeForNode(scope: structScope)
                guard let t = a.value._type else { throw semaError(.structPropertyNotTyped(type: name, property: a.name), userVisible: false) }
                return (a.name, t, a.isMutable)
            }
        }
        
        let cs = concepts.optionalMap { scope.concept(named: $0) }!
        let ty = StructType(members: members, methods: [], name: name, concepts: cs, heapAllocated: byRef)
        self.type = ty
        
        try errorCollector.run {
            ty.genericTypes = try genericParameters.map(GenericType.fromConstraint(inScope: scope))
        }
        
        let memberFunctions = try methods.flatMap { (method: FuncDecl) -> StructMethod? in
            return try errorCollector.run {
                let t = try method.genFunctionInterface(scope: scope)
                let mutableSelf = method.attrs.contains(.mutating)
                return (name: method.name, type: t, mutating: mutableSelf)
            }
        }

        ty.methods = memberFunctions
        
        scope.addType(ty, name: name)
        self.type = ty

        for method in methods {
            method.parent?._type = ty
            try errorCollector.run {
                let declScope = SemaScope(parent: scope)
                declScope.genericParameters = method.genericParameters
                try method.typeForNode(scope: declScope)
            }
        }
        

        
        if let implicit = implicitIntialiser() {
            initialisers.append(implicit)
        }
        
        try errorCollector.run {
            let definesOwnMemberwiseInit = try initialisers.contains { initialiser in
                let memberTypes = ty.members.map { $0.type }
                return try initialiser.ty.params(scope: scope).elementsEqual(memberTypes, isEquivalent: ==)
            }
            
            if !definesOwnMemberwiseInit {
                if let memberwiseInit = try memberwiseInitialiser() {
                    initialisers.append(memberwiseInit)
                }
            }
        }
        try initialisers.walkChildren(collector: errorCollector) { node in
            try node.typeForNode(scope: structScope)
        }
        
        for i in initialisers {
            if let initialiserType = i.ty.type {
                scope.addFunction(name: name, type: initialiserType)
            }
        }
        
        // check it satisfies its explicit constraints
        for c in ty.concepts {
            try errorCollector.run {
                guard ty.models(concept: c) else {
                    throw semaError(.noModel(type: ty, concept: c))
                }
            }
        }
        
        try errorCollector.throwIfErrors()
        
        return ty
    }
    
}

extension ConceptExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        let conceptScope = SemaScope(parent: scope)
        let errorCollector = ErrorCollector()
        
        try requiredMethods.walkChildren(collector: errorCollector) { method in
            try method.typeForNode(scope: conceptScope)
        }
        try requiredProperties.walkChildren(collector: errorCollector) { property in
            try property.typeForNode(scope: conceptScope)
        }
        
        let methodTypes = try requiredMethods.walkChildren(collector: errorCollector) { method throws -> StructMethod in
            guard let t = method.fnType.type else { throw semaError(.structMethodNotTyped(type: name, methodName: method.name)) }
            let mutableSelf = method.attrs.contains(.mutating)
            return (name: method.name, type: t, mutating: mutableSelf)
        }
        let propertyTypes = try requiredProperties.walkChildren(collector: errorCollector) { prop throws -> StructMember in
            guard let t = prop.value._type else { throw semaError(.structPropertyNotTyped(type: name, property: prop.name)) }
            return (prop.name, t, true)
        }
        
        let ty = ConceptType(name: name, requiredFunctions: methodTypes, requiredProperties: propertyTypes)
        
        scope.addConcept(ty, name: name)
        
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
            else { throw semaError(.initialiserNotAssociatedWithType) }
        
        let params = try ty.params(scope: scope)
        
        let initialiserFunctionType = FunctionType(params: params, returns: parentType)
        self.mangledName = parentName.mangle(type: initialiserFunctionType)
        
        scope.addFunction(name: parentName, type: initialiserFunctionType)
        ty.type = initialiserFunctionType
        
        guard let impl = self.impl else {
            return // if no body, we're done
        }
        
        // Do sema on params, body, and expose self and its properties into the scope
        
        let initScope = SemaScope(parent: scope)
        
        // ad scope properties to initScope
        for p in parentProperties {
            guard let propType = p.value._type else { throw semaError(.paramsNotTyped, userVisible: false) }
            initScope.addVariable(variable: (type: propType, mutable: true, isImmutableCapture: false), name: p.name)
        }
        
        for (p, type) in zip(impl.params, try ty.params(scope: scope)) {
            initScope.addVariable(variable: (type: type, mutable: false, isImmutableCapture: false), name: p)
        }
        
        try impl.body.walkChildren { ex in
            try ex.typeForNode(scope: initScope)
        }
        
    }
}

extension PropertyLookupExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        guard case let objType as NominalType = try object.typeForNode(scope: scope) else { throw semaError(.noTypeForStruct, userVisible: false) }
        
        let propertyType = try objType.propertyType(name: propertyName)
        self._type = propertyType
        return propertyType
    }
    
}

extension MethodCallExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        let ty = try object.typeForNode(scope: scope)
        guard case let parentType as NominalType = ty else { throw semaError(.notStructType(ty), userVisible: false) }
        
        let args = try self.args.elements.map { arg in try arg.typeForNode(scope: scope) }
        
        let fnType = try parentType.methodType(methodNamed: name, argTypes: args)
        mangledName = name.mangle(type: fnType)
        
        guard case .method(_, let mutatingMethod) = fnType.callingConvention else { throw semaError(.functionNotMethod, userVisible: false) }
        let (baseType, _, allowsMutation) = try object.recursiveType(scope: scope)
        
        if mutatingMethod && !allowsMutation {
            throw semaError(.mutatingMethodOnImmutable(method: name, baseType: baseType.explicitName))
        }
        
        // gen types for objects in call
        for arg in self.args.elements {
            _ = try arg.typeForNode(scope: scope)
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

extension TupleExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        guard elements.count != 0 else {
            let t = BuiltinType.void
            self._type = t
            return t
        }
        
        let tys = try elements.map { try $0.typeForNode(scope: scope) }
        let t = TupleType(members: tys)
        _type = t
        return t
    }
}

extension TupleMemberLookupExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        guard case let objType as TupleType = try object.typeForNode(scope: scope) else { throw semaError(.noTypeForTuple, userVisible: false) }
        
        let propertyType = try objType.elementType(at: index)
        self._type = propertyType
        return propertyType
    }
}




