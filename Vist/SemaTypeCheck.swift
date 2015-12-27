//
//  SemaTypeCheck.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

import Foundation


protocol TypeProvider {
    /// Function used to traverse AST and get type information for all its objects
    ///
    /// Each implementation of this function should **call `.llvmType` on all of its sub expressions**
    ///
    /// The function implementation **should assign the result type to self** as well as returning it
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType
}

extension TypeProvider {
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        return .Null
    }
}


extension IntegerLiteral : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        self.type = .Int(size: size)
        return type!
    }
}

extension FloatingPointLiteral : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        self.type = .Float(size: size)
        return .Float(size: size)
    }
}

extension BooleanLiteral : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        self.type = .Bool
        return LLVMType.Bool
    }
}

extension Variable : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        guard let v = vars[name] else { throw SemaError.NoVariable(name) }
        self.type = v
        return v
    }
}

extension BinaryExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        switch op {
        case "<", ">", "==", "!=", ">=", "<=":
            try lhs.llvmType(vars, fns: fns)
            try rhs.llvmType(vars, fns: fns)
            self.type = .Bool
            return LLVMType.Bool
            
        default:
            let a = try lhs.llvmType(vars, fns: fns)
            let b = try rhs.llvmType(vars, fns: fns)
            
            if (try a.ir()) == (try b.ir()) {
                self.type = a
                return a
            } else { throw IRError.MisMatchedTypes }
        }
        

    }
}

extension Void : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        self.type = .Void
        return .Void
    }
}

extension FunctionCallExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        for arg in args.elements {
            try arg.llvmType(vars, fns: fns)
        }
        guard let fn = fns[name] else { throw SemaError.NoFunction(name) }
        
        self.type = fn.returns
        return fn.returns
    }
}



extension ArrayExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // element type
        var types: [LLVMType] = []
        for i in 0..<arr.count {
            let el = arr[i]
            let t = try el.llvmType(vars, fns: fns)
            types.append(t)
        }
        guard Set(try types.map { try $0.ir() }).count == 1 else { throw SemaError.HeterogenousArray(self.description()) }
        
        guard let elementType = types.first else { throw SemaError.EmptyArray }
        
        let t = LLVMType.Array(el: elementType, size: UInt32(arr.count))
        self.type = t
        self.elType = elementType
        return t
    }
    
}

extension ArraySubscriptExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        guard let name = (arr as? Variable<AnyExpression>)?.name else { throw SemaError.NotVariableType }
        
        guard case .Array(let type, _)? = vars[name] else { throw SemaError.CannotSubscriptNonArrayVariable }
        
        // gen type for subscripting value
        try index.llvmType(vars, fns: fns)
        
        let t = type
        self.type = t
        return t        
    }
    
}

extension ReturnExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        _ = try expression.llvmType(vars, fns: fns)

        self.type = .Null
        return .Null
    }
    
}

extension RangeIteratorExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        try start.llvmType(vars, fns: fns)
        try end.llvmType(vars, fns: fns)
        
        self.type = .Null
        return .Null
    }
    
}

extension ForInLoopExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        let loopVarScope = SemaScope<LLVMType>(parent: vars)
        let loopFnScope = SemaScope<LLVMFnType>(parent: fns)
        
        loopVarScope[binded.name] = .Int(size: 64)
        
        // gen types for iterator
        try iterator.llvmType(vars, fns: fns)
        
        
        // parse inside of loop in loop scope
        try semaVariableSpecialisation(&block, v: loopVarScope, f: loopFnScope)
        
        return .Null
    }
    
}

extension WhileLoopExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        let loopVarScope = SemaScope<LLVMType>(parent: vars)
        let loopFnScope = SemaScope<LLVMFnType>(parent: fns)
        
        // gen types for iterator
        try iterator.llvmType(vars, fns: fns)
        
        // parse inside of loop in loop scope
        try block.llvmType(vars, fns: fns)
        
        return .Null
    }
}
extension WhileIteratorExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        let t = try condition.llvmType(vars, fns: fns)
        guard try t.ir() == LLVMInt1Type() else { throw SemaError.NonBooleanCondition }
        type = .Bool
        return .Bool
    }
}


extension ConditionalExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        for statement in statements {
            try statement.llvmType(vars, fns: fns)
        }
        
        return .Null
    }
}

extension ElseIfBlockExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        let cond = try condition?.llvmType(vars, fns: fns)
        condition?.type = cond
        
        try semaVariableSpecialisation(&block, v: vars, f: fns)
        
        self.type = .Null
        return .Null
    }
    
}

extension MutationExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        try object.llvmType(vars, fns: fns)
        try value.llvmType(vars, fns: fns)
        
        return .Null
    }
}



