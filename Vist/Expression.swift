//
//  AST.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

protocol Expression : Printable {
}

protocol Typed {
    var type: Type { get }
}
protocol Sized : Expression {
    var size: UInt32 { get set }
}
protocol Type : Expression {}

protocol Literal : Expression {
}




protocol ScopeExpression : Expression {
    var expressions: [Expression] { get set }
    var topLevel: Bool { get }
}

class AST : ScopeExpression {
    var expressions: [Expression]
    var topLevel = true
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
}
class BlockExpression : ScopeExpression {
    var expressions: [Expression]
    var topLevel = false
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
}
class DefinitionScope : ScopeExpression {
    var expressions: [Expression]
    var topLevel = false
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
}
struct EndOfScope : Expression {}


struct BooleanLiteral : Literal, Typed, BooleanType {
    let val: Bool
    var type: Type = ValueType(name: "Bool")
    
    init(val: Bool) {
        self.val = val
    }
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


struct FloatingPointLiteral : Literal, Typed, FloatingPointType, Sized {
    let val: Double
    var size: UInt32 = 64
    var type: Type {
        return ValueType(name: size == 32 ? "Float" : size == 64 ? "Double" : "Float\(size)")
    }
    
    init(val: Double, size: UInt32 = 64) {
        self.val = val
    }
}

struct IntegerLiteral : Literal, Typed, IntegerType, Sized {
    let val: Int
    var size: UInt32
    var type: Type {
        return ValueType(name: size == 32 ? "Int" : "Int\(size)")
    }
    
    init(val: Int, size: UInt32 = 64) {
        self.val = val
        self.size = size
    }

}
struct StringLiteral : Literal, Typed {
    let str: String
    var type: Type
    
    init(str: String) {
        self.str = str
        self.type = ValueType(name: "String")
    }
}

struct CommentExpression : Expression {
    let str: String
}

struct Void : Expression {}


protocol AssignableExpression : Expression {}

class Variable : AssignableExpression {
    let name: String
    let isMutable: Bool = false
    
    init(name: String, isMutable: Bool = false) {
        self.name = name
    }
}

class BinaryExpression : Expression {
    let op: String
    let lhs: Expression, rhs: Expression
    
    init(op: String, lhs: Expression, rhs: Expression) {
        self.op = op
        self.lhs = lhs
        self.rhs = rhs
    }
}

class PrefixExpression : Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
}

class PostfixExpression : Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
}

class FunctionCallExpression : Expression {
    let name: String
    let args: TupleExpression
    
    init(name: String, args: TupleExpression) {
        self.name = name
        self.args = args
    }
}

class AssignmentExpression : Expression, StructMember {
    let name: String
    let type: String?
    let isMutable: Bool
    let value: Expression
    
    init(name: String, type: String?, isMutable: Bool, value: Expression) {
        self.name = name
        self.type = type
        self.isMutable = isMutable
        self.value = value
    }
}

class MutationExpression : Expression {
    let object: AssignableExpression
    let value: Expression
    
    init(object: AssignableExpression, value: Expression) {
        self.object = object
        self.value = value
    }
}



class FunctionPrototypeExpression : Expression, StructMember {
    let name: String
    let type: FunctionType
    let impl: FunctionImplementationExpression?
    
    init(name: String, type: FunctionType, impl: FunctionImplementationExpression?) {
        self.name = name
        self.type = type
        self.impl = impl
    }
}

class FunctionImplementationExpression : Expression {
    let params: TupleExpression
    let body: BlockExpression
    
    init(params: TupleExpression, body: BlockExpression) {
        self.params = params
        self.body = body
    }
}

class TupleExpression : Expression {
    let elements: [Expression]
    
    init(elements: [Expression]) {
        self.elements = elements
    }
    
    static func void() -> TupleExpression{ return TupleExpression(elements: [])}
    
    func mapAs<T>(t: T.Type) -> [T] {
        return elements.flatMap { $0 as? T }
    }
}

class ReturnExpression : Expression {
    let expression: Expression
    
    init(expression: Expression) {
        self.expression = expression
    }
}


class ValueType : Type {
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
}

class FunctionType : Type {
    let args: TupleExpression
    let returns: TupleExpression
    
    init(args: TupleExpression, returns: TupleExpression) {
        self.args = args
        self.returns = returns
    }
    
    func desc() -> String {
        let params = args.elements.isEmpty ? "()" : "(\(args.elements[0])" + args.elements.dropFirst().reduce("") { "\($0), \($1)" } + ")"
        let ret = returns.elements.isEmpty ? "Void" : (returns.elements.count > 1 ? "(" : "") + "\(returns.elements[0])" + returns.elements.dropFirst().reduce("") { "\($0), \($1)" }  + (returns.elements.count > 1 ? ")" : "")
        return params + " -> " + ret
    }
}






class ElseIfBlockExpression : Expression {
    let condition: Expression?
    let block: ScopeExpression
    
    init(condition: Expression?, block: ScopeExpression) {
        self.condition = condition
        self.block = block
    }
}


class ConditionalExpression : Expression {
    let statements: [ElseIfBlockExpression]
    
    init(statements: [(condition: Expression?, block: ScopeExpression)]) throws {
        var p: [ElseIfBlockExpression] = []
        
        for (index, path) in statements.enumerate() {
            
            p.append(ElseIfBlockExpression(path))
            
            // nil condition here is an else block, if there is anything after an else block then throw
            // either because there is more than 1 else or expressions after an else
            guard let _ = path.condition else {
                if index == statements.count-1 { break }
                else { self.statements = []; throw ParseError.InvalidIfStatement }}
        }
        
        self.statements = p
    }
}

protocol LoopExpression : Expression {
    
    typealias Iterator: IteratorExpression
    
    var iterator: Iterator { get }
    var block: BlockExpression { get }
}


class ForInLoopExpression<Iterator : IteratorExpression> : LoopExpression {
    
    let binded: Variable
    let iterator: Iterator
    let block: BlockExpression
    
    init(identifier: Variable, iterator: Iterator, block: BlockExpression) {
        self.binded = identifier
        self.iterator = iterator
        self.block = block
    }
    
}

class WhileLoopExpression<Iterator : IteratorExpression> : LoopExpression {
    
    let iterator: WhileIteratorExpression
    let block: BlockExpression
    
    init(iterator: WhileIteratorExpression, block: BlockExpression) {
        self.iterator = iterator
        self.block = block
    }
    
}


protocol IteratorExpression : Expression {
}

class RangeIteratorExpression : IteratorExpression {
    
    let start: Int, end: Int
    
    init(s: Int, e: Int) {
        start = s
        end = e
    }
}

class WhileIteratorExpression : IteratorExpression {
    
    let condition: Expression
    
    init(condition: Expression) {
        self.condition = condition
    }
    
}

class ArrayExpression : Expression, AssignableExpression {
    
    let arr: [Expression]
    
    init(arr: [Expression]) {
        self.arr = arr
    }
    
}

class ArraySubscriptExpression : Expression, AssignableExpression {
    let arr: Expression
    let index: Expression
    
    init(arr: Expression, index: Expression) {
        self.arr = arr
        self.index = index
    }
    
}






protocol StructMember {
}


class StructExpression : Expression {
    
    let name: String
    let properties: [AssignmentExpression]
    let methods: [FunctionPrototypeExpression]
    
    init(name: String, properties: [AssignmentExpression], methods: [FunctionPrototypeExpression]) {
        self.name = name
        self.properties = properties
        self.methods = methods
    }
    
}






// TODO: Implement more generic expressions









