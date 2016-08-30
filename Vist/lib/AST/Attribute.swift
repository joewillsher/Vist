//
//  Attribute.swift
//  Vist
//
//  Created by Josef Willsher on 30/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol AttributeExpr { }

enum ASTAttributeExpr: AttributeExpr {
    case Operator(prec: Int)
}

enum FunctionAttributeExpr: String, AttributeExpr {
    case inline
    case noreturn
    case noinline
    case mutating
    case `private`, `public`
    case runtime
}
