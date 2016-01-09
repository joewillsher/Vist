//
//  StdLibExpose.swift
//  Vist
//
//  Created by Josef Willsher on 09/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class StdLibExpose {
    
    private lazy var ast: AST? = try? {
        let code = try String(contentsOfFile: "\(PROJECT_DIR)/Vist/stdlib/llvmheader.vist")
        var l = Lexer(code: code)
        var p = Parser(tokens: try l.getTokens(), isStdLib: true)
        let a = try p.parse()
        try scopeSemallvmType(forScopeExpression: a)
        return a
    }()
    
    func astToSemaScope(scope globalScope: SemaScope) {
        guard let ast = ast else { fatalError("Stdlib could not be loaded") }
        
        let fns = ast.expressions
            .flatMap { ($0 as? FunctionPrototypeExpression) }
            .map { ($0.name, $0.fnType.type as? LLVMFnType) }
        
        let structs = ast.expressions
            .flatMap { ($0 as? StructExpression) }
        let tys = structs
            .map { ($0.name, $0.type as? LLVMStType) }
        let methods = structs
            .flatMap {
                $0.methods
                    .flatMap { ($0.name, $0.type as? LLVMFnType) }
                    +
                    $0.initialisers
                        .flatMap { ($0.parent?.name ?? "", $0.type as? LLVMFnType)
                }
        }
        
        for (name, t) in fns + methods {
            globalScope[function: name] = t
        }
        
        for (name, t) in tys {
            globalScope[type: name] = t
        }
        
    }
    
    func astToStackFrame(frame frame: StackFrame) {
        guard let ast = ast else { fatalError("Stdlib could not be loaded") }
        
        let structs = ast.expressions
            .flatMap { ($0 as? StructExpression) }
        let tys = structs
            .map { ($0.name, $0.type as? LLVMStType) }
        
        for (name, t) in tys {
            if let t = t { frame.addType(name, val: t) }
        }
        
    }
    
}
