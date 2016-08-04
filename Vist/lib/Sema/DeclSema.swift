//
//  StructSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension TypeDecl : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        let errorCollector = ErrorCollector()
        let structScope = SemaScope.capturingScope(parent: scope, overrideReturnType: nil) // cannot return from Struct scope
        
        try errorCollector.run {
            // if its a redeclaration, throw (unless we're in the tdlib)
            if let _ = scope.type(named: name), !scope.isStdLib {
                throw semaError(.invalidTypeRedeclaration(name))
            }
        }
        
        // add generic params to scope
        structScope.genericParameters = genericParameters
        
        // maps over properties and gens types
        let members = try properties
            .flatMap { $0.declared }
            .flatMap { decl in
                try errorCollector.run { _ -> StructMember in
                    try decl.typeForNode(scope: structScope)
                    guard let t = decl.value._type else {
                        throw semaError(.structPropertyNotTyped(type: name, property: decl.name), userVisible: false)
                    }
                    return (decl.name, t, decl.isMutable)
                }
        }
        
        let cs = concepts.optionalMap { scope.concept(named: $0) }!
        let ty = StructType(members: members, methods: [], name: name, concepts: cs, isHeapAllocated: byRef)
        self.type = ty
        
        try errorCollector.run {
            ty.genericTypes = try genericParameters?.map(GenericType.fromConstraint(inScope: scope))
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
            //method.parent?.declaredType = ty
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
                return try initialiser.typeRepr.params(scope: scope).elementsEqual(memberTypes, by: ==)
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
            if let initialiserType = i.typeRepr.type {
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

extension ConceptDecl : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        let conceptScope = SemaScope(parent: scope)
        let errorCollector = ErrorCollector()
        
        try requiredMethods.walkChildren(collector: errorCollector) { method in
            try method.typeForNode(scope: conceptScope)
        }
        try requiredProperties
            .flatMap { $0.declared }
            .walkChildren(collector: errorCollector) { property in
                try property.typeForNode(scope: conceptScope)
        }
        
        let methodTypes = try requiredMethods.walkChildren(collector: errorCollector) { method throws -> StructMethod in
            guard let t = method.typeRepr.type else {
                throw semaError(.structMethodNotTyped(type: name, methodName: method.name))
            }
            return (
                name: method.name,
                type: t,
                mutating: method.attrs.contains(.mutating)
            )
        }
        let propertyTypes = try requiredProperties
            .flatMap { $0.declared }
            .walkChildren(collector: errorCollector) { prop throws -> StructMember in
                guard let t = prop.value._type else {
                    throw semaError(.structPropertyNotTyped(type: name, property: prop.name))
                }
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
            let parentType = parent?.declaredType,
            let parentName = parent?.name,
            let parentProperties = parent?.declaredType?.members
            else { throw semaError(.initialiserNotAssociatedWithType) }
        
        let params = try typeRepr.params(scope: scope)
        
        let initialiserFunctionType = FunctionType(params: params, returns: parentType)
        self.mangledName = parentName.mangle(type: initialiserFunctionType)
        
        scope.addFunction(name: parentName, type: initialiserFunctionType)
        typeRepr.type = initialiserFunctionType
        
        guard let impl = self.impl else {
            return // if no body, we're done
        }
        
        // Do sema on params, body, and expose self and its properties into the scope
        let initScope = SemaScope(parent: scope)
        
        // ad scope properties to initScope
        for p in parentProperties {
            initScope.addVariable(variable: (type: p.type, mutable: true, isImmutableCapture: false), name: p.name)
        }
        
        for (p, type) in try zip(impl.params, typeRepr.params(scope: scope)) {
            initScope.addVariable(variable: (type: type, mutable: false, isImmutableCapture: false), name: p)
        }
        
        try impl.body.walkChildren { ex in
            try ex.typeForNode(scope: initScope)
        }
        
    }
}



extension VariableDecl : DeclTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        // handle redeclaration
        if scope.thisScopeContainsVariable(named: name) {
            throw semaError(.invalidRedeclaration(name))
        }
        
        // if provided, get the explicit type
        let explicitType = try typeRepr?.typeIn(scope: scope)
        
        // scope for declaration -- not a return type and sets the `semaContext` to the explicitType
        let declScope = SemaScope(parent: scope, returnType: nil, semaContext: explicitType)
        
        let objectType = try value.typeForNode(scope: declScope)
        
        if case let fn as FunctionType = objectType {
            scope.addFunction(name: name, type: fn) // store in function table if closure
        }
        else {
            let type = explicitType ?? objectType
            scope.addVariable(variable: (type, isMutable, false), name: name)  // store in arr
        }
        
        // if its a null expression
        if let e = explicitType, value._type == BuiltinType.null, value is NullExpr {
            value._type = e
        } // otherwise, if the type is null, we are assigning to something we shouldn't be
        else if objectType == BuiltinType.null {
            throw semaError(.cannotAssignToNullExpression(name))
        }
    }
}


extension VariableGroupDecl : DeclTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        // simply type children
        for child in declared {
            try child.typeForNode(scope: scope)
        }
    }
}


