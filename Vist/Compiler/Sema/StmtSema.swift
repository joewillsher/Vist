//
//  StmtSema.swift
//  Vist
//
//  Created by Josef Willsher on 03/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


private extension ScopeEscapeStmt {
    func checkScopeEscapeStmt(scope: SemaScope) throws {
        // set the AST context to `scope.returnType`
        let retScope = SemaScope(parent: scope, semaContext: scope.returnType)
        let returnType = try expr.typeForNode(retScope)
        
        guard let ret = scope.returnType where ret == returnType else {
            throw semaError(.wrongFunctionReturnType(applied: returnType, expected: scope.returnType ?? BuiltinType.null))
        }
    }
}

extension ReturnStmt : StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        guard !scope.isYield else { throw semaError(.invalidReturn) }
        try checkScopeEscapeStmt(scope)
    }
}


extension YieldStmt : StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        guard scope.isYield else { throw semaError(.invalidYield) }
        try checkScopeEscapeStmt(scope)
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Control flow
//-------------------------------------------------------------------------------------------------------------------------

extension ConditionalStmt : StmtTypeProvider {
    
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
        guard let condition = c where condition == StdLib.boolType else { throw semaError(.nonBooleanCondition) }
    }
    
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Loops
//-------------------------------------------------------------------------------------------------------------------------


extension ForInLoopStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType)
        let generator = try self.generator.typeForNode(scope)
        
        // check its a generator, and the return type is the loop variable type
        guard case let storage as StorageType = generator, let generatorFunctionType = storage.generatorFunction(), let yieldType = generatorFunctionType.yieldType
            else { throw semaError(.notGenerator(generator)) }
        
        // add bound name to scopes
        loopScope[variable: binded.name] = (type: yieldType, mutable: false)
        
        self.generatorFunctionName = "generate".mangle(generatorFunctionType.withParent(storage, mutating: false))
        
        // parse inside of loop in loop scope
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(loopScope)
        }
    }
    
}


extension WhileLoopStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope(parent: scope, returnType: scope.returnType, isYield: scope.isYield)
        
        // gen types for iterator
        guard try condition.typeForNode(scope) == StdLib.boolType else { throw semaError(.nonBooleanCondition) }
        
        // parse inside of loop in loop scope
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(loopScope)
        }
    }
}

