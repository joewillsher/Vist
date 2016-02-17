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

protocol Printable {
    var astString: String { get }
}

extension Printable {
    
    var astString: String {
        return _description(0)
    }
    
    func _description(n: Int) -> String {
        
        if let v = printDirectly() { return v }
        
        let mirror = Mirror(reflecting: self)
        
        let children = mirror.children.flatMap { (label: String?, child: Any) -> (String?, Printable)? in
            if case let v as Printable = child where label != "parent" { return (label, v) } else { return nil }
        }
        
        let n0 = "\n", t1 = t(n+1), te = t(n)
        
        return "(\(self.dynamicType)" + children
            .reduce("") {
            let a = $1.0.map { "\($0):" } ?? ""
            return "\($0)\(n0)\(t1)\(a)\($1.1._description(n+1))" } + "\(n0)\(te))"
    }
    
        
    /// Print the object, not a _description of it
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
    
    func printVal() -> String? {
        return isEmpty ? "[]" : nil
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
}
