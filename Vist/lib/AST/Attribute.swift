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
    case inline = "inline"
    case noreturn = "noreturn"
    case noinline = "noinline"
    case mutating = "mutating"
    case `private` = "private", `public` = "public"
}
