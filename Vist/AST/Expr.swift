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
protocol Expr : ASTNode, _Typed, ExprTypeProvider {}
protocol TypedExpr : Expr, Typed {}

final class BlockExpr : TypedExpr, ScopeNode {
    var exprs: [ASTNode]
    var variables: [String]
    
    init(exprs: [ASTNode], variables: [String] = []) {
        self.exprs = exprs
        self.variables = variables
    }
    
    var type: FnType? = nil
    
    var childNodes: [ASTNode] {
        return exprs
    }
}

final class ClosureExpr : TypedExpr, ScopeNode {
    var exprs: [ASTNode]
    var parameters: [String]
    
    init(exprs: [ASTNode], params: [String]) {
        self.exprs = exprs
        self.parameters = params
    }
    
    var type: FnType? = nil
    
    var childNodes: [ASTNode] {
        return exprs
    }
}





//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                               Literals
//-------------------------------------------------------------------------------------------------------------------------

protocol SizedExpr : Expr {
    var size: UInt32 { get set }
}

protocol ExplicitlyTyped {
    var explicitType: String { get }
}

final class FloatingPointLiteral : SizedExpr, Typed, ExplicitlyTyped {
    let val: Double
    var size: UInt32 = 64
    var explicitType: String {
        return size == 32 ? "Float" : size == 64 ? "Double" : "Float\(size)"
    }
    
    init(val: Double, size: UInt32 = 64) {
        self.val = val
    }
    
    var type: StructType? = nil
}

final class IntegerLiteral : SizedExpr, Typed, ExplicitlyTyped {
    let val: Int
    var size: UInt32
    var explicitType: String {
        return size == 32 ? "Int" : "Int\(size)"
    }
    
    init(val: Int, size: UInt32 = 64) {
        self.val = val
        self.size = size
    }
    
    var type: StructType? = nil
}

final class BooleanLiteral : TypedExpr {
    let val: Bool
    
    init(val: Bool) {
        self.val = val
    }
    
    var type: StructType? = nil
}

final class StringLiteral : TypedExpr {
    let str: String
    var count: Int { return str.characters.count }
    
    init(str: String) {
        self.str = str
    }
    
//    var arr: ArrayExpr? = nil
    
    var type: BuiltinType? = nil
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





//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                               Variables
//-------------------------------------------------------------------------------------------------------------------------


/// A variable lookup Expr
///
/// Generic over the variable type, use AnyExpr if this is not known
final class VariableExpr : AssignableExpr {
    let name: String
    
    init(name: String) {
        self.name = name
    }
    
    var _type: Ty? = nil
    
    var desc: String {
        return name
    }
}

protocol AssignableExpr : Expr {
    var desc: String { get }
}

final class MutationExpr : Expr {
    let object: AssignableExpr
    let value: Expr
    
    init(object: AssignableExpr, value: Expr) {
        self.object = object
        self.value = value
    }
    
    var _type: Ty? = nil
}





//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                               Operators
//-------------------------------------------------------------------------------------------------------------------------

final class BinaryExpr : Expr {
    let op: String
    let lhs: Expr, rhs: Expr
    
    init(op: String, lhs: Expr, rhs: Expr) {
        self.op = op
        self.lhs = lhs
        self.rhs = rhs
    }
    
    var mangledName: String = ""
    
    var fnType: FnType? = nil
    var _type: Ty? = nil
}

final class PrefixExpr : Expr {
    let op: String
    let expr: Expr
    
    init(op: String, expr: Expr) {
        self.op = op
        self.expr = expr
    }
    
    var _type: Ty? = nil
}

final class PostfixExpr : Expr {
    let op: String
    let expr: Expr
    
    init(op: String, expr: Expr) {
        self.op = op
        self.expr = expr
    }
    
    var _type: Ty? = nil
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                               Functions
//-------------------------------------------------------------------------------------------------------------------------

final class FunctionCallExpr : Expr {
    let name: String
    let args: TupleExpr
    
    init(name: String, args: TupleExpr) {
        self.name = name
        self.args = args
        self.mangledName = name
    }
    
    var mangledName: String
    
    var fnType: FnType? = nil
    var _type: Ty? = nil
}


final class FunctionImplementationExpr : Expr {
    let params: [String]
    let body: BlockExpr
    
    init(params: [String], body: BlockExpr) {
        self.params = params
        self.body = body
    }
    
    var _type: Ty? = nil
}

final class TupleMemberLookupExpr : AssignableExpr {
    let index: Int
    let object: Expr
    
    init(index: Int, object: Expr) {
        self.index = index
        self.object = object
    }
    
    var _type: Ty? = nil
    
    var desc: String {
        return "tuple.\(index)"
    }
}

final class ReturnStmt : Stmt {
    let expr: Expr
    
    init(expr: Expr) {
        self.expr = expr
    }
}







//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                               Array
//-------------------------------------------------------------------------------------------------------------------------


final class ArrayExpr : AssignableExpr, Typed {
    
    let arr: [Expr]
    
    init(arr: [Expr]) {
        self.arr = arr
    }
    
    var elType: Ty?
    var type: BuiltinType? = nil
    
    var desc: String {
        return "array"
    }
}

final class ArraySubscriptExpr : AssignableExpr {
    let arr: Expr
    let index: Expr
    
    init(arr: Expr, index: Expr) {
        self.arr = arr
        self.index = index
    }
    
    var _type: Ty? = nil
    
    var desc: String {
        return "array[\(index)]"
    }
}




//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                               Struct
//-------------------------------------------------------------------------------------------------------------------------


protocol StructMemberExpr {
}


final class StructExpr : TypedExpr, ScopeNode {
    let name: String
    let properties: [VariableDecl]
    let methods: [FuncDecl]
    var initialisers: [InitialiserDecl]
    let attrs: [AttributeExpr]
    
    init(name: String, properties: [VariableDecl], methods: [FuncDecl], initialisers: [InitialiserDecl], attrs: [AttributeExpr]) {
        self.name = name
        self.properties = properties
        self.methods = methods
        self.initialisers = initialisers
        self.attrs = attrs
    }
    
    var type: StructType? = nil
    
    var childNodes: [ASTNode] {
        return properties.mapAs(ASTNode) + methods.mapAs(ASTNode) + initialisers.mapAs(ASTNode)
    }
}



final class MethodCallExpr <ObjectType : AssignableExpr> : Expr {
    let name: String
    let object: ObjectType
    let args: TupleExpr
    
    init(name: String, args: TupleExpr, object: ObjectType) {
        self.name = name
        self.args = args
        self.object = object
    }
    
    var mangledName: String = ""
    
    var structType: StructType? = nil
    var _type: Ty? = nil
}

final class PropertyLookupExpr : AssignableExpr {
    let name: String
    let object: AssignableExpr
    
    init(name: String, object: AssignableExpr) {
        self.name = name
        self.object = object
    }
    
    var _type: Ty? = nil
    
    var desc: String {
        return "object.\(name)"
    }
}





//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                               Other
//-------------------------------------------------------------------------------------------------------------------------


struct NullExpr : Expr {
    var _type: Ty? = BuiltinType.Null
}


//// FIXME: find another way to do this
///// used to lowe type name information
//final class ValueType : Expr {
//    var name: String
//    
//    init(name: String) {
//        self.name = name
//    }
//    
//    var _type: Ty? = nil
//}


final class TupleExpr : TypedExpr {
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
    
    var type: TupleType? = nil
}

struct CommentExpr : Expr {
    let str: String
    init(str: String) {
        self.str = str
    }
    
    var _type: Ty? = nil
}

final class Void : TypedExpr {
    var type: BuiltinType? = .Void
}


