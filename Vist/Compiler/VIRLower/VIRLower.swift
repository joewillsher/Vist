//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRLowerError: VistError {
    case notLowerable( Value)
    
    var description: String {
        switch self {
        case .notLowerable(let v): return "value '\(v.vir)' is not Lowerable"
        }
    }
}


// Extends LLVM bool to be initialisable from bool literal, and usable
// as condition
extension LLVMBool : BooleanType, BooleanLiteralConvertible {
    
    public init(booleanLiteral value: Bool) {
        self.init(value ? 1: 0)
    }
    
    public var boolValue: Bool {
        return self == 1
    }
}



typealias IRGenFunction = (builder: LLVMBuilder, module: LLVMModule)

protocol VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue
}

extension Module {
    
    /// Creates or gets a function pointer
    private func getOrAddFunction(named name: String, type: FunctionType, IGF: IRGenFunction) -> LLVMFunction {
        // if already defined, we return it
        if let f = IGF.module.function(named: name) {
            return f
        }
        
        // otherwise we create a new prototype
        return LLVMFunction(name: name, type: LLVMType(ref: type.lowerType(module)), module: IGF.module)
    }
    
    func getOrAddRuntimeFunction(named name: String, IGF: IRGenFunction) -> LLVMFunction {
        let (_, fnType) = Runtime.function(mangledName: name)!
        return module.getOrAddFunction(named: name, type: fnType, IGF: IGF)
    }
    
    func virLower(module: LLVMModule, isStdLib: Bool) throws {
        
        let builder = LLVMBuilder()
        loweredBuilder = builder
        loweredModule = module
        let IGF = (builder, module) as IRGenFunction
        
        for fn in functions {
            // create function proto
            let function = getOrAddFunction(named: fn.name, type: fn.type, IGF: IGF)
            fn.loweredFunction = function
            
            // name the params
            for (i, p) in (fn.params ?? []).enumerate() where p.irName != nil {
                var param = try function.getParam(i)
                param.name = p.irName
            }
        }
        
        for global in globalValues {
            try global.updateUsesWithLoweredVal(global.virLower(IGF))
        }
        
        // lower the function bodies
        for fn in functions {
            try fn.virLower(IGF)
        }
        
        try validate()
    }
    
    private func validate() throws {
        var err = UnsafeMutablePointer<Int8>.alloc(1)
        guard !LLVMVerifyModule(loweredModule!.module, LLVMReturnStatusAction, &err) else {
            throw irGenError(.invalidModule(loweredModule!.module, String.fromCString(err)), userVisible: true)
        }
    }
}




extension Function : VIRLower {
    
    private func applyInline() throws {
        switch inline {
        case .`default`: break
        case .always: try loweredFunction?.addAttr(LLVMAlwaysInlineAttribute)
        case .never: try loweredFunction?.addAttr(LLVMNoInlineAttribute)
        }
    }
    private func applyVisibility() throws {
        switch visibility {
        case .`public`:
            loweredFunction?.visibility = LLVMDefaultVisibility
            loweredFunction?.linkage = LLVMExternalLinkage
        case .`internal`:
            loweredFunction?.visibility = LLVMDefaultVisibility
            loweredFunction?.linkage = LLVMExternalLinkage
        case .`private`:
            loweredFunction?.visibility = LLVMProtectedVisibility
            loweredFunction?.linkage = LLVMPrivateLinkage
        }
    }
    private func applyAttributes() throws {
        if attributes.contains(.noreturn) { try loweredFunction?.addAttr(LLVMNoReturnAttribute) }
        if attributes.contains(.readnone) { try loweredFunction?.addAttr(LLVMReadNoneAttribute) }
    }
    
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        
        let b = IGF.builder.getInsertBlock()
        guard let fn = IGF.module.function(named: name) else { fatalError() }
        
        // apply function attributes, linkage, and visibility
        try applyInline()
        try applyVisibility()
        try applyAttributes()
        
        // if no body, return
        guard let blocks = blocks else { return fn.function }
        
        // declare blocks, so break instructions have something to br to
        for bb in blocks {
            bb.loweredBlock = try fn.appendBasicBlock(named: bb.name)
            IGF.builder.positionAtEnd(bb.loweredBlock!)
            
            for param in bb.parameters ?? [] {
                let v = try param.virLower(IGF)
                param.updateUsesWithLoweredVal(v)
            }
        }
        
        for bb in blocks {
            IGF.builder.positionAtEnd(bb.loweredBlock!)
            
            for case let inst as protocol<VIRLower, Inst> in bb.instructions {
                let v = try inst.virLower(IGF)
                inst.updateUsesWithLoweredVal(v)
            }
        }
        
        // for the global values that declare their lifetime to exist
        // only in this scope, we define their lifetimes using intrinsics
        for lifetime in globalLifetimes {
            
        }
        
        if let b = b { IGF.builder.positionAtEnd(b) }
        
        try validate()
        
        return fn.function
    }
    
    private func validate() throws {
        guard !LLVMVerifyFunction(loweredFunction!.function._value, LLVMReturnStatusAction) else {
            #if DEBUG
            module.loweredModule.dump()
            #endif
            throw irGenError(.invalidFunction(name), userVisible: true)
        }
    }
}

extension BasicBlock {

    func loweredValForParamNamed(name: String, predBlock: BasicBlock) throws -> LLVMValue {
        guard let application = applications.find({$0.predecessor === predBlock}),
            case let blockOperand as BlockOperand = application.args?.find({$0.name == name}) else { throw VIRError.noFunctionBody }
        return blockOperand.loweredValue!
    }
    
}


extension Param : VIRLower {

    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        guard let function = parentFunction, block = parentBlock else { throw VIRError.noParentBlock }
        
        if let functionParamIndex = function.params?.indexOf({$0.name == name}) {
            return try function.loweredFunction!.getParam(functionParamIndex)
        }
        else if let phi = phi {
            return phi
        }
        else {
            let phi = try IGF.builder.buildPhi(type: type!.lowerType(module), name: paramName)
            
            for operand in try block.appliedArgs(for: self) {
                operand.phi = phi
            }
            
            return phi
        }
    }
}



extension VariableInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        guard let type = type else { throw irGenError(.notTyped) }
        
        let mem = try IGF.builder.buildAlloca(type: type.lowerType(module), name: irName)
        try IGF.builder.buildStore(value: value.loweredValue!, in: mem)
        return value.loweredValue!
    }
}


extension GlobalValue : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        var global = LLVMGlobalValue(module: IGF.module, type: memType!.lowerType(module), name: globalName)
        global.hasUnnamedAddr = true
        global.isExternallyInitialised = false
        global.initialiser = LLVMValue.constNull(type: memType!.lowerType(module))
        return global.value
    }
}


extension ArrayInst : VIRLower {
    func virLower(IGF: IRGenFunction) throws -> LLVMValue {
        
        return try IGF.builder.buildArray(values.map { $0.loweredValue! },
                                                    elType: arrayType.mem.lowerType(module),
                                                    irName: irName)
    }
}


