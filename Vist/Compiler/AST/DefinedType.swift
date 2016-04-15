//
//  DefinedType.swift
//  Vist
//
//  Created by Josef Willsher on 06/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class DefinedFunctionType {
    let paramType: DefinedType
    let returnType: DefinedType
    
    init(paramType: DefinedType, returnType: DefinedType) {
        self.paramType = paramType
        self.returnType = returnType
    }
    
    var type: FunctionType? = nil
}


enum DefinedType {
    case void
    case type(String)
    indirect case tuple([DefinedType])
    case function(DefinedFunctionType)
    
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
    
    private func tyArr(scope: SemaScope) throws -> [Type] {
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
    
    var isVoid: Bool { if case .void = self { return true } else { return false } }
    
    func typeInScope(scope: SemaScope) throws -> Type {
        switch self {
        case .void:
            return BuiltinType.void
            
        case let .type(typeName):
            
            if let builtin = BuiltinType(typeName) {
                return builtin as Type
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
            return FunctionType(params: try functionType.paramType.tyArr(scope), returns: try functionType.returnType.typeInScope(scope))
        }
    }
}



extension DefinedFunctionType {
    
    func params(scope: SemaScope) throws -> [Type] {
        return try paramType.tyArr(scope)
    }
    
    func returnType(scope: SemaScope) throws -> Type {
        return try returnType.typeInScope(scope)
    }
}





