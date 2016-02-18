//
//  StmtSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



extension ReturnStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // set the AST context to `scope.returnType`
        let retScope = SemaScope(parent: scope, semaContext: scope.returnType)
        let returnType = try expr.typeForNode(retScope)
        
        guard let ret = scope.returnType where ret == returnType else {
            throw error(SemaError.WrongFunctionReturnType(applied: returnType, expected: scope.returnType ?? BuiltinType.Null))
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension ConditionalStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // call on child `ElseIfBlockExpressions`
        for statement in statements {
            // inner scopes
            let ifScope = SemaScope(parent: scope, returnType: scope.returnType)
            try statement.typeForNode(ifScope)
        }
    }
}


extension ElseIfBlockStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // get condition type
        let c = try condition?.typeForNode(scope)
        
        // gen types for cond block
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(scope)
        }

        // if no condition we're done
        if condition == nil { return }
        
        // otherwise make sure its a Bool
        guard let condition = c where condition == StdLib.BoolType else { throw error(SemaError.NonBooleanCondition) }
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Loops
//-------------------------------------------------------------------------------------------------------------------------


extension ForInLoopStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // add bound name to scopes
        loopScope[variable: binded.name] = (type: StdLib.IntType, mutable: false)
        
        // gen types for iterator
        guard try iterator.typeForNode(scope) == StdLib.RangeType else { throw error(SemaError.NotRangeType) }
        
        // parse inside of loop in loop scope
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(loopScope)
        }
    }
    
}


extension WhileLoopStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // gen types for iterator
        guard try condition.typeForNode(scope) == StdLib.BoolType else { throw error(SemaError.NonBooleanCondition) }
        
        // parse inside of loop in loop scope
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(loopScope)
        }
    }
}

