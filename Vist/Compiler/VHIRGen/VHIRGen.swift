//
//  VHIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol ValueEmitter {
    /// Emit the get-accessor for a VHIR rvalue
    @warn_unused_result
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor
}
protocol StmtEmitter {
    /// Emit the VHIR for an AST statement
    func emitStmt(module module: Module, scope: Scope) throws
}

protocol LValueEmitter: ValueEmitter {
    /// Emit the get/set-accessor for a VHIR lvalue
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
    @warn_unused_result
    func emit(module module: Module, scope: Scope) throws {
        if case let rval as ValueEmitter = self {
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
        let scope = Scope(module: module)
        
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
            try scope.releaseVariables()
            try builder.buildReturnVoid()
        }
        
    }
}



// MARK: Lower AST nodes to instructions

extension IntegerLiteral : ValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let int = try module.builder.buildIntLiteral(val)
        let std = try module.builder.buildStructInit(StdLib.intType, values: Operand(int))
        return try std.accessor()
    }
}

extension BooleanLiteral : ValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let bool = try module.builder.buildBoolLiteral(val)
        let std = try module.builder.buildStructInit(StdLib.boolType, values: Operand(bool))
        return try std.accessor()
    }
}

extension StringLiteral : ValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
       
        // %0 = string_literal "meme"   // utf8 literal
        // %1 = int_literal 4           // size, calculated statically
        // %2 = call @String_topi64 (%0: %Builtin.OpaquePointer, %1: Builtin.Int)    // call to string initialiser
        
        // string_literal lowered to:
        //  - make global string constant
        //  - GEP from it to get the first element
        //
        // String initialiser allocates %1 bytes of memory and stores %0 into it
        //
        // String exposes methods to move buffer and change size
        //
        // String `print` passes `base` into a runtime vist_print which takes i8*
        
        // Misc todos:
        //  - Initialiser(allocating) calling convention?
        //  - Shorthand for stdlib types in manging -- Int->I, Bool->B, Double->D
        //  - Mangling operators by using a prefix then not using - to seperate tokens. In operators all chars are
        //    going to not be letters, so using a prefix for them (and a different prefix for functions) we can
        //    tell the demangler how to parse these chars
        //  - Make sure mangler can differentiate Int, Int and IntInt param types. Swift uses a number prefix.
        //  - Lower function visibility attributes
        
        // Bigger todos:
        //  - Type checking in all builder factory methods and...
        //  - Full error handling model in VHIR
        //  - Pointer type in stdlib
        
        
        
        /*
         %refcounted.type = type { i8*, i32 }
         $myFoo.rt = type { refcounted.type }
         
         
         
         vist_deallocRefType
         
         
         
         */
        
        let string = try module.builder.buildStringLiteral(str)
        let length = try module.builder.buildIntLiteral(str.characters.count + 1)
        
        let initialiser = try module.getOrInsertStdLibFunction(named: "String", argTypes: [BuiltinType.opaquePointer, BuiltinType.int(size: 64)])!
        let std = try module.builder.buildFunctionCall(initialiser, args: [Operand(string), Operand(length)])
        
        return try std.accessor()
    }
}


extension VariableDecl : ValueEmitter {
        
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        let val = try value.emitRValue(module: module, scope: scope)
        
        if isMutable {
            let variable = try val.getMemCopy()
            scope.add(variable, name: name)
            return variable
        }
        else {
            let variable = try module.builder.buildVariableDecl(Operand(val.getter()), irName: name).accessor()
            scope.add(variable, name: name)
            return variable
        }
    }
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

        if let stdlib = try module.getOrInsertStdLibFunction(named: name, argTypes: fnType.params) {
            return try module.builder.buildFunctionCall(stdlib, args: args).accessor()
        }
        else if let runtime = try module.getOrInsertRuntimeFunction(named: name, argTypes: fnType.params) /*where name.hasPrefix("vist_")*/ {
            return try module.builder.buildFunctionCall(runtime, args: args).accessor()
        }
        else if
            let prefixRange = name.rangeOfString("Builtin."),
            let instruction = BuiltinInst(rawValue: name.stringByReplacingCharactersInRange(prefixRange, withString: "")) {
            
            return try module.builder.buildBuiltinInstruction(instruction, args: args).accessor()
        }
        else if let function = module.functionNamed(mangledName) {
            return try module.builder.buildFunctionCall(function, args: args).accessor()
        }
        else { fatalError("No function \(name)") }
    }
}

private extension CollectionType where Generator.Element == FunctionAttributeExpr {
    var visibility: Function.Visibility {
        if contains(.`private`) { return .`private` }
        else if contains(.`public`) { return .`public` }
        else { return .`internal` } // default case is internal
    }
}

extension FuncDecl : StmtEmitter {
    
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
        
        function.visibility = attrs.visibility
        
        // make scope and occupy it with params
        let fnScope = Scope(parent: scope)
        
        // add the explicit method parameters
        for paramName in impl.params {
            let paramAccessor = try function.paramNamed(paramName).accessor()
            fnScope.add(paramAccessor, name: paramName)
        }
        // A method calling convention means we have to pass `self` in, and tell vars how
        // to access it, and `self`’s properties
        if case .method(let selfType) = type.callingConvention {
            // We need self to be passed by ref as a `RefParam`
            let selfParam = function.params![0] as! RefParam
            let selfVar = selfParam.accessor
            try selfVar.retainIfRefcounted()
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
        try fnScope.releaseVariables()

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

extension ReturnStmt: ValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let retVal = try expr.emitRValue(module: module, scope: scope).getter()
        return try module.builder.buildReturn(Operand(retVal)).accessor()
    }
}

extension TupleExpr: ValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        if self.elements.isEmpty { return try VoidLiteralValue().accessor() }
        
        guard case let type as TupleType = _type else { throw VHIRError.noType(#file) }
        let elements = try self.elements.map { try $0.emitRValue(module: module, scope: scope).getter() }.map(Operand.init)
        return try module.builder.buildTupleCreate(type, elements: elements).accessor()
    }
}

extension TupleMemberLookupExpr: ValueEmitter, LValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        let tuple = try object.emitRValue(module: module, scope: scope).getter()
        return try module.builder.buildTupleExtract(Operand(tuple), index: index).accessor()
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
            let object = try self.object.emitRValue(module: module, scope: scope)
            return try module.builder.buildStructExtract(Operand(try object.getter()), property: propertyName).accessor()
            
        case is ConceptType:
            let object = try self.object.emitRValue(module: module, scope: scope).asReferenceAccessor().reference()
            return try module.builder.buildOpenExistential(object, propertyName: propertyName).accessor()
            
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
        let loopVariable = try module.builder.buildStructInit(StdLib.intType, values: Operand(loopCountParam), irName: binded.name).accessor()
        loopScope.add(loopVariable, name: binded.name)
        
        // vhirgen the body of the loop
        try block.emitStmt(module: module, scope: loopScope)
        try loopScope.releaseVariables()
        
        // iterate the loop count and check whether we are within range
        let one = try module.builder.buildIntLiteral(1)
        let iterated = try module.builder.buildBuiltinInstructionCall(.iaddoverflow, args: Operand(loopCountParam), Operand(one), irName: "count.it")
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
        
        let loopScope = Scope(parent: scope)
        // build loop block
        try module.builder.setInsertPoint(loopBlock) // move into
        try block.emitStmt(module: module, scope: loopScope) // gen stmts
        try loopScope.releaseVariables()
        try module.builder.buildBreak(to: condBlock) // break back to condition check
        try module.builder.setInsertPoint(exitBlock)  // move past -- we're done
    }
}

extension StructExpr: ValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        module.getOrInsert(type)
        
        for i in initialisers {
            try i.emitStmt(module: module, scope: scope)
        }
        
        for m in methods {
            guard let t = m.fnType.type else { fatalError() }
            try module.getOrInsertFunction(named: m.name, type: t)
        }
        for m in methods {
            try m.emitStmt(module: module, scope: scope)
        }
        
        return try VoidLiteralValue().accessor()
    }
}

extension ConceptExpr: ValueEmitter {

    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        module.getOrInsert(type)
        
        for m in requiredMethods {
            try m.emitStmt(module: module, scope: scope)
        }
        
        return try VoidLiteralValue().accessor()
    }

}

extension InitialiserDecl: StmtEmitter {
    
    func emitStmt(module module: Module, scope: Scope) throws {
        guard let initialiserType = ty.type, selfType = parent?.type else { throw VHIRError.noType(#file) }
        
        // if has body
        guard let impl = impl else {
            try module.builder.createFunctionPrototype(mangledName, type: initialiserType.vhirType(module))
            return
        }
        
        let originalInsertPoint = module.builder.insertPoint
        
        // make function and move into it
        let function = try module.builder.buildFunction(mangledName, type: initialiserType.vhirType(module), paramNames: impl.params)
        try module.builder.setInsertPoint(function)
        
        // make scope and occupy it with params
        let fnScope = Scope(parent: scope)
        
        let selfVar: GetSetAccessor
        
        if selfType.heapAllocated {
            let size = try module.builder.buildIntLiteral(selfType.size(module), size: 32, irName: "size")
            
            let allocator = try module.getOrInsertRawRuntimeFunction(named: "vist_allocObject")!
            let refCounted = try module.builder.buildFunctionCall(allocator, args: [Operand(size)], irName: "refcounted")
            
            let memory = try refCounted.allocGetSetAccessor().reference()
            let bitcast = try module.builder.buildBitcast(from: PtrOperand(memory), newType: selfType.refCountedBox(module), irName: "storage")
            let accessor = RefCountedAccessor(refcountedBox: bitcast)
            try accessor.retain()
            selfVar = accessor
        }
        else {
             selfVar = try module.builder.buildAlloc(selfType, irName: "self").accessor
        }
        
        fnScope.add(selfVar, name: "self")
        
        // add self’s elements into the scope, whose accessors are elements of selfvar
        for member in selfType.members {
            let structElement = try module.builder.buildStructElementPtr(try selfVar.reference(),
                                                                         property: member.name,
                                                                         irName: member.name)
            fnScope.add(structElement.accessor, name: member.name)
        }
        
        // add the initialiser’s params
        for param in impl.params {
            fnScope.add(try function.paramNamed(param).accessor(), name: param)
        }
        
        // vhir gen for body
        try impl.body.emitStmt(module: module, scope: fnScope)
        
        try fnScope.removeVariableNamed("self")?.releaseUnretainedIfRefcounted()
        try fnScope.releaseVariables()
        
        try module.builder.buildReturn(Operand(try selfVar.aggregateGetter()))
        
        // move out of function
        module.builder.insertPoint = originalInsertPoint
    }
}


extension MutationExpr: ValueEmitter {
    
    func emitRValue(module module: Module, scope: Scope) throws -> Accessor {
        
        let rval = try value.emitRValue(module: module, scope: scope).getter()
        guard case let lhs as LValueEmitter = object else { fatalError() }
        
        // set the lhs to rval
        try lhs.emitLValue(module: module, scope: scope).setter(Operand(rval))

        return try VoidLiteralValue().accessor()
    }
    
}

extension MethodCallExpr: ValueEmitter {
    
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
            return try module.builder.buildFunctionCall(function, args: [selfRef] + args).accessor()
            
        case let existentialType as ConceptType:
            
            guard let argTypes = args.optionalMap({$0.type}) else { fatalError() }
            
            // get the witness from the existential
            let fn = try module.builder.buildExistentialWitnessMethod(selfRef,
                                                                      methodName: name,
                                                                      argTypes: argTypes,
                                                                      existentialType: existentialType,
                                                                      irName: "witness")
            guard case let fnType as FnType = fn.memType else { fatalError() }
            
            // get the instance from the existential
            let unboxedSelf = try module.builder.buildExistentialUnbox(selfRef, irName: "unboxed")
            // call the method by applying the opaque ptr to self as the first param
            return try module.builder.buildFunctionApply(PtrOperand(fn),
                                                        returnType: fnType.returns,
                                                        args: [PtrOperand(unboxedSelf)] + args).accessor()
        default:
            fatalError()
        }

        
    }
}




