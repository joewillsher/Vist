//
//  FunctionAttribute.swift
//  Vist
//
//  Created by Josef Willsher on 06/01/2016.
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
    
    func addAttrTo(function: LLVMValueRef) {
        switch self {
        case .inline: LLVMAddFunctionAttr(function, LLVMAlwaysInlineAttribute)
        case .noreturn: LLVMAddFunctionAttr(function, LLVMNoReturnAttribute)
        case .noinline: LLVMAddFunctionAttr(function, LLVMNoInlineAttribute)
        case .`private`: LLVMSetLinkage(function, LLVMPrivateLinkage)
        case .`public`: LLVMSetLinkage(function, LLVMExternalLinkage)
        default: break
        }
    }
}

