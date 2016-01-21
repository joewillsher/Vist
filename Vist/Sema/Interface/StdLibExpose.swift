//
//  StdLibExpose.swift
//  Vist
//
//  Created by Josef Willsher on 09/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class StdLibExpose {
    
    private let isStdLib: Bool
    
    init(isStdLib: Bool) {
        self.isStdLib = isStdLib
    }
    
    private var code: String {
        if !isStdLib {
            return (try? String(contentsOfFile: "\(PROJECT_DIR)/Vist/stdlib/stdlib.visth")) ?? ""
        }
        else { return "" }
    }
    
    private func astGen() throws -> AST {
        var l = Lexer(code: code)
        var p = Parser(tokens: try l.getTokens(), isStdLib: true)
        let a = try p.parse()
        let s = SemaScope(parent: nil)
        try sema(a, globalScope: s)
        return a
    }
    
    // Swift's lazy sucks so I implement it myself
    
    private var _ast: AST? = nil
    
    private var ast: AST? {
        get {
            if let ast = _ast { return ast }
            do {
                let ast = try astGen()
                _ast = ast
                return ast
            } catch {
                print(error)
                fatalError()
            }
            return nil
        }
        set {
            _ast = newValue
        }
    }
    
    
    func astToSemaScope(scope globalScope: SemaScope) {
        guard let ast = ast else { fatalError("Stdlib could not be loaded") }
        
        let fns = ast.exprs
            .flatMap { $0 as? FuncDecl }
            .map { f -> (String, FnType?) in (f.name, f.fnType.type) }
        
        let structs = ast.exprs
            .flatMap { $0 as? StructExpr }
        let tys = structs
            .map { s -> (String, StructType?) in (s.name, s.type) }
        let methods = structs
            .flatMap {
                $0.methods.flatMap { ($0.name, $0.fnType.type) }
                +
                $0.initialisers .flatMap { ($0.parent!.name, FnType.returning($0.parent!._type!))
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
        
        let tys = ast.exprs
            .flatMap { ($0 as? StructExpr) }
            .map { ($0.name, $0._type as? StructType) }
        
        for (name, t) in tys {
            if let t = t { frame.addType(name, val: t) }
        }
        
    }
    
    
}
