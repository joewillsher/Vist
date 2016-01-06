//
//  FunctionAttribute.swift
//  Vist
//
//  Created by Josef Willsher on 06/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


enum AttributeExpression {
    case Inline
    
    init?(name: String) {
        
        switch name {
        case "inline":
            self = .Inline
            
        default:
            return nil
        }
    }
    
    func addAttrTo(function: LLVMValueRef) {
        switch self {
        case .Inline:
            LLVMAddFunctionAttr(function, LLVMAlwaysInlineAttribute)
        }
    }
}

