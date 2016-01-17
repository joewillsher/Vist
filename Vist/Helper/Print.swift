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


public protocol Printable : CustomStringConvertible {
    func _description(n: Int) -> String
    func printList() -> [(String?, Printable)]?
    func printVal() -> String?
    func printDirectly() -> String?
    func inline() -> Bool
}

extension AST {
    
    var description: String {
        return _description(0)
    }
}

extension Printable {
    public var description: String {
        return "\(self.dynamicType)"
    }
}

extension Printable {
    
    public func _description(n: Int) -> String {
        
        if let v = printDirectly() { return v }
        if let v = printVal() { return "(\(self.dynamicType) \(v))" }
        
        let i = inline()
        let n0 = i ? "" : "\n", t1 = i ? " " : t(n+1), te = i ? "" : t(n)
        let ty = (self as? Typed)?.type
        let typeItem = ty != nil ? [("type", ty!)] : [] as [(String?, Printable)]
        
        return "(\(self.dynamicType)" + ((printList() ?? []) + typeItem).reduce("") {
            
            let a: String
            if let s = $1.0 { a = "\(s):" }
            else            { a = "" }
            
            return "\($0)\(n0)\(t1)\(a)\($1.1._description(n+1))" } + "\(n0)\(te))"
    }
    
    /// implement to call _description on children
    public func printList() -> [(String?, Printable)]? { return nil }
    
    /// should represent this object
    public func printVal() -> String? { return nil }
    
    /// return true to run children inline
    public func inline() -> Bool { return false }
    
    /// Print the object, not a _description of it
    public func printDirectly() -> String? { return nil }
}


extension String : Printable {
    public func printDirectly() -> String? {
        return "\"\(self)\""
    }   
}
extension Int : Printable {
    public func printDirectly() -> String? {
        return "\(self)"
    }
}
extension UInt32 : Printable {
    public func printDirectly() -> String? {
        return "\(self)"
    }
}
extension Float : Printable {
    public func printDirectly() -> String? {
        return "\(self)"
    }
}
extension Double : Printable {
    public func printDirectly() -> String? {
        return "\(self)"
    }
}
extension Bool : Printable {
    public func printDirectly() -> String? {
        return "\(self)"
    }
}

extension Array : Printable {
    
    public func inline() -> Bool {
        return isEmpty
    }
    
    public func printVal() -> String? {
        return isEmpty ? "[]" : nil
    }
    public func printList() -> [(String?, Printable)]? {
        
        return self
            .flatMap { $0 as? Printable }
            .enumerate()
            .map { (String?("\($0)"), $1) }
    }
    
}

extension Optional : Printable {
    public func printDirectly() -> String? {
        switch self {
        case .None: return "nil"
        case .Some(let a) where a is Printable: return (a as! Printable).printDirectly()
        case _: return nil
        }
    }
    
    public func printVal() -> String? {
        switch self {
        case .None: return "nil"
        case .Some(let a) where a is Printable: return (a as! Printable).printVal()
        case _: return nil
        }
    }
    
    public func printList() -> [(String?, Printable)]? {
        switch self {
        case .None: return nil
        case .Some(let a) where a is Printable: return (a as! Printable).printList()
        case _: return nil
        }
    }
}

extension ScopeExpression {
    func printList() -> [(String?, Printable)]? {
        return expressions.map { (nil, $0 as Printable) }
    }
}
extension BlockExpression {
    func printList() -> [(String?, Printable)]? {
        return [("expressions", expressions), ("variables", variables)]
    }
}

extension AssignmentExpression {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("explicitType", aType), ("value", value), ("mutable", isMutable)]
    }
    
}

extension FunctionPrototypeExpression {
    func printList() -> [(String?, Printable)]? {
        return [("name",name), ("mangled", mangledName), ("impl",impl), ("fnType", fnType), ("attrs", attrs)]
    }
}

extension FunctionType {
    func printList() -> [(String?, Printable)]? {
        return [("args", args), ("returns", returns)]
    }
}

extension FunctionAttributeExpression : Printable {
    
    func printVal() -> String? {
        return "@\(self.rawValue)"
    }
}
extension ASTAttributeExpression : Printable {
    
    func printVal() -> String? {
        switch self {
        case .Operator(prec: let p): return "@operator(\(p))"
        }
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
extension StringLiteral {
    func printVal() -> String? {
        return "\"\(str.debugDescription)\""
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
        return !(type is StructType)
    }
    func printList() -> [(String?, Printable)]? {
        return [("name", name)]
    }
}

extension FunctionCallExpression {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("args", args), ("mangled", mangledName)]
    }
}


extension CommentExpression {
    func printVal() -> String? {
        return "\"\(str.debugDescription)\""
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
        return [("name", name), ("properties", properties), ("methods", methods), ("initialisers", initialisers)]
    }
}

extension FnType: Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("params", params), ("returns", returns)]
    }
}

extension NativeType : Printable {
    
    func printVal() -> String? {
        return "\(self)"
    }
}

extension ValueType : Printable {
    
    func printVal() -> String? {
        return name
    }
}

extension ClosureExpression : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return expressions.map { (nil, $0 as Printable) }
    }
}

extension InitialiserExpression : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("ty", ty), ("impl", impl), ("mangled", mangledName)]
    }
}

extension PropertyLookupExpression : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("object", object)]
    }
}

extension MethodCallExpression : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("object", object), ("params", params)]
    }
}
extension StructType: Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("members", members), ("methods", methods)]
    }
}
