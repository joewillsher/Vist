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
    
    func llvmType(scope: SemaScope) throws -> Ty {
        let ty = StdLib.IntType
        self.type = ty
        return ty
    }
}

extension FloatingPointLiteral : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        let ty = StdLib.DoubleType
        self.type = ty
        return ty
    }
}

extension BooleanLiteral : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        let ty = StdLib.BoolType
        self.type = ty
        return ty
    }
}

extension StringLiteral : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        let t = BuiltinType.Array(el: BuiltinType.Int(size: 8), size: UInt32(count))
        self.type = t
        return t
    }
}

extension NullExpr : ExprTypeProvider {
    
    mutating func llvmType(scope: SemaScope) throws -> Ty {
        _type = nil
        return BuiltinType.Null
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension VariableExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // lookup variable type in scope
        guard let v = scope[variable: name] else {
            throw error(SemaError.NoVariable(name))
        }
        
        // assign type to self and return
        self._type = v.type
        return v.type
    }
}


extension MutationExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // gen types for variable and value
        let old = try object.llvmType(scope)
        let new = try value.llvmType(scope)
        
        guard old == new else { throw error(SemaError.DifferentTypeForMutation(object.desc, old, new)) }
        
        switch object {
        case let variable as VariableExpr:
            
            guard let v = scope[variable: variable.name] else { throw error(SemaError.NoVariable(variable.name)) }
            guard v.mutable else { throw error(SemaError.ImmutableVariable(variable.name)) }
            
        case let propertyLookup as PropertyLookupExpr:
            
            let objectName = propertyLookup.object.desc
            let object = scope[variable: objectName]
            
            guard case let type as StructType = object?.type else { throw error(SemaError.NoVariable(objectName)) }
            guard let mutable = object?.mutable where mutable else { throw error(SemaError.ImmutableVariable(objectName)) }
                
            guard try type.propertyMutable(propertyLookup.name) else { throw error(SemaError.ImmutableProperty(p: propertyLookup.name, obj: objectName, ty: type.name)) }
            
        case let memberLookup as TupleMemberLookupExpr:
            
            let objectName = memberLookup.object.desc
            let object = scope[variable: objectName]
            
            guard case _ as TupleType = object?.type else { throw error(SemaError.NoVariable(objectName)) }
            guard let mutable = object?.mutable where mutable else { throw error(SemaError.ImmutableVariable(objectName)) }
            
        default:
            break
        }
        
        return BuiltinType.Null
    }
}


extension VariableDecl : DeclTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        // handle redeclaration
        if let _ = scope[variable: name] {
            throw error(SemaError.InvalidRedeclaration(name))
        }
        
        // if provided, get the explicit type
        let explicitType = try aType?.type()
        
        // scope for declaration -- not a return type and sets the `semaContext` to the explicitType
        let declScope = SemaScope(parent: scope, returnType: nil, semaContext: explicitType)
        
        let objectType = try value.llvmType(declScope)
        
        if case let fn as FnType = objectType {
            scope[function: name] = fn          // store in function table if closure
        }
        else {
            scope[variable: name] = (objectType, isMutable)  // store in arr
        }
        
        // if its a null expression
        if let e = explicitType where value._type == BuiltinType.Null && value is NullExpr {
            value._type = e
        } // otherwise, if the type is null, we are assigning to something we shouldn't be
        else if objectType == BuiltinType.Null {
            throw error(SemaError.CannotAssignToNullExpression(name))
        }
        
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Exprs
//-------------------------------------------------------------------------------------------------------------------------


extension Void : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        self.type = BuiltinType.Void
        return BuiltinType.Void
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------


extension ClosureExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
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
            try exp.llvmType(innerScope)
        }
        
        return ty
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // element types
        var types: [Ty] = []
        for el in arr {
            types.append(try el.llvmType(scope))
        }
        
        // make sure array is homogeneous
        guard Set(types.map { $0.ir() }).count == 1 else { throw error(SemaError.HeterogenousArray(types)) }
        
        // get element type and assign to self
        guard let elementType = types.first else { throw error(SemaError.EmptyArray) }
        self.elType = elementType
        
        // assign array type to self and return
        let t = BuiltinType.Array(el: elementType, size: UInt32(arr.count))
        self.type = t
        return t
    }
    
}

extension ArraySubscriptExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // make sure its an array
        guard case let v as VariableExpr = arr, case BuiltinType.Array(let type, _)? = scope[variable: v.name]?.type else { throw error(SemaError.CannotSubscriptNonArrayVariable) }
        
        // gen type for subscripting value
        guard try index.llvmType(scope) == StdLib.IntType else { throw error(SemaError.NonIntegerSubscript) }
        
        // assign type to self and return
        self._type = type
        return type
    }
    
}

