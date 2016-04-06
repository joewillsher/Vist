//
//  LiteralInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class IntLiteralInst : InstBase {
    var value: LiteralValue<Int>, size: Int
    
    override var type: Ty? { return BuiltinType.int(size: UInt32(size)) }
    
    private init(val: Int, size: Int, irName: String?) {
        self.value = LiteralValue(val: val, irName: nil)
        self.size = size
        super.init(args: [Operand(value)], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = int_literal \(value.value) \(useComment)"
    }
}
final class BoolLiteralInst : InstBase {
    var value: LiteralValue<Bool>
    
    override var type: Ty? { return value.type }
    
    private init(val: Bool, irName: String?) {
        self.value = LiteralValue(val: val, irName: nil)
        super.init(args: [Operand(value)], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = bool_literal \(value.value) \(useComment)"
    }
}
final class StringLiteralInst : InstBase {
    var value: LiteralValue<String>
    
    var encoding: String.Encoding { return value.value.encoding }
    override var type: Ty? { return value.type }
    
    private init(val: String, irName: String?) {
        self.value = LiteralValue(val: val, irName: nil)
        super.init(args: [Operand(value)], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = string_literal \(encoding) \"\(value.value)\" \(useComment)"
    }
}


final class LiteralValue<Literal> : Value {
    var value: Literal
    
    var irName: String?
    var type: Ty? {
        switch value {
        case is Int: return BuiltinType.int(size: 64)
        case is Bool: return BuiltinType.bool
        case is String: return BuiltinType.opaquePointer
        case is (): return BuiltinType.void
        default: fatalError("Invalid literal")
        }
    }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    private init(val: Literal, irName: String?) {
        self.value = val
        self.irName = irName
    }
}


final class VoidLiteralValue : Value {
    var type: Ty? { return BuiltinType.void }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    var irName: String? = nil
    
    var name: String {
        get { return "()" }
        set { }
    }
}


extension Builder {
    /// Builds a builtin i64 object
    func buildIntLiteral(val: Int, size: Int = 64, irName: String? = nil) throws -> IntLiteralInst {
        return try _add(IntLiteralInst(val: val, size: size, irName: irName))
    }
    
    
    /// Builds a builtin i1 object
    func buildBoolLiteral(val: Bool, irName: String? = nil) throws -> BoolLiteralInst {
        return try _add(BoolLiteralInst(val: val, irName: irName))
    }

    /// Builds a builtin i1 object
    func buildStringLiteral(val: String, irName: String? = nil) throws -> StringLiteralInst {
        return try _add(StringLiteralInst(val: val, irName: irName))
    }

    func createVoidLiteral() -> VoidLiteralValue {
        return VoidLiteralValue()
    }
}

