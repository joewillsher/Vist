//
//  Stmt.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


///  - Statement / Stmt
///      - brace, return, conditional, if, while, for in, switch, break, fallthrough, continue
protocol Stmt : ASTNode, StmtTypeProvider {}

final class ElseIfBlockStmt : Stmt {
    var condition: Expr?
    var block: BlockExpr
    
    init(condition: Expr?, block: BlockExpr) {
        self.condition = condition
        self.block = block
    }
}


final class ConditionalStmt : Stmt {
    let statements: [ElseIfBlockStmt]
    
    init(statements: [ElseIfBlockStmt]) {
        self.statements = statements
    }
}


protocol LoopStmt : Stmt {
    var block: BlockExpr { get }
}


final class ForInLoopStmt : LoopStmt {
    let binded: VariableExpr
    let generator: Expr
    var block: BlockExpr
    
    init(identifier: VariableExpr, iterator: Expr, block: BlockExpr) {
        self.binded = identifier
        self.generator = iterator
        self.block = block
    }
    
    var generatorFunctionName: String?
}

final class WhileLoopStmt : LoopStmt {
    let condition: Expr
    var block: BlockExpr
    
    init(condition: Expr, block: BlockExpr) {
        self.condition = condition
        self.block = block
    }
}

protocol ScopeEscapeStmt : Stmt {
    var expr: Expr { get }
}

final class ReturnStmt : ScopeEscapeStmt {
    let expr: Expr
    
    init(expr: Expr) {
        self.expr = expr
    }
    
    var expectedReturnType: Type?
}
final class YieldStmt : ScopeEscapeStmt {
    let expr: Expr
    
    init(expr: Expr) {
        self.expr = expr
    }
}
