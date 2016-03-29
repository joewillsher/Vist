//
//  VHIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol RValueEmitter {
    @warn_unused_result
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor
}
protocol StmtEmitter {
    func emitStmt(module module: Module, scope: Scope) throws
}

protocol LValueEmitter: RValueEmitter {
    @warn_unused_result
    func emitLValue(module module: Module, scope: Scope) throws -> GetSetAccessor
}

/// A libaray without a main function can emit vhir for this
protocol LibraryTopLevel: ASTNode {}


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
extension ASTNode {
    func emit(module module: Module, scope: Scope) throws {
        if case let rval as RValueEmitter = self {
            _ = try rval.emitRValue(module: module, scope: scope)
        }
        else if case let stmt as StmtEmitter = self {
            try stmt.emitStmt(module: module, scope: scope)
        }
    }
}

extension CollectionType where Generator.Element == ASTNode {
    
    func emitBody(module module: Module, scope: Scope) throws {
        for x in self {
            try x.emit(module: module, scope: scope)
        }
    }
    
}


extension AST {
    
    func emitVHIR(module module: Module, isLibrary: Bool) throws {
        
        let builder = module.builder
        let scope = Scope()
        
        if isLibrary {
            // if its a library we dont emit a main, and just vhirgen on any decls/statements
            for case let g as LibraryTopLevel in exprs {
                try g.emit(module: module, scope: scope)
            }
        }
        else {
            let mainTy = FnType(params: [], returns: BuiltinType.void)
            let main = try builder.buildFunction("main", type: mainTy, paramNames: [])
            
            try exprs.emitBody(module: module, scope: scope)
            
            try builder.setInsertPoint(main)
            try builder.buildReturnVoid()
        }
        
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
            let variable = try val.allocAccessor()
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


private extension CollectionType where Generator.Element == Expr {
    
}

extension FunctionCall/*: VHIRGenerator*/ {
    
    func argOperands(module module: Module, scope: Scope) throws -> [Operand] {
        guard case let fnType as FnType = fnType?.usingTypesIn(module) else { throw VHIRError.paramsNotTyped }
        
        return try zip(argArr, fnType.params).map { rawArg, paramType in
            let arg = try rawArg.emitRValue(module: module, scope: scope)
            
            if case let alias as TypeAlias = paramType, case let existentialType as ConceptType = alias.targetType {
                let existentialRef = try arg.asReferenceAccessor().reference()
                return try module.builder.buildExistentialBox(existentialRef, existentialType: existentialType)
            }
            else {
                return try arg.getter()
            }
            }.map(Operand.init)
    }
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        guard case let fnType as FnType = fnType?.usingTypesIn(module) else { throw VHIRError.paramsNotTyped }
        let args = try argOperands(module: module, scope: scope)

        if let stdlib = try module.stdLibFunctionNamed(name, argTypes: fnType.params) {
            return try module.builder.buildFunctionCall(stdlib, args: args).accessor
        }
        else if let runtime = try module.runtimeFunctionNamed(name, argTypes: fnType.params) /*where name.hasPrefix("vist_")*/ {
            return try module.builder.buildFunctionCall(runtime, args: args).accessor
        }
        else if
            let prefixRange = name.rangeOfString("Builtin."),
            let instruction = BuiltinInst(rawValue: name.stringByReplacingCharactersInRange(prefixRange, withString: "")) {
            
            return try module.builder.buildBuiltinInstruction(instruction, args: args).accessor
        }
        else if let function = module.functionNamed(mangledName) {
            return try module.builder.buildFunctionCall(function, args: args).accessor
        }
        else { fatalError("No function \(name)") }
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
        
        // find proto/make function and move into it
        let function = try module.builder.getOrBuildFunction(mangledName, type: type, paramNames: impl.params)
        try module.builder.setInsertPoint(function)
        
        // make scope and occupy it with params
        let fnScope = Scope(parent: scope)
        
        // add the explicit method parameters
        for paramName in impl.params {
            let paramAccessor = try function.paramNamed(paramName).accessor
            fnScope.add(paramAccessor, name: paramName)
        }
        // A method calling convention means we have to pass `self` in, and tell vars how
        // to access it, and `self`’s properties
        if case .method(let selfType) = type.callingConvention {
            // We need self to be passed by ref as a `RefParam`
            let selfParam = function.params![0] as! RefParam
            let selfVar = RefAccessor(memory: selfParam)
            fnScope.add(selfVar, name: "self") // add `self`
            
            // add self's properties, their accessor is a lazily evaluated struct GEP
            if case let type as StorageType = selfType {
                for property in type.members {
                    let pVar = LazyRefAccessor {
                        try module.builder.buildStructElementPtr(selfVar.reference(), property: property.name, irName: property.name)
                    }
                    fnScope.add(pVar, name: property.name)
                }
            }
            
        }
        
        // vhir gen for body
        try impl.body.emitStmt(module: module, scope: fnScope)
        
        // add implicit `return ()` for a void function without a return expression
        if type.returns == BuiltinType.void && !function.instructions.contains({$0 is ReturnInst}) {
            try module.builder.buildReturnVoid()
        }
        
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
        
        if self.elements.isEmpty { return VoidLiteralValue().accessor }
        
        guard case let type as TupleType = _type else { throw VHIRError.noType(#file) }
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
        return try module.builder.buildTupleElementPtr(tuple.reference(), index: index).accessor
    }
}

extension PropertyLookupExpr: LValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        switch object._type {
        case is StructType:
            let object = try self.object.emitRValue(module: module, scope: scope).getter()
            return try module.builder.buildStructExtract(Operand(object), property: propertyName).accessor
            
        case is ConceptType:
            let object = try self.object.emitRValue(module: module, scope: scope).asReferenceAccessor().reference()
            return try module.builder.buildOpenExistential(object, propertyName: propertyName).accessor
            
        default:
            fatalError()
        }
    }
    
    func emitLValue(module module: Module, scope: Scope) throws -> GetSetAccessor {
        guard case let o as LValueEmitter = object else { fatalError() }
        
        let str = try o.emitLValue(module: module, scope: scope)
        return try module.builder.buildStructElementPtr(str.reference(), property: propertyName).accessor
    }
    
}

extension BlockExpr: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        try exprs.emitBody(module: module, scope: scope)
    }
}

extension ConditionalStmt: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        
        // the if statement's exit bb
        let exitBlock = try module.builder.appendBasicBlock(name: "exit")
        
        for (index, branch) in statements.enumerate() {
            
            // the success block, and the failure
            let ifBlock = try module.builder.appendBasicBlock(name: branch.condition == nil ? "else.\(index)" : "if.\(index)")
            try exitBlock.move(after: ifBlock)
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
                    try exitBlock.move(after: failBlock)
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
            if !ifBlock.instructions.contains({$0.instIsTerminator}) {
                try module.builder.buildBreak(to: exitBlock)
                try module.builder.setInsertPoint(failBlock)
            }
                // if there is a return or break, we dont jump to exit
                // if its the last block and the exit is not used, we can remove
            else if index == statements.endIndex.predecessor() && exitBlock.predecessors.isEmpty {
                try exitBlock.eraseFromParent()
            }
                // otherwise, if its not the end, we move to the exit
            else {
                try module.builder.setInsertPoint(failBlock)
            }
            
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
        let loopCountParam = Param(paramName: "loop.count", type: Builtin.intType)
        let loopBlock = try module.builder.appendBasicBlock(name: "loop", parameters: [loopCountParam])
        let exitBlock = try module.builder.appendBasicBlock(name: "loop.exit")
        
        // break into the loop block
        let loopOperand = BlockOperand(value: start, param: loopCountParam)
        try module.builder.buildBreak(to: loopBlock, args: [loopOperand])
        try module.builder.setInsertPoint(loopBlock)
        
        // make the loop's vhirgen scope and build the stdint count to put in it
        let loopScope = Scope(parent: scope)
        let loopVariable = try module.builder.buildStructInit(StdLib.intType, values: loopOperand)
        loopScope.add(loopVariable.accessor, name: binded.name)
        
        // vhirgen the body of the loop
        try block.emitStmt(module: module, scope: loopScope)
        
        // iterate the loop count and check whether we are within range
        let one = try module.builder.buildBuiltinInt(1)
        let iterated = try module.builder.buildBuiltinInstructionCall(.iaddoverflow, args: loopOperand, Operand(one), irName: "count.it")
        let condition = try module.builder.buildBuiltinInstructionCall(.ilte, args: Operand(iterated), Operand(end))
        
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
        
        module.getOrInsert(type)
        
        for i in initialisers {
            try i.emitStmt(module: module, scope: scope)
        }
        
        for m in methods {
            guard let t = m.fnType.type else { fatalError() }
            try module.getOrInsertFunctionNamed(m.mangledName, type: t)
        }
        for m in methods {
            try m.emitStmt(module: module, scope: scope)
        }
        
        return VoidLiteralValue().accessor
    }
}

extension ConceptExpr: RValueEmitter {

    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        module.getOrInsert(type)
        
        for m in requiredMethods {
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
        
        let selfVar = try module.builder.buildAlloc(selfType, irName: "self").accessor
        fnScope.add(selfVar, name: "self")
        
        // add self’s elements into the scope, whose accessors are elements of selfvar
        for member in selfType.members {
            let accessor = try module.builder.buildStructElementPtr(selfVar.reference(), property: member.name, irName: member.name)
            fnScope.add(accessor.accessor, name: member.name)
        }
        
        // add the initialiser’s params
        for param in impl.params {
            fnScope.add(try function.paramNamed(param).accessor, name: param)
        }
        
        // vhir gen for body
        try impl.body.emitStmt(module: module, scope: fnScope)
        try module.builder.buildReturn(Operand(try selfVar.getter()))
        
        // move out of function
        module.builder.insertPoint = originalInsertPoint
    }
}


extension MutationExpr: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        let rval = try value.emitRValue(module: module, scope: scope).getter()
        guard case let lhs as LValueEmitter = object else { fatalError() }
        
        // set the lhs to rval
        try lhs.emitLValue(module: module, scope: scope).setter(Operand(rval))

        return VoidLiteralValue().accessor
    }
    
}

extension MethodCallExpr: RValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        // TODO: guarantees about mutating methods only being called on mutable
        //       (and therefore reference-backed) objects. Maybe make non
        //       mutating methods take `self` as a value parameter.
        
        // build self and args' values
        let args = try argOperands(module: module, scope: scope)
        let selfVar = try object.emitRValue(module: module, scope: scope)
        
        // get ptr to self, if its not reference based we build
        // memory and store it there to get a ptr.
        let selfRef = try selfVar.asReferenceAccessor().reference()
        
        // construct function call
        switch object._type {
        case is StructType:
            let function = module.functionNamed(mangledName)!
            return try module.builder.buildFunctionCall(function, args: [selfRef] + args).accessor
            
        case let existentialType as ConceptType:
            
            guard let argTypes = args.optionalMap({$0.type}) else { fatalError() }
            
            let fn = try module.builder.buildExistentialWitnessMethod(selfRef,
                                                                      methodName: name,
                                                                      argTypes: argTypes,
                                                                      existentialType: existentialType)
            guard case let fnType as FnType = fn.memType else { fatalError() }
            return try module.builder.buildFunctionCall(PtrOperand(fn),
                                                        returnType: fnType.returns,
                                                        args: args).accessor
        default:
            fatalError()
        }

        
    }
}




