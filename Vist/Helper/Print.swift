//
//  Print.swift
//  Vist
//
//  Created by Josef Willsher on 04/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


private func t(n:Int) -> String {
    return Array(count: n, repeatedValue: "  ").reduce("", combine: +)
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

extension BlockExpr {
    func printList() -> [(String?, Printable)]? {
        return exprs.map { (nil, $0 as Printable) }
    }
}
extension AST {
    func printList() -> [(String?, Printable)]? {
        return [("Expressions", exprs)]
    }
}

extension VariableDecl {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("explicitType", aType), ("value", value), ("mutable", isMutable)]
    }
    
}

extension FunctionDecl {
    func printList() -> [(String?, Printable)]? {
        return [("name",name), ("mangled", mangledName), ("impl",impl), ("fnType", fnType), ("attrs", attrs)]
    }
}

extension FunctionType {
    func printList() -> [(String?, Printable)]? {
        return [("args", args), ("returns", returns)]
    }
}

extension FunctionAttributeExpr : Printable {
    
    func printVal() -> String? {
        return "@\(self.rawValue)"
    }
}
extension ASTAttributeExpr : Printable {
    
    func printVal() -> String? {
        switch self {
        case .Operator(prec: let p): return "@operator(\(p))"
        }
    }
}

extension TupleExpr {
    func printList() -> [(String?, Printable)]? {
        return elements.isEmpty ? [("Void","()")] : elements.enumerate().map { (Optional(String($0.0)), $0.1 as Printable) }
    }
    func inline() -> Bool {
        return elements.isEmpty
    }
}

extension FunctionImplementationExpr {
    func printList() -> [(String?, Printable)]? {
        return [("params", params), ("body", body)]
    }
}

extension BinaryExpr {
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

extension FunctionCallExpr {
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("args", args), ("mangled", mangledName)]
    }
}


extension CommentExpr {
    func printVal() -> String? {
        return "\"\(str.debugDescription)\""
    }
}

extension ReturnStmt {
    func printList() -> [(String?, Printable)]? {
        return [("Expression", expr)]
    }
}



private func ifStr(n n: Int, ex: ElseIfBlockStmt) -> String? {
    return ex.condition == nil ? "else" : n == 0 ? "if" : "if else"
}

extension ConditionalStmt {
    
    func printList() -> [(String?, Printable)]? {
        return statements.enumerate().map { (ifStr(n: $0, ex: $1), $1) }
    }
}

extension ElseIfBlockStmt {
    
    func printList() -> [(String?, Printable)]? {
        return [("cond", condition), ("then", block)]
    }
}
extension MutationExpr {
    
    func printList() -> [(String?, Printable)]? {
        return [("object", object), ("val", value)]
    }
}

extension ForInLoopStmt {
    
    func printList() -> [(String?, Printable)]? {
        return [("for", binded), ("in", iterator), ("do", block)]
    }
    
}


extension WhileLoopExpr {
    
    func printList() -> [(String?, Printable)]? {
        return [("while", condition), ("do", block)]
    }
    
}


extension ArrayExpr {
    
    func printList() -> [(String?, Printable)]? {
        return arr.enumerate().map { (String($0), $1) }
    }
    
}

extension ArraySubscriptExpr {
    
    func printList() -> [(String?, Printable)]? {
        return [("arr", arr), ("index", index)]
    }
}

extension StructExpr {
    
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("properties", properties), ("methods", methods), ("initialisers", initialisers)]
    }
}

extension FnType: Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("params", params), ("returns", returns)]
    }
}

extension BuiltinType : Printable {
    
    func printVal() -> String? {
        return "\(self)"
    }
}

extension ValueType : Printable {
    
    func printVal() -> String? {
        return name
    }
}

extension ClosureExpr : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return exprs.map { (nil, $0 as Printable) }
    }
}

extension InitialiserDecl : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("ty", ty), ("impl", impl), ("mangled", mangledName)]
    }
}

extension PropertyLookupExpr : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("object", object)]
    }
}

extension MethodCallExpr : Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("name", name), ("object", object), ("params", params)]
    }
}
extension StructType: Printable {
    
    func printList() -> [(String?, Printable)]? {
        return [("members", members), ("methods", methods)]
    }
}
