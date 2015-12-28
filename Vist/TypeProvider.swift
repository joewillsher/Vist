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
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType
}

extension TypeProvider {
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        return .Null
    }
}





extension IntegerLiteral : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        let ty = LLVMType.Int(size: size)
        self.type = ty
        return ty
    }
}

extension FloatingPointLiteral : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        let ty = LLVMType.Float(size: size)
        self.type = ty
        return ty
    }
}

extension BooleanLiteral : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        self.type = LLVMType.Bool
        return LLVMType.Bool
    }
}

extension Variable : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // lookup variable type in scope
        guard let v = vars[name] else { throw SemaError.NoVariable(name) }
        
        // assign type to self and return
        self.type = v
        return v
    }
}

extension BinaryExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // FIXME: this is kinda a hack: these should be stdlib implementations -- operators should be user definable and looked up from the vars scope like functions
        switch op {
        case "<", ">", "==", "!=", ">=", "<=":
            try lhs.llvmType(vars, fns: fns)
            try rhs.llvmType(vars, fns: fns)
            
            self.type = LLVMType.Bool
            return LLVMType.Bool
            
        default:
            let a = try lhs.llvmType(vars, fns: fns)
            let b = try rhs.llvmType(vars, fns: fns)
            
            // if same object
            if (try a.ir()) == (try b.ir()) {
                // assign type to self and return
                self.type = a
                return a
                
            } else { throw IRError.MisMatchedTypes }
        }
        
        
    }
}

extension Void : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        self.type = LLVMType.Void
        return .Void
    }
}






private extension FunctionType {
    
    func params() throws -> [LLVMType] {
        let res = args.mapAs(ValueType).flatMap { LLVMType($0.name) }
        if res.count == args.elements.count { return res } else { throw IRError.TypeNotFound }
    }
    
    func returnType() throws -> LLVMType {
        let res = returns.mapAs(ValueType).flatMap { LLVMType($0.name) }
        if res.count == returns.elements.count && res.count == 0 { return LLVMType.Void }
        if let f = res.first where res.count == returns.elements.count { return f } else { throw IRError.TypeNotFound }
    }
    
}

extension FunctionCallExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // gen types for objects in call
        for arg in args.elements {
            try arg.llvmType(vars, fns: fns)
        }
        // get from table
        guard let fn = fns[name] else { throw SemaError.NoFunction(name) }
        
        // assign type to self and return
        self.type = fn.returns
        return fn.returns
    }
}

extension FunctionPrototypeExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        let ty = LLVMFnType(params: try fnType.params(), returns: try fnType.returnType())
        // update function table
        fns[name] = ty
        fnType.type = ty // store type in fntype
        type = LLVMType.Void     // retult of prototype is void
        
        guard var functionScopeExpression = impl?.body else { return .Void }
        // if body construct scope and parse inside it
        
        let fnVarsScope = SemaScope(parent: vars), fnFunctionsScope = SemaScope(parent: fns)
        
        for (i, v) in (impl?.params.elements ?? []).enumerate() {
            
            let n = (v as? ValueType)?.name ?? "$\(i)"
            let t = try fnType.params()[i]
            
            fnVarsScope[n] = t
        }
        
        // type gen for inner scope
        try variableTypeSema(forScope: &functionScopeExpression, vars: fnVarsScope, functions: fnFunctionsScope)
        
        return .Void
    }
}

extension AssignmentExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        // handle redeclaration
        if let _ = vars.variables[name] { throw SemaError.InvalidRedeclaration(name, value) }
        
        // get val type
        let inferredType = try value.llvmType(vars, fns: fns)
        
        type = LLVMType.Void        // set type to self
        value.type = inferredType   // store type in value’s type
        vars[name] = inferredType   // store in arr
        return .Void                // return void type for assignment expression
    }
}



extension ArrayExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // element types
        var types: [LLVMType] = []
        for i in 0..<arr.count {
            let el = arr[i]
            let t = try el.llvmType(vars, fns: fns)
            types.append(t)
        }
        
        // make sure array is homogeneous
        guard Set(try types.map { try $0.ir() }).count == 1 else { throw SemaError.HeterogenousArray(self.description()) }
        
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
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // get array variable
        guard let name = (arr as? Variable<AnyExpression>)?.name else { throw SemaError.NotVariableType }
        
        // make sure its an array
        guard case .Array(let type, _)? = vars[name] else { throw SemaError.CannotSubscriptNonArrayVariable }
        
        // gen type for subscripting value
        try index.llvmType(vars, fns: fns)
        
        // assign type to self and return
        self.type = type
        return type
    }
    
}

extension ReturnExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        try expression.llvmType(vars, fns: fns)
        
        self.type = LLVMType.Null
        return .Null
    }
    
}

extension RangeIteratorExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // gen types for start and end
        let s = try start.llvmType(vars, fns: fns)
        let e = try end.llvmType(vars, fns: fns)
        
        // make sure range has same start and end types
        guard try e.ir() == s.ir() else { throw SemaError.RangeWithInconsistentTypes }
        
        self.type = LLVMType.Null
        return .Null
    }
    
}

extension ForInLoopExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // scopes for inner loop
        let loopVarScope = SemaScope<LLVMType>(parent: vars)
        let loopFnScope = SemaScope<LLVMFnType>(parent: fns)
        
        // add bound name to scopes
        loopVarScope[binded.name] = .Int(size: 64)
        
        // gen types for iterator
        try iterator.llvmType(vars, fns: fns)
        
        // parse inside of loop in loop scope
        try variableTypeSema(forScope: &block, vars: loopVarScope, functions: loopFnScope)
        
        return .Null
    }
    
}

extension WhileLoopExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // scopes for inner loop
        let loopVarScope = SemaScope<LLVMType>(parent: vars)
        let loopFnScope = SemaScope<LLVMFnType>(parent: fns)
        
        // gen types for iterator
        let it = try iterator.llvmType(vars, fns: fns)
        guard try it.ir() == LLVMInt1Type() else { throw SemaError.NonBooleanCondition }
        
        // parse inside of loop in loop scope
        try variableTypeSema(forScope: &block, vars: loopVarScope, functions: loopFnScope)
        
        type = LLVMType.Null
        return .Null
    }
}
extension WhileIteratorExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // make condition variable and make sure bool
        let t = try condition.llvmType(vars, fns: fns)
        guard try t.ir() == LLVMInt1Type() else { throw SemaError.NonBooleanCondition }
        
        type = LLVMType.Bool
        return .Bool
    }
}


extension ConditionalExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // call on child `ElseIfBlockExpressions`
        for statement in statements {
            // inner scopes
            let ifVarScope = SemaScope<LLVMType>(parent: vars)
            let ifFnScope = SemaScope<LLVMFnType>(parent: fns)
            
            try statement.llvmType(ifVarScope, fns: ifFnScope)
        }
        
        type = LLVMType.Null
        return .Null
    }
}

extension ElseIfBlockExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // get condition type
        let cond = try condition?.llvmType(vars, fns: fns)
        guard try cond?.ir() == LLVMInt1Type() || cond == nil else { throw SemaError.NonBooleanCondition }
        
        // gen types for cond block
        try variableTypeSema(forScope: &block, vars: vars, functions: fns)
        
        self.type = LLVMType.Null
        return .Null
    }
    
}

extension MutationExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // gen types for variable and value
        let old = try object.llvmType(vars, fns: fns)
        let new = try value.llvmType(vars, fns: fns)
        guard try old.ir() == new.ir() else { throw SemaError.DifferentTypeForMutation }
        
        return .Null
    }
}

extension StructExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        let structVarScope = SemaScope<LLVMType>(parent: vars)
        let structFnScope = SemaScope<LLVMFnType>(parent: fns)
        
        // maps over properties and gens types
        let members = try properties.flatMap { (a: AssignmentExpression) -> LLVMType? in
            try a.llvmType(structVarScope, fns: structFnScope)
            return a.value.type as? LLVMType
        }
        guard members.count == properties.count else { throw SemaError.StructPropertyNotTyped }
        
        let memberFunctions = try methods.flatMap { (f: FunctionPrototypeExpression) -> LLVMFnType? in
            try f.llvmType(structVarScope, fns: structFnScope)
            return f.fnType.type as? LLVMFnType
        }
        guard memberFunctions.count == methods.count else { throw SemaError.StructMethodNotTyped }
        
        let ty = LLVMType.Struct(members: members, methods: memberFunctions)
        
        self.type = ty
        return ty
    }
}


