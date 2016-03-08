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

extension BooleanLiteral: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        return try module.builder.buildBoolLiteral(val)
    }
}

extension VariableDecl: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        let val = try value.vhirGen(module: module, scope: scope)
        let variable = try module.builder.buildVariableDecl(Operand(val), irName: name)
        scope.add(variable, name: name)
        return variable
    }
}

extension FunctionCall/*: VHIRGenerator*/ {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        let args = try argArr.map { Operand(try $0.vhirGen(module: module, scope: scope)) }
        guard let argTypes = argArr.optionalMap({ $0._type }), returnType = _type else { throw VHIRError.paramsNotTyped }
        
        if let stdlib = try module.stdLibFunctionNamed(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(stdlib, args: args)
        }
        else if let runtime = try module.runtimeFunctionNamed(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(runtime, args: args)
        }
        else if
            let prefixRange = name.rangeOfString("Builtin."),
            let instruction = BuiltinInst(rawValue: name.stringByReplacingCharactersInRange(prefixRange, withString: "")) where args.count == 2{
            
            return try module.builder.buildBuiltinCall(instruction, args: args[0], args[1], returnType: returnType)
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
            for param in impl.params {
                fnScope.add(try function.paramNamed(param), name: param)
            }
            
            // vhir gen for body
            try impl.body.vhirStmtGen(module: module, scope: fnScope)
            
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

extension ReturnStmt: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        return try module.builder.buildReturn(Operand(try expr.vhirGen(module: module, scope: scope)))
    }
}

extension TupleExpr: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        guard let type = type else { throw VHIRError.noType }
        let elements = try self.elements.map { try $0.vhirGen(module: module, scope: scope) }.map(Operand.init)
        return try module.builder.buildTupleCreate(type, elements: elements)
    }
}

extension TupleMemberLookupExpr: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        let tuple = try object.vhirGen(module: module, scope: scope)
        return try module.builder.buildTupleExtract(Operand(tuple), index: index)
    }
}
extension PropertyLookupExpr: VHIRGenerator {
    
    func vhirGen(module module: Module, scope: Scope) throws -> Value {
        let object = try self.object.vhirGen(module: module, scope: scope)
        return try module.builder.buildStructExtract(Operand(object), property: propertyName)
    }
}

extension BlockExpr: VHIRGenerator {
    
    func vhirStmtGen(module module: Module, scope: Scope) throws {
        for case let x as VHIRGenerator in exprs {
            try x.vhirGen(module: module, scope: scope)
        }
    }
}

extension ConditionalStmt: VHIRStmtGenerator {
    
    func vhirStmtGen(module module: Module, scope: Scope) throws {
        
        // the if statement's exit bb
        let exitBlock = try module.builder.appendBasicBlock("exit")
        
        for (index, branch) in statements.enumerate() {
            
            // the success block, and the failure
            let ifBlock = try module.builder.appendBasicBlock(branch.condition == nil ? "else.\(index)" : "if.\(index)")
            let failBlock: BasicBlock
            
            if let c = branch.condition {
                let cond = try c.vhirGen(module: module, scope: scope)
                let v = try module.builder.buildStructExtract(Operand(cond), property: "value")
                
                // if its the last block, a condition fail takes
                // us to the exit
                if index == statements.endIndex.predecessor() {
                    failBlock = exitBlock
                }
                    // otherwise it takes us to a landing pad for the next
                    // condition to be evaluated
                else {
                    failBlock = try module.builder.appendBasicBlock("fail.\(index)")
                }
                
                try module.builder.buildCondBreak(ifBlock, elseBlock: failBlock, condition: Operand(v), params: nil)
            }
                // if its unconditional, we go to the exit afterwards
            else {
                failBlock = exitBlock
                try module.builder.buildBreak(ifBlock, params: nil)
            }
            
            // move into the if block, and evaluate its expressions
            // in a new scope
            let ifScope = Scope(parent: scope)
            try module.builder.setInsertPoint(ifBlock)
            try branch.block.vhirStmtGen(module: module, scope: ifScope)
            
            // once we're done in success, break to the exit and
            // move into the fail for the next round
            try module.builder.buildBreak(exitBlock, params: nil)
            try module.builder.setInsertPoint(failBlock)
        }
        
    }
    
}


extension ForInLoopStmt: VHIRStmtGenerator {
    
    func vhirStmtGen(module module: Module, scope: Scope) throws {
        
        let range = try iterator.vhirGen(module: module, scope: scope)
        _ = try module.builder.buildStructExtract(Operand(range), property: "start")
        _ = try module.builder.buildStructExtract(Operand(range), property: "end")
        
//        let loop = module.builder.addBasicBlock("loop", params: <#T##[Operand]?#>)
        
        
        
    }
}



