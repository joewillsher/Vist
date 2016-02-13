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
    
    private func tyArr(scope: SemaScope) throws -> [Ty] {
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
    
    
    
    func type(scope: SemaScope) throws -> Ty {
        switch self {
        case .Void:
            return BuiltinType.Void
            
        case let .Type(typeName):
            
            if let builtin = BuiltinType(typeName) {
                return builtin as Ty
            }
//            else if let std = StdLib.getStdLibType(name) {
//                return std
//            }
            else if let i = scope[type: typeName] {
                return i
            }
            else if let g = scope.genericParameters, let i = g.indexOf({$0.type == typeName}) {
                
                let type = g[i]
                guard let concepts = type.constraints.optionalMap({ scope[concept: $0] }) else { throw error(SemaError.GenericSubstitutionInvalid) }
                
                return GenericType(name: type.0, concepts: concepts)
            }
            else if let existential = scope[concept: typeName] {
                return existential
            }
            else {
                print(typeName)
                throw error(SemaError.NoTypeNamed(typeName))
            }
            
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





