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
    /// Each implementation of this function should **call `.llvmType` on all of its sub expressions**
    ///
    /// The function implementation **should assign the result type to self** as well as returning it
    func llvmType(scope: SemaScope) throws -> LLVMTyped
}

extension TypeProvider {
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        return LLVMType.Null
    }
}

@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: T, rhs: T)
    -> Bool {
    let l = (try? lhs.ir()), r = (try? rhs.ir())
    if let l = l, let r = r { return l == r } else { return false }
}
@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: LLVMTyped?, rhs: T)
    -> Bool {
    let l = (try? lhs?.ir()), r = (try? rhs.ir())
    if let l = l, let r = r { return l == r } else { return false }
}
@warn_unused_result
func ==
    (lhs: LLVMTyped, rhs: LLVMTyped)
    -> Bool {
        let l = (try? lhs.ir()), r = (try? rhs.ir())
        if let l = l, let r = r { return l == r } else { return false }
}
extension CollectionType {
    func mapAs<T>(_: T.Type) -> [T] {
        return flatMap { $0 as? T }
    }
}


extension LLVMType : Equatable {}
extension LLVMFnType : Equatable {}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Literals
//-------------------------------------------------------------------------------------------------------------------------

extension IntegerLiteral : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        let ty = LLVMType.Int(size: size)
        self.type = ty
        return ty
    }
}

extension FloatingPointLiteral : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        let ty = LLVMType.Float(size: size)
        self.type = ty
        return ty
    }
}

extension BooleanLiteral : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        self.type = LLVMType.Bool
        return LLVMType.Bool
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Variables
//-------------------------------------------------------------------------------------------------------------------------

extension Variable : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // lookup variable type in scope
        guard let v = scope[variable: name] else {
            throw SemaError.NoVariable(name) }
        
        // assign type to self and return
        self.type = v
        return v
    }
}


extension AssignmentExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        // handle redeclaration
        if let _ = scope[variable: name] { throw SemaError.InvalidRedeclaration(name, value) }
        
        // get val type
        let inferredType = try value.llvmType(scope)
        
        if let fn = inferredType as? LLVMFnType {
            scope[function: name] = fn              // store in function table if closure
        } else {
            scope[variable: name] = inferredType    // store in arr
        }
        
        type = LLVMType.Void        // set type to self
        value.type = inferredType   // store type in value’s type
        return LLVMType.Void                // return void type for assignment expression
    }
}


extension MutationExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // gen types for variable and value
        let old = try object.llvmType(scope)
        let new = try value.llvmType(scope)
        guard old == new else { throw SemaError.DifferentTypeForMutation }
        
        return LLVMType.Null
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Expressions
//-------------------------------------------------------------------------------------------------------------------------

extension BinaryExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // FIXME: this is kinda a hack: these should be stdlib implementations -- operators should be user definable and looked up from the vars scope like functions
        switch op {
        case "<", ">", "==", "!=", ">=", "<=":
            try lhs.llvmType(scope)
            try rhs.llvmType(scope)
            
            self.type = LLVMType.Bool
            return LLVMType.Bool
            
        default:
            let a = try lhs.llvmType(scope)
            let b = try rhs.llvmType(scope)
            
            // if same object
            if a == b {
                // assign type to self and return
                self.type = a
                return a
                
            } else { throw SemaError.DifferentTypesForOperator(op) }
        }
        
        
    }
}


extension Void : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        self.type = LLVMType.Void
        return LLVMType.Void
    }
}

extension TupleExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        for e in elements {
            try e.llvmType(scope)
        }
        // FIXME: Tuple types
        
        type = LLVMType.Void
        return LLVMType.Void
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Functions
//-------------------------------------------------------------------------------------------------------------------------

private extension FunctionType {
    
    func params() throws -> [LLVMType] {
        let res = args.mapAs(ValueType).flatMap { LLVMType($0.name) }
        if res.count == args.elements.count { return res } else { throw SemaError.TypeNotFound }
    }
    
    func returnType() throws -> LLVMTyped {
        if let tup = returns as? TupleExpression {
            
            if tup.elements.count == 0 { return LLVMType.Void }
            
            let res = args.mapAs(ValueType).flatMap { LLVMType($0.name) }
            guard res.count == args.elements.count else { throw SemaError.TypeNotFound }
            let a = res.map { $0 as LLVMTyped }
            return a.first!
            
        } else if let f = returns as? FunctionType {
            
            return LLVMFnType(params: try f.params(), returns: try f.returnType())
            
        } else if let x = returns as? ValueType {
            
            if let val = LLVMType(x.name) { return val } else { throw SemaError.NoTypeNamed(x.name) }
        }
        
        return LLVMType.Null
    }
}


extension FunctionCallExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // get from table
        guard let fnType = scope[function: name] else { throw SemaError.NoFunction(name) }
        
        // gen types for objects in call
        for (i, arg) in args.elements.enumerate() {
            let ti = try arg.llvmType(scope)
            let expected = fnType.params[i]
            guard ti == expected else { throw SemaError.WrongFunctionApplication(applied: ti, expected: expected, paramNum: i) }
        }
        
        // assign type to self and return
        self.type = fnType.returns
        return fnType.returns
    }
}


extension FunctionPrototypeExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        let ty = LLVMFnType(params: try fnType.params(), returns: try fnType.returnType())
        
        scope[function: name] = ty  // update function table
        fnType.type = ty            // store type in fntype
        type = LLVMType.Void        // retult of prototype is void
        
        guard var functionScopeExpression = impl?.body else { return LLVMType.Void }
        // if body construct scope and parse inside it
        
        let fnScope = SemaScope(parent: scope, returnType: ty.returns)
        
        for (i, v) in (impl?.params.elements ?? []).enumerate() {
            
            let n = (v as? ValueType)?.name ?? "$\(i)"
            let t = try fnType.params()[i]
            
            fnScope[variable: n] = t
        }
        
        // type gen for inner scope
        try variableTypeSema(forScopeExpression: &functionScopeExpression, scope: fnScope)
        
        return LLVMType.Void
    }
}


extension ReturnExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        scope.objectType = scope.returnType // set hint to return type
        
        let returnType = try expression.llvmType(scope)
        guard let ret = scope.returnType where ret == returnType else { throw SemaError.WrongFunctionReturnType(applied: returnType, expected: scope.returnType ?? LLVMType.Null) }
        
        scope.objectType = nil // reset
        
        self.type = LLVMType.Null
        return LLVMType.Null
    }
    
}


extension ClosureExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        let ty = (scope.objectType as? LLVMFnType) ?? LLVMFnType(params: [LLVMType.Void], returns: LLVMType.Void)
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
        
        for exp in expressions {
            try exp.llvmType(innerScope)
        }
        
        return ty
    }
}





//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension ConditionalExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // call on child `ElseIfBlockExpressions`
        for statement in statements {
            // inner scopes
            let ifScope = SemaScope(parent: scope, returnType: scope.returnType)
            
            try statement.llvmType(ifScope)
        }
        
        type = LLVMType.Null
        return LLVMType.Null
    }
}


extension ElseIfBlockExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // get condition type
        let cond = try condition?.llvmType(scope)
        guard cond == LLVMType.Bool || cond == nil else { throw SemaError.NonBooleanCondition }
        
        // gen types for cond block
        try variableTypeSema(forScopeExpression: &block, scope: scope)
        
        self.type = LLVMType.Null
        return LLVMType.Null
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Loops
//-------------------------------------------------------------------------------------------------------------------------

extension RangeIteratorExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // gen types for start and end
        let s = try start.llvmType(scope)
        let e = try end.llvmType(scope)
        
        // make sure range has same start and end types
        guard e == s else { throw SemaError.RangeWithInconsistentTypes }
        
        self.type = LLVMType.Null
        return LLVMType.Null
    }
    
}


extension ForInLoopExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // add bound name to scopes
        loopScope[variable: binded.name] = LLVMType.Int(size: 64)
        
        // gen types for iterator
        try iterator.llvmType(scope)
        
        // parse inside of loop in loop scope
        try variableTypeSema(forScopeExpression: &block, scope: loopScope)
        
        return LLVMType.Null
    }
    
}


extension WhileLoopExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // gen types for iterator
        let it = try iterator.llvmType(scope)
        guard it == LLVMType.Bool else { throw SemaError.NonBooleanCondition }
        
        // parse inside of loop in loop scope
        try variableTypeSema(forScopeExpression: &block, scope: loopScope)
        
        type = LLVMType.Null
        return LLVMType.Null
    }
}

extension WhileIteratorExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // make condition variable and make sure bool
        let t = try condition.llvmType(scope)
        guard t == LLVMType.Bool else { throw SemaError.NonBooleanCondition }
        
        type = LLVMType.Bool
        return LLVMType.Bool
    }
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Arrays
//-------------------------------------------------------------------------------------------------------------------------

extension ArrayExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // element types
        var types: [LLVMTyped] = []
        for i in 0..<arr.count {
            let el = arr[i]
            let t = try el.llvmType(scope)
            types.append(t)
        }
        
        // make sure array is homogeneous
        guard Set(try types.map { try $0.ir() }).count == 1 else { throw SemaError.HeterogenousArray(description) }
        
        // get element type and assign to self
        guard let elementType = types.first else { throw SemaError.EmptyArray }
        self.elType = elementType
        
        // assign array type to self and return
        let t = LLVMType.Array(el: elementType, size: UInt32(arr.count))
        self.type = t
        return t
    }
    
}

extension ArraySubscriptExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        // get array variable
        guard let name = (arr as? Variable)?.name else { throw SemaError.NotVariableType }
        
        // make sure its an array
        guard case LLVMType.Array(let type, _)? = scope[variable: name] else { throw SemaError.CannotSubscriptNonArrayVariable }
        
        // gen type for subscripting value
        guard case LLVMType.Int = try index.llvmType(scope) else { throw SemaError.NonIntegerSubscript }
        
        // assign type to self and return
        self.type = type
        return type
    }
    
}



//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Structs
//-------------------------------------------------------------------------------------------------------------------------

extension StructExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        let structScope = SemaScope(parent: scope, returnType: nil) // cannot return from Struct scope
        
        // maps over properties and gens types
        let members = try properties.map { (a: AssignmentExpression) -> (String, LLVMType) in
            try a.llvmType(structScope)
            guard let t = a.value.type as? LLVMType else { throw SemaError.StructPropertyNotTyped }
            return (a.name, t)
        }
        
        let memberFunctions = try methods.flatMap { (f: FunctionPrototypeExpression) -> (String, LLVMFnType) in
            try f.llvmType(structScope)
            guard let t = f.fnType.type as? LLVMFnType else { throw SemaError.StructMethodNotTyped }
            return (f.name, t)
        }
        
        let ty = LLVMStType(members: members, methods: memberFunctions)
        
        scope[type: name] = ty
        self.type = ty
        
        for i in initialisers {
            try i.llvmType(scope)
        }
        
        return ty
    }

}


extension InitialiserExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        guard let parentType = parent?.type, parentName = parent?.name else { throw SemaError.InitialiserNotAssociatedWithType }
        
        let initScope = SemaScope(parent: scope)
        
        // ad scope properties to initScope
        for p in parent?.properties ?? [] {
            initScope[variable: p.name] = p.value.type
        }
        
        for (p, type) in zip(impl.params.elements, try ty.params()) {
            if let param = p as? ValueType {
                initScope[variable: param.name] = type
            }
        }
        
        for ex in impl.body.expressions {
            try ex.llvmType(initScope)
        }
        
        let params = try ty.params()
        
        let t = LLVMFnType(params: params, returns: parentType)
        scope[function: parentName] = t
        self.type = t
        return t
    }
}

extension PropertyLookupExpression : TypeProvider {
    
    func llvmType(scope: SemaScope) throws -> LLVMTyped {
        
        guard let objType = try object.llvmType(scope) as? LLVMStType else { throw SemaError.NoTypeFor(object) }
        guard let propertyType = try objType.propertyType(name) else { throw SemaError.NoPropertyNamed(name) }
        let t = propertyType
        self.type = t
        return t
    }
    
}





