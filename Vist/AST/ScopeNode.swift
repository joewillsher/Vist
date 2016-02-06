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
        
        var errors: [VistError] = []
        
        for exp in childNodes {
            do {
                try fn(exp)
            }
            catch let error where error is VistError {
                errors.append(error as! VistError)
            }
        }
        
        try errors.throwIfErrors()
        
    }
}

extension CollectionType where Generator.Element == ASTNode {
    
    func walkChildren<Ret>(fn: (ASTNode) throws -> Ret) throws {
        
        var errors: [VistError] = []
        
        for exp in self {
            do {
                try fn(exp)
            }
            catch let error where error is VistError {
                errors.append(error as! VistError)
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
