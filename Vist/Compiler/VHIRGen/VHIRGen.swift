//
//  VHIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol VHIRGenerator {
    func emitValue(module module: Module, scope: Scope) throws -> RValue
}
protocol VHIRStmtGenerator {
    func emitStmt(module module: Module, scope: Scope) throws
}

// MARK: Special

extension Expr {
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        throw VHIRError.notGenerator
    }
}
extension Stmt {
    func emitStmt(module module: Module, scope: Scope) throws {
        throw VHIRError.notGenerator
    }
}
extension Decl {
    func emitStmt(module module: Module, scope: Scope) throws {
        throw VHIRError.notGenerator
    }
}


extension AST {
    
    func emitAST(module module: Module) throws {
        
        let builder = module.builder
        let scope = Scope()
        
        let mainTy = FnType(params: [], returns: BuiltinType.void)
        let main = try builder.buildFunction("main", type: mainTy, paramNames: [])
        
        for x in exprs {
            if case let g as VHIRGenerator = x {
                try g.emitValue(module: module, scope: scope) }
            else if case let g as VHIRStmtGenerator = x { try g.emitStmt(module: module, scope: scope) }
        }
        
        try builder.setInsertPoint(main)
        try builder.buildReturnVoid()
        
    }
}

// MARK: Lower AST nodes to instructions

extension IntegerLiteral: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        return try module.builder.buildIntLiteral(val)
    }
}

extension BooleanLiteral: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        return try module.builder.buildBoolLiteral(val)
    }
}

extension VariableDecl: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {

        let val = try value.emitValue(module: module, scope: scope)
        
        if isMutable {
            let variable = try module.builder.referenceAccessor(val)
            scope.add(variable, name: name)
            return val
        }
        else {
            let variable = try module.builder.buildVariableDecl(Operand(val), irName: name)
            scope.add(ValAccessor(variable), name: name)
            return variable
        }
    }
}

extension FunctionCall/*: VHIRGenerator*/ {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        let args = try argArr.map { Operand(try $0.emitValue(module: module, scope: scope)) }
        guard let argTypes = argArr.optionalMap({ $0._type }) else { throw VHIRError.paramsNotTyped }
        
        if let stdlib = try module.stdLibFunctionNamed(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(stdlib, args: args)
        }
        else if let runtime = try module.runtimeFunctionNamed(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(runtime, args: args)
        }
        else if
            let prefixRange = name.rangeOfString("Builtin."),
            let instruction = BuiltinInst(rawValue: name.stringByReplacingCharactersInRange(prefixRange, withString: "")) {
            
            return try module.builder.buildBuiltinInstruction(instruction, args: args[0], args[1])
        }
        else {
            let function = module.functionNamed(mangledName)!
            return try module.builder.buildFunctionCall(function, args: args)
        }
    }
}

extension FuncDecl: VHIRStmtGenerator {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        guard let type = fnType.type else { throw VHIRError.noType }
        
        // if has body
        guard let impl = impl else {
            try module.builder.createFunctionPrototype(mangledName, type: type)
            return
        }
        
        let originalInsertPoint = module.builder.insertPoint
        
        // make function and move into it
        let function = try module.builder.buildFunction(mangledName, type: type, paramNames: impl.params)
        try module.builder.setInsertPoint(function)
        
        // make scope and occupy it with params
        let fnScope = Scope(parent: scope)
        for param in impl.params {
            fnScope.add(ValAccessor(try function.paramNamed(param)), name: param)
        }
        
        // vhir gen for body
        try impl.body.emitStmt(module: module, scope: fnScope)
        
        module.builder.insertPoint = originalInsertPoint
    }
}




extension VariableExpr: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        return try scope.variableNamed(name)!.getter()
    }
}

extension ReturnStmt: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        let retVal = try expr.emitValue(module: module, scope: scope)
        return try module.builder.buildReturn(Operand(retVal))
    }
}

extension TupleExpr: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        guard let type = type else { throw VHIRError.noType }
        let elements = try self.elements.map { try $0.emitValue(module: module, scope: scope) }.map(Operand.init)
        return try module.builder.buildTupleCreate(type, elements: elements)
    }
}

extension TupleMemberLookupExpr: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        let tuple = try object.emitValue(module: module, scope: scope)
        return try module.builder.buildTupleExtract(Operand(tuple), index: index)
    }
}
extension PropertyLookupExpr: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        let object = try self.object.emitValue(module: module, scope: scope)
        return try module.builder.buildStructExtract(Operand(object), property: propertyName)
    }
}

extension BlockExpr: VHIRStmtGenerator {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        for case let x as VHIRGenerator in exprs {
            try x.emitValue(module: module, scope: scope)
        }
    }
}

extension ConditionalStmt: VHIRStmtGenerator {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        
        // the if statement's exit bb
        let exitBlock = try module.builder.appendBasicBlock(name: "exit")
        
        for (index, branch) in statements.enumerate() {
            
            // the success block, and the failure
            let ifBlock = try module.builder.appendBasicBlock(name: branch.condition == nil ? "else.\(index)" : "if.\(index)")
            try exitBlock.moveAfter(ifBlock)
            let failBlock: BasicBlock
            
            if let c = branch.condition {
                let cond = try c.emitValue(module: module, scope: scope)
                let v = try module.builder.buildStructExtract(Operand(cond), property: "value")
                
                // if its the last block, a condition fail takes
                // us to the exit
                if index == statements.endIndex.predecessor() {
                    failBlock = exitBlock
                }
                    // otherwise it takes us to a landing pad for the next
                    // condition to be evaluated
                else {
                    failBlock = try module.builder.appendBasicBlock(name: "fail.\(index)")
                    try exitBlock.moveAfter(failBlock)
                }
                
                try module.builder.buildCondBreak(if: Operand(v),
                                                  to: (block: ifBlock, args: nil),
                                                  elseTo: (block: failBlock, args: nil))
            }
                // if its unconditional, we go to the exit afterwards
            else {
                failBlock = exitBlock
                try module.builder.buildBreak(to: ifBlock)
            }
            
            // move into the if block, and evaluate its expressions
            // in a new scope
            let ifScope = Scope(parent: scope)
            try module.builder.setInsertPoint(ifBlock)
            try branch.block.emitStmt(module: module, scope: ifScope)
            
            // once we're done in success, break to the exit and
            // move into the fail for the next round
            try module.builder.buildBreak(to: exitBlock)
            try module.builder.setInsertPoint(failBlock)
        }
        
    }
    
}


extension ForInLoopStmt: VHIRStmtGenerator {
    
//        break $loop(%6: %Builtin.Int64)
//    
//    $loop(%loop.count: %Builtin.Int64):                                           // preds: entry, loop
//        %8 = struct %Int (%loop.count: %Builtin.Int64)                              // uses: %9
//    
//        BODY...
//
//        %count.it = builtin i_add %loop.count: %Builtin.Int64, %10: %Builtin.Int64  // uses: %13
//        %11 = bool_literal false                                                    // uses: %12
//        %12 = struct %Bool (%11: %Builtin.Bool)                                     // uses:
//        break %12: %Bool, $loop(%count.it: %Builtin.Int64), $loop.exit
//    
//    $loop.exit:                                                                   // preds: loop
    
    func emitStmt(module module: Module, scope: Scope) throws {
        
        // extract loop start and ends as builtin ints
        let range = try iterator.emitValue(module: module, scope: scope)
        let startInt = try module.builder.buildStructExtract(Operand(range), property: "start")
        let endInt = try module.builder.buildStructExtract(Operand(range), property: "end")
        let start = try module.builder.buildStructExtract(Operand(startInt), property: "value")
        let end = try module.builder.buildStructExtract(Operand(endInt), property: "value")
        
        // loop count, builtin int
        let loopCountParam = BBParam(paramName: "loop.count", type: Builtin.intType)
        let loopBlock = try module.builder.appendBasicBlock(name: "loop", parameters: [loopCountParam])
        let exitBlock = try module.builder.appendBasicBlock(name: "loop.exit")
        
        // break into the loop block
        let loopOperand = BlockOperand(value: start, param: loopCountParam)
        try module.builder.buildBreak(to: loopBlock, args: [loopOperand])
        try module.builder.setInsertPoint(loopBlock)
        
        // make the loop's vhirgen scope and build the stdint count to put in it
        let loopScope = Scope(parent: scope)
        let loopVariable = try module.builder.buildStructInit(StdLib.intType, values: loopOperand)
        loopScope.add(ValAccessor(loopVariable), name: binded.name)
        
        // vhirgen the body of the loop
        try block.emitStmt(module: module, scope: loopScope)
        
        // iterate the loop count and check whether we are within range
        let one = try module.builder.buildBuiltinInt(1)
        let iterated = try module.builder.buildBuiltinInstruction(.iaddoverflow, args: loopOperand, Operand(one), irName: "count.it")
        let condition = try module.builder.buildBuiltinInstruction(.lte, args: Operand(iterated), Operand(end))
        
        // cond break -- leave the loop or go again
        // call the loop block but with the iterated loop count
        let iteratedLoopOperand = BlockOperand(value: iterated, param: loopCountParam)
        try module.builder.buildCondBreak(if: Operand(condition),
                                          to: (block: loopBlock, args: [iteratedLoopOperand]),
                                          elseTo: (block: exitBlock, args: nil))
        
        try module.builder.setInsertPoint(exitBlock)
    }
}

extension WhileLoopStmt: VHIRStmtGenerator {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        
        // setup blocks
        let condBlock = try module.builder.appendBasicBlock(name: "cond")
        let loopBlock = try module.builder.appendBasicBlock(name: "loop")
        let exitBlock = try module.builder.appendBasicBlock(name: "loop.exit")
        
        try module.builder.buildBreak(to: condBlock)
        try module.builder.setInsertPoint(condBlock)
        
        let condBool = try condition.emitValue(module: module, scope: scope)
        let cond = try module.builder.buildStructExtract(Operand(condBool), property: "value", irName: "cond")
        
        try module.builder.buildCondBreak(if: Operand(cond),
                                          to: (block: loopBlock, args: nil),
                                          elseTo: (block: exitBlock, args: nil))
        
        try module.builder.setInsertPoint(loopBlock)
        try block.emitStmt(module: module, scope: scope)
        try module.builder.buildBreak(to: condBlock)
        
        try module.builder.setInsertPoint(exitBlock)
    }
}

extension StructExpr: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        module.getOrInsertAliasTo(type)
        
        for i in initialisers {
            try i.emitStmt(module: module, scope: scope)
        }
        
        for m in methods {
            guard let t = m.fnType.type else { fatalError() }
            try module.getOrInsertFunctionNamed(m.name, type: t)
        }
        for m in methods {
            try m.emitStmt(module: module, scope: scope)
        }
        
        return VoidLiteralValue()
    }
}

extension InitialiserDecl: VHIRStmtGenerator {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        guard let type = ty.type, selfType = parent?.type else { throw VHIRError.noType }
        
        // if has body
        guard let impl = impl else {
            try module.builder.createFunctionPrototype(mangledName, type: type)
            return
        }
        
        let originalInsertPoint = module.builder.insertPoint
        
        // make function and move into it
        let function = try module.builder.buildFunction(mangledName, type: type, paramNames: impl.params)
        try module.builder.setInsertPoint(function)
        
        // make scope and occupy it with params
        let fnScope = Scope(parent: scope)
        
        let selfVar = RefAccessor(try module.builder.buildAlloc(selfType, irName: "self").address)
        fnScope.add(selfVar, name: "self")
        
        for param in impl.params {
            fnScope.add(ValAccessor(try function.paramNamed(param)), name: param)
        }
        
        // vhir gen for body
        try impl.body.emitStmt(module: module, scope: fnScope)
        try module.builder.buildReturn(Operand(try selfVar.getter()))
        
        module.builder.insertPoint = originalInsertPoint
    }
}

extension MutationExpr: VHIRGenerator {
    
    func emitValue(module module: Module, scope: Scope) throws -> RValue {
        
        let lval = try object.emitValue(module: module, scope: scope), rval = try value.emitValue(module: module, scope: scope)
//        
//        guard case let addr as Address = lval else { return VoidLiteralValue() }
//        
//        try module.builder.buildStore(Operand(rval), to: <#T##Address<Ty>#>)
        
        
        return VoidLiteralValue()
    }
    
}


