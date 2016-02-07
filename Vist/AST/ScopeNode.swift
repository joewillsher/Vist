//
//  ScopeNode.swift
//  Vist
//
//  Created by Josef Willsher on 06/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// AST nodes which have children
///
/// for example blocks, the global scope, structs
///
protocol ScopeNode {
    var childNodes: [ASTNode] { get }
}

extension ScopeNode {
    
    func walkChildren<Ret>(fn: (ASTNode) throws -> Ret) throws {
        try childNodes.walkChildren(fn)
    }
}

extension CollectionType where Generator.Element : ASTNode {
    
    /// Maps the input function over the children, which are types conforming to ASTNode
    ///
    /// Catches errors and continues walking the tree, throwing them all at
    /// in an ErrorCollection at the end
    ///
    /// ```
    /// try initialisers.walkChildren { i in
    ///     try i.codeGen(stackFrame)
    /// }
    /// ```
    ///
    func walkChildren<Ret>(fn: (Generator.Element) throws -> Ret) throws {
        
        var errors: [VistError] = []
        
        for exp in self {
            do {
                try fn(exp)
            }
            catch let error as VistError {
                errors.append(error)
            }
        }
        
        try errors.throwIfErrors()
    }
}

extension CollectionType where Generator.Element == ASTNode {
    
    /// Maps the input function over the ASTNode children
    ///
    /// Catches errors and continues walking the tree, throwing them all at 
    /// in an ErrorCollection at the end
    ///
    /// ```
    /// try block.exprs.walkChildren { exp in
    ///     try exp.nodeCodeGen(stackFrame)
    /// }
    /// ```
    ///
    func walkChildren<Ret>(fn: (ASTNode) throws -> Ret) throws {
        
        var errors: [VistError] = []
        
        for exp in self {
            do {
                try fn(exp)
            }
            catch let error as VistError {
                errors.append(error)
            }
        }
        
        try errors.throwIfErrors()
    }
}

extension CollectionType where Generator.Element : ASTNode {
    
    /// flatMaps `$0 as? T` over the collection
    func mapAs<T>(_: T.Type) -> [T] {
        return flatMap { $0 as? T }
    }
}
