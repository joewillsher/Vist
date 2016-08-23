//
//  LLVMWrapper.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.Task

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
    case noSuccessor, notPhi
    
    var description: String {
        switch self {
        case .notAFunction: return "Not a LLVM function"
        case .notAGlobal: return "Not a LLVM global"
        case .invalidParamCount(let e, let g): return "Expected \(e) params, got \(g)"
        case .invalidParamIndex(let i, let f): return "No param at index \(i)" + (f.map { " for function '\($0)'" } ?? "")
        case .noSuccessor: return "Inst does not have a successor"
        case .notPhi: return "Can only add incoming values to a phi node"
        }
    }
}


struct LLVMBuilder {
    private var builder: LLVMBuilderRef? = nil
//    var metadata: Set<RuntimeObject> = []
    
    init() { builder = LLVMCreateBuilder() }
    private init(ref: LLVMBuilderRef) { builder = ref }
}
extension LLVMBuilder {
    
    /// Position the builder at the end of `block`
    func position(atEndOf block: LLVMBasicBlock) {
        LLVMPositionBuilderAtEnd(builder, block.block)
    }
    func position(after: LLVMValue) throws {
        let successor = LLVMGetNextInstruction(after._value)
        guard successor != nil else {
            // if we are at the end of a block
            let parentBlock = LLVMGetInstructionParent(after._value)
            LLVMPositionBuilderAtEnd(builder, parentBlock)
            return
        }
        LLVMPositionBuilderBefore(builder, successor)
    }
    func position(before: LLVMValue) {
        LLVMPositionBuilderBefore(builder, before._value)
    }
    func getInsertBlock() -> LLVMBasicBlock? {
        guard let i = LLVMGetInsertBlock(builder) else { return nil }
        return LLVMBasicBlock(ref: i)
    }
    
}
extension LLVMBuilder {
    
    /// Wraps a LLVM function and checks the builder
    private func wrap(_ val: @autoclosure () throws -> LLVMValueRef) throws -> LLVMValue {
        #if DEBUG
            guard builder != nil else { throw error(NullLLVMRef()) }
        #endif
        return try LLVMValue(ref: val())
    }
    func buildPhi(type: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildPhi(builder, type.type!, name ?? ""))
    }
    func buildAlloca(type: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildAlloca(builder, type.type!, name ?? ""))
    }
    
    @discardableResult
    func buildStore(value val: LLVMValue, in addr: LLVMValue) throws -> LLVMValue {
        return try wrap(LLVMBuildStore(builder, val.val(), addr.val()))
    }
    func buildLoad(from addr: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildLoad(builder, addr.val(), name ?? ""))
    }
    func buildBitcast(value val: LLVMValue, to type: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildBitCast(builder, val.val(), type.type!, name ?? ""))
    }
    static func constBitcast(value val: LLVMValue, to type: LLVMType) throws -> LLVMValue {
        return try LLVMValue(ref:LLVMConstBitCast(val.val(), type.type!))
    }
    func buildTrunc(val: LLVMValue, size: Int, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildTrunc(builder, val.val(), LLVMIntType(UInt32(size)), name ?? ""))
    }
    @discardableResult
    func buildBr(to block: LLVMBasicBlock) throws -> LLVMValue {
        return try wrap(LLVMBuildBr(builder, block.block))
    }
    @discardableResult
    func buildCondBr(if cond: LLVMValue, to success: LLVMBasicBlock, elseTo fail: LLVMBasicBlock) throws -> LLVMValue {
        return try wrap(LLVMBuildCondBr(builder, cond.val(), success.block, fail.block))
    }
    @discardableResult
    func buildRet(val: LLVMValue) throws -> LLVMValue {
        return try wrap(LLVMBuildRet(builder, val.val())
        )
    }
    @discardableResult
    func buildRetVoid() throws -> LLVMValue {
        return try wrap(LLVMBuildRetVoid(builder))
    }
    func buildApply(function: LLVMValue, args: [LLVMValue], name: String? = nil) throws -> LLVMValue {
        return try buildCall(function: LLVMFunction(ref: function._value), args: args)
    }
    @discardableResult
    func buildCall(function: LLVMFunction, args: [LLVMValue], name: String? = nil) throws -> LLVMValue {
        var applied = try args.map { try $0.val() }
//        guard function.paramCount == applied.count else { throw error(LLVMError.invalidParamCount(expected: function.paramCount, got: applied.count)) }
        return try wrap(LLVMBuildCall(builder, function.function.val(), &applied, UInt32(applied.count), name ?? ""))
    }
    @discardableResult
    func buildUnreachable() throws -> LLVMValue {
        return try wrap(LLVMBuildUnreachable(builder))
    }
    @discardableResult
    func buildInsertValue(value val: LLVMValue, in aggr: LLVMValue, index: Int, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildInsertValue(builder, aggr.val(), val.val(), UInt32(index), name ?? ""))
    }
    @discardableResult
    static func constInsert(value val: LLVMValue, in aggr: LLVMValue, index: Int, name: String? = nil) throws -> LLVMValue {
        var v = [UInt32(index)]
        var value = val
        
        var types = [LLVMTypeRef?](repeating: nil, count: Int(LLVMCountStructElementTypes(aggr.type.type)))
        LLVMGetStructElementTypes(aggr.type.type, &types)
        let type = types[index]
        
        // cast the pointer if its the wrong target
        let kind = LLVMGetTypeKind(type)
        if kind == LLVMPointerTypeKind || kind == LLVMArrayTypeKind {
            if LLVMGetElementType(type) != nil {
                if let hasType = val._value.map(LLVMTypeOf), hasType != type {
                    if kind == LLVMPointerTypeKind {
                        value = try constBitcast(value: value, to: LLVMType(ref: type))
                    }
                    else if kind == LLVMArrayTypeKind {
                        value = try constGEP(ofAggregate: value, index: LLVMValue.constInt(value: 0, size: 32))
                    }
                }
            }
        }
        
        // correct null value type (which we get from the struct
        return try LLVMValue(ref: LLVMConstInsertValue(aggr.val(),
                                                       value._value ?? LLVMConstNull(type),
                                                       &v,
                                                       1))
    }
    func buildExtractValue(from val: LLVMValue, index: Int, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildExtractValue(builder, val.val(), UInt32(index), name ?? ""))
    }
    func buildStructGEP(ofAggregate val: LLVMValue, index: Int, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildStructGEP(builder, val.val(), UInt32(index), name ?? ""))
    }
    func buildGEP(ofAggregate aggr: LLVMValue, index: LLVMValue, name: String? = nil) throws -> LLVMValue {
        var v = try [index.val()]
        return try wrap(LLVMBuildGEP(builder, aggr.val(), &v, 1, name ?? ""))
    }
    static func constGEP(ofAggregate aggr: LLVMValue, index: LLVMValue) throws -> LLVMValue {
        var v = try [index.val()]
        return try LLVMValue(ref:LLVMConstInBoundsGEP(aggr.val(), &v, 1))
    }
    func buildGlobalString(value str: String, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildGlobalString(builder, str, name ?? ""))
    }
    func buildGlobalString(value str: UnsafeMutablePointer<CChar>, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildGlobalString(builder, str, name ?? ""))
    }
    static func constAggregate(type: LLVMType, elements: [LLVMValue]) throws -> LLVMValue {
        // creates an undef, then for each element in type, inserts the next element into it
        return try elements
            .enumerated()
            .reduce(LLVMValue.undef(type: type)) { aggr, el in
                return try constInsert(value: el.element,
                                       in: aggr,
                                       index: el.offset)
        }
    }
    
    func buildAggregate(type: LLVMType, elements: [LLVMValue], irName: String? = nil) throws -> LLVMValue {
        // creates an undef, then for each element in type, inserts the next element into it
        return try elements
            .enumerated()
            .reduce(LLVMValue.undef(type: type)) { aggr, el in
                return try buildInsertValue(value: el.element,
                                            in: aggr,
                                            index: el.offset,
                                            name: irName)
        }
    }

    func buildArray(elements buffer: [LLVMValue], elType: LLVMType, irName: String? = nil) throws -> LLVMValue {
        let elPtrType = LLVMPointerType(elType.type, 0)
        
        let arrType = LLVMArrayType(elType.type, UInt32(buffer.count))
        let ptr = LLVMBuildAlloca(builder, arrType, irName ?? "") // [n x el]*
        let basePtr = LLVMBuildBitCast(builder, ptr, elPtrType, "") // el*
        
        for (index, val) in buffer.enumerated() {
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
    func buildArrayAlloca(size: LLVMValue, elementType: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildArrayAlloca(builder, elementType.type, size.val(), name ?? ""))
    }
    func buildArrayMalloc(size: LLVMValue, elementType: LLVMType, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildArrayMalloc(builder, elementType.type, size.val(), name ?? ""))
    }
    @discardableResult func buildFree(ptr: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildFree(builder, ptr.val()))
    }
    
    
}

extension LLVMBuilder {
    
    func buildIAdd(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildAdd(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildISub(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildSub(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildIMul(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(
            LLVMBuildMul(builder, lhs.val(), rhs.val(), name ?? "")
        )
    }
    func buildIDiv(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildSDiv(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildIRem(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildSRem(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildIShiftR(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildAShr(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildIShiftL(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildShl(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildAnd(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildAnd(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildOr(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildOr(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildXor(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildXor(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildIntCompare(_ pred: LLVMIntPredicate, lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildICmp(builder, pred, lhs.val(), rhs.val(), name ?? ""))
    }
    
    func buildFAdd(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildFAdd(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildFSub(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildFSub(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildFMul(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildFMul(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildFDiv(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildFDiv(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildFRem(lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildFRem(builder, lhs.val(), rhs.val(), name ?? ""))
    }
    func buildFloatCompare(_ pred: LLVMRealPredicate, lhs: LLVMValue, rhs: LLVMValue, name: String? = nil) throws -> LLVMValue {
        return try wrap(LLVMBuildFCmp(builder, pred, lhs.val(), rhs.val(), name ?? ""))
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


struct LLVMBasicBlock : Dumpable, Hashable {
//    private
    var block: LLVMBasicBlockRef
    var phiUses: Set<PhiTrackingOperand> = []
    
//    private
    init(ref: LLVMBasicBlockRef) { block = ref }
    
    func move(after other: LLVMBasicBlock) {
        LLVMMoveBasicBlockAfter(block, other.block)
    }
    func move(before other: LLVMBasicBlock) {
        LLVMMoveBasicBlockBefore(block, other.block)
    }
    
    private func dump() { LLVMDumpValue(block) }
    
    var hashValue: Int { return block.hashValue }
    static func == (l: LLVMBasicBlock, r: LLVMBasicBlock) -> Bool {
        return l.block == r.block
    }
    
    mutating func addPhiUse(_ op: PhiTrackingOperand) {
        phiUses.insert(op).memberAfterInsert.setLoweredValue(op.loweredValue!)
    }
}



/// Any indirectly stored `RuntimeVariable`s are lowered to a global LLVMValue.
/// `GlobalMetadataCache` stores the globals which have been generated
struct GlobalMetadataCache {
    private var cachedGlobals: [UnsafeMutablePointer<Void>: LLVMGlobalValue] = [:]
}

/// A collection which iterates over a module's linked list of functions
final class FunctionsSequence : Sequence {
    typealias Element = LLVMFunction
    
    private var function: LLVMValueRef?
    
    private init(function: LLVMValueRef) { self.function = function }
    
    typealias Iterator = AnyIterator<LLVMFunction>
    
    func makeIterator() -> Iterator {
        return AnyIterator {
            guard let f = self.function else { return nil }
            defer { self.function = LLVMGetNextFunction(f) }
            return LLVMFunction(ref: f)
        }
    }
}

struct LLVMModule : Dumpable {
    private(set) var module: LLVMModuleRef?
    var typeMetadata: [String: TypeMetadata] = [:]
    
    private(set) var globals = GlobalMetadataCache()
    
    var functions: FunctionsSequence {
        return FunctionsSequence(function: LLVMGetFirstFunction(module))
    }
    
    func getModule() throws -> LLVMModuleRef {
        guard let module = module else { throw NullLLVMRef() }
        return module
    }
    
    init(name: String) {
        module = LLVMModuleCreateWithName(name)
    }
    init(ref: LLVMModuleRef) {
        module = ref
    }
    
    func validate() throws {
        var errorMessage: UnsafeMutablePointer<Int8>? = UnsafeMutablePointer.allocate(capacity: 1)
        guard let module = module else { fatalError() }
        guard LLVMVerifyModule(module, LLVMReturnStatusAction, &errorMessage) == false else {
            #if DEBUG
                dump()
            #endif
            let message = errorMessage.map { String(cString: $0) }
            throw irGenError(.invalidModule(module, message), userVisible: true)
        }
    }

    /// Returns a function from the module named `name`
    func function(named name: String) -> LLVMFunction? {
        let f = LLVMGetNamedFunction(module, name)
        if let f = f {
            return LLVMFunction(ref: f)
        }
        else { return nil }
    }
    ///
    func global(named name: String) -> LLVMGlobalValue? {
        let f = LLVMGetNamedGlobal(module, name)
        if let f = f {
            // will always be a global so it cannot fail
            return try! LLVMGlobalValue(ref: f)
        }
        else { return nil }
    }
    
    func getIntrinsic(_ intrinsic: LLVMIntrinsic, overload: LLVMType...) throws -> LLVMFunction {
        var types = overload.map{$0.type}
        let intrinsicFunction = getIntrinsicFunction(intrinsic, module!, &types, types.count)
        return LLVMFunction(ref: intrinsicFunction)
    }
    
    func dump() { LLVMDumpModule(module) }
    func description() -> String { return String(cString: LLVMPrintModuleToString(module)) }
    
    var dataLayout: String {
        get { return String(cString: LLVMGetDataLayout(module)) }
        nonmutating set { LLVMSetDataLayout(module, newValue) }
    }
    var target: String {
        get { return String(cString: LLVMGetTarget(module)) }
        nonmutating set { LLVMSetTarget(module, newValue) }
    }
    
    mutating func createLLVMGlobal<T>(forPointer value: UnsafeMutablePointer<T>, baseName: String, IGF: inout IRGenFunction, module: Module) throws -> LLVMGlobalValue {
        if let global = globals.cachedGlobals[value] {
            return global
        }
        let v = try value.lowerMemory(IGF: &IGF, module: module, baseName: baseName)
        return createGlobal(value: v, forPtr: value, baseName: baseName, IGF: &IGF)
    }
    
    /// Add a LLVM global value to the module
    mutating func createGlobal(value: LLVMValue, forPtr: UnsafeMutablePointer<Void>?, baseName: String, IGF: inout IRGenFunction) -> LLVMGlobalValue {
        let global = LLVMGlobalValue(module: IGF.module, type: value.type, name: baseName)
        global.initialiser = value
        global.isConstant = true
        if let p = forPtr { globals.cachedGlobals[p] = global }
        return global
    }
    
    /// An initialiser which loads from a bitcode file
    /// - precondition: path points at a bitcode file
    init(path: String, name: String) {
        precondition(path.hasSuffix(".bc"))
        
        var buffer: LLVMMemoryBufferRef? = nil
        var str: UnsafeMutablePointer<Int8>? = UnsafeMutablePointer.allocate(capacity: 1)
        
        var runtimeModule = LLVMModuleCreateWithName(name)
        
        LLVMCreateMemoryBufferWithContentsOfFile(path, &buffer, &str)
        LLVMGetBitcodeModule(buffer, &runtimeModule, &str)
        module = runtimeModule
    }
    
}

enum _WidthUnit { case bytes, bits }

struct LLVMType : Dumpable {
//    private
    var type: LLVMTypeRef?
    
    init(ref: LLVMTypeRef?) { type = ref }
    
    static func functionType(params: [LLVMType], returns: LLVMType) -> LLVMType {
        var fs = params.map { $0.type }
        return LLVMType(ref: LLVMFunctionType(returns.type, &fs, UInt32(fs.count), false))
    }
    
    func dump() { LLVMDumpType(type) }
    
    /// Get the struct offset of an aggregate's element at `index`
    func offsetOfElement(at index: Int, module: LLVMModule) -> Int {
        let dataLayout = LLVMCreateTargetData(module.dataLayout)
        return Int(LLVMOffsetOfElement(dataLayout, type, UInt32(index)))
    }
    var size: LLVMValue {
        return LLVMValue(ref: LLVMSizeOf(type))
    }
    /// the size in `unit` of this lowered type
    func size(unit: _WidthUnit, IGF: IRGenFunction) -> Int {
        let dataLayout = LLVMCreateTargetData(IGF.module.dataLayout)
        let s = Int(LLVMSizeOfTypeInBits(dataLayout, type!))
        switch unit {
        case .bits: return s
        case .bytes: return s / 8
        }
    }
    /// get self*
    func getPointerType() -> LLVMType {
        return LLVMType(ref: LLVMPointerType(type, 0))
    }
    /// i8*
    static var opaquePointer: LLVMType {
        return LLVMType(ref: LLVMPointerType(LLVMInt8Type(), 0))
    }
    static func intType(size: Int) -> LLVMType {
        return LLVMType(ref: LLVMIntType(UInt32(size)))
    }
    static func arrayType(element: LLVMType, size: Int) -> LLVMType {
        return LLVMType(ref: LLVMArrayType(element.type, UInt32(size)))
    }
    static var bool: LLVMType {
        return LLVMType(ref: LLVMInt1Type())
    }
    static var void: LLVMType {
        return LLVMType(ref: LLVMVoidType())
    }
    static var null: LLVMType {
        return LLVMType(ref: nil)
    }
    
    static var half: LLVMType {
        return LLVMType(ref: LLVMHalfType())
    }
    static var single: LLVMType {
        return LLVMType(ref: LLVMFloatType())
    }
    static var double: LLVMType {
        return LLVMType(ref: LLVMDoubleType())
    }
}

struct LLVMValue : Dumpable, Hashable {
//    private
    var _value: LLVMValueRef? = nil
    
    var parentBlock: LLVMBasicBlock {
        return LLVMBasicBlock(ref: LLVMGetInstructionParent(_value))
    }
    
    private func val() throws -> LLVMValueRef? {
        guard let v = _value else { throw NullLLVMRef() }
        return v
    }
    
    init(ref: LLVMValueRef?) { _value = ref }
    
    var name: String? {
        get { return String(cString: LLVMGetValueName(_value)) }
        nonmutating set { if let name = newValue { LLVMSetValueName(_value, name) } }
    }
    
    static func constNull(type: LLVMType) -> LLVMValue {
        return LLVMValue(ref: LLVMConstNull(type.type!))
    }
    static func constInt(value: Int, size: Int) -> LLVMValue {
        return LLVMValue(ref: LLVMConstInt(LLVMIntType(UInt32(size)), UInt64(bitPattern: Int64(value)), false))
    }
    static func constBool(value: Bool) -> LLVMValue {
        return LLVMValue(ref: LLVMConstInt(LLVMInt1Type(), UInt64(value.hashValue), false))
    }
    static func constString(value: String) -> LLVMValue {
        return LLVMValue(ref: LLVMConstString(value, UInt32(value.utf8.count), false))
    }
    static func undef(type: LLVMType) -> LLVMValue {
        return LLVMValue(ref: LLVMGetUndef(type.type!))
    }
    static func constArray(of type: LLVMType, vals: [LLVMValue]) -> LLVMValue {
        var els = vals.map { $0._value }
        let s = UInt32(els.count)
        return LLVMValue(ref: LLVMConstArray(type.type!, &els, s))
    }
    static var nullptr: LLVMValue { return LLVMValue(ref: nil) }
    
    func dump() { try! LLVMDumpValue(val()) }
    var type: LLVMType { return LLVMType(ref: try! LLVMTypeOf(val())) }
    
    var hashValue: Int { return _value?.hashValue ?? 0 }
    static func == (l: LLVMValue, r: LLVMValue) -> Bool {
        return l._value == r._value
    }
    
    func eraseFromParent(replacingAllUsesWith val: LLVMValue? = nil) {
        if let val = val {
            LLVMReplaceAllUsesWith(_value, val._value)
        }
        LLVMInstructionEraseFromParent(_value)
    }
    
    /// - precondition: `self` is a Phi node
    func addPhiIncoming(_ incoming: [(value: LLVMValue, from: LLVMBasicBlock)]) {
        precondition(LLVMGetInstructionOpcode(_value) == LLVMPHI)
        
        var incomingVals = incoming.map { $0.value._value }
        var incomingBlocks = incoming.map { $0.from.block } as [LLVMValueRef?]
        
        LLVMAddIncoming(_value, &incomingVals, &incomingBlocks, UInt32(incomingBlocks.count))
    }
    
    /// - precondition: `self` is a Phi node
    func incomingBlock(at index: Int) -> LLVMBasicBlock {
        precondition(LLVMGetInstructionOpcode(_value) == LLVMPHI)
        return LLVMBasicBlock(ref: LLVMGetIncomingBlock(_value, UInt32(index)))
    }
    /// - precondition: `self` is a Phi node
    func incomingValue(at index: Int) -> LLVMValue {
        precondition(LLVMGetInstructionOpcode(_value) == LLVMPHI)
        return LLVMValue(ref: LLVMGetIncomingValue(_value, UInt32(index)))
    }
}

struct LLVMGlobalValue : Dumpable {
    var value: LLVMValue
    
    init(module: LLVMModule, type: LLVMType, name: String) {
        value = LLVMValue(ref: LLVMAddGlobal(module.module, type.type!, name))
    }
    
    var parent: LLVMModule {
        return LLVMModule(ref: LLVMGetGlobalParent(value._value))
    }
    
//    private
    init(ref: LLVMValueRef) throws {
        guard LLVMIsAGlobalValue(ref) != nil else { throw error(LLVMError.notAGlobal) }
        value = LLVMValue(ref: ref)
    }
    
    var hasUnnamedAddr: Bool {
        get { return LLVMHasUnnamedAddr(value._value) == true }
        nonmutating set { LLVMSetUnnamedAddr(value._value, LLVMBool(booleanLiteral: newValue)) }
    }
    var isExternallyInitialised: Bool {
        get { return LLVMIsExternallyInitialized(value._value) == true }
        nonmutating set { LLVMSetExternallyInitialized(value._value, LLVMBool(booleanLiteral: newValue)) }
    }
    var initialiser: LLVMValue {
        get { return LLVMValue(ref: LLVMGetInitializer(value._value)) }
        nonmutating set { LLVMSetInitializer(value._value, newValue._value) }
    }
    var linkage: LLVMLinkage {
        get { return try! LLVMGetLinkage(value.val()) }
        nonmutating set(linkage) { try! LLVMSetLinkage(value.val(), linkage) }
    }
    var isConstant: Bool {
        get { return try! LLVMIsConstant(value.val()) != 0 }
        nonmutating set { try! LLVMSetGlobalConstant(value.val(), newValue ? 1 : 0) }
    }
    
    var type: LLVMType {
        return value.type
    }
    
    private func dump() { value.dump() }
}


/// A LLVM function, a LLVM value ref under the hood
struct LLVMFunction : Dumpable {
    private (set) var function: LLVMValue
    
//    private
    init(ref: LLVMValueRef?) {
//        guard LLVMIsAFunction(ref) != nil else { throw error(LLVMError.notAFunction) }
        function = LLVMValue(ref: ref)
    }
    init(name: String, type: LLVMType, module: LLVMModule) {
        let r = LLVMAddFunction(module.module, name, type.type!)
        function = LLVMValue(ref: r)
    }
    
    func addAttr(_ attr: LLVMAttribute) throws {
        try LLVMAddFunctionAttr(function.val(), attr)
    }
    var visibility: LLVMVisibility {
        get { return try! LLVMGetVisibility(function.val()) }
        nonmutating set(vis) { try! LLVMSetVisibility(function.val(), vis) }
    }
    var linkage: LLVMLinkage {
        get { return try! LLVMGetLinkage(function.val()) }
        nonmutating set(linkage) { try! LLVMSetLinkage(function.val(), linkage) }
    }

    func appendBasicBlock(named name: String) throws -> LLVMBasicBlock {
        return LLVMBasicBlock(ref:
            try LLVMAppendBasicBlock(function.val(), name)
        )
    }
    
    var unsafePointer: UnsafeMutablePointer<Void>? {
        return UnsafeMutablePointer(function._value)
    }
    
    var paramCount: Int { return try! Int(LLVMCountParams(function.val())) }
    var name: String? {
        get { return function.name }
        nonmutating set { function.name = newValue }
    }
    
    var type: LLVMType { return function.type }
    
    /// Returns the function parameter at `index`
    func param(at index: Int) throws -> LLVMValue {
        guard index < paramCount else { throw error(LLVMError.invalidParamIndex(index, function: name)) }
        return try LLVMValue(ref: LLVMGetParam(function.val(), UInt32(index)))
    }
        
    func dump() { function.dump() }
}




