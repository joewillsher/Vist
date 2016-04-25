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
    
    func typeForNode(scope: SemaScope) throws -> Type {
        // TODO: modify the AST to make this a function call
        let ty = StdLib.intType
        self.type = ty
        return ty
    }
}

extension FloatingPointLiteral : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        let ty = StdLib.doubleType
        self.type = ty
        return ty
    }
}

extension BooleanLiteral : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        let ty = StdLib.boolType
        self.type = ty
        return ty
    }
}

extension StringLiteral : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        let t = StdLib.stringType
        self.type = t
        return t
    }
}

extension NullExpr : ExprTypeProvider {
    
    mutating func typeForNode(scope: SemaScope) throws -> Type {
        _type = nil
        return BuiltinType.null
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension VariableExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        // lookup variable type in scope
        guard let v = scope[variable: name] else {
            throw semaError(.noVariable(name))
        }
        
        // assign type to self and return
        self._type = v.type
        return v.type
    }
}


extension MutationExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        // gen types for variable and value
        let old = try object.typeForNode(scope)
        let new = try value.typeForNode(scope)
        
        // make sure consistent types
        guard old == new else { throw semaError(.differentTypeForMutation(name: (object as? VariableExpr)?.name, from: old, to: new)) }

        // switch over object being mutated
        switch object {
        case let variable as VariableExpr:
            
            guard let v = scope[variable: variable.name] else { throw semaError(.noVariable(variable.name)) }
            guard v.mutable else { throw semaError(.immutableVariable(name: variable.name, type: variable.typeName)) }
            
        case let lookup as LookupExpr:
            // if its a lookup expression we can 
            
            guard let type = lookup.object._type else { throw semaError(.notStructType(lookup._type)) }
            let (_, parentMutable, mutable) = try lookup.recursiveType(scope)
            
            guard let p = parentMutable where p else {
                // provide nice error -- if its a variable we can put its name in the error message using '.immutableVariable'
                if case let v as VariableExpr = lookup.object { throw semaError(.immutableVariable(name: v.name, type: v.typeName)) }
                else { throw semaError(.immutableObject(type: type.vir)) }
            }
            
            switch lookup {
            case let tuple as TupleMemberLookupExpr:
                guard mutable else { throw semaError(.immutableTupleMember(index: tuple.index)) }

            case let prop as PropertyLookupExpr:
                guard mutable else { throw semaError(.immutableProperty(p: prop.propertyName, ty: type.vir)) }
                
            default:
                throw semaError(.unreachable("All lookup types accounted for"), userVisible: false)
            }
            
        default:
            throw semaError(.todo("Other chainable types need mutability debugging"))
        }
        
        return BuiltinType.null
    }
}


// TODO: Define rvalue and lvalue prototol to constrain assignments and stuff
extension ChainableExpr {
    
    func recursiveType(scope: SemaScope) throws -> (type: Type, parentMutable: Bool?, mutable: Bool) {
        
        switch self {
        case let variable as VariableExpr:
            guard let (type, mutable) = scope[variable: variable.name] else { throw semaError(.noVariable(variable.name)) }
            return (type: type, parentMutable: nil, mutable: mutable)
            
        case let propertyLookup as PropertyLookupExpr:
            guard case let (objectType as StorageType, parentMutable, objectMutable) = try propertyLookup.object.recursiveType(scope) else {
                throw semaError(.notStructType(propertyLookup._type!))
            }
            return (
                type: try objectType.propertyType(propertyLookup.propertyName),
                parentMutable: objectMutable && (parentMutable ?? true),
                mutable: try objectType.propertyIsMutable(propertyLookup.propertyName)
            )
            
        case let tupleMemberLookup as TupleMemberLookupExpr:
            guard case let (objectType as TupleType, _, tupleMutable) = try tupleMemberLookup.object.recursiveType(scope) else {
                throw semaError(.notTupleType(tupleMemberLookup._type!))
            }
            return (
                type: try objectType.propertyType(tupleMemberLookup.index),
                parentMutable: tupleMutable,
                mutable: tupleMutable
            )

        case let intLiteral as IntegerLiteral:
            guard case let t as StorageType = intLiteral.type else { throw semaError(.noStdIntType, userVisible: false) }
            return (type: t, parentMutable: nil, mutable: false)
            
//        case let tuple as TupleExpr:
//            return (type: _type, )
            
        default:
            throw semaError(.notValidLookup, userVisible: false)
        }
        
    }
    
}



extension VariableDecl : DeclTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        // handle redeclaration
        if scope.containsVariable(name) {
            throw semaError(.invalidRedeclaration(name))
        }
        
        // if provided, get the explicit type
        let explicitType = try aType?.typeInScope(scope)
        
        // scope for declaration -- not a return type and sets the `semaContext` to the explicitType
        let declScope = SemaScope(parent: scope, returnType: nil, semaContext: explicitType)
        
        let objectType = try value.typeForNode(declScope)
        
        if case let fn as FunctionType = objectType {
            scope.addFunction(name, type: fn) // store in function table if closure
        }
        else {
            let type = explicitType ?? objectType
            scope[variable: name] = (type, isMutable) // store in arr
        }
        
        // if its a null expression
        if let e = explicitType where value._type == BuiltinType.null && value is NullExpr {
            value._type = e
        } // otherwise, if the type is null, we are assigning to something we shouldn't be
        else if objectType == BuiltinType.null {
            throw semaError(.cannotAssignToNullExpression(name))
        }
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Exprs
//-------------------------------------------------------------------------------------------------------------------------


extension Void : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        self.type = BuiltinType.void
        return BuiltinType.void
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------


extension ClosureExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        // no type inferrence from param list, just from AST context
        let ty = (scope.semaContext as? FunctionType) ?? FunctionType(params: [BuiltinType.void], returns: BuiltinType.void)
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
        // Make syntax for the users to define this?
        
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
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        // element types
        let types = try arr.map { el in try el.typeForNode(scope) }
        
        // make sure array is homogeneous
        guard !types.contains({types.first != $0}) else { throw semaError(.heterogenousArray(types)) }
        
        // get element type and assign to self
        guard let elementType = types.first else { throw semaError(.emptyArray) }
        self.elType = elementType
        
        // assign array type to self and return
        let t = BuiltinType.array(el: elementType, size: arr.count)
        self.type = t
        return t
    }
    
}

extension ArraySubscriptExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        
        // make sure its an array
        guard case let v as VariableExpr = arr, case BuiltinType.array(let type, _)? = scope[variable: v.name]?.type else { throw semaError(.cannotSubscriptNonArrayVariable) }
        
        // gen type for subscripting value
        guard try index.typeForNode(scope) == StdLib.intType else { throw semaError(.nonIntegerSubscript) }
        
        // assign type to self and return
        self._type = type
        return type
    }
    
}

