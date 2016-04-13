//
//  FunctionSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



extension FuncDecl: DeclTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        let declScope = SemaScope(parent: scope)
        declScope.genericParameters = genericParameters
        
        let paramTypes = try fnType.params(declScope), returnType = try fnType.returnType(declScope)
        // if its a generator function there is no return
        let ret = isGeneratorFunction ? BuiltinType.void : returnType
        
        var ty: FnType
        
        if case let parentType as StorageType = parent?._type {
            ty = FnType(params: paramTypes, returns: ret, callingConvention: .method(selfType: parentType))
        }
        else {
            ty = FnType(params: paramTypes, returns: ret)
        }
        
        if isGeneratorFunction {
            ty.setGeneratorVariantType(yielding: returnType)
        }

        mangledName = name.mangle(ty)

        // scope return type hint applies to yield and return so use `returnType`
        let fnScope = SemaScope(parent: declScope, returnType: returnType, isYield: isGeneratorFunction)
        // TODO: non capturing scope, but only for variables
        
        scope.addFunction(name, type: ty)  // update function table
        fnType.type = ty            // store type in fntype
        
        guard let impl = self.impl else { return }
        // if body construct scope and parse inside it
        
        // make surebound list is same length
        guard impl.params.count == paramTypes.count else { throw semaError(.wrongFuncParamList(applied: impl.params, forType: paramTypes)) }
        
        for (index, name) in impl.params.enumerate() {
            fnScope[variable: name] = (type: paramTypes[index], mutable: false)
        }
        
        // if is a method
        if case let parentType as StorageType = parent?._type {
            
            let mutableSelf = attrs.contains(.mutating)
            // add self
            fnScope[variable: "self"] = (type: parentType, mutable: mutableSelf)
            
            // add self's memebrs implicitly
            for (memberName, memberType, mutable) in parentType.members {
                fnScope[variable: memberName] = (type: memberType, mutable: mutable && mutableSelf)
            }
        }
        
        // type gen for inner scope
        try impl.body.exprs.walkChildren { exp in
            try exp.typeForNode(fnScope)
        }
        
        if isGeneratorFunction {
            // so there are equal number of param names and params in the type
            // for the VHIRGen phase
            impl.params.append("loop_thunk")
        }
        
    }
}

extension BinaryExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        let t = try semaFunctionCall(scope)
        self.fnType = t
        return t.returns
    }
}


extension FunctionCallExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        let t = try semaFunctionCall(scope)
        self.fnType = t
        return t.returns
    }
}

extension FunctionCall {
    
    func semaFunctionCall(scope: SemaScope) throws -> FnType {
        
        // gen types for objects in call
        for arg in argArr {
            try arg.typeForNode(scope)
        }
        
        // get from table
        guard let argTypes = argArr.optionalMap({ expr in expr._type }) else { throw semaError(.paramsNotTyped, userVisible: false) }
        
        let (mangledName, fnType) = try scope.function(name, argTypes: argTypes)
        self.mangledName = mangledName
        
        // assign type to self and return
        self._type = fnType.returns
        return fnType
    }
}

