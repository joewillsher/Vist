//
//  DefinedType.swift
//  Vist
//
//  Created by Josef Willsher on 06/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class FunctionType {
    let args: DefinedType
    let returns: DefinedType
    
    init(args: DefinedType, returns: DefinedType) {
        self.args = args
        self.returns = returns
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
    
    var count: Int {
        switch self {
        case .Void: return 0
        case .Type, Function: return 1
        case let .Tuple(tys): return tys.count
        }
    }
    
    
    private func tyArr() throws -> [Ty] {
        switch self {
        case .Void:             return []
        case .Type, .Function:  return [try type()]
        case let .Tuple(ts):    return try ts.flatMap { try $0.type() }
        }
    }
    
    func arr() -> [String] {
        switch self {
        case .Void, .Function:  return []
        case let .Type(t):      return [t]
        case let .Tuple(ts):    return ts.flatMap { $0.arr() }
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
            let types = try elements.map({try $0.type()})
            return TupleType(members: types)
            
        case let .Function(f):
            return FnType(params: try f.args.tyArr(), returns: try f.returns.type())
        }
    }
}



extension FunctionType {
    
    func params(scope: SemaScope)
        throws -> [Ty] {
            return try args.tyArr()
    }
    
    func returnType(scope: SemaScope)
        throws -> Ty {
            
            return try returns.type()
    }
}





