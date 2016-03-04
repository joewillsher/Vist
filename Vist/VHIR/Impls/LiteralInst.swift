//
//  LiteralInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class IntLiteralInst: InstBase {
    var value: IntLiteralValue
    
    override var type: Ty? { return BuiltinType.int(size: 64) }
    
    private init(val: Int, irName: String? = nil) {
        self.value = IntLiteralValue(val: val)
        super.init()
        self.irName = irName
        self.args = [Operand(value)]
    }
    
    override var instVHIR: String {
        return "\(name) = int_literal \(value.value) \(useComment)"
    }
}

final class IntLiteralValue: Value {
    var value: Int
    
    var irName: String?
    var type: Ty? { return BuiltinType.int(size: 64) }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    private init(val: Int, irName: String? = nil) {
        self.value = val
        self.irName = irName
    }
}


final class VoidLiteralValue: Value {
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
    func buildBuiltinInt(val: Int, irName: String? = nil) throws-> IntLiteralInst {
        let v = IntLiteralInst(val: val, irName: irName)
        try addToCurrentBlock(v)
        return v
    }
    
    /// Builds an `Int` literal from a value
    func buildIntLiteral(val: Int, irName: String? = nil) throws-> StructInitInst {
        let v = try buildBuiltinInt(val, irName: irName.map { "\($0).value" })
        return try buildStructInit(StdLib.intType, values: [Operand(v)], irName: irName)
    }
}

