//
//  Print.swift
//  Vist
//
//  Created by Josef Willsher on 04/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation



private func t(n:Int) -> String {
    return Array(count: n, repeatedValue: "\t").reduce("", combine: +)
}


protocol Printable {
    func description(n: Int) -> String
    func printList() -> [(String?, Printable)]?
    func printVal() -> String?
    func printDirectly() -> String?
    func inline() -> Bool
}

extension Printable {
    
    func description(n: Int = 0) -> String {
        
        if let v = printDirectly() { return v }
        if let v = printVal() { return "(\(self.dynamicType) \(v))" }
        
        let i = inline()
        let n0 = i ? "" : "\n", t1 = i ? " " : t(n+1), te = i ? "" : t(n)
    
        return "(\(self.dynamicType)" + (printList() ?? []).reduce("") {
            
            let a: String
            if let s = $1.0 {
                a = s + ":"
            } else {
                a = ""
            }
            
            return "\($0)\(n0)\(t1)\(a)\($1.1.description(n+1))" } + "\(n0)\(te))"
    }
    
    /// implement to call description on children
    func printList() -> [(String?, Printable)]? { return nil }
    
    /// should represent this object
    func printVal() -> String? { return nil }
    
    /// return true to run children inline
    func inline() -> Bool { return false }
    
    /// Print the object, not a description of it
    func printDirectly() -> String? { return nil }
}


extension String : Printable {
    func printDirectly() -> String? {
        return "\"\(self)\""
    }
}
extension Int : Printable {
    func printDirectly() -> String? {
        return "\(self)"
    }
}
extension UInt32 : Printable {
    func printDirectly() -> String? {
        return "\(self)"
    }
}
extension Float : Printable {
    func printDirectly() -> String? {
        return "\(self)"
    }
}
extension Double : Printable {
    func printDirectly() -> String? {
        return "\(self)"
    }
}
extension Bool : Printable {
    func printDirectly() -> String? {
        return "\(self)"
    }
}

extension Optional : Printable {
    func printDirectly() -> String? {
        switch self {
        case .None: return "nil"
        case .Some(let a) where a is Printable: return (a as! Printable).printDirectly()
        case _: return nil
        }
    }
    
    func printVal() -> String? {
        switch self {
        case .None: return "nil"
        case .Some(let a) where a is Printable: return (a as! Printable).printVal()
        case _: return nil
        }
    }
    
    func printList() -> [(String?, Printable)]? {
        switch self {
        case .None: return nil
        case .Some(let a) where a is Printable: return (a as! Printable).printList()
        case _: return nil
        }
    }
}

extension ScopeExpression {
    func printList() -> [(String?, Printable)]? {
        return expressions.map {(nil, $0 as Printable) }
    }
}

extension Assignment {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("type", type), ("value", value)]
    }
    
}

extension FunctionPrototype {
    func printList() -> [(String?, Printable)]? {
        return [("name",name), ("type",type), ("impl",impl)]
    }
}

extension FunctionType {
    func printVal() -> String? {
        return desc()
    }
}

extension Tuple {
    func printList() -> [(String?, Printable)]? {
        return elements.isEmpty ? [("Void","()")] : elements.enumerate().map { (Optional(String($0.0)), $0.1 as Printable) }
    }
    func inline() -> Bool {
        return elements.isEmpty
    }
}

extension FunctionImplementation {
    func printList() -> [(String?, Printable)]? {
        return [("params", params), ("body", body)]
    }
}

extension BinaryExpression {
    func printList() -> [(String?, Printable)]? {
        return [("operator", op), ("lhs", lhs), ("rhs", rhs)]
    }
}

extension ValueType {
    func printList() -> [(String?, Printable)]? {
        return [("name", name)]
    }
    func inline() -> Bool {
        return true
    }
}

extension IntegerLiteral {
    func printList() -> [(String?, Printable)]? {
        return [("val", val), ("size", size)]
    }
    func inline() -> Bool {
        return true
    }
}
extension FloatingPointLiteral {
    func printList() -> [(String?, Printable)]? {
        return [("val", val), ("size", size)]
    }
    func inline() -> Bool {
        return true
    }
}
extension Variable {
    func inline() -> Bool {
        return true
    }
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("is_mutable", isMutable)]
    }
}

extension FunctionCall {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("args", args)]
    }
}

extension EndOfScope {
    func inline() -> Bool {
        return true
    }
}

extension Comment {
    func printVal() -> String? {
        return "\"\(str)\""
    }
}

extension ReturnExpression {
    func printList() -> [(String?, Printable)]? {
        return [("expression", expression)]
    }
}



private func ifStr(n n: Int, ex: ElseIfBlock) -> String? {
    return ex.condition == nil ? "else" : n == 0 ? "if" : "if else"
}

extension ConditionalExpression {
    
    func printList() -> [(String?, Printable)]? {
        return statements.enumerate().map { (ifStr(n: $0, ex: $1), $1) }
    }
}

extension ElseIfBlock {
    
    func printList() -> [(String?, Printable)]? {
        return [("cond", condition), ("then", block)]
    }
}
extension Mutation {
    
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("val", value)]
    }
}

extension ForInLoopExpression {
    
    func printList() -> [(String?, Printable)]? {
        return [("for", binded), ("in", iterator), ("do", block)]
    }
    
}

extension RangeIteratorExpression {
    func printList() -> [(String?, Printable)]? {
        return [("start", start), ("end", end)]
    }
    func inline() -> Bool {
        return true
    }
}

extension WhileLoopExpression {
    
    func printList() -> [(String?, Printable)]? {
        return [("while", iterator), ("do", block)]
    }
    
}

extension WhileIteratorExpression {
    
    func printList() -> [(String?, Printable)]? {
        return [("cond", condition)]
    }
}

