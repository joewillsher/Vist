//
//  LinkAST.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


func astLink(main: AST, other: [AST]) throws -> AST {
    
    return try other
        .map(interFileInterfaceASTGen)
        .reduce(main, combine: appendAST)
}

func appendAST(head: AST, next: AST) -> AST {
    return AST(expressions: next.expressions + head.expressions)
}

