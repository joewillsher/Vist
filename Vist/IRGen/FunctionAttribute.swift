//
//  FunctionAttribute.swift
//  Vist
//
//  Created by Josef Willsher on 06/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol AttributeExpression { }

enum ASTAttributeExpression : AttributeExpression {
    case Operator(prec: Int)
}

enum FunctionAttributeExpression : String, AttributeExpression {
    case Inline = "inline"
    case NoReturn = "noreturn"
    case NoInline = "noinline"
    
    func addAttrTo(function: LLVMValueRef) {
        switch self {
        case .Inline: LLVMAddFunctionAttr(function, LLVMAlwaysInlineAttribute)
        case .NoReturn: LLVMAddFunctionAttr(function, LLVMNoReturnAttribute)
        case .NoInline: LLVMAddFunctionAttr(function, LLVMNoInlineAttribute)
        }
    }
}

