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
}


extension Printable {
    public var description: String {
        return _description(0)
    }
}

extension Printable {
    
    public func _description(n: Int) -> String {
        
        if let v = printDirectly() { return v }
        if let v = printVal() { return "(\(self.dynamicType) \(v))" }
        
        let mirror = Mirror(reflecting: self)
        
        let children = mirror.children.flatMap { (label: String?, child: Any) -> (String?, Printable)? in
            if case let v as Printable = child where label != "parent" { return (label, v) } else { return nil }
        }
        
        let n0 = "\n", t1 = t(n+1), te = t(n)
        
        return "(\(self.dynamicType)" + children
            .reduce("") {
            
            let a: String
            if let s = $1.0 { a = "\(s):" }
            else            { a = "" }
            
            return "\($0)\(n0)\(t1)\(a)\($1.1._description(n+1))" } + "\(n0)\(te))"
    }
    
    /// implement to call _description on children
    public func printList() -> [(String?, Printable)]? { return nil }
    
    /// should represent this object
    public func printVal() -> String? { return nil }
    
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
    
    public func printVal() -> String? {
        return isEmpty ? "[]" : nil
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
}
