//
//  LLVMWrapper.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


private protocol Dumpable {
    func dump()
}

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
    private var builder: LLVMBuilderRef = nil
    
    init() { builder = LLVMCreateBuilder() }
    private init(ref: LLVMBuilderRef) { builder = ref }
}
extension LLVMBuilder {
    
    func positionAtEnd(block: LLVMBasicBlock) {
        LLVMPositionBuilderAtEnd(builder, block.block)
    }
    func positionBefore(after: LLVMValue) {
        LLVMPositionBuilderBefore(builder, after._value)
    }
    func getInsertBlock() -> LLVMBasicBlock? {
        let i = LLVMGetInsertBlock(builder)
        guard i != nil else { return nil }
        return LLVMBasicBlock(ref: i)
    }
    
}
extension LLVMBuilder {
    
    /// Wraps a LLVM function and checks the builder
    @warn_unused_result
    private func wrap(@autoclosure val: () throws -> LLVMValueRef) throws -> LLVMValue {
        #if DEBUG
            guard builder != nil else { throw error(NullLLVMRef()) }
        #endif
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
    func buildLoad(from addr: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildLoad(builder, addr.val(), name ?? "")
        )
    }
    func buildBitcast(value val: LLVMValue, to type: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildBitCast(builder, val.val(), type.type, name ?? "")
        )
    }
    func buildBr(to block: LLVMBasicBlock) throws -> LLVMValue {
        return try wrap(
            LLVMBuildBr(builder, block.block)
        )
    }
    func buildCondBr(if cond: LLVMValue, to success: LLVMBasicBlock, elseTo fail: LLVMBasicBlock) throws -> LLVMValue {
        return try wrap(
            LLVMBuildCondBr(builder, cond.val(), success.block, fail.block)
        )
    }
    func buildRet(val: LLVMValue) throws -> LLVMValue {
        return try wrap(
            LLVMBuildRet(builder, val.val())
        )
    }
    func buildRetVoid() throws -> LLVMValue {
        return try wrap(
            LLVMBuildRetVoid(builder)
        )
    }
    func buildCall(function: LLVMFunction, args: [LLVMValue], name: String? = nil) throws -> LLVMValue {
        var applied = try args.map { try $0.val() }
//        guard function.paramCount == applied.count else { throw error(LLVMError.invalidParamCount(expected: function.paramCount, got: applied.count)) }
        return try wrap(
            LLVMBuildCall(builder, function.function.val(), &applied, UInt32(applied.count), name ?? "")
        )
    }
    func buildUnreachable() throws -> LLVMValue {
        return try wrap(
            LLVMBuildUnreachable(builder)
        )
    }
    func buildInsertValue(value val: LLVMValue, in aggr: LLVMValue, index: Int, name: String? = nil) throws -> LLVMValue {
        return try LLVMValue(ref:
            LLVMBuildInsertValue(builder, aggr.val(), val.val(), UInt32(index), name ?? "")
        )
    }
    func buildExtractValue(val: LLVMValue, index: Int, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildExtractValue(builder, val.val(), UInt32(index), name ?? "")
        )
    }
    func buildStructGEP(val: LLVMValue, index: Int, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildStructGEP(builder, val.val(), UInt32(index), name ?? "")
        )
    }
    func buildGEP(val: LLVMValue, index: LLVMValue, name: String? = nil) throws -> LLVMValue {
        var v = try [index.val()]
        return try wrap(
            LLVMBuildGEP(builder, val.val(), &v, 1, name ?? "")
        )
    }
    func buildGlobalString(str: String) throws -> LLVMValue {
        return try wrap(
            LLVMBuildGlobalString(builder, str, "")
        )
    }
    func buildAggregateType(type: LLVMType, elements: [LLVMValue], irName: String? = nil) throws -> LLVMValue {
        // creates an undef, then for each element in type, inserts the next element into it
        return try elements
            .enumerate()
            .reduce(LLVMValue.undef(type)) { aggr, el in
                return try buildInsertValue(value: el.element,
                                            in: aggr,
                                            index: el.index,
                                            name: irName)
        }
    }
    func buildArray(buffer: [LLVMValue], elType: LLVMType, irName: String? = nil) throws -> LLVMValue {
        let elPtrType = LLVMPointerType(elType.type, 0)
        
        let arrType = LLVMArrayType(elType.type, UInt32(buffer.count))
        let ptr = LLVMBuildAlloca(builder, arrType, irName ?? "") // [n x el]*
        let basePtr = LLVMBuildBitCast(builder, ptr, elPtrType, "") // el*
        
        for (index, val) in buffer.enumerate() {
            // Make the index to lookup
            var mem = [LLVMConstInt(LLVMInt32Type(), UInt64(index), false)]
            // get the element ptr
            let el = LLVMBuildGEP(builder, basePtr, &mem, 1, "el.\(index)")
            let bcElPtr = LLVMBuildBitCast(builder, el, elPtrType, "el.ptr.\(index)")
            // store val into memory
            LLVMBuildStore(builder, val._value, bcElPtr)
        }
        
        return LLVMValue(ref: LLVMBuildLoad(builder, ptr, ""))
    }
    func buildArrayAlloca(size size: LLVMValue, elementType: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildArrayAlloca(builder, elementType.type, size.val(), name ?? "")
        )
    }
    func buildArrayMalloc(size size: LLVMValue, elementType: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildArrayMalloc(builder, elementType.type, size.val(), name ?? "")
        )
    }
}

extension LLVMBuilder {

    typealias LLVMBinFunction = @convention(c) (builder: LLVMBuilderRef, lhs: LLVMValueRef, rhs: LLVMValueRef, name: UnsafePointer<Int8>) -> LLVMValueRef
    typealias LLVMBinIntFunction = @convention(c) (builder: LLVMBuilderRef, pred: LLVMIntPredicate, lhs: LLVMValueRef, rhs: LLVMValueRef, name: UnsafePointer<Int8>) -> LLVMValueRef
    typealias LLVMBinFloatFunction = @convention(c) (builder: LLVMBuilderRef, pred: LLVMRealPredicate, lhs: LLVMValueRef, rhs: LLVMValueRef, name: UnsafePointer<Int8>) -> LLVMValueRef
    
    private func buildBinaryOperation_createThunk(function: LLVMBinFunction) -> (lhs: LLVMValue, rhs: LLVMValue, name: String?) throws -> LLVMValue {
        return { lhs, rhs, name in
            return try self.wrap(
                function(builder: self.builder, lhs: lhs.val(), rhs: rhs.val(), name: name ?? "")
            )
        }
    }
    
    func buildIAdd(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildAdd)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildISub(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildSub)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildIMul(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildMul)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildIDiv(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildSDiv)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildIRem(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildSRem)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildIShiftR(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildAShr)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildIShiftL(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildShl)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildAnd(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildAnd)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildOr(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildOr)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildXor(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildXor)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildIntCompare(pred: LLVMIntPredicate, lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        let f = LLVMBuildICmp as LLVMBinIntFunction
        return try self.wrap(
            f(builder: builder, pred: pred, lhs: lhs.val(), rhs: rhs.val(), name: name ?? "")
        )
    }
    
    func buildFAdd(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildFAdd)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildFSub(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildFSub)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildFMul(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildFMul)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildFDiv(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildFDiv)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildFRem(lhs lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try buildBinaryOperation_createThunk(LLVMBuildFRem)(lhs: lhs, rhs: rhs, name: name)
    }
    func buildFloatCompare(pred: LLVMRealPredicate, lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        let f = LLVMBuildFCmp as LLVMBinFloatFunction
        return try self.wrap(
            f(builder: builder, pred: pred, lhs: lhs.val(), rhs: rhs.val(), name: name ?? "")
        )
    }

}

extension LLVMIntPredicate {
    static var lessThanEqual = LLVMIntSLE
    static var lessThan = LLVMIntSLT
    static var greaterThan = LLVMIntSGT
    static var greaterThanEqual = LLVMIntSGE
    static var equal = LLVMIntEQ
    static var notEqual = LLVMIntNE
}
extension LLVMRealPredicate {
    static var lessThanEqual = LLVMRealOLE
    static var lessThan = LLVMRealOLT
    static var greaterThan = LLVMRealOGT
    static var greaterThanEqual = LLVMRealOGE
    static var equal = LLVMRealOEQ
    static var notEqual = LLVMRealONE
}


struct LLVMBasicBlock : Dumpable {
//    private
    var block: LLVMBasicBlockRef
    
//    private
    init(ref: LLVMBasicBlockRef) { block = ref }
    
    func move(after other: LLVMBasicBlock) {
        LLVMMoveBasicBlockAfter(block, other.block)
    }
    func move(before other: LLVMBasicBlock) {
        LLVMMoveBasicBlockBefore(block, other.block)
    }
    
    private func dump() { LLVMDumpValue(block) }
}

struct LLVMModule : Dumpable {
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
    
    func getIntrinsic(name: String, overload: LLVMType...) throws -> LLVMFunction {
        let intrinsic: LLVMValueRef
        switch overload.count {
        case 0: intrinsic = getRawIntrinsic(name, module)
        case 1: intrinsic = getSinglyOverloadedIntrinsic(name, module, overload[0].type)
        case _:
            var overloads = overload.map{$0.type}
            intrinsic = getOverloadedIntrinsic(name, module, &overloads, Int32(overload.count))
        }
        guard intrinsic != nil else { throw NullLLVMRef() }
        return try LLVMFunction(ref: intrinsic)
    }
    
    func dump() { LLVMDumpModule(module) }
    
    var dataLayout: String { return String.fromCString(LLVMGetDataLayout(module))! }
}

struct LLVMType : Dumpable {
//    private
    var type: LLVMTypeRef
    
    init(ref: LLVMTypeRef) { type = ref }
    
    func dump() { LLVMDumpType(type) }
    
    func offsetOfElement(index index: Int, module: LLVMModule) -> Int {
        let dataLayout = LLVMCreateTargetData(module.dataLayout)
        return Int(LLVMOffsetOfElement(dataLayout, type, UInt32(index)))
    }
    /// get self*
    func getPointerType() -> LLVMType {
        return LLVMType(ref: LLVMPointerType(type, 0))
    }
    /// i8*
    static var opaquePointer: LLVMType {
        return LLVMType(ref: LLVMPointerType(LLVMInt8Type(), 0))
    }
    static func intType(size size: Int) -> LLVMType {
        return LLVMType(ref: LLVMIntType(UInt32(size)))
    }
}

struct LLVMValue : Dumpable {
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
    static func constInt(value: Int, size: Int) -> LLVMValue {
        return LLVMValue(ref: LLVMConstInt(LLVMIntType(UInt32(size)), UInt64(value), false))
    }
    static func constBool(value: Bool) -> LLVMValue {
        return LLVMValue(ref: LLVMConstInt(LLVMInt1Type(), UInt64(value.hashValue), false))
    }
    static func undef(type: LLVMType) -> LLVMValue {
        return LLVMValue(ref: LLVMGetUndef(type.type))
    }
    static var nullptr: LLVMValue { return LLVMValue(ref: nil) }
    
    func dump() { try! LLVMDumpValue(val()) }
    var type: LLVMType { return LLVMType(ref: try! LLVMTypeOf(val())) }
}

struct LLVMGlobalValue : Dumpable {
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

    private func dump() { value.dump() }
}


/// A LLVM function, a LLVM value ref under the hood
struct LLVMFunction : Dumpable {
    private (set) var function: LLVMValue
    
//    private
    init(ref: LLVMValueRef) {
//        guard LLVMIsAFunction(ref) != nil else { throw error(LLVMError.notAFunction) }
        function = LLVMValue(ref: ref)
    }
    init(name: String, type: LLVMType, module: LLVMModule) {
        let r = LLVMAddFunction(module.module, name, type.type)
        function = LLVMValue(ref: r)
    }
    
    func addAttr(attr: LLVMAttribute) throws {
        try LLVMAddFunctionAttr(function.val(), attr)
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
    
    func dump() { function.dump() }
}




