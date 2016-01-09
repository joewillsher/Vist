//
//  SemaTypeCheck.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


/// Adds type information to ast nodes and checks type signatures of functions, returns, & operators
func scopeSemallvmType<ScopeType : ScopeExpression>(forScopeExpression scopeExp: ScopeType, scope: SemaScope) throws {
    
    for (_, exp) in scopeExp.expressions.enumerate() {
        
        try exp.llvmType(scope)
        
        
        //-------------------------------
        // TODO: Parse all function declarations first, then go in to define them and everything else
        // TODO: Also make sure linked files can read into *eachother*
        //-------------------------------
    }
    
}

