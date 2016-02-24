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
        let ty = FnType(params: paramTypes, returns: returnType)
        
        mangledName = name.mangle(ty, parentTypeName: parent?.name)
        
        let fnScope = SemaScope(parent: declScope, returnType: ty.returns)
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
        
    }
}

extension BinaryExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        let args = [lhs, rhs]
        
        // gen types for objects in call
        for arg in args {
            try arg.typeForNode(scope)
        }
        
        guard let argTypes = args.optionalMap({ $0._type }) else { throw semaError(.paramsNotTyped, userVisible: false) }
        
        let (mangledName, fnType) = try scope.function(op, argTypes: argTypes)
        self.mangledName = mangledName
        
        // assign type to self and return
        self.fnType = fnType
        self._type = fnType.returns
        return fnType.returns
    }
}


extension FunctionCallExpr: ExprTypeProvider {
    
    func typeForNode(scope: SemaScope) throws -> Ty {
        
        // gen types for objects in call
        for arg in args.elements {
            try arg.typeForNode(scope)
        }
        
        // get from table
        guard let argTypes = args.elements.optionalMap({ $0._type }) else { throw semaError(.paramsNotTyped, userVisible: false) }
        
        let (mangledName, fnType) = try scope.function(name, argTypes: argTypes)
        self.mangledName = mangledName
        
        // assign type to self and return
        self.fnType = fnType
        self._type = fnType.returns
        return fnType.returns
    }
}

