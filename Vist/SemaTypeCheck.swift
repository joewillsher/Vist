//
//  SemaTypeCheck.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


/// Adds type information to ast nodes and checks type signatures of functions, returns, & operators
func variableTypeSema<ScopeType : ScopeExpression>(inout forScopeExpression scopeExp: ScopeType, scope s: SemaScope? = nil) throws {
    
    let scope = s ?? SemaScope(parent: nil, returnType: nil) // global scope if no parent, no return in user code
    
    for (i, exp) in scopeExp.expressions.enumerate() {
        
        try exp.llvmType(scope)
        
        
        //-------------------------------
        // TODO: Parse all function declarations first, then go in to define them and everything else
        // TODO: Also make sure linked files can read into *eachother*
        //-------------------------------
    }
    
}

