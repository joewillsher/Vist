//
//  TypeProvider.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol TypeProvider {
    /// Function used to traverse AST and get type information for all its objects
    ///
    /// Each implementation of this function should **call `.llvmType` on all of its sub exprs**
    ///
    /// The function implementation **should assign the result type to self** as well as returning it
    func llvmType(scope: SemaScope) throws -> Ty
}

// TODO: make private
extension TypeProvider {
    func llvmType(scope: SemaScope) throws -> Ty {
        return BuiltinType.Null
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Literals
//-------------------------------------------------------------------------------------------------------------------------

extension IntegerLiteral : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        guard let ty = scope[type: "Int"] else { fatalError("No Std Int type") }
        self.type = ty
        return ty
    }
}

extension FloatingPointLiteral : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        let ty = BuiltinType.Float(size: size) // TODO: Float stdlib
        self.type = ty
        return ty
    }
}

extension BooleanLiteral : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        guard let ty = scope[type: "Bool"] else { fatalError("No Std Bool type") }
        self.type = ty
        return ty
    }
}

extension StringLiteral : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        let t = BuiltinType.Array(el: BuiltinType.Int(size: 8), size: UInt32(count))
        self.type = t
        return t
//        let a = str.characters.map { CharacterExpression(c: $0) as Expr }
//        arr = ArrayExpression(arr: a)
//        
//        let t = try arr!.llvmType(scope)
//        self.type = t
//        return t
    }
}

//extension CharacterExpr : TypeProvider {
//    
//    func llvmType(scope: SemaScope) throws -> Ty {
//        let t = LLVMType.Int(size: 8)
//        self.type = t
//        return t
//    }
//}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Variable : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // lookup variable type in scope
        guard let v = scope[variable: name] else {
            throw SemaError.NoVariable(name)
        }
        
        // assign type to self and return
        self.type = v
        return v
    }
}


extension VariableDecl : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        // handle redeclaration
        if let _ = scope[variable: name] { throw SemaError.InvalidRedeclaration(name, value) }
        
        // get val type
        let explicitType = BuiltinType(aType ?? "") as? Ty ?? scope[type: aType ?? ""]
        let inferredType = try value.llvmType(scope)
        
        if let fn = (explicitType ?? inferredType) as? FnType {
            scope[function: name] = fn              // store in function table if closure
        }
        else {
            scope[variable: name] = inferredType    // store in arr
        }
        
        value.type = explicitType ?? inferredType       // store type in value’s type
        return BuiltinType.Void                            // return void type for assignment Expr
    }
}


extension MutationExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // gen types for variable and value
        let old = try object.llvmType(scope)
        let new = try value.llvmType(scope)
        guard old == new else { throw SemaError.DifferentTypeForMutation }
        
        return BuiltinType.Null
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Exprs
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        let args = [lhs, rhs]
        
        let params = try args.map { try $0.llvmType(scope) }
        
        guard let fnType = scope[function: op, paramTypes: params] else {
            if let f = scope[function: op] { throw SemaError.WrongFunctionApplications(name: op, applied: params, expected: f.params) }
            throw SemaError.NoFunction(op)
        }
        
        self.mangledName = op.mangle(fnType)
        
        // gen types for objects in call
        for arg in args {
            try arg.llvmType(scope)
        }
        
        // assign type to self and return
        self.type = fnType.returns
        return fnType.returns
    }
}


extension Void : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        self.type = BuiltinType.Void
        return BuiltinType.Void
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------

/// Curried function, returns a function which takes a ValueType object and returns the correct type
private func getType<
    TypeCollection : CollectionType
    where TypeCollection.Generator.Element == StructType>
    (tys: TypeCollection) -> ValueType throws -> Ty {
        
    return { (ty: ValueType) -> Ty in
        if let builtin = BuiltinType(ty.name) as? Ty { return builtin }
        else if let i = (tys.indexOf { ty.name == $0.name }) { return tys[i] as Ty }
        throw SemaError.TypeNotFound
    }
}

private extension FunctionType {
    
    func params<
        TypeCollection : CollectionType
        where TypeCollection.Generator.Element == StructType>
        (tys: TypeCollection)
        throws -> [Ty] {
            
            let res = try args.elements.mapAs(ValueType).map(getType(tys))
            return res
    }
    
    func returnType<
        TypeCollection : CollectionType
        where TypeCollection.Generator.Element == StructType>
        (tys: TypeCollection)
        throws -> Ty {
            
            if let tup = returns as? TupleExpr {
                
                if tup.elements.count == 0 { return BuiltinType.Void }
                
                let res = try tup.elements.mapAs(ValueType).map(getType(tys))
                guard res.count == tup.elements.count else { throw SemaError.TypeNotFound }
                return StructType.withProperties(res, gen: {"\($0)"})
            }
            else if let f = returns as? FunctionType {
                
                return FnType(params: try f.params(tys), returns: try f.returnType(tys))
            }
            else if let x = returns as? ValueType {
                
                if let val = BuiltinType(x.name) {
                    return val
                }
                else if let i = (tys.indexOf { $0.name == x.name }) {
                    return tys[i]
                }
                else {
                    throw SemaError.NoTypeNamed(x.name)
                }
            }
            
            return BuiltinType.Null
    }
}


extension FunctionCallExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // get from table
        let params = try args.elements.map { try $0.llvmType(scope) }
        
        guard let fnType = scope[function: name, paramTypes: params] else {
            if let f = scope[function: name] {
                throw SemaError.WrongFunctionApplications(name: name, applied: params, expected: f.params)
            }
            throw SemaError.NoFunction(name)
        }
        
        self.mangledName = name.mangle(fnType)
        
        // gen types for objects in call
        for arg in args.elements {
            try arg.llvmType(scope)
        }
        
        // assign type to self and return
        self.type = fnType.returns
        return fnType.returns
    }
}


extension FunctionDecl : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        let ty = FnType(params: try fnType.params(scope.allTypes), returns: try fnType.returnType(scope.allTypes))
        
        if let p = parent?.name {
            mangledName = name.mangle(ty, parentTypeName: p)
        } else {
            mangledName = name.mangle(ty)
        }
        
        scope[function: name] = ty  // update function table
        fnType.type = ty            // store type in fntype
        
        guard let functionScopeExpression = impl?.body else { return BuiltinType.Void }
        // if body construct scope and parse inside it
        
        let fnScope = SemaScope(parent: scope, returnType: ty.returns)
        
        for (i, v) in (impl?.params.elements ?? []).enumerate() {
            
            let n = (v as? ValueType)?.name ?? "$\(i)"
            let t = try fnType.params(scope.allTypes)[i]
            
            try v.llvmType(fnScope)
            
            fnScope[variable: n] = t
        }
        
        if let t = parent?.type {
            fnScope[variable: "self"] = t
        }
        
        // type gen for inner scope
        for exp in functionScopeExpression.exprs {
            try exp.llvmType(fnScope)
        }
        
        return BuiltinType.Void
    }
}


extension ReturnStmt : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        scope.objectType = scope.returnType // set hint to return type
        
        let returnType = try expr.llvmType(scope)
        guard let ret = scope.returnType where ret == returnType else {
            throw SemaError.WrongFunctionReturnType(applied: returnType, expected: scope.returnType ?? BuiltinType.Null)
        }
        
        scope.objectType = nil // reset
        
        return BuiltinType.Null
    }
    
}


extension ClosureExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        let ty = (scope.objectType as? FnType) ?? FnType(params: [BuiltinType.Void], returns: BuiltinType.Void)
        self.type = ty

        // inner scope should be nil if we dont want implicit captutring
        let innerScope = SemaScope(parent: nil, returnType: ty)
        innerScope.returnType = ty.returns
        
        for (i, t) in ty.params.enumerate() {
            let name = parameters.isEmpty ? "$\(i)" : parameters[i]
            innerScope[variable: name] = t
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
//  MARK:                                                 Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension ConditionalStmt : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // call on child `ElseIfBlockExpressions`
        for statement in statements {
            // inner scopes
            let ifScope = SemaScope(parent: scope, returnType: scope.returnType)
            
            try statement.llvmType(ifScope)
        }
        
        return BuiltinType.Null
    }
}


extension ElseIfBlockStmt : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // get condition type
        let c = try condition?.llvmType(scope)
        guard let cond = c where cond.isStdBool else { throw SemaError.NonBooleanCondition }
        
        // gen types for cond block
        for exp in block.exprs {
            try exp.llvmType(scope)
        }
        
        return BuiltinType.Null
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Loops
//-------------------------------------------------------------------------------------------------------------------------


extension ForInLoopStmt : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // add bound name to scopes
        loopScope[variable: binded.name] = scope[type: "Int"]
        
        // gen types for iterator
        guard try iterator.llvmType(scope).isStdRange else { throw SemaError.NotRangeType }
        
        // parse inside of loop in loop scope
        for exp in block.exprs {
            try exp.llvmType(loopScope)
        }
        
        return BuiltinType.Null
    }
    
}


extension WhileLoopExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // gen types for iterator
        let it = try condition.llvmType(scope)
        guard it.isStdBool else { throw SemaError.NonBooleanCondition }
        
        // parse inside of loop in loop scope
        for exp in block.exprs {
            try exp.llvmType(loopScope)
        }
        
        return BuiltinType.Null
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // element types
        var types: [Ty] = []
        for i in 0..<arr.count {
            let el = arr[i]
            let t = try el.llvmType(scope)
            types.append(t)
        }
        
        // make sure array is homogeneous
        guard Set(types.map { $0.ir() }).count == 1 else { throw SemaError.HeterogenousArray(description) }
        
        // get element type and assign to self
        guard let elementType = types.first else { throw SemaError.EmptyArray }
        self.elType = elementType
        
        // assign array type to self and return
        let t = BuiltinType.Array(el: elementType, size: UInt32(arr.count))
        self.type = t
        return t
    }
    
}

extension ArraySubscriptExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // get array variable
        guard let name = (arr as? Variable)?.name else { throw SemaError.NotVariableType }
        
        // make sure its an array
        guard case BuiltinType.Array(let type, _)? = scope[variable: name] else { throw SemaError.CannotSubscriptNonArrayVariable }
        
        // gen type for subscripting value
        guard case BuiltinType.Int = try index.llvmType(scope) else { throw SemaError.NonIntegerSubscript }
        
        // assign type to self and return
        self.type = type
        return type
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Structs
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        let structScope = SemaScope(parent: scope, returnType: nil) // cannot return from Struct scope
        
        // maps over properties and gens types
        let members = try properties.map { (a: VariableDecl) -> (String, Ty, Bool) in
            try a.llvmType(structScope)
            guard let t = a.value.type else { throw SemaError.StructPropertyNotTyped }
            return (a.name, t, a.isMutable)
        }
        
        let ty = StructType(members: members, methods: [], name: name)
        
        scope[type: name] = ty
        self.type = ty
        
        let memberFunctions = try methods.flatMap { (f: FunctionDecl) -> (String, FnType) in
            try f.llvmType(structScope)
            guard let t = f.fnType.type as? FnType else { throw SemaError.StructMethodNotTyped }
            return (f.name.mangle(t, parentTypeName: name), t)
        }
        
        ty.methods = memberFunctions
        
        if let implicit = implicitIntialiser() {
            initialisers.append(implicit)
        }
        
        for i in initialisers {
            try i.llvmType(scope)
        }
        
        return ty
    }

}



extension InitialiserDecl : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard
            let parentType = parent?.type,
            let parentName = parent?.name,
            let parentProperties = parent?.properties
            else {
                throw SemaError.InitialiserNotAssociatedWithType
        }
        
        let params = try ty.params(scope.allTypes)
        
        let t = FnType(params: params, returns: parentType)
        self.mangledName = parentName.mangle(t)
        
        scope[function: parentName] = t
        ty.type = t
        
        guard let impl = self.impl else {
            return t
        }
        
        let initScope = SemaScope(parent: scope)
        
        // ad scope properties to initScope
        for p in parentProperties {
            initScope[variable: p.name] = p.value.type
        }
        
        for (p, type) in zip(impl.params.elements, try ty.params(scope.allTypes)) {
            
            if let param = p as? ValueType {
                initScope[variable: param.name] = type
            }
        }
        
        for ex in impl.body.exprs {
            try ex.llvmType(initScope)
        }
        
        return t
    }
}

extension PropertyLookupExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard let objType = try object.llvmType(scope) as? StructType else { throw SemaError.NoTypeFor(object) }
        guard let propertyType = try objType.propertyType(name) else { throw SemaError.NoPropertyNamed(name) }
        self.type = propertyType
        return propertyType
    }
    
}

extension MethodCallExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard let parentType = try object.llvmType(scope) as? StructType else { fatalError("Not struct type") }
        
        let params = try self.params.elements.map { try $0.llvmType(scope) }
        
        guard let fnType = parentType[function: name, paramTypes: params] else { throw SemaError.NoFunction(name) }
        
        self.mangledName = name.mangle(fnType, parentTypeName: parentType.name)
        
        guard params == fnType.params else {
            throw SemaError.WrongFunctionApplications(name: "\(parentType.name).\(name)", applied: params, expected: fnType.params)
        }
        
        // gen types for objects in call
        for arg in self.params.elements {
            try arg.llvmType(scope)
        }
        
        // assign type to self and return
        self.type = fnType.returns
        return fnType.returns
    }
}





//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Tuples
//-------------------------------------------------------------------------------------------------------------------------

extension TupleExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard elements.count != 1 else { return BuiltinType.Void }
        
        let tys = try elements
            .map { try $0.llvmType(scope) }
        
        let t = TupleType(members: tys)
        type = t
        return t
    }
}

extension TupleMemberLookupExpr : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        guard let objType = try object.llvmType(scope) as? StructType else { throw SemaError.NoTypeFor(object) }
        guard let propertyType = try objType.propertyType("\(index)") else { throw SemaError.TupleHasNoObjectAtIndex(index) }
        self.type = propertyType
        return propertyType
    }
}







