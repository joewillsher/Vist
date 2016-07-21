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
final class IntLiteralInst : InstBase {
    var value: Int, size: Int
    
    override var type: Type? { return BuiltinType.int(size: size) }
    
    init(val: Int, size: Int, irName: String? = nil) {
        self.value = val
        self.size = size
        super.init(args: [], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = int_literal \(value)\(useComment)"
    }
    
    override func copyInst() -> IntLiteralInst {
        return IntLiteralInst(val: value, size: size)
    }
}
/**
 An boolean literal
 
 `%a = bool_literal false`
 */
final class BoolLiteralInst : InstBase {
    var value: Bool
    
    override var type: Type? { return BuiltinType.bool }
    
    init(val: Bool, irName: String? = nil) {
        self.value = val
        super.init(args: [], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = bool_literal \(value)\(useComment)"
    }
    
    override func copyInst() -> BoolLiteralInst {
        return BoolLiteralInst(val: value)
    }
}


/**
 A string literal, specifying an encoding
 
 `%a = string_literal utf16 "hello 😎"`
 */
final class StringLiteralInst : InstBase {
    var value: String
    
    var isUTF8Encoded: Bool { return value.smallestEncoding == .utf8 || value.smallestEncoding == .ascii }
    override var type: Type? { return BuiltinType.opaquePointer }
    
    init(val: String, irName: String? = nil) {
        self.value = val
        super.init(args: [], irName: irName)
    }
    
    override var instVIR: String {
        return "\(name) = string_literal \(isUTF8Encoded ? "utf8" : "utf16") \"\(value)\" \(useComment)"
    }
    
    override func copyInst() -> StringLiteralInst {
        return StringLiteralInst(val: value, irName: irName)
    }
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


