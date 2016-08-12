//
//  TypeRepr.swift
//  Vist
//
//  Created by Josef Willsher on 06/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Like TypeRepr but represents a function type
final class FunctionTypeRepr {
    let paramType: TypeRepr
    let returnType: TypeRepr
    
    init(paramType: TypeRepr, returnType: TypeRepr) {
        self.paramType = paramType
        self.returnType = returnType
    }
    
    var type: FunctionType? = nil
    
    func params(scope: SemaScope) throws -> [Type] {
        return try paramType.tyArr(scope: scope)
    }
    
    func returnType(scope: SemaScope) throws -> Type {
        return try returnType.typeIn(scope)
    }
}


/// The pre-type checked AST type. Exposes methods to calculate
/// simple VIR types (used in Sema) for the nodes of the AST
enum TypeRepr {
    case void
    case type(String)
    case tuple([TypeRepr])
    case function(FunctionTypeRepr)
    
    init(_ str: String) {
        self = .type(str)
    }
    
    init(_ strs: [String]) {
        switch strs.count {
        case 0: self = .void
        case 1: self = .type(strs[0])
        case _: self = .tuple(strs.map(TypeRepr.init))
        }
    }
    
    func typeIn(_ scope: SemaScope) throws -> Type {
        switch self {
        case .void:
            return BuiltinType.void
            
        case let .type(typeName):
            
            if let builtin = BuiltinType(typeName) {
                return builtin
            }
            else if let i = scope.type(named: typeName) {
                return i
            }
            else {
                throw semaError(.noTypeNamed(typeName))
            }
            
        case .tuple(let elements):
            return elements.isEmpty ?
                BuiltinType.void :
                TupleType(members: try elements.map({try $0.typeIn(scope)}))
            
        case .function(let functionType):
            return FunctionType(params: try functionType.paramType.tyArr(scope: scope),
                                returns: try functionType.returnType.typeIn(scope))
        }
    }
    
    fileprivate func tyArr(scope: SemaScope) throws -> [Type] {
        switch self {
        case .void:             return []
        case .type, .function:  return [try typeIn(scope)]
        case .tuple(let ts):    return try ts.flatMap { try $0.typeIn(scope) }
        }
    }
    
    func typeNames() -> [String] {
        switch self {
        case .void, .function:  return []
        case let .type(t):      return [t]
        case let .tuple(ts):    return ts.flatMap { $0.typeNames() }
        }
    }
    
    var isVoid: Bool { if case .void = self { return true } else { return false } }
}

