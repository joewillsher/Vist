//
//  FunctionSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension FuncDecl : DeclTypeProvider {
    
    /// Generate the function type and mangled name for a function
    /// - note: call `typeForNode(_:)` to sema the body 
    func genFunctionInterface(scope: SemaScope) throws -> FunctionType {
        
        let declScope = SemaScope(parent: scope)
        declScope.genericParameters = genericParameters
        
        let mutableSelf = attrs.contains(.mutating)
        let paramTypes = try typeRepr.params(scope: declScope), returnType = try typeRepr.returnType(scope: declScope)
        // if its a generator function there is no return
        let ret = isGeneratorFunction ? BuiltinType.void : returnType
        
        var ty: FunctionType
        
        if let parentType = parent?.declaredType {
            ty = FunctionType(params: paramTypes, returns: ret, callingConvention: .method(selfType: parentType, mutating: mutableSelf))
        }
        else {
            ty = FunctionType(params: paramTypes, returns: ret)
        }
        
        if isGeneratorFunction {
            ty.setGeneratorVariantType(yielding: returnType)
        }
        
        mangledName = name.mangle(type: ty)
        
        scope.addFunction(name: name, type: ty)  // update function table
        typeRepr.type = ty            // store type in fntype
        return ty
    }
    
    func typeForNode(scope: SemaScope) throws {
        
        // if we have already gen'ed the interface for this function, fnType.type
        // won't be nil, if we haven't, gen it now
        let ty = try typeRepr.type ?? genFunctionInterface(scope: scope)
        
        guard let impl = self.impl else { return }
        // if body construct scope and parse inside it
        
        let mutableSelf = attrs.contains(.mutating)
        
        // get the type the scope returns or yields
        let scopeRetType: Type
        if let yt = ty.yieldType, isGeneratorFunction {
            scopeRetType = yt
        }
        else {
            scopeRetType = ty.returns
        }
        
        // scope return type hint applies to yield and return so use `returnType`
        let fnScope = SemaScope(parent: scope, returnType: scopeRetType, isYield: isGeneratorFunction)
        
        // make surebound list is same length
        guard impl.params.count == ty.params.count || isGeneratorFunction else { throw semaError(.wrongFuncParamList(applied: impl.params, forType: ty.params)) }
        
        for (index, name) in impl.params.enumerated() {
            fnScope.addVariable(variable: (type: ty.params[index], mutable: false, isImmutableCapture: false), name: name)
        }
        
        // if is a method
        if let parentType = parent?.declaredType {
            // add self
            fnScope.addVariable(variable: (type: parentType, mutable: mutableSelf, isImmutableCapture: !mutableSelf), name: "self")
            // add self's memebrs implicitly
            for (memberName, memberType, mutable) in parentType.members {
                fnScope.addVariable(variable: (type: memberType, mutable: mutable && mutableSelf, isImmutableCapture: !mutableSelf), name: memberName)
            }
        }
        
        // type gen for inner scope
        try impl.body.exprs.walkChildren { exp in
            try exp.typeForNode(scope: fnScope)
        }
        
        if isGeneratorFunction {
            // so there are equal number of param names and params in the type
            // for the VIRGen phase
            impl.params.append("loop_thunk")
        }
        
    }
    
}

extension BinaryExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        let t = try semaFunctionCall(scope: scope)
        self.fnType = t
        return t.returns
    }
}


extension FunctionCallExpr : ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Type {
        let t = try semaFunctionCall(scope: scope)
        self.fnType = t
        return t.returns
    }
}

extension FunctionCall {
    
    func semaFunctionCall(scope: SemaScope) throws -> FunctionType {
        
        // gen types for objects in call
        for arg in argArr {
            _ = try arg.typeForNode(scope: scope)
        }
        
        // get from table
        guard let argTypes = argArr.optionalMap(transform: { expr in expr._type }) else {
            throw semaError(.paramsNotTyped, userVisible: false)
        }
        
        let (mangledName, fnType) = try scope.function(named: name, argTypes: argTypes)
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

