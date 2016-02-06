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
        if let t = parent?.type {
            // add self
            fnScope[variable: "self"] = (type: t, mutable: false)
            
            // add self's memebrs implicitly
            for (name, type, _) in t.members {
                fnScope[variable: name] = (type: type, mutable: false)
            }
        }
        
        // type gen for inner scope
        try impl.body.exprs.walkChildren { exp in
            try exp.llvmType(fnScope)
        }
        
    }
}


extension FunctionCallExpr : ExprTypeProvider {
    
    func llvmType(scope: SemaScope) throws -> Ty {
        
        // get from table
        guard let params = try args.elements.stableOptionalMap({ try $0.llvmType(scope) }) else { throw error(SemaError.ParamsNotTyped, userVisible: false) }
        let builtinFn = BuiltinDef.getBuiltinFunction(self.name, args: params)
        let fnType: FnType
        
        // if its in the stdlib return it
        if let (mangledName, type) = StdLib.getStdLibFunction(self.name, args: params) where !scope.isStdLib {
            self.mangledName = mangledName
            fnType = type
        }
        else {
            let _fnType = builtinFn?.1 ?? scope[function: self.name, paramTypes: params]
            let name = builtinFn?.0 ?? self.name
            
            //!scope.isStdLib
            
            guard let ty = _fnType  else {
                if let f = scope[function: name] { throw error(SemaError.WrongFunctionApplications(name: name, applied: params, expected: f.params)) }
                else                             { throw error(SemaError.NoFunction(name, params)) }
            }
            
            self.mangledName = name.mangle(ty)
            fnType = ty
        }
        
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

