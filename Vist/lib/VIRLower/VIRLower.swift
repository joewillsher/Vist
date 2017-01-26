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
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue
}

extension Module {
    
    /// Creates or gets a function pointer
    private func getOrAddFunction(named name: String, type: FunctionType, igf: inout IRGenFunction) -> LLVMFunction {
        // if already defined, we return it
        if let f = igf.module.function(named: name) {
            return f
        }
        
        // otherwise we create a new prototype
        return LLVMFunction(name: name, type: type.lowered(module: module), module: igf.module)
    }
    
    func getRuntimeFunction(_ fn: Runtime.Function, igf: inout IRGenFunction) -> LLVMFunction {
        return module.getOrAddFunction(named: fn.name, type: fn.type.importedType(in: self) as! FunctionType, igf: &igf)
    }
    
    func virLower(module: LLVMModule, isStdLib: Bool) throws {
        
        let builder = LLVMBuilder()
        loweredBuilder = builder
        loweredModule = module
        var igf = (builder, module) as IRGenFunction
        
        // define function stubs
        for fn in functions {
            // create function proto
            let function = getOrAddFunction(named: fn.name, type: fn.type, igf: &igf)
            fn.loweredFunction = function
            
            // name the params
            for (i, p) in (fn.params ?? []).enumerated() where p.irName != nil {
                try function.param(at: i).name = p.irName
            }
        }
        
        // first emit any type destructors, needed for the metadata
        for type in typeList.values {
            if let destructor = type.destructor {
                let fn = getOrAddFunction(named: destructor.name,
                                          type: destructor.type,
                                          igf: &igf)
                destructor.loweredFunction = fn
                try destructor.virLower(igf: &igf)
            }
            if let copyConstructor = type.copyConstructor {
                let fn = getOrAddFunction(named: copyConstructor.name,
                                          type: copyConstructor.type,
                                          igf: &igf)
                copyConstructor.loweredFunction = fn
                try copyConstructor.virLower(igf: &igf)
            }
        }
        
        // emit concepts, needed for conformances
        for type in typeList.values where type.targetType is ConceptType {
            try type.getLLVMTypeMetadata(igf: &igf, module: self)
        }
        // finally emit struct metadata
        for type in typeList.values where type.targetType is StructType {
            try type.getLLVMTypeMetadata(igf: &igf, module: self)
        }
        
//        // TEST: build witness table metadata
//        for table in witnessTables {
//            try table.loweredMetadata(igf: &igf)
//        }
        
        for global in globalValues {
            try global.updateUsesWithLoweredVal(global.virLower(igf: &igf))
        }
        
        // lower the function bodies
        for fn in functions {
            try fn.virLower(igf: &igf)
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
    
    @discardableResult func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        let b = igf.builder.getInsertBlock()
        guard let fn = igf.module.function(named: name) else { fatalError() }
        
        // apply function attributes, linkage, and visibility
        try applyInline()
        try applyVisibility()
        try applyAttributes()
        
        // if no body, return
        guard let _ = self.blocks, !emmitedBody else { return fn.function }
        defer { emmitedBody = true }
        
        // declare blocks, so break instructions have something to br to
        // loop over the dominance tree
        for bb in dominator.analysis {
            bb.loweredBlock = try fn.appendBasicBlock(named: bb.name)
            igf.builder.position(atEndOf: bb.loweredBlock!)
            
            for param in bb.parameters ?? [] {
                let val = try param.virLower(igf: &igf)
                param.phi = val
            }
        }
        for bb in dominator.analysis {
            igf.builder.position(atEndOf: bb.loweredBlock!)
            for param in bb.parameters ?? [] {
                param.updateUsesWithLoweredVal(param.phi!)
            }
        }
        
        // loop over the dominance tree
        for bb in dominator.analysis {
            igf.builder.position(atEndOf: bb.loweredBlock!)
            
            for case let inst as VIRLower & Inst in bb.instructions {
                let v = try inst.virLower(igf: &igf)
                inst.updateUsesWithLoweredVal(v)
            }
        }
        
        // for the global values that declare their lifetime to exist
        // only in this scope, we define their lifetimes using intrinsics
        for lifetime in globalLifetimes {
            
            guard let global = igf.module.global(named: lifetime.globalName) else {
                // the global couldn't be found -- try the next
                continue
            }
            let size = global.type.size(unit: .bits, igf: igf)
            let globalPointer = try igf.builder.buildBitcast(value: global.value, to: LLVMType.opaquePointer)
            let constSize = LLVMValue.constInt(value: size, size: 64)
            
            try igf.builder.position(after: lifetime.start.loweredValue!)
            try igf.builder.buildCall(function: igf.module.getIntrinsic(.lifetime_start),
                                      args: [constSize, globalPointer])
            
            try igf.builder.position(after: lifetime.end.loweredValue!)
            try igf.builder.buildCall(function: igf.module.getIntrinsic(.lifetime_end),
                                      args: [constSize, globalPointer])
        }
        
        if let b = b { igf.builder.position(atEndOf: b) }
        
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
    
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
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
            let phi = try igf.builder.buildPhi(type: type!.lowered(module: module),
                                               name: paramName)
            for operand in try block.blockArgs(for: self) {
                operand.phi = phi
            }
            
            return phi
        }
    }
}


extension GlobalValue : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let global = LLVMGlobalValue(module: igf.module, type: memType!.lowered(module: module), name: globalName)
        global.hasUnnamedAddr = true
        global.isExternallyInitialised = false
        global.linkage = LLVMPrivateLinkage
        global.initialiser = LLVMValue.constNull(type: memType!.lowered(module: module))
        return global.value
    }
}


extension ArrayInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        return try igf.builder.buildArray(elements: values.map { $0.loweredValue! },
                                          elType: arrayType.mem.lowered(module: module),
                                          irName: irName)
    }
}


