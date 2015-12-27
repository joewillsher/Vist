//
//  ASTInterface.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

func interfaceASTGen(ast: AST) throws -> AST {
    
    let interface = AST(expressions: [])
    
    
    for exp in ast.expressions {
        
        if let e = exp as? AssignmentExpression {
            interface.expressions.append(e)
            
        } else if let f = exp as? FunctionPrototypeExpression {
            
            let fun = FunctionPrototypeExpression(name: f.name, type: f.fnType, impl: nil)
            fun.type = f.type
            interface.expressions.append(fun)
                        
        }
    }
    
    return interface
}

