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
    case Void
    case Type(String)
    indirect case Tuple([DefinedType])
    case Function(FunctionType)
    
    init(_ str: String) {
        self = .Type(str)
    }
    
    init(_ strs: [String]) {
        switch strs.count {
        case 0: self = .Void
        case 1: self = .Type(strs[0])
        case _: self = .Tuple(strs.map(DefinedType.init))
        }
    }
    
    private func tyArr(scope: SemaScope? = nil) throws -> [Ty] {
        switch self {
        case .Void:             return []
        case .Type, .Function:  return [try type(scope)]
        case let .Tuple(ts):    return try ts.flatMap { try $0.type(scope) }
        }
    }
    
    func typeNames() -> [String] {
        switch self {
        case .Void, .Function:  return []
        case let .Type(t):      return [t]
        case let .Tuple(ts):    return ts.flatMap { $0.typeNames() }
        }
    }

    
    
    func type(scope: SemaScope? = nil) throws -> Ty {
        switch self {
        case .Void:
            return BuiltinType.Void
            
        case let .Type(name):
            
            if let builtin = BuiltinType(name) {
                return builtin as Ty
            }
            else if let std = StdLib.getStdLibType(name) {
                return std
            }
            else if let i = scope?[type: name] {
                return i
            }
            throw error(SemaError.NoTypeNamed(name))
            
        case let .Tuple(elements):
            return TupleType(members: try elements.map({try $0.type(scope)}))
            
        case let .Function(functionType):
            return FnType(params: try functionType.paramType.tyArr(scope), returns: try functionType.returnType.type(scope))
        }
    }
}



extension FunctionType {
    
    func params(scope: SemaScope) throws -> [Ty] {
        return try paramType.tyArr(scope)
    }
    
    func returnType(scope: SemaScope) throws -> Ty {
        return try returnType.type(scope)
    }
}





