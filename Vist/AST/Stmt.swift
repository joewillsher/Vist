//
//  Stmt.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


///  - Statement / Stmt
///      - brace, return, conditional, if, while, for in, switch, break, fallthrough, continue
protocol Stmt: ASTNode, StmtTypeProvider {}



final class ElseIfBlockStmt: Stmt {
    var condition: Expr?
    var block: BlockExpr
    
    init(condition: Expr?, block: BlockExpr) {
        self.condition = condition
        self.block = block
    }
}


final class ConditionalStmt: Stmt {
    let statements: [ElseIfBlockStmt]
    
    init(statements: [(condition: Expr?, block: BlockExpr)]) throws {
        var p: [ElseIfBlockStmt] = []
        
        for (index, path) in statements.enumerate() {
            
            p.append(ElseIfBlockStmt(condition: path.0, block: path.1))
            
            // nil condition here is an else block, if there is anything after an else block then throw
            // either because there is more than 1 else or Exprs after an else
            guard let _ = path.condition else {
                if index == statements.count-1 { break }
                self.statements = []; throw parseError(.InvalidIfStatement)
            }
        }
        
        self.statements = p
    }
}


protocol LoopStmt: Stmt {
    var block: BlockExpr { get }
}


final class ForInLoopStmt: LoopStmt {
    let binded: VariableExpr
    let iterator: Expr
    var block: BlockExpr
    
    init(identifier: VariableExpr, iterator: Expr, block: BlockExpr) {
        self.binded = identifier
        self.iterator = iterator
        self.block = block
    }
}

final class WhileLoopStmt: LoopStmt {
    let condition: Expr
    var block: BlockExpr
    
    init(condition: Expr, block: BlockExpr) {
        self.condition = condition
        self.block = block
    }
}


final class ReturnStmt: Stmt {
    let expr: Expr
    
    init(expr: Expr) {
        self.expr = expr
    }
}
