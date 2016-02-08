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
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // we manually handle errors here because
        //  - we want a shared error cache across the whole type, incl vars,inits&methods
        //  - when we map we need to capture the result values
        var errors: [VistError] = []
        
        let structScope = SemaScope(parent: scope, returnType: nil) // cannot return from Struct scope
        
        // maps over properties and gens types
        let members = try properties.flatMap { (a: VariableDecl) -> StructMember? in
            
            do {
                try a.llvmType(structScope)
                guard let t = a.value._type else { throw error(SemaError.StructPropertyNotTyped(type: name, property: a.name)) }
                return (a.name, t, a.isMutable)
            }
            catch let error as VistError {
                errors.append(error)
                return nil
            }
        }
        
        let ty = StructType(members: members, methods: [], name: name)
        
        scope[type: name] = ty
        self.type = ty
        
        let memberFunctions = try methods.flatMap { (f: FuncDecl) -> StructMethod? in
            
            do {
                try f.llvmType(structScope)
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
        
        do {
            try initialisers.walkChildren { node in
                try node.llvmType(scope)
            }
        } catch let error as VistError {
            errors.append(error)
        }
        
        try errors.throwIfErrors()
        
        return ty
    }
    
}



extension InitialiserDecl : DeclTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        
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
            try ex.llvmType(initScope)
        }
        
    }
}

extension PropertyLookupExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard case let objType as StructType = try object.llvmType(scope) else { throw error(SemaError.NoTypeForStruct, userVisible: false) }
        
        let propertyType = try objType.propertyType(name)
        self._type = propertyType
        return propertyType
    }
    
}

extension MethodCallExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        let ty = try object.llvmType(scope)
        guard case let parentType as StructType = ty else { throw error(SemaError.NotStructType(ty), userVisible: false) }
        
        let args = try self.args.elements.map { try $0.llvmType(scope) }
        
        guard let fnType = parentType.getMethod(name, argTypes: args) else { throw error(SemaError.NoFunction(name, args)) }
        
        self.mangledName = name.mangle(fnType, parentTypeName: parentType.name)
        
        // gen types for objects in call
        for arg in self.args.elements {
            try arg.llvmType(scope)
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
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard elements.count != 1 else { return BuiltinType.Void }
        
        let tys = try elements.map { try $0.llvmType(scope) }
        
        let t = TupleType(members: tys)
        type = t
        return t
    }
}

extension TupleMemberLookupExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard case let objType as TupleType = try object.llvmType(scope) else { throw error(SemaError.NoTypeForTuple, userVisible: false) }
        
        let propertyType = try objType.propertyType(index)
        self._type = propertyType
        return propertyType
    }
}




