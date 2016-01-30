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
final class AST : ASTNode {
    var exprs: [ASTNode]
    
    init(exprs: [ASTNode]) {
        self.exprs = exprs
    }
    
    var type: Ty? = nil
}

// TODO: Notes from swift:
//
// they have different types -
//
//  - Pattern, as in pattern matching
//      - `is` pattern, tuple pattern, enum element pattern, case statement 'bool' patterns, x?
//  - Declarations / Decl
//      - Vars, funcs, types, and initalisers
//  - Statement / Stmt
//      - brace, return, defer, conditional, do/catch, if, while, for, for each, switch, break, fallthrough, continue, throw
//  - Expression / expr
//      - literals, tuples, parens, array, closure
//      - Call expression, operator, methods, casts,
//      - Sub expressions of syntax structures, like `type name generic params`
//  - TypeRepr & SourceLoc
//      - ‘Representation of a type as written in source’, generates human readable code to attach to AST objects
//      - Source code location information
//
// Swift has an explicit AST walker function


protocol _Typed {
    var _type: Ty? { get set }
}

protocol Typed : _Typed {
    typealias Type: Ty
    var type: Type? { get set }
}

extension Typed {
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
