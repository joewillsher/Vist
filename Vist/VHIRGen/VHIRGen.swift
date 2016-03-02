//
//  VHIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol VHIRGenerator {
    func vhirGen(module: Module) throws -> Value
}

extension ASTNode {
    func vhirGen(module: Module) throws -> Value {
        throw VHIRError.notGenerator
    }
}

extension AST: VHIRGenerator {
    
    func vhirGen(module: Module) throws {
        
        let builder = module.builder
        
        let mainTy = FnType(params: [], returns: BuiltinType.void)
        let main = try builder.buildFunction("main", type: mainTy, paramNames: [])
        
        for case let x as VHIRGenerator in exprs {
            try builder.setInsertPoint(main)
            try x.vhirGen(module)
        }
        
        try builder.setInsertPoint(main)
        try builder.buildReturnVoid()
        
    }
}

extension IntegerLiteral: VHIRGenerator {
    
    func vhirGen(module: Module) throws -> Value {
        return try module.builder.buildIntLiteral(val)
    }
}

extension VariableDecl: VHIRGenerator {
    
    func vhirGen(module: Module) throws -> Value {
        let v = try value.vhirGen(module)
        return try module.builder.buildVariableDecl(Operand(v), irName: name)
    }
}

extension BinaryExpr {
    
    func vhirGen(module: Module) throws -> Value {
        let args = try argArr.map { Operand(try $0.vhirGen(module)) }
        guard let argTypes = argArr.optionalMap({ $0._type }) else { throw VHIRError.paramsNotTyped }
        
        if let stdlib = try module.getStdLibFunction(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(stdlib, args: args)
        }
        
        fatalError()
    }
}

extension FunctionCallExpr: VHIRGenerator {
    
    func vhirGen(module: Module) throws -> Value {
        let args = try argArr.map { Operand(try $0.vhirGen(module)) }
        guard let argTypes = argArr.optionalMap({ $0._type }) else { throw VHIRError.paramsNotTyped }
        
        if let stdlib = try module.getStdLibFunction(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(stdlib, args: args)
        }
        
        fatalError()
    }
}

