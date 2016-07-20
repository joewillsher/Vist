//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRLowerError: VistError {
    case notLowerable(VIRElement)
    
    var description: String {
        switch self {
        case .notLowerable(let v): return "value '\(v.vir)' is not Lowerable"
        }
    }
}


// Extends LLVM bool to be initialisable from bool literal, and usable
// as condition
extension LLVMBool : Boolean, BooleanLiteralConvertible {
    
    public init(booleanLiteral value: Bool) {
        self.init(value.hashValue)
    }
    
    public var boolValue: Bool {
        return self == 1
    }
}



typealias IRGenFunction = (builder: LLVMBuilder, module: LLVMModule)

protocol VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue
}

extension Module {
    
    /// Creates or gets a function pointer
    private func getOrAddFunction(named name: String, type: FunctionType, IGF: inout IRGenFunction) -> LLVMFunction {
        // if already defined, we return it
        if let f = IGF.module.function(named: name) {
            return f
        }
        
        // otherwise we create a new prototype
        return LLVMFunction(name: name, type: type.lowered(module: module), module: IGF.module)
    }
    
    func getRuntimeFunction(_ fn: Runtime.Function, IGF: inout IRGenFunction) -> LLVMFunction {
        return module.getOrAddFunction(named: fn.name, type: fn.type.importedType(in: self) as! FunctionType, IGF: &IGF)
    }
    
    func virLower(module: LLVMModule, isStdLib: Bool) throws {
        
        let builder = LLVMBuilder()
        loweredBuilder = builder
        loweredModule = module
        var IGF = (builder, module) as IRGenFunction
        
        for type in typeList where type.targetType is ConceptType {
            _ = try type.getLLVMTypeMetadata(IGF: &IGF, module: self)
        }
        for type in typeList where type.targetType is StructType {
            _ = try type.getLLVMTypeMetadata(IGF: &IGF, module: self)
        }

        for fn in functions {
            // create function proto
            let function = getOrAddFunction(named: fn.name, type: fn.type, IGF: &IGF)
            fn.loweredFunction = function
            
            // name the params
            for (i, p) in (fn.params ?? []).enumerated() where p.irName != nil {
                try function.param(at: i).name = p.irName
            }
        }
        
        for global in globalValues {
            try global.updateUsesWithLoweredVal(global.virLower(IGF: &IGF))
        }
        
        // lower the function bodies
        for fn in functions {
            _ = try fn.virLower(IGF: &IGF)
        }
        
        try loweredModule?.validate()
    }
    
}




extension Function : VIRLower {
    
    private func applyInline() throws {
        switch inlineRequirement {
        case .default: break
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
    
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
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
            IGF.builder.position(atEndOfBlock: bb.loweredBlock!)
            
            for param in bb.parameters ?? [] {
                let v = try param.virLower(IGF: &IGF)
                param.updateUsesWithLoweredVal(v)
            }
        }
        
        for bb in blocks {
            IGF.builder.position(atEndOfBlock: bb.loweredBlock!)
            
            for case let inst as protocol<VIRLower, Inst> in bb.instructions {
                let v = try inst.virLower(IGF: &IGF)
                inst.updateUsesWithLoweredVal(v)
            }
        }
        
        // for the global values that declare their lifetime to exist
        // only in this scope, we define their lifetimes using intrinsics
        for lifetime in globalLifetimes {
            
            guard
                let global = IGF.module.global(named: lifetime.globalName) else {
                // the global couldn't be found -- try the next
                continue
            }
            let size = global.type.size(unit: .bits, IGF: IGF)
            let globalPointer = try IGF.builder.buildBitcast(value: global.value, to: LLVMType.opaquePointer)
            let constSize = LLVMValue.constInt(value: size, size: 64)
            
            let startIntrinsic = try IGF.module.getIntrinsic(named: "llvm.lifetime.start")
            let endIntrinsic = try IGF.module.getIntrinsic(named: "llvm.lifetime.end")
            
            try IGF.builder.position(after: lifetime.start.loweredValue!)
            _ = try IGF.builder.buildCall(function: startIntrinsic, args: [constSize, globalPointer])
            try IGF.builder.position(after: lifetime.end.loweredValue!)
            _ = try IGF.builder.buildCall(function: endIntrinsic, args: [constSize, globalPointer])
        }
        
        if let b = b { IGF.builder.position(atEndOfBlock: b) }
        
        return fn.function
    }
    
//    private func validate() throws {
//        guard !LLVMVerifyFunction(loweredFunction!.function._value, LLVMReturnStatusAction) else {
//            #if DEBUG
//                try module.loweredModule.validate()
//            #endif
//            throw irGenError(.invalidFunction(name), userVisible: true)
//        }
//    }
}

extension BasicBlock {

    func loweredValForParamNamed(name: String, predBlock: BasicBlock) throws -> LLVMValue {
        guard let application = applications.first(where: {$0.predecessor === predBlock}),
            case let blockOperand as BlockOperand = application.args?.first(where: {$0.name == name}) else { throw VIRError.noFunctionBody }
        return blockOperand.loweredValue!
    }
    
}


extension Param : VIRLower {

    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        guard let function = parentFunction, let block = parentBlock else { throw VIRError.noParentBlock }
        
        if let functionParamIndex = function.params?.index(where: {$0.name == name}) {
            return try function.loweredFunction!.param(at: functionParamIndex)
        }
        else if let phi = phi {
            return phi
        }
        else {
            let phi = try IGF.builder.buildPhi(type: type!.lowered(module: module), name: paramName)
            
            for operand in try block.blockArgs(for: self) {
                operand.phi = phi
            }
            
            return phi
        }
    }
}



extension VariableInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        guard let type = type else {
            throw irGenError(.notTyped)
        }
        
        let mem = try IGF.builder.buildAlloca(type: type.lowered(module: module), name: irName)
        try IGF.builder.buildStore(value: value.loweredValue!, in: mem)
        return value.loweredValue!
    }
}


extension GlobalValue : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let global = LLVMGlobalValue(module: IGF.module, type: memType!.lowered(module: module), name: globalName)
        global.hasUnnamedAddr = true
        global.isExternallyInitialised = false
        global.linkage = LLVMPrivateLinkage
        global.initialiser = LLVMValue.constNull(type: memType!.lowered(module: module))
        return global.value
    }
}


extension ArrayInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        return try IGF.builder.buildArray(elements: values.map { $0.loweredValue! },
                                          elType: arrayType.mem.lowered(module: module),
                                          irName: irName)
    }
}


