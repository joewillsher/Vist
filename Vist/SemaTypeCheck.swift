//
//  SemaTypeCheck.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


/// Adds type information to ast nodes and checks type signatures of functions, returns, & operators
func semaVariableSpecialisation<ScopeType : ScopeExpression>(inout scope: ScopeType, v: SemaScope<LLVMType>? = nil, f: SemaScope<LLVMFnType>? = nil) throws {
    
    let vars = v ?? SemaScope<LLVMType>(parent: nil)
    let functions = f ?? SemaScope<LLVMFnType>(parent: nil)
    
    for exp in scope.expressions {
        
        if let e = exp as? AssignmentExpression {
            
            // handle redeclaration
            if let _ = vars.variables[e.name] { throw SemaError.InvalidRedeclaration(e.name, e.value) }
            
            // get val type
            let inferredType = try e.value.llvmType(vars, fns: functions)
            
            vars[e.name] = inferredType
            
        } else if let fn = exp as? FunctionPrototypeExpression {
            
            let t = fn.fnType
            
            let ty = LLVMFnType(params: try t.params(), returns: try t.returnType())
            // update function table
            functions[fn.name] = ty
            
            guard var functionScopeExpression = fn.impl?.body else { continue }
            // if body construct scope and parse inside it
            
            let fnVarsScope = SemaScope(parent: vars), fnFunctionsScope = SemaScope(parent: functions)
            
            for (i, v)  in (fn.impl?.params.elements ?? []).enumerate() {
                
                let n = (v as? ValueType)?.name ?? "$\(i)"
                let t = try t.params()[i]
                
                fnVarsScope[n] = t
            }
            
            try semaVariableSpecialisation(&functionScopeExpression, v: fnVarsScope, f: fnFunctionsScope)
            
            
        } else {
            
            try exp.llvmType(vars, fns: functions)
            
        }
        
        
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




