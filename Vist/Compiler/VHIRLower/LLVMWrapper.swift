//
//  LLVMWrapper.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct NullLLVMRef : VistError {
    var description: String { return "null llvm value" }
}
enum LLVMError : VistError {
    case notAFunction, notAGlobal
    case invalidParamCount(expected: Int, got: Int)
    case invalidParamIndex(Int, function: String?)
    
    var description: String {
        switch self {
        case .notAFunction: return "Not a LLVM function"
        case .notAGlobal: return "Not a LLVM global"
        case .invalidParamCount(let e, let g): return "Expected \(e) params, got \(g)"
        case .invalidParamIndex(let i, let f): return "No param at index \(i)" + (f.map { " for function '\($0)'" } ?? "")
        }
    }
}


struct LLVMBuilder {
//    private
    var builder: LLVMBuilderRef = nil
    
//    private
    init(ref: LLVMBuilderRef) { builder = ref }
}
extension LLVMBuilder {
    
    func positionAtEnd(block: LLVMBasicBlock) {
        LLVMPositionBuilderAtEnd(builder, block.block)
    }
    
}
extension LLVMBuilder {
    
    /// Wraps a LLVM function and checks the builder
    @warn_unused_result
    private func wrap(@autoclosure val: () throws -> LLVMValueRef) throws -> LLVMValue {
        guard builder != nil else { throw error(NullLLVMRef()) }
        return try LLVMValue(ref: val())
    }
    @warn_unused_result
    func buildPhi(type type: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildPhi(builder, type.type, name ?? "")
        )
    }
    @warn_unused_result
    func buildAlloca(type type: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildAlloca(builder, type.type, name ?? "")
        )
    }
    func buildStore(value val: LLVMValue, in addr: LLVMValue) throws -> LLVMValue {
        return try wrap(
            LLVMBuildStore(builder, val.val(), addr.val())
        )
    }
    func buildBr(to block: LLVMBasicBlock) throws -> LLVMValue {
        return try wrap(
            LLVMBuildBr(builder, block.block)
        )
    }
    func buildRet(val: LLVMValue) throws -> LLVMValue {
        return try wrap(
            LLVMBuildRet(builder, val.val())
        )
    }
    func buildCall(function: LLVMFunction, args: [LLVMValue], name: String? = nil) throws -> LLVMValue {
        var applied = try args.map { try $0.val() }
        guard function.paramCount == applied.count else { throw error(LLVMError.invalidParamCount(expected: function.paramCount, got: applied.count)) }
        return try wrap(
            LLVMBuildCall(builder, function.function.val(), &applied, UInt32(applied.count), name ?? "")
        )
    }

    
}

struct LLVMBasicBlock {
//    private
    var block: LLVMBasicBlockRef
    
//    private
    init(ref: LLVMBasicBlockRef) { block = ref }
}

struct LLVMModule {
//    private
    var module: LLVMModuleRef
    
    init(name: String) {
        module = LLVMModuleCreateWithName(name)
    }
    init(ref: LLVMModuleRef) {
        module = ref
    }
    
    func function(named name: String) -> LLVMFunction? {
        let f = LLVMGetNamedFunction(module, name)
        if f != nil {
            return try! LLVMFunction(ref: f)
        }
        else { return nil }
    }
    func global(named name: String) -> LLVMGlobalValue? {
        let f = LLVMGetNamedGlobal(module, name)
        if f != nil {
            return try! LLVMGlobalValue(ref: f)
        }
        else { return nil }
    }
    
    func dump() { LLVMDumpModule(module) }
}

struct LLVMType {
//    private
    var type: LLVMTypeRef
    
    init(ref: LLVMTypeRef) { type = ref }
    
    func dump() { LLVMDumpType(type) }
}

struct LLVMValue {
//    private
    var _value: LLVMValueRef = nil
    
    private func val() throws -> LLVMValueRef {
        guard _value != nil else { throw NullLLVMRef() }
        return _value
    }
    
//    private
    init(ref: LLVMValueRef) { _value = ref }
    
    var name: String? {
        get { return String.fromCString(LLVMGetValueName(_value)) }
        set { if let name = newValue { LLVMSetValueName(_value, name) } }
    }
    
    static func constNull(type type: LLVMType) -> LLVMValue {
        return LLVMValue(ref: LLVMConstNull(type.type))
    }
    
    func dump() { try! LLVMDumpValue(val()) }
    var type: LLVMType { return LLVMType(ref: try! LLVMTypeOf(val())) }
}

struct LLVMGlobalValue {
    var value: LLVMValue
    
    init(module: LLVMModule, type: LLVMType, name: String) {
        value = LLVMValue(ref: LLVMAddGlobal(module.module, type.type, name))
    }
    
//    private
    init(ref: LLVMValueRef) throws {
        guard LLVMIsAGlobalValue(ref) != nil else { throw error(LLVMError.notAGlobal) }
        value = LLVMValue(ref: ref)
    }
    
    var hasUnnamedAddr: Bool {
        get { return Bool(LLVMHasUnnamedAddr(value._value)) }
        set { LLVMSetUnnamedAddr(value._value, LLVMBool(booleanLiteral: newValue)) }
    }
    var isExternallyInitialised: Bool {
        get { return Bool(LLVMIsExternallyInitialized(value._value)) }
        set { LLVMSetExternallyInitialized(value._value, LLVMBool(booleanLiteral: newValue)) }
    }
    var initialiser: LLVMValue {
        get { return LLVMValue(ref: LLVMGetInitializer(value._value)) }
        set { return LLVMSetInitializer(value._value, newValue._value) }
    }

}


/// A LLVM function, a LLVM value ref under the hood
struct LLVMFunction {
//    private
    var function: LLVMValue
    
//    private
    init(ref: LLVMValueRef) throws {
        guard LLVMIsAFunction(ref) != nil else { throw error(LLVMError.notAFunction) }
        function = LLVMValue(ref: ref)
    }
    init(name: String, type: LLVMType, module: LLVMModule) {
        let r = LLVMAddFunction(module.module, name, type.type)
        function = LLVMValue(ref: r)
    }
    
    func addAttr(attr: LLVMAttribute) throws {
        try LLVMAddAttribute(function.val(), attr)
    }
    func setVisibility(vis: LLVMVisibility) throws {
        try LLVMSetVisibility(function.val(), vis)
    }
    func setLinkage(linkage: LLVMLinkage) throws {
        try LLVMSetLinkage(function.val(), linkage)
    }
    
    func appendBasicBlock(named name: String) throws -> LLVMBasicBlock {
        return LLVMBasicBlock(ref:
            try LLVMAppendBasicBlock(function.val(), name)
        )
    }
    
    var paramCount: Int { return try! Int(LLVMCountParams(function.val())) }
    var name: String? {
        get { return function.name }
        set { function.name = newValue }
    }
    
    func getParam(index: Int) throws -> LLVMValue {
        guard let function = try? function.val() else { throw error(NullLLVMRef()) }
        guard index < paramCount else { throw error(LLVMError.invalidParamIndex(index, function: name)) }
        return LLVMValue(ref: LLVMGetParam(function, UInt32(index)))
    }
}




