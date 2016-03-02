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
        let main = try builder.createFunction("main", type: mainTy, paramNames: [])
        
        for case let x as VHIRGenerator in exprs {
            try builder.setInsertPoint(main)
            try x.vhirGen(module)
        }
        
        try builder.setInsertPoint(main)
        try builder.createReturnVoid()
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
        let decl = try module.builder.buildVariableDecl(Operand(v), irName: name)
        return decl
    }
}

//extension FunctionCallExpr: VHIRGenerator {
//    
//    func vhirGen(module: Module) throws -> Value {
//        
//    }
//}

