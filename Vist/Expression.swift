//
//  AST.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

protocol Expression: Printable {
}

protocol Typed {
    var type: Type { get }
}
protocol Sized: Expression {
    var size: UInt32 { get set }
}
protocol Type: Expression {}

protocol Literal: Expression {
}

protocol Scope: Expression {
    var expressions: [Expression] { get set }
    var topLevel: Bool { get }
}

struct AST: Scope {
    var expressions: [Expression]
    var topLevel = true
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
}
struct Block: Scope {
    var expressions: [Expression]
    var topLevel = false
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
}
struct DefinitionScope: Scope {
    var expressions: [Expression]
    var topLevel = false
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
}
struct EndOfScope: Expression {}


struct BooleanLiteral: Literal, Typed, BooleanType {
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


struct FloatingPointLiteral: Literal, Typed, FloatingPointType, Sized {
    let val: Double
    var size: UInt32 = 64
    var type: Type {
        return ValueType(name: size == 32 ? "Float" : size == 64 ? "Double" : "Float\(size)")
    }
    
    init(val: Double, size: UInt32 = 64) {
        self.val = val
    }
}

struct IntegerLiteral: Literal, Typed, IntegerType, Sized {
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
struct StringLiteral: Literal, Typed {
    let str: String
    var type: Type
    
    init(str: String) {
        self.str = str
        self.type = ValueType(name: "String")
    }
}

struct Comment: Expression {
    let str: String
}

struct Variable: Expression {
    let name: String?
    let isMutable: Bool = false
    
    init(name: String?, isMutable: Bool = false) {
        self.name = name
    }
}

struct BinaryExpression: Expression {
    let op: String
    let lhs: Expression, rhs: Expression
    
    init(op: String, lhs: Expression, rhs: Expression) {
        self.op = op
        self.lhs = lhs
        self.rhs = rhs
    }
}

struct PrefixExpression: Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
}

struct PostfixExpression: Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
}

struct FunctionCall: Expression {
    let name: String
    let args: Tuple
    
    init(name: String, args: Tuple) {
        self.name = name
        self.args = args
    }
}

struct Assignment: Expression {
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




struct FunctionPrototype: Type {
    let name: String
    let type: FunctionType
    let impl: FunctionImplementation?
    
    init(name: String, type: FunctionType, impl: FunctionImplementation?) {
        self.name = name
        self.type = type
        self.impl = impl
    }
}

struct FunctionImplementation: Expression {
    let params: Tuple
    let body: Expression
}

struct Tuple: Expression {
    let elements: [Expression]
    
    init(elements: [Expression]) {
        self.elements = elements
    }
    
    static func void() -> Tuple{ return Tuple(elements: [])}
}




struct ValueType: Type {
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
}

struct FunctionType: Type {
    let args: Tuple
    let returns: Tuple
    
    init(args: Tuple, returns: Tuple) {
        self.args = args
        self.returns = returns
    }
    
    func desc() -> String {
        let params = args.elements.isEmpty ? "()" : "(\(args.elements[0])" + args.elements.dropFirst().reduce("") { "\($0), \($1)" } + ")"
        let ret = returns.elements.isEmpty ? "Void" : (returns.elements.count > 1 ? "(" : "") + "\(returns.elements[0])" + returns.elements.dropFirst().reduce("") { "\($0), \($1)" }  + (returns.elements.count > 1 ? ")" : "")
        return params + " -> " + ret
    }
}






