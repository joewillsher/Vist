//
//  FunctionSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



extension FuncDecl: DeclTypeProvider {
    
    /// Generate the function type and mangled name for a function
    /// - note: call `typeForNode(_:)` to sema the body 
    func genFunctionInterface(scope: SemaScope) throws -> FunctionType {
        
        let declScope = SemaScope(parent: scope)
        declScope.genericParameters = genericParameters
        
        let mutableSelf = attrs.contains(.mutating)
        let paramTypes = try fnType.params(declScope), returnType = try fnType.returnType(declScope)
        // if its a generator function there is no return
        let ret = isGeneratorFunction ? BuiltinType.void : returnType
        
        var ty: FunctionType
        
        if case let parentType as NominalType = parent?._type {
            ty = FunctionType(params: paramTypes, returns: ret, callingConvention: .method(selfType: parentType, mutating: mutableSelf))
        }
        else {
            ty = FunctionType(params: paramTypes, returns: ret)
        }
        
        if isGeneratorFunction {
            ty.setGeneratorVariantType(yielding: returnType)
        }
        
        mangledName = name.mangle(ty)
        
        scope.addFunction(name, type: ty)  // update function table
        fnType.type = ty            // store type in fntype
        return ty
    }
    
    func typeForNode(scope: SemaScope) throws {
        
        // if we have already gen'ed the interface for this function, fnType.type
        // won't be nil, if we haven't, gen it now
        let ty = try fnType.type ?? genFunctionInterface(scope)
        
        guard let impl = self.impl else { return }
        // if body construct scope and parse inside it
        
        let mutableSelf = attrs.contains(.mutating)
        
        // get the type the scope returns or yields
        let scopeRetType: Type
        if let yt = ty.yieldType where isGeneratorFunction {
            scopeRetType = yt
        }
        else {
            scopeRetType = ty.returns
        }
        
        // scope return type hint applies to yield and return so use `returnType`
        let fnScope = SemaScope(parent: scope, returnType: scopeRetType, isYield: isGeneratorFunction)
        
        // make surebound list is same length
        guard impl.params.count == ty.params.count || isGeneratorFunction else { throw semaError(.wrongFuncParamList(applied: impl.params, forType: ty.params)) }
        
        for (index, name) in impl.params.enumerate() {
            fnScope[variable: name] = (type: ty.params[index], mutable: false)
        }
        
        // if is a method
        if case let parentType as NominalType = parent?._type {
            
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
            // for the VIRGen phase
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
    
    func semaFunctionCall(scope: SemaScope) throws -> FunctionType {
        
        // gen types for objects in call
        for arg in argArr {
            try arg.typeForNode(scope)
        }
        
        // get from table
        guard let argTypes = argArr.optionalMap({ expr in expr._type }) else {
            throw semaError(.paramsNotTyped, userVisible: false)
        }
        
        let (mangledName, fnType) = try scope.function(name, argTypes: argTypes)
        self.mangledName = mangledName
        
        // we need explicit self, VIRGen cant handle the implicit method call
        // case just yet
        if case .method = fnType.callingConvention {
            throw semaError(.useExplicitSelf(methodName: name))
        }
        
        // assign type to self and return
        self._type = fnType.returns
        return fnType
    }
}

