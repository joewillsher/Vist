//
//  TypeProvider.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol ExprTypeProvider {
    func typeForNode(scope: SemaScope) throws -> Ty
}

protocol StmtTypeProvider {
    func typeForNode(scope: SemaScope) throws
}
protocol DeclTypeProvider {
    func typeForNode(scope: SemaScope) throws
}

// TODO: make private
extension ExprTypeProvider {
    func typeForNode(scope: SemaScope) throws -> Ty {
        return BuiltinType.Null
    }
}

extension ASTNode {
    func typeForNode(scope: SemaScope) throws {
        if case let expr as ExprTypeProvider = self {
            try expr.typeForNode(scope)
        }
        else if case let stmt as StmtTypeProvider = self {
            try stmt.typeForNode(scope)
        }
        else if case let stmt as DeclTypeProvider = self {
            try stmt.typeForNode(scope)
        }
    }
}



extension CollectionType where Index == Int {
    
    /// An impl of flatmap which flatmaps but returns nil if the size changes
    @warn_unused_result
    public func optionalMap<T>(@noescape transform: (Self.Generator.Element) throws -> T?) rethrows -> [T]? {
        let new = try flatMap(transform)
        if new.count == count { return new } else { return nil }
    }
    
}


