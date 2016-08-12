//
//  Decl.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// - Declaration / Decl

protocol Decl : ASTNode, DeclTypeProvider, StmtEmitter { }

typealias ConstrainedType = (name: String, constraints: [String], parentName: String)


protocol TypeMemberVariableDecl : class, Decl {
    weak var parent: NominalTypeDecl? { get set }
    var declared: [VariableDecl] { get }
}

protocol NominalTypeDecl : class, Decl {
    var name: String { get }
    var declaredType: NominalType? { get }
}

final class TypeDecl: ScopeNode, NominalTypeDecl, LibraryTopLevel {
    let name: String
    let properties: [TypeMemberVariableDecl]
    var methods: [FuncDecl], initialisers: [InitDecl]
    let attrs: [AttributeExpr]
    let byRef: Bool
    
    let genericParameters: [ConstrainedType]?
    let concepts: [String]
    
    init(name: String,
         attrs: [AttributeExpr],
         properties: [TypeMemberVariableDecl],
         methods: [FuncDecl],
         initialisers: [InitDecl],
         genericParameters: [ConstrainedType]?,
         concepts: [String],
         byRef: Bool) {
        self.name = name
        self.properties = properties
        self.methods = methods
        self.initialisers = initialisers
        self.attrs = attrs
        self.genericParameters = genericParameters
        self.byRef = byRef
        self.concepts = concepts
    }
    
    var type: StructType? = nil
    var declaredType: NominalType? { return type as? NominalType }
    
    var childNodes: [ASTNode] {
        return properties.map { $0 as ASTNode }
            + methods as [ASTNode]
            + initialisers as [ASTNode]
    }
}

final class ConceptDecl : TypedExpr, ScopeNode, NominalTypeDecl, LibraryTopLevel {
    let name: String
    let requiredProperties: [TypeMemberVariableDecl]
    let requiredMethods: [FuncDecl]
    
    init(name: String, requiredProperties: [TypeMemberVariableDecl], requiredMethods: [FuncDecl]) {
        self.name = name
        self.requiredProperties = requiredProperties
        self.requiredMethods = requiredMethods
    }
    
    var type: ConceptType? = nil
    var declaredType: NominalType? { return type as? NominalType }
    
    var childNodes: [ASTNode] {
        return requiredProperties.flatMap{$0.declared} as [ASTNode]
             + requiredMethods as [ASTNode]
    }
}

final class VariableDecl : Decl, TypeMemberVariableDecl {
    let name: String
    let typeRepr: TypeRepr?
    let isMutable: Bool
    var value: Expr
    
    init(name: String, typeRepr: TypeRepr?, isMutable: Bool, value: Expr) {
        self.name = name
        self.typeRepr = typeRepr
        self.isMutable = isMutable
        self.value = value
    }
    
    /// `self` if the function is a type member decl
    var parent: NominalTypeDecl? = nil
    
    var declared: [VariableDecl] { return [self] }
}

final class VariableGroupDecl : Decl, TypeMemberVariableDecl {
    var declared: [VariableDecl]
    
    init(declared: [VariableDecl]) {
        self.declared = declared
    }
    
    /// `self` if the function is a type member decl
    weak var parent: NominalTypeDecl? = nil {
        willSet(parent) {
            for child in declared {
                child.parent = parent
            }
        }
    }
}

final class FuncDecl : Decl, LibraryTopLevel {
    let name: String
    let typeRepr: FunctionTypeRepr
    let impl: FunctionBodyExpr?
    let attrs: [FunctionAttributeExpr]
    let genericParameters: [ConstrainedType]?
    
    init(name: String,
         typeRepr: FunctionTypeRepr,
         impl: FunctionBodyExpr?,
         attrs: [FunctionAttributeExpr],
         genericParameters: [ConstrainedType]?) {
        self.name = name
        self.typeRepr = typeRepr
        self.impl = impl
        self.attrs = attrs
        self.genericParameters = genericParameters
    }
    
    /// Is the funtion a generator
    var isGeneratorFunction: Bool {
        // its a method called 'generate' with no params & a non void return type
        return name == "generate" &&
            (parent != nil) &&
            typeRepr.paramType.typeNames().isEmpty &&
            !typeRepr.returnType.isVoid
    }
    
    var mangledName: String?
    
    var hasBody: Bool { return impl != nil }
    
    /// `self` if the function is a member function
    weak var parent: NominalTypeDecl? = nil
}


final class FunctionBodyExpr : Expr {
    var params: [String]
    let body: BlockExpr
    
    init(params: [String], body: BlockExpr) {
        self.params = params
        self.body = body
    }
    
    var _type: Type? = nil
}

final class InitDecl : Decl {
    let typeRepr: FunctionTypeRepr
    let impl: FunctionBodyExpr?
    let isImplicit: Bool
    
    init(ty: FunctionTypeRepr,
         impl: FunctionBodyExpr?,
         parent: NominalTypeDecl?,
         isImplicit: Bool) {
        self.typeRepr = ty
        self.impl = impl
        self.parent = parent
        self.isImplicit = isImplicit
    }
    
    var mangledName: String?
    
    weak var parent: NominalTypeDecl? = nil
}


