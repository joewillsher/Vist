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

protocol LValueEmitter : ValueEmitter, _LValueEmitter {
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
extension _LValueEmitter where Self : LValueEmitter {
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        return (try emitLValue(module: module, gen: gen) as ManagedEmittedType).erased
    }
    func canEmitLValue(module: Module, gen: VIRGenFunction) throws -> Bool {
        return try canEmitLValue(module: module, gen: gen)
    }
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
extension ASTNode where Self : ValueEmitter {
    func emit(module: Module, gen: VIRGenFunction) throws {
        _ = try emitRValue(module: module, gen: gen)
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
        let gen = VIRGenFunction(scope: VIRGenScope(module: module),
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
        return try gen.builder.buildUnmanaged(StructInitInst(type: StdLib.intType, values: int), gen: gen)
    }
}

extension BooleanLiteral : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<StructInitInst> {
        let bool = try gen.builder.build(BoolLiteralInst(val: val))
        return try gen.builder.buildUnmanaged(StructInitInst(type: StdLib.boolType, values: bool), gen: gen)
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
        
        var string = try gen.builder.buildUnmanaged(StringLiteralInst(val: str), gen: gen)
        var length = try gen.builder.buildUnmanaged(IntLiteralInst(val: str.utf8.count + 1, size: 64, irName: "size"), gen: gen)
        var isUTFU = try gen.builder.buildUnmanaged(BoolLiteralInst(val: string.managedValue.isUTF8Encoded, irName: "isUTF8"), gen: gen)
        
        let paramTypes: [Type] = [BuiltinType.opaquePointer, BuiltinType.int(size: 64), BuiltinType.bool]
        let initName = "String".mangle(type: FunctionType(params: paramTypes, returns: StdLib.stringType, callingConvention: .initialiser))
        let initialiser = try module.getOrInsertStdLibFunction(mangledName: initName)!
        let std = try gen.builder.buildFunctionCall(function: initialiser,
                                                    args: [Operand(string.forward(gen)), Operand(length.forward(gen)), Operand(isUTFU.forward(gen))])
        return Managed<FunctionCallInst>.forUnmanaged(std, gen: gen)
    }
}


extension VariableDecl : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<VariableAddrInst> {
        
        guard let type = self.type?.importedType(in: module), let value = self.value else {
            fatalError()
        }
        
        // gen the ManagedValue for the variable's value
        var managed = try value.emitRValue(module: module, gen: gen)
        // coeerce to the correct type (as a pointer) and forward
        // the cleanup to the memory
        try managed.forwardCoerce(to: type.ptrType(), gen: gen)
        
        // create a variableaddr inst and forward the memory's cleanup onto it
        let variable = try gen.builder.build(VariableAddrInst(addr: managed.lValue,
                                                              mutable: isMutable,
                                                              irName: name))
        let m = Managed<VariableAddrInst>.forManaged(variable, hasCleanup: false, gen: gen)
        gen.addVariable(m, name: name)
        return m
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
    
    func argOperands(module: Module, gen: VIRGenFunction) throws -> [Operand] {
        guard case let fnType as FunctionType = fnType?.importedType(in: module) else {
            throw VIRError.paramsNotTyped
        }
        
        return try zip(argArr, fnType.cannonicalisedParamTypes()).map { rawArg, paramType in
            var arg = try rawArg.emitRValue(module: module, gen: gen)
            var copy = try arg.coerceCopy(to: paramType, gen: gen)
            return Operand(copy.forward(gen))
        }
    }
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        
        let args = try argOperands(module: module, gen: gen)
        
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
        else if let closure = try gen.variable(named: name) {
            
            guard case let fnType as FunctionType = closure.type.getBasePointeeType().importedType(in: module) else {
                fatalError()
            }
            // we can always just forward the function's clearup; it will never have any
            var coerced = closure.erased
            try coerced.forwardCoerce(to: fnType.ptrType(), gen: gen)
            
            let apply = try gen.builder.buildFunctionApply(function: PtrOperand(coerced.lValue),
                                                           returnType: fnType.returns,
                                                           args: args)
            return AnyManagedValue.forUnmanaged(apply, gen: gen)
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
        let closureVGF = VIRGenFunction(scope: closureScope, builder: gen.builder)
        // add params
        for paramName in parameters! {
            let param = try closure.thunk.param(named: paramName).managed(gen: closureVGF)
            gen.addVariable(param, name: paramName)
        }
        // emit body
        try exprs.emitBody(module: module, gen: closureVGF)
        
        if type.returns == BuiltinType.void && !thunk.instructions.contains(where: {$0 is ReturnInst}) {
            try closureVGF.cleanup()
            try closureVGF.builder.buildReturnVoid()
        }
        // move back out
        gen.builder.insertPoint = entry
        
        // return an accessor of the function reference
        return try gen.builder.buildUnmanaged(FunctionRefInst(function: closure.thunk), gen: gen)
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
        let vgf = VIRGenFunction(scope: fnScope, builder: gen.builder)
        
        // add the explicit method parameters
        for paramName in impl.params {
            let param = try function.param(named: paramName).managed(gen: vgf)
            vgf.addVariable(param, name: paramName)
        }
        // A method calling convention means we have to pass `self` in, and tell vars how
        // to access it, and `self`’s properties
        if case .method(let selfType, _) = type.callingConvention {
            // We need self to be passed by ref as a `RefParam`
            let selfParam = function.params![0] as! RefParam
            let selfVar = Managed<RefParam>.forLValue(selfParam, gen: vgf)
            vgf.addVariable(selfVar, name: "self")
            
            guard case let type as NominalType = selfType else { fatalError() }
            
            // if it is a ref self the self accessors are lazily calculated struct GEP
            if selfVar.isIndirect {
                for property in type.members {
                    let pVar = try vgf.builder.buildUnmanaged(StructElementPtrInst(object: selfVar.lValue,
                                                                                   property: property.name,
                                                                                   irName: property.name),
                                                              gen: vgf)
                    vgf.addVariable(pVar, name: property.name)
                }
                // If it is a value self then we do a struct extract to get self elements
                // case is Accessor:
            } else {
                for property in type.members {
                    let pVar = try vgf.builder.buildUnmanaged(StructExtractInst(object: selfVar.value,
                                                                                property: property.name,
                                                                                irName: property.name),
                                                              gen: vgf)
                    vgf.addVariable(pVar, name: property.name)
                }
            }
        }
        
        // vir gen for body
        try impl.body.emitStmt(module: module, gen: vgf)
        
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
        return try gen.variable(named: name)!.erased
    }
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        return try gen.variable(named: name)!.erased
    }
    
    func canEmitLValue(module: Module, gen: VIRGenFunction) throws -> Bool {
        return try gen.variable(named: name)?.isIndirect ?? false
    }
}

extension ReturnStmt : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        var retVal = try expr.emitRValue(module: module, gen: gen)
        // coerce to expected return type, managing abstraction differences
        var boxed = try retVal.coerceCopy(to: expectedReturnType!, gen: gen)
        try gen.cleanup()
        // forward clearup to caller function
        try gen.builder.buildReturn(value: boxed.forward(gen))
    }
}

extension TupleExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> Managed<TupleCreateInst> {
        
        guard let type = try _type?.importedType(in: module).getAsTupleType() else {
            throw VIRError.noType(#file)
        }
        let elements = try self.elements.map { el -> Value in
            var managed = try el.emitRValue(module: module, gen: gen)
            try managed.forwardCoerceToValue(gen: gen)
            // forward the clearup to the tuple
            return managed.forward(gen)
        }
        
        return try gen.builder.buildUnmanaged(TupleCreateInst(type: type, elements: elements), gen: gen)
    }
}

extension TupleMemberLookupExpr : ValueEmitter, LValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        var tuple = try object.emitRValue(module: module, gen: gen)
        
        if tuple.isIndirect {
            let tuplePtr = try tuple.coerceCopy(to: object._type!.ptrType(), gen: gen)
            return try gen.builder.buildUnmanaged(TupleElementPtrInst(tuple: tuplePtr.lValue,
                                                                      index: index),
                                                  gen: gen).erased
        }
        else {
            var copy = try tuple.coerceCopyToValue(gen: gen)
            return try gen.builder.buildUnmanaged(TupleExtractInst(tuple: copy.forward(gen),
                                                                   index: index),
                                                  gen: gen).erased
        }
    }
    
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> Managed<TupleElementPtrInst> {
        guard case let o as _LValueEmitter = object else { fatalError() }
        var tuple = try o.emitLValue(module: module, gen: gen)
        assert(tuple.isIndirect)
        let tuplePtr = try tuple.coerceCopy(to: object._type!.ptrType(), gen: gen)
        return try gen.builder.buildUnmanagedLValue(TupleElementPtrInst(tuple: tuplePtr.lValue,
                                                                        index: index),
                                                    gen: gen)
    }
}

extension PropertyLookupExpr : LValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        
        switch object._type {
        case let ty as StructType:
            switch object {
            case let lValEmitter as _LValueEmitter
                where try lValEmitter.canEmitLValue(module: module, gen: gen):
                
                // if self is backed by a ptr, do a GEP then load
                var object = try lValEmitter.emitLValue(module: module, gen: gen)
                try object.forwardCoerce(to: ty.ptrType(), gen: gen)
                
                var elPtr = try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: object.lValue,
                                                                                      property: propertyName),
                                                                 gen: gen)
                return try gen.builder.buildManaged(LoadInst(address: elPtr.forwardLValue(gen)), gen: gen).erased
                
            case let rValEmitter:
                // otherwise just get the struct element
                var object = try rValEmitter.emitRValue(module: module, gen: gen)
                return try gen.builder.buildManaged(StructExtractInst(object: object.forward(gen),
                                                                      property: propertyName),
                                                    gen: gen).erased
            }
            
        case let ex as ConceptType:
            var object = try self.object.emitRValue(module: module, gen: gen)
            try object.forwardCoerce(to: ex.ptrType(), gen: gen)
            
            var ptr = try gen.builder.buildUnmanagedLValue(ExistentialProjectPropertyInst(existential: object.lValue,
                                                                                          propertyName: propertyName),
                                                           gen: gen)
            return try gen.builder.buildManaged(LoadInst(address: ptr.forward(gen)), gen: gen).erased
            
        default:
            fatalError()
        }
    }
    
    func emitLValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        guard case let o as _LValueEmitter = self.object else { fatalError() }
        
        var object = try o.emitLValue(module: module, gen: gen)
        try object.forwardCoerce(to: self.object._type!.ptrType(), gen: gen)
        
        switch self.object._type {
        case is StructType:
            return try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: object.lValue,
                                                                             property: propertyName),
                                                        gen: gen).erased
        case is ConceptType:
            return try gen.builder.buildUnmanagedLValue(ExistentialProjectPropertyInst(existential: object.lValue,
                                                                                       propertyName: propertyName),
                                                        gen: gen).erased
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

extension CoercionExpr {
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        var val = try base.emitRValue(module: module, gen: gen)
        try val.forwardCoerce(to: _type!.importedType(in: module), gen: gen)
        return val
    }
}
extension ImplicitCoercionExpr {
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        var val = try expr.emitRValue(module: module, gen: gen)
        try val.forwardCoerce(to: type.importedType(in: module), gen: gen)
        return val
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
            
            // move into the if block, and evaluate its expressions
            // in a new scope
            let ifScope = VIRGenScope(parent: gen.scope, function: gen.scope.function)
            let ifVGF = VIRGenFunction(scope: ifScope, builder: gen.builder)
            
            switch branch.condition {
            case .boolean(let c):
                var cond = try c.emitRValue(module: module, gen: gen)
                try cond.forwardCoerceToValue(gen: gen)
                let v = try gen.builder.build(StructExtractInst(object: cond.forward(gen), property: "value"))
                
                let bodyBlock = try gen.builder.appendBasicBlock(name: "\(base)true\(index)")
                try backedgeBlock.move(after: bodyBlock)
                
                try gen.builder.buildCondBreak(if: Operand(v),
                                               to: (block: bodyBlock, args: nil),
                                               elseTo: (block: backedgeBlock, args: nil))
                gen.builder.insertPoint.block = bodyBlock
            case .typeMatch(let match):
                var val = try match.boundExpr.emitRValue(module: module, gen: gen)
                try val.forwardCoerce(to: val.type.ptrType(), gen: gen)
                
                let targetType = match._type!.importedType(in: module)
                var castParam = Managed<Param>.forUnmanaged(Param(paramName: match.variable, type: targetType),
                                                            gen: ifVGF)
                ifVGF.addVariable(castParam, name: match.variable)
                
                let bodyBlock = try gen.builder.appendBasicBlock(name: "\(base)cast\(index)", parameters: [castParam.managedValue])
                try backedgeBlock.move(after: bodyBlock)
                
                try gen.builder.buildCastBreak(val: PtrOperand(val.forwardLValue(gen)),
                                               successVariable: castParam.forward(gen),
                                               targetType: targetType,
                                               success: (block: bodyBlock, args: nil),
                                               fail: (block: backedgeBlock, args: nil))
                gen.builder.insertPoint.block = bodyBlock
                
            default:
                break
            }
            
            try branch.block.emitStmt(module: module, gen: ifVGF)
            
            // once we're done in success, break to the exit and
            // move into the fail for the next round
            if !(gen.builder.insertPoint.block?.instructions.last?.isTerminator ?? false) {
                try ifVGF.cleanup()
                try ifVGF.builder.buildBreak(to: exitBlock)
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
        let loopGen = VIRGenFunction(scope: loopScope, builder: gen.builder)
        let loopVar = try loopClosure.thunk.param(named: binded.name).managed(gen: gen)
        loopGen.addVariable(loopVar, name: binded.name)
        
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
        var generator = try self.generator.emitRValue(module: module, gen: gen)
        var input = try generator.coerceCopy(to: self.generator._type!.ptrType(), gen: gen)
        
        // call the generator function from loop position
        // apply the scope it requests
        let call = try gen.builder.buildFunctionCall(function: generatorClosure.thunk,
                                                     args: [PtrOperand(input.forwardLValue(gen)), loopClosure.thunk.buildFunctionPointer()])
        
        if let entryInst = entryInsertPoint.inst, let entryFunction = entryInsertPoint.function {
            // set the captured global values' lifetimes
            for captured in loopClosure.capturedGlobals {
                captured.lifetime = GlobalValue.Lifetime(start: entryInst,
                                                         end: call,
                                                         globalName: captured.globalName,
                                                         owningFunction: entryFunction)
            }
        }
        
        try loopGen.cleanup()
    }
}


extension YieldStmt : StmtEmitter {
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
        guard case let loopThunk as RefParam = gen.builder.insertPoint.function?.params?[1] else {
            fatalError()
        }
        
        var val = try expr.emitRValue(module: module, gen: gen)
        let param = try val.coerceCopy(to: expr._type!, gen: gen)
        
        try gen.builder.buildFunctionApply(function: PtrOperand(loopThunk),
                                           returnType: BuiltinType.void,
                                           args: [Operand(param.borrow().value)])
    }
}


extension WhileLoopStmt : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        
        // setup blocks
        let base = gen.builder.insertPoint.block?.name.appending(".") ?? ""
        let condBlock = try gen.builder.appendBasicBlock(name: "\(base)loop.cond")
        let loopBlock = try gen.builder.appendBasicBlock(name: "\(base)loop.body")
        let exitBlock = try gen.builder.appendBasicBlock(name: "\(base)loop.exit")
        
        // condition check in cond block
        try gen.builder.buildBreak(to: condBlock)
        gen.builder.insertPoint.block = condBlock
        
        var condBool = try condition.emitRValue(module: module, gen: gen)
        let cond = try gen.builder.build(StructExtractInst(object: condBool.forward(gen), property: "value", irName: "cond"))
        
        // cond break into/past loop
        try gen.builder.buildCondBreak(if: Operand(cond),
                                       to: (block: loopBlock, args: nil),
                                       elseTo: (block: exitBlock, args: nil))
        
        let loopScope = VIRGenScope(parent: gen.scope, function: gen.scope.function)
        let loopVGF = VIRGenFunction(scope: loopScope, builder: gen.builder)
        // build loop block
        gen.builder.insertPoint.block = loopBlock // move into
        try block.emitStmt(module: module, gen: loopVGF) // gen stmts
        try loopVGF.cleanup()
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
        
        alias.destructor = try emitImplicitDestructorDecl(module: module, gen: gen)
        alias.copyConstructor = try emitImplicitCopyConstructorDecl(module: module, gen: gen)
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
        let fnScope = VIRGenScope(parent: gen.scope, function: function)
        let fnVGF = VIRGenFunction(scope: fnScope, builder: gen.builder)
        
        var selfVar: AnyManagedValue
        
        if selfType.isHeapAllocated {
            selfVar = try module.builder.buildManaged(AllocObjectInst(memType: selfType, irName: "storage"),
                                                      hasCleanup: false,
                                                      gen: fnVGF).erased
        }
        else {
            selfVar = try gen.builder.buildManaged(AllocInst(memType: selfType.importedType(in: fnVGF.module)),
                                                   hasCleanup: false,
                                                   gen: fnVGF).erased
        }
        
        fnVGF.addVariable(selfVar, name: "self")
        
        // add self’s elements into the scope, whose accessors are elements of selfvar
        for member in selfType.members {
            let structElement = try fnVGF.builder.buildUnmanagedLValue(StructElementPtrInst(object: selfVar.lValue,
                                                                                            property: member.name,
                                                                                            irName: member.name), gen: fnVGF)
            fnVGF.addVariable(structElement, name: member.name)
        }
        
        // add the initialiser’s params
        for param in impl.params {
            try fnVGF.addVariable(function.param(named: param).managed(gen: fnVGF), name: param)
        }
        
        // vir gen for body
        try impl.body.emitStmt(module: module, gen: fnVGF)
        
        // forward the return val
        try selfVar.forwardCoerceToValue(gen: fnVGF)
        let val = selfVar.forward(gen)
        // cleanup the scope and return
        try fnVGF.cleanup()
        try fnVGF.builder.buildReturn(value: val)
        
        // move out of function
        gen.builder.insertPoint = originalInsertPoint
    }
}


extension MutationExpr : StmtEmitter {
    
    func emitStmt(module: Module, gen: VIRGenFunction) throws {
        guard case let lhs as _LValueEmitter = object else { fatalError() }
        var lval = try lhs.emitLValue(module: module, gen: gen)
        
        // create a copy with its own clearup
        var rval = try value.emitRValue(module: module, gen: gen).erased
        // the lhs takes over the clearup of the temp
        try rval.forwardCoerce(to: lval.rawType, gen: gen)
        try rval.forward(into: &lval, gen: gen)
    }
    
}

extension MethodCallExpr : ValueEmitter {
    
    func emitRValue(module: Module, gen: VIRGenFunction) throws -> AnyManagedValue {
        guard let fnType = fnType else { fatalError() }
        
        // build self and args' values
        let args = try argOperands(module: module, gen: gen)
        var selfRef = try object.emitRValue(module: module, gen: gen)
        let selfVal = try selfRef.coerceCopy(to: object._type!.ptrType(), gen: gen)

        // construct function call
        switch object._type {
        case is StructType:
            guard case .method = fnType.callingConvention else { fatalError() }
            
            let function = try module.getOrInsertFunction(named: mangledName, type: fnType)
            let call = try gen.builder.buildFunctionCall(function: function, args: [PtrOperand(selfVal.borrow().lValue)] + args)
            return AnyManagedValue.forUnmanaged(call, gen: gen)
            
        case let existentialType as ConceptType:
            
            // get the witness from the existential
            let fn = try gen.builder.build(ExistentialWitnessInst(existential: selfVal.borrow().lValue,
                                                                  methodName: mangledName,
                                                                  existentialType: existentialType,
                                                                  irName: "witness"))
            guard case let fnType as FunctionType = fn.memType?.importedType(in: module) else { fatalError() }
            
            // get the instance from the existential
            let unboxedSelf = try gen.builder.build(ExistentialProjectInst(existential: selfVal.borrow().lValue, irName: "unboxed"))
            // call the method by applying the opaque ptr to self as the first param
            let call = try gen.builder.buildFunctionApply(function: PtrOperand(fn),
                                                          returnType: fnType.returns,
                                                          args: [PtrOperand(unboxedSelf)] + args)
            return AnyManagedValue.forUnmanaged(call, gen: gen)
            
        default:
            fatalError()
        }
        
        
    }
}

