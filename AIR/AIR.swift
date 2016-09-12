//
//  AIR.swift
//  Vist
//
//  Created by Josef Willsher on 04/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A value which is representable in VIR
protocol AIRValue {
    var air: String { get }
    var valueAIR: String { get }
    func dagNode(dag: SelectionDAG) -> DAGNode
}
extension AIRValue {
    var valueAIR: String { return air }
}

/// An AIR value who's identity is tied to the operation -- these appear
/// top level in an AIRBB and cannot be copied into each use
protocol AIROp : class, AIRValue {
    var args: [AIRArg] { get }
    var dagOp: SelectionDAGOp? { get }
}

/// An AIR op which has a side effect -- passes its value out into
/// `register`
protocol AIRSideEffectingOp : AIROp {
    var result: AIRRegister { get }
}
struct AIROpHash : Hashable {
    var hashValue: Int
    static func == (l: AIROpHash, r: AIROpHash) -> Bool {
        return l.hashValue == r.hashValue
    }
}
extension AIROp {
    var hashValue: AIROpHash {
        return AIROpHash(hashValue: valueAIR.hashValue)
    }
}

struct AIRArg {
    var val: AIRValue, type: AIRType
    
    init(value: AIRValue, type: AIRType) {
        self.val = value
        self.type = type
    }
    init(reg: AIRRegister, type: AIRType) {
        self.val = reg
        self.type = type
    }
    init(imm: AIRImm) {
        self.val = imm
        self.type = imm.type
    }
}


final class AIRFunction : AIRImm {
    var blocks: [AIRBlock] = []
    var params: [Param]
    var type: AIRType, name: String
    
    init(name: String, type: AIRType, params: [Param]) {
        self.name = name
        self.type = type
        self.params = params
    }
    
    var airType: AIRType? { return type }
    var air: String { return "@\(name)" }
    
    final class Param : AIRValue {
        let name: String, type: AIRType
        let index: Int
        var register: AIRRegister
        
        init(name: String, type: AIRType, register: AIRRegister, index: Int) {
            self.name = name
            self.type = type
            self.register = register
            self.index = index
        }
        
        var result: AIRRegister {
            get { return register }
            set { register = newValue }
        }
    }
}

extension AIRFunction.Param {
    var air: String { return register.air }
    var airType: AIRType? { return type }
}

typealias AIRGenFunction = (builder: AIRBuilder, module: Module)

final class AIRBlock {
    var insts: [AIROp] = []
}


enum AIRType {
    case int(size: Int), float(size: Int), void
    case aggregate(elements: [AIRType])
    indirect case named(name: String, type: AIRType)
    indirect case function(params: [AIRType], returns: AIRType)
    
    var air: String {
        switch self {
        case .int(let size): return "i\(size)"
        case .float(let size): return "f\(size)"
        case .function: return "i64"
        case .named(let name, _): return "%\(name)"
        case .void: return "void"
        case .aggregate(let els): return "{\(els.map { $0.air }.joined(separator: ", "))}"
        }
    }
}







protocol AIRImm : AIRValue {
    var type: AIRType { get }
}

// immediates are constructed inline
struct IntImm : AIRImm {
    let value: Int, size: Int
    
    var type: AIRType { return .int(size: size) }
    var air: String { return "\(type.air) \(value)"  }
}
struct FloatImm : AIRImm {
    let value: Int, size: Int
    
    var type: AIRType { return .int(size: size) }
    var air: String { return "\(type.air) \(value)"  }
}
struct AggregateImm : AIRImm {
    let elements: [AIRValue]
    var type: AIRType
    
    var air: String { return "\(type.air) { \(elements.map { $0.valueAIR }.joined(separator: ", ")) }" }
}

// ops are calls to processor ops
final class CallOp : AIRSideEffectingOp {
    let function: AIRArg
    let args: [AIRArg]
    var result: AIRRegister
    let returnType: AIRType
    
    init(vir: Function, args: [AIRArg], result: AIRRegister) {
        self.function = AIRArg(imm: vir.airFunction!)
        self.returnType = vir.type.returns.machineType()
        self.args = args
        self.result = result
    }
    
    var airType: AIRType? { return returnType }
    var air: String { return "\(result.air) = call \(returnType.air) \(function.val.air) (\(args.map { $0.val.valueAIR }.joined(separator: ", ")))" }
    var valueAIR: String { return result.air }
    var dagOp: SelectionDAGOp? { return .call }
}
// ops are calls to processor ops
final class RetOp : AIRSideEffectingOp {
    let val: AIRArg
    /// The return addr
    var result: AIRRegister
    
    init(val: AIRArg, result: AIRRegister) {
        self.val = val
        self.result = result
    }
    
    var air: String { return "ret \(val.type.air) \(val.val.valueAIR) // to \(result.air)" }
    var valueAIR: String { return result.air }
    var args: [AIRArg] { return [val] }
    var dagOp: SelectionDAGOp? { return .ret }
}

/// A processor op
final class BuiltinOp : AIROp {
    let op: AIROpCode
    let arg1: AIRArg, arg2: AIRArg
    let returnType: AIRType
    
    init(op: AIROpCode, arg1: AIRArg, arg2: AIRArg, returnType: AIRType) {
        self.op = op
        self.arg1 = arg1; self.arg2 = arg2
        self.returnType = returnType
    }
    
    var airType: AIRType? { return returnType }
    var air: String { return "\(returnType.air) \(op.rawValue) \(arg1.val.valueAIR), \(arg2.val.valueAIR)" }
    var args: [AIRArg] { return [arg1, arg2] }
    var dagOp: SelectionDAGOp? {
        switch op {
        case .add: return .add
        default: fatalError("TODO")
        }
    }
}

//// ops are calls to processor ops
final class StructExtractOp : AIROp {
    let aggr: AIRArg, index: Int
    var elType: AIRType
    
    init(aggr: AIRArg, index: Int, elType: AIRType) {
        self.aggr = aggr
        self.index = index
        self.elType = elType
    }
    
    var airType: AIRType? { return elType }
    var air: String { return "\(elType.air) element \(index) \(aggr.val.valueAIR)" }
    var args: [AIRArg] { return [aggr] }
    var dagOp: SelectionDAGOp? { return nil }
}


enum AIROpCode : String {
    case add, mul, sub, div
}




protocol AIRRegister : AIRValue {
    var air: String { get }
    var hash: AIRRegisterHash { get }
}

struct VirtualRegister : AIRRegister {
    let id: Int
    var air: String { return "%vreg\(id)" }
    var hash: AIRRegisterHash { return AIRRegisterHash(hashValue: id) }
}

extension AIRBuilder {
    func getRegister() -> VirtualRegister {
        defer { registerIndex += 1 }
        return VirtualRegister(id: registerIndex)
    }
}

struct AIRRegisterHash : Hashable {
    var hashValue: Int
    static func == (l: AIRRegisterHash, r: AIRRegisterHash) -> Bool {
        return l.hashValue == r.hashValue
    }
}












protocol AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue
}
extension Operand {
    func getAIR(builder: AIRBuilder) throws -> AIRValue {
        if let lowered = airValue { return lowered }
        guard case let val as AIRLower & Value = value else { fatalError() }
        let air = try val.lowerVIRToAIR(builder: builder)
        val.updateUsesWithAIR(air)
        if case let op as AIRSideEffectingOp = air { return op.result }
        return air
    }
}

extension IntLiteralInst : AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue {
        return IntImm(value: value, size: 64)
    }
}
extension FunctionCallInst : AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue {
        return try builder.build(CallOp(vir: function,
                                        args: try functionArgs
                                            .map { try AIRArg(value: $0.getAIR(builder: builder), type: $0.type!.machineType()) },
                                        result: builder.getRegister())).result
    }
}
extension ReturnInst : AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue {
        return try builder.build(RetOp(val: AIRArg(value: returnValue.getAIR(builder: builder), type: returnValue.type!.machineType()),
                                       result: builder.getRegister())).result
    }
}
extension StructInitInst : AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue {
        return AggregateImm(elements: try args.map { try $0.getAIR(builder: builder) }, type: type!.machineType())
    }
}
extension TupleCreateInst : AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue {
        return AggregateImm(elements: try args.map { try $0.getAIR(builder: builder) }, type: type!.machineType())
    }
}
extension Param : AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue {
        let i = parentFunction!.params!.index(of: self)!
        return AIRFunction.Param(name: name, type: type!.machineType(), register: builder.getRegister(), index: i)
    }
}
extension BuiltinInstCall : AIRLower {
    func lowerVIRToAIR(builder: AIRBuilder) throws -> AIRValue {
        let args = try self.args.map {
            try AIRArg(value: $0.getAIR(builder: builder), type: $0.type!.machineType())
        }
        let op: AIROpCode
        switch inst {
        case .idiv:         op = .div
        case .iaddunchecked: op = .add
        default:
            fatalError("TODO")
        }
        return try builder.build(BuiltinOp(op: op, arg1: args[0], arg2: args[1],
                                           returnType: returnType.machineType()))
    }
}



