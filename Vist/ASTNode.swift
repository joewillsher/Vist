////
////  ASTNode.swift
////  Vist
////
////  Created by Josef Willsher on 27/12/2015.
////  Copyright © 2015 vistlang. All rights reserved.
////
//
//import Foundation
//
///// ASTNode represents all objects in the AST that the parser can generate
/////
///// 1 level of abstraction, blocks and expressions
//protocol ASTNode {}
//
//
//enum TypeAST : ASTNode {
//    
//    case Type(String)
//
//    case FunctionType(args: [TypeAST], returns: [TypeAST])
//}
//
//
///// An AST object, produced by the parser, which is an expression
//enum ExpressionAST : ASTNode {
//    
//    case IntegerLiteral(val: Int, size: UInt64), BooleanLiteral(val: Bool), FloatingPointLiteral(val: Double, size: UInt64), StringLiteral(val: String)
//    
//    case Void, Comment(str: String)
//    
//    case VariableLookup(name: String)
//    
//    indirect case BinaryOperator(op: String, lhs: ExpressionAST, rhs: ExpressionAST), PrefixOperator(op: String, exp: ExpressionAST), PostfixOperator(op: String, exp: ExpressionAST)
//    indirect case FunctionCall(name: String, parameters: [ExpressionAST])
//    
//    indirect case Tuple(elements: [ExpressionAST])
//    
//    indirect case Assignment(name: String, mutable: Bool, value: ASTNode), Mutation(object: ASTNode, value: ASTNode)
//    
//    
////    indirect case FunctionPrototype(
//    
//    
//    indirect case Return(exp: TypeAST)
//    
//    
//}
//
///// An AST object, produced by the parser, which is a block
//enum BlockAST : ASTNode {
//    
//    indirect case AST(expressions: [ExpressionAST]), Block(expressions: [ExpressionAST])
//    
//    
//}
