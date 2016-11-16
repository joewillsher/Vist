//
//  TypeProvider.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol ExprTypeProvider {
    @discardableResult func typeCheckNode(scope: SemaScope) throws -> Type
}

protocol StmtTypeProvider {
    func typeCheckNode(scope: SemaScope) throws
}
protocol DeclTypeProvider {
    func typeCheckNode(scope: SemaScope) throws
}

// TODO: make private
extension ExprTypeProvider {
    func typeCheckNode(scope: SemaScope) throws -> Type {
        return BuiltinType.null
    }
}

extension ASTNode {
    func typeCheckNode(scope: SemaScope) throws {
        if case let expr as ExprTypeProvider = self {
            try expr.typeCheckNode(scope: scope)
        }
        else if case let stmt as StmtTypeProvider = self {
            try stmt.typeCheckNode(scope: scope)
        }
        else if case let stmt as DeclTypeProvider = self {
            try stmt.typeCheckNode(scope: scope)
        }
    }
}

extension AST {
    
    private func semaDecls(scope: SemaScope) {
        // TODO: Sema walks the root scope of the tree
        //       - it picks up type/function/concept decls
        //       - only recurses to their child decls, doesn't
        //         type check function bodies etc
        //       - this step resolves types and populates the
        //         global scope
        //       - so we get forward declaration behaviour and
        //         multithreaded sema can resolve types declared
        //         at different roots in the AST
    }
    
    func sema(globalScope: SemaScope) throws {
        
        let globalCollector = AsyncErrorCollector()
        try walkChildrenAsync(collector: globalCollector) { node in
            try node.typeCheckNode(scope: globalScope)
        }
        globalCollector.group.wait()
        try globalCollector.throwIfErrors()
    }
}



extension Collection where IndexDistance == Int {
    
    /// An impl of flatmap which flatmaps but returns nil if the size changes
    func optionalMap<T>(_ transform: (Generator.Element) throws -> T?) rethrows -> [T]? {
        let new = try flatMap(transform)
        if new.count == count { return new } else { return nil }
    }
}
