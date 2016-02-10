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
        
        // we manually handle errors here because
        //  - we want a shared error cache across the whole type, incl vars,inits&methods
        //  - when we map we need to capture the result values
        var errors: [VistError] = []
        
        let structScope = SemaScope(parent: scope, returnType: nil) // cannot return from Struct scope
        
        // add generic params to scope
        structScope.genericParameters = genericParameters
        
        // maps over properties and gens types
        let members = try properties.flatMap { (a: VariableDecl) -> StructMember? in
            
            do {
                try a.typeForNode(structScope)
                guard let t = a.value._type else { throw error(SemaError.StructPropertyNotTyped(type: name, property: a.name)) }
                return (a.name, t, a.isMutable)
            }
            catch let error as VistError {
                errors.append(error)
                return nil
            }
        }
        
        
        var ty = StructType(members: members, methods: [], name: name)
        
        scope[type: name] = ty
        self.type = ty
        
        let memberFunctions = try methods.flatMap { (f: FuncDecl) -> StructMethod? in
            
            do {
                try f.typeForNode(structScope)
                guard let t = f.fnType.type else { throw error(SemaError.StructMethodNotTyped(type: name, methodName: f.name)) }
                return (f.name.mangle(t, parentTypeName: name), t)
            }
            catch let error as VistError {
                errors.append(error)
                return nil
            }
            
        }
        
        ty.methods = memberFunctions
        
        if let implicit = implicitIntialiser() {
            initialisers.append(implicit)
        }
        
        let memberwise = try memberwiseInitialiser()
        initialisers.append(memberwise)
        
        try initialisers.walkChildren { node in
            try node.typeForNode(structScope)
        }
        
        for i in initialisers {
            scope[function: name] = i.ty.type
        }
        
        try errors.throwIfErrors()
        
        return ty
    }
    
}

extension ConceptExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let conceptScope = SemaScope(parent: scope)
        
        var errors: [VistError] = []
        
        do {
            try requiredMethods.walkChildren { method in
                try method.typeForNode(conceptScope)
            }
        }
        catch let error as VistError {
            errors.append(error)
        }
        do {
            try requiredProperties.walkChildren { method in
                try method.typeForNode(conceptScope)
            }
        }
        catch let error as VistError {
            errors.append(error)
        }
        
        
        
        let methodTypes = try requiredMethods.walkChildren { method throws -> StructMethod in
            if let t = method.fnType.type { return (method.name, t) }
            throw error(SemaError.StructMethodNotTyped(type: name, methodName: method.name))
        }
        let propertyTypes = try requiredProperties.walkChildren { prop throws -> StructMember in
            if let t = prop.value._type { return (prop.name, t, true) }
            throw error(SemaError.StructPropertyNotTyped(type: name, property: prop.name))
        }
        
        let ty = ConceptType(name: name, requiredFunctions: methodTypes, requiredProperties: propertyTypes)
        
        scope[concept: name] = ty
        
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




