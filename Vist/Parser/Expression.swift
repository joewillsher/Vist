//
//  Expression.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


protocol Expression : Printable, TypeProvider, Typed {}


// TODO: make this generic
// use behaviour delegates (when released in swift 3) to make `let (delated) type: LLVMTyped { get }`
protocol Typed {
    var type: LLVMTyped? { get set }
}


protocol Sized : Expression {
    var size: UInt32 { get set }
}

protocol ExplicitlyTyped {
    var explicitType: String { get }
}

protocol Literal : Expression {
}

struct NullExpression : Expression {
    var type: LLVMTyped? = nil
}

protocol ScopeExpression : Expression, TypeProvider {
    var expressions: [Expression] { get set }
    var topLevel: Bool { get }
}

final class AST : ScopeExpression {
    var expressions: [Expression]
    var topLevel = true
    init(expressions: [Expression]) {
        self.expressions = expressions
    }
    
    var type: LLVMTyped? = nil
}
final class BlockExpression : ScopeExpression {
    var expressions: [Expression]
    var variables: [ValueType]
    
    var topLevel = false
    init(expressions: [Expression], variables: [ValueType] = []) {
        self.expressions = expressions
        self.variables = variables
    }
    
    var type: LLVMTyped? = nil
}

final class ClosureExpression : Expression {
    
    var expressions: [Expression]
    var parameters: [String]
    
    init(expressions: [Expression], params: [String]) {
        self.expressions = expressions
        self.parameters = params
    }
    
    var type: LLVMTyped? = nil
}


final class BooleanLiteral : Literal, BooleanType {
    let val: Bool
    
    init(val: Bool) {
        self.val = val
    }
    
    var type: LLVMTyped? = nil
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


final class FloatingPointLiteral : Literal, ExplicitlyTyped, FloatingPointType, Sized {
    let val: Double
    var size: UInt32 = 64
    var explicitType: String {
        return size == 32 ? "Float" : size == 64 ? "Double" : "Float\(size)"
    }
    
    init(val: Double, size: UInt32 = 64) {
        self.val = val
    }
    
    var type: LLVMTyped? = nil
}

final class IntegerLiteral : Literal, ExplicitlyTyped, IntegerType, Sized {
    let val: Int
    var size: UInt32
    var explicitType: String {
        return size == 32 ? "Int" : "Int\(size)"
    }
    
    init(val: Int, size: UInt32 = 64) {
        self.val = val
        self.size = size
    }
    
    var type: LLVMTyped? = nil
}
final class StringLiteral : Literal, Expression {
    let str: String
    var count: Int { return str.characters.count }
    
    init(str: String) {
        self.str = str
    }
    
//    var arr: ArrayExpression? = nil
    
    var type: LLVMTyped? = nil
}
//final class CharacterExpression : Expression {
//    let val: Character
//    
//    init(c: Character) {
//        val =  c
//    }
//    
//    var type: LLVMTyped? = nil
//}


struct CommentExpression : Expression {
    let str: String
    init(str: String) {
        self.str = str
        self.type = nil
    }
    var type: LLVMTyped? = nil
}

final class Void : Expression {
    var type: LLVMTyped? = nil
}


protocol AssignableExpression : Expression {}

/// A variable lookup expression
///
/// Generic over the variable type, use AnyExpression if this is not known
final class Variable : AssignableExpression {
    let name: String
    
    init(name: String) {
        self.name = name
    }
    
    var type: LLVMTyped? = nil
}

final class BinaryExpression : Expression {
    let op: String
    let lhs: Expression, rhs: Expression
    
    init(op: String, lhs: Expression, rhs: Expression) {
        self.op = op
        self.lhs = lhs
        self.rhs = rhs
    }
    
    var mangledName: String = ""
    
    var type: LLVMTyped? = nil
}

final class PrefixExpression : Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
    
    var type: LLVMTyped? = nil
}

final class PostfixExpression : Expression {
    let op: String
    let expr: Expression
    
    init(op: String, expr: Expression) {
        self.op = op
        self.expr = expr
    }
    
    var type: LLVMTyped? = nil
}

final class FunctionCallExpression : Expression {
    let name: String
    let args: TupleExpression
    
    init(name: String, args: TupleExpression) {
        self.name = name
        self.args = args
        self.mangledName = name
    }
    
    var mangledName: String
    
    var type: LLVMTyped? = nil
}

final class AssignmentExpression : Expression, StructMember {
    let name: String
    let aType: String?
    let isMutable: Bool
    var value: Expression
    
    init(name: String, type: String?, isMutable: Bool, value: Expression) {
        self.name = name
        self.aType = type
        self.isMutable = isMutable
        self.value = value
    }
    
    var type: LLVMTyped? = nil
}

final class MutationExpression : Expression {
    let object: AssignableExpression
    let value: Expression
    
    init(object: AssignableExpression, value: Expression) {
        self.object = object
        self.value = value
    }
    
    var type: LLVMTyped? = nil
}


struct OpObj {
    let precedence: Int
}

class FunctionPrototypeExpression : Expression, StructMember {
    let name: String
    let fnType: FunctionType
    let impl: FunctionImplementationExpression?
    let attrs: [FunctionAttributeExpression]
    
    init(name: String, type: FunctionType, impl: FunctionImplementationExpression?, attrs: [FunctionAttributeExpression]) {
        self.name = name
        self.fnType = type
        self.impl = impl
        self.mangledName = name
        self.attrs = attrs
    }
    
    var mangledName: String
    
    var type: LLVMTyped? = nil
}

final class FunctionImplementationExpression : Expression {
    let params: TupleExpression
    let body: BlockExpression
    
    init(params: TupleExpression, body: BlockExpression) {
        self.params = params
        self.body = body
    }
    
    var type: LLVMTyped? = nil
}

final class TupleExpression : Expression {
    let elements: [Expression]
    
    init(elements: [Expression]) {
        self.elements = elements
    }
    
    static func void() -> TupleExpression{ return TupleExpression(elements: [])}
    
    func mapAs<T>(_: T.Type) -> [T] {
        return elements.flatMap { $0 as? T }
    }
    
    var type: LLVMTyped? = nil
}

final class ReturnExpression : Expression {
    let expression: Expression
    
    init(expression: Expression) {
        self.expression = expression
    }
    
    var type: LLVMTyped? = nil
}


final class ValueType : Expression {
    var name: String
    
    init(name: String) {
        self.name = name
    }
    
    var type: LLVMTyped? = nil
}


final class FunctionType : Expression {
    let args: TupleExpression
    let returns: Expression
    
    init(args: TupleExpression, returns: Expression) {
        self.args = args
        self.returns = returns
    }
    
    var type: LLVMTyped? = nil
}






final class ElseIfBlockExpression<BlockType : ScopeExpression> : Expression {
    var condition: Expression?
    var block: BlockType
    
    init(condition: Expression?, block: BlockType) {
        self.condition = condition
        self.block = block
    }
    
    var type: LLVMTyped? = nil
}


final class ConditionalExpression<BlockType : ScopeExpression> : Expression {
    let statements: [ElseIfBlockExpression<BlockType> ]
    
    init(statements: [(condition: Expression?, block: BlockType)]) throws {
        var p: [ElseIfBlockExpression<BlockType>] = []
        
        for (index, path) in statements.enumerate() {
            
            p.append(ElseIfBlockExpression<BlockType>(condition: path.0, block: path.1))
            
            // nil condition here is an else block, if there is anything after an else block then throw
            // either because there is more than 1 else or expressions after an else
            guard let _ = path.condition else {
                if index == statements.count-1 { break }
                else { self.statements = []; throw ParseError.InvalidIfStatement }
            }
        }
        
        self.statements = p
    }
    
    var type: LLVMTyped? = nil
}

protocol LoopExpression : Expression {
    
    typealias BlockType: ScopeExpression
    
//    var iterator: Expression { get }
    var block: BlockType { get }
}


final class ForInLoopExpression
    <BlockType : ScopeExpression>
    : LoopExpression {
    
    let binded: Variable
    let iterator: Expression
    var block: BlockType
    
    init(identifier: Variable, iterator: Expression, block: BlockType) {
        self.binded = identifier
        self.iterator = iterator
        self.block = block
    }
    
    var type: LLVMTyped? = nil
}

final class WhileLoopExpression
    <BlockType : ScopeExpression>
    : LoopExpression {
    
    let iterator: WhileIteratorExpression
    var block: BlockType
    
    init(iterator: WhileIteratorExpression, block: BlockType) {
        self.iterator = iterator
        self.block = block
    }
    
    var type: LLVMTyped? = nil
}


protocol IteratorExpression : Expression {
}

final class RangeIteratorExpression : IteratorExpression {
    
    let start: Expression, end: Expression
    
    init(s: Expression, e: Expression) {
        start = s
        end = e
    }
    
    var type: LLVMTyped? = nil
}

final class WhileIteratorExpression : IteratorExpression {
    
    let condition: Expression
    
    init(condition: Expression) {
        self.condition = condition
    }
    
    
    var type: LLVMTyped? = nil
}

final class ArrayExpression : Expression, AssignableExpression {
    
    let arr: [Expression]
    
    init(arr: [Expression]) {
        self.arr = arr
    }
    
    var elType: LLVMTyped?
    var type: LLVMTyped? = nil
}

final class ArraySubscriptExpression : Expression, AssignableExpression {
    let arr: Expression
    let index: Expression
    
    init(arr: Expression, index: Expression) {
        self.arr = arr
        self.index = index
    }
    
    var type: LLVMTyped? = nil
}






protocol StructMember {
}


final class StructExpression : Expression {
    let name: String
    let properties: [AssignmentExpression]
    let methods: [FunctionPrototypeExpression]
    var initialisers: [InitialiserExpression]
    let attrs: [AttributeExpression]
    
    init(name: String, properties: [AssignmentExpression], methods: [FunctionPrototypeExpression], initialisers: [InitialiserExpression], attrs: [AttributeExpression]) {
        self.name = name
        self.properties = properties
        self.methods = methods
        self.initialisers = initialisers
        self.attrs = attrs
    }
    
    var type: LLVMTyped? = nil
}

final class InitialiserExpression : Expression, StructMember {
    let ty: FunctionType
    let impl: FunctionImplementationExpression?
    weak var parent: StructExpression?
    
    init(ty: FunctionType, impl: FunctionImplementationExpression?, parent: StructExpression?) {
        self.ty = ty
        self.impl = impl
        self.parent = parent
        self.mangledName = ""
    }
    
    var mangledName: String

    var type: LLVMTyped? = nil
}


final class MethodCallExpression <ObjectType : Expression> : Expression {
    let name: String
    let object: ObjectType
    let params: TupleExpression
    
    init(name: String, params: TupleExpression, object: ObjectType) {
        self.name = name
        self.params = params
        self.object = object
    }
    
    var type: LLVMTyped? = nil
}

final class PropertyLookupExpression : AssignableExpression {
    let name: String
    let object: Expression
    
    init(name: String, object: Expression) {
        self.name = name
        self.object = object
    }
    
    var type: LLVMTyped? = nil
}







