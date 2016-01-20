//
//  Print.swift
//  Vist
//
//  Created by Josef Willsher on 04/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation

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
        
        let mirror = Mirror(reflecting: self)
        
        let children = mirror.children.flatMap { (label: String?, child: Any) -> (String?, Printable)? in
            if let v = child as? Printable where label != "parent" { return (label, v) } else { return nil }
        }
        
        let i = inline()
        let n0 = i ? "" : "\n", t1 = i ? " " : t(n+1), te = i ? "" : t(n)
        let ty = (self as? Typed)?.type
        let typeItem = ty != nil ? [("type", ty!)] : [] as [(String?, Printable)]
        
        return "(\(self.dynamicType)" + (children + typeItem).reduce("") {
            
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
