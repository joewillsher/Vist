//
//  SemaTypeCheck.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

func sema(ast: AST, globalScope: SemaScope) throws {
    
    try scopeSemallvmType(ast, scope: globalScope)
}

/// Adds type information to ast nodes and checks type signatures of functions, returns, & operators
func scopeSemallvmType(ast: AST, scope: SemaScope) throws {
    
    for exp in ast.exprs {
        
        try exp.llvmType(scope)
        
        //-------------------------------
        // TODO: Parse all function declarations first, then go in to define them and everything else
        // TODO: Also make sure linked files can read into *eachother*
        //-------------------------------
    }
    
}

