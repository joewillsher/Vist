//
//  Print.swift
//  Vist
//
//  Created by Josef Willsher on 04/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


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

extension Array : Printable {
    
    func printList() -> [(String?, Printable)]? {
        
        var list: [Printable] = []
        
        for el in self where el is Printable {
            let p = el as! Printable
            
            list.append(p)
        }
        
        return list.enumerate().map { (String?("\($0)"), $1) }
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

extension AssignmentExpression {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("explicitType", aType), ("type",type), ("value", value)]
    }
    
}

extension FunctionPrototypeExpression {
    func printList() -> [(String?, Printable)]? {
        return [("name",name), ("type",type), ("impl",impl)]
    }
}

extension FunctionType {
    func printVal() -> String? {
        return desc()
    }
}

extension TupleExpression {
    func printList() -> [(String?, Printable)]? {
        return elements.isEmpty ? [("Void","()")] : elements.enumerate().map { (Optional(String($0.0)), $0.1 as Printable) }
    }
    func inline() -> Bool {
        return elements.isEmpty
    }
}

extension FunctionImplementationExpression {
    func printList() -> [(String?, Printable)]? {
        return [("params", params), ("body", body)]
    }
}

extension BinaryExpression {
    func printList() -> [(String?, Printable)]? {
        return [("operator", op), ("lhs", lhs), ("rhs", rhs)]
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
        return [("name", name)]
    }
}

extension FunctionCallExpression {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("args", args)]
    }
}


extension CommentExpression {
    func printVal() -> String? {
        return "\"\(str)\""
    }
}

extension ReturnExpression {
    func printList() -> [(String?, Printable)]? {
        return [("expression", expression)]
    }
}



private func ifStr<BlockType>(n n: Int, ex: ElseIfBlockExpression<BlockType>) -> String? {
    return ex.condition == nil ? "else" : n == 0 ? "if" : "if else"
}

extension ConditionalExpression {
    
    func printList() -> [(String?, Printable)]? {
        return statements.enumerate().map { (ifStr(n: $0, ex: $1), $1) }
    }
}

extension ElseIfBlockExpression {
    
    func printList() -> [(String?, Printable)]? {
        return [("cond", condition), ("then", block)]
    }
}
extension MutationExpression {
    
    func printList() -> [(String?, Printable)]? {
        return [("object", object), ("val", value)]
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

extension ArrayExpression {
    
    func printList() -> [(String?, Printable)]? {
        return arr.enumerate().map { (String($0), $1) }
    }
    
}

extension ArraySubscriptExpression {
    
    func printList() -> [(String?, Printable)]? {
        return [("arr", arr), ("index", index)]
    }
}

extension StructExpression {
    
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("properties", properties), ("methods", methods)]
    }
}

extension LLVMFnType : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("params", params), ("returns", returns)]
    }
}

extension LLVMType : Printable {
    
    func printVal() -> String? {
        return "\(self)"
    }
}

extension ValueType : Printable {
    
    func printVal() -> String? {
        return name
    }
}
