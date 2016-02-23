//
//  DefinedType.swift
//  Vist
//
//  Created by Josef Willsher on 06/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class FunctionType {
    let paramType: DefinedType
    let returnType: DefinedType
    
    init(paramType: DefinedType, returnType: DefinedType) {
        self.paramType = paramType
        self.returnType = returnType
    }
    
    var type: FnType? = nil
}


enum DefinedType {
    case void
    case type(String)
    indirect case tuple([DefinedType])
    case function(FunctionType)
    
    init(_ str: String) {
        self = .type(str)
    }
    
    init(_ strs: [String]) {
        switch strs.count {
        case 0: self = .void
        case 1: self = .type(strs[0])
        case _: self = .tuple(strs.map(DefinedType.init))
        }
    }
    
    private func tyArr(scope: SemaScope) throws -> [Ty] {
        switch self {
        case .void:             return []
        case .type, .function:  return [try typeInScope(scope)]
        case .tuple(let ts):    return try ts.flatMap { try $0.typeInScope(scope) }
        }
    }
    
    func typeNames() -> [String] {
        switch self {
        case .void, .function:  return []
        case let .type(t):      return [t]
        case let .tuple(ts):    return ts.flatMap { $0.typeNames() }
        }
    }
    
    
    
    func typeInScope(scope: SemaScope) throws -> Ty {
        switch self {
        case .void:
            return BuiltinType.void
            
        case let .type(typeName):
            
            if let builtin = BuiltinType(typeName) {
                return builtin as Ty
            }
            else if let i = scope[type: typeName] {
                return i
            }
            else {
                throw semaError(.noTypeNamed(typeName))
            }
            
        case let .tuple(elements):
            return elements.isEmpty ? BuiltinType.void : TupleType(members: try elements.map({try $0.typeInScope(scope)}))
            
        case let .function(functionType):
            return FnType(params: try functionType.paramType.tyArr(scope), returns: try functionType.returnType.typeInScope(scope))
        }
    }
}



extension FunctionType {
    
    func params(scope: SemaScope) throws -> [Ty] {
        return try paramType.tyArr(scope)
    }
    
    func returnType(scope: SemaScope) throws -> Ty {
        return try returnType.typeInScope(scope)
    }
}





