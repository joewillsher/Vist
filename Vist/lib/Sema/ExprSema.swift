//
//  ExprSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Literals
//-------------------------------------------------------------------------------------------------------------------------

extension IntegerLiteral : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        let ty = StdLib.intType
        self.type = ty
        return ty
    }
}

extension FloatingPointLiteral : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        let ty = StdLib.doubleType
        self.type = ty
        return ty
    }
}

extension BooleanLiteral : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        let ty = StdLib.boolType
        self.type = ty
        return ty
    }
}

extension StringLiteral : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        let t = StdLib.stringType
        self.type = t
        return t
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension VariableExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        // lookup variable type in scope
        guard let v = scope.variable(named: name) else {
            throw semaError(.noVariable(name))
        }
        // assign type to self and return
        self._type = v.type
        return v.type
    }
}

extension SelfExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        guard let type = scope.declContext else {
            throw semaError(.selfNonTypeContext)
        }
        self._type = type
        return type
    }
}


extension MutationExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        // gen types for variable and value
        let old = try object.typeCheckNode(scope: scope)
        let new = try value.typeCheckNode(scope: scope)
        
        // make sure consistent types
        guard new.canAddConstraint(old, solver: scope.constraintSolver) else {
            throw semaError(.differentTypeForMutation(name: (object as? VariableExpr)?.name, from: old, to: new))
        }
        try new.addConstraint(old, solver: scope.constraintSolver)
        
        // switch over object being mutated
        switch object {
        case let variable as VariableExpr:
            
            guard let v = scope.variable(named: variable.name) else { throw semaError(.noVariable(variable.name)) }
            guard v.mutable else {
                // it's immutable, eek -- diagnose
                if v.isImmutableCapture {
                    // if we are mutating self
                    throw semaError(.immutableCapture(name: variable.name))
                }
                else {
                    throw semaError(.immutableVariable(name: variable.name, type: variable.typeName))
                }
            }
            
        case let lookup as LookupExpr:
            // if its a lookup expression we can 
            
            guard let type = lookup.object._type else {
                throw semaError(.notStructType(lookup._type))
            }
            let (_, parentMutable, mutable) = try lookup.recursiveType(scope: scope)
            
            guard let p = parentMutable, p else {
                // provide nice error -- if its a variable we can put its name in the error message using '.immutableVariable'
                if case let v as VariableExpr = lookup.object { throw semaError(.immutableVariable(name: v.name, type: v.typeName)) }
                else { throw semaError(.immutableObject(type: type)) }
            }
            
            switch lookup {
            case let tuple as TupleMemberLookupExpr:
                guard mutable else { throw semaError(.immutableTupleMember(index: tuple.index)) }
            case let prop as PropertyLookupExpr:
                guard mutable else { throw semaError(.immutableProperty(p: prop.propertyName, ty: type)) }
            default:
                throw semaError(.unreachable("All lookup types accounted for"), userVisible: false)
            }
            
        default:
            throw semaError(.todo("Other chainable types need work"), userVisible: false)
        }
        
        return BuiltinType.null
    }
}

extension CoercionExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        let oldType = try base.typeCheckNode(scope: scope)
        let newType = try type.typeIn(scope)
        
        do {
            try oldType.addConstraint(newType, solver: scope.constraintSolver)
        }
        catch SemaError.couldNotAddConstraint {
            throw semaError(.cannotCoerce(from: oldType, to: newType))
        }
        self._type = newType
        return newType
    }
    
}

extension ImplicitCoercionExpr : ExprTypeProvider {
    
    /// the expr was given a type when it was type checked
    func typeCheckNode(scope: SemaScope) throws -> Type {
        let exprType = expr._type!
        do {
            try exprType.addConstraint(type, solver: scope.constraintSolver)
        }
        catch SemaError.couldNotAddConstraint {
            throw semaError(.cannotCoerce(from: exprType, to: type))
        }
        return type
    }
    
}

extension ChainableExpr {
    
    func recursiveType(scope: SemaScope) throws -> (type: Type, parentMutable: Bool?, mutable: Bool) {
        
        switch self {
        case let variable as VariableExpr:
            guard let (type, mutable, _) = scope.variable(named: variable.name) else { throw semaError(.noVariable(variable.name)) }
            return (type: type, parentMutable: nil, mutable: mutable)
            
        case let propertyLookup as PropertyLookupExpr:
            guard case let (objectType as NominalType, parentMutable, objectMutable) = try propertyLookup.object.recursiveType(scope: scope) else {
                throw semaError(.notStructType(propertyLookup._type!))
            }
            return (
                type: try objectType.propertyType(name: propertyLookup.propertyName),
                parentMutable: objectMutable && (parentMutable ?? true),
                mutable: try objectType.propertyIsMutable(name: propertyLookup.propertyName)
            )
            
        case let tupleMemberLookup as TupleMemberLookupExpr:
            guard case let (objectType as TupleType, _, tupleMutable) = try tupleMemberLookup.object.recursiveType(scope: scope) else {
                throw semaError(.notTupleType(tupleMemberLookup._type!))
            }
            return try (
                type: objectType.elementType(at: tupleMemberLookup.index),
                parentMutable: tupleMutable,
                mutable: tupleMutable
            )
            
        case let intLiteral as IntegerLiteral:
            guard case let t as NominalType = intLiteral.type else { throw semaError(.noStdIntType, userVisible: false) }
            return (type: t, parentMutable: nil, mutable: false)
            
            // TODO: sema for tuple literal bases
//        case let tuple as TupleExpr:
//            return (type: _type, )
            
        case let selfExpr as SelfExpr:
//            return (type: selfExpr._type!, parentMutable: nil, mutable: true)
            throw semaError(.notValidLookup, userVisible: false)
            
        default:
            throw semaError(.notValidLookup, userVisible: false)
        }
        
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Exprs
//-------------------------------------------------------------------------------------------------------------------------


extension VoidExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        self.type = BuiltinType.void
        return BuiltinType.void
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------


extension ClosureExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        // If the AST context tells us the type, use that
        // otherwise create type variables for the unknown param & return types
        guard let size = parameters?.count ?? (scope.semaContext as? FunctionType)?.params.count else {
            throw semaError(.cannotInferClosureParamListSize)
        }
        
        let ty: FunctionType
        if case let context as FunctionType = scope.semaContext {
            ty = context
            hasConcreteType = true
        }
        else if scope.semaContext != nil {
            throw semaError(.closureNotFunctionType)
        }
        else {
            // constrain the type variables to any explicit type
            let paramTvs = (0..<size).map { _ in scope.constraintSolver.getTypeVariable() }
            let retTv = scope.constraintSolver.getTypeVariable()
            ty = FunctionType(params: paramTvs,
                              returns: retTv)
        }
        
        guard let mangledName = scope.name?.appending(".closure") else {
            fatalError("Closure context needs name to provide mangling")
        }
        self.mangledName = mangledName
        self.type = ty
        
        // we dont want implicit captutring
        let innerScope = SemaScope.capturing(scope,
                                                  overrideReturnType: ty.returns)
        innerScope.returnType = ty.returns
        
        // add implicit params
        if parameters == nil {
            parameters = (0..<ty.params.count).map { "$\($0)" }
        }
        guard parameters?.count == ty.params.count else { fatalError() }
        
        // add params to scope
        for (name, type) in zip(parameters!, ty.params) {
            innerScope.addVariable(variable: (type: type, mutable: false, isImmutableCapture: false),
                                   name: name)
        }
        
        // type check body
        for exp in exprs {
            try exp.typeCheckNode(scope: innerScope)
        }
        
        self.type = ty
        return ty
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        // element types
        let types = try arr.map { el in
            try el.typeCheckNode(scope: scope)
        }
        
        // make sure array is homogeneous
        guard !types.contains(where: {types.first != $0}) else {
            throw semaError(.heterogenousArray(types))
        }
        
        // get element type and assign to self
        guard let elementType = types.first else {
            throw semaError(.emptyArray)
        }
        self.elType = elementType
        
        // assign array type to self and return
        let t = BuiltinType.array(el: elementType, size: arr.count)
        self.type = t
        return t
    }
    
}

extension ArraySubscriptExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        // make sure its an array
        guard case let v as VariableExpr = arr,
            case BuiltinType.array(let type, _)? = scope.variable(named: v.name)?.type else {
            throw semaError(.cannotSubscriptNonArrayVariable)
        }
        
        // gen type for subscripting value
        guard try index.typeCheckNode(scope: scope) == StdLib.intType else {
            throw semaError(.nonIntegerSubscript)
        }
        
        // assign type to self and return
        self._type = type
        return type
    }
    
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Tuples
//-------------------------------------------------------------------------------------------------------------------------

extension TupleExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        guard elements.count != 0 else {
            let t = BuiltinType.void
            self._type = t
            return t
        }
        
        let tys = try elements.map { try $0.typeCheckNode(scope: scope) }
        let t = TupleType(members: tys)
        _type = t
        return t
    }
}

extension TupleMemberLookupExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        guard case let objType as TupleType = try object.typeCheckNode(scope: scope) else {
            throw semaError(.noTypeForTuple, userVisible: false)
        }
        
        let propertyType = try objType.elementType(at: index)
        self._type = propertyType
        return propertyType
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Types
//-------------------------------------------------------------------------------------------------------------------------


extension PropertyLookupExpr : ExprTypeProvider {
    
    func typeCheckNode(scope: SemaScope) throws -> Type {
        
        guard case let objType as NominalType = try object.typeCheckNode(scope: scope) else { throw semaError(.noTypeForStruct, userVisible: false) }
        
        let propertyType = try objType.propertyType(name: propertyName)
        self._type = propertyType
        return propertyType
    }
    
}

