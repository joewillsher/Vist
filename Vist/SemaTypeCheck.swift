//
//  SemaTypeCheck.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


/// Adds type information to ast nodes and checks type signatures of functions, returns, & operators
func variableTypeSema<ScopeType : ScopeExpression>(inout forScope scope: ScopeType, vars: SemaScope<LLVMType>? = nil, functions: SemaScope<LLVMFnType>? = nil) throws {
    
    let vars = vars ?? SemaScope<LLVMType>(parent: nil)
    let functions = functions ?? SemaScope<LLVMFnType>(parent: nil)
    
    for (i, exp) in scope.expressions.enumerate() {
        
        try exp.llvmType(vars, fns: functions)
        continue

        // if top level expression is assignment or
        
//        if let e = exp as? AssignmentExpression {
//            
//            // handle redeclaration
//            if let _ = vars.variables[e.name] { throw SemaError.InvalidRedeclaration(e.name, e.value) }
//            
//            // get val type
//            let inferredType = try e.value.llvmType(vars, fns: functions)
//            
//            scope.expressions[i].type = inferredType
//            
//            vars[e.name] = inferredType
//            
//            
//        } else if let fn = exp as? FunctionPrototypeExpression {
//            
//            let t = fn.fnType
//            
//            let ty = LLVMFnType(params: try t.params(), returns: try t.returnType())
//            // update function table
//            functions[fn.name] = ty
//            
//            guard var functionScopeExpression = fn.impl?.body else { continue }
//            // if body construct scope and parse inside it
//            
//            let fnVarsScope = SemaScope(parent: vars), fnFunctionsScope = SemaScope(parent: functions)
//            
//            for (i, v) in (fn.impl?.params.elements ?? []).enumerate() {
//                
//                let n = (v as? ValueType)?.name ?? "$\(i)"
//                let t = try t.params()[i]
//                
//                fnVarsScope[n] = t
//            }
//            
//            try variableTypeSema(forScope: &functionScopeExpression, vars: fnVarsScope, functions: fnFunctionsScope)
//            
//            scope.expressions[i].type = ty
//            
//        } else if let st = exp as? StructExpression {
//            
//            
//            
//            
//            
//        } else {
//            
//            // handle all other cases by generating their (and their children's) types
//            try exp.llvmType(vars, fns: functions)
//            
//        }
        
        
        //-------------------------------
        // TODO: Parse all function declarations first, then go in to define them and everything else
        // TODO: Also make sure linked files can read into *eachother*
        //-------------------------------
    }
    
}

