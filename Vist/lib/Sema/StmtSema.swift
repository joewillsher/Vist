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
        let returnType = try expr.typeForNode(scope: retScope)
        
        guard let ret = scope.returnType, ret == returnType else {
            throw semaError(.wrongFunctionReturnType(applied: returnType, expected: scope.returnType ?? BuiltinType.null))
        }
    }
}

extension ReturnStmt : StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        guard !scope.isYield, let returnType = scope.returnType else {
            throw semaError(.invalidReturn)
        }
        expectedReturnType = returnType
        
        let exprType = try expr.typeForNode(scope: scope)
        
        do {
            try exprType.addConstraint(returnType,
                                       solver: scope.constraintSolver)
        }
        catch SemaError.couldNotAddConstraint {
            // diagnose why the constraint system couldn't add the constraint
            throw semaError(.wrongFunctionReturnType(applied: exprType,
                                                     expected: returnType))
        }
    }
}


extension YieldStmt : StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        guard scope.isYield else { throw semaError(.invalidYield) }
        try checkScopeEscapeStmt(scope: scope)
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
            let ifScope = SemaScope.capturingScope(parent: scope)
            try statement.typeForNode(scope: ifScope)
        }
    }
}


extension ElseIfBlockStmt : StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // get condition type
        let blockScope = SemaScope.capturingScope(parent: scope)
        _ = try condition.typeForPattern(scope: blockScope)
        
        // gen types for cond block
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(scope: blockScope)
        }
    }
    
}

private extension ConditionalPattern {
    
    func typeForPattern(scope: SemaScope) throws -> Type? {
        
        switch self {
        case .boolean(let cond):
            let condType = try cond.typeForNode(scope: scope)
            
            guard condType == StdLib.boolType else {
                throw semaError(.nonBooleanCondition)
            }
            return condType
            
        case .typeMatch(let match):
            // if c the Int do
            // if c the Int = x.a.y do
            
            let targetType = try match.type.typeIn(scope)
            
            // add the implicit variable
            scope.addVariable(variable: (type: targetType, mutable: false, isImmutableCapture: false),
                              name: match.variable)
            
            let bound = match.explicitBoundExpr ?? VariableExpr(name: match.variable)
            let exprType = try bound.typeForNode(scope: scope)
            
            do {
                try exprType.addConstraint(targetType, solver: scope.constraintSolver)
            }
            catch SemaError.couldNotAddConstraint {
                throw semaError(.dynamicCastFail(label: match.variable, from: exprType, to: targetType))
            }
            
            match.boundExpr = bound
            match._type = targetType
            return targetType
            
        case .none:
            return nil
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//  MARK:                                                 Loops
//-------------------------------------------------------------------------------------------------------------------------


extension ForInLoopStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope.capturingScope(parent: scope)
        let generator = try self.generator.typeForNode(scope: scope)
        
        // check its a generator, and the return type is the loop variable type
        guard
            case let storage as NominalType = generator,
            let generatorFunctionType = storage.generatorFunction(),
            let yieldType = generatorFunctionType.yieldType
            else {
                throw semaError(.notGenerator(generator))
        }
        
        // add bound name to scopes
        loopScope.addVariable(variable: (type: yieldType, mutable: false, isImmutableCapture: false), name: binded.name)
        
        self.generatorFunctionName = "generate".mangle(type: generatorFunctionType.asMethod(withSelf: storage, mutating: false))
        
        // parse inside of loop in loop scope
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(scope: loopScope)
        }
    }
    
}


extension WhileLoopStmt: StmtTypeProvider {
    
    func typeForNode(scope: SemaScope) throws {
        
        // scopes for inner loop
        let loopScope = SemaScope.capturingScope(parent: scope)
        
        // gen types for iterator
        guard try condition.typeForNode(scope: scope) == StdLib.boolType else { throw semaError(.nonBooleanCondition) }
        
        // parse inside of loop in loop scope
        try block.exprs.walkChildren { exp in
            try exp.typeForNode(scope: loopScope)
        }
    }
}

