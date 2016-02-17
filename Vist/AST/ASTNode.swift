//
//  ASTNode.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol ASTNode : Printable {}

// use behaviour delegates (when released in swift 3) to make `let (delated) type: Ty { get }`
///
/// AST walker node
///
/// Provides common interfaces for expressions, declarations, and statements
///
final class AST : ASTNode, ScopeNode {
    var exprs: [ASTNode]
    
    init(exprs: [ASTNode]) {
        self.exprs = exprs
    }
    
    var type: Ty? = nil
    
    var childNodes: [ASTNode] {
        return exprs
    }
}

/// Type erased `Typed` protocol
///
/// Conformants have a `_type` member which is an existential type
///
protocol _Typed {
    var _type: Ty? { get set }
}

extension _Typed {
    var typeName: String {
        return _type?.mangledName ?? "<invalid>"
    }
}

/// Typed protocol which defines a generic type
///
protocol Typed : _Typed {
    typealias Type: Ty
    var type: Type? { get set }
}

// extending `Typed` to conform to `_Typed`
extension Typed {
    
    /// This property gets from and sets to the specifically typed `type` property
    /// 
    /// It should only be used by API, use the `type` property instead
    ///
    @available(*, unavailable, message="Use the `type` property")
    var _type: Ty? {
        get {
            return type as? Ty
        }
        set {
            if case let t as Type = newValue {
                type = t
            }
            else {
                if newValue == nil { fatalError("new value nil") }
                fatalError("associated type requirement specifies `\(Type.self)` type. provided value was `\(newValue.dynamicType)`")
            }
        }
    }
}

