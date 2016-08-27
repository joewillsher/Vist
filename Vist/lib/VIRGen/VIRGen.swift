//
//  VIRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSString

protocol ValueEmitter {
    associatedtype ManagedEmittedType : ManagedValue
    /// Emit the get-accessor for a VIR rvalue
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> ManagedEmittedType
}
protocol _ValueEmitter {
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue
}


protocol StmtEmitter {
    /// Emit the VIR for an AST statement
    func emitStmt(module: Module, gen: VIRGenFunction) throws
}

protocol LValueEmitter : ValueEmitter {
    associatedtype ManagedEmittedType : ManagedValue
    /// Emit the get/set-accessor for a VIR lvalue
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> ManagedEmittedType
    func canEmitLValue(module: Module, gen: VIRGenFunction) throws -> Bool
}
protocol _LValueEmitter : _ValueEmitter {
    /// Emit the get/set-accessor for a VIR lvalue
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue
    func canEmitLValue(module: Module, gen: VIRGenFunction) throws -> Bool
}
extension LValueEmitter {
    func canEmitLValue(module: Module, gen: VIRGenFunction) throws -> Bool { return true }
}

/// A libaray without a main function can emit vir for this
protocol LibraryTopLevel: ASTNode {}

extension ASTNode {
    func emit(module: Module, gen: VIRGenFunction) throws {
        throw VIRError.notGenerator(self.dynamicType)
    }
}
extension ASTNode where Self : StmtEmitter {
    func emit(module: Module, gen: VIRGenFunction) throws {
        try emitStmt(module: module, gen: gen)
    }
}


extension Expr {
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        throw VIRError.notGenerator(self.dynamicType)
    }
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        throw VIRError.notGenerator(self.dynamicType)
    }
}
extension Expr where Self : ValueEmitter {
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        return (try emitRValue(module: module, gen: gen) as ManagedEmittedType).erased
    }
}
extension Expr where Self : LValueEmitter {
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        return (try emitLValue(module: module, gen: gen) as ManagedEmittedType).erased
    }
}


extension Collection where Iterator.Element == ASTNode {
    
    func emitBody(module: Module, gen: VIRGenFunction) throws {
        for x in self {
            try x.emit(module: module, gen: gen)
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
        
        let builder = module.builder!
        var gen = VIRGenFunction(scope: VIRGenScope(module: module),
                                 builder: builder)
        if isLibrary {
            // if its a library we dont emit a main, and just virgen on any decls/statements
            for case let g as LibraryTopLevel in exprs {
                try g.emit(module: module, gen: gen)
            }
        }
        else {
            let mainTy = FunctionType(params: [], returns: BuiltinType.void)
            _ = try builder.buildFunction(name: "main", type: mainTy, paramNames: [])
            
            try exprs.emitBody(module: module, gen: gen)
            
            try gen.cleanup()
            try builder.buildReturnVoid()
        }
        
    }
}



// MARK: Lower AST nodes to instructions

extension IntegerLiteral : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<StructInitInst> {
        let int = try gen.builder.build(IntLiteralInst(val: val, size: 64))
        return try gen.builder.buildManaged(StructInitInst(type: StdLib.intType, values: int), gen: gen)
    }
}

extension BooleanLiteral : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<StructInitInst> {
        let bool = try gen.builder.build(BoolLiteralInst(val: val))
        return try gen.builder.buildManaged(StructInitInst(type: StdLib.boolType, values: bool), gen: gen)
    }
}

extension StringLiteral : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<FunctionCallInst> {
        
        // string_literal lowered to:
        //  - make global string constant
        //  - GEP from it to get the first element
        //
        // String initialiser allocates %1 bytes of memory and stores %0 into it
        // String exposes methods to move buffer and change size
        // String `print` passes `base` into a cshim functions which print the buffer
        //    - wholly if its contiguous UTF8
        //    - char by char if it contains UTF16 code units
        
        var string = try gen.builder.buildManaged(StringLiteralInst(val: str), gen: gen)
        var length = try gen.builder.buildManaged(IntLiteralInst(val: str.utf8.count + 1, size: 64, irName: "size"), gen: gen)
        var isUTFU = try gen.builder.buildManaged(BoolLiteralInst(val: string.managedValue.isUTF8Encoded, irName: "isUTF8"), gen: gen)
        
        let paramTypes: [Type] = [BuiltinType.opaquePointer, BuiltinType.int(size: 64), BuiltinType.bool]
        let initName = "String".mangle(type: FunctionType(params: paramTypes, returns: StdLib.stringType, callingConvention: .initialiser))
        let initialiser = try module.getOrInsertStdLibFunction(mangledName: initName)!
        let std = try gen.builder.buildFunctionCall(function: initialiser,
                                                    args: [Operand(string.forward()), Operand(length.forward()), Operand(isUTFU.forward())])
        return Managed<FunctionCallInst>.forUnmanaged(std, gen: gen)
    }
}


extension VariableDecl : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<VariableAddrInst> {
        
        let type = value._type!.importedType(in: module)
        // gen the ManagedValue for the variable's value
        let val = try value.emitRValue(module: module, gen: gen)
        // alloc variable memory
        var alloc = try gen.emitTempAlloc(memType: type)
        // coeerce to the right type and forward the cleanup to the memory
        var managed = try val.coerce(to: type, gen: gen)
        try managed.forward(into: alloc, gen: gen) // forward the temp
        
        // create a variableaddr inst and forward the memory's cleanup onto it
        let variable = try gen.builder.buildManaged(VariableAddrInst(addr: alloc.forwardLValue(),
                                                                     mutable: isMutable,
                                                                     irName: name),
                                                    gen: gen)
        gen.managedValues.append(variable)
        return variable
    }
}

extension VariableGroupDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        for decl in declared {
            _ = try decl.emitRValue(module: module, gen: gen)
        }
    }
}

extension FunctionCall/*: ValueEmitter*/ {
    
    func argOperands(module: Module, gen: VIRGenFunction) throws -> [ManagedValue] {
        guard case let fnType as FunctionType = fnType?.importedType(in: module) else {
            throw VIRError.paramsNotTyped
        }
        
        return try zip(argArr, fnType.params).map { rawArg, paramType in
            let arg = try rawArg.emitRValue(module: module, gen: gen)
            return try arg.copy(gen: gen).coerce(to: paramType, gen: gen)
        }
    }
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        
        let argAccessors = try argOperands(module: module, gen: gen)
        let args = try argAccessors.map { try Operand($0.borrow().value) }
        
        if let stdlib = try module.getOrInsertStdLibFunction(mangledName: mangledName) {
            return try AnyManagedValue.forUnmanaged(gen.builder.buildFunctionCall(function: stdlib, args: args), gen: gen)
        }
        else if
            let prefixRange = name.range(of: "Builtin."),
            let instruction = BuiltinInst(rawValue: name.replacingCharacters(in: prefixRange, with: "")) {
            
            return try AnyManagedValue.forUnmanaged(gen.builder.build(BuiltinInstCall(inst: instruction, operands: args)), gen: gen)
        }
        else if let function = module.function(named: mangledName) {
            return try AnyManagedValue.forUnmanaged(gen.builder.buildFunctionCall(function: function, args: args), gen: gen)
        }
        else if let closure = gen.variable(named: name) {
            fatalError("TODO")
//            // If we only have an accessor, get the value from it, which must be a function* type
//            // because the only case this is allowed is GEPing a struct
//            // Otherwise we just get the lvalue from the byval accessor
//            let ref = (closure is IndirectAccessor ?
//                try! OpaqueLValue(rvalue: closure.aggregateGetValue()) :
//                try closure.getValue()) as! LValue
//            
//            guard case let ret as FunctionType = ref.memType?.importedType(in: module) else { fatalError() }
//            
//            return try gen.builder.buildFunctionApply(function: PtrOperand(ref),
//                                                      returnType: ret.returns,
//                                                      args: args)
        }
        else {
            fatalError("No function name=\(name), mangledName=\(mangledName)")
        }
    }
}

extension ClosureExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<FunctionRefInst> {
        
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
        let closureScope = VIRGenScope.capturing(parent: gen.scope,
                                                 function: closure.thunk,
                                                 captureDelegate: closure,
                                                 breakPoint: entry)
        var closureVGF = VIRGenFunction(scope: closureScope, builder: gen.builder)
        // add params
        for param in parameters! {
            let param = try closure.thunk.param(named: param).managed(gen: closureVGF)
            gen.managedValues.append(param)
        }
        // emit body
        try exprs.emitBody(module: module, gen: closureVGF)
        // move back out
        gen.builder.insertPoint = entry
        
        // return an accessor of the function reference
        return try gen.builder.buildManaged(FunctionRefInst(function: closure.thunk), gen: gen)
    }
}

extension FuncDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
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
            let param = try function.param(named: paramName).managed(gen: vgf)
            gen.managedValues.append(param)
        }
        // A method calling convention means we have to pass `self` in, and tell vars how
        // to access it, and `self`’s properties
        if case .method(let selfType, _) = type.callingConvention {
            // We need self to be passed by ref as a `RefParam`
            let selfParam = function.params![0] as! RefParam
            let selfVar = Managed<RefParam>.forLValue(selfParam, gen: vgf)
            vgf.managedValues.append(selfVar)
            
            guard case let type as NominalType = selfType else { fatalError() }
            
            // if it is a ref self the self accessors are lazily calculated struct GEP
            if selfVar.isIndirect {
                for property in type.members {
                    let pVar = try vgf.builder.buildManaged(StructElementPtrInst(object: selfVar.lValue,
                                                                                 property: property.name,
                                                                                 irName: property.name),
                                                            gen: vgf)
                    vgf.managedValues.append(pVar)
                }
                // If it is a value self then we do a struct extract to get self elements
                // case is Accessor:
            } else {
                for property in type.members {
                    let pVar = try vgf.builder.buildManaged(StructExtractInst(object: selfVar.value,
                                                                              property: property.name,
                                                                              irName: property.name),
                                                            gen: vgf)
                    vgf.managedValues.append(pVar)
                }
            }
        }
        
        // vir gen for body
        try impl.body.emitStmt(module: module, gen: vgf)
        
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
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        return gen.variable(named: name)!
    }
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        return gen.variable(named: name)!
    }
    
    func canEmitLValue(module: Module, gen: VIRGenFunction) throws -> Bool {
        return gen.variable(named: name)?.managedValue is LValue
    }
}

extension ReturnStmt : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<ReturnInst> {
        let retVal = try expr.emitRValue(module: module, gen: gen)
        // coerce to expected return type, managing abstraction differences
        var boxed = try retVal.coerce(to: expectedReturnType!, gen: gen)
        // forward clearup to caller function
        return try gen.builder.buildManagedReturn(value: boxed.forward(), gen: gen)
    }
}

extension TupleExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<TupleCreateInst> {
        
        guard let type = try _type?.importedType(in: module).getAsTupleType() else {
            throw VIRError.noType(#file)
        }
        let elements = try self.elements.map {
            try $0.emitRValue(module: module, gen: gen)
                .coerce(to: $0._type!, gen: gen).forward()
            // forward the clearup to the tuple
        }
        
        return try gen.builder.buildManaged(TupleCreateInst(type: type, elements: elements), gen: gen)
    }
}

extension TupleMemberLookupExpr : ValueEmitter, LValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        let tuple = try object.emitRValue(module: module, gen: gen)
        
        if tuple.isIndirect {
            return try gen.builder.buildManaged(TupleElementPtrInst(tuple: tuple.value, index: index))
        }
        else {
            let tuplePtr = try tuple.coerce(to: tuple.object._type!.ptrType(), gen: gen)
            return try gen.builder.buildManaged(TupleExtractInst(tuple: tuplePtr.lValue,
                                                                 index: index),
                                                gen: gen)
        }
    }
    
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> Managed<TupleElementPtrInst> {
        let tuple = try o.emitLValue(module: module, gen: gen)
        return try gen.builder.build(TupleElementPtrInst(tuple: tuple.lValueReference(), index: index)).accessor
    }
}

extension PropertyLookupExpr : LValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        
        switch object._type {
        case is StructType:
            switch object {
            case let lValEmitter as _LValueEmitter
                where try lValEmitter.canEmitLValue(module: module, gen: gen):
                // if self is backed by a ptr, do a GEP then load
                let object = try lValEmitter.emitLValue(module: module, gen: gen)
                let elPtr = try gen.builder.build(StructElementPtrInst(object: object.reference(), property: propertyName))
                return try gen.builder.build(LoadInst(address: elPtr))
            case let rValEmitter:
                // otherwise just get the struct element
                let object = try rValEmitter.emitRValue(module: module, gen: gen)
                return try gen.builder.build(StructExtractInst(object: object.getValue(), property: propertyName))
            }
            
        case is ConceptType:
            let object = try self.object.emitRValue(module: module, gen: gen).referenceBacked().reference()
            let ptr = try gen.builder.build(ExistentialProjectPropertyInst(existential: object, propertyName: propertyName))
            return try gen.builder.build(LoadInst(address: ptr))
            
        default:
            fatalError()
        }
    }
    
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        guard case let o as _LValueEmitter = self.object else { fatalError() }
        let object = try o.emitLValue(module: module, gen: gen).lValueReference()
        
        switch self.object._type {
        case is StructType:
            return try gen.builder.build(StructElementPtrInst(object: object, property: propertyName)).accessor
            
        case is ConceptType:
            return try gen.builder.build(ExistentialProjectPropertyInst(existential: object, propertyName: propertyName)).accessor
            
        default:
            fatalError()
        }
        
    }
    
    func canEmitLValue(module: Module, gen: VIRGenFunction) throws -> Bool {
        guard case let o as _LValueEmitter = object else { fatalError() }
        switch object._type {
        case is StructType: return try o.canEmitLValue(module: module, gen: gen)
        case is ConceptType: return true
        default: fatalError()
        }
    }
    
}

extension BlockExpr : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        try exprs.emitBody(module: module, gen: gen)
    }
}

extension ConditionalStmt : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
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
                var cond = try c.emitRValue(module: module, gen: gen).coerceToValue(gen: gen)
                let v = try gen.builder.build(StructExtractInst(object: cond.forward(), property: "value"))
                
                let bodyBlock = try gen.builder.appendBasicBlock(name: branch.condition == nil ? "\(base)else\(index)" : "\(base)true\(index)")
                try backedgeBlock.move(after: bodyBlock)
                
                try gen.builder.buildCondBreak(if: Operand(v),
                                               to: (block: bodyBlock, args: nil),
                                               elseTo: (block: backedgeBlock, args: nil))
                gen.builder.insertPoint.block = bodyBlock
            }
            
            // move into the if block, and evaluate its expressions
            // in a new scope
            let ifScope = VIRGenScope(parent: gen.scope, function: gen.scope.function)
            var ifVGF = VIRGenFunction(scope: ifScope, builder: gen.builder)
            try branch.block.emitStmt(module: module, gen: ifVGF)
            
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
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
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
        let loopScope = VIRGenScope.capturing(parent: gen.scope,
                                              function: loopClosure.thunk,
                                              captureDelegate: loopClosure,
                                              breakPoint: gen.builder.insertPoint)
        var loopGen = VIRGenFunction(scope: loopScope, builder: gen.builder)
        let loopVar = try loopClosure.thunk.param(named: binded.name).managed(gen: gen)
        loopGen.managedValues.append(loopVar)
        
        // emit body for loop thunk
        gen.builder.insertPoint.function = loopClosure.thunk // move to loop thunk
        try block.emitStmt(module: module, gen: loopGen)
        try gen.builder.buildReturnVoid()
        
        // move back out
        gen.builder.insertPoint = entryInsertPoint
        
        // require that we inline the loop thunks early
        loopClosure.thunk.inlineRequirement = .always
        generatorClosure.thunk.inlineRequirement = .always
        
        // get the instance of the generator
        let generator = try self.generator.emitRValue(module: module, gen: gen)
            .coerce(to: self.generator._type!.ptrType(), gen: gen)
        
        // call the generator function from loop position
        // apply the scope it requests
        let call = try gen.builder.buildFunctionCall(function: generatorClosure.thunk,
                                                     args: [PtrOperand(generator.forwardLValue()), loopClosure.thunk.buildFunctionPointer()])
        
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
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
        guard case let loopThunk as RefParam = gen.builder.insertPoint.function?.params?[1] else {
            fatalError()
        }
        
        let val = try expr.emitRValue(module: module, gen: gen)
        let param = try val.aggregateGetValue()
        
        try gen.builder.buildFunctionApply(function: PtrOperand(loopThunk), returnType: BuiltinType.void, args: [Operand(param)])
    }
}


extension WhileLoopStmt : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
        // setup blocks
        let condBlock = try gen.builder.appendBasicBlock(name: "cond")
        let loopBlock = try gen.builder.appendBasicBlock(name: "loop")
        let exitBlock = try gen.builder.appendBasicBlock(name: "loop.exit")
        
        // condition check in cond block
        try gen.builder.buildBreak(to: condBlock)
        gen.builder.insertPoint.block = condBlock
        
        let condBool = try condition.emitRValue(module: module, gen: gen).forward().value
        let cond = try gen.builder.build(StructExtractInst(object: condBool, property: "value", irName: "cond"))
        
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
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        let alias = module.getOrInsert(type: type)
        
        for i in initialisers {
            try i.emitStmt(module: module, gen: gen)
        }
        
        for method in methods {
            guard let t = method.typeRepr.type, let mangledName = method.mangledName else { fatalError() }
            try module.getOrInsertFunction(named: mangledName, type: t, attrs: method.attrs)
        }
        for m in methods {
            try m.emitStmt(module: module, gen: gen)
        }
        
        alias.destructor = try emitImplicitDestructorDecl(module: module)
        alias.copyConstructor = try emitImplicitCopyConstructorDecl(module: module)
    }
}


extension ConceptDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
        guard let type = type else { throw irGenError(.notTyped) }
        
        module.getOrInsert(type: type)
        
        for m in requiredMethods {
            try m.emitStmt(module: module, gen: gen)
        }
    }
    
}

extension InitDecl : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
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
            selfVar = try gen.builder.build(AllocInst(memType: selfType.importedType(in: module), irName: "self")).accessor
        }
        
        fnScope.insert(variable: selfVar, name: "self")
        
        // add self’s elements into the scope, whose accessors are elements of selfvar
        for member in selfType.members {
            let structElement = try gen.builder.build(StructElementPtrInst(object: selfVar.lValueReference(),
                                                                           property: member.name,
                                                                           irName: member.name))
            fnScope.insert(variable: structElement.accessor, name: member.name)
        }
        
        // add the initialiser’s params
        for param in impl.params {
            try fnScope.insert(variable: function.param(named: param), name: param)
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
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<VoidLiteralValue> {
        
        guard case let lhs as _LValueEmitter = object else { fatalError() }
        let lval = try lhs.emitLValue(module: module, gen: gen)
        
        // create a copy with its own clearup
        var rval = try value.emitRValue(module: module, gen: gen)
            .coerce(to: lval.rawType, gen: gen)
        // the lhs takes over the clearup of the temp
        try rval.forward(into: lval, gen: gen)
        
        return Managed<VoidLiteralValue>.forUnmanaged(VoidLiteralValue(), gen: gen)
    }
    
}

extension MethodCallExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        
        // build self and args' values
        let argAccessors = try argOperands(module: module, gen: gen)
        let args = try argAccessors.map { try $0.aggregateGetValue() }.map(Operand.init)
        defer {
            for accessor in argAccessors {
                try! accessor.releaseCoercionTemp()
            }
        }
        let selfVarAccessor = try object.emitRValue(module: module, gen: gen)
        try selfVarAccessor.retain()
        
        guard let fnType = fnType else { fatalError() }
        
        // construct function call
        switch object._type {
        case is StructType:
            guard case .method = fnType.callingConvention else { fatalError() }
            let selfRef = try selfVarAccessor.referenceBacked().aggregateReference()
            
            let function = try module.getOrInsertFunction(named: mangledName, type: fnType)
            return try gen.builder.buildFunctionCall(function: function, args: [PtrOperand(selfRef)] + args)
            
        case let existentialType as ConceptType:
            
            let selfRef = try selfVarAccessor.referenceBacked().aggregateReference()
            
            // get the witness from the existential
            let fn = try gen.builder.build(ExistentialWitnessInst(existential: selfRef,
                                                                  methodName: mangledName,
                                                                  existentialType: existentialType,
                                                                  irName: "witness"))
            guard case let fnType as FunctionType = fn.memType?.importedType(in: module) else { fatalError() }
            
            // get the instance from the existential
            let unboxedSelf = try gen.builder.build(ExistentialProjectInst(existential: selfRef, irName: "unboxed"))
            // call the method by applying the opaque ptr to self as the first param
            return try gen.builder.buildFunctionApply(function: PtrOperand(fn),
                                                      returnType: fnType.returns,
                                                      args: [PtrOperand(unboxedSelf)] + args)
        default:
            fatalError()
        }
        
        
    }
}






