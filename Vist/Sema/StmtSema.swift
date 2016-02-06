//
//  StmtSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//



extension ReturnStmt : StmtTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        
        // set the AST context to `scope.returnType`
        let retScope = SemaScope(parent: scope, semaContext: scope.returnType)
        let returnType = try expr.llvmType(retScope)
        
        guard let ret = scope.returnType where ret == returnType else {
            throw error(SemaError.WrongFunctionReturnType(applied: returnType, expected: scope.returnType ?? BuiltinType.Null))
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension ConditionalStmt : StmtTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        
        // call on child `ElseIfBlockExpressions`
        for statement in statements {
            // inner scopes
            let ifScope = SemaScope(parent: scope, returnType: scope.returnType)
            
            try statement.llvmType(ifScope)
        }
    }
}


extension ElseIfBlockStmt : StmtTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        
        // get condition type
        let c = try condition?.llvmType(scope)
        
        // gen types for cond block
        for exp in block.exprs {
            try exp.llvmType(scope)
        }

        // if no condition we're done
        if condition == nil { return }
        
        // otherwise make sure its an Int
        guard let condition = c where condition == StdLib.BoolType else { throw error(SemaError.NonBooleanCondition) }
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Loops
//-------------------------------------------------------------------------------------------------------------------------


extension ForInLoopStmt : StmtTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // add bound name to scopes
        loopScope[variable: binded.name] = (type: StdLib.IntType, mutable: false)
        
        // gen types for iterator
        guard try iterator.llvmType(scope) == StdLib.RangeType else { throw error(SemaError.NotRangeType) }
        
        // parse inside of loop in loop scope
        for exp in block.exprs {
            try exp.llvmType(loopScope)
        }
    }
    
}


extension WhileLoopStmt : StmtTypeProvider {
    
    func llvmType(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        
        // gen types for iterator
        guard try condition.llvmType(scope) == StdLib.BoolType else { throw error(SemaError.NonBooleanCondition) }
        
        // parse inside of loop in loop scope
        for exp in block.exprs {
            try exp.llvmType(loopScope)
        }
    }
}

