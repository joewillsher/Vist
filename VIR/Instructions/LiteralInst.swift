//
//  LiteralInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSString

/**
 An int literal
 
 `%a = int_literal 1`
 */
final class IntLiteralInst : Inst {
    var value: Int, size: Int
    
    var type: Type? { return BuiltinType.int(size: size) }
    
    var args: [Operand] = []
    var uses: [Operand] = []
    
    init(val: Int, size: Int, irName: String? = nil) {
        self.value = val
        self.size = size
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = int_literal \(value)\(useComment)"
    }
    
    func copy() -> IntLiteralInst {
        return IntLiteralInst(val: value, size: size)
    }
    
    var parentBlock: BasicBlock?
    var irName: String?
}
/**
 An boolean literal
 
 `%a = bool_literal false`
 */
final class BoolLiteralInst : Inst {
    var value: Bool
    
    var type: Type? { return BuiltinType.bool }
    
    var args: [Operand] = []
    var uses: [Operand] = []

    init(val: Bool, irName: String? = nil) {
        self.value = val
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = bool_literal \(value)\(useComment)"
    }
    
    func copy() -> BoolLiteralInst {
        return BoolLiteralInst(val: value)
    }
    var parentBlock: BasicBlock?
    var irName: String?
}


/**
 A string literal, specifying an encoding
 
 `%a = string_literal utf16 "hello 😎"`
 */
final class StringLiteralInst : Inst {
    var value: String
    
    var isUTF8Encoded: Bool { return value.smallestEncoding == .utf8 || value.smallestEncoding == .ascii }
    var type: Type? { return BuiltinType.opaquePointer }
    
    var args: [Operand] = []
    var uses: [Operand] = []
    
    init(val: String, irName: String? = nil) {
        self.value = val
        self.irName = irName
    }
    
    var vir: String {
        return "\(name) = string_literal \(isUTF8Encoded ? "utf8" : "utf16") \"\(value)\" \(useComment)"
    }
    
    func copy() -> StringLiteralInst {
        return StringLiteralInst(val: value, irName: irName)
    }
    var parentBlock: BasicBlock?
    var irName: String?
}

/// A void literal: `()`
final class VoidLiteralValue : Value {
    var type: Type? { return BuiltinType.void }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    var irName: String? = nil
    
    var name: String {
        get { return "()" }
        set { }
    }
}


