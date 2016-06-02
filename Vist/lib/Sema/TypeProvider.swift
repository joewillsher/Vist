//
//  TypeProvider.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol ExprTypeProvider {
    func typeForNode(scope: SemaScope) throws -> Type
}

protocol StmtTypeProvider {
    func typeForNode(scope: SemaScope) throws
}
protocol DeclTypeProvider {
    func typeForNode(scope: SemaScope) throws
}

// TODO: make private
extension ExprTypeProvider {
    func typeForNode(scope: SemaScope) throws -> Type {
        return BuiltinType.null
    }
}

extension ASTNode {
    func typeForNode(scope: SemaScope) throws {
        if case let expr as ExprTypeProvider = self {
            _ = try expr.typeForNode(scope: scope)
        }
        else if case let stmt as StmtTypeProvider = self {
            _ = try stmt.typeForNode(scope: scope)
        }
        else if case let stmt as DeclTypeProvider = self {
            _ = try stmt.typeForNode(scope: scope)
        }
    }
}



extension Collection where IndexDistance == Int {
    
    /// An impl of flatmap which flatmaps but returns nil if the size changes
    func optionalMap<T>(transform: @noescape (Generator.Element) throws -> T?) rethrows -> [T]? {
        let new = try flatMap(transform)
        if new.count == count { return new } else { return nil }
    }
}
