//
//  VIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSString

protocol ValueEmitter {
    /// Emit the get-accessor for a VIR rvalue
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue
}
protocol StmtEmitter {
    /// Emit the VIR for an AST statement
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws
}

protocol LValueEmitter: ValueEmitter {
    /// Emit the get/set-accessor for a VIR lvalue
    func emitLValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue
    func canEmitLValue(module: Module, gen: inout VIRGenFunction) throws -> Bool
}
extension LValueEmitter {
    func canEmitLValue(module: Module, gen: inout VIRGenFunction) throws -> Bool { return true }
}

/// A libaray without a main function can emit vir for this
protocol LibraryTopLevel: ASTNode {}


extension Expr {
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        throw VIRError.notGenerator(self.dynamicType)
    }
}
extension Stmt {
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        throw VIRError.notGenerator(self.dynamicType)
    }
}
extension Decl {
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        throw VIRError.notGenerator(self.dynamicType)
    }
}
extension ASTNode {
    func emit(module: Module, gen: inout VIRGenFunction) throws {
        if case let rval as ValueEmitter = self {
            let unusedAccessor = try rval.emitRValue(module: module, gen: &gen)
            // function calls return values at -1
            // unused values could have a ref count of 0 and not be deallocated
            // any unused function calls should have dealloc_unowned_object called on them
            if rval is FunctionCallExpr {
                try unusedAccessor.deallocUnowned()
            }
        }
        else if case let stmt as StmtEmitter = self {
            try stmt.emitStmt(module: module, gen: &gen)
        }
    }
}

extension Collection where Iterator.Element == ASTNode {
    
    func emitBody(module: Module, gen: inout VIRGenFunction) throws {
        for x in self {
            try x.emit(module: module, gen: &gen)
        }
    }
    
}

infix operator .+ {}
/// Used for constructing string descriptions
/// eg `irName: irName .+ "subexpr"`
func .+ (lhs: String?, rhs: String) -> String? {
    guard let l = lhs else { return nil }
    return "\(l).\(rhs)"
}

extension AST {
    
    func emitVIR(module: Module, isLibrary: Bool) throws {
        
        let builder = gen.builder!
        var gen = VIRGenFunction(scope: VIRGenScope(module: module),
                                 builder: builder)
        
        if isLibrary {
            // if its a library we dont emit a main, and just virgen on any decls/statements
            for case let g as LibraryTopLevel in exprs {
                try g.emit(module: module, gen: &gen)
            }
        }
        else {
            let mainTy = FunctionType(params: [], returns: BuiltinType.void)
            _ = try builder.buildFunction(name: "main", type: mainTy, paramNames: [])
            
            try exprs.emitBody(module: module, gen: &gen)
            
            try gen.cleanup()
            try builder.buildReturnVoid()
        }
        
    }
}



// MARK: Lower AST nodes to instructions

extension IntegerLiteral : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        let int = try gen.builder.build(inst: IntLiteralInst(val: val, size: 64))
        return try gen.builder.buildManaged(inst: StructInitInst(type: StdLib.intType, values: int), gen: &gen)
    }
}

extension BooleanLiteral : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        let bool = try gen.builder.build(inst: BoolLiteralInst(val: val))
        return try gen.builder.buildManaged(inst: StructInitInst(type: StdLib.boolType, values: bool), gen: &gen)
    }
}

extension StringLiteral : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
       
        // string_literal lowered to:
        //  - make global string constant
        //  - GEP from it to get the first element
        //
        // String initialiser allocates %1 bytes of memory and stores %0 into it
        // String exposes methods to move buffer and change size
        // String `print` passes `base` into a cshim functions which print the buffer
        //    - wholly if its contiguous UTF8
        //    - char by char if it contains UTF16 code units
        
        var string = try gen.builder.buildManaged(inst: StringLiteralInst(val: str), gen: &gen)
        var length = try gen.builder.buildManaged(inst: IntLiteralInst(val: str.utf8.count + 1, size: 64, irName: "size"), gen: &gen)
        var isUTFU = try gen.builder.buildManaged(inst: BoolLiteralInst(val: string.isUTF8Encoded, irName: "isUTF8"), gen: &gen)
        
        let paramTypes: [Type] = [BuiltinType.opaquePointer, BuiltinType.int(size: 64), BuiltinType.bool]
        let initName = "String".mangle(type: FunctionType(params: paramTypes, returns: StdLib.stringType, callingConvention: .initialiser))
        let initialiser = try module.getOrInsertStdLibFunction(mangledName: initName)!
        let std = try gen.builder.buildFunctionCall(function: initialiser,
                                                    args: [Operand(string.forward()), Operand(length.forward()), Operand(isUTFU.forward())])
        
        return ManagedValue.forUnmanaged(std, gen: &gen)
    }
}


extension VariableDecl : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        
        let type = value._type!.importedType(in: module)
        // gen the ManagedValue for the variable's value
        var val = try value.emitRValue(module: module, gen: &gen)
        // alloc variable memory
        var alloc = try gen.emitTempAlloc(memType: type)
        // coeerce to the right type and forward the cleanup to the memory
        var managed = try val.coerce(to: type, gen: &gen)
        try managed.forward(into: alloc, gen: &gen) // forward the temp
        
        // create a variableaddr inst and forward the memory's cleanup onto it
        let variable = try gen.builder.build(inst: VariableAddrInst(addr: alloc.forwardLValue(), irName: name))
        gen.managedValues.append(variable)
        return variable
    }
}

extension VariableGroupDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        for decl in declared {
            _ = try decl.emitRValue(module: module, gen: &gen)
        }
    }
}

extension FunctionCall/*: VIRGenerator*/ {
    
    func argOperands(module: Module, gen: inout VIRGenFunction) throws -> [ManagedValue] {
        guard case let fnType as FunctionType = fnType?.importedType(in: module) else {
            throw VIRError.paramsNotTyped
        }
        
        return try zip(argArr, fnType.params).map { rawArg, paramType in
            let arg = try rawArg.emitRValue(module: module, gen: &gen)
            return try arg.copy(gen: &gen)
        }
    }
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        
        let argAccessors = try argOperands(module: module, gen: &gen)
        let args = try argAccessors.map { try $0.aggregateGetValue() }.map(Operand.init)
        
        if let stdlib = try module.getOrInsertStdLibFunction(mangledName: mangledName) {
            return try gen.builder.buildFunctionCall(function: stdlib, args: args).accessor()
        }
        else if
            let prefixRange = name.range(of: "Builtin."),
            let instruction = BuiltinInst(rawValue: name.replacingCharacters(in: prefixRange, with: "")) {
            
            return try gen.builder.build(inst: BuiltinInstCall(inst: instruction, operands: args)).accessor()
        }
        else if let function = module.function(named: mangledName) {
            return try gen.builder.buildFunctionCall(function: function, args: args).accessor()
        }
        else if let closure = try scope.variable(named: name) {
            
            // If we only have an accessor, get the value from it, which must be a function* type
            // because the only case this is allowed is GEPing a struct
            // Otherwise we just get the lvalue from the byval accessor
            let ref = (closure is IndirectAccessor ?
                try! OpaqueLValue(rvalue: closure.aggregateGetValue()) :
                try closure.getValue()) as! LValue
            
            guard case let ret as FunctionType = ref.memType?.importedType(in: module) else { fatalError() }
            
            return try gen.builder.buildFunctionApply(function: PtrOperand(ref),
                                                         returnType: ret.returns,
                                                         args: args).accessor()
        }
        else {
            fatalError("No function name=\(name), mangledName=\(mangledName)")
        }
    }
}

extension ClosureExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        
        // get the name and type
        guard let mangledName = self.mangledName, let type = self.type else {
            fatalError()
        }
        // We cannot perform VIRGen
        precondition(hasConcreteType)
        
        // record position and create the closure body
        let entry = gen.builder.insertPoint
        let thunk = try gen.builder.getOrBuildFunction(name: mangledName,
                                                          type: type,
                                                          paramNames: parameters!)
        
        // Create the closure to delegate captures
        let closure = Closure.wrapping(function: thunk)
        let closureScope = VIRGenScope.capturing(parent: scope,
                                           function: closure.thunk,
                                           captureDelegate: closure,
                                           breakPoint: entry)
        // add params
        for param in parameters! {
            closureScope.insert(variable: try closure.thunk.param(named: param).accessor(), name: param)
        }
        // emit body
        try exprs.emitBody(module: module, scope: closureScope)
        // move back out
        gen.builder.insertPoint = entry
        
        // return an accessor of the function reference
        return try gen.builder.buildManaged(inst: FunctionRefInst(function: closure.thunk), gen: &gen)
    }
}

extension FuncDecl : StmtEmitter {
        
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        
        guard let type = typeRepr.type else { throw VIRError.noType(#function) }
        guard let mangledName = self.mangledName else { throw VIRError.noMangledName }
        
        // if has body
        guard let impl = impl else {
            try gen.builder.buildFunctionPrototype(name: mangledName, type: type, attrs: attrs)
            return
        }
        
        let originalInsertPoint = gen.builder.insertPoint
        
        // find proto/make function and move into it
        let function = try gen.builder.getOrBuildFunction(name: mangledName, type: type, paramNames: impl.params, attrs: attrs)
        gen.builder.insertPoint.function = function
        
        // make scope and occupy it with params
        let fnScope = VIRGenScope(parent: gen.scope, function: function)
        var vgf = VIRGenFunction(scope: fnScope, builder: gen.builder)
        
        // add the explicit method parameters
        for paramName in impl.params {
            let paramAccessor = try function.param(named: paramName).accessor()
            fnScope.insert(variable: paramAccessor, name: paramName)
        }
        // A method calling convention means we have to pass `self` in, and tell vars how
        // to access it, and `self`’s properties
        if case .method(let selfType, _) = type.callingConvention {
            // We need self to be passed by ref as a `RefParam`
            let selfParam = function.params![0]
            let selfVar = try selfParam.accessor()
            fnScope.insert(variable: selfVar, name: "self") // add `self`
            
            guard case let type as NominalType = selfType else { fatalError() }
            
            switch selfVar {
            // if it is a ref self the self accessors are lazily calculated struct GEP
            case let selfRef as IndirectAccessor:
                for property in type.members {
                    let pVar = LazyRefAccessor {
                        try vgf.builder.build(inst: StructElementPtrInst(object: selfRef.lValueReference(),
                                                                            property: property.name,
                                                                            irName: property.name))
                    }
                    fnScope.insert(variable: pVar, name: property.name)
                }
                // If it is a value self then we do a struct extract to get self elements
            // case is Accessor:
            default:
                for property in type.members {
                    let pVar = LazyAccessor(module: module) {
                        try vgf.builder.build(inst: StructExtractInst(object: selfVar.getValue(), property: property.name, irName: property.name))
                    }
                    fnScope.insert(variable: pVar, name: property.name)
                }
            }
        }
        
        // vir gen for body
        try impl.body.emitStmt(module: module, gen: &vgf)

        // TODO: look at exit nodes of block, not just place we're left off
        // add implicit `return ()` for a void function without a return expression
        if type.returns == BuiltinType.void && !function.instructions.contains(where: {$0 is ReturnInst}) {
            try vgf.cleanup()
            try vgf.builder.buildReturnVoid()
        }
        
        gen.builder.insertPoint = originalInsertPoint
    }
}




extension VariableExpr : LValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        return try scope.variable(named: name)!
    }
    func emitLValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        return try scope.variable(named: name)! as! IndirectAccessor
    }
    
    func canEmitLValue(module: Module, gen: inout VIRGenFunction) throws -> Bool {
        return try scope.variable(named: name) is LValueEmitter
    }
}

extension ReturnStmt : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        let retVal = try expr.emitRValue(module: module, gen: &gen)
        
        // before returning, we release all variables in the scope...
        try scope.releaseVariables(deleting: false, except: retVal)
        // ...and release-unowned the return value if its owned by the scope
        //    - we exepct the caller of the function to retain the value or
        //      dealloc it, so we return it as +0
        if scope.isInScope(variable: retVal) {
            try retVal.releaseUnowned()
        } else {
            // if its brought in by another scope, we can safely release
            try retVal.release() // FIXME: CHECK THIS
        }
        
        let boxed = try retVal
            .coercedAccessor(to: expectedReturnType, module: module)
            .getEscapingValue()
        return try gen.builder.buildReturn(value: boxed).accessor()
    }
}

extension TupleExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        
        if self.elements.isEmpty { return try VoidLiteralValue().accessor() }
        
        guard let type = try _type?.importedType(in: module).getAsTupleType() else { throw VIRError.noType(#file) }
        let elements = try self.elements.map { try $0.emitRValue(module: module, gen: &gen).aggregateGetValue() }
        
        return try gen.builder.build(inst: TupleCreateInst(type: type, elements: elements)).accessor()
    }
}

extension TupleMemberLookupExpr : ValueEmitter, LValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        let tuple = try object.emitRValue(module: module, gen: &gen).getValue()
        return try gen.builder.build(inst: TupleExtractInst(tuple: tuple, index: index)).accessor()
    }
    
    func emitLValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        guard case let o as LValueEmitter = object else { fatalError() }
        
        let tuple = try o.emitLValue(module: module, gen: &gen)
        return try gen.builder.build(inst: TupleElementPtrInst(tuple: tuple.lValueReference(), index: index)).accessor
    }
}

extension PropertyLookupExpr : LValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        
        switch object._type {
        case is StructType:
            switch object {
            case let lValEmitter as LValueEmitter
                where try lValEmitter.canEmitLValue(module: module, gen: &gen):
                // if self is backed by a ptr, do a GEP then load
                let object = try lValEmitter.emitLValue(module: module, gen: &gen)
                let elPtr = try gen.builder.build(inst: StructElementPtrInst(object: object.reference(), property: propertyName))
                return try gen.builder.build(inst: LoadInst(address: elPtr)).accessor()
            case let rValEmitter:
                // otherwise just get the struct element
                let object = try rValEmitter.emitRValue(module: module, gen: &gen)
                return try gen.builder.build(inst: StructExtractInst(object: object.getValue(), property: propertyName)).accessor()
            }
            
        case is ConceptType:
            let object = try self.object.emitRValue(module: module, gen: &gen).referenceBacked().reference()
            let ptr = try gen.builder.build(inst: ExistentialProjectPropertyInst(existential: object, propertyName: propertyName))
            return try gen.builder.build(inst: LoadInst(address: ptr)).accessor()
            
        default:
            fatalError()
        }
    }
    
    func emitLValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        guard case let o as LValueEmitter = self.object else { fatalError() }
        let object = try o.emitLValue(module: module, gen: &gen).lValueReference()
        
        switch self.object._type {
        case is StructType:
            return try gen.builder.build(inst: StructElementPtrInst(object: object, property: propertyName)).accessor
            
        case is ConceptType:
            return try gen.builder.build(inst: ExistentialProjectPropertyInst(existential: object, propertyName: propertyName)).accessor
            
        default:
            fatalError()
        }
        
    }
    
    func canEmitLValue(module: Module, gen: inout VIRGenFunction) throws -> Bool {
        guard case let o as LValueEmitter = object else { fatalError() }
        switch object._type {
        case is StructType: return try o.canEmitLValue(module: module, gen: &gen)
        case is ConceptType: return true
        default: fatalError()
        }
    }
    
}

extension BlockExpr : StmtEmitter {
    
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        try exprs.emitBody(module: module, gen: &gen)
    }
}

extension ConditionalStmt : StmtEmitter {
    
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        
        // the if statement's exit bb
        let base = gen.builder.insertPoint.block?.name.appending(".") ?? ""
        let exitBlock = try gen.builder.appendBasicBlock(name: "\(base)exit")
        
        for (index, branch) in statements.enumerated() {
            
            let isLast = branch === statements.last
            
            let backedgeBlock = isLast ?
                exitBlock :
                try gen.builder.appendBasicBlock(name: "\(base)false\(index)")
            if !isLast {
                try exitBlock.move(after: backedgeBlock)
            }
            
            if let c = branch.condition {
                let cond = try c.emitRValue(module: module, gen: &gen).getValue()
                let v = try gen.builder.build(inst: StructExtractInst(object: cond, property: "value"))
                
                let bodyBlock = try gen.builder.appendBasicBlock(name: branch.condition == nil ? "\(base)else\(index)" : "\(base)true\(index)")
                try backedgeBlock.move(after: bodyBlock)
                
                try gen.builder.buildCondBreak(if: Operand(v),
                                                  to: (block: bodyBlock, args: nil),
                                                  elseTo: (block: backedgeBlock, args: nil))
                gen.builder.insertPoint.block = bodyBlock
            }
            
            // move into the if block, and evaluate its expressions
            // in a new scope
            let ifScope = VIRGenScope(parent: scope, function: scope.function)
            try branch.block.emitStmt(module: module, scope: ifScope)
            
            // once we're done in success, break to the exit and
            // move into the fail for the next round
            if !(gen.builder.insertPoint.block?.instructions.last?.isTerminator ?? false) {
                try gen.builder.buildBreak(to: exitBlock)
            }
            
            gen.builder.insertPoint.block = backedgeBlock
        }
    }
    
}


extension ForInLoopStmt : StmtEmitter {
    
    
    /**
     For in loops rely on generators. Array could define a generator:
     
     ```vist
     extend Array {
        func generate::->Element = {
            for i in 0 ..< endIndex do
                yield self[i]
        }
     }
     ```
     
     A for in loop can revieve from the generator--the yielding allows it
     to look like the function returns many times. In reality `generate` is
     lowered to take a closure that takes its return type:
     
     ```vir
     // written type:
     func @generate : &method (%HalfOpenRange) -> %Int
     // lowered type:
     func @generate_mHalfOpenRangePtI : &method (%HalfOpenRange, %*(&thin (%Int) -> %Builtin.Void)) -> %Builtin.Void
     ```
     
     The `yield` applies this closure. The closure can also be thick, this allows
     it to capture state from the loop's scope.
     */
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        
        // get generator function
        guard let functionName = generatorFunctionName,
            let generatorFunction = try module.function(named: functionName)
                ?? module.getOrInsertStdLibFunction(mangledName: functionName),
            let yieldType = generatorFunction.type.yieldType else { fatalError() }
        
        // If we got the generator function from the stdlib, remangle 
        // the name non cannonically
        if let t = StdLib.function(mangledName: functionName) {
            generatorFunction.name = functionName.demangleName().mangle(type: t)
        }
        let entryInsertPoint = gen.builder.insertPoint
        
        // create a loop thunk, which stores the loop body
        let n = (entryInsertPoint.function?.name).map { "\($0)." } ?? "" // name
        let loopThunk = try gen.builder.buildUniqueFunction(name: "\(n)loop_thunk",
                                                               type: FunctionType(params: [yieldType]),
                                                               paramNames: [binded.name])
        
        // save current position
        gen.builder.insertPoint = entryInsertPoint
        
        // make the semantic scope for the loop
        // if the scope captures from the parent, it goes through a global variable
        let loopClosure = Closure.wrapping(function: loopThunk), generatorClosure = Closure.wrapping(function: generatorFunction)
        let loopScope = VIRGenScope.capturing(parent: scope,
                                        function: loopClosure.thunk,
                                        captureDelegate: loopClosure,
                                        breakPoint: gen.builder.insertPoint)
        let loopVarAccessor = try loopClosure.thunk.param(named: binded.name).accessor()
        loopScope.insert(variable: loopVarAccessor, name: binded.name)
        
        // emit body for loop thunk
        gen.builder.insertPoint.function = loopClosure.thunk // move to loop thunk
        try block.emitStmt(module: module, scope: loopScope)
        try gen.builder.buildReturnVoid()
        
        // move back out
        gen.builder.insertPoint = entryInsertPoint
        
        // require that we inline the loop thunks early
        loopClosure.thunk.inlineRequirement = .always
        generatorClosure.thunk.inlineRequirement = .always
        
        // get the instance of the generator
        let generator = try self.generator.emitRValue(module: module, gen: &gen).referenceBacked().aggregateReference()
        
        // call the generator function from loop position
        // apply the scope it requests
        let call = try gen.builder.buildFunctionCall(function: generatorClosure.thunk,
                                                        args: [PtrOperand(generator), loopClosure.thunk.buildFunctionPointer()])
        
        if let entryInst = entryInsertPoint.inst, let entryFunction = entryInsertPoint.function {
            // set the captured global values' lifetimes
            for captured in loopClosure.capturedGlobals {
                captured.lifetime = GlobalValue.Lifetime(start: entryInst,
                                                         end: call,
                                                         globalName: captured.globalName,
                                                         owningFunction: entryFunction)
            }
        }
        
        try loopScope.releaseVariables(deleting: true)
    }
}


extension YieldStmt : StmtEmitter {
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        
        guard case let loopThunk as RefParam = gen.builder.insertPoint.function?.params?[1] else {
            fatalError()
        }
        
        let val = try expr.emitRValue(module: module, gen: &gen)
        let param = try val.aggregateGetValue()
        
        try gen.builder.buildFunctionApply(function: PtrOperand(loopThunk), returnType: BuiltinType.void, args: [Operand(param)])
    }
}


extension WhileLoopStmt : StmtEmitter {
    
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        
        // setup blocks
        let condBlock = try gen.builder.appendBasicBlock(name: "cond")
        let loopBlock = try gen.builder.appendBasicBlock(name: "loop")
        let exitBlock = try gen.builder.appendBasicBlock(name: "loop.exit")
        
        // condition check in cond block
        try gen.builder.buildBreak(to: condBlock)
        gen.builder.insertPoint.block = condBlock
        
        let condBool = try condition.emitRValue(module: module, gen: &gen).forward().value
        let cond = try gen.builder.build(inst: StructExtractInst(object: condBool, property: "value", irName: "cond"))
        
        // cond break into/past loop
        try gen.builder.buildCondBreak(if: Operand(cond),
                                          to: (block: loopBlock, args: nil),
                                          elseTo: (block: exitBlock, args: nil))
        
        let loopScope = VIRGenScope(parent: scope, function: scope.function)
        // build loop block
        gen.builder.insertPoint.block = loopBlock // move into
        try block.emitStmt(module: module, scope: loopScope) // gen stmts
        try loopScope.releaseVariables(deleting: true)
        try gen.builder.buildBreak(to: condBlock) // break back to condition check
        gen.builder.insertPoint.block = exitBlock  // move past -- we're done
    }
}

extension TypeDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        let alias = module.getOrInsert(type: type)
        
        for i in initialisers {
            try i.emitStmt(module: module, gen: &gen)
        }
        
        for method in methods {
            guard let t = method.typeRepr.type, let mangledName = method.mangledName else { fatalError() }
            try module.getOrInsertFunction(named: mangledName, type: t, attrs: method.attrs)
        }
        for m in methods {
            try m.emitStmt(module: module, gen: &gen)
        }
        
        alias.destructor = try emitImplicitDestructorDecl(module: module)
        alias.copyConstructor = try emitImplicitCopyConstructorDecl(module: module)
    }
}


extension ConceptDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        module.getOrInsert(type: type)
        
        for m in requiredMethods {
            try m.emitStmt(module: module, gen: &gen)
        }
    }
    
}

extension InitDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: inout VIRGenFunction) throws {
        guard let initialiserType = typeRepr.type,
            case let selfType as StructType = parent?.declaredType,
            let mangledName = self.mangledName else {
                throw VIRError.noType(#file)
        }
        
        // if has body
        guard let impl = impl else {
            try gen.builder.buildFunctionPrototype(name: mangledName, type: initialiserType)
            return
        }
        
        let originalInsertPoint = gen.builder.insertPoint
        
        // make function and move into it
        let function = try gen.builder.buildFunction(name: mangledName, type: initialiserType, paramNames: impl.params)
        gen.builder.insertPoint.function = function
        
        function.inlineRequirement = .always
        
        // make scope and occupy it with params
        let fnScope = VIRGenScope(parent: scope, function: function)
        
        let selfVar: IndirectAccessor
        
        if selfType.isHeapAllocated {
            selfVar = try RefCountedAccessor.allocObject(type: selfType, module: module)
        }
        else {
            selfVar = try gen.builder.build(inst: AllocInst(memType: selfType.importedType(in: module), irName: "self")).accessor
        }
        
        fnScope.insert(variable: selfVar, name: "self")
        
        // add self’s elements into the scope, whose accessors are elements of selfvar
        for member in selfType.members {
            let structElement = try gen.builder.build(inst: StructElementPtrInst(object: selfVar.lValueReference(),
                                                                                    property: member.name,
                                                                                    irName: member.name))
            fnScope.insert(variable: structElement.accessor, name: member.name)
        }
        
        // add the initialiser’s params
        for param in impl.params {
            try fnScope.insert(variable: function.param(named: param).accessor(), name: param)
        }
        
        // vir gen for body
        try impl.body.emitStmt(module: module, scope: fnScope)
        
        try fnScope.removeVariable(named: "self")?.releaseUnowned()
        
        let ret = try gen.builder.buildReturn(value: selfVar.getEscapingValue())
        try fnScope.releaseVariables(deleting: true)
//        try fnScope.emitDestructors(builder: gen.builder, return: ret)
        
        // move out of function
        gen.builder.insertPoint = originalInsertPoint
    }
}


extension MutationExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        
        let rval = try value.emitRValue(module: module, gen: &gen)
            .coercedAccessor(to: object._type, module: module)
        guard case let lhs as LValueEmitter = object else { fatalError() }
        
        // set the lhs to rval
        try lhs.emitLValue(module: module, gen: &gen).setValue(rval)
        
        return try VoidLiteralValue().accessor()
    }
    
}

extension MethodCallExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: inout VIRGenFunction) throws -> ManagedValue {
        
        // build self and args' values
        let argAccessors = try argOperands(module: module, gen: &gen)
        let args = try argAccessors.map { try $0.aggregateGetValue() }.map(Operand.init)
        defer {
            for accessor in argAccessors {
                try! accessor.releaseCoercionTemp()
            }
        }
        let selfVarAccessor = try object.emitRValue(module: module, gen: &gen)
        try selfVarAccessor.retain()
        
        guard let fnType = fnType else { fatalError() }
        
        // construct function call
        switch object._type {
        case is StructType:
            guard case .method = fnType.callingConvention else { fatalError() }
            let selfRef = try selfVarAccessor.referenceBacked().aggregateReference()
            
            let function = try module.getOrInsertFunction(named: mangledName, type: fnType)
            return try gen.builder.buildFunctionCall(function: function, args: [PtrOperand(selfRef)] + args).accessor()
            
        case let existentialType as ConceptType:
            
            let selfRef = try selfVarAccessor.referenceBacked().aggregateReference()
            
            // get the witness from the existential
            let fn = try gen.builder.build(inst: ExistentialWitnessInst(existential: selfRef,
                                                                           methodName: mangledName,
                                                                           existentialType: existentialType,
                                                                           irName: "witness"))
            guard case let fnType as FunctionType = fn.memType?.importedType(in: module) else { fatalError() }
            
            // get the instance from the existential
            let unboxedSelf = try gen.builder.build(inst: ExistentialProjectInst(existential: selfRef, irName: "unboxed"))
            // call the method by applying the opaque ptr to self as the first param
            return try gen.builder.buildFunctionApply(function: PtrOperand(fn),
                                                         returnType: fnType.returns,
                                                         args: [PtrOperand(unboxedSelf)] + args).accessor()
        default:
            fatalError()
        }

        
    }
}






