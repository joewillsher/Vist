//
//  TypeProvider.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol ExprTypeProvider {
    func llvmType(scope: SemaScope) throws -> Ty
}

protocol StmtTypeProvider {
    func llvmType(scope: SemaScope) throws
}
protocol DeclTypeProvider {
    func llvmType(scope: SemaScope) throws
}

// TODO: make private
extension ExprTypeProvider {
    func llvmType(scope: SemaScope) throws -> Ty {
        return BuiltinType.Null
    }
}

extension ASTNode {
    func llvmType(scope: SemaScope) throws {
        if case let expr as ExprTypeProvider = self {
            try expr.llvmType(scope)
        }
        else if case let stmt as StmtTypeProvider = self {
            try stmt.llvmType(scope)
        }
        else if case let stmt as DeclTypeProvider = self {
            try stmt.llvmType(scope)
        }
    }
}



extension CollectionType where Index == Int {
    
    /// An impl of flatmap which flatmaps but throws if the size changes
    @warn_unused_result
    public func stableOptionalMap<T>(@noescape transform: (Self.Generator.Element) throws -> T?) rethrows -> [T]? {
        let new = try flatMap(transform)
        if new.count == count { return new } else { return nil }
    }
    
}


