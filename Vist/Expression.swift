//
//  AST.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

protocol Expression : Printable, LLVMTypeProvider, Typed {}

protocol Typed {
    var type: LLVMType? { get set }
}

struct AnyExpression : Expression {
    var type: LLVMType? = nil
}

protocol Sized : Expression {
    var size: UInt32 { get set }
}

protocol ExplicitlyTyped {
    var explicitType: String { get }
}

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
    
    var type: LLVMType? = nil
}
class BlockExpression : ScopeExpression {
    var expressions: [Expression]
    var topLevel = false
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
    
    var type: LLVMType? = nil
}


class BooleanLiteral : Literal, BooleanType {
    let val: Bool
    
    init(val: Bool) {
        self.val = val
    }
    
    var type: LLVMType? = nil
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


class FloatingPointLiteral : Literal, ExplicitlyTyped, FloatingPointType, Sized {
    let val: Double
    var size: UInt32 = 64
    var explicitType: String {
        return size == 32 ? "Float" : size == 64 ? "Double" : "Float\(size)"
    }
    
    init(val: Double, size: UInt32 = 64) {
        self.val = val
    }
    
    var type: LLVMType? = nil
}

class IntegerLiteral : Literal, ExplicitlyTyped, IntegerType, Sized {
    let val: Int
    var size: UInt32
    var explicitType: String {
        return size == 32 ? "Int" : "Int\(size)"
    }
    
    init(val: Int, size: UInt32 = 64) {
        self.val = val
        self.size = size
    }
    
    var type: LLVMType? = nil
}
struct StringLiteral : Literal, Typed {
    let str: String
    
    init(str: String) {
        self.str = str
    }
    
    var type: LLVMType? = nil
}

struct CommentExpression : Expression {
    let str: String
    init(str: String) {
        self.str = str
        self.type = nil
    }
    var type: LLVMType? = nil
}

class Void : Expression {
    var type: LLVMType? = nil
}


protocol AssignableExpression : Expression {}

/// A variable lookup expression
///
/// Generic over the variable type, use AnyExpression if this is not known
class Variable <T : Expression> : AssignableExpression {
    let name: String
    
    init(name: String) {
        self.name = name
    }
    
    var type: LLVMType? = nil
}

class BinaryExpression : Expression {
    let op: String
    let lhs: Expression, rhs: Expression
    
    init(op: String, lhs: Expression, rhs: Expression) {
        self.op = op
        self.lhs = lhs
        self.rhs = rhs
    }
    
    var type: LLVMType? = nil
}

class PrefixExpression : Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
    
    var type: LLVMType? = nil
}

class PostfixExpression : Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
    
    var type: LLVMType? = nil
}

class FunctionCallExpression : Expression {
    let name: String
    let args: TupleExpression
    
    init(name: String, args: TupleExpression) {
        self.name = name
        self.args = args
    }
    
    var type: LLVMType? = nil
}

class AssignmentExpression : Expression, StructMember {
    let name: String
    let aType: String?
    let isMutable: Bool
    let value: Expression
    
    init(name: String, type: String?, isMutable: Bool, value: Expression) {
        self.name = name
        self.aType = type
        self.isMutable = isMutable
        self.value = value
    }
    
    var type: LLVMType? = nil
}

class MutationExpression : Expression {
    let object: AssignableExpression
    let value: Expression
    
    init(object: AssignableExpression, value: Expression) {
        self.object = object
        self.value = value
    }
    
    var type: LLVMType? = nil
}



class FunctionPrototypeExpression : Expression, StructMember {
    let name: String
    let fnType: FunctionType
    let impl: FunctionImplementationExpression?
    
    init(name: String, type: FunctionType, impl: FunctionImplementationExpression?) {
        self.name = name
        self.fnType = type
        self.impl = impl
    }
    
    var type: LLVMType? = nil
}

class FunctionImplementationExpression : Expression {
    let params: TupleExpression
    let body: BlockExpression
    
    init(params: TupleExpression, body: BlockExpression) {
        self.params = params
        self.body = body
    }
    
    var type: LLVMType? = nil
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
    
    var type: LLVMType? = nil
}

class ReturnExpression : Expression {
    let expression: Expression
    
    init(expression: Expression) {
        self.expression = expression
    }
    
    var type: LLVMType? = nil
}


class ValueType : Expression {
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
    var type: LLVMType? = nil
}

class FunctionType : Expression {
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
    
    var type: LLVMType? = nil
}






class ElseIfBlockExpression : Expression {
    let condition: Expression?
    let block: ScopeExpression
    
    init(condition: Expression?, block: ScopeExpression) {
        self.condition = condition
        self.block = block
    }
    
    var type: LLVMType? = nil
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
    
    var type: LLVMType? = nil
}

protocol LoopExpression : Expression {
    
    typealias Iterator: IteratorExpression
    
    var iterator: Iterator { get }
    var block: BlockExpression { get }
}


class ForInLoopExpression
    <Iterator : IteratorExpression,
    BoundType : Expression>
    : LoopExpression {
    
    let binded: Variable<BoundType>
    let iterator: Iterator
    let block: BlockExpression
    
    init(identifier: Variable<BoundType>, iterator: Iterator, block: BlockExpression) {
        self.binded = identifier
        self.iterator = iterator
        self.block = block
    }
    
    var type: LLVMType? = nil
}

class WhileLoopExpression<Iterator : IteratorExpression> : LoopExpression {
    
    let iterator: WhileIteratorExpression
    let block: BlockExpression
    
    init(iterator: WhileIteratorExpression, block: BlockExpression) {
        self.iterator = iterator
        self.block = block
    }
    
    var type: LLVMType? = nil
}


protocol IteratorExpression : Expression {
}

class RangeIteratorExpression : IteratorExpression {
    
    let start: Expression, end: Expression
    
    init(s: Expression, e: Expression) {
        start = s
        end = e
    }
    
    var type: LLVMType? = nil
}

class WhileIteratorExpression : IteratorExpression {
    
    let condition: Expression
    
    init(condition: Expression) {
        self.condition = condition
    }
    
    
    var type: LLVMType? = nil
}

class ArrayExpression : Expression, AssignableExpression {
    
    let arr: [Expression]
    
    init(arr: [Expression]) {
        self.arr = arr
    }
    
    var elType: LLVMType?
    var type: LLVMType? = nil
}

class ArraySubscriptExpression : Expression, AssignableExpression {
    let arr: Expression
    let index: Expression
    
    init(arr: Expression, index: Expression) {
        self.arr = arr
        self.index = index
    }
    
    var type: LLVMType? = nil
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
    
    var type: LLVMType? = nil
}














