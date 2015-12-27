//
//  TypeProvider.swift
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
        
        // lookup variable type in scope
        guard let v = vars[name] else { throw SemaError.NoVariable(name) }
        
        // assign type to self and return
        self.type = v
        return v
    }
}

extension BinaryExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // FIXME: this is kinda a hack: these should be stdlib implementations -- operators should be user definable and looked up from the vars scope like functions
        switch op {
        case "<", ">", "==", "!=", ">=", "<=":
            try lhs.llvmType(vars, fns: fns)
            try rhs.llvmType(vars, fns: fns)
            self.type = .Bool
            return LLVMType.Bool
            
        default:
            let a = try lhs.llvmType(vars, fns: fns)
            let b = try rhs.llvmType(vars, fns: fns)
            
            // if same object
            if (try a.ir()) == (try b.ir()) {
                // assign type to self and return
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
        
        // gen types for objects in call
        for arg in args.elements {
            try arg.llvmType(vars, fns: fns)
        }
        // get from table
        guard let fn = fns[name] else { throw SemaError.NoFunction(name) }
        
        // assign type to self and return
        self.type = fn.returns
        return fn.returns
    }
}



extension ArrayExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // element types
        var types: [LLVMType] = []
        for i in 0..<arr.count {
            let el = arr[i]
            let t = try el.llvmType(vars, fns: fns)
            types.append(t)
        }
        
        // make sure array is homogeneous
        guard Set(try types.map { try $0.ir() }).count == 1 else { throw SemaError.HeterogenousArray(self.description()) }
        
        // get element type and assign to self
        guard let elementType = types.first else { throw SemaError.EmptyArray }
        self.elType = elementType
        
        // assign array type to self and return
        let t = LLVMType.Array(el: elementType, size: UInt32(arr.count))
        self.type = t
        return t
    }
    
}

extension ArraySubscriptExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // get array variable
        guard let name = (arr as? Variable<AnyExpression>)?.name else { throw SemaError.NotVariableType }
        
        // make sure its an array
        guard case .Array(let type, _)? = vars[name] else { throw SemaError.CannotSubscriptNonArrayVariable }
        
        // gen type for subscripting value
        try index.llvmType(vars, fns: fns)
        
        // assign type to self and return
        self.type = type
        return type
    }
    
}

extension ReturnExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        try expression.llvmType(vars, fns: fns)
        
        self.type = .Null
        return .Null
    }
    
}

extension RangeIteratorExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // gen types for start and end
        let s = try start.llvmType(vars, fns: fns)
        let e = try end.llvmType(vars, fns: fns)
        
        // make sure range has same start and end types
        guard try e.ir() == s.ir() else { throw SemaError.RangeWithInconsistentTypes }
        
        self.type = .Null
        return .Null
    }
    
}

extension ForInLoopExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // scopes for inner loop
        let loopVarScope = SemaScope<LLVMType>(parent: vars)
        let loopFnScope = SemaScope<LLVMFnType>(parent: fns)
        
        // add bound name to scopes
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
        
        // scopes for inner loop
        let loopVarScope = SemaScope<LLVMType>(parent: vars)
        let loopFnScope = SemaScope<LLVMFnType>(parent: fns)
        
        // gen types for iterator
        let it = try iterator.llvmType(vars, fns: fns)
        guard try it.ir() == LLVMInt1Type() else { throw SemaError.NonBooleanCondition }
        
        // parse inside of loop in loop scope
        try semaVariableSpecialisation(&block, v: loopVarScope, f: loopFnScope)
        
        type = .Null
        return .Null
    }
}
extension WhileIteratorExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // make condition variable and make sure bool
        let t = try condition.llvmType(vars, fns: fns)
        guard try t.ir() == LLVMInt1Type() else { throw SemaError.NonBooleanCondition }
        
        type = .Bool
        return .Bool
    }
}


extension ConditionalExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // call on child `ElseIfBlockExpressions`
        for statement in statements {
            // inner scopes
            let ifVarScope = SemaScope<LLVMType>(parent: vars)
            let ifFnScope = SemaScope<LLVMFnType>(parent: fns)
            
            try statement.llvmType(ifVarScope, fns: ifFnScope)
        }
        
        type = .Null
        return .Null
    }
}

extension ElseIfBlockExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // get condition type
        let cond = try condition?.llvmType(vars, fns: fns)
        guard try cond?.ir() == LLVMInt1Type() else { throw SemaError.NonBooleanCondition }
        
        // gen types for cond block
        try semaVariableSpecialisation(&block, v: vars, f: fns)
        
        self.type = .Null
        return .Null
    }
    
}

extension MutationExpression : TypeProvider {
    
    func llvmType(vars: SemaScope<LLVMType>, fns: SemaScope<LLVMFnType>) throws -> LLVMType {
        
        // gen types for variable and value
        let old = try object.llvmType(vars, fns: fns)
        let new = try value.llvmType(vars, fns: fns)
        guard try old.ir() == new.ir() else { throw SemaError.DifferentTypeForMutation }
        
        return .Null
    }
}

