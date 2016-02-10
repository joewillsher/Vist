//
//  Decl.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// - Declaration / Decl
protocol Decl : ASTNode, DeclTypeProvider {}


final class VariableDecl : Decl, StructMemberExpr {
    let name: String
    let aType: DefinedType?
    let isMutable: Bool
    var value: Expr
    
    init(name: String, type: DefinedType?, isMutable: Bool, value: Expr) {
        self.name = name
        self.aType = type
        self.isMutable = isMutable
        self.value = value
    }
}

final class FuncDecl : Decl, StructMemberExpr {
    let name: String
    let fnType: FunctionType
    let impl: FunctionImplementationExpr?
    let attrs: [FunctionAttributeExpr]
    let genericParameters: [ConstrainedType]
    
    init(name: String, type: FunctionType, impl: FunctionImplementationExpr?, attrs: [FunctionAttributeExpr], genericParameters: [ConstrainedType]) {
        self.name = name
        self.fnType = type
        self.impl = impl
        self.mangledName = name
        self.attrs = attrs
        self.genericParameters = genericParameters
    }
    
    var mangledName: String
    
    /// `self` if the function is a member function
    weak var parent: StructExpr? = nil
}



final class InitialiserDecl : Decl, StructMemberExpr {
    let ty: FunctionType
    let impl: FunctionImplementationExpr?
    weak var parent: StructExpr?
    
    init(ty: FunctionType, impl: FunctionImplementationExpr?, parent: StructExpr?) {
        self.ty = ty
        self.impl = impl
        self.parent = parent
        self.mangledName = ""
    }
    
    var mangledName: String
}
