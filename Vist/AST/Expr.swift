//
//  Expr.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


///  - Expression / Expr
///      - literals, tuples, parens, array, closure
///      - Call expression, operator, methods, casts
///      - Sub expressions of syntax structures, like `type name generic params`
protocol Expr : ASTNode, Typed {}
///  - Statement / Stmt
///      - brace, return, conditional, if, while, for in, switch, break, fallthrough, continue
protocol Stmt : ASTNode {}
/// - Declaration / Decl
protocol Decl : ASTNode {}













struct NullExpr : Expr {
    var type: Ty? = nil
}

















final class VariableDecl : Decl, StructMember {
    let name: String
    let aType: String?
    let isMutable: Bool
    var value: Expr
    
    init(name: String, type: String?, isMutable: Bool, value: Expr) {
        self.name = name
        self.aType = type
        self.isMutable = isMutable
        self.value = value
    }
}

class FunctionDecl : Decl, StructMember {
    let name: String
    let fnType: FunctionType
    let impl: FunctionImplementationExpr?
    let attrs: [FunctionAttributeExpr]
    
    init(name: String, type: FunctionType, impl: FunctionImplementationExpr?, attrs: [FunctionAttributeExpr]) {
        self.name = name
        self.fnType = type
        self.impl = impl
        self.mangledName = name
        self.attrs = attrs
    }
    
    var mangledName: String
    
    // FIXME: FunctionDecl protocol and 2 implementations
    /// `self` if the function is a member function
    weak var parent: StructExpr? = nil
}

final class InitialiserDecl : Decl, StructMember {
    let ty: FunctionType
    let impl: FunctionImplementationExpr?
    weak var parent: StructExpr?
    
    init(ty: FunctionType, impl: FunctionImplementationExpr?, parent: StructExpr?) {
        self.ty = ty
        self.impl = impl
        self.parent = parent
        self.mangledName = ""
    }
    
    var mangledName: String
}

// TODO: Notes from swift:
//
// they have different types -
//
//  - Pattern, as in pattern matching
//      - `is` pattern, tuple pattern, enum element pattern, case statement 'bool' patterns, x?
//  - Declarations / Decl
//      - Vars, funcs, types, and initalisers
//  - Statement / Stmt
//      - brace, return, defer, conditional, do/catch, if, while, for, for each, switch, break, fallthrough, continue, throw
//  - Expression / expr
//      - literals, tuples, parens, array, closure
//      - Call expression, operator, methods, casts,
//      - Sub expressions of syntax structures, like `type name generic params`
//  - TypeRepr & SourceLoc
//      - ‘Representation of a type as written in source’, generates human readable code to attach to AST objects
//      - Source code location information
//
// Swift has an explicit AST walker function











final class BlockExpr : Expr {
    var exprs: [ASTNode]
    var variables: [ValueType]
    
    init(exprs: [ASTNode], variables: [ValueType] = []) {
        self.exprs = exprs
        self.variables = variables
    }
    
    var type: Ty? = nil
}

final class ClosureExpr : Expr, Typed {
    
    var exprs: [ASTNode]
    var parameters: [String]
    
    init(exprs: [ASTNode], params: [String]) {
        self.exprs = exprs
        self.parameters = params
    }
    
    var type: Ty? = nil
}


final class BooleanLiteral : Literal, BooleanType, Typed {
    let val: Bool
    
    init(val: Bool) {
        self.val = val
    }
    
    var type: Ty? = nil
}

protocol FloatingPointType {
    var val: Double { get }
}
protocol IntegerType {
    var val: Int { get }
}
protocol BooleanType {
    var val: Bool { get }
}


final class FloatingPointLiteral : Literal, ExplicitlyTyped, FloatingPointType, Sized, Typed {
    let val: Double
    var size: UInt32 = 64
    var explicitType: String {
        return size == 32 ? "Float" : size == 64 ? "Double" : "Float\(size)"
    }
    
    init(val: Double, size: UInt32 = 64) {
        self.val = val
    }
    
    var type: Ty? = nil
}

final class IntegerLiteral : Literal, ExplicitlyTyped, IntegerType, Sized, Typed {
    let val: Int
    var size: UInt32
    var explicitType: String {
        return size == 32 ? "Int" : "Int\(size)"
    }
    
    init(val: Int, size: UInt32 = 64) {
        self.val = val
        self.size = size
    }
    
    var type: Ty? = nil
}
final class StringLiteral : Literal, Expr, Typed {
    let str: String
    var count: Int { return str.characters.count }
    
    init(str: String) {
        self.str = str
    }
    
//    var arr: ArrayExpr? = nil
    
    var type: Ty? = nil
}
//final class CharacterExpr : Expr {
//    let val: Character
//    
//    init(c: Character) {
//        val =  c
//    }
//    
//    var type: Ty? = nil
//}


struct CommentExpr : Expr {
    let str: String
    init(str: String) {
        self.str = str
    }
    
    var type: Ty? = nil
}

final class Void : Expr, Typed {
    var type: Ty? = BuiltinType.Void
}


protocol AssignableExpr : Expr {}

/// A variable lookup Expr
///
/// Generic over the variable type, use AnyExpr if this is not known
final class Variable : AssignableExpr, Typed {
    let name: String
    
    init(name: String) {
        self.name = name
    }
    
    var type: Ty? = nil
}








final class BinaryExpr : Expr, Typed {
    let op: String
    let lhs: Expr, rhs: Expr
    
    init(op: String, lhs: Expr, rhs: Expr) {
        self.op = op
        self.lhs = lhs
        self.rhs = rhs
    }
    
    var mangledName: String = ""
    
    var type: Ty? = nil
}

final class PrefixExpr : Expr, Typed {
    let op: String
    let expr: Expr
    
    init(op: String, expr: Expr) {
        self.op = op
        self.expr = expr
    }
    
    var type: Ty? = nil
}

final class PostfixExpr : Expr, Typed {
    let op: String
    let expr: Expr
    
    init(op: String, expr: Expr) {
        self.op = op
        self.expr = expr
    }
    
    var type: Ty? = nil
}











final class FunctionCallExpr : Expr, Typed {
    let name: String
    let args: TupleExpr
    
    init(name: String, args: TupleExpr) {
        self.name = name
        self.args = args
        self.mangledName = name
    }
    
    var mangledName: String
    
    var type: Ty? = nil
}


final class MutationExpr : Expr {
    let object: AssignableExpr
    let value: Expr
    
    init(object: AssignableExpr, value: Expr) {
        self.object = object
        self.value = value
    }
    
    var type: Ty? = nil
}





final class FunctionImplementationExpr : Expr {
    let params: TupleExpr
    let body: BlockExpr
    
    init(params: TupleExpr, body: BlockExpr) {
        self.params = params
        self.body = body
    }
    
    var type: Ty? = nil
}

final class TupleExpr : Expr {
    let elements: [Expr]
    
    init(elements: [Expr]) {
        self.elements = elements
    }
    init(element: Expr) {
        self.elements = [element]
    }
    
    static func void() -> TupleExpr{ return TupleExpr(elements: [])}
    
    func mapAs<T>(_: T.Type) -> [T] {
        return elements.flatMap { $0 as? T }
    }
    
    var type: Ty? = nil
}

final class TupleMemberLookupExpr : AssignableExpr {
    let index: Int
    let object: Expr
    
    init(index: Int, object: Expr) {
        self.index = index
        self.object = object
    }
    
    var type: Ty? = nil
}

final class ReturnStmt : Stmt {
    let expr: Expr
    
    init(expr: Expr) {
        self.expr = expr
    }
}


// FIXME: find another way to do this
/// used to lowe type name information
final class ValueType : Expr {
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
    var type: Ty? = nil
}


final class FunctionType : Expr {
    let args: TupleExpr
    let returns: Expr
    
    init(args: TupleExpr, returns: Expr) {
        self.args = args
        self.returns = returns
    }
    
    var type: Ty? = nil
}













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
    
    init(statements: [(condition: Expr?, block: BlockExpr)]) throws {
        var p: [ElseIfBlockStmt] = []
        
        for (index, path) in statements.enumerate() {
            
            p.append(ElseIfBlockStmt(condition: path.0, block: path.1))
            
            // nil condition here is an else block, if there is anything after an else block then throw
            // either because there is more than 1 else or Exprs after an else
            guard let _ = path.condition else {
                if index == statements.count-1 { break }
                else { self.statements = []; throw ParseError.InvalidIfStatement }
            }
        }
        
        self.statements = p
    }
}













protocol LoopStmt : Stmt {
    var block: BlockExpr { get }
}


final class ForInLoopStmt : LoopStmt {
    
    let binded: Variable
    let iterator: Expr
    var block: BlockExpr
    
    init(identifier: Variable, iterator: Expr, block: BlockExpr) {
        self.binded = identifier
        self.iterator = iterator
        self.block = block
    }
}

final class WhileLoopExpr : LoopStmt {
    
    let condition: Expr
    var block: BlockExpr
    
    init(condition: Expr, block: BlockExpr) {
        self.condition = condition
        self.block = block
    }
}











final class ArrayExpr : Expr, AssignableExpr {
    
    let arr: [Expr]
    
    init(arr: [Expr]) {
        self.arr = arr
    }
    
    var elType: Ty?
    var type: Ty? = nil
}

final class ArraySubscriptExpr : Expr, AssignableExpr {
    let arr: Expr
    let index: Expr
    
    init(arr: Expr, index: Expr) {
        self.arr = arr
        self.index = index
    }
    
    var type: Ty? = nil
}


















protocol StructMember {
}


final class StructExpr : Expr {
    let name: String
    let properties: [VariableDecl]
    let methods: [FunctionDecl]
    var initialisers: [InitialiserDecl]
    let attrs: [AttributeExpr]
    
    init(name: String, properties: [VariableDecl], methods: [FunctionDecl], initialisers: [InitialiserDecl], attrs: [AttributeExpr]) {
        self.name = name
        self.properties = properties
        self.methods = methods
        self.initialisers = initialisers
        self.attrs = attrs
    }
    
    var type: Ty? = nil
}



final class MethodCallExpr <ObjectType : Expr> : Expr {
    let name: String
    let object: ObjectType
    let params: TupleExpr
    
    init(name: String, params: TupleExpr, object: ObjectType) {
        self.name = name
        self.params = params
        self.object = object
    }
    
    var mangledName: String = ""
    
    var type: Ty? = nil
}

final class PropertyLookupExpr : AssignableExpr {
    let name: String
    let object: Expr
    
    init(name: String, object: Expr) {
        self.name = name
        self.object = object
    }
    
    var type: Ty? = nil
}







