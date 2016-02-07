//
//  FunctionSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



extension FuncDecl : DeclTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        
        let params = try fnType.params(scope), res = try fnType.returnType(scope)
        let ty = FnType(params: params, returns: res)
        
        if let p = parent?.name {
            mangledName = name.mangle(ty, parentTypeName: p)
        } else {
            mangledName = name.mangle(ty)
        }
        
        scope[function: name] = ty  // update function table
        fnType.type = ty            // store type in fntype
        
        guard let impl = self.impl else { return }
        // if body construct scope and parse inside it
        
        let fnScope = SemaScope(parent: scope, returnType: ty.returns)
        
        for (index, name) in impl.params.enumerate() {
            
            let type = params[index]
            fnScope[variable: name] = (type: type, mutable: false)
        }
        
        // if is a method
        if let parentType = parent?.type {
            // add self
            fnScope[variable: "self"] = (type: parentType, mutable: false)
            
            // add self's memebrs implicitly
            for (name, type, _) in parentType.members {
                fnScope[variable: name] = (type: type, mutable: false)
            }
        }
        
        // type gen for inner scope
        try impl.body.exprs.walkChildren { exp in
            try exp.llvmType(fnScope)
        }
        
    }
}

extension BinaryExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        let args = [lhs, rhs]
        
        guard let argTypes = try args.stableOptionalMap({ try $0.llvmType(scope) }) else { throw error(SemaError.ParamsNotTyped, userVisible: false) }
        
        let (mangledName, fnType) = try scope.function(op, argTypes: argTypes)
        self.mangledName = mangledName
        
        // gen types for objects in call
        for arg in args {
            try arg.llvmType(scope)
        }
        
        // assign type to self and return
        self.fnType = fnType
        self._type = fnType.returns
        return fnType.returns
    }
}


extension FunctionCallExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // get from table
        guard let argTypes = try args.elements.stableOptionalMap({ try $0.llvmType(scope) }) else { throw error(SemaError.ParamsNotTyped, userVisible: false) }
        
        let (mangledName, fnType) = try scope.function(name, argTypes: argTypes)
        self.mangledName = mangledName
        
        // gen types for objects in call
        for arg in args.elements {
            try arg.llvmType(scope)
        }
        
        // assign type to self and return
        self.fnType = fnType
        self._type = fnType.returns
        return fnType.returns
    }
}

