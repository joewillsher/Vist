//
//  VHIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol VHIRGenerator {
    func vhirGen(module module: Module, scope: Scope) throws -> Value
}
protocol VHIRStmtGenerator {
    func vhirStmtGen(module module: Module, scope: Scope) throws
}

// MARK: Special

extension Expr {
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        throw VHIRError.notGenerator
    }
}
extension Stmt {
    func vhirStmtGen(module module: Module, scope: Scope) throws {
        throw VHIRError.notGenerator
    }
}
extension Decl {
    func vhirStmtGen(module module: Module, scope: Scope) throws {
        throw VHIRError.notGenerator
    }
}


extension AST {
    
    func vhirGenAST(module module: Module) throws {
        
        let builder = module.builder
        let scope = Scope()
        
        let mainTy = FnType(params: [], returns: BuiltinType.void)
        let main = try builder.buildFunction("main", type: mainTy, paramNames: [])
        
        for x in exprs {
            try builder.setInsertPoint(main)
            if case let g as VHIRGenerator = x { try g.vhirGen(module: module, scope: scope) }
            else if case let g as VHIRStmtGenerator = x { try g.vhirStmtGen(module: module, scope: scope) }
        }
        
        try builder.setInsertPoint(main)
        try builder.buildReturnVoid()
        
    }
}

// MARK: Lower AST nodes to instructions

extension IntegerLiteral: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        return try module.builder.buildIntLiteral(val)
    }
}

extension VariableDecl: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        let v = try value.vhirGen(module: module, scope: scope)
        scope.add(v, name: name)
        return try module.builder.buildVariableDecl(Operand(v), irName: name)
    }
}

extension FunctionCall/*: VHIRGenerator*/ {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        let args = try argArr.map { Operand(try $0.vhirGen(module: module, scope: scope)) }
        guard let argTypes = argArr.optionalMap({ $0._type }) else { throw VHIRError.paramsNotTyped }
        
        if let stdlib = try module.stdLibFunctionNamed(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(stdlib, args: args)
        }
        
        let function = module.functionNamed(mangledName)!
        return try module.builder.buildFunctionCall(function, args: args)
    }
}

extension FuncDecl: VHIRStmtGenerator {
    
    func vhirStmtGen(module module: Module, scope: Scope) throws {
        guard let type = fnType.type else { throw VHIRError.noType }
        
        
        // if has body
        if let impl = impl {
            let originalInsertPoint = module.builder.insertPoint
            
            // make function and move into it
            let function = try module.builder.buildFunction(mangledName, type: type, paramNames: impl.params)
            try module.builder.setInsertPoint(function)
            
            // make scope and occupy it with params
            let fnScope = Scope(parent: scope)
            for p in impl.params {
                fnScope.add(try function.paramNamed(p), name: p)
            }
            
            // vhir gen for body
            for case let x as VHIRGenerator in impl.body.exprs {
                try x.vhirGen(module: module, scope: fnScope)
            }
            
            module.builder.insertPoint = originalInsertPoint
        }
            // if no body, just add a prototype
        else {
            try module.builder.createFunctionPrototype(mangledName, type: type)
        }
        
    }
}

extension VariableExpr: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        return scope.variableNamed(name)!
    }
}




