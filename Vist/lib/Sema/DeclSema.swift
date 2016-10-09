//
//  StructSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension TypeDecl : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
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
        
        // type checks properties
        let members = try properties
            .flatMap { $0.declared }
            .flatMap { decl in
                try errorCollector.run { _ -> StructMember in
                    try decl.typeCheckNode(scope: structScope)
                    guard let t = decl.type else {
                        throw semaError(.structPropertyNotTyped(type: name, property: decl.name), userVisible: false)
                    }
                    return (decl.name, t, decl.isMutable)
                }
        }
        
        // Find conforming concepts
        let cs = concepts.optionalMap { scope.concept(named: $0) }!
        let ty = StructType(members: members, methods: [], name: name, concepts: cs, isHeapAllocated: byRef)
        self.type = ty
        
        // Add generic params
        try errorCollector.run {
            ty.genericTypes = try genericParameters?.map(GenericType.fromConstraint(inScope: scope))
        }
        
        // Get the types of the methods
        let memberFunctions = try methods.flatMap { (method: FuncDecl) -> StructMethod? in
            return try errorCollector.run {
                let t = try method.genFunctionInterface(scope: scope, addToScope: true)
                let mutableSelf = method.attrs.contains(.mutating)
                guard let mangledName = method.mangledName else {
                    throw semaError(.noMangledName(unmangled: method.name), userVisible: false)
                }
                return (name: mangledName, type: t, mutating: mutableSelf)
            }
        }
        ty.methods = memberFunctions
        
        // Record the (now finalised) type
        scope.addType(ty, name: name)
        self.type = ty

        for method in methods {
            // type check the method bodies
            try errorCollector.run {
                let declScope = SemaScope(parent: scope)
                declScope.genericParameters = method.genericParameters
                try method.typeCheckNode(scope: declScope)
            }
        }
        
        // define an implicit initialiser
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
        // type check the initialisers
        try initialisers.walkChildren(collector: errorCollector) { node in
            try node.typeCheckNode(scope: structScope)
        }
        try deinitialisers.walkChildren(collector: errorCollector) { node in
            try node.typeCheckNode(scope: structScope)
        }
        
        for i in initialisers {
            if let initialiserType = i.typeRepr.type {
                // ad initialisers to outer scope
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
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        // inner concept scope
        let conceptScope = SemaScope.capturingScope(parent: scope, overrideReturnType: nil)
        let errorCollector = ErrorCollector()
        
        // type check properties briefly
        try requiredProperties
            .flatMap { $0.declared }
            .walkChildren(collector: errorCollector) { property in
                try property.typeCheckNode(scope: conceptScope)
        }
        // define a placeholder type, this is so inner contexts see theyre in a method
        let placeholder = ConceptType(name: name, requiredFunctions: [], requiredProperties: [])
        self.type = placeholder
        
        // get the method types
        let methodTypes = try requiredMethods.walkChildren(collector: errorCollector) { method throws -> StructMethod in
            // add the method&type to outer scope
            let t = try method.genFunctionInterface(scope: scope, addToScope: true)
            
            guard let mangledName = method.mangledName else {
                throw semaError(.noMangledName(unmangled: method.name), userVisible: false)
            }
            // requirememnts cannot have a body
            guard !method.hasBody else {
                throw semaError(.conceptBody(concept: placeholder, function: method))
            }
            
            return (
                name: mangledName,
                type: t,
                mutating: method.attrs.contains(.mutating)
            )
        }
        // get property types from the typecked nodes
        let propertyTypes = try requiredProperties
            .flatMap { $0.declared }
            .walkChildren(collector: errorCollector) { prop throws -> StructMember in
                guard let t = prop.type else {
                    throw semaError(.structPropertyNotTyped(type: name, property: prop.name))
                }
                return (prop.name, t, true)
        }
        // define the concept
        let ty = ConceptType(name: name, requiredFunctions: methodTypes, requiredProperties: propertyTypes)
        scope.addConcept(ty, name: name)
        
        // fix self references
        for method in requiredMethods {
            try method.typeCheckNode(scope: scope)
        }
        
        try errorCollector.throwIfErrors()
        
        self.type = ty
        return ty
    }
    
}



extension InitDecl : DeclTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws {
        
        guard
            let parentType = parent?.declaredType,
            let parentName = parent?.name,
            let parentProperties = parent?.declaredType?.members
            else { throw semaError(.initialiserNotAssociatedWithType) }
        
        let params = try typeRepr.params(scope: scope)
        
        let initialiserFunctionType = FunctionType(params: params, returns: parentType, callingConvention: .initialiser)
        mangledName = parentName.mangle(type: initialiserFunctionType)
        typeRepr.type = initialiserFunctionType
        
        scope.addFunction(name: parentName, type: initialiserFunctionType)
        
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
            try ex.typeCheckNode(scope: initScope)
        }
        
    }
}

extension DeinitDecl : DeclTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws {
        
        guard
            let parentType = parent?.declaredType,
            let parentProperties = parent?.declaredType?.members
            else { throw semaError(.deinitialiserNotAssociatedWithType) }
        
        // must be a ref type
        guard parentType.isHeapAllocated else {
            throw semaError(.deinitNonRefType(parentType))
        }
        guard let impl = self.impl else {
            throw semaError(.noDeinitBody)
        }
        
        // Do sema on params, body, and expose self and its properties into the scope
        let initScope = SemaScope(parent: scope)
        self.mangledName = "deinit".mangle(type: deinitType!)
        
        initScope.addVariable(variable: (type: parentType, mutable: true, isImmutableCapture: false), name: "self")
        // ad scope properties to initScope
        for p in parentProperties {
            initScope.addVariable(variable: (type: p.type, mutable: true, isImmutableCapture: false), name: p.name)
        }
        
        try impl.body.walkChildren { ex in
            try ex.typeCheckNode(scope: initScope)
        }
        
    }
}


extension VariableDecl : DeclTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws {
        // handle redeclaration
        if scope.thisScopeContainsVariable(named: name) {
            throw semaError(.invalidRedeclaration(name))
        }
        
        // if provided, get the explicit type
        let explicitType = try typeRepr?.typeIn(scope)
        
        // scope for declaration -- not a return type and sets the `semaContext` to the explicitType
        let scopeName = scope.name ?? ""
        let contextName = (explicitType as? FunctionType).map {
            scopeName.mangle(type: $0) + "." + self.name
        } ?? (scopeName + "." + self.name) // default to the unmangled
        let declScope = SemaScope.capturingScope(parent: scope,
                                                 overrideReturnType: nil,
                                                 context: explicitType,
                                                 scopeName: contextName)
        
        let objectType = try value?.typeCheckNode(scope: declScope)
        
        // if the type is null and no explicit type is specified, diagnose
        if explicitType == nil, value == nil {
            throw semaError(.cannotAssignToNullExpression(name))
        }
        
        let type = explicitType ?? objectType!
        scope.addVariable(variable: (type, isMutable, false), name: name)
        
        if let ex = explicitType, objectType != explicitType {
            try objectType?.addConstraint(ex, solver: scope.constraintSolver)
            // if we implicitly coerce the expr
            value = value.map { ImplicitCoercionExpr(expr: $0, type: ex) }
        }
        
        self.type = type
    }
}


extension VariableGroupDecl : DeclTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws {
        // simply type children
        for child in declared {
            try child.typeCheckNode(scope: scope)
        }
    }
}


