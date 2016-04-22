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
        case .notLowerable(let v): return "value '\(v.vhir)' is not Lowerable"
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



typealias IRGen = (builder: LLVMBuilderRef, module: LLVMModuleRef, isStdLib: Bool)

protocol VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue
}

extension Module {
    
    /// Creates or gets a function pointer
    private func getOrAddFunction(named name: String, type: FunctionType, irGen: IRGen) -> LLVMFunction {
        // if already defined, we return it
        let _module = LLVMModule(ref: irGen.module)
        if let f = _module.function(named: name) {
            return f
        }
        
        // otherwise we create a new prototype
        return LLVMFunction(name: name, type: LLVMType(ref: type.lowerType(module)), module: _module)
    }
    
    func getOrAddRuntimeFunction(named name: String, irGen: IRGen) -> LLVMFunction {
        let (_, fnType) = Runtime.function(mangledName: name)!
        return module.getOrAddFunction(named: name, type: fnType, irGen: irGen)
    }
    
    func vhirLower(module: LLVMModule, isStdLib: Bool) throws {
        
        loweredBuilder = LLVMBuilder()
        loweredModule = module
        let irGen = (loweredBuilder.builder, module.module, isStdLib) as IRGen
        
        for fn in functions {
            // create function proto
            let function = getOrAddFunction(named: fn.name, type: fn.type, irGen: irGen)
            fn.loweredFunction = function
            
            // name the params
            for (i, p) in (fn.params ?? []).enumerate() where p.irName != nil {
                var param = try function.getParam(i)
                param.name = p.irName
            }
        }
        
        for global in globalValues {
            try global.updateUsesWithLoweredVal(global.vhirLower(self, irGen: irGen))
        }
        
        // lower the function bodies
        for fn in functions {
            try fn.vhirLower(self, irGen: irGen)
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




extension Function : VHIRLower {
    
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
            try loweredFunction?.setVisibility(LLVMDefaultVisibility)
            try loweredFunction?.setLinkage(LLVMExternalLinkage)
        case .`internal`:
            try loweredFunction?.setVisibility(LLVMDefaultVisibility)
            try loweredFunction?.setLinkage(LLVMExternalLinkage)
        case .`private`:
            try loweredFunction?.setVisibility(LLVMProtectedVisibility)
            try loweredFunction?.setLinkage(LLVMPrivateLinkage)
        }
    }
    private func applyAttributes() throws {
        if attributes.contains(.noreturn) { try loweredFunction?.addAttr(LLVMNoReturnAttribute) }
        if attributes.contains(.readnone) { try loweredFunction?.addAttr(LLVMReadNoneAttribute) }
    }
    
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        
        let b = module.loweredBuilder.getInsertBlock()
        guard let fn = module.loweredModule.function(named: name) else { fatalError() }
        
        // apply function attributes, linkage, and visibility
        try applyInline()
        try applyVisibility()
        try applyAttributes()
        
        // if no body, return
        guard let blocks = blocks else { return fn.function }
        
        // declare blocks, so break instructions have something to br to
        for bb in blocks {
            bb.loweredBlock = try fn.appendBasicBlock(named: bb.name)
            module.loweredBuilder.positionAtEnd(bb.loweredBlock!)
            
            for param in bb.parameters ?? [] {
                let v = try param.vhirLower(module, irGen: irGen)
                param.updateUsesWithLoweredVal(v)
            }
        }
        
        for bb in blocks {
            module.loweredBuilder.positionAtEnd(bb.loweredBlock!)
            
            for case let inst as protocol<VHIRLower, Inst> in bb.instructions {
                let v = try inst.vhirLower(module, irGen: irGen)
                inst.updateUsesWithLoweredVal(v)
            }
        }
        
        // for the global values that declare their lifetime to exist
        // only in this scope, we define their lifetimes using intrinsics
        for lifetime in globalLifetimes {
            
        }
        
        if let b = b { module.loweredBuilder.positionAtEnd(b) }
        
        try validate()
        
        return fn.function
    }
    
    private func validate() throws {
        guard !LLVMVerifyFunction(loweredFunction!.function._value, LLVMReturnStatusAction) else {
            module.loweredModule?.dump()
            throw irGenError(.invalidFunction(name), userVisible: true)
        }
    }
}

extension BasicBlock {

    func loweredValForParamNamed(name: String, predBlock: BasicBlock) throws -> LLVMValue {
        guard let application = applications.find({$0.predecessor === predBlock}),
            case let blockOperand as BlockOperand = application.args?.find({$0.name == name}) else { throw VHIRError.noFunctionBody }
        return blockOperand.loweredValue!
    }
    
}


extension Param : VHIRLower {

    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        guard let function = parentFunction, block = parentBlock else { throw VHIRError.noParentBlock }
        
        if let functionParamIndex = function.params?.indexOf({$0.name == name}) {
            return try function.loweredFunction!.getParam(functionParamIndex)
        }
        else if let phi = phi {
            return phi
        }
        else {
            let phi = try module.loweredBuilder.buildPhi(type: type!.lowerType(module), name: paramName)
            
            for operand in try block.appliedArgs(for: self) {
                operand.phi = phi
            }
            
            return phi
        }
    }
}



extension VariableInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        guard let type = type else { throw irGenError(.notTyped) }
        
        let mem = try module.loweredBuilder.buildAlloca(type: type.lowerType(module), name: irName)
        try module.loweredBuilder.buildStore(value: value.loweredValue!, in: mem)
        return value.loweredValue!
    }
}


extension GlobalValue : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        var global = LLVMGlobalValue(module: module.loweredModule!, type: memType!.lowerType(module), name: globalName)
        global.hasUnnamedAddr = true
        global.isExternallyInitialised = false
        global.initialiser = LLVMValue.constNull(type: memType!.lowerType(module))
        return global.value
    }
}


extension ArrayInst : VHIRLower {
    func vhirLower(module: Module, irGen: IRGen) throws -> LLVMValue {
        
        return try module.loweredBuilder.buildArray(values.map { $0.loweredValue! },
                                                    elType: arrayType.mem.lowerType(module),
                                                    irName: irName)
    }
}


