//
//  IRGen.swift
//  Vist
//
//  Created by Josef Willsher on 01/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum IRLowerError : VistError {
    case notLowerable(VIRElement)
    
    var description: String {
        switch self {
        case .notLowerable(let v): return "value '\(v.vir)' is not Lowerable"
        }
    }
}


// Extends LLVM bool to be initialisable from bool literal, and usable
// as condition
extension LLVMBool : ExpressibleByBooleanLiteral {
    
    public init(booleanLiteral value: Bool) {
        self.init(value.hashValue)
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
        
        // first emit any type destructors, needed for the metadata
        for type in typeList.values {
            if let destructor = type.destructor {
                let fn = getOrAddFunction(named: destructor.name,
                                          type: destructor.type,
                                          IGF: &IGF)
                destructor.loweredFunction = fn
                try destructor.virLower(IGF: &IGF)
            }
            if let copyConstructor = type.copyConstructor {
                let fn = getOrAddFunction(named: copyConstructor.name,
                                          type: copyConstructor.type,
                                          IGF: &IGF)
                copyConstructor.loweredFunction = fn
                try copyConstructor.virLower(IGF: &IGF)
            }
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
        // emit concepts, needed for conformances
        for type in typeList.values where type.targetType is ConceptType {
            _ = try type.getLLVMTypeMetadata(IGF: &IGF, module: self)
        }
        // finally emit struct metadata
        for type in typeList.values where type.targetType is StructType {
            _ = try type.getLLVMTypeMetadata(IGF: &IGF, module: self)
        }

        // TEST: build witness table metadata
        for table in witnessTables {
            _ = try table.lowerMetadata(IGF: &IGF)
        }
        
        for global in globalValues {
            try global.updateUsesWithLoweredVal(global.virLower(IGF: &IGF))
        }
        
        // lower the function bodies
        for fn in functions {
            try fn.virLower(IGF: &IGF)
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
        case .public:
            loweredFunction?.visibility = LLVMDefaultVisibility
            loweredFunction?.linkage = LLVMExternalLinkage
        case .internal:
            loweredFunction?.visibility = LLVMDefaultVisibility
            loweredFunction?.linkage = LLVMExternalLinkage
        case .private:
            loweredFunction?.visibility = LLVMProtectedVisibility
            loweredFunction?.linkage = LLVMPrivateLinkage
        }
    }
    private func applyAttributes() throws {
        if attributes.contains(.noreturn) { try loweredFunction?.addAttr(LLVMNoReturnAttribute) }
        if attributes.contains(.readnone) { try loweredFunction?.addAttr(LLVMReadNoneAttribute) }
    }
    
    @discardableResult func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        let b = IGF.builder.getInsertBlock()
        guard let fn = IGF.module.function(named: name) else { fatalError() }
        
        // apply function attributes, linkage, and visibility
        try applyInline()
        try applyVisibility()
        try applyAttributes()
        
        // if no body, return
        guard let _ = self.blocks, !emmitedBody else { return fn.function }
        defer { emmitedBody = true }
        
        // declare blocks, so break instructions have something to br to
        // loop over the dominance tree
        for bb in dominator.analsis {
            bb.loweredBlock = try fn.appendBasicBlock(named: bb.name)
            IGF.builder.position(atEndOf: bb.loweredBlock!)
            
            for param in bb.parameters ?? [] {
                let val = try param.virLower(IGF: &IGF)
                param.phi = val
            }
        }
        for bb in dominator.analsis {
            IGF.builder.position(atEndOf: bb.loweredBlock!)
            for param in bb.parameters ?? [] {
                param.updateUsesWithLoweredVal(param.phi!)
            }
        }
        
        // loop over the dominance tree
        for bb in dominator.analsis {
            IGF.builder.position(atEndOf: bb.loweredBlock!)
            
            for case let inst as VIRLower & Inst in bb.instructions {
                let v = try inst.virLower(IGF: &IGF)
                inst.updateUsesWithLoweredVal(v)
            }
        }
        
        // for the global values that declare their lifetime to exist
        // only in this scope, we define their lifetimes using intrinsics
        for lifetime in globalLifetimes {
            
            guard let global = IGF.module.global(named: lifetime.globalName) else {
                // the global couldn't be found -- try the next
                continue
            }
            let size = global.type.size(unit: .bits, IGF: IGF)
            let globalPointer = try IGF.builder.buildBitcast(value: global.value, to: LLVMType.opaquePointer)
            let constSize = LLVMValue.constInt(value: size, size: 64)
            
            try IGF.builder.position(after: lifetime.start.loweredValue!)
            try IGF.builder.buildCall(function: IGF.module.getIntrinsic(.lifetime_start),
                                      args: [constSize, globalPointer])
            
            try IGF.builder.position(after: lifetime.end.loweredValue!)
            try IGF.builder.buildCall(function: IGF.module.getIntrinsic(.lifetime_end),
                                      args: [constSize, globalPointer])
        }
        
        if let b = b { IGF.builder.position(atEndOf: b) }
        
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
        
        // search entry block
        if let functionParamIndex = function.params?.index(where: {$0 === self}) {
            let v = try function.loweredFunction!.param(at: functionParamIndex)
            // set operands applied to the entry block
            for operand in try block.args(for: self) {
                operand.setLoweredValue(v)
            }
            return v
        }
        else if let phi = phi {
            return phi
        }
        else {
            let phi = try IGF.builder.buildPhi(type: type!.lowered(module: module),
                                               name: paramName)
            for operand in try block.blockArgs(for: self) {
                operand.phi = phi
            }
            
            return phi
        }
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


