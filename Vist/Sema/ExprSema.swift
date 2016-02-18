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
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        let ty = StdLib.IntType
        self.type = ty
        return ty
    }
}

extension FloatingPointLiteral : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        let ty = StdLib.DoubleType
        self.type = ty
        return ty
    }
}

extension BooleanLiteral : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        let ty = StdLib.BoolType
        self.type = ty
        return ty
    }
}

extension StringLiteral : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        let t = BuiltinType.Array(el: BuiltinType.Int(size: 8), size: UInt32(count))
        self.type = t
        return t
    }
}

extension NullExpr : ExprTypeProvider {
    
    mutating func typeForNode(scope: SemaScope) throws -> Ty {
        _type = nil
        return BuiltinType.Null
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension VariableExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        // lookup variable type in scope
        guard let v = scope[variable: name] else {
            throw error(SemaError.noVariable(name))
        }
        
        // assign type to self and return
        self._type = v.type
        return v.type
    }
}


extension MutationExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        // gen types for variable and value
        let old = try object.typeForNode(scope)
        let new = try value.typeForNode(scope)
        
        guard old == new else { throw error(SemaError.differentTypeForMutation(object.typeName, old, new)) }
        
        switch object {
        case let variable as VariableExpr:
            
            guard let v = scope[variable: variable.name] else { throw error(SemaError.noVariable(variable.name)) }
            guard v.mutable else { throw error(SemaError.immutableVariable(variable.name)) }
            
        case let propertyLookup as PropertyLookupExpr:
            
            guard case let type as StorageType = propertyLookup.object._type else { throw error(SemaError.notStructType(propertyLookup._type)) }
            let (_, mutable) = try propertyLookup.recursiveType(scope)
            guard mutable else { throw error(SemaError.immutableObject(type: type.explicitName)) }
            
            guard try type.propertyMutable(propertyLookup.propertyName) else { throw error(SemaError.immutableProperty(p: propertyLookup.propertyName, ty: type.explicitName)) }
            
        case let memberLookup as TupleMemberLookupExpr:
            break
//            let objectName = memberLookup.object.desc
//            let object = scope[variable: objectName]
//            
//            guard case _ as TupleType = object?.type else { throw error(SemaError.noVariable(objectName)) }
//            guard let mutable = object?.mutable where mutable else { throw error(SemaError.immutableVariable(objectName)) }
            
            // TODO: checks on mutation expressions
            
        default:
            break
        }
        
        return BuiltinType.Null
    }
}

extension ChainableExpr {
    
    func recursiveType(scope: SemaScope) throws -> (type: Ty, mutable: Bool) {
        
        switch self {
        case let variable as VariableExpr:
            guard let v = scope[variable: variable.name] else { throw error(SemaError.noVariable(variable.name)) }
            return v
            
        case let propertyLookup as PropertyLookupExpr:
            guard case let (objectType as StorageType, mutable) = try propertyLookup.object.recursiveType(scope) else { throw error(SemaError.notStructType(propertyLookup._type!)) }
            return (
                type: try objectType.propertyType(propertyLookup.propertyName),
                mutable: try objectType.propertyMutable(propertyLookup.propertyName) && mutable
            )
            
        case let tupleMemberLookup as TupleMemberLookupExpr:
            guard case let (objectType as TupleType, mutable) = try tupleMemberLookup.object.recursiveType(scope) else { throw error(SemaError.notTupleType(tupleMemberLookup._type!)) }
            return (
                type: try objectType.propertyType(tupleMemberLookup.index),
                mutable: mutable
            )

        case let intLiteral as IntegerLiteral:
            guard case let t as StorageType = intLiteral.type else { throw error(SemaError.noStdIntType, userVisible: false) }
            return (type: t, mutable: false)
            
//        case let tuple as TupleExpr:
//            return (type: _type, )
//            
        default:
            throw error(SemaError.notValidLookup, userVisible: false)
        }
        
    }
    
}



extension VariableDecl : DeclTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        // handle redeclaration
        if scope.containsVariable(name) {
            throw error(SemaError.invalidTypeRedeclaration(name))
        }
        
        // if provided, get the explicit type
        let explicitType = try aType?.type(scope)
        
        // scope for declaration -- not a return type and sets the `semaContext` to the explicitType
        let declScope = SemaScope(parent: scope, returnType: nil, semaContext: explicitType)
        
        let objectType = try value.typeForNode(declScope)
        
        if case let fn as FnType = objectType {
            scope.addFunction(name, type: fn) // store in function table if closure
        }
        else {
            let type = explicitType ?? objectType
            scope[variable: name] = (type, isMutable) // store in arr
        }
        
        // if its a null expression
        if let e = explicitType where value._type == BuiltinType.Null && value is NullExpr {
            value._type = e
        } // otherwise, if the type is null, we are assigning to something we shouldn't be
        else if objectType == BuiltinType.Null {
            throw error(SemaError.cannotAssignToNullExpression(name))
        }
        
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Exprs
//-------------------------------------------------------------------------------------------------------------------------


extension Void : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        self.type = BuiltinType.Void
        return BuiltinType.Void
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------


extension ClosureExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        // no type inferrence from param list, just from AST context
        let ty = (scope.semaContext as? FnType) ?? FnType(params: [BuiltinType.Void], returns: BuiltinType.Void)
        self.type = ty
        
        // we dont want implicit captutring
        let innerScope = SemaScope.nonCapturingScope(scope, returnType: ty)
        innerScope.returnType = ty.returns
        
        for (i, t) in ty.params.enumerate() {
            let name = parameters.isEmpty ? i.implicitParamName() : parameters[i]
            innerScope[variable: name] = (type: t, mutable: false)
        }
        
        // TODO: Implementation relying on parameters
        // Specify which parameters from the scope are copied into the closure
        //  - this is needed for method calls -- as `self` needs to be copied in
        // Make syntax for the users to define this
        
        for exp in exprs {
            try exp.typeForNode(innerScope)
        }
        
        return ty
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        // element types
        var types: [Ty] = []
        for el in arr {
            types.append(try el.typeForNode(scope))
        }
        
        // make sure array is homogeneous
        guard Set(types.map { $0.globalType(nil) }).count == 1 else { throw error(SemaError.heterogenousArray(types)) }
        
        // get element type and assign to self
        guard let elementType = types.first else { throw error(SemaError.emptyArray) }
        self.elType = elementType
        
        // assign array type to self and return
        let t = BuiltinType.Array(el: elementType, size: UInt32(arr.count))
        self.type = t
        return t
    }
    
}

extension ArraySubscriptExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        // make sure its an array
        guard case let v as VariableExpr = arr, case BuiltinType.Array(let type, _)? = scope[variable: v.name]?.type else { throw error(SemaError.cannotSubscriptNonArrayVariable) }
        
        // gen type for subscripting value
        guard try index.typeForNode(scope) == StdLib.IntType else { throw error(SemaError.nonIntegerSubscript) }
        
        // assign type to self and return
        self._type = type
        return type
    }
    
}

