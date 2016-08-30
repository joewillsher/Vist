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

protocol Pattern : ASTNode, Expr {
}

/// The pattern that matches a conditional expr
enum ConditionalPattern {
    case boolean(Expr)
    case typeMatch(TypeMatchPattern)
    case none // < the pattern matching an else block
}

final class ElseIfBlockStmt : Stmt {
    var condition: ConditionalPattern
    var block: BlockExpr
    
    init(condition: ConditionalPattern, block: BlockExpr) {
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

/// `x the Type` or `x the type = foo` pattern
final class TypeMatchPattern : Pattern {
    let variable: String
    let explicitBoundExpr: Expr?
    let type: TypeRepr
    
    init(variable: String, explicitBoundExpr: Expr?, type: TypeRepr) {
        self.variable = variable
        self.explicitBoundExpr = explicitBoundExpr
        self.type = type
    }
    
    /// The expr we are binding to, if there is no
    /// explicit expr then after sema this is a type
    /// checked variable expr
    var boundExpr: Expr!
    
    var _type: Type?
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
