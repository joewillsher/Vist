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
        
        if case let e as VariableDecl = exp {
            interface.exprs.append(e)
        }
        else if case let f as FuncDecl = exp {
            
            let fun = FuncDecl(name: f.name, type: f.fnType, impl: nil, attrs: f.attrs, genericParameters: f.genericParameters)
            interface.exprs.append(fun)
            
        }
        
        // TODO: Structs / concepts etc need to be exposed in the interface
    }
    
    return interface
}

func interFileInterfaceASTGen(ast: AST) throws -> AST {
    
    let interface = AST(exprs: [])
    
    
    for exp in ast.exprs {
        
        if case let e as VariableDecl = exp {
            interface.exprs.append(e)
        }
        else if case let f as FuncDecl = exp {
            interface.exprs.append(f)
        }
        else if case let s as StructExpr = exp {
            interface.exprs.append(s)
        }
    }
    
    return interface
}



