//
//  SemaTypeCheck.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

func sema(ast: AST, globalScope: SemaScope) throws {
    try scopeSematypeForNode(ast, scope: globalScope)
}

/// Adds type information to ast nodes and checks type signatures of functions, returns, & operators
func scopeSematypeForNode(ast: AST, scope: SemaScope) throws {
    
    //-------------------------------
    // TODO: Parse all function declarations first, then go in to define them and everything else
    // TODO: Also make sure linked files can read into *eachother*
    //-------------------------------
    
    try ast.walkChildren { node in
        try node.typeForNode(scope)
    }
    
}

