//
//  ASTInterface.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

func interfaceASTGen(ast: AST) throws -> AST {
    
    let interface = AST(exprs: [])
    
    
    for exp in ast.exprs {
        
        if let e = exp as? AssignmentExpr {
            interface.exprs.append(e)
        }
        else if let f = exp as? FunctionDecl {
            
            let fun = FunctionDecl(name: f.name, type: f.fnType, impl: nil, attrs: f.attrs)
            fun.type = f.type
            interface.exprs.append(fun)
                        
        }
        
        // TODO: Structs / concepts etc need to be exposed in the interface
    }
    
    return interface
}

func interFileInterfaceASTGen(ast: AST) throws -> AST {
    
    let interface = AST(exprs: [])
    
    
    for exp in ast.exprs {
        
        if let e = exp as? AssignmentExpr {
            interface.exprs.append(e)
        }
        else if let f = exp as? FunctionDecl {
            
//            let fun = FunctionDecl(name: f.name, type: f.fnType, impl: f.impl, attrs: f.attrs)
//            fun.type = f.type
            interface.exprs.append(f)
        }
        else if let s = exp as? StructExpr {
            interface.exprs.append(s)
        }
        
        // TODO: Structs / concepts etc need to be exposed in the interface
    }
    
    return interface
}



