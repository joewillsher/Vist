//
//  LiteralInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class IntLiteralInst: InstBase {
    var value: LiteralValue<Int>
    
    override var type: Ty? { return value.type }
    
    private init(val: Int, irName: String?) {
        self.value = LiteralValue(val: val, irName: nil)
        super.init(args: [Operand(value)], irName: irName)
    }
    
    override var instVHIR: String {
        return "\(name) = int_literal \(value.value) \(useComment)"
    }
}
final class BoolLiteralInst: InstBase {
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

final class LiteralValue<Literal>: RValue {
    var value: Literal
    
    var irName: String?
    var type: Ty? {
        switch value {
        case is Int: return BuiltinType.int(size: 64)
        case is Bool: return BuiltinType.bool
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


final class VoidLiteralValue: RValue {
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
    func buildBuiltinInt(val: Int, irName: String? = nil) throws -> IntLiteralInst {
        return try _add(IntLiteralInst(val: val, irName: irName))
    }
    
    /// Builds an `Int` literal from a value
    func buildIntLiteral(val: Int, irName: String? = nil) throws -> StructInitInst {
        let v = try buildBuiltinInt(val, irName: irName.map { "\($0).value" })
        return try buildStructInit(StdLib.intType, values: Operand(v), irName: irName)
    }
    
    
    /// Builds a builtin i1 object
    func buildBuiltinBool(val: Bool, irName: String? = nil) throws -> BoolLiteralInst {
        return try _add(BoolLiteralInst(val: val, irName: irName))
    }
    
    /// Builds an `Bool` literal from a value
    func buildBoolLiteral(val: Bool, irName: String? = nil) throws -> StructInitInst {
        let v = try buildBuiltinBool(val, irName: irName.map { "\($0).value" })
        return try buildStructInit(StdLib.boolType, values: Operand(v), irName: irName)
    }
    
    func createVoidLiteral() -> VoidLiteralValue {
        return VoidLiteralValue()
    }
}

