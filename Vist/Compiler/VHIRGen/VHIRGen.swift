//
//  VHIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol RValueEmitter {
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor
}
protocol StmtEmitter {
    func emitStmt(module module: Module, scope: Scope) throws
}

protocol LValueEmitter: RValueEmitter {
    func emitLValue(module module: Module, scope: Scope) throws -> GetSetAccessor
}



extension Expr {
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
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
            if case let g as RValueEmitter = x { try g.emitRValue(module: module, scope: scope) }
            else if case let g as StmtEmitter = x { try g.emitStmt(module: module, scope: scope) }
        }
        
        try builder.setInsertPoint(main)
        try builder.buildReturnVoid()
        
    }
}

private extension RValue {
    /// The accessor whose getter returns `self`
    var accessor: ValAccessor { return ValAccessor(self) }

    /// Builds a reference accessor which can store into & load from
    /// the memory it allocates
    func buildReferenceAccessor() throws -> GetSetAccessor {
        let allocation = PtrOperand(try module.builder.buildAlloc(type!))
        try module.builder.buildStore(Operand(self), in: allocation)
        return RefAccessor(allocation)
    }
}

// MARK: Lower AST nodes to instructions

extension IntegerLiteral: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        return try module.builder.buildIntLiteral(val).accessor
    }
}

extension BooleanLiteral: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        return try module.builder.buildBoolLiteral(val).accessor
    }
}

extension VariableDecl: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {

        let val = try value.emitRValue(module: module, scope: scope).getter()
        
        if isMutable {
            let variable = try val.buildReferenceAccessor()
            scope.add(variable, name: name)
            return variable
        }
        else {
            let variable = try module.builder.buildVariableDecl(Operand(val), irName: name).accessor
            scope.add(variable, name: name)
            return variable
        }
    }
}

extension FunctionCall/*: VHIRGenerator*/ {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let args = try argArr.map { Operand(try $0.emitRValue(module: module, scope: scope).getter()) }
        guard let argTypes = argArr.optionalMap({ $0._type }) else { throw VHIRError.paramsNotTyped }
        
        if let stdlib = try module.stdLibFunctionNamed(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(stdlib, args: args).accessor
        }
        else if let runtime = try module.runtimeFunctionNamed(name, argTypes: argTypes) {
            return try module.builder.buildFunctionCall(runtime, args: args).accessor
        }
        else if
            let prefixRange = name.rangeOfString("Builtin."),
            let instruction = BuiltinInst(rawValue: name.stringByReplacingCharactersInRange(prefixRange, withString: "")) {
            
            return try module.builder.buildBuiltinInstruction(instruction, args: args[0], args[1]).accessor
        }
        else {
            let function = module.functionNamed(mangledName)!
            return try module.builder.buildFunctionCall(function, args: args).accessor
        }
    }
}

extension FuncDecl: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        guard let type = fnType.type else { throw VHIRError.noType(#file) }
        
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




extension VariableExpr: LValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        return scope.variableNamed(name)!
    }
    func emitLValue(module module: Module, scope: Scope) throws -> GetSetAccessor {
        return scope.variableNamed(name)! as! GetSetAccessor
    }
}

extension ReturnStmt: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let retVal = try expr.emitRValue(module: module, scope: scope).getter()
        return try module.builder.buildReturn(Operand(retVal)).accessor
    }
}

extension TupleExpr: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        guard let type = type else { throw VHIRError.noType(#file) }
        let elements = try self.elements.map { try $0.emitRValue(module: module, scope: scope).getter() }.map(Operand.init)
        return try module.builder.buildTupleCreate(type, elements: elements).accessor
    }
}

extension TupleMemberLookupExpr: RValueEmitter, LValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let tuple = try object.emitRValue(module: module, scope: scope).getter()
        return try module.builder.buildTupleExtract(Operand(tuple), index: index).accessor
    }
    
    func emitLValue(module module: Module, scope: Scope) throws -> GetSetAccessor {
        guard case let o as LValueEmitter = object else { fatalError() }
        
        let tuple = try o.emitLValue(module: module, scope: scope)
        let addr = tuple.accessor()
        
        let el = try module.builder.buildTupleElementPtr(addr, index: index)
        
        return RefAccessor(PtrOperand(el))
    }
}
extension PropertyLookupExpr: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let object = try self.object.emitRValue(module: module, scope: scope).getter()
        return try module.builder.buildStructExtract(Operand(object), property: propertyName).accessor
    }
}

extension BlockExpr: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        for case let x as RValueEmitter in exprs {
            try x.emitRValue(module: module, scope: scope)
        }
    }
}

extension ConditionalStmt: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        
        // the if statement's exit bb
        let exitBlock = try module.builder.appendBasicBlock(name: "exit")
        
        for (index, branch) in statements.enumerate() {
            
            // the success block, and the failure
            let ifBlock = try module.builder.appendBasicBlock(name: branch.condition == nil ? "else.\(index)" : "if.\(index)")
            try exitBlock.moveAfter(ifBlock)
            let failBlock: BasicBlock
            
            if let c = branch.condition {
                let cond = try c.emitRValue(module: module, scope: scope).getter()
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


extension ForInLoopStmt: StmtEmitter {
    
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
        let range = try iterator.emitRValue(module: module, scope: scope).getter()
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

extension WhileLoopStmt: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        
        // setup blocks
        let condBlock = try module.builder.appendBasicBlock(name: "cond")
        let loopBlock = try module.builder.appendBasicBlock(name: "loop")
        let exitBlock = try module.builder.appendBasicBlock(name: "loop.exit")
        
        // condition check in cond block
        try module.builder.buildBreak(to: condBlock)
        try module.builder.setInsertPoint(condBlock)
        
        let condBool = try condition.emitRValue(module: module, scope: scope).getter()
        let cond = try module.builder.buildStructExtract(Operand(condBool), property: "value", irName: "cond")
        
        // cond break into/past loop
        try module.builder.buildCondBreak(if: Operand(cond),
                                          to: (block: loopBlock, args: nil),
                                          elseTo: (block: exitBlock, args: nil))
        
        // build loop block
        try module.builder.setInsertPoint(loopBlock) // move into
        try block.emitStmt(module: module, scope: scope) // gen stmts
        try module.builder.buildBreak(to: condBlock) // break back to condition check
        try module.builder.setInsertPoint(exitBlock)  // move past -- we're done
    }
}

extension StructExpr: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
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
        
        return VoidLiteralValue().accessor
    }
}

extension InitialiserDecl: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        guard let type = ty.type, selfType = parent?.type else { throw VHIRError.noType(#file) }
        
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
        
        let selfVar = RefAccessor(PtrOperand(try module.builder.buildAlloc(selfType, irName: "self")))
        fnScope.add(selfVar, name: "self")
        
        // add self elements into the scope, whose accessors are elements of selfvar
        
        
        
        for param in impl.params {
            fnScope.add(ValAccessor(try function.paramNamed(param)), name: param)
        }
        
        // vhir gen for body
        try impl.body.emitStmt(module: module, scope: fnScope)
        try module.builder.buildReturn(Operand(try selfVar.getter()))
        
        module.builder.insertPoint = originalInsertPoint
    }
}

extension MutationExpr: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        let lvalAccessor = try object.emitRValue(module: module, scope: scope), rval = try value.emitRValue(module: module, scope: scope)
        
        guard case let accessor as GetSetAccessor = lvalAccessor else { return VoidLiteralValue().accessor }
        
        try accessor.setter(Operand(try rval.getter()))
        
        // TODO:
        //  - Each `emitRValue` function should return an accessor
        //  - lval here can use the referencesaccessor setter to store
        //    into the lhs if its a variable
        
        // the `%10` name for the address is because its reading beyond the instructions to get a name
        // and its not finding it. We should be returning the name of the alloc inst and not the address
        
        return VoidLiteralValue().accessor
    }
    
}


